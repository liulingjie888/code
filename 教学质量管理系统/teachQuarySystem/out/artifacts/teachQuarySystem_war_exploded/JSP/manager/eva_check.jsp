<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/10
  Time: 19:38
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
var sch=document.getElementById("sch");
var stu=document.getElementById("stu");
var tea=document.getElementById("tea");
var sch_hint=document.getElementById("sch_hint");
var stu_hint=document.getElementById("stu_hint");
var tea_hint=document.getElementById("tea_hint");
var sch_isExist=true;
var stu_isExist=true;
var tea_isExist=true;
var sch_http=new XMLHttpRequest();
sch_http.onreadystatechange=sch_checkResult;
var stu_http=new XMLHttpRequest();
stu_http.onreadystatechange=stu_checkResult;
var tea_http=new XMLHttpRequest();
tea_http.onreadystatechange=tea_checkResult;
var check_url="${pageContext.request.contextPath}/JSP/manager/check.jsp";

