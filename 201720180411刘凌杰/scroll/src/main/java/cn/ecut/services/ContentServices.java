package cn.ecut.services;

import cn.ecut.dao.ContentDao;
import cn.ecut.dao.DiscussDao;
import cn.ecut.model.Content;
import cn.ecut.model.Discuss;

import java.sql.Timestamp;
import java.util.List;

/**
 * @author lujiapeng
 * @className ContentServices
 * @description TODO
 * @date 2020/9/18 9:49
 **/
public class ContentServices {
    private ContentDao cd = new ContentDao() ;
    private DiscussDao dd = new DiscussDao() ;
    public boolean addContent(Content c) {
        c.setLikeCount( 0 );
        c.setPublishTime( new Timestamp( System.currentTimeMillis() ));
        // 调用DAO ，将其添加到数据库中
        return cd.addContent( c ) ;
    }

    public List<Content> list( Integer begin ) {
        if( begin != 0 ){
            begin  += 1 ;
        }
        return cd.list( begin ) ;
    }

    public Content loadById( Integer id ) {
        Content content = cd.loadById( id ) ;
        // 期望看到评论
        List<Discuss> discusses = dd.loadDiscussesByContentId(id);
        content.setDiscussList( discusses );
        return content  ;
    }
}
