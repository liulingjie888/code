<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.TeaEvaluation" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ page import="com.jie.object.Classes" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/9
  Time: 22:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String id=request.getParameter("id");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
    TeaEvaluation evaluation=(TeaEvaluation) db.query("select * from teaEvaluation where eva_id=?",new BeanHandler(TeaEvaluation.class),id);

    List<Classes> tea_id=(ArrayList<Classes>)db.query("select distinct tea_id from teachers",new BeanListHandler(Classes.class));
    List<Classes> stu_num=(ArrayList<Classes>)db.query("select distinct stu_num from students",new BeanListHandler(Classes.class));
%>
<html>
<head>
    <title>修改教师测评</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        textarea{
            font-size:18px;
        }
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/eva_check_exist.js"></script>
</head>
<body>
<h2 align="center">修改教师测评</h2><br>
<form action="${pageContext.request.contextPath}/update?type=teaEva_info" method="post" target="_self" onsubmit="return isOk()">
    <table align="center" cellpadding="8">
        <tr>
            <td align="right">ID:</td>
            <td><input type="text" name="eva_id" readonly value="<%=evaluation.getEva_id()%>"/></td>
        </tr>
        <tr>
            <td align="right">教师ID:</td>
            <td><input type="text" id="tea" name="tea_id" onkeyup="tea_check()" list="teachers" required value="<%=evaluation.getTea_id()%>"/><span id="tea_hint"></span></td>
            <datalist id="teachers">
                <c:forEach var="element" items="<%=tea_id%>">
                    <option value="${element.tea_id}"></option>
                </c:forEach>
            </datalist>
        </tr>
        <tr>
            <td align="right">评分:</td>
            <td><input type="number" max="100" min="0" name="eva_code" required value="<%=evaluation.getEva_code()%>"/>&nbsp;&nbsp;&nbsp;&nbsp;1-100分</td>
        </tr>
        <tr>
            <td align="right">评语:</td>
            <td><textarea  rows="3" cols="22" name="eva_text"><%=evaluation.getEva_text()%></textarea></td>
        </tr>
        <tr>
            <td align="right">时间:</td>
            <td><input type="datetime-local" name="eva_time" required value="<%=evaluation.getEva_time().replace(" ","T")%>"/></td>
        </tr>
        <tr>
            <td align="right">测评学生:</td>
            <td><input type="text" id="stu" name="stu_num" onkeyup="stu_check()" list="students" value="<%=evaluation.getStu_num()%>" /><span id="stu_hint"></span></td>
            <datalist id="students">
                <c:forEach var="element" items="<%=stu_num%>">
                    <option value="${element.stu_num}"></option>
                </c:forEach>
            </datalist>
        </tr>

        <tr>
            <td align="right"> </td>
            <td>&nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" value="提交"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="button" onclick="location.href='teaEva_info.jsp';" value="返回" /></td>
        </tr>
    </table>
</form>
<script>

    <%@ include file="../../eva_check.jsp"%>

    function isOk() {
        if(window.confirm("是否确认更新？"))
            return tea_isExist && stu_isExist;
        else
            return false;
    }
    <c:if test="${param.success=='true'}">
        alert("更新成功！");
    </c:if>
    <c:if test="${param.success=='false'}">
        alert("更新失败！");
    </c:if>
</script>
</body>
</html>
