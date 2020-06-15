<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/10
  Time: 8:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>修改密码</title>
</head>
<style>
    span{
        color: red;
    }
    table{
        font-size:20px;
    }
    input{
        font-size: 18px;
    }
    body{
        background-image:url("../../image/home.jpg");
    }
</style>
<body>
<h2 align="center">修改密码</h2>
<form action="${pageContext.request.contextPath}/update?type=student_pawd" method="post" onsubmit="return isOk()">
<table align="center" border="0" cellpadding="13" cellspacing="0">
    <input type="hidden" name="stu_num" value="${student}"/>
    <tr>
        <td height="70">输入原密码:</td>
        <td><input type="password" name="initial_pawd" required/><span id="hint">${param.hint}</span></td>
    </tr>
    <tr>
        <td height="70">输入新密码:</td>
        <td><input type="password" name="first_pawd" id="first" onkeyup="isSuitable()" required/><span id="hint_first"></span></td>
    </tr>
    <tr>
        <td height="70">确认密码:</td>
        <td><input type="password" name="second_pawd" id="second" required onkeyup="isSamePswd()"/><span id="hint_second"></span></td>
    </tr>
    <tr>
        <td align="right"><input type="submit"/></td>
        <td align="center"><input type="button" onclick="location.href='${pageContext.request.contextPath}/JSP/student/studentHome.jsp';" value="返回"/></td>
    </tr>
</table>
</form>
</body>
<script>
    var first=document.getElementById("first");
    var second=document.getElementById("second");
    var hint_first=document.getElementById("hint_first");
    var hint_second=document.getElementById("hint_second");
    function isOk() {
        if(window.confirm("是否确认修改？"))
            return isSamePswd()&isSuitable();
        else
            return false;
    }

    //两次密码是否相同
    function isSamePswd() {
        if(first.value==second.value){
            hint_second.innerHTML="";
            return true;
        }
        else {
            hint_second.innerHTML="  两次密码不一致";
            return false;
        }
    }

    //长度是否小于5
    function isSuitable() {
        if(first.value.length<5){
            hint_first.innerHTML="  长度至少为5";
            return false;
        }else {
            hint_first.innerHTML="";
            return true;
        }

    }


</script>
</html>
