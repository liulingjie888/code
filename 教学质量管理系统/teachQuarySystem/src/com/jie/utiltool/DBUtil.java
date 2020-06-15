package com.jie.utiltool;

import com.jie.object.*;
import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.ResultSetHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import javax.sql.DataSource;
import java.io.*;
import java.sql.*;

public class DBUtil {
    public static final int row=7;
    public static final String charset="UTF-8";
    public static final int insert=1;
    public static final int update=0;
    public static final int delete=-1;
    private static DataSource datasource=null;
    private QueryRunner runner=null;
    //静态块
    static {
        datasource=new ComboPooledDataSource("myConfig");
    }
    //构造
    public DBUtil(){
        runner=new QueryRunner(datasource);
    }

    //自定义查询
    public static int queryNum(String sql,Object... params){
        ResultSet result=null;
        try {
            Connection conn=datasource.getConnection();
            PreparedStatement statement=conn.prepareStatement(sql);
            for(int i=0;i<params.length;i++){
                statement.setString(i+1,(String)params[i]);
            }
            result=statement.executeQuery();
            //获取最后一行行数
            result.last();
            return result.getRow();
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            try {
                if(result!=null)
                    result.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return 0;
    }

    //较快查询数量
    public int queryNumber(String sql,Object... params){
        try {
            return (int)(long)runner.query(sql,new ScalarHandler(),params);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return 0;
    }

    //判断是否存在
    public  int exist(String sql,Object... params){

        try {

            return (int)(long)runner.query("select EXISTS ("+sql+") as 'exist'",new ScalarHandler(),params);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return 0;
    }

    //自定义执行
    public static int execute(String sql,Object... params){
        try{
            Connection conn = datasource.getConnection();
            PreparedStatement statement = conn.prepareStatement(sql);
            for (int i = 0; i < params.length; i++) {
                statement.setString(i + 1, (String) params[i]);
            }
            return statement.executeUpdate();
        }catch (SQLException e){
            e.printStackTrace();
        }
        return 0;
    }

    //取出图片流，1为学生，2为教师
    public static InputStream getPhoto(String name,int select) throws SQLException, IOException {
        Connection conn = datasource.getConnection();
        String sql="";
        if(select==1)
            sql="select photo_stream from stu_photo where photo_name='"+name+"'";
        if(select==2)
            sql="select photo_stream from tea_photo where photo_name='"+name+"'";
        PreparedStatement statement=conn.prepareStatement(sql);
        ResultSet rs=statement.executeQuery();
        if(rs.next()) {
            Blob blob=rs.getBlob(1);
            InputStream in=blob.getBinaryStream();
            rs.close();
            statement.close();
            return in;
        }

      return null;
    }

    //插入图片流
    public static void insertPhoto(String name, InputStream is, int select){
        try{
            Connection conn = datasource.getConnection();
            String sql="";
            if(select==1)
                sql="insert into stu_photo values (0,?,?)";
            if(select==2) {
                sql = "insert into tea_photo values (0,?,?)";
                System.out.println("执行");
            }

            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1,name);
            statement.setBlob(2,is,is.available());
            statement.executeUpdate();
            is.close();
            statement.close();
        }catch (SQLException e){
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //更新图片流
    public static void updatePhoto(String name, InputStream is, int select){
        try{
            Connection conn = datasource.getConnection();
            String sql="";
            if(select==1)
                sql="update stu_photo set photo_stream=? where photo_name=?";
            if(select==2) {
                sql ="update tea_photo set photo_stream=? where photo_name=?";
                System.out.println("执行");
            }

            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(2,name);
            statement.setBlob(1,is,is.available());
            statement.executeUpdate();
            is.close();
            statement.close();
        }catch (SQLException e){
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //查询
    public Object query(String sql, ResultSetHandler<?> rsh,Object... params){
        Object obj=null;
        try {
            obj=runner.query(sql,rsh,params);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return obj;
    }

    //Classes增删改
//    public boolean execute(Classes classes,int flag){
//        int num=0;
//        try {
//            switch (flag) {
//                case DBUtil.insert:
//                    num=runner.update("insert into classes values(?,?)",new String[]{classes.getCla_id(),classes.getCla_name()});
//                    break;
//                case DBUtil.update:
//                    num = runner.update("update classes set cla_name=? where cla_id=?", new String[]{classes.getCla_name(), classes.getCla_id()});
//                    break;
//                case DBUtil.delete:
//                    num=runner.update("delete from classes where cla_id=?",new String[]{classes.getCla_id()});
//                    break;
//            }
//        } catch (SQLException e) {
//            e.printStackTrace();
//        }
//        if(num>0)
//            return true;
//        else
//            return false;
//    }

    //Subject增删改
    public boolean execute(Subject subject, int flag){
        int num=0;
        try {
            switch (flag) {
                case DBUtil.insert:
                    num=runner.update("insert into subject values(?,?)",new String[]{subject.getSub_id(),subject.getSub_name()});
                    break;
                case DBUtil.update:
                    num = runner.update("update subject set sub_name=? where sub_id=?", new String[]{subject.getSub_name(), subject.getSub_id()});
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from subject where sub_id=?",new String[]{subject.getSub_id()});
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //Student增删改
    public boolean execute(Student student, int flag){
        int num=0;
        String[] info=null;
        try {
            switch (flag) {
                case DBUtil.insert:
                    info=new String[]{student.getStu_id(),student.getStu_num(),student.getStu_name(),student.getStu_sex(), student.getCla_name(),
                    student.getStu_identity(),student.getStu_email(),student.getStu_address(),student.getStu_photo(),student.getStu_password()};
                    num=runner.update("insert into students values (?,?,?,?,?,?,?,?,?,?)",info);
                    break;
                case DBUtil.update:
                    info=new String[]{student.getStu_num(),student.getStu_name(),student.getStu_sex(), student.getCla_name(),student.getStu_identity(),
                            student.getStu_email(),student.getStu_address(),student.getStu_photo(),student.getStu_password(),student.getStu_id()};
                    String sql="update students set stu_num=?,stu_name=?,stu_sex=?,cla_name=?,stu_identity=?,stu_email=?,stu_address=?,stu_photo=?,stu_password=? where stu_id=?";
                    num = runner.update(sql,info);
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from students where stu_id=?",new String[]{student.getStu_id()});
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //Teacher增删改
    public boolean execute(Teacher teacher, int flag){
        int num=0;
        String[] info=null;
        try {
            switch (flag) {
                case DBUtil.insert:
                    info=new String[]{teacher.getTea_id(),teacher.getTea_name(),teacher.getTea_sex(), teacher.getTea_identity(),
                            teacher.getTea_email(),teacher.getTea_address(),teacher.getTea_photo(),teacher.getAvg_code()};
                    num=runner.update("insert into teachers values(?,?,?,?,?,?,?,?)",info);
                    break;
                case DBUtil.update:
                    info=new String[]{teacher.getTea_name(),teacher.getTea_sex(), teacher.getTea_identity(),
                            teacher.getTea_email(),teacher.getTea_address(),teacher.getTea_photo(),teacher.getTea_id()};
                    num = runner.update("update teachers set tea_name=?,tea_sex=?,tea_identity=?,tea_email=?,tea_address=?,tea_photo=? where tea_id=?",info);
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from teachers where tea_id=?",teacher.getTea_id());
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //Schedule删改
    public boolean execute(Schedule schedule, int flag){
        int num=0;
        String[] info=null;
        try {
            switch (flag) {
                case DBUtil.insert:
                    info=new String[]{schedule.getSch_id(),schedule.getSch_name(),schedule.getSch_term(),schedule.getTea_name(),
                            schedule.getCla_name(),schedule.getSch_remark(),schedule.getAvg_code()};
                    num=runner.update("insert into schedule values (?,?,?,?,?,?,?)",info);
                    break;
                case DBUtil.update:
                    info=new String[]{schedule.getSch_name(),schedule.getSch_term(),schedule.getTea_name(),schedule.getCla_name(),schedule.getSch_remark(),schedule.getSch_id()};
                    num = runner.update("update schedule set sch_name=?,sch_term=?,tea_name=?,cla_name=?,sch_remark=? where sch_id=?",info);
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from schedule where sch_id=?",schedule.getSch_id());
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //SchEvaluation增删改
    public boolean execute(SchEvaluation schEvaluation, int flag){
        int num=0;
        String[] info=null;
        try {
            switch (flag) {
                case DBUtil.insert:
                    info=new String[]{schEvaluation.getEva_id(),schEvaluation.getSch_id(),schEvaluation.getEva_code(),
                            schEvaluation.getStu_num(),schEvaluation.getEva_time(),schEvaluation.getEva_text()};
                    num=runner.update("insert into schEvaluation values (?,?,?,?,?,?)",info);
                    break;
                case DBUtil.update:
                    info=new String[]{schEvaluation.getSch_id(),schEvaluation.getEva_code(),schEvaluation.getStu_num(),
                            schEvaluation.getEva_time(),schEvaluation.getEva_text(),schEvaluation.getEva_id()};
                    num = runner.update("update schEvaluation set sch_id=?,eva_code=?,stu_num=?,eva_time=?,eva_text=? where eva_id=?",info);
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from schEvaluation where eva_id=?",schEvaluation.getEva_id());
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //TeaEvaluation增删改
    public boolean execute(TeaEvaluation teaEvaluation, int flag){
        int num=0;
        String[] info=null;
        try {
            switch (flag) {
                case DBUtil.insert:
                    info=new String[]{teaEvaluation.getEva_id(),teaEvaluation.getTea_id(),teaEvaluation.getEva_code(),
                            teaEvaluation.getStu_num(),teaEvaluation.getEva_time(),teaEvaluation.getEva_text()};
                    num=runner.update("insert into teaEvaluation values (?,?,?,?,?,?)",info);
                    break;
                case DBUtil.update:
                    info=new String[]{teaEvaluation.getTea_id(),teaEvaluation.getEva_code(),teaEvaluation.getStu_num(),
                            teaEvaluation.getEva_time(),teaEvaluation.getEva_text(),teaEvaluation.getEva_id()};
                    num = runner.update("update teaEvaluation set tea_id=?,eva_code=?,stu_num=?,eva_time=?,eva_text=? where eva_id=?",info);
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from teaEvaluation where eva_id=?",teaEvaluation.getEva_id());
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //StuSch增删改
    public boolean execute(StuSch stuSch,int flag){
        int num=0;
        try {
            switch (flag) {
                case DBUtil.insert:
                    num=runner.update("insert into stu_sch values (?,?,?)",stuSch.getRela_id(),stuSch.getStu_num(),stuSch.getSch_id());
                    break;
                case DBUtil.update:
                    num = runner.update("update stu_sch set stu_num=?,sch_id=? where rela_id=?",stuSch.getStu_num(),stuSch.getSch_id(),stuSch.getRela_id());
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from stu_sch where rela_id=?",stuSch.getRela_id());
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    //StuTea增删改
    public boolean execute(StuTea stuTea,int flag){
        int num=0;
        try {
            switch (flag) {
                case DBUtil.insert:
                    num=runner.update("insert into stu_tea values (?,?,?)",stuTea.getRela_id(),stuTea.getStu_num(),stuTea.getTea_id());
                    break;
                case DBUtil.update:
                    num = runner.update("update stu_tea set stu_num=?,tea_id=? where rela_id=?",stuTea.getStu_num(),stuTea.getTea_id(),stuTea.getRela_id());
                    break;
                case DBUtil.delete:
                    num=runner.update("delete from stu_tea where rela_id=?",stuTea.getRela_id());
                    break;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(num>0)
            return true;
        else
            return false;
    }

    public static void main(String[] args){
        String name="23";
        switch (name){
            case "123":
                System.out.println("123");
                break;
            case "234":
                System.out.println("234");
                break;
            case "23":
                System.out.println("23");
                break;
        }
//        long start = System.currentTimeMillis();
//        DBUtil db=new DBUtil();
//        System.out.println(db.exist("select * from schEvaluation where stu_num='19'"));  //2697ms
////        DBUtil.exist("select * from schEvaluation where stu_num='11'");             //2529ms
////        DBUtil.queryNum("select * from schEvaluation where stu_num='11'");      //2690ms
//
//        long end = System.currentTimeMillis();
//        System.out.println("程序运行时间："+(end-start)+"ms");
//        int num=DBUtil.queryNum("select * from manager where username=? and password=?",new Object[]{"sa","123456"});
//        System.out.println(num);

//        测试插入teacher
//        Teacher teacher=new Teacher();
//        teacher.setTea_address("江西");
//        teacher.setTea_email("1780498115@qq.com");
//        teacher.setTea_identity("XXXXXXXXXXXXXXXXX");
//        teacher.setTea_name("刘凌杰");
//        teacher.setTea_photo("18460321931");
//        teacher.setTea_sex("男");
//        if(new DBUtil().execute(teacher,DBUtil.insert))
//            System.out.println("插入成功！");
//        else
//            System.out.println("插入失败！");
    }
}
