package com.jie.reqandresp;

import com.jie.object.*;
import com.jie.utiltool.DBUtil;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class Insert extends HttpServlet {
    protected static DiskFileItemFactory factory=null;
    protected static ServletFileUpload fileupload=null;
    static {
        factory=new DiskFileItemFactory();
        factory.setSizeThreshold(102400000);
        File photo=new File("D:\\photo");
        if(!photo.exists()){
            photo.mkdirs();
        }
        factory.setRepository (photo);

        fileupload=new ServletFileUpload( factory );
        fileupload.setHeaderEncoding("utf-8");
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        DBUtil db = (DBUtil) req.getSession().getAttribute("DBUtil");
        String type=req.getParameter("type");
        if("teaEva".equals(type)) {
            String eva_text = req.getParameter("eva_text");
            String eva_code = req.getParameter("eva_code");
            String tea_id = req.getParameter("tea_id");
            String stu_num = req.getParameter("stu_num");
            Date day = new Date();
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

            TeaEvaluation teaeva = new TeaEvaluation();
            teaeva.setTea_id(tea_id);
            teaeva.setEva_code(eva_code);
            teaeva.setEva_text(eva_text);
            teaeva.setStu_num(stu_num);
            teaeva.setEva_time(sdf.format(day));
            if(db.execute(teaeva,DBUtil.insert)) {
                //代替触发器
                String sql="update teachers set avg_code= (select AVG(eva_code) from teaEvaluation where tea_id=?) where tea_id=?";
                DBUtil.execute(sql,tea_id,tea_id);
                resp.sendRedirect(req.getContextPath() + "/JSP/student/tea_info/tea_eva.jsp?success=true&isEva=true&id=" + tea_id);
            }else {
                resp.sendRedirect(req.getContextPath() + "/JSP/student/tea_info/tea_eva.jsp?success=false&isEva=false");
            }
        }

        if("schEva".equals(type)){
            SchEvaluation scheva=new SchEvaluation();
            Date day = new Date();
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
            scheva.setSch_id(req.getParameter("sch_id"));
            scheva.setEva_code(req.getParameter("eva_code"));
            scheva.setStu_num(req.getParameter("stu_num"));
            scheva.setEva_text(req.getParameter("eva_text"));
            scheva.setEva_time(sdf.format(day));
            if(db.execute(scheva,DBUtil.insert)) {
                //代替触发器
                String sql="update schedule set avg_code= (select AVG(eva_code) from schEvaluation where sch_id=?) where sch_id=?";
                DBUtil.execute(sql,req.getParameter("sch_id"),req.getParameter("sch_id"));
                resp.sendRedirect(req.getContextPath() + "/JSP/student/sch_info/sch_eva.jsp?success=true&isEva=true&id="+req.getParameter("sch_id"));
            }else {
                resp.sendRedirect(req.getContextPath() + "/JSP/student/sch_info/sch_eva.jsp?success=false&isEva=false");
            }
        }

        if("sch_info".equals(type)){
            Schedule schedule=new Schedule();
            schedule.setTea_name(req.getParameter("tea_name"));
            schedule.setSch_term(req.getParameter("sch_term"));
            schedule.setSch_name(req.getParameter("sch_name"));
            schedule.setCla_name(req.getParameter("cla_name"));
            schedule.setSch_remark(req.getParameter("sch_remark"));
            if(db.execute(schedule,DBUtil.insert)){
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/sch_info/sch_insert.jsp?success=true");
            }else
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/sch_info/sch_insert.jsp?success=false");
        }

        if("stu_info".equals(type)){
            Student student=new Student();

            try {
                List<FileItem> fileitems=fileupload.parseRequest(req);
                System.out.println("图片处理中");
                for(FileItem item: fileitems){
                    if(item.isFormField()){
                        String name=item.getFieldName();
                        switch (name){
                            case "stu_num":
                                student.setStu_num(item.getString(DBUtil.charset));
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
                        DBUtil.insertPhoto(student.getStu_num(),is,1);
                    }
                }
            } catch (FileUploadException e) {
                e.printStackTrace();
            }

//            student.setStu_password((req.getParameter("stu_password").length()<=0?req.getParameter("stu_num"):req.getParameter("stu_password") ));
//            student.setStu_sex(req.getParameter("stu_sex"));
//            student.setStu_photo(req.getParameter("stu_photo"));
//            student.setStu_num(req.getParameter("stu_num"));
//            String identity=req.getParameter("stu_identity");
//            student.setStu_identity(identity.equals("")?null:identity);
//            student.setStu_email(req.getParameter("stu_email"));
//            student.setStu_address(req.getParameter("stu_address"));
//            student.setStu_name(req.getParameter("stu_name"));
//            student.setCla_name(req.getParameter("cla_name"));
            if(db.execute(student, DBUtil.insert)){
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_insert.jsp?success=true");
            }else
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_insert.jsp?success=false");

        }

        if("tea_info".equals(type)){
            Teacher teacher=new Teacher();
            try {
                List<FileItem> fileitems=fileupload.parseRequest(req);
                System.out.println("图片处理中");
                for(FileItem item: fileitems){
                    if(item.isFormField()){
                       String name=item.getFieldName();
                       switch (name){
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
                        DBUtil.insertPhoto(teacher.getTea_name(),is,2);
                    }
                }
            } catch (FileUploadException e) {
                e.printStackTrace();
            }

//            Teacher teacher=new Teacher();
//            teacher.setTea_sex(req.getParameter("tea_sex"));
//            teacher.setTea_name(req.getParameter("tea_name"));
//            teacher.setTea_email(req.getParameter("tea_email"));
//            teacher.setTea_address(req.getParameter("tea_address"));
//            teacher.setTea_identity(req.getParameter("tea_identity"));
//            teacher.setTea_photo(req.getParameter("tea_photo"));

            if(db.execute(teacher,DBUtil.insert)){
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/tea_info/tea_insert.jsp?success=true");
            }else
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/tea_info/tea_insert.jsp?success=false");
        }

        if("schEva_info".equals(type)){
            SchEvaluation schEvaluation=new SchEvaluation();
            schEvaluation.setSch_id(req.getParameter("sch_id"));
            schEvaluation.setEva_text(req.getParameter("eva_text"));
            schEvaluation.setEva_time(req.getParameter("eva_time"));
            schEvaluation.setStu_num(req.getParameter("stu_num"));
            schEvaluation.setEva_code(req.getParameter("eva_code"));
            if(db.execute(schEvaluation,DBUtil.insert)){
                //代替触发器
                String sql="update schedule set avg_code= (select AVG(eva_code) from schEvaluation where sch_id=?) where sch_id=?";
                DBUtil.execute(sql,req.getParameter("sch_id"),req.getParameter("sch_id"));
                    resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/schEva_info/schEva_insert.jsp?success=true");
            }else
                    resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/schEva_info/schEva_insert.jsp?success=false");
        }

        if("teaEva_info".equals(type)){
            TeaEvaluation teaEvaluation=new TeaEvaluation();
            teaEvaluation.setTea_id(req.getParameter("tea_id"));
            teaEvaluation.setEva_text(req.getParameter("eva_text"));
            teaEvaluation.setEva_time(req.getParameter("eva_time"));
            teaEvaluation.setStu_num(req.getParameter("stu_num"));
            teaEvaluation.setEva_code(req.getParameter("eva_code"));
            if(db.execute(teaEvaluation,DBUtil.insert)){
                //代替触发器
                String sql="update teachers set avg_code= (select AVG(eva_code) from teaEvaluation where tea_id=?) where tea_id=?";
                DBUtil.execute(sql,req.getParameter("tea_id"),req.getParameter("tea_id"));
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/teaEva_info/teaEva_insert.jsp?success=true");
            }else
                resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/teaEva_info/teaEva_insert.jsp?success=false");
        }

        if("stu_sch".equals(type)){
            String[] id=(String[])req.getSession(false).getAttribute("students");
            String sch_id=req.getParameter("sch_id");
            StuSch stuSch=new StuSch();stuSch.setSch_id(sch_id);
            for(int i=0;i<id.length;i++){
                stuSch.setStu_num(id[i]);
                db.execute(stuSch,DBUtil.insert);
            }
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_rela.jsp?type=sch&success=true");
        }

        if("stu_tea".equals(type)){
            String[] id=(String[])req.getSession(false).getAttribute("students");
            String sch_id=req.getParameter("tea_id");
            StuTea stuTea=new StuTea();stuTea.setTea_id(sch_id);
            for(int i=0;i<id.length;i++){
                stuTea.setStu_num(id[i]);
                db.execute(stuTea,DBUtil.insert);
            }
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_rela.jsp?type=tea&success=true");
        }
    }
}
