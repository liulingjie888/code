package cn.ecut.model;

import java.sql.Timestamp;

/**
 * @author lujiapeng
 * @className Discuss
 * @description TODO
 * @date 2020/9/18 16:16
 **/
public class Discuss {
    private Integer id ;
    private String discussContent ;
    private Timestamp publishTime ;
    private Content content ;
    private User user ;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getDiscussContent() {
        return discussContent;
    }

    public void setDiscussContent(String discussContent) {
        this.discussContent = discussContent;
    }

    public Timestamp getPublishTime() {
        return publishTime;
    }

    public void setPublishTime(Timestamp publishTime) {
        this.publishTime = publishTime;
    }

    public Content getContent() {
        return content;
    }

    public void setContent(Content content) {
        this.content = content;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }
}
