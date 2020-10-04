package cn.ecut.dao;

import cn.ecut.exception.DaoException;
import cn.ecut.model.User;
import cn.ecut.util.JDBCHelper;
import cn.ecut.util.TableNames;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author lujiapeng
 * @className UserDao
 * @description 针对于 User 的数据访问层
 * @date 2020/9/17 14:37
 **/
public class UserDao {

    public List<User> loadByUsername(User user ){
        String SQL = "select id , username , password from" + TableNames.USER_TABLE_NAME + "where username = ? " ;
        ResultSet resultSet = JDBCHelper.query(SQL, user.getUsername());
        List<User> users = warp(resultSet);
        return users ;
    }

    public User loadByUserId(Integer  userId ){
        String SQL = "select id , username , password from" + TableNames.USER_TABLE_NAME + "where id = ? " ;
        ResultSet resultSet = JDBCHelper.query(SQL, userId);
        List<User> users = warp(resultSet);
        if( users.size() > 0 ){
            return users.get( 0 ) ;
        }
        return null  ;
    }

    public boolean saveUser(User user ){
        String SQL = "insert into " + TableNames.USER_TABLE_NAME + "( username , password) values ( ? , ? )" ;
        return JDBCHelper.execute( SQL , user.getUsername() , user.getPassword() ) ;
    }


    private List<User> warp(ResultSet resultSet ) throws DaoException{
        List<User> list = new ArrayList<>() ;
        try {
            while( resultSet.next() ){
                User u = new User() ;
                u.setId( resultSet.getInt("id") ) ;
                u.setUsername( resultSet.getString("username") );
                u.setPassword( resultSet.getString("password") );
                list.add( u ) ;
            }
        } catch (SQLException e) {
            throw new DaoException("数据封装出错。") ;
        }
        return list ;
    }
}
