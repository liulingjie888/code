<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/18
  Time: 9:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>成功页面</title>
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
