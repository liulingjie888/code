<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/17
  Time: 15:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册</title>
    <link href="${pageContext.request.contextPath}/css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="${pageContext.request.contextPath}/font-awesome-4.7.0/css/font-awesome.min.css" type="text/css" rel="stylesheet">
    <script src="${pageContext.request.contextPath}/js/jquery-3.5.1.min.js"></script>
    <style type="text/css">
        *{
            margin: 0px;
            padding: 0px;
        }
    </style>
</head>
<body>

<!-- 注册核心 -->
<div class="row" style="margin-top: 13%;width: 100%">
    <div class="col-md-4 " style="text-align: right ; "></div>
    <div class="col-md-4 center-block">
        <form action="${pageContext.request.contextPath}/user/register" method="post">
            <input type="text" name="username" id="username" class="form-control" placeholder="请输入用户名">
            <br>
            <input type="password" name="password" id="password" class="form-control" placeholder="请输入密码">
            <br>
            <input type="password" name="configPassword" id="configPassword" class="form-control" placeholder="请确认密码">
            <br>
            <button type="submit" class="btn btn-primary btn-block">注册</button>
            <br>
        </form>
    </div>
    <div class="col-md-4 "></div>
</div>
<div style="margin-top: 3%;width: 100%">
    <c:if test="${ not empty msg }">
        <h1 style="text-align: center ; color: red ; font-weight: bolder">${msg}</h1>
    </c:if>
</div>
</body>
</html>
