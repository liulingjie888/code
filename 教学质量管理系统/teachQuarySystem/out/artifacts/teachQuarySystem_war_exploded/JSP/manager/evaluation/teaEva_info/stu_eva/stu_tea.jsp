<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/12
  Time: 21:35
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>教师统计</title>
    <link href="../../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        td[name="td_number"]{
            background-color:aquamarine;
        }
        input[id="number"]{
            width:50px;
        }
        /*table[id="table_navigation"]{*/
            /*background-color: aquamarine;*/
        /*}*/
        a{
            font-size: 17px;
        }
        body{
            background-image:url("../../../../../image/home.jpg");
        }
    </style>
</head>
<body>
<table align="center" id="table_navigation">
    <tr>
        <td width="130"><a href="#" onclick="location.href='${pageContext.request.contextPath}/JSP/manager/evaluation/teaEva_info/teaEva_info.jsp';">学生测评管理</a></td>
        <td width="100"></td>
        <td width="150"></td>
        <td width="150" align="right"></td>
        <td width="160" align="right"><a href="#" onclick="location.href='${pageContext.request.contextPath}/JSP/manager/managerHome.jsp';">返回</a></td>

    </tr>
</table>
<h2 align="center">统计</h2>
<table align="center">
    <tr>
        <td ><input type="radio" id="1" name="standard" onclick="good()"/></td><td width="150">优秀教师:</td>
        <td><input type="radio" id="2" name="standard" onclick="nogood() "  checked/></td><td width="150">合格教师:</td>
        <td><input type="radio" id="3" name="standard" onclick="bad()" /></td><td width="170">不合格教师:</td>
        <td>评判标准:</td><td><input type="number" id="number" max="100" min="1" value="70"/></td>
    </tr>
</table>

<div id="show"></div>
<br>
<%@ include file="../../../../turnPage.jsp"%>
</body>
<script>

    var code=document.getElementById("number");
    var show=document.getElementById("show");
    var requestUrl="${pageContext.request.contextPath}/JSP/manager/evaluation/teaEva_info/stu_eva/show.jsp";
    var standard=2;

    var http=new XMLHttpRequest();
    http.onreadystatechange=checkResult;

    window.onload=function() {
        var url=requestUrl+"?page=<%=session.getAttribute("stu_tea_page")==null?1:session.getAttribute("stu_tea_page")%>&type="+standard+"&code="+code.value;
        http.open("GET",url,true);
        http.send(null);
    }

    function first() {
        url=requestUrl+"?page=1&type="+standard+"&code="+code.value;
        http.open("GET",url,true);
        http.send(null);
    }

    //上一页
    function previous() {
        var page=document.getElementById("previousPage");
        var url=requestUrl+"?page="+page.value+"&type="+standard+"&code="+code.value;
        http.open("GET",url,true);
        http.send(null);
    }
    //下一页
    function next() {
        var page=document.getElementById("nextPage");
        var url=requestUrl+"?page="+page.value+"&type="+standard+"&code="+code.value;
        http.open("GET",url,true);
        http.send(null);
    }
    //最后一页
    function last() {
        var page=document.getElementById("lastPage");
        var url=requestUrl+"?page="+page.value+"&type="+standard+"&code="+code.value;
        http.open("GET",url,true);
        http.send(null);
    }

    function  good() {
        standard=1;
        first();
    }

    function  nogood() {
        standard=2;
        first();
    }

    function bad() {
        standard=3;
        first();
    }

    function checkResult(){
        if(http.readyState==4 && http.status==200){
            show.innerHTML=http.responseText;
        }
    }
</script>
</html>
