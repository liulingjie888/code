<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %>
<%@ page import="com.jie.object.Schedule" %>
<%@ page import="com.jie.object.SchEvaluation" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/6
  Time: 10:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String sch_id=request.getParameter("id");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");
    Schedule schedule=(Schedule) db.query("select * from schedule where sch_id=?",new BeanHandler(Schedule.class),sch_id);
%>
<html>
<head>
    <title>课程测评</title>
    <link href="../../../CSS/fontSize.css" rel="stylesheet" type="text/css" />
    <style>
        body{
            background-image:url("../../../image/home.jpg");
        }
    </style>
</head>
<body>
<h2 align="center">课程测评</h2><br>
<c:if test="${param.isEva=='false'}">
    <form method="post" action="${pageContext.request.contextPath}/insert?type=schEva" onsubmit="return judge()" target="_self">
        <table align="center" cellpadding="13" cellspacing="0">
            <tr>
                <td>课程：</td><td><%=schedule.getSch_name()%></td>
            </tr>

            <tr>
                <td>评价：</td><td><textarea name="eva_text" cols="22" rows="3" ></textarea></td>
            </tr>
            <tr>
                <td>评分：</td><td><input type="number" name="eva_code"  max="100" min="0" required/><span id="hint">&nbsp;请输入0-100</span></td>
            </tr>
            <tr>
                <input type="hidden" name="sch_id" value="<%=sch_id%>"/>
                <input type="hidden" name="stu_num" value="${sessionScope.student}"/>
                <td></td><td>&nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" width="50" height="30" value="提交"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="button" name="back" value="返回" onclick="history.back();"/></td>
            </tr>
        </table>
    </form>

    <script>
        function judge() {
            if(window.confirm("是否确认提交？"))
                return true;
            else
                return false;
        }

    </script>
</c:if>

<c:if test="${param.isEva=='true'}">
    <%
        SchEvaluation scheva=(SchEvaluation)db.query("select * from schEvaluation where sch_id=? and stu_num=?",new BeanHandler(SchEvaluation.class),sch_id,session.getAttribute("student"));
    %>
    <table align="center" cellpadding="13" cellspacing="0" >
        <tr>
            <td>课程：</td><td><%=schedule.getSch_name()%></td>
        </tr>

        <tr>
            <td>评价：</td><td><textarea  readonly rows="3" cols="22" name="eva_text"><%=scheva.getEva_text()%></textarea></td>
        </tr>
        <tr>
            <td>评分：</td><td><input type="text" name="eva_code" readonly value="<%=scheva.getEva_code()%>"/></td>
        </tr>
        <tr>
            <td>时间：</td><td><%=scheva.getEva_time()%></td>
        </tr>
        <tr>
            <td></td><td align="center"><input type="button" name="back" value="返回" onclick="location.href='${pageContext.request.contextPath}/JSP/student/sch_info/sch_info.jsp'"/></td>
        </tr>
    </table>
</c:if>

</body>
<script>
    <c:if test="${param.success=='true'}">
        alert("测评成功！");
    </c:if>
    <c:if test="${param.success=='false'}">
        alert("测评失败！");
    </c:if>
</script>
</html>