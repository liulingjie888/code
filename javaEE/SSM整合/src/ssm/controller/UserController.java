package ssm.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import ssm.pojo.MyUser;
import ssm.service.UserService;

import java.util.List;

/**
 * @author liulingjie
 * @date 20-9-1 上午8:17
 */
@Controller
public class UserController {
    @Autowired
    UserService userService;
    @RequestMapping("/select")
    public String select(MyUser user, Model model) {
        List<MyUser> list = userService.selectUserByUname(user);
        model.addAttribute("userList", list);
        return "userList";
    }
}