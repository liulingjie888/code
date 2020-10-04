package cn.ecut.model;

import java.sql.Timestamp;
import java.util.List;

/**
 * @author lujiapeng
 * @className Content
 * @description TODO
 * @date 2020/9/18 9:46
 **/
public class Content {
    private Integer id ;
    private String content ;
    private Timestamp publishTime ;
    private Integer likeCount ;
    private User user ;
    private List<Discuss> discussList ;

    public List<Discuss> getDiscussList() {
        return discussList;
    }

    public void setDiscussList(List<Discuss> discussList) {
        this.discussList = discussList;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public Timestamp getPublishTime() {
        return publishTime;
    }

    public void setPublishTime(Timestamp publishTime) {
        this.publishTime = publishTime;
    }

    public Integer getLikeCount() {
        return likeCount;
    }

    public void setLikeCount(Integer likeCount) {
        this.likeCount = likeCount;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }
}
