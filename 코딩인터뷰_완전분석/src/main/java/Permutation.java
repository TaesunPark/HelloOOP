public class Permutation {

    public static void main(String[] args) {
        permutation("가나다");
    }

    public static void permutation(String str){
        permutation(str, "");
    }

    //순열을 완성이 됐을 때 permutation 함수는 n! 번 호출
    //순열이 완성되기 전에 permutation 함수는 n번 호출
    //문자열 출력하는 데 O(N)
    //전체 시간복잡도 O(n!*n^2)
    public static void permutation(String str, String prefix){
        if(str.length() == 0){
            System.out.println(prefix);
        } else{
            for (int i = 0; i < str.length(); i++){
                String rem = str.substring(0, i) + str.substring(i+1);
                permutation(rem, prefix + str.charAt(i));
            }
        }
    }
}
