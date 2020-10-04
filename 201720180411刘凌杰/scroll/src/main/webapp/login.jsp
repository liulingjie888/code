<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/17
  Time: 10:10
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>登录页面</title>
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
    <!-- 整个页面的最顶端 -->
    <div class="row" style="height: 40px ; line-height: 40px ;font-size: 24px;margin-top: 34px ;box-shadow: 0px 1px 3px #dedede ; width: 100% ">
        <div class="col-md-4 " style="text-align: right ; ">欢迎登录</div>
        <div class="col-md-4 "></div>
        <div class="col-md-4 ">没有账号？ <span style="color: #ff0000" id="register">请注册>></span></div>
    </div>

    <script type="text/javascript">
        $("#register").click(function(){
            window.location = "${pageContext.request.contextPath}/register.jsp" ;
        })
    </script>

    <!-- 登录核心 -->
    <div class="row" style="margin-top: 13%;width: 100%">
        <div class="col-md-4 " style="text-align: right ; "></div>
        <div class="col-md-4 center-block">
            <form action="${pageContext.request.contextPath}/user/login" method="post">
                <input type="text" name="username" id="username" class="form-control" placeholder="请输入用户名">
                <br>
                <input type="password" name="password" id="password" class="form-control" placeholder="请输入密码">
                <br>
                <button type="submit" class="btn btn-primary btn-block">登录</button>
                <br>
                <button type="reset" class="btn btn-primary btn-block">取消</button>
            </form>
        </div>
        <div class="col-md-4 "></div>
    </div>

    <div style="margin-top: 3%">
        <c:if test="${ not empty msg }">
            <h1 style="text-align: center ; color: red ; font-weight: bolder">${msg}</h1>
        </c:if>
    </div>
</body>
</html>
