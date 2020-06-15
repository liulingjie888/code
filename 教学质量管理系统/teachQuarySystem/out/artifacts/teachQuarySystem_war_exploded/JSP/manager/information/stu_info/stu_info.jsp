<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 13:12
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>学生信息管理</title>
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
<h2 align="center">学生信息管理</h2>
<br>
<table align="center" >
<tr>
    <td width="190" align="left"><a href="./relative/sch.jsp"> 课程管理</a></td>
    <td width="240" align="left"><a href="./relative/tea.jsp">教师管理</a></td>
    <td width="240" ><input type="search" id="searchText" placeholder="输入学生名、学号或班级"/></td>
    <td width="110"><input type="button" id="searchButton" value="搜索" onclick="first()"/> </td>
    <td width="100"><a href="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_insert.jsp">添加</a></td>
    <td><a href="${pageContext.request.contextPath}/JSP/manager/managerHome.jsp">返回</a> </td>
</tr>
</table>
<br>
<input type="hidden" value="" id="searchCode"/>
<div id="show"></div>
<br>
<%@ include file="../../../turnPage.jsp"%>

</body>
<script>


    function deleteform() {
        var form1=document.getElementById("myform");
        form1.removeAttribute("action");
        var action = document.createAttribute("action");
        action.nodeValue="${pageContext.request.contextPath}/delete?type=stu_info";
        form1.setAttributeNode(action);
        if(window.confirm("是否确认删除？"))
            form1.submit();
        else
            return;
    }

    function rela_form(select) {
        var form1=document.getElementById("myform");
        form1.removeAttribute("action");
        var action = document.createAttribute("action");
        if(select==1)
             action.nodeValue="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_rela.jsp?type=sch";
        if(select==2)
            action.nodeValue="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_rela.jsp?type=tea";
        form1.setAttributeNode(action);
        form1.submit();
    }

    window.onload=function() {
            var url=requestUrl+"?page=<%=session.getAttribute("stu_info_page")==null?1:session.getAttribute("stu_info_page")%>&searchText="+searchInput.value+"&searchCode="+searchCode.value;
            xmlhttp.open("GET",url,true);
            xmlhttp.send(null);
    }

    var requestUrl="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_info_show.jsp";
    <%@ include file="../../../jsVar.jsp"%>
</script>


</html>
