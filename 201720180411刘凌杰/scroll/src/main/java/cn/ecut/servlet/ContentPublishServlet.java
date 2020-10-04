package cn.ecut.servlet;

import cn.ecut.model.Content;
import cn.ecut.model.User;
import cn.ecut.services.ContentServices;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @author lujiapeng
 * @className ContentPublishServlet
 * @description 针对于内容发布
 * @date 2020/9/18 9:41
 **/
@WebServlet("/content/publish")
public class ContentPublishServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String content = request.getParameter("content");
        System.out.println( content );
        // 获取用户
        Object o = request.getSession().getAttribute("user");
        User user = null ;
        if( o instanceof User) {
            user = (User) o ;
        }

        // 发布内容
        // 1、封装一个对象
        Content c = new Content() ;
        c.setContent( content );
        c.setUser( user );

        // 2、利用service 中的方法，处理业务
        ContentServices cs = new ContentServices() ;
        boolean result = cs.addContent( c ) ;
        String msg = "" ;
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
