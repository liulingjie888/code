<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Teacher" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/9
  Time: 11:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String id =request.getParameter("id");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
    Teacher teacher =(Teacher) db.query("select * from teachers where tea_id=?",new BeanHandler(Teacher.class), id);
%>
<html>
<head>
    <title>教师修改</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
</head>
<body>
<h2 align="center">教师修改</h2><br>
<form action="${pageContext.request.contextPath}/update?type=tea_info" method="post" target="_self" onsubmit="return isOk()" enctype="multipart/form-data">
    <table align="center"  border="0" cellspacing="0" cellpadding="8">
        <tr>
            <td></td>
            <td align="left"><img width="140" height="210" alt="无图片" src="${pageContext.request.contextPath}/photo?select=2&name=<%=teacher.getTea_name()%>"> </td>
        </tr>
        <tr>
            <td align="right">ID:</td>
            <td> <input type="text" name="tea_id" readonly value="<%=id%>"/></td>
        </tr>
        <tr>
            <td align="right">姓名:</td>
            <td><input type="text" name="tea_name"  required value="<%=teacher.getTea_name()%>"/></td>
        </tr>
        <tr>
            <td align="right">性别:</td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;男<input type="radio" name="tea_sex" id="boy" value="男"/>&nbsp;&nbsp;&nbsp;&nbsp;女<input type="radio" name="tea_sex" id="girl" value="女"/></td>
        </tr>
        <tr>
            <td align="right">身份证:</td>
            <td><input type="text" name="tea_identity" value="<%=teacher.getTea_identity()%>"/></td>
        </tr>
        <tr>
            <td align="right">照片</td>
            <td><input type="file" formenctype="multipart/form-data" accept="image/jpeg" name="photo"/></td>
        </tr>
        <tr>
            <td align="right">邮箱:</td>
            <td><input type="text" name="tea_email" value="<%=teacher.getTea_email()%>"/></td>
        </tr>
        <tr>
            <td align="right">地址:</td>
            <td><input type="text" name="tea_address" value="<%=teacher.getTea_address()%>" /></td>
        </tr>
        <tr>
            <td align="right">电话:</td>
            <td><input type="text" name="tea_photo" value="<%=teacher.getTea_photo()%>" /></td>
        </tr>
        <tr>
            <td> </td>
            <td>
                &nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" value="修改"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <c:choose>
                    <c:when test="${param.back=='tea_eva'}">
                        <input type="button" onclick="location.href='../../evaluation/teaEva_info/teaEva_info.jsp';" value="返回" />
                    </c:when>
                    <c:when test="${param.back=='statistics'}">
                        <input type="button" onclick="location.href='../../evaluation/teaEva_info/stu_eva/stu_tea.jsp';" value="返回" />
                    </c:when>
                    <c:otherwise>
                        <input type="button" onclick="location.href='tea_info.jsp';" value="返回" />
                    </c:otherwise>
                </c:choose>
            </td>
        </tr>
    </table>
</form>
</body>
<script>
    function isOk() {
        if(window.confirm("是否确认更新？"))
            return true;
        else
            return false;
    }

    var stu_boy=document.getElementById("boy");
    var stu_girl=document.getElementById("girl");
    <%if(teacher.getTea_sex().equals("男")){ %>
    stu_boy.checked="checked";
    <%}else{%>
    stu_girl.checked="chcked";
    <%}%>

    <c:if test="${param.success=='true'}">
    alert("更新成功！");
    </c:if>
    <c:if test="${param.success=='false'}">
    alert("更新失败！");
    </c:if>
</script>
</html>
