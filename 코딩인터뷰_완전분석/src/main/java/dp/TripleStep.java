package dp;

import java.util.HashMap;
import java.util.LinkedHashMap;

public class TripleStep {
    static int n;

    public static void main(String[] args) {
        n = 5;
        System.out.print(tripleStap(n));
    }

    public static int tripleStap(int depth){
        HashMap<Integer, Integer> hashMap = new LinkedHashMap<>();
        return tripleStap(depth, hashMap);
    }

    public static int tripleStap(int depth, HashMap<Integer, Integer> h){
        if (h.containsKey(depth)){
            return h.get(depth);
        }

        int ways;

        if (depth < 0){
            return 0;
        }

        if (depth == 0){
            ways = 1;
        } else{
            ways = tripleStap(depth - 1, h) + tripleStap(depth - 2, h) + tripleStap( depth - 3, h);
        }
        h.put(n, ways);
        return ways;
    }
}
