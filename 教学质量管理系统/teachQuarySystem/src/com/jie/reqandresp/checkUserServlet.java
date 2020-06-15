package com.jie.reqandresp;

import com.jie.object.Manager;
import com.jie.utiltool.DBUtil;
import org.apache.commons.dbutils.handlers.BeanHandler;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLEncoder;

public class checkUserServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        resp.setContentType("text/html;charset=utf-8");
        String username=req.getParameter("username");
        String password=req.getParameter("password");
        String manager=req.getParameter("manager");
        DBUtil db=new DBUtil();
        if(manager!=null && manager.equals("power")){
            //管理员登入
            int num=db.queryNumber("select count(*) from manager where username=? and password=?",new Object[]{username,password});
            if(num>0) {
                req.setAttribute("username", username);
                req.getRequestDispatcher("/JSP/manager/managerHome.jsp").forward(req, resp);
                return;
            }
        }else{
            //学生登入
            int num=db.queryNumber(("select count(*) from students where stu_num=? and stu_password=?"),new Object[]{username,password});
            if(num>0) {
                req.setAttribute("username", username);
                req.getRequestDispatcher("/JSP/student/studentHome.jsp").forward(req, resp);
                return;
            }
        }
        req.getRequestDispatcher("/index.jsp?error=passwordWrong").forward(req,resp);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req,resp);
    }
}
