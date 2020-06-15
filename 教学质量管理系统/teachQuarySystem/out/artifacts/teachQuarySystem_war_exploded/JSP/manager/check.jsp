<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/10
  Time: 13:40
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String value=request.getParameter("value");
    int num=0;
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
    System.out.println("类型"+request.getParameter("type"));
%>
<c:choose>
    <c:when test="${param.type== 'cla'}" ><%
        num=db.exist("select * from students where cla_name=?",value);
    %></c:when>
    <c:when test="${param.type== 'tea_name'}"><%
        num=db.exist("select * from teachers where tea_name=?",value);
    %></c:when>
    <c:when test="${param.type== 'tea_id'}"><%
        num=db.exist("select * from teachers where tea_id=?",value);
        System.out.println("教师ID为"+num);
    %></c:when>
    <c:when test="${param.type== 'sch'}"><%
        num=db.exist("select * from schedule where sch_id=?",value);
    %></c:when>
    <c:when test="${param.type== 'stu'}"><%
        num=db.exist("select * from students where stu_num=?",value);
    %></c:when>
</c:choose>

<%--<%--%>
    <%--if(num>0){--%>
        <%--response.getWriter().println("exist");--%>
    <%--}else{--%>
        <%--response.getWriter().println("noexist");--%>
    <%--}--%>
<%--%>--%>
<c:set var="num" value="<%=num%>"/>

<c:if test="${num>0}">
    <c:out value="exist" escapeXml="true"/>
</c:if>

<c:if test="${num<=0}">
    <c:out value="noexist" escapeXml="true"/>
</c:if>