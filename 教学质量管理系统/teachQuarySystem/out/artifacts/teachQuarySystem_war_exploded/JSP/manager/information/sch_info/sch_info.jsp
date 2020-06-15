<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/7
  Time: 17:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>课程信息管理</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/searchPage.js"></script>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/deleleCheck.js"></script>
</head>
<body>
<h2 align="center">课程信息管理</h2><br>
<table align="center">
    <tr>
        <td width="25"></td>
        <td width="240" ><input type="search" id="searchText" placeholder="输入课程名、ID"/></td>
        <td width="170" >评分>=<input width="60" type="number" max="100" min="0" id="searchCode" /></td>
        <td width="110"><input type="button" id="searchButton" value="搜索" onclick="first()"/> </td>
        <td width="100"><a href="${pageContext.request.contextPath}/JSP/manager/information/sch_info/sch_insert.jsp">添加</a></td>
        <td><a href="${pageContext.request.contextPath}/JSP/manager/managerHome.jsp">返回</a> </td>
    </tr>
</table>
<br>
<div id="show"></div>
<br>
<%@ include file="../../../turnPage.jsp"%>

</body>
<script>
    window.onload=function() {
        var url=requestUrl+"?page=<%=session.getAttribute("sch_info_page")==null?1:session.getAttribute("sch_info_page")%>&searchText="+searchInput.value+"&searchCode="+searchCode.value;
        xmlhttp.open("GET",url,true);
        xmlhttp.send(null);
    }
    var requestUrl="${pageContext.request.contextPath}/JSP/manager/information/sch_info/sch_info_show.jsp";
    <%@ include file="../../../jsVar.jsp"%>
</script>

</html>
