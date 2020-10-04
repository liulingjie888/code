<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/18
  Time: 16:48
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>失败</title>
</head>
<body>
<c:if test="${not empty msg}">
    <h1 style="text-align: center;color: red;font-weight: bolder">${msg}</h1>
    <script type="text/javascript">
        let fn = function(){
            window.location = "${pageContext.request.contextPath}/index.jsp" ;
        }
        setTimeout( fn , 3000 ) ;
    </script>
</c:if>
</body>
</html>
