package com.jie.reqandresp;

import com.jie.utiltool.DBUtil;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class Delete extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String type=req.getParameter("type");
        HttpSession session=req.getSession();
        DBUtil db=(DBUtil)session.getAttribute("DBUtil");

        if(type.equals("sch_info")){
             String[] deleteId=req.getParameterValues("delete");
             if(deleteId==null) {
                 resp.sendRedirect(req.getContextPath() + "/JSP/manager/information/sch_info/sch_info.jsp");
                 return;
             }

             for(int i=0;i<deleteId.length;i++){
                 DBUtil.execute("delete from schedule where sch_id=?",deleteId[i]);
             }

             resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/sch_info/sch_info.jsp");
        }

        if(type.equals("stu_info")){
            String[] deleteId=req.getParameterValues("delete");
            if(deleteId==null) {
                resp.sendRedirect(req.getContextPath() + "/JSP/manager/information/stu_info/stu_info.jsp");
                return;
            }

            for(int i=0;i<deleteId.length;i++){
                DBUtil.execute("delete from students where stu_id=?",deleteId[i]);
            }
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/stu_info.jsp");
        }

        if(type.equals("tea_info")){
            String[] deleteId=req.getParameterValues("delete");
            if(deleteId==null) {
                resp.sendRedirect(req.getContextPath() + "/JSP/manager/information/tea_info/tea_info.jsp");
                return;
            }

            for(int i=0;i<deleteId.length;i++){
                DBUtil.execute("delete from teachers where tea_id=?",deleteId[i]);
            }
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/tea_info/tea_info.jsp");
        }

        if(type.equals("schEva_info")){
            String[] deleteId=req.getParameterValues("delete");
            if(deleteId==null) {
                resp.sendRedirect(req.getContextPath() + "/JSP/manager/evaluation/schEva_info/schEva_info.jsp");
                return;
            }

            for(int i=0;i<deleteId.length;i++){
                DBUtil.execute("delete from schEvaluation where eva_id=?",deleteId[i]);
            }
            //代替触发器
            String sql="update schedule set avg_code= (select AVG(eva_code) from schEvaluation where sch_id=?) where sch_id=?";
            DBUtil.execute(sql,req.getParameter("sch_id"),req.getParameter("sch_id"));
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/schEva_info/schEva_info.jsp");
        }

        if(type.equals("teaEva_info")){
            String[] deleteId=req.getParameterValues("delete");
            if(deleteId==null) {
                resp.sendRedirect(req.getContextPath() + "/JSP/manager/evaluation/teaEva_info/teaEva_info.jsp");
                return;
            }

            for(int i=0;i<deleteId.length;i++){
                DBUtil.execute("delete from teaEvaluation where eva_id=?",deleteId[i]);
            }
            //代替触发器
            String sql="update teachers set avg_code= (select AVG(eva_code) from teaEvaluation where tea_id=?) where tea_id=?";
            DBUtil.execute(sql,req.getParameter("tea_id"),req.getParameter("tea_id"));
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/evaluation/teaEva_info/teaEva_info.jsp");
        }

        if(type.equals("stu_sch")){
            String[] deleteId=req.getParameterValues("delete");
            if(deleteId==null) {
                resp.sendRedirect(req.getContextPath() + "/JSP/manager/information/stu_info/relative/sch.jsp");
                return;
            }
            for(int i=0;i<deleteId.length;i++){
                DBUtil.execute("delete from stu_sch where rela_id=?",deleteId[i]);
            }
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/relative/sch.jsp");
        }

        if(type.equals("stu_tea")){
            String[] deleteId=req.getParameterValues("delete");
            if(deleteId==null) {
                resp.sendRedirect(req.getContextPath() + "/JSP/manager/information/stu_info/relative/tea.jsp");
                return;
            }
            for(int i=0;i<deleteId.length;i++){
                DBUtil.execute("delete from stu_tea where rela_id=?",deleteId[i]);
            }
            resp.sendRedirect(req.getContextPath()+"/JSP/manager/information/stu_info/relative/tea.jsp");
        }

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req,resp);
    }
}
