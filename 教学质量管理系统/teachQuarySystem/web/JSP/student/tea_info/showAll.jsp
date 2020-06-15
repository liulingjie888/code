<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Teacher" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 18:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String sql="select * from teachers where tea_id like '%"+searchText+"%' or tea_name like '%"+searchText+"%'";
    float num=DBUtil.queryNum(sql);
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("tea_info_page_student",Page);
    List<Teacher> list=(ArrayList<Teacher>)db.query(sql+" limit ?,?",new BeanListHandler(Teacher.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<table align="center" cellpadding="2" border="1" cellspacing="0">
    <tr id="navigation">
        <td width="100">ID</td><td width="100">姓名</td><td width="100">性别</td><td width="250">邮箱</td><td width="170">电话号码</td><td width="100">测评</td>
    </tr>
    <c:forEach var="element" items="<%=list%>">
        <%rest--;%>
        <tr>
            <td height="32">${element.tea_id}</td>
            <td>${element.tea_name}</td>
            <td>${element.tea_sex}</td>
            <td>${element.tea_email}</td>
            <td>${element.tea_photo}</td>
                <%--查看是否是师生关系--%>
            <c:set var="teacherID" value="${element.tea_id}" scope="request"/>
            <%
                num=db.exist("select * from stu_tea where tea_id=? and stu_num=?",request.getAttribute("teacherID"),session.getAttribute("student"));
            %>
            <c:set var="num" value="<%=num%>" scope="request"/>
                <%--是师生关系加入测试权限--%>
            <c:if test="${num>0}">
                <%
                    num=db.exist("select * from teaEvaluation where tea_id=? and stu_num=?",request.getAttribute("teacherID"),session.getAttribute("student"));
                    if(num>0){
                %>
                        <td><a href="${pageContext.request.contextPath}/JSP/student/tea_info/tea_eva.jsp?isEva=true&id=${element.tea_id}">已测评</a></td>
                <%
                    }else{
                %>
                        <td><a href="${pageContext.request.contextPath}/JSP/student/tea_info/tea_eva.jsp?isEva=false&id=${element.tea_id}">测评</a></td>
                <%
                    }
                %>
            </c:if>
                <%--不是师生关系没有测试权限--%>
            <c:if test="${num<=0}">
                <td></td>
            </c:if>
        </tr>
    </c:forEach>
    <%--补充行数--%>
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