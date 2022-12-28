package springboot.dao;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springboot.user.UserDao;

@Configuration
public class CountingDaoFactory {

    @Bean
    public UserDao userDao(){
        //return new UserDao(connectionMaker());
        return null;
    }

    @Bean
    public ConnectionMaker connectionMaker(){
        return new CountingConnectionMaker(realConnectionMaker());
    }

    @Bean
    public ConnectionMaker realConnectionMaker(){
        return new DConnectionMaker();
    }
}
