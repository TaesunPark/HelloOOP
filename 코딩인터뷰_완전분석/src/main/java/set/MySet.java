package set;

import java.util.HashSet;
import java.util.Set;

public class MySet {
    public static void main(String[] args) {
        Set<String> hash_Set = new HashSet<String>();

        hash_Set.add("박태순");
        hash_Set.add("정상벽");
        hash_Set.add("김채운");
        hash_Set.add("박윤경");
        hash_Set.add("손모은");
        hash_Set.add("이윤환");

        System.out.println(hash_Set);
    }
}
