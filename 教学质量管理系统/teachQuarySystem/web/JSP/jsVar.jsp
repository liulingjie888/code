<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/9
  Time: 10:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%--window.onload=aimPage(<%=session.getAttribute("stu_info_page")==null?1:session.getAttribute("stu_info_page")%>);--%>

var searchInput=document.getElementById("searchText");
var searchCode=document.getElementById("searchCode");
var show=document.getElementById("show");

var xmlhttp=new XMLHttpRequest();
xmlhttp.onreadystatechange=checkResult;

<%--<c:if test="${param.success=='true'}">--%>
<%--alert("添加成功！");--%>
<%--</c:if>--%>
<%--<c:if test="${param.success=='false'}">--%>
<%--alert("添加失败！");--%>
<%--</c:if>--%>

