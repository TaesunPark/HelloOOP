package Thread;

public class ExampleA {

    public static void main(String[] args) {
        // 자바의 모든 스레드는 java.lang.Thread 클래스에 의해 생성되고 제어된다.
        // 독립적인 응용 프로그램이 실행될 때, main() 메서드를 실행하기 위한 하나의 사용자 스레드 (user thread)가 자동으로 만들어지는데, 이 스레드를 주 스레드라고 부른다.
        // 1. java.lang.Runnable 인터페이스 구현하기
        // 2. java.lang.Thread 클래스를 상속받기

        RunnableThreadExample instance = new RunnableThreadExample();
        Thread thread = new Thread(instance);
        thread.start();

        while (instance.count != 5){
            try{
                Thread.sleep(250);
            }catch (InterruptedException exc){
                exc.printStackTrace();
            }
        }
    }
}
