<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %>
<%@ page import="com.jie.object.Student" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/5
  Time: 20:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    DBUtil dbUtil=(DBUtil)session.getAttribute("DBUtil");
    String stu_num=(String)session.getAttribute("student");
    Student student=(Student)dbUtil.query("select * from students where stu_num=?",new BeanHandler(Student.class),stu_num);
%>
<html>
<head>
    <title>个人信息</title>
</head>
<style>
    table{
        font-size:20px;
    }
    body{
        background-image:url("../../image/home.jpg");
    }
</style>
<body>
<h2 align="center">个人信息</h2>
<table align="center">
    <tr><td width="400"></td><td><a href="${pageContext.request.contextPath}/JSP/student/studentHome.jsp">返回</a></td></tr>
</table>
<br>
<table align="center" cellspacing="0" cellpadding="5" border="1">
    <tr><td></td>
        <td align="left"><img width="140" height="210" alt="无图片" src="${pageContext.request.contextPath}/photo?select=1&name=<%=student.getStu_num()%>"></td></tr>
    <tr><td align="right" width="100">学号：</td><td width="300"><%=student.getStu_num()%></td></tr>
    <tr><td align="right">姓名：</td><td><%=student.getStu_name()%></td></tr>
    <tr><td align="right">性别：</td><td><%=student.getStu_sex()%></td></tr>
    <tr><td align="right">班级：</td><td><%=student.getCla_name()%></td></tr>
    <tr><td align="right">身份证：</td><td><%=student.getStu_identity()%></td></tr>
    <tr><td align="right">邮箱：</td><td><%=student.getStu_email()%></td></tr>
    <tr><td align="right">地址：</td><td><%=student.getStu_address()%></td></tr>
    <tr><td align="right">电话：</td><td><%=student.getStu_photo()%></td></tr>
</table>
</body>
</html>
