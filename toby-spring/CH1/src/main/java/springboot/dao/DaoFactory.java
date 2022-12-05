package springboot.dao;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;


@Configuration // 애플리케이션 컨텍스트 또는 빈 팩토리가 사용할 설정정보라는 표시
public class DaoFactory {

    @Bean // 오브젝트 생성을 담당하는 IoC용 메소드 라는 표시
    public UserDao userDao(){
        ConnectionMaker connectionMaker = new DConnectionMaker(); // 팩토리의 메소드는 UserDao 타입의 오브젝트를 어떻게 만들고, 어떻게 준비시킬지 결정한다.
        UserDao userDao = new UserDao();
        // 수정자 DI 방식
        userDao.setConnectionMaker(connectionMaker);
        return userDao;
    }
    @Bean
    public ConnectionMaker connectionMaker(){
        return new DConnectionMaker();
    }
}
