package cn.ecut.services;

import cn.ecut.dao.UserDao;
import cn.ecut.model.User;

import java.util.List;
import java.util.Objects;

/**
 * @author lujiapeng
 * @className UserServices
 * @description TODO
 * @date 2020/9/17 14:36
 **/
public class UserServices {

    private UserDao userDao = new UserDao() ;

    /**
     * 根据用户名和密码获取User对象
     * @param user 封装了 用户名和密码的 User 对象
     * @return
     */
    public User loadByUsername(User user ) {
        // 需要 利用 DAO 层，访问数据库
        List<User> list = userDao.loadByUsername(user);
        if(Objects.nonNull( list ) && list.size() > 0 ){
            return list.get( 0 ) ;
        }
        return null ;
    }


    /**
     * 保存用户对象
     * @param user 用户对象
     * @return
     */
    public boolean saveUser(User user){
        return userDao.saveUser( user ) ;
    }


}
