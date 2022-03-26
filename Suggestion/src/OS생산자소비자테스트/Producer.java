package OS생산자소비자테스트;

public class Producer extends Thread{
    Buffer b;
    int N;
    Producer(Buffer b, int N){
        this.b = b;
        this.N = N;
    }

    public synchronized void run(){
        for (int i=0; i<N; i++){
            b.insert(i);
            System.out.println("Producer cnt = "+i);
        }
    }

}
