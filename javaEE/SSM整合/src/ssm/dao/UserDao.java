package ssm.dao;

import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;
import ssm.pojo.MyUser;

import java.util.List;

/**
 * @author liulingjie
 * @date 20-9-1 上午8:15
 */
@Repository("userDao")
@Mapper
/*
 * 使用Spring自动扫描MyBatis的接口并装配 （Spring将指定包中所有被@Mapper注解标注的接口自动装配为Mybatis的映射接口
 */
public interface UserDao {
    /**
     * 接口方法对应SQL映射文件UserMapper.xml中的id
     */
    public List<MyUser> selectUserByUname(MyUser user);
}