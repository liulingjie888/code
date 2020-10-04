<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/17
  Time: 16:58
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>发布内容</title>
    <link href="${pageContext.request.contextPath}/css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="${pageContext.request.contextPath}/font-awesome-4.7.0/css/font-awesome.min.css" type="text/css" rel="stylesheet">
    <script src="${pageContext.request.contextPath}/js/jquery-3.5.1.min.js"></script>
</head>
<body>
    <div class="row" style="width: 100%;margin-top: 5% ;">
        <div class="col-md-4 " ></div>
        <div class="col-md-4 " >
            <form action="${pageContext.request.contextPath}/content/publish" method="post">
                <textarea style="width: 100%" class="form-control" name="content"></textarea>
                <br>
                <br>
                <button type="submit" class="btn btn-primary btn-block">发布</button>
                <br>
                <button type="reset" class="btn btn-primary btn-block">取消</button>
            </form>
        </div>
        <div class="col-md-4 " ></div>


    </div>

</body>
</html>

