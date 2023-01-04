package springboot.user;

import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.context.annotation.Bean;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import springboot.dao.ConnectionMaker;
import springboot.domain.User;
import springboot.user.dao.JdbcContext;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

// 리스트 1-6 독립된 SimpleConnectionMaker를 사용하게 만든 UserDao

public class UserDao {

    private ConnectionMaker connectionMaker;

    private DataSource dataSource;

    private JdbcContext jdbcContext;

    public void setJdbcContext(JdbcContext jdbcContext){
        this.jdbcContext = jdbcContext;
    }

    public void setDataSource(DataSource dataSource) {
        this.jdbcContext = new JdbcContext(); // JdbcContext -> JdbcContext 생성 (IoC) // 수정자 메소드이면서 JdbcContext에 대한 생성, DI 작업을 동시에 한다.
        this.jdbcContext.setDataSource(dataSource);
        this.dataSource = dataSource;

    }

//    public UserDao(){
//        connectionMaker = new DConnectionMaker(); // 앗! 그런데 여기에는 클래스 이름이 나오네
//    }

    //수정자 메소드 DI 방식
//    public void setConnectionMaker(ConnectionMaker connectionMaker) {
//        this.connectionMaker = connectionMaker;
//    }

//    public UserDao(ConnectionMaker connectionMaker){
//        this.connectionMaker = connectionMaker;
//    }

    public void add(User user) throws SQLException{
        this.jdbcContext.workWithStatementStrategy(new StatementStrategy() {
            @Override
            public PreparedStatement makePreparedStatement(Connection c) throws SQLException {
                PreparedStatement ps = c.prepareStatement("insert into users(id, name, password) values(?,?,?)");
                ps.setString(1, user.getId());
                ps.setString(2, user.getName());
                ps.setString(3, user.getPassword());
                return ps;
            }
        });

    }

    public User get(String id) throws SQLException, ClassNotFoundException {
        Connection c = dataSource.getConnection();
//        Connection c = connectionMaker.makeConnection();

        PreparedStatement ps = c
                .prepareStatement("select * from users where id = ?");

        ps.setString(1, id);

        ResultSet rs = ps.executeQuery();

        User user = null;
        if(rs.next()){
            user = new User();
            user.setId(rs.getString("id"));
            user.setName(rs.getString("name"));
            user.setPassword(rs.getString("password"));
        }

        rs.close();
        ps.close();
        c.close();

        if(user == null) throw new EmptyResultDataAccessException(1);

        return user;
    }

    public void deleteAll() throws SQLException{
        this.jdbcContext.executeSql("delete from users");
    }

    public int getCount() throws SQLException{
        Connection c = null;
        PreparedStatement ps = null;
        ResultSet rs = null;

        try {
            c = dataSource.getConnection();
            ps = c.prepareStatement("select count(*) from users");
            rs = ps.executeQuery();
            rs.next();
            return rs.getInt(1);
        } catch (SQLException e){
            throw e;
        } finally {
            if(rs != null){
                try{
                    rs.close();
                } catch (SQLException e){

                }
            }
            if(ps != null){
                try{
                    ps.close();
                } catch (SQLException e){

                }
            }
            if(c != null){
                try{
                    c.close();
                } catch (SQLException e){

                }
            }
        }
    }



}