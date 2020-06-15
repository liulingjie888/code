<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 17:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
//    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
//    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    if (searchText.equals("") || searchText==null){
        request.getRequestDispatcher("/JSP/student/sch_info/showRela.jsp").forward(request,response);
        return;
    }else {
        request.getRequestDispatcher("/JSP/student/sch_info/showAll.jsp").forward(request,response);
        return;
    }
%>