package OS생산자소비자테스트;

public class Main {
    public static void main(String[] args) {
        Buffer b = new Buffer(100);
        Producer p = new Producer(b, 10000);
        Consumer c = new Consumer(b, 10000);
        p.start();
        c.start();
        try {
            p.join();
            c.join();
        } catch (InterruptedException e){
            System.out.println(b.count);
        }
    }
}
