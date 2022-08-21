package 배열과문자열;

import java.util.Arrays;

public class 면접문제2 {
    // 문제 : 문자열 두 개가 서로 순열관계인 지?
    public static void main(String[] args) {
        System.out.print(풀이());
    }

    public static boolean 풀이(){
        String str1 = "abcde";
        String str2 = "bcdea";
        String value1 = "";
        String value2 = "";
        char[] charList1 = str1.toCharArray();
        char[] charList2 = str2.toCharArray();

        // 1. 문자열에 공백이 들어가있는 지, 2. 대소문자를 구분을 해야하는 지
        // 나는 ASKII로 가정하고, 공백은 없고, 대소문자를 구분하지 않는다는 가정하에 짜겠습니다.
        // 풀이 1. str1, str2를 오름차순 정렬해서 문자열이 같은 지 확인한다.

        Arrays.sort(charList1);
        Arrays.sort(charList2);

        for (int i=0; i<charList1.length; i++){
            value1 += charList1[i];
        }

        for (int i=0; i<charList2.length; i++){
            value2 += charList2[i];
        }

        if (value1.equals(value2)) return true;
        else return false;
    }
}
