<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Schedule" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 14:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    String searchCode=request.getParameter("searchCode");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String codeSql=searchCode.equals("")?"":" and avg_code>="+searchCode;
    String sql="select * from schedule where (sch_id like '%"+searchText+"%' or sch_name like '%"+searchText+"%')"+codeSql;

    float num=DBUtil.queryNum(sql);
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("sch_info_page",Page);
    List<Schedule> list=(ArrayList<Schedule>)db.query(sql+" limit ?,?",new BeanListHandler(Schedule.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<form method="post" action="${pageContext.request.contextPath}/delete?type=sch_info" onsubmit="return isDelete()" target="_self">
    <table align="center" cellspacing="0" cellpadding="2" border="1">
        <tr id="navigation">
            <td width="40">ID</td><td width="110">课程名</td><td width="120">班级</td><td width="110">学期</td><td width="100">教师</td><td width="80">测评分</td>
            <%--<td width="130">备注</td>--%>
            <td width="100">查看</td><td><input type="checkbox" id="deleteAll" onclick="selectAll(1)"/> <input type="submit" value="删除"/></td>
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
                <td><a href="${pageContext.request.contextPath}/JSP/manager/information/sch_info/sch_update.jsp?id=${element.sch_id}">查看</a></td>
                <td><input type="checkbox" name="delete" value="${element.sch_id}"/></td>
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