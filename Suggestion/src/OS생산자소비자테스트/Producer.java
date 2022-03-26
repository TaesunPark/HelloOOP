package OS생산자소비자테스트;

public class Producer extends Thread{
    Buffer b;
    int N;
    Producer(Buffer b, int N){
        this.b = b;
        this.N = N;
    }

    public void run(){
        for (int i=0; i<N; i++){
            System.out.println("producer cnt = "+i);
            b.insert(i);
        }
    }

}
