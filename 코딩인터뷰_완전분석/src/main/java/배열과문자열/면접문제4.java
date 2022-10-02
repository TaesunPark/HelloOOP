package 배열과문자열;

import java.util.Arrays;
import java.util.Collections;

public class 면접문제4 {
    public static void main(String[] args) {
        System.out.print(Character.getNumericValue('a'));
        System.out.print(isPermutationOfPalindrome("tact co"));
    }

    public static boolean isPermutationOfPalindrome(String phrase){
        int[] table = buildCharFrequencyTable(phrase);
        return checkMaxOneOdd(table);
    }

    public static boolean checkMaxOneOdd(int[] table){
        boolean foundOdd = false;
        for (int count : table){
            if (count % 2 == 1){
                if (foundOdd){
                    return false;
                }
                foundOdd = true;
            }
        }
        return true;
    }
    public static int[] buildCharFrequencyTable(String phrase){
        int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
        for (char c : phrase.toCharArray()){
            int x = getCharNumber(c);
            if (x != -1){
                table[x]++;
            }
        }
        return table;
    }


    // 각 문자에 숫자를 대응시킨다.
    public static int getCharNumber(Character c){
        int a = Character.getNumericValue('a');
        int z = Character.getNumericValue('z');
        int val = Character.getNumericValue(c);
        if (a <= val && val <= z) return val - a;
        return -1;
    }

}
