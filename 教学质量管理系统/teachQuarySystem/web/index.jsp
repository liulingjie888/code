
<%--
  Created by IntelliJ IDEA.
  User: LLJ
  Date: 2019/8/31
  Time: 9:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page session="true" %>
<%
  String sessionState=request.getParameter("destorySession");
  if(sessionState!=null && sessionState.equals("true"))
      request.getSession(false).invalidate();
%>
<html>
<head>
  <meta charset="UTF-8">
  <title>登入界面</title>

  <style>
    .t1{
      font-size:18px;
      width:250px;
      height:30px;
    }
    .t2{
      width:65px;
      height:35px;
      font-size:18px;
    }
    .t3{
      width:20px;
      height:20px;
    }
    table{
      font-size:20px;
    }
    #hint{
      color:red;
      font-size:18px;
    }
    body{
      background-image:url("image/home.jpg");
    }
  </style>
</head>

<body>

<form name="form1" method="post" action="${pageContext.request.contextPath}/checkUserServlet">
  <table align="center" width="1000" height="600" border="0"
         cellpadding="5" cellspacing="0">
    <tr >
      <td height="25%" colspan="2" align="center" valign="middle"><font size="+3">教学质量网络测评系统</font></td>
    </tr>
    <tr>
      <td align="right"  width="58%">用户名</td>
      <td height="60"><input name="username" type="text" class="t1" required="required"/>&nbsp;
      <input name="manager" type="checkbox" class="t3" value="power" onclick="checkbox()"/>管理员
      </td>
    </tr>
    <tr>
      <td align="right">密码</td>
      <%
        String param=request.getParameter("error");
        String hint="";
        if (param!=null && param.equals("passwordWrong"))
          hint=" 密码或用户名错误";
      %>
      <td height="80"><input name="password" type="password" class="t1" required="required"/><span id="hint"><%=hint%></span></td>
    </tr>
    <tr>
      <td></td>
      <td valign="top"><br />&nbsp;&nbsp;<input name="submit" type="submit" class="t2" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input name="reset" type="reset" class="t2"/></td>
    </tr>
  </table>
</form>
<script>
  function checkbox(){
    if(""==form1.save.disabled){
      form1.save.disabled="disabled";
    }
    else{
      form1.save.disabled="";
    }
  }
</script>

</body>
</html>
