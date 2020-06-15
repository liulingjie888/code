function isDelete() {
    if(confirm("是否确认删除?"))
        return true;
    else
        return false;
}

function selectAll(select) {

    if(select==1) {
        var delete1 = document.getElementById("deleteAll");
        var delete2 = document.getElementsByName("delete");
    }

    if(select==2) {
        var delete1 = document.getElementById("addSch");
        var delete2 = document.getElementsByName("sch_check");
    }

    if(select==3) {
        var delete1 = document.getElementById("addTea");
        var delete2 = document.getElementsByName("tea_check");
    }

    if(delete1.checked=="")
        for(var i=0;i<delete2.length;i++)
            delete2[i].checked="";
    else
        for(var i=0;i<delete2.length;i++)
            delete2[i].checked="checked";

}