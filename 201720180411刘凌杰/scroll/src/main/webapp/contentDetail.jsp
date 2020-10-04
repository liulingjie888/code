<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/18
  Time: 16:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
<head>
    <title>内容详情</title>
    <link href="${pageContext.request.contextPath}/css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="${pageContext.request.contextPath}/font-awesome-4.7.0/css/font-awesome.min.css" type="text/css" rel="stylesheet">
    <script src="${pageContext.request.contextPath}/js/jquery-3.5.1.min.js"></script>
</head>
<body>

    <div>
        <div>内容是 ： ${content.content}</div>
        <div>发布时间是 ： ${content.publishTime}</div>
        <div>作者 ： ${content.user.username}</div>
        <div><i class='fa fa-thumbs-up'></i>： ${content.likeCount}</div>
    </div>
    <div>
        <c:if test="${not empty content.discussList}">
            <c:forEach items="${content.discussList}" var="discuss">
                <div>评论内容： ${discuss.discussContent}</div>
                <div>评论时间： ${discuss.publishTime}</div>
                <div>评论人： ${discuss.user.username}</div>
            </c:forEach>
        </c:if>
    </div>
    <div>
        <form action="${pageContext.request.contextPath}/discuss/publish" method="post">
            <input type="hidden" value="${content.id}" name="contentId">
            <textarea style="width: 100%" class="form-control" name="content"></textarea>
            <br>
            <br>
            <button type="submit" class="btn btn-primary btn-block">发布</button>
            <br>
            <button type="reset" class="btn btn-primary btn-block">取消</button>
        </form>
    </div>
</body>
</html>
