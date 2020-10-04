package cn.ecut.servlet;

import cn.ecut.model.User;
import cn.ecut.util.StatusCode;
import com.alibaba.fastjson.JSON;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * @author lujiapeng
 * @className GetUserInfoServlet
 * @description TODO
 * @date 2020/9/17 16:36
 **/
@WebServlet("/user/getInfo")
public class GetUserInfoServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Object user = request.getSession().getAttribute("user");
        Map<String ,Object> map = new HashMap<>() ;
        String msg = "" ;
        if( user instanceof User){
            msg = "获取成功" ;
            User u = (User) user ;
            map.put( "data" , u  ) ;
            map.put( "msg" , msg ) ;
            map.put("status" ,  StatusCode.SUCCESS ) ;
        }else{
            msg = "获取失败" ;
            map.put("msg" , msg ) ;
            map.put("status" , StatusCode.SERVER_ERROR) ;
            map.put("data" , null ) ;
        }
        response.getWriter().write(JSON.toJSONString( map ));
    }
}
