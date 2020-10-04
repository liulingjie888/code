package cn.ecut.servlet;

import cn.ecut.model.Content;
import cn.ecut.services.ContentServices;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @author lujiapeng
 * @className ContentDetailServlet
 * @description TODO
 * @date 2020/9/18 16:10
 **/
@WebServlet("/content/detail")
public class ContentDetailServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String contentId = request.getParameter("id");
        ContentServices contentServices = new ContentServices() ;
        Content content = contentServices.loadById(Integer.valueOf( contentId ));
        request.setAttribute( "content" , content );
        request.getRequestDispatcher("/contentDetail.jsp").forward( request , response );
    }
}
