 #include"chat.h"

// void main(void){
//     MYSQL *conn_prt;
//     liu_mysql_conn(&conn_prt);
//     char *p;
//     liu_mysql_query(conn_prt,"select * from user",&p);
//     mysql_close(conn_prt);
//     printf("字符串为\n%s\n",p);
// }


//查询
/*
    result为存放结果集的二维数组,如(定义:char * result[10][10]={NULL};,传参:result)
    mp为结果集的行数
    np为结果集的字段数
*/
int liu_mysql_query(MYSQL *conn_prt,char *query_str,char **result,int *mp,int *np){
	MYSQL_RES       *res = NULL;
    MYSQL_ROW       row;
    int             rc, fields,i,j;
    int             rows;
    int             n=0;
	// query_str = "select * from user";
    rc = mysql_real_query(conn_prt, query_str, strlen(query_str));	//执行sql语句

    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(conn_prt));
        return -1;
    }

    res = mysql_store_result(conn_prt);								//取出结果集

    if (NULL == res) {
         printf("mysql_restore_result(): %s\n", mysql_error(conn_prt));
         return -1;
    }

    rows = mysql_num_rows(res);				//获取结果集数量
    printf("The total rows is: %d\n", rows);

    fields = mysql_num_fields(res);			//获取结果集字段数量
    printf("The total fields is: %d\n", fields);

    *np=fields;
    *mp=rows;

    for(i=0;i<rows;i++){
        row = mysql_fetch_row(res);
        n=0;
        for(j=0;j<fields;j++){
            *result++=row[j];
            n++;
            printf("字段%s\n",row[j]);
        }
        for(j=n;j<FIELDS;j++){
            *result++=NULL;
        }
        // printf("%d",number-n);
        // *result=*result+(number-n);         //跳到下一行
    }
    
    mysql_free_result(res);
	return 0;

}

//增删改
int liu_mysql_update(MYSQL *conn_prt,char *query_str){
    int rc;

    rc = mysql_real_query(conn_prt, query_str, strlen(query_str));	//执行sql语句

    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(conn_prt));
        return -1;
    }
	return rc;
}

//初始化mysql句柄,并获取它的地址
int liu_mysql_conn(MYSQL **conn_prt_prt){
	
	*conn_prt_prt = mysql_init(NULL);  //初始化MYSQL句柄
 
	if(!*conn_prt_prt){
		printf("connect mysql failed");
		return -1;
	}
 
	/*尝试与mysql数据库连接*/
	if(!mysql_real_connect(*conn_prt_prt,"cdb-e3rotq3y.cd.tencentcdb.com","root","LLJ-MySQL","LINUXCHAT",10063,NULL,0)){
		printf("failed to coonect mysql:%s\n",mysql_error(*conn_prt_prt));
	}else{
		printf("connect success...........\n");
	}

	return 0;
}

//关闭数据库
 void liu_mysql_close(MYSQL *conn_prt){
     mysql_close(conn_prt);
 }

 //查询结果拼接字符串放入result
int liu_mysql_query1(MYSQL *conn_prt,char *query_str,char *result,int *num){
	MYSQL_RES       *res = NULL;
    MYSQL_ROW       row;
    int             rc, fields,i,j;
    int             rows;
	// query_str = "select * from user";
    rc = mysql_real_query(conn_prt, query_str, strlen(query_str));	//执行sql语句

    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(conn_prt));
        return -1;
    }
 
    res = mysql_store_result(conn_prt);								//取出结果集

    if (NULL == res) {
         printf("mysql_restore_result(): %s\n", mysql_error(conn_prt));
         return -1;
    }

    rows = mysql_num_rows(res);				//获取结果集数量
    *num=rows;
    fields = mysql_num_fields(res);			//获取结果集字段数量

    memset(result,0,strlen(result));
    for(i=0;i<rows;i++){
        row = mysql_fetch_row(res);         //拼接字符串,@为记录分割线,&为字段分割线
        if(0!=i)
            strcat(result,"@");
        for(j=0;j<fields;j++){
            if(0!=j)
                strcat(result,"#");
            strcat(result,row[j]);
        }
        
    }
    strcat(result,"\0");
    
    mysql_free_result(res);
	return 0;

}

// void main(){
//     MYSQL *conn_prt;
//    char result[2048]={'\0'};
//    int num=0;
//    char r[16];
//    liu_mysql_conn(&conn_prt);
//    liu_mysql_query1(conn_prt,"select * from messages",result,&num);
//    printf("%s\n",result);
//     liu_mysql_query1(conn_prt,"select * from messages where number<3",result,&num);
//    printf("%s\n",result);
//     liu_mysql_query1(conn_prt,"select * from user",result,&num);
//    printf("%s\n",result);
//    liu_mysql_close(conn_prt);

//    message_id=atof(result);
//    printf("message_id为\n%d\n",message_id);
//    printf("result:%s\n",result);
    
//     // char* result="3543";
//     // int a=atof("234");
//     // int b=atof(result);
//     // printf("%d\n%d",a,b);

// }
