<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/3
  Time: 18:07
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%
    if(session.getAttribute("student")==null) {
        session.setAttribute("student", request.getAttribute("username"));
        session.setAttribute("DBUtil",new DBUtil());
    }
%>
<html>
<head>
    <meta charset="UTF-8">
    <title>教学测评系统</title>
    <style>
        div{
            font-size:22px;
            margin:auto;
            height:50px;
            width:200px;
            padding-top:60px
        }
        table{
            font-size:19px;
        }
        body{
            background-image:url("../../image/home.jpg");
        }
    </style>
</head>

<body>
<h2 align="center">教&nbsp;学&nbsp;质&nbsp;量&nbsp;网&nbsp;络&nbsp;评&nbsp;测&nbsp;系&nbsp;统</h2><br>
<table width="1000" border="0" cellspacing="0" cellpadding="0" align="center">
    <tr>
        <td width="690">&nbsp;</td>
        <td width="125"><a href="${pageContext.request.contextPath}/JSP/student/student_info.jsp">个人信息</a></td>
        <td width="125"><a href="${pageContext.request.contextPath}/JSP/student/change_pawd.jsp">修改密码</a></td>
        <td width="185"><a href="/teachQuarySystem_war_exploded/index.jsp?destorySession=true">退出</a></td>
    </tr>
</table>
<div align="center">
    <a href="${pageContext.request.contextPath}/JSP/student/tea_info/tea_info.jsp" >教师测评</a>
</div>
<p></p>
<div align="center">
    <a href="${pageContext.request.contextPath}/JSP/student/sch_info/sch_info.jsp">课程测评</a>
</div>
</body>
<script>
    <c:if test="${param.success=='true'}">
        alert("修改密码成功！");
    </c:if>
</script>
</html>
