<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/9
  Time: 11:00
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>添加教师</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
</head>
<body>
<h2 align="center">添加教师</h2><br>
<form action="${pageContext.request.contextPath}/insert?type=tea_info" method="post" target="_self" onsubmit="return isOk()" enctype="multipart/form-data">
    <table align="center"  border="0" cellspacing="0" cellpadding="8">
        <tr>
            <td align="right">姓名:</td>
            <td><input type="text" name="tea_name" required/></td>
        </tr>
        <tr>
            <td align="right">性别:</td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;男<input type="radio" name="tea_sex" value="男" checked width="20" height="20"/>&nbsp;&nbsp;&nbsp;&nbsp;女<input type="radio" name="tea_sex" value="女" width="20" height="20"/></td>
        </tr>
        <tr>
            <td align="right">身份证:</td>
            <td><input type="text" name="tea_identity" /></td>
        </tr>
        <tr>
            <td align="right">照片</td>
            <td><input type="file" accept="image/jpeg" name="photo"/></td>
        </tr>
        <tr>
            <td align="right">邮箱:</td>
            <td><input type="text" name="tea_email" /></td>
        </tr>
        <tr>
            <td align="right">地址:</td>
            <td><input type="text" name="tea_address" /></td>
        </tr>
        <tr>
            <td align="right">电话:</td>
            <td><input type="text" name="tea_photo"  /></td>
        </tr>
        <tr>
            <td></td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" value="提交"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <input type="button" onclick="location.href='tea_info.jsp';" value="返回" /></td>
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
