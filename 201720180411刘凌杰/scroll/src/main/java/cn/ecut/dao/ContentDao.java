package cn.ecut.dao;

import cn.ecut.exception.DaoException;
import cn.ecut.model.Content;
import cn.ecut.model.User;
import cn.ecut.util.JDBCHelper;
import cn.ecut.util.TableNames;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author lujiapeng
 * @className ContentDao
 * @description TODO
 * @date 2020/9/18 9:51
 **/
public class ContentDao {
    private UserDao userDao = new UserDao() ;
    private String column = " content, publish_time , like_count, user_id " ;

    public boolean addContent(Content c) {
        String SQL = "insert into " + TableNames.CONTENT_TABLE_NAME + "( content, publish_time , like_count, user_id) values ( ? , ? , ? , ?)";
        return JDBCHelper.execute( SQL , c.getContent() , c.getPublishTime() , c.getLikeCount() , c.getUser().getId() ) ;
    }

    public List<Content> list( Integer begin ) {
        String SQL = "select id , " + column + " from" + TableNames.CONTENT_TABLE_NAME + " order by publish_time  limit ? , ? " ;
        ResultSet resultSet = JDBCHelper.query(SQL, begin,15);
        List<Content> warp = warp(resultSet);
        return warp ;
    }

    public List<Content> listTop( ) {
        String SQL = "select id , " + column + " from" + TableNames.CONTENT_TABLE_NAME + " order by like_count limit 0 ,10 " ;
        ResultSet resultSet = JDBCHelper.query(SQL);
        List<Content> warp = warp(resultSet);
        return warp ;
    }


    public Content loadById( Integer id ) {
        String SQL = "select id , " + column + " from" + TableNames.CONTENT_TABLE_NAME + " where id = ?" ;
        ResultSet resultSet = JDBCHelper.query(SQL, id );

        List<Content> warp = warp(resultSet);
        if( warp.size() > 0 ){
            return warp.get( 0 ) ;
        }
        return null ;
    }


    private List<Content> warp(ResultSet resultSet ) throws DaoException {
        List<Content> list = new ArrayList<>() ;
        try {
            while( resultSet.next() ){
                Content c = new Content() ;
                c.setId( resultSet.getInt("id"));
                c.setContent( resultSet.getString("content"));
                c.setPublishTime( resultSet.getTimestamp( "publish_time"));
                c.setLikeCount( resultSet.getInt( "like_count"));
                // 调用 userDao 中的方法
                User user = userDao.loadByUserId(resultSet.getInt("user_id"));
                c.setUser( user );
                list.add( c ) ;
            }
        } catch (SQLException e) {
            throw new DaoException("数据封装出错。") ;
        }
        return list ;
    }
}
