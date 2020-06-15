<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.StuSch" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/13
  Time: 15:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String sql="select * from stu_sch where sch_id like '%"+searchText+"%' or stu_num like '%"+searchText+"%'";
    float num=DBUtil.queryNum(sql);
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("sch_page",Page);
    List<StuSch> list=(ArrayList<StuSch>)db.query(sql+" limit ?,?",new BeanListHandler(StuSch.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<form id="myform" method="post" action="${pageContext.request.contextPath}/delete?type=stu_sch" onsubmit="return isDelete()" target="_self">
    <table align="center" border="1" cellpadding="2" cellspacing="0">
        <tr id="navigation">
            <td width="150">ID</td><td width="150">课程ID</td><td width="150">学生学号</td>
            <td width="150"><input type="checkbox" id="deleteAll" onclick="selectAll(1)"/><input type="submit" value="删除" /></td>
        </tr>
        <c:forEach var="element" items="<%=list%>">
            <tr>
                <% rest--;%>
                <td height="32">${element.rela_id}</td>
                <td>${element.sch_id}</td>
                <td>${element.stu_num}</td>
                <td><input type="checkbox" name="delete" value="${element.rela_id}"/></td>
            </tr>
        </c:forEach>
        <%
            for(int i=0;i<rest;i++){
        %>
        <tr><td height="32"></td><td></td><td></td><td></td></tr>
        <%
            }
        %>
    </table>
    <input type="hidden" id="firstPage" value="1"/>
    <input type="hidden" id="previousPage" value="<%=((Page-1)<1?1:(Page-1))%>"/>
    <input type="hidden" id="nextPage" value="<%=((Page+1)>maxPage?maxPage:(Page+1))%>"/>
    <input type="hidden" id="lastPage" value="<%=maxPage%>"/>
</form>