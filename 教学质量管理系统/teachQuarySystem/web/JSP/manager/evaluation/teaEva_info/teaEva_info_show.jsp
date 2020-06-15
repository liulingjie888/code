<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.TeaEvaluation" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ page import="com.jie.object.Student" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanHandler" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/9
  Time: 22:12
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String sql="select * from teaEvaluation where eva_id like '%"+searchText+"%' or tea_id like '%"+searchText+"%'";
    float num=db.queryNumber(sql.replace("*","count(*)"));
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("teaEva_info_page",Page);
    List<TeaEvaluation> list=(ArrayList<TeaEvaluation>)db.query(sql+" limit ?,?",new BeanListHandler(TeaEvaluation.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<form method="post" action="${pageContext.request.contextPath}/delete?type=teaEva_info" onsubmit="return isDelete()" target="_self">
    <table align="center" border="1" cellpadding="2" cellspacing="0">
        <tr id="navigation">
            <td width="80">ID</td><td width="100">教师ID</td><td width="50">评分</td><td width="200">评语</td><td width="170">时间</td><td width="80">测评学生</td>
            <td>修改</td><td><input type="checkbox" id="deleteAll" onclick="selectAll(1)"/><input type="submit" value="删除"/></td>
        </tr>
        <c:forEach var="element" items="<%=list%>">
            <%rest--;%>
            <tr>
                <td height="32">${element.eva_id}</td>
                <td><a href="${pageContext.request.contextPath}/JSP/manager/information/tea_info/tea_update.jsp?back=tea_eva&id=${element.tea_id}">${element.tea_id}</a></td>
                <td>${element.eva_code}</td>
                <td>${element.eva_text}</td>
                <td>${element.eva_time}</td>
                <c:set value="${element.stu_num}" var="stu_num" scope="request"/>
                <%
                    Student student=(Student)db.query("select * from students where stu_num=?",new BeanHandler(Student.class),request.getAttribute("stu_num"));
                %>
                <td><a href="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_update.jsp?back=tea_eva&id=<%=student.getStu_id()%>">${element.stu_num}</a></td>
                <td><a href="${pageContext.request.contextPath}/JSP/manager/evaluation/teaEva_info/teaEva_update.jsp?id=${element.eva_id}">修改</a></td>
                <td><input type="checkbox" name="delete" value="${element.eva_id}"/></td>
            </tr>
        </c:forEach>
        <%
            for(int i=0;i<rest;i++){
        %>
                <tr><td height="32"></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr>
        <%
            }
        %>
    </table>
    <input type="hidden" id="firstPage" value="1"/>
    <input type="hidden" id="previousPage" value="<%=((Page-1)<1?1:(Page-1))%>"/>
    <input type="hidden" id="nextPage" value="<%=((Page+1)>maxPage?maxPage:(Page+1))%>"/>
    <input type="hidden" id="lastPage" value="<%=maxPage%>"/>
</form>
