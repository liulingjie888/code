package cn.ecut.servlet;

import cn.ecut.model.Content;
import cn.ecut.services.ContentServices;
import cn.ecut.util.StatusCode;
import com.alibaba.fastjson.JSON;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author lujiapeng
 * @className ContentListServlet
 * @description TODO
 * @date 2020/9/18 10:06
 **/
@WebServlet("/content/list")
public class ContentListServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //  先获取15条
        String num = request.getParameter("num");
        Integer begin = Integer.valueOf( num ) ;
        ContentServices contentServices = new ContentServices() ;
        List<Content> list =  contentServices.list( begin ) ;
        System.out.println("获取获取"+begin);
        Map<String ,Object> map = new HashMap<>() ;
        if( list.size() > 0 ) {
            map.put("data", list);
            map.put("status", StatusCode.SUCCESS);
            map.put("msg", "成功");
        }else{
            map.put("status", StatusCode.SERVER_ERROR);
            map.put("msg", "失败");
        }
        response.getWriter().write(JSON.toJSONString( map ));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req,resp);
    }
}
