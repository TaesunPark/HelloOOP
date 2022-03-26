package OS생산자소비자테스트;

import java.util.concurrent.Semaphore;

public class Buffer {
    int[] buf;
    int size;
    int count;
    int in;
    int out;

    Buffer(int size){
        buf = new int[size];
        this.size = size;
        count = in = out = 0;
    }

    void insert(int item){
        while (count == size){
            System.out.println("insert 무한루프");
        }
        buf[in] = item;
        in = (in + 1) % size;
        count++;
    }

    int remove(){
       while (count == 0){
           System.out.println("remove 무한루프");
       }
       int item = buf[out];
       out = (out+1) % size;
       count--;
       return item;
    }
}
