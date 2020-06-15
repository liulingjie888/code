<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/10
  Time: 19:10
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
var cla=document.getElementById("cla");
var tea=document.getElementById("tea");
var cla_hint=document.getElementById("cla_hint");
var tea_hint=document.getElementById("tea_hint");
var cla_isExist=true;
var tea_isExist=true;
var cla_http=new XMLHttpRequest();
cla_http.onreadystatechange=cla_checkResult;
var tea_http=new XMLHttpRequest();
tea_http.onreadystatechange=tea_checkResult;
var check_url="${pageContext.request.contextPath}/JSP/manager/check.jsp";
