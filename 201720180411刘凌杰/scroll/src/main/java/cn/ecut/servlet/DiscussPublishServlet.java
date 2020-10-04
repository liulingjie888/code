package cn.ecut.servlet;

import cn.ecut.model.Discuss;
import cn.ecut.model.User;
import cn.ecut.services.DiscussServices;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @author lujiapeng
 * @className DiscussPublishServlet
 * @description TODO
 * @date 2020/9/18 16:37
 **/
@WebServlet("/discuss/publish")
public class DiscussPublishServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String contentId = request.getParameter("contentId");
        String content = request.getParameter("content");

        Discuss discuss = new Discuss() ;
        discuss.setDiscussContent( content );


        String msg = "" ;
        // 获取用户
        Object o = request.getSession().getAttribute("user");
        User user = null ;
        if( o instanceof  User ) {
            user = (User) o ;
        }else{
            // 此时证明没有登录
            msg = "没有登录" ;
            request.setAttribute("msg" , msg );
            request.getRequestDispatcher("/fail.jsp").forward( request , response );
        }
        discuss.setUser( user );
        DiscussServices discussServices = new DiscussServices() ;
        boolean result = discussServices.add( discuss , contentId ) ;

        if( result ){
            // 发布成功，回到主页
            msg = "发布成功" ;
            request.setAttribute("msg" , msg );
            request.getRequestDispatcher("/success.jsp").forward( request , response );
        }else{
            msg = "发布失败" ;
            request.setAttribute("msg" , msg );
            request.getRequestDispatcher("/fail.jsp").forward( request , response );
        }

    }
}
