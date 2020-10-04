package cn.ecut.services;

import cn.ecut.dao.ContentDao;
import cn.ecut.dao.DiscussDao;
import cn.ecut.model.Content;
import cn.ecut.model.Discuss;

import java.sql.Timestamp;

/**
 * @author lujiapeng
 * @className DiscussServices
 * @description TODO
 * @date 2020/9/18 16:43
 **/
public class DiscussServices {

    private ContentDao contentDao = new ContentDao() ;
    private DiscussDao discussDao = new DiscussDao() ;
    public boolean add(Discuss discuss, String contentId) {
        // 获取到一个 Content
        Content content = contentDao.loadById(Integer.valueOf(contentId));
        discuss.setContent( content );
        discuss.setPublishTime( new Timestamp(System.currentTimeMillis() )) ;
        return  discussDao.add( discuss ) ;

    }
}
