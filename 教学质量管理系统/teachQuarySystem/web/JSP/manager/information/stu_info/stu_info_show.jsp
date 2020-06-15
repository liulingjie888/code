<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="java.util.List" %>
<%@ page import="com.jie.object.Student" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 13:20
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String sql="select * from students where stu_num like '%"+searchText+"%' or stu_name like '%"+searchText+"%' or cla_name like '%"+searchText+"%'";
    float num=DBUtil.queryNum(sql);
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("stu_info_page",Page);
    System.out.println("stu_info当前页面： "+session.getAttribute("stu_info_page"));

    List<Student> list=(ArrayList<Student>)db.query(sql+" limit ?,?",new BeanListHandler(Student.class), DBUtil.row*(Page-1),DBUtil.row);
    int rest=DBUtil.row;
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<form id="myform" method="post" action="" onsubmit="return isDelete()" target="_self">
    <table align="center" border="1" cellpadding="2" cellspacing="0">
        <tr id="navigation">
            <td width="40">ID</td><td width="140">学号</td><td width="100">姓名</td><td width="80 ">性别</td><td width="230">身份证</td><td width="100">班级</td>
            <%--<td width="210">邮箱</td><td width="220">地址</td><td width="150">电话</td>--%>
            <td width="150">密码</td><td width="60">查看</td>
            <td width="100"><input type="checkbox" id="deleteAll" onclick="selectAll(1)"/><input type="button" value="删除" onclick="deleteform()"/></td>
            <td width="150"><input type="checkbox" id="addSch" onclick="selectAll(2)"/><input type="button" value="添加课程" onclick="rela_form(1)"/></td>
            <td width="150"><input type="checkbox" id="addTea" onclick="selectAll(3)"/><input type="button" value="添加教师" onclick="rela_form(2)"/></td>
        </tr>
        <c:forEach var="element" items="<%=list%>">
            <tr>
                <% rest--;%>
                <td height="32">${element.stu_id}</td>
                <td>${element.stu_num}</td>
                <td>${element.stu_name}</td>
                <td>${element.stu_sex}</td>
                <td>${element.stu_identity}</td>
                <%--<td>${element.stu_email}</td>--%>
                <%--<td>${element.stu_address}</td>--%>
                <%--<td>${element.stu_photo}</td>--%>
                <td>${element.cla_name}</td>
                <td>${element.stu_password}</td>
                <td><a href="${pageContext.request.contextPath}/JSP/manager/information/stu_info/stu_update.jsp?id=${element.stu_id}">查看</a></td>
                <td><input type="checkbox" name="delete" value="${element.stu_id}"/></td>
                <td><input type="checkbox" name="sch_check" value="${element.stu_num}"/></td>
                <td><input type="checkbox" name="tea_check" value="${element.stu_num}"/></td>
            </tr>
        </c:forEach>
        <%
            for(int i=0;i<rest;i++){
        %>
                <tr><td height="32"></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr>
        <%
            }
        %>
    </table>
    <input type="hidden" id="firstPage" value="1"/>
    <input type="hidden" id="previousPage" value="<%=((Page-1)<1?1:(Page-1))%>"/>
    <input type="hidden" id="nextPage" value="<%=((Page+1)>maxPage?maxPage:(Page+1))%>"/>
    <input type="hidden" id="lastPage" value="<%=maxPage%>"/>
</form>