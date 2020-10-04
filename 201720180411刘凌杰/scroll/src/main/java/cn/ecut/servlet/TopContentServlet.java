package cn.ecut.servlet;

import cn.ecut.dao.ContentDao;
import cn.ecut.model.Content;
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
 * @author liulingjie
 * @date 20-9-19 下午6:08
 */
@WebServlet("/content/top")
public class TopContentServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        List<Content> list= new ContentDao().listTop();
        Map<String ,Object> map = new HashMap<>() ;
        if( list.size() > 0 ) {
            map.put("data", list);
            map.put("status", StatusCode.SUCCESS);
            map.put("msg", "成功");
        }else{
            map.put("status", StatusCode.SERVER_ERROR);
            map.put("msg", "失败");
        }
        resp.getWriter().write(JSON.toJSONString( map ));
    }
}
