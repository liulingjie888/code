<%@ page import="com.jie.object.Schedule" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page import="com.jie.object.Student" %>
<%@ page import="com.jie.object.Teacher" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/13
  Time: 12:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
%>
<html>
<head>
    <title>选择</title>
    <link href="../../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../../image/home.jpg");
        }
    </style>
    <script type="text/javascript" src="${pageContext.request.contextPath}/JS/eva_check_exist.js"></script>
</head>
<body>
<c:if test="${param.type=='sch'}">
    <%
        List<Schedule> sch_list=(ArrayList<Schedule>)db.query("select * from schedule",new BeanListHandler(Schedule.class));
        String[] stu_ids=request.getParameterValues("sch_check");
        if(stu_ids!=null)
            session.setAttribute("students",stu_ids);
    %>
    <h2 align="center">课程选择</h2><br>
    <div align="center">
    <form action="${pageContext.request.contextPath}/insert?type=stu_sch" method="post" target="_self" onsubmit="return sch_isExist;">
        <table>
            <tr>
                <td><input type="text" name="sch_id" list="schstu" id="sch" onkeyup="sch_check()" required/><span id="sch_hint"></span></td>
                <datalist id="schstu">
                    <% for(int i=0;i<sch_list.size();i++){ %>
                    <option value="<%=sch_list.get(i).getSch_id()%>"></option>
                    <%}%>
                </datalist>
            </tr>
            <tr>
                <td align="center" height="100"><input type="submit" value="添加" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <input type="button" value="返回" onclick="location.href='${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_info.jsp';"></td>
            </tr>
        </table>
    </form>
    </div>
</c:if>

<c:if test="${param.type=='tea'}">
    <%
        List<Teacher> tea_list=(ArrayList<Teacher>)db.query("select * from teachers",new BeanListHandler(Teacher.class));
        String[] stu_ids=request.getParameterValues("tea_check");
        System.out.println("长度为"+tea_list.size());
        if(stu_ids!=null)
            session.setAttribute("students",stu_ids);
    %>
    <h2 align="center">教师选择</h2><br>
    <div align="center">
        <form action="${pageContext.request.contextPath}/insert?type=stu_tea" method="post" target="_self" onsubmit="return tea_isExist;">
            <table>
                <tr>
                    <td><input type="text" name="tea_id" list="teastu" id="tea" onkeyup="tea_check()" required/><span id="tea_hint"></span>
                        <datalist id="teastu">
                            <% for(int i=0;i<tea_list.size();i++){ %>
                            <option value="<%=tea_list.get(i).getTea_id()%>"></option>
                            <%}%>
                        </datalist>
                    </td>

                </tr>
                <tr>
                    <td align="center" height="100"><input type="submit" value="添加" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <input type="button" value="返回" onclick="location.href='${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_info.jsp';"></td>
                </tr>
            </table>
        </form>
    </div>
</c:if>

</body>
<script>
    <%@ include file="../../eva_check.jsp"%>

    <c:if test="${param.success=='true'}">
        window.alert("添加成功！");
    </c:if>
    <c:if test="${param.success=='false'}">
    window.alert("添加失败！");
    </c:if>
</script>
</html>
