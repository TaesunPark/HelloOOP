package OS생산자소비자테스트;

public class Consumer extends Thread{
    Buffer b;
    int N;

    Consumer(Buffer b, int N){
        this.b = b;
        this.N = N;
    }

    public void run(){
        int item;
        for (int i=0; i<N; i++){
            System.out.println("Consumer cnt = "+i);
            item = b.remove();
        }
    }

}
