<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/13
  Time: 15:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>学生教师</title>
    <link href="../../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../../image/home.jpg");
        }
    </style>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/searchPage.js"></script>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/deleleCheck.js"></script>
</head>
<body>
<h2 align="center">学生教师</h2>
<br>
<table align="center" >
    <tr>
        <td width="240" ><input type="search" id="searchText" placeholder="输入教师或学生学号"/></td>
        <td width="110"><input type="button" id="searchButton" value="搜索" onclick="first()"/> </td>
        <td><a href="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_info.jsp">返回</a> </td>
    </tr>
</table>
<br>
<input type="hidden" value="" id="searchCode"/>
<div id="show"></div>
<br>
<%@ include file="../../../../turnPage.jsp"%>
</body>
<script>
    window.onload=function() {
        var url=requestUrl+"?page=<%=session.getAttribute("tea_page")==null?1:session.getAttribute("tea_page")%>&searchText="+searchInput.value+"&searchCode="+searchCode.value;
        xmlhttp.open("GET",url,true);
        xmlhttp.send(null);
    }
    var requestUrl="${pageContext.request.contextPath}/JSP/manager/information/stu_info/relative/tea_show.jsp";
    <%@ include file="../../../../jsVar.jsp"%>
</script>
</html>
