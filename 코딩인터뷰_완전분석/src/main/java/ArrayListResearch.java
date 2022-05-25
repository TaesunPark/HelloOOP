import java.util.ArrayList;
import java.util.stream.Collectors;

public class ArrayListResearch {
    static long startTime;
    static long endTime;
    static final int initialCapacity = 5;
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>(initialCapacity);

        for (int i=1; i<40; i++){
            startTime = System.nanoTime();
            list.add(i);
            endTime = System.nanoTime();
            System.out.print(endTime-startTime+"시간 소요 /"+i + "저장" + "\n");
        }

    }
}
