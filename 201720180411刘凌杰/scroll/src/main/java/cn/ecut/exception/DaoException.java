package cn.ecut.exception;

/**
 * @author lujiapeng
 * @className DaoException
 * @description TODO
 * @date 2020/9/17 14:44
 **/
public class DaoException extends RuntimeException{
    public DaoException() {
        super();
    }

    public DaoException(String message) {
        super(message);
    }

    public DaoException(String message, Throwable cause) {
        super(message, cause);
    }
}
