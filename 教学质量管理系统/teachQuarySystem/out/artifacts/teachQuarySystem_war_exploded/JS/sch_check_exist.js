function cla_check() {
    cla_http.open("GET",check_url+"?type=cla&value="+cla.value,true);
    cla_http.send(null);
}

function cla_checkResult() {
    if(cla_http.readyState==4 && cla_http.status==200){
        if(cla_http.responseText.trim()=="exist"){
            cla_isExist=true;
            cla_hint.innerHTML="";
        }else{
            cla_isExist=false;
            cla_hint.innerHTML=" 该班级不存在";
        }
    }
}

function tea_check() {
    tea_http.open("GET",check_url+"?type=tea_name&value="+tea.value,true);
    tea_http.send(null);
}


function tea_checkResult() {
    if(tea_http.readyState==4 && tea_http.status==200){
        if(tea_http.responseText.trim()=="exist"){
            tea_isExist=true;
            tea_hint.innerHTML="";
        }else{
            tea_isExist=false;
            tea_hint.innerHTML=" 该教师不存在";
        }
    }
}