package com.jie.reqandresp;

import com.jie.object.Classes;
import com.jie.object.Schedule;
import com.jie.object.Teacher;
import com.jie.utiltool.DBUtil;
import org.apache.commons.dbutils.DbUtils;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Search extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String type=req.getParameter("type");
        String search=req.getParameter("searchText");
        if(search==null || type==null)return;

        HttpSession session=req.getSession();
        DBUtil db=(DBUtil)session.getAttribute("DBUtil");

        StringBuilder html=new StringBuilder("<table align=\"center\">");
        if(type.equals("teacher")){
            List<Teacher> list=(ArrayList<Teacher>)db.query("select * from teachers where tea_name like '%"+search+"%'",new BeanListHandler(Teacher.class));
            html.append("<tr><td>ID</td><td>姓名</td><td>性别</td><td>电话</td><td></td></tr>");
            for(int i=0;i<list.size();i++){
                html.append("<tr>");
                html.append("<td>"+list.get(i).getTea_id()+"</td>");
                html.append("<td>"+list.get(i).getTea_name()+"</td>");
                html.append("<td>"+list.get(i).getTea_sex()+"</td>");
                html.append("<td>"+list.get(i).getTea_photo()+"</td>");
                int num=DBUtil.queryNum("select * from teaEvaluation where tea_id=? and stu_num=?",list.get(i).getTea_id(),session.getAttribute("student") );
                if(num>0)
                    html.append("<td><a href=\"http://liulingjie.cn:8080/teachQuarySystem_war_exploded/JSP/student/tea_eva.jsp?isEva=true&id="+list.get(i).getTea_id()+"\">已测评</a></td>");
                else
                    html.append("<td><a href=\"http://liulingjie.cn:8080/teachQuarySystem_war_exploded/JSP/student/tea_eva.jsp?isEva=false&id="+list.get(i).getTea_id()+"\">测评</a></td>");
                html.append("</tr>");
            }
            html.append("</table>");
            resp.getWriter().println(html.toString());
        }

        if(type.equals("schedule")){
            List<Schedule> list=(ArrayList<Schedule>)db.query("select * from schedule where sch_name like '%"+search+"%'",new BeanListHandler(Schedule.class));
            html.append("<tr><td>ID</td><td>课程名</td><td>班级</td><td>学期</td><td>教师</td><td>备注</td>");

            for(int i=0;i< list.size();i++){
                html.append("<tr>");
                html.append("<td>"+list.get(i).getSch_id()+"</td>");
                html.append("<td>"+list.get(i).getSch_name()+"</td>");
                html.append("<td>"+list.get(i).getCla_name()+"</td>");
                html.append("<td>"+ list.get(i).getSch_term()+"</td>");
                html.append("<td>"+list.get(i).getTea_name()+"</td>");
                html.append("<td"+list.get(i).getSch_remark()+"</td>");
                int num=DBUtil.queryNum("select * from schEvaluation where sch_id=? and stu_num=?",list.get(i).getSch_id(),session.getAttribute("student"));
                if(num>0)
                    html.append("<td><a href=\"http://liulingjie.cn:8080/teachQuarySystem_war_exploded/JSP/student/sch_eva.jsp?isEva=true&id="+list.get(i).getSch_id()+"\">已测评</a></td>");
                else
                    html.append("<td><a href=\"http://liulingjie.cn:8080/teachQuarySystem_war_exploded/JSP/student/sch_eva.jsp?isEva=false&id="+list.get(i).getSch_id()+"\">测评</a></td>");
                html.append("</tr>");
            }
            html.append("</table>");
            resp.getWriter().println(html.toString());
        }

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
