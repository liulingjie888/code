package ssm.service;

import ssm.pojo.MyUser;

import java.util.List;

/**
 * @author liulingjie
 * @date 20-9-1 上午8:16
 */
public interface UserService {
    public List<MyUser> selectUserByUname(MyUser user);
}
