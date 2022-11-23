package springboot.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


// 리스트 1-7 독립시킨 DB 연결 기능인 SimpleConnectionMaker
public class SimpleConnectionMaker {
    public Connection makeNewConnection() throws ClassNotFoundException,
            SQLException{
    Class.forName("com.mysql.jdbc.Driver");
    Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3307/spring?characterEncoding=UTF-8", "root",
            "12345678");
        return c;
    }

}
