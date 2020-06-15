<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/5
  Time: 21:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>课程信息查询</title>
    <link href="../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../image/home.jpg");
        }
    </style>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/searchPage.js"></script>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/deleleCheck.js"></script>
</head>

<body>
<h2 align="center">课程信息查询</h2><br>
<table align="center">
    <tr>
        <td width="30"></td>
        <td width="240"><input type="search" id="searchText" placeholder="输入课程名、ID"/></td>
        <td width="140"><input type="button" onclick="first()" value="搜索"/></td>
        <td><a href="${pageContext.request.contextPath}/JSP/student/studentHome.jsp" >返回</a></td>
    </tr>
</table>
<br>
<input type="hidden" value="" id="searchCode"/>
<div id="show"></div>
<p></p>
<%@include file="../../turnPage.jsp"%>

</body>

<script>
    window.onload=function() {
        var url=requestUrl+"?page=<%=session.getAttribute("sch_info_page_student")==null?1:session.getAttribute("sch_info_page_student")%>&searchText="+searchInput.value+"&searchCode="+searchCode.value;
        xmlhttp.open("GET",url,true);
        xmlhttp.send(null);
    }
    requestUrl="${pageContext.request.contextPath}/JSP/student/sch_info/sch_info_show.jsp";
    <%@include file="../../jsVar.jsp"%>
</script>
</html>
