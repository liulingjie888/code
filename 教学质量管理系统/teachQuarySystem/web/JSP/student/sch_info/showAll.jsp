<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="com.jie.utiltool.DBUtil" %>
<%@ page import="com.jie.object.Schedule" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="org.apache.commons.dbutils.handlers.BeanListHandler" %>
<%@ page import="org.apache.commons.dbutils.DbUtils" %><%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/9/8
  Time: 17:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    int Page=Integer.parseInt(request.getParameter("page"));
    String searchText=request.getParameter("searchText");
    DBUtil db=(DBUtil)session.getAttribute("DBUtil");

    String sql="select * from schedule where sch_id like '%"+searchText+"%' or sch_name like '%"+searchText+"%'";
    float num=DBUtil.queryNum(sql);
    int maxPage=(int)Math.ceil(num/DBUtil.row);
    //防止删除后页数溢出
    Page=(Page<=maxPage?Page:maxPage);
    //记录页面
    session.setAttribute("sch_info_page_student",Page);
    List<Schedule> list=(ArrayList<Schedule>)db.query(sql+" limit ?,?",new BeanListHandler(Schedule.class), DBUtil.row*(Page-1),DBUtil.row);
%>
<p align="center">数量：<%=(int)num%>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;页：<%=Page%>&nbsp;/&nbsp;<%=maxPage%></p>
<table id="showtable" align="center" cellspacing="0" border="1" cellpadding="2">
    <tr id="navigation">
        <td width="100">ID</td><td width="100">课程名</td><td width="100">班级</td><td width="100">学期</td><td width="100">教师</td><td width="100">备注</td><td width="100">测评</td>
    </tr>
    <%
        int rest=DBUtil.row;         //记录剩余数
        for(int i=0;i<list.size();i++){
            long start = System.currentTimeMillis();
            num=db.exist("select * from schEvaluation where sch_id=? and stu_num=?",list.get(i).getSch_id(),session.getAttribute("student"));
            int isSch_stu=db.exist("select * from stu_sch where sch_id=? and stu_num=?",list.get(i).getSch_id(),session.getAttribute("student"));
            long end = System.currentTimeMillis();
            System.out.println("3程序运行时间："+(end-start)+"ms"+i);
//           if(searchText.equals("") && isSch_stu<=0)continue;
    %>
    <c:set value="<%=num%>" var="num" />
    <c:set value="<%=isSch_stu%>" var="isSch_stu" />
    <tr>
        <td height="32"><%=list.get(i).getSch_id()%></td>
        <td><%=list.get(i).getSch_name()%></td>
        <td ><%=list.get(i).getCla_name()%></td>
        <td><%=list.get(i).getSch_term()%></td>
        <td ><%=list.get(i).getTea_name()%></td>
        <td><%=list.get(i).getSch_remark()%></td>

        <%--该学生含有该课程--%>
        <c:if test="${isSch_stu>0}">
            <c:choose>
                <c:when test="${num>0}">
                    <td ><a href="${pageContext.request.contextPath}/JSP/student/sch_info/sch_eva.jsp?isEva=true&id=<%=list.get(i).getSch_id()%>">已测评</a></td>
                </c:when>
                <c:otherwise>
                    <td ><a href="${pageContext.request.contextPath}/JSP/student/sch_info/sch_eva.jsp?isEva=false&id=<%=list.get(i).getSch_id()%>">测评</a></td>
                </c:otherwise>
            </c:choose>
        </c:if>
        <%--不含有该课程--%>
        <c:if test="${isSch_stu<=0}">
            <td></td>
        </c:if>
    </tr>
    <%
            rest--;
        }
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