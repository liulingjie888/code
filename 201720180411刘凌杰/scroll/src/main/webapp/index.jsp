<%--
  Created by IntelliJ IDEA.
  User: lujiapeng
  Date: 2020/9/17
  Time: 14:53
  To change this template use File | Settings | File Templates.
--%>
<!DOCTYPE html>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>主页</title>
    <link href="${pageContext.request.contextPath}/css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="${pageContext.request.contextPath}/font-awesome-4.7.0/css/font-awesome.min.css" type="text/css" rel="stylesheet">
    <script src="${pageContext.request.contextPath}/js/jquery-3.5.1.min.js"></script>
    <style type="text/css">
        *{
            margin: 0px;
            padding: 0px;
        }
    </style>
</head>
<body >

<script type="text/javascript">
    let begin = 0 ;
    var getting=0,ok=0;
    function discuss( id ){
        // 此时的id ，就是 内容的id
        <%--$.post("${pageContext.request.contextPath}/content/detail" , {contentId:id} )--%>
        window.location = "${pageContext.request.contextPath}/content/detail?id=" + id ;
    }

    $(function(){

        $.post("${pageContext.request.contextPath}/content/list" ,{num:begin} ,  function (responseData){
            console.log( responseData ) ;
            if( responseData.status == 0 ){
                // 此时证明是成功的
                let datas = responseData.data ;  // 此时是数组
                // window.alert("成功"+responseData.toString());
                for( let i = 0 ; i < datas.length ; i++ ) {
                    let xxx = datas[i] ;
                    // 创建一个div ，向 div 中填充内容
                    let e = $("<div style=\"margin-bottom: 10px;box-shadow: 0px 1px 3px #2d2c2c ;\" onclick='discuss("+xxx.id+")'>\n" +
                        "                <div >\n" +
                        "                    <div style=\"text-align: left ; padding-left: 10px; padding-top: 10px\">" +xxx.user.username +"</div>\n" +
                        "                    <div style=\"text-align: center\">" + xxx.content + "</div>\n" +
                        "                </div>\n" +
                        "                <div style=\"text-align: right ; padding-bottom: 10px ; padding-right: 10px;\">\n" +
                        "                   " + xxx.publishTime + " <i class='fa fa-thumbs-up'></i>&nbsp;" + xxx.likeCount + "\n" +
                        "                </div>\n" +
                        "            </div>");

                    // 追加一个元素
                    $("#contentList").append( e ) ;
                }

                begin=begin+datas.length;
            }
        } , "JSON") ;

        //前十
        $.post("${pageContext.request.contextPath}/content/top"  ,  function (responseData){
            console.log( responseData ) ;
            if( responseData.status == 0 ){
                // 此时证明是成功的
                let datas = responseData.data ;  // 此时是数组
                // window.alert("成功"+responseData.toString());
                for( let i = 0 ; i < datas.length ; i++ ) {
                    let xxx = datas[i] ;
                    // 创建一个div ，向 div 中填充内容
                    let e = $("<div style=\"margin-bottom: 10px;box-shadow: 0px 1px 3px #2d2c2c ;\" onclick='discuss("+xxx.id+")'>\n" +
                        "                <div >\n" +
                        "                    <div style=\"text-align: left ; padding-left: 10px; padding-top: 10px\">" +xxx.user.username +"</div>\n" +
                        "                    <div style=\"text-align: center\">" + xxx.content + "</div>\n" +
                        "                </div>\n" +
                        "                <div style=\"text-align: right ; padding-bottom: 10px ; padding-right: 10px;\">\n" +
                        "                   " + xxx.publishTime + " <i class='fa fa-thumbs-up'></i>&nbsp;" + xxx.likeCount + "\n" +
                        "                </div>\n" +
                        "            </div>");

                    // 追加一个元素
                    $("#top").append( e ) ;
                }
            }
        } , "JSON") ;

        // 获取用户信息
        $.post("${pageContext.request.contextPath}/user/getInfo" , function(responseData){
            if( responseData.status == -1 ){
                $("#userInfo").css("display" , "none") ;
                $("#login").css("display" , "block").click(function(){
                    window.location = "${pageContext.request.contextPath}/login.jsp"
                }) ;
            }else if(responseData.status == 0){
                $("#login").css("display" , "none") ;
                $("#userInfo").css("display" , "block") ;
                $("#username").text(responseData.data.username) ;
                $("#publish_content").click(function(){
                    window.location = "${pageContext.request.contextPath}/publish_content.jsp"
                })
            }
        } , "JSON") ;

        //获取用户更多信息
        $(window).scroll(function() {
            if(getting==1) {return;}

            if ($(window).scrollTop() >= $(document).height() -$(window).height()-1) {

                getting=1;
                $.post("${pageContext.request.contextPath}/content/list" ,{num:begin} ,  function (responseData){
                    console.log( responseData ) ;
                    if( responseData.status == 0 ){
                        // 此时证明是成功的
                        let datas = responseData.data ;  // 此时是数组
                        // window.alert("成功"+responseData.toStrinhttp://localhost:8080/scroll_war_exploded/g());
                        for( let i = 0 ; i < datas.length ; i++ ) {
                            begin++;
                            let xxx = datas[i] ;
                            // 创建一个div ，向 div 中填充内容
                            let e = $("<div style=\"margin-bottom: 10px;box-shadow: 0px 1px 3px #2d2c2c ;\" onclick='discuss("+xxx.id+")'>\n" +
                                "                <div >\n" +
                                "                    <div style=\"text-align: left ; padding-left: 10px; padding-top: 10px\">" +xxx.user.username +"</div>\n" +
                                "                    <div style=\"text-align: center\">" + xxx.content + "</div>\n" +
                                "                </div>\n" +
                                "                <div style=\"text-align: right ; padding-bottom: 10px ; padding-right: 10px;\">\n" +
                                "                   " + xxx.publishTime + " <i class='fa fa-thumbs-up'></i>&nbsp;" + xxx.likeCount + "\n" +
                                "                </div>\n" +
                                "            </div>");

                            // 追加一个元素
                            $("#contentList").append( e ) ;
                        }

                    }
                    getting=0;
                } , "JSON") ;


                // alert("滚动条已经到达底部为" + $(window).scrollTop()+" "+ $(window).height()+"  "+$(document).height() );
            }
        });
    })
</script>

    <div class="row" style="margin-top: 5% ; width: 100%">
        <div class="col-md-4 " style="text-align: right; font-weight: bolder">
            <div id="user">
                <div id="userInfo">
                    <div id="username"></div>
                    <div id="publish_content" style="color: red ; font-weight: bolder">发布内容</div>
                    等...
                </div>
                <div id="login">登录</div>
            </div>
        </div>
        <div class="col-md-4 " id="contentList">

        </div>
        <div class="col-md-4 " id="top">
            点赞最高十条数据
        </div>
    </div>

</body>
</html>
