package com.jie.reqandresp;

import com.jie.object.*;
import com.jie.utiltool.DBUtil;
import org.apache.commons.dbutils.DbUtils;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

public class Update extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req,resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String type=req.getParameter("type");
        HttpSession session=req.getSession();
        DBUtil db=(DBUtil)session.getAttribute("DBUtil");

        //更新课程
        if("sch_info".equals(type)){
            Schedule schedule=new Schedule();
            schedule.setSch_id(req.getParameter("sch_id"));
            schedule.setCla_name(req.getParameter("cla_name"));
            schedule.setSch_name(req.getParameter("sch_name"));
            schedule.setSch_remark(req.getParameter("sch_remark"));
            schedule.setSch_term(req.getParameter("sch_term"));
            schedule.setTea_name(req.getParameter("tea_name"));

            if(db.execute(schedule,DBUtil.update))
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/sch_info/sch_update.jsp?success=true&id="+req.getParameter("sch_id"));
            else
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/sch_info/sch_update.jsp?success=false&id="+req.getParameter("sch_id"));
        }

        //更新学生
        if("stu_info".equals(type)){
            Student student=new Student();
            try {
                List<FileItem> fileitems=Insert.fileupload.parseRequest(req);
                System.out.println("图片处理中");
                for(FileItem item: fileitems){
                    if(item.isFormField()){
                        String name=item.getFieldName();
                        switch (name){
                            case "stu_num":
                                student.setStu_num(item.getString(DBUtil.charset));
                                break;
                            case "stu_id":
                                student.setStu_id(item.getString(DBUtil.charset));
                                break;
                            case "stu_sex":
                                student.setStu_sex(item.getString(DBUtil.charset));
                                break;
                            case "stu_name":
                                student.setStu_name(item.getString(DBUtil.charset));
                                break;
                            case "cla_name":
                                student.setCla_name(item.getString(DBUtil.charset));
                                break;
                            case "stu_email":
                                student.setStu_email(item.getString(DBUtil.charset));
                                break;
                            case "stu_address":
                                student.setStu_address(item.getString(DBUtil.charset));
                                break;
                            case "stu_identity":
                                student.setStu_identity(item.getString(DBUtil.charset).equals("")?null:item.getString(DBUtil.charset));
                                break;
                            case "stu_photo":
                                student.setStu_photo(item.getString(DBUtil.charset));
                                break;
                            case "stu_password":
                                student.setStu_password(item.getString(DBUtil.charset).equals("")?student.getStu_num():item.getString(DBUtil.charset));
                                break;
                        }
                    }else{
                        InputStream is=item.getInputStream();
                        DBUtil.updatePhoto(student.getStu_num(),is,1);
                    }
                }
            } catch (FileUploadException e) {
                e.printStackTrace();
            }


//            student.setStu_id(req.getParameter("stu_id"));
//            student.setStu_name(req.getParameter("stu_name"));
//            student.setCla_name(req.getParameter("cla_name"));
//            student.setStu_address(req.getParameter("stu_address"));
//            student.setStu_email(req.getParameter("stu_email"));
//            student.setStu_identity(req.getParameter("stu_identity"));
//            student.setStu_num(req.getParameter("stu_num"));
//            student.setStu_photo(req.getParameter("stu_photo"));
//            student.setStu_sex(req.getParameter("stu_sex"));
//            student.setStu_password((req.getParameter("stu_password").length()<=0?req.getParameter("stu_num"):req.getParameter("stu_password") ));
            if(db.execute(student,DBUtil.update)){
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_update.jsp?success=true&id="+student.getStu_id());
            }else
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_update.jsp?success=false&id="+student.getStu_id());

        }

        //更新教师
        if("tea_info".equals(type)){
            Teacher teacher=new Teacher();
            String tea_id=null;
            try {

                List<FileItem> fileitems=Insert.fileupload.parseRequest(req);
                System.out.println("图片处理中");
                for(FileItem item: fileitems){
                    if(item.isFormField()){
                        String name=item.getFieldName();
                        switch (name){
                            case "tea_id":
                                tea_id=item.getString(DBUtil.charset);
                                teacher.setTea_id(tea_id);
                                break;
                            case "tea_sex":
                                teacher.setTea_sex(item.getString(DBUtil.charset));
                                break;
                            case "tea_name":
                                teacher.setTea_name(item.getString(DBUtil.charset));
                                break;
                            case "tea_email":
                                teacher.setTea_email(item.getString(DBUtil.charset));
                                break;
                            case "tea_address":
                                teacher.setTea_address(item.getString(DBUtil.charset));
                                break;
                            case "tea_identity":
                                teacher.setTea_identity(item.getString(DBUtil.charset).equals("")?null:item.getString(DBUtil.charset));
                                break;
                            case "tea_photo":
                                teacher.setTea_photo(item.getString(DBUtil.charset));
                                break;
                        }
                    }else{
                        InputStream is=item.getInputStream();
                        DBUtil.updatePhoto(teacher.getTea_name(),is,2);
                    }
                }
            } catch (FileUploadException e) {
                e.printStackTrace();
            }

//            teacher.setTea_id(req.getParameter("tea_id"));
//            teacher.setTea_photo(req.getParameter("tea_photo"));
//            teacher.setTea_email(req.getParameter("tea_email"));
//            teacher.setTea_sex((req.getParameter("tea_sex")));
//            teacher.setTea_address(req.getParameter("tea_address"));
//            teacher.setTea_identity(req.getParameter("tea_identity"));
//            teacher.setTea_name(req.getParameter("tea_name"));
            if(db.execute(teacher,DBUtil.update)){
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/tea_info/tea_update.jsp?success=true&id="+tea_id);
            }else {
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/tea_info/tea_update.jsp?success=false&id="+tea_id);
            }
        }

        if("schEva_info".equals(type)){
            SchEvaluation evaluation=new SchEvaluation();
            evaluation.setEva_code(req.getParameter("eva_code"));
            evaluation.setEva_time(req.getParameter("eva_time"));
            evaluation.setStu_num(req.getParameter("stu_num"));
            evaluation.setEva_text(req.getParameter("eva_text"));
            evaluation.setEva_id(req.getParameter("eva_id"));
            evaluation.setSch_id(req.getParameter("sch_id"));
            if(db.execute(evaluation,DBUtil.update)){
                //代替触发器
                String sql="update schedule set avg_code= (select AVG(eva_code) from schEvaluation where sch_id=?) where sch_id=?";
                DBUtil.execute(sql,req.getParameter("sch_id"),req.getParameter("sch_id"));
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/schEva_info/schEva_update.jsp?success=true&id="+req.getParameter("eva_id"));
            }else {
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/schEva_info/schEva_update.jsp?success=false&id="+req.getParameter("eva_id"));
            }
        }

        if("teaEva_info".equals(type)){
            TeaEvaluation evaluation=new TeaEvaluation();
            evaluation.setEva_code(req.getParameter("eva_code"));
            evaluation.setEva_time(req.getParameter("eva_time"));
            evaluation.setStu_num(req.getParameter("stu_num"));
            evaluation.setEva_text(req.getParameter("eva_text"));
            evaluation.setEva_id(req.getParameter("eva_id"));
            evaluation.setTea_id(req.getParameter("tea_id"));
            if(db.execute(evaluation,DBUtil.update)){
                //代替触发器
                String sql="update teachers set avg_code= (select AVG(eva_code) from teaEvaluation where tea_id=?) where tea_id=?";
                DBUtil.execute(sql,req.getParameter("tea_id"),req.getParameter("tea_id"));
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/teaEva_info/teaEva_update.jsp?success=true&id="+req.getParameter("eva_id"));
            }else {
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/teaEva_info/teaEva_update.jsp?success=false&id="+req.getParameter("eva_id"));
            }
        }

        //修改密码
        if("student_pawd".equals(type)){
            String status="";
            String password=req.getParameter("initial_pawd");
            String stu_num=req.getParameter("stu_num");
            int num=DBUtil.queryNum("select * from students where stu_num=? and stu_password=?",stu_num,password);
            if(num>0){
                password=req.getParameter("first_pawd");
                num=DBUtil.execute("update students set stu_password=? where stu_num=?",password,stu_num);
                if(num>0) {
                    status = "true";
                    System.out.println("修改成功");
                } else {
                    status = "false";
                    System.out.println("修改失败");
                }
                req.getRequestDispatcher("/JSP/student/studentHome.jsp?success="+status).forward(req,resp);
            }else {
                String hint="  原密码不正确";
                req.getRequestDispatcher("/JSP/student/change_pawd.jsp?hint="+hint).forward(req,resp);
            }

        }

        //修改密码
        if("manager_pawd".equals(type)){
            String status="";
            String password=req.getParameter("initial_pawd");
            String manager=req.getParameter("manager");
            int num=DBUtil.queryNum("select * from manager where username=? and password=?",manager,password);
            if(num>0){
                password=req.getParameter("first_pawd");
                num=DBUtil.execute("update manager set password=? where username=?",password,manager);
                if(num>0) {
                    status = "true";
                    System.out.println("修改成功");
                } else {
                    status = "false";
                    System.out.println("修改失败");
                }
                req.getRequestDispatcher("/JSP/manager/managerHome.jsp?success="+status).forward(req,resp);
            }else {
                String hint="  原密码不正确";
                req.getRequestDispatcher("/JSP/manager/change_pawd.jsp?hint="+hint).forward(req,resp);
            }

        }

    }
}
