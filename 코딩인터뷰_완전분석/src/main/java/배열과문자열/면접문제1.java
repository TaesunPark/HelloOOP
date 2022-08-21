public class 면접문제1 {
    public static void main(String[] args) {
        System.out.print(풀이());
    }

    // 문자열이 주어졌을 때, 이 문자열에 같은 문자가 중복되어 등장하는지 확인하는 알고리즘을 작성하라.
    public static boolean 풀이(){
        String str = "abcdefg";
        // 만약 문자열이 아스키 코드일 경우
        boolean[] checkedList = new boolean[128];

        for (int i=0; i<str.length();i++){
            if (checkedList[str.charAt(i)]){
                return false;
            } else {
                checkedList[str.charAt(i)] = true;
            }
        }
        return true;
    }

}
