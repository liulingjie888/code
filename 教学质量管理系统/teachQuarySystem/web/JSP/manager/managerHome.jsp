<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/3
  Time: 18:07
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    if (session.getAttribute("manager")==null) {
        session.setAttribute("manager", request.getAttribute("username"));
        session.setAttribute("DBUtil",new DBUtil());
    }
%>
<html>
<head>
    <meta charset="UTF-8">
    <title>教学测评系统</title>
    <link href="../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        div{
            margin:auto;
            height:50px;
            width:200px;
            padding-top:40px;
        }
        a{
            font-size:20px;
        }
        li{
            line-height:60px;
        }
        body{
            background-image:url("../../image/home.jpg");
        }
    </style>
</head>

<body>
<h2 align="center">教 学 质 量 网 络 评 测 系 统</h2>
<table align="center" width="1000">
    <tr>
        <td width="270"></td>
        <td width="270" align="right"><a href="/teachQuarySystem_war_exploded/JSP/manager/change_pawd.jsp">修改密码</a></td>
        <td width="98" align="center"><a href="/teachQuarySystem_war_exploded/index.jsp?destorySession=true">退出</a></td>
    </tr>
</table>



<%--<div align="center"><a href="${pageContext.request.contextPath}/JSP/manager/information/home.jsp">信息管理</a></div>--%>
<%--<div align="center"><a href="${pageContext.request.contextPath}/JSP/manager/evaluation/home.jsp">测评管理</a></div>--%>
<div id="information">
    <ul>
        <li>信息管理
            <ul>
                <li><a href="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_info.jsp">学生信息管理</a></li>
                <li><a href="${pageContext.request.contextPath}/JSP/manager/information/tea_info/tea_info.jsp">教师信息管理</a></li>
                <li> <a href="${pageContext.request.contextPath}/JSP/manager/information/sch_info/sch_info.jsp">课程信息管理</a></li>
            </ul>
        </li>
        <li>测评管理
            <ul>
                <li><a href="${pageContext.request.contextPath}/JSP/manager/evaluation/schEva_info/stu_eva/stu_sch.jsp">课程测评管理</a></li>
                <li><a href="${pageContext.request.contextPath}/JSP/manager/evaluation/teaEva_info/stu_eva/stu_tea.jsp">教师测评管理</a></li>
            </ul>
        </li>
    </ul>
</div>
</body>
<script>
    <c:if test="${param.success=='true'}">
    alert("修改密码成功！");
    </c:if>
</script>
</html>