<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 15:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title> 添加学生</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
</head>
<body>
<h2 align="center">添加学生</h2>
<form action="${pageContext.request.contextPath}/insert?type=stu_info" method="post" target="_self" onsubmit="return isOk()"  enctype="multipart/form-data">
    <table align="center" border="0" cellspacing="0" cellpadding="8">
        <tr>
            <td align="right">学号:</td>
            <td width="120"><input type="text" name="stu_num" required /></td>
        </tr>
        <tr>
            <td align="right">姓名:</td>
            <td><input type="text" name="stu_name" required/></td>
        </tr>
        <tr>
            <td align="right">性别:</td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;男<input type="radio" name="stu_sex" checked value="男">&nbsp;&nbsp;&nbsp;&nbsp;女<input type="radio" name="stu_sex" value="女" /></td>
        </tr>
        <tr>
            <td align="right">身份证:</td>
            <td><input type="text" name="stu_identity" /></td>
        </tr>
        <tr>
            <td align="right">照片</td>
            <td><input type="file" accept="image/jpeg" name="photo"/></td>
        </tr>
        <tr>
            <td align="right">邮箱:</td>
            <td><input type="email" name="stu_email" /></td>
        </tr>
        <tr>
            <td align="right">地址:</td>
            <td><input type="text" name="stu_address" /></td>
        </tr>
        <tr>
            <td align="right">电话:</td>
            <td><input type="tel" name="stu_photo"  /></td>
        </tr>
        <tr>
            <td align="right">班级:</td>
            <td><input type="text" name="cla_name"/></td>
        </tr>
        <tr>
            <td  align="right">密码:</td>
            <td><input type="text" name="stu_password" /></td>
        </tr>

        <tr>
            <td > </td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" value="提交"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="button" onclick="location.href='stu_info.jsp';" value="返回" /></td>
        </tr>
    </table>
</form>
</body>
<script>
    function isOk() {
        if(window.confirm("是否确认添加？"))
            return true;
        else
            return false;
    }

    <c:if test="${param.success=='true'}">
        alert("添加成功！");
    </c:if>
    <c:if test="${param.success=='false'}">
        alert("添加失败！");
    </c:if>
</script>
</html>
