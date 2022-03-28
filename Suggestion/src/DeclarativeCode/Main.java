package DeclarativeCode;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<Integer> testList = new ArrayList<>();
        testList.add(1);
        testList.add(2);
        testList.add(3);
        testList.add(4);
        System.out.print(squareImperative(testList));
        System.out.print(squareDeclarative(testList));
    }

    public static List<Integer> squareImperative(final List<Integer> datum){
        var result = new ArrayList<Integer>();
        for (var i=0; i< datum.size(); i++){
            result.add(i,datum.get(i) * datum.get(i));
        }
        return result;
    }
    public static List<Integer> squareDeclarative(final List<Integer> datum){
        return datum.parallelStream()
                .map(i -> i*i)
                .collect(Collectors.toList());
    }
}
