package cn.ecut.servlet;

import cn.ecut.model.User;
import cn.ecut.services.UserServices;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Objects;

/**
 * @author lujiapeng
 * @className UserRegisterServlet
 * @description 用于用户注册
 * @date 2020/9/17 15:18
 **/
@WebServlet("/user/register")
public class UserRegisterServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 接收参数
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String configPassword = request.getParameter("configPassword") ;

        String msg = "" ;
        User user = new User();
        user.setUsername(username);
        // 查找 User
        UserServices userServices = new UserServices();
        user = userServices.loadByUsername(user);
        if(Objects.isNull( user ) ) {
            // 如果是 null ，则表示 用户名可以使用
            if( Objects.isNull( password ) || Objects.isNull( configPassword )){
                // 此时表示 password 是空  或 configPassword 是空
                msg = "用户名或密码 为空" ;
                request.setAttribute("msg" , msg );
                request.getRequestDispatcher("/register.jsp").forward( request , response );
            }else{
                if( password .equals( configPassword )){
                    user = new User();
                    // 两次密码一致
                    user.setPassword( password );
                    user.setUsername( username );
                    boolean b = userServices.saveUser(user);
                    if( b ) {
                        request.getSession().setAttribute("user" , user );
                        response.sendRedirect(request.getContextPath()+"/index.jsp");
                    }else{
                        msg = "服务器错误！请联系管理员！" ;
                        request.setAttribute("msg" , msg );
                        request.getRequestDispatcher("/register.jsp").forward( request , response );
                    }
                }else{
                    // 两次密码不一致
                    msg = "两次密码不一致" ;
                    request.setAttribute("msg" , msg );
                    request.getRequestDispatcher("/register.jsp").forward( request , response );
                }
            }
        }else{
            // 用户名不可用
            msg = "用户名已经被使用" ;
            request.setAttribute("msg" , msg );
            request.getRequestDispatcher("/register.jsp").forward( request , response );
        }

    }
}
