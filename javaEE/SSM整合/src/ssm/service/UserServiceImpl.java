package ssm.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import ssm.pojo.MyUser;
import ssm.dao.UserDao;

import java.util.List;

/**
 * @author liulingjie
 * @date 20-9-1 上午8:16
 */
@Service("userService")
@Transactional
/**
 * 加上注解@Transactional可以指定这个类需要受Spring的事务管理，
 *注意@Transactional只能针对public属性范围内的方法添加，
 *本案例并不需要处理事务，在这里只是告诉读者如何使用事务
 */
public class UserServiceImpl implements UserService {
    @Autowired
    private UserDao userDao;
    @Override
    public List<MyUser> selectUserByUname(MyUser user) {
        return userDao.selectUserByUname(user);
    }
}