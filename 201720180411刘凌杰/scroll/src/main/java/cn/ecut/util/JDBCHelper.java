package cn.ecut.util;

import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Objects;
import java.util.Properties;

/**
 * @author lujiapeng
 * @className JDBCHelper
 * @description JDBC工具类，可以叫做 JDBCHelper 或 JDBCUtil
 **/
public class JDBCHelper {
    private static String driverName ;
    private static String url ;
    private static String username ;
    private static String password ;
    private static boolean autoCommit ;
    private static int isolation ;

    private static Connection connection ;
    /**
     * 0、加载配置文件 ：当类被加载之后，就直接 加载 配置文件
     */
    static{
        // 类代码块 ： 当类加载的时候，就会被执行，而且比 构造方法先执行
        config();
    }
    private static void config(){
        // 创建一个对象，获取到资源文件
        Properties properties = new Properties() ;

        // 通过 Class 中的方法，可以获取到 指定的资源文件
        InputStream resourceAsStream = JDBCHelper.class.getResourceAsStream("/jdbc.properties");
        // 将流中的中的内容，加载到 properties 对象中
        try {
            properties.load( resourceAsStream );
            // 根据指定的属性名，获取 相应的内容（属性值）
            String connect = properties.getProperty("connect");
            String autocommit = properties.getProperty("jdbc.connection.transaction.autocommit");
            autoCommit = Boolean.valueOf( autocommit ) ;
            String i = properties.getProperty("jdbc.connection.transaction.isolation");
            isolation = Integer.valueOf( i ) ;
            driverName = properties.getProperty("jdbc.connection.mysql.driver");
             url = properties.getProperty("jdbc.connection.mysql.url") ;
             username = properties.getProperty("jdbc.connection.mysql.username") ;
             password = properties.getProperty("jdbc.connection.mysql.password") ;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 1、加载驱动
     */
    private static boolean load(){
        try {
            Class.forName( driverName ) ;
            return true ;
        } catch (ClassNotFoundException e) {
            System.out.println("加载驱动异常：" + e.getMessage());
        }
        return false ;
    }
    /**
     * 2、建立连接
     */
    public static Connection connect(){
        if( load() ){
            try {
                connection = DriverManager.getConnection(url, username, password);
            } catch (SQLException e) {
                e.printStackTrace();
                System.out.println("建立连接失败" + e.getMessage() );
            }
        }
        return connection ;
    }
    /**
     * 3、设置事务是否是 自动提交的， 并且 还要设置 事务的隔离级别
     */
    public static void transaction(){
        if(Objects.isNull( connection)){
            connection = connect() ;
            try {
                connection.setAutoCommit(autoCommit);
            } catch (SQLException e) {
                e.printStackTrace();
            }
            try {
                connection.setTransactionIsolation(isolation);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    /**
     * 4、创建 Statement 对象 或 PreparedStatement 对象
     */
    public static Statement statement(){
        Statement st = null ;
        if( Objects.isNull(connection )){
            connection = connect() ;
        }
        try {
            st = connection.createStatement() ;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return st ;
    }


    /**
     *
     * @param SQL
     * @param autoGeneratedKeys 是否需要自动生成主键
     * @return
     */
    public static PreparedStatement prepare( String SQL , boolean autoGeneratedKeys ){
        PreparedStatement ps = null ;
        if( Objects.isNull( connection )){
            connection = connect() ;
        }
        try {
            if( autoGeneratedKeys ) {
                ps = connection.prepareStatement(SQL , Statement.RETURN_GENERATED_KEYS);
            }else{
                ps = connection.prepareStatement( SQL ) ;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return ps ;
    }

    /**
     * 5、执行 SQL ： 查询、insert、delete、update
     */
    /**
     * 仅仅处理查询语句
     * @param SQL
     * @param params 可变长参数，在方法中当作数组来处理即可。
     * @return
     */
    public static ResultSet query( String SQL , Object... params ){
        if( SQL == null || SQL.trim().isEmpty() || !SQL.trim().toLowerCase().startsWith("select")){
            throw new RuntimeException("你的SQL语句为空，或不是查询语句") ;
        }
        ResultSet rs = null ;
        if(params.length > 0 ){
            PreparedStatement ps = prepare( SQL , false ) ;
            try {
                for( int  i = 0 ; i < params.length ; i ++ ){
                    ps.setObject( i+1 , params[i]);
                }
                rs = ps.executeQuery() ;
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }else{
            Statement st = statement() ;
            try {
                rs = st.executeQuery( SQL ) ;
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return rs ;
    }


    /**
     * 执行 Insert、update、delete等SQL
     * @param SQL
     * @param params
     * @return
     */
    public static boolean  execute( String SQL , Object... params ){
        if( SQL == null || SQL.trim().isEmpty() || SQL.trim().toLowerCase().startsWith("select")){
            throw new RuntimeException("你的SQL语句为空，或是 查询语句") ;
        }
        boolean r = false ;
        if(params.length > 0 ){
            PreparedStatement ps = prepare( SQL , false ) ;
            Connection c = null ;
            try {
                c = ps.getConnection() ;
            } catch (SQLException e) {
                e.printStackTrace();
            }
            try {
                for( int  i = 0 ; i < params.length ; i ++ ){
                    ps.setObject( i+1 , params[i]);
                }
                ps.executeUpdate() ;
                r = true ;
                // 提交事务
                commit( c );
            } catch (SQLException e) {
                e.printStackTrace();
                rollback( c );
            }
        }else{
            Statement st = statement() ;
            Connection c = null ;
            try {
                c = st.getConnection() ;
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            try {
                st.executeUpdate( SQL ) ;
                r = true ;
                commit( c );
            } catch (SQLException e) {
                e.printStackTrace();
                rollback( c );
            }
        }
        return r ;
    }


    /**
     * 6、处理事务： 提交或 回滚事务
     */
    private static void commit( Connection c ){
        if( c != null && autoCommit ){
            try {
                c.commit();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    private static void rollback( Connection c ){
        if( c != null && autoCommit ){
            try {
                c.rollback();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    /**
     * 最后一步：释放资源
     */
    public static void release( Object o ){
        if(Objects.nonNull( o )){
            if( o instanceof ResultSet){
                ResultSet resultSet = ( ResultSet) o ;
                try {
                    resultSet.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
            if( o instanceof Statement){
                Statement st = ( Statement) o ;
                try {
                    st.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
            if( o instanceof Connection){
                Connection c = ( Connection) o ;
                try {
                    c.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
