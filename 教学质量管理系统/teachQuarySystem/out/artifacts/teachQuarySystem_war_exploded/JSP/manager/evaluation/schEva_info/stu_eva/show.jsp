<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Teacher" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ page import="com.jie.object.Schedule" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/14
  Time: 12:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String type=request.getParameter("type");
    String code=request.getParameter("code");if(code.equals(""))code="60";
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String sql="select * from schedule";
    System.out.println(type);
    if(type.equals("1"))
        sql="select * from schedule where avg_code>=85 order by avg_code DESC";
    if(type.equals("2"))
        sql="select * from schedule where avg_code>="+code+" order by avg_code DESC";
    if(type.equals("3"))
        sql="select * from schedule where avg_code<"+code+" order by avg_code DESC";
//    switch (type){
//        case "1":
//            sql="select * from teachers where avg_code>85";
//            break;
//        case "2":
//            sql="select * from teachers where avg_code>"+code;
//            break;
//        case "3":
//            sql="select * from teachers where avg_code<"+code;
//            break;
//    }
    System.out.println(sql);
    float num=db.queryNumber(sql.replace("*","count(*)"));
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("stu_sch_page",Page);
    List<Schedule> list=(ArrayList<Schedule>)db.query(sql+" limit ?,?",new BeanListHandler(Schedule.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;

    int good=db.queryNumber("select count(*) from schedule where avg_code>=85");
    int nogood=db.queryNumber("select count(*) from schedule where avg_code>=?",code);
    int bad=db.queryNumber("select count(*) from schedule where avg_code<?",code);
%>
<table align="center"><tr>
    <td width="40" align="center" name="td_number"><%=good%></td><td width="150"></td>
    <td width="40"  align="center" name="td_number"><%=nogood%></td><td width="150"></td>
    <td width="40"  align="center" name="td_number"><%=bad%></td><td width="280"></td>
</tr></table>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<table align="center" cellspacing="0" cellpadding="2" border="1">
    <tr id="navigation">
        <td width="40">ID</td><td width="110">课程名</td><td width="120">班级</td><td width="110">学期</td><td width="100">教师</td><td width="80">测评分</td>
        <%--<td width="130">备注</td>--%>
        <td width="100">查看</td>
    </tr>
    <c:forEach var="element" items="<%=list%>">
        <%rest--;%>
        <tr>
            <td height="32">${element.sch_id}</td>
            <td>${element.sch_name}</td>
            <td>${element.cla_name}</td>
            <td>${element.sch_term}</td>
            <td>${element.tea_name}</td>
            <td>${element.avg_code}</td>
                <%--<td>${element.sch_remark}</td>--%>
            <td><a href="${pageContext.request.contextPath}/JSP/manager/information/sch_info/sch_update.jsp?back=statistics&id=${element.sch_id}">查看</a></td>
        </tr>
    </c:forEach>
    <%
        for(int i=0;i<rest;i++){
    %>
    <tr><td height="32"></td><td></td><td></td><td></td><td></td><td></td><td></td></tr>
    <%
        }
    %>
</table>
<input type="hidden" id="firstPage" value="1"/>
<input type="hidden" id="previousPage" value="<%=((Page-1)<1?1:(Page-1))%>"/>
<input type="hidden" id="nextPage" value="<%=((Page+1)>maxPage?maxPage:(Page+1))%>"/>
<input type="hidden" id="lastPage" value="<%=maxPage%>"/>


