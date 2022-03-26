package OS생산자소비자테스트;

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
        while (count == size);
        buf[in] = item;
        in = (in + 1) % size;
        count++;
    }

    int remove(){
       while (count == 0);
       int item = buf[out];
       out = (out+1) % size;
       count--;
       return item;
    }
}
