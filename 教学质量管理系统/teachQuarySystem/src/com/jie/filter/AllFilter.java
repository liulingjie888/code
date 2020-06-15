package com.jie.filter;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.UnsupportedEncodingException;

public class AllFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        CharacterRequest req=new CharacterRequest((HttpServletRequest)servletRequest);
        HttpServletResponse resp=(HttpServletResponse)servletResponse;
        req.setCharacterEncoding("utf-8");

        resp.setContentType("text/html;charset=utf-8");
        HttpSession session= req.getSession();

        //管理员已登入，或身份验证请求，则通过
        if(  session.getAttribute("manager")!=null|| req.getRequestURI().endsWith("checkUserServlet")) {
            System.out.println("manager这里通过");
            filterChain.doFilter(req, resp);
            return;
        }
        //学生已登入且访问的URL中不含manager，则通过
        if(session.getAttribute("student")!=null && !req.getRequestURI().contains("manager")){
            System.out.println("student这里通过");
            filterChain.doFilter(req,resp);
            return;
        }
        System.out.println("这里通过");
        req.getRequestDispatcher("/index.jsp").forward(req,resp);
    }

    @Override
    public void destroy() {

    }

    class CharacterRequest extends HttpServletRequestWrapper{
        private HttpServletRequest request;
        public CharacterRequest(HttpServletRequest request){
            super(request);
            this.request=request;
        }
        @Override
        public String getParameter(String name){
            String value=super.getParameter(name);
            if(value==null){
                return null;
            }
            String method=super.getMethod();
            if("get".equalsIgnoreCase(method)){
                    System.out.println(request.getRequestURI()+"前: "+value);
//                try{
//                    value=new String(value.getBytes("iso-8859-1"),"utf-8");
//                    System.out.println("后: "+value);
//                }catch (UnsupportedEncodingException e){
//                    throw new RuntimeException();
//                }
            }
            return value;
        }
    }
}
