package springboot.user;


import static org.assertj.core.api.Assertions.assertThat;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;
import org.springframework.core.SpringVersion;
import org.springframework.dao.EmptyResultDataAccessException;

import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import springboot.domain.User;

import java.sql.SQLException;

public class UserDaoTest {

    @Autowired
    private UserDao dao;
    private ApplicationContext context;
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        //ConnectionMaker connectionMaker = new DConnectionMaker();
        //UserDao dao = new UserDao(connectionMaker);
        //UserDao dao = new DaoFactory().userDao(); // 팩토리를 사용함.
        //ApplicationContext context = new AnnotationConfigApplicationContext(DaoFactory.class);
    }

    @BeforeEach
    public void setUp(){
        ApplicationContext context = new GenericXmlApplicationContext("applicationContext.xml");
        this.dao = context.getBean("userDao", UserDao.class);
    }

    @Test
    public void addAndGet() throws SQLException, ClassNotFoundException {
//        ApplicationContext context = new GenericXmlApplicationContext("applicationContext.xml");
//        UserDao dao = context.getBean("userDao", UserDao.class);
        dao.deleteAll();

        assertThat(dao.getCount()).isEqualTo(0);
        User user = new User("1dd","박태순","qweq1");
        User user2 = new User("1dd2","박태순2","qweq12");
        dao.deleteAll();
        dao.add(user);
        dao.add(user2);
        assertThat(dao.getCount()).isEqualTo(2);
        System.out.println(user.getId() + "등록 성공");

        User userget1 = dao.get(user.getId());

        assertThat(userget1.getName()).isEqualTo(user.getName());
        assertThat(userget1.getPassword()).isEqualTo(user.getPassword());

        User userget2 = dao.get(user2.getId());

        assertThat(userget2.getName()).isEqualTo(userget2.getName());
        assertThat(userget2.getPassword()).isEqualTo(userget2.getPassword());
    }

    @Test
    public void count() throws SQLException, ClassNotFoundException {
//        ApplicationContext context = new GenericXmlApplicationContext("applicationContext.xml");
//
//        UserDao dao = context.getBean("userDao", UserDao.class);
        User user1 = new User("gyume1","진양철", "no123");
        User user2 = new User("gyume2","진도준", "no124");
        User user3 = new User("gyume3","진비비", "no125");

        dao.deleteAll();
        assertThat(dao.getCount()).isEqualTo(0);

        dao.add(user1);
        assertThat(dao.getCount()).isEqualTo(1);

        dao.add(user2);
        assertThat(dao.getCount()).isEqualTo(2);

        dao.add(user3);
        assertThat(dao.getCount()).isEqualTo(3);
    }

    @Test
    public void getUserFailure() throws SQLException, ClassNotFoundException {
//        ApplicationContext context = new GenericXmlApplicationContext("applicationContext.xml");
//        UserDao dao = context.getBean("userDao", UserDao.class);
        dao.deleteAll();
        assertThat(dao.getCount()).isEqualTo(0);
        org.junit.jupiter.api.Assertions.assertThrows(EmptyResultDataAccessException.class, () -> {
            dao.get("unknown_id");
        });
    }
}
