package 배열과문자열;

public class 면접문제3 {
    public static void main(String[] args) {
        // URL화 문자열에 들어 있는 모든 공백을 '%20' 으로 바꿔 주는 메서드를 작성하라.
        System.out.print(문제3());
    }

    public static String 문제3() {
        String str = "Mr John Smith";
        String result = "";
        int spaceSize = 0;

        for (int i=0; i<str.length(); i++){
            if (str.charAt(i) == ' ') spaceSize++;
        }

        char[] newArray = new char[str.length() + spaceSize*2];

        for (int i=str.length()-1, size = newArray.length-1;i>=0; i--){
            if (str.charAt(i) == ' '){
                newArray[size] = '0';
                newArray[size-1] = '2';
                newArray[size-2] = '%';
                size = size-3;
            } else{
                newArray[size] = str.charAt(i);
                size--;
            }
        }

        for (int i=0; i<newArray.length; i++){
            result += newArray[i];
        }
        
        return result;
    }
}
