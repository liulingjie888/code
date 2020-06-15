<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Teacher" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %><%--
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

    String sql="select * from teachers";
    System.out.println(type);
    if(type.equals("1"))
        sql="select * from teachers where avg_code>=85 order by avg_code DESC";
    if(type.equals("2"))
        sql="select * from teachers where avg_code>="+code+" order by avg_code DESC";
    if(type.equals("3"))
        sql="select * from teachers where avg_code<"+code+" order by avg_code DESC";
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
    session.setAttribute("stu_tea_page",Page);
    List<Teacher> list=(ArrayList<Teacher>)db.query(sql+" limit ?,?",new BeanListHandler(Teacher.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;

    int good=db.queryNumber("select count(*) from teachers where avg_code>=85");
    int nogood=db.queryNumber("select count(*) from teachers where avg_code>=?",code);
    int bad=db.queryNumber("select count(*) from teachers where avg_code<?",code);
%>
<table align="center"><tr>
    <td width="40" align="center" name="td_number"><%=good%></td><td width="150"></td>
    <td width="40"  align="center" name="td_number"><%=nogood%></td><td width="150"></td>
    <td width="40"  align="center" name="td_number"><%=bad%></td><td width="280"></td>
</tr></table>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
    <table align="center" border="1" cellpadding="2" cellspacing="0">
        <tr id="navigation">
            <td width="60">ID</td><td width="100">姓名</td><td width="80">性别</td><td width="230">身份证</td><td width="80">测评分</td>
            <%--<td width="210">邮箱</td><td width="220">地址</td><td width="150">电话</td>--%>
            <td>查看</td>
        </tr>
        <c:forEach var="element" items="<%=list%>">
            <%rest--;%>
            <tr>
                <td height="32">${element.tea_id}</td>
                <td>${element.tea_name}</td>
                <td>${element.tea_sex}</td>
                <td>${element.tea_identity}</td>
                <td>${element.avg_code}</td>
                    <%--<td>${element.tea_email}</td>--%>
                    <%--<td>${element.tea_address}</td>--%>
                    <%--<td>${element.tea_photo}</td>--%>
                <td><a href="${pageContext.request.contextPath}/JSP/manager/information/tea_info/tea_update.jsp?back=statistics&id=${element.tea_id}">查看</a></td>
            </tr>
        </c:forEach>
        <%
            for(int i=0;i<rest;i++){
        %>
        <tr><td height="32"></td><td></td><td></td><td></td><td></td><td></td></tr>
        <%
            }
        %>
    </table>
    <input type="hidden" id="firstPage" value="1"/>
    <input type="hidden" id="previousPage" value="<%=((Page-1)<1?1:(Page-1))%>"/>
    <input type="hidden" id="nextPage" value="<%=((Page+1)>maxPage?maxPage:(Page+1))%>"/>
    <input type="hidden" id="lastPage" value="<%=maxPage%>"/>

