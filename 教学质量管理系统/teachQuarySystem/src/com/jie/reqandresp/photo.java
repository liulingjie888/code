package com.jie.reqandresp;

import com.jie.utiltool.DBUtil;
import org.apache.commons.dbutils.DbUtils;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLDecoder;
import java.sql.SQLException;

public class photo extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //判断学生还是老师
        int select=Integer.parseInt(req.getParameter("select"));
        String name=req.getParameter("name");
        System.out.println("名字为"+name+"\n"+ URLDecoder.decode(name,DBUtil.charset));
        try {
            InputStream in=DBUtil.getPhoto(name,select);
            //先将数据读入到内存
            ByteArrayOutputStream abos=new ByteArrayOutputStream();
            byte[] data=new byte[1024];
            int len=0;
            while((len=in.read(data,0,1024))!=-1){
                abos.write(data,0,len);
            }
            abos.writeTo(resp.getOutputStream());
            in.close();
            abos.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
