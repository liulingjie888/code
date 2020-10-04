package cn.ecut.servlet;

import cn.ecut.model.User;
import cn.ecut.services.UserServices;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Objects;

/**
 * @author lujiapeng
 * @className UserLoginServlet
 * @description 用于用户登录
 * @date 2020/9/17 10:51
 **/
@WebServlet("/user/login")
public class UserLoginServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 接收参数
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        // 封装对象
        User user = new User();
        user.setUsername(username);
        user.setPassword(password);
        // 声明一个提示消息
        String msg = "" ;
        // 需要进入到数据库中查找
        UserServices userServices = new UserServices();
        user = userServices.loadByUsername(user);
        System.out.println("登入成功，用户id为"+user.getId());

        // 如果存在，则证明 有这个用户，如果不存在，则表示没有这个用户
        // 如果 登录成功，返回主页( index.jsp )
        // 如果登录失败，则 给出提示消息，并 回到 登录页面。
        if (Objects.nonNull(user)) {
            // 证明存在， 继续判断，密码是否相同
            if( user.getPassword().equals( password ) ) {
                // 此时证明 可以登录
                HttpSession session = request.getSession();
                session.setAttribute( "user" , user );
                // 转到主页 ： 重定向或 转发
                response.sendRedirect(request.getContextPath()+"/index.jsp");
            }else{
                // 登录失败
                msg = "用户名或密码错误" ;
                request.setAttribute("msg" , msg );
                request.getRequestDispatcher("/login.jsp").forward(request , response);
            }
        }else {
            // 此时证明不存在，那么需要进行提示，注册
            msg = "用户名不存在" ;
            request.setAttribute("msg" , msg );
            request.getRequestDispatcher("/login.jsp").forward(request , response);
        }

    }
}
