<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Schedule" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %>
<%@ page import="com.jie.object.Classes" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 10:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String id=request.getParameter("id");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
    Schedule schedule=(Schedule)db.query("select * from schedule where sch_id=?",new BeanHandler(Schedule.class),id);

    List<Classes> classes=(ArrayList<Classes>)db.query("select distinct cla_name from students",new BeanListHandler(Classes.class));
    List<Classes> teachers=(ArrayList<Classes>)db.query("select distinct tea_name from teachers",new BeanListHandler(Classes.class));
%>
<html>
<head>
    <title>课程修改</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/sch_check_exist.js"></script>
</head>
<body>
<h2 align="center">课程修改</h2>
<br>
<form action="${pageContext.request.contextPath}/update?type=sch_info" method="post" target="_self" onsubmit="return isOk()">
<table align="center" border="0" cellspacing="0" cellpadding="8">
    <tr>
        <td align="right">ID:</td>
        <td><input type="text" name="sch_id" readonly value="<%=schedule.getSch_id()%>"/></td>
    </tr>
    <tr>
        <td align="right">课程名:</td>
        <td><input type="text" name="sch_name" required value="<%=schedule.getSch_name()%>"/></td>
    </tr>
    <tr>
        <td align="right">班级:</td>
        <td><input type="text" id="cla" name="cla_name" required onkeyup="cla_check()" list="class" value="<%=schedule.getCla_name()%>"/><span id="cla_hint"></span></td>
        <datalist id="class">
            <c:forEach var="element" items="<%=classes%>">
                <option value="${element.cla_name}"></option>
            </c:forEach>
        </datalist>
    </tr>
    <tr>
        <td align="right">学期:</td>
        <td><input type="text" name="sch_term" required value="<%=schedule.getSch_term()%>"/></td>
    </tr>
    <tr>
        <td align="right">教师名:</td>
        <td><input type="text" id="tea" name="tea_name" required onkeyup="tea_check()" list="teacher" value="<%=schedule.getTea_name()%>"/><span id="tea_hint"></span></td>
        <datalist id="teacher">
            <c:forEach var="element" items="<%=teachers%>">
                <option value="${element.tea_name}"></option>
            </c:forEach>
        </datalist>
    </tr>
    <tr>
        <td align="right">备注:</td>
        <td><input type="text" name="sch_remark" value="<%=schedule.getSch_remark()%>" /></td>
    </tr>

    <tr>
        <td></td>
        <td>
            &nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" value="更新"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <c:choose>
                <c:when test="${param.back=='sch_eva'}">
                    <input type="button" onclick="location.href='../../evaluation/schEva_info/schEva_info.jsp';" value="返回" />
                </c:when>
                <c:when test="${param.back=='statistics'}">
                    <input type="button" onclick="location.href='../../evaluation/schEva_info/stu_eva/stu_sch.jsp';" value="返回" />
                </c:when>
                <c:otherwise>
                    <input type="button" onclick="location.href='sch_info.jsp';" value="返回" />
                </c:otherwise>
            </c:choose>

        </td>
    </tr>
</table>
</form>
</body>
<script>

    <%@ include file="sch_check.jsp"%>

    function isOk() {
        if(window.confirm("是否确认更新？"))
            return cla_isExist && tea_isExist;
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
</html>
