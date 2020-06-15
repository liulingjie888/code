<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Student" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 14:35
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String id =request.getParameter("id");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
    Student student =(Student)db.query("select * from students where stu_id=?",new BeanHandler(Student.class), id);
%>
<html>
<head>
    <title>学生修改</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
</head>
<body>
<h2 align="center">学生修改</h2>
<form action="${pageContext.request.contextPath}/update?type=stu_info" method="post" target="_self" onsubmit="return isOk()" enctype="multipart/form-data">
    <table align="center" cellpadding="8">
        <tr>
            <td></td>
            <td align="left"><img width="140" height="210" alt="无图片" src="${pageContext.request.contextPath}/photo?select=1&name=<%=student.getStu_num()%>"> </td>
        </tr>
        <tr>
            <td align="right" width="120">ID:</td>
            <td> <input type="text" name="stu_id" readonly value="<%=id%>"/></td>
        </tr>

        <tr>
            <td align="right">学号:</td>
            <td><input type="text" name="stu_num" required value="<%=student.getStu_num()%>"/></td>
        </tr>
        <tr>
            <td align="right">姓名:</td>
            <td><input type="text" name="stu_name"  required value="<%=student.getStu_name()%>"/></td>
        </tr>
        <tr>
            <td align="right">性别:</td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;男<input type="radio" name="stu_sex" value="男" id="boy"/>&nbsp;&nbsp;&nbsp;&nbsp;女<input type="radio" name="stu_sex" value="女" id="girl"/></td>
        </tr>
        <tr>
            <td align="right">身份证:</td>
            <td><input type="text" name="stu_identity" value="<%=student.getStu_identity()%>"/></td>
        </tr>
        <tr>
            <td align="right">照片</td>
            <td><input type="file" accept="image/jpeg" name="photo"/></td>
        </tr>
        <tr>
            <td align="right">邮箱:</td>
            <td><input type="email" name="stu_email" value="<%=student.getStu_email()%>"/></td>
        </tr>
        <tr>
            <td align="right">地址:</td>
            <td><input type="text" name="stu_address" value="<%=student.getStu_address()%>" /></td>
        </tr>
        <tr>
            <td align="right">电话:</td>
            <td><input type="tel" name="stu_photo" value="<%=student.getStu_photo()%>" /></td>
        </tr>
        <tr>
            <td align="right">班级:</td>
            <td><input type="text" name="cla_name" value="<%=student.getCla_name()%>" /></td>
        </tr>
        <tr>
            <td align="right">密码:</td>
            <td><input type="text" name="stu_password"  value="<%=student.getStu_password()%>" /></td>
        </tr>

        <tr>
            <td> </td>
            <td>
                &nbsp;&nbsp;<input type="submit" value="更新"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <c:choose>
                    <c:when test="${param.back=='tea_eva'}">
                        <input type="button" onclick="location.href='../../evaluation/teaEva_info/teaEva_info.jsp';" value="返回" />
                    </c:when>
                    <c:when test="${param.back=='sch_eva'}">
                        <input type="button" onclick="location.href='../../evaluation/schEva_info/schEva_info.jsp';" value="返回" />
                    </c:when>
                    <c:otherwise>
                        <input type="button" onclick="location.href='stu_info.jsp';" value="返回" />
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
    <%if(student.getStu_sex().equals("男")){ %>
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
