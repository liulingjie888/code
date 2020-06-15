<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Teacher" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/9
  Time: 10:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    String searchCode=request.getParameter("searchCode");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String codeSql=searchCode.equals("")?"":" and avg_code>="+searchCode;
    String sql="select * from teachers where (tea_id like '%"+searchText+"%' or tea_name like '%"+searchText+"%')"+codeSql;
    float num=DBUtil.queryNum(sql);
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("tea_info_page",Page);
    List<Teacher> list=(ArrayList<Teacher>)db.query(sql+" limit ?,?",new BeanListHandler(Teacher.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest= DBUtil.row;
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<form method="post" action="${pageContext.request.contextPath}/delete?type=tea_info" onsubmit="return isDelete()" target="_self">
    <table align="center" border="1" cellpadding="2" cellspacing="0">
        <tr id="navigation">
            <td width="40">ID</td><td width="100">姓名</td><td width="80">性别</td><td width="230">身份证</td><td width="80">测评分</td>
            <%--<td width="210">邮箱</td><td width="220">地址</td><td width="150">电话</td>--%>
            <td>查看</td><td width="100"><input type="checkbox" id="deleteAll" onclick="selectAll(1)"/><input type="submit" value="删除"/></td>
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
                <td><a href="${pageContext.request.contextPath}/JSP/manager/information/tea_info/tea_update.jsp?id=${element.tea_id}">查看</a></td>
                <td><input type="checkbox" name="delete" value="${element.tea_id}"/></td>
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
</form>