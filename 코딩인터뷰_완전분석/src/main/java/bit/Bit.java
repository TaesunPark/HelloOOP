package bit;

public class Bit {
    public static void main(String[] args) {
        // 아스키 코드는 8진법
        System.out.println(getBit(0100, 6));
        // 8진법 -> 2진법
        System.out.println(setBit(0100, 4));
    }

    // 비트값 채워넣기
    public static boolean getBit(int num, int i){
        return ((num & (1 << i)) != 0);
    }

    // 비트값 확인
    public static int setBit(int num, int i){
        return num | (1 << i);
    }

}
