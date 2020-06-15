function sch_check() {
    sch_http.open("GET",check_url+"?type=sch&value="+sch.value,true);
    sch_http.send(null);
}

function sch_checkResult() {
    if(sch_http.readyState==4 && sch_http.status==200){
        if(sch_http.responseText.trim()=="exist"){
            sch_isExist=true;
            sch_hint.innerHTML="";
        }else{
            sch_isExist=false;
            sch_hint.innerHTML="  该课程ID不存在";
        }
    }
}

function tea_check() {
    tea_http.open("GET",check_url+"?type=tea_id&value="+tea.value,true);
    tea_http.send(null);
}

function tea_checkResult() {
    if(tea_http.readyState==4 && tea_http.status==200){
        if(tea_http.responseText.trim()=="exist"){
            tea_isExist=true;
            tea_hint.innerHTML="";
        }else{
            tea_isExist=false;
            tea_hint.innerHTML="  该教师ID不存在";
        }
    }
}

function stu_check() {
    stu_http.open("GET",check_url+"?type=stu&value="+stu.value,true);
    stu_http.send(null);
}


function stu_checkResult() {
    if(stu_http.readyState==4 && stu_http.status==200){
        if(stu_http.responseText.trim()=="exist"){
            stu_isExist=true;
            stu_hint.innerHTML="";
        }else{
            stu_isExist=false;
            stu_hint.innerHTML="  该学生不存在";
        }
    }
}

