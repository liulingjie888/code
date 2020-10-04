package cn.ecut.filter;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.Charset;

/**
 * @author lujiapeng
 * @className CharacterEncodingFilter
 * @description TODO
 * @date 2020/9/15 9:44
 **/

public class CharacterEncodingFilter implements Filter {

    // 声明一个 filed , 为了维护 在所有方法中，都可以访问。
    private String encoding ;

    @Override
    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest request = (HttpServletRequest)req ;
        HttpServletResponse response = (HttpServletResponse)resp ;
        // 为 request 和 response 设置编码
        request.setCharacterEncoding(this.encoding);
        response.setCharacterEncoding(this.encoding);
        response.setContentType("text/html;charset="+this.encoding);
        // 将 数据 继续执行。
        chain.doFilter( request , response );
    }

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        // FilterConfig 与 ServletConfig 对象 差不多！
        // 获取 初始化参数
        String encoding = filterConfig.getInitParameter("encoding");
        // 需要检查( 为了防止一些奇奇怪怪的东西 )
        if ( encoding == null ||  encoding.trim().isEmpty() || !Charset.isSupported( encoding )){
            this.encoding = "UTF-8";
        }else{
            this.encoding = encoding ;
        }

    }

    @Override
    public void destroy() {
    }
}
