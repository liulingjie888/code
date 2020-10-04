package cn.ecut.dao;

import cn.ecut.exception.DaoException;
import cn.ecut.model.Content;
import cn.ecut.model.Discuss;
import cn.ecut.model.User;
import cn.ecut.util.JDBCHelper;
import cn.ecut.util.TableNames;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author lujiapeng
 * @className DiscussDao
 * @description TODO
 * @date 2020/9/18 16:18
 **/
public class DiscussDao {
    private String column = " discuss_content, publish_time , content_id, user_id " ;
    private UserDao userDao = new UserDao() ;
    private ContentDao contentDao = new ContentDao() ;

    public boolean add(Discuss discuss) {
        String SQL = "insert into " + TableNames.DISCUSS_TABLE_NAME +"( " + column+ ") values ( ? , ? , ? , ? )" ;
        return JDBCHelper.execute( SQL , discuss.getDiscussContent() , discuss.getPublishTime() , discuss.getContent().getId() , discuss.getUser().getId() ) ;

    }


    public List<Discuss> loadDiscussesByContentId(Integer contentId) {
        String SQL = "select id , " + column + " from " + TableNames.DISCUSS_TABLE_NAME + " where content_id = ? " ;
        ResultSet resultSet = JDBCHelper.query(SQL, contentId);
        List<Discuss> warp = warp(resultSet);
        return warp ;
    }



    private List<Discuss> warp(ResultSet resultSet ) throws DaoException {
        List<Discuss> list = new ArrayList<>() ;
        try {
            while( resultSet.next() ){
                Discuss c = new Discuss() ;
                c.setId( resultSet.getInt("id"));
                c.setDiscussContent( resultSet.getString("discuss_content"));
                c.setPublishTime( resultSet.getTimestamp( "publish_time"));
                // 调用 userDao 中的方法
                User user = userDao.loadByUserId(resultSet.getInt("user_id"));

                c.setUser( user );
                Content content = contentDao.loadById(resultSet.getInt("content_id"));
                c.setContent( content );
                list.add( c ) ;
            }
        } catch (SQLException e) {
            throw new DaoException("数据封装出错。") ;
        }
        return list ;
    }


}
