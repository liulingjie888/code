create table t_users(
    id int(11) auto_increment primary key ,
    username varchar(255) not null  unique ,
    password varchar(255) not null
) ;

create table t_content(
    id int(11) auto_increment primary key ,
    content varchar(255) not null ,
    publish_time timestamp not null ,
    like_count int(11) default 0 ,    --喜欢数量
    user_id int(11)
) ;

create table t_discuss(
    id int(11) auto_increment primary  key ,
    discuss_content varchar(255) not null , --评论内容
    publish_time timestamp not null ,
    content_id int(11) ,                    --被评论文章的id
    user_id int(11)                         --发表评论的id
) ;
