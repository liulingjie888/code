
//搜索且第一页
function first() {
    var url=requestUrl+"?page=1&searchText="+searchInput.value+"&searchCode="+searchCode.value;
    xmlhttp.open("GET",url,true);
    xmlhttp.send(null);
}
//上一页
function previous() {
    var page=document.getElementById("previousPage");
    var url=requestUrl+"?page="+page.value+"&searchText="+searchInput.value+"&searchCode="+searchCode.value;
    xmlhttp.open("GET",url,true);
    xmlhttp.send(null);
}
//下一页
function next() {
    var page=document.getElementById("nextPage");
    var url=requestUrl+"?page="+page.value+"&searchText="+searchInput.value+"&searchCode="+searchCode.value;
    xmlhttp.open("GET",url,true);
    xmlhttp.send(null);
}
//最后一页
function last() {
    var page=document.getElementById("lastPage");
    var url=requestUrl+"?page="+page.value+"&searchText="+searchInput.value+"&searchCode="+searchCode.value;
    xmlhttp.open("GET",url,true);
    xmlhttp.send(null);
}

function checkResult() {
    if(xmlhttp.readyState==4 && xmlhttp.status==200){
        show.innerHTML=xmlhttp.responseText;
    }
}

