package springboot.dao;

import java.sql.Connection;
import java.sql.SQLException;

// 약속
public interface ConnectionMaker {
    public Connection makeConnection() throws ClassNotFoundException, SQLException;
}
