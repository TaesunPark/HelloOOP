package 스택과_큐;

import java.util.EmptyStackException;

public class FixedMultiStack {
    private int numberOfStacks = 3;
    private int stackCapacity;
    private int[] values;
    private int[] sizes;

    public FixedMultiStack(int stackSize){
        stackCapacity = stackSize;
        values = new int[stackSize * numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    /* 스택에 값을 추가한다. */
    public void push(int stackNum, int value){
        /* 여유 공간이 있는지 검사한다. */
        if (isFull(stackNum)){
            throw new FullStackException();
            // 예외 던지기
        }
        /* 스택 포인터를 증가시키고 가장 꼭대기 값을 갱신한다. */
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
    }

    public int pop(int stackNum){
        if (isEmpty(stackNum)){
            throw new EmptyStackException();
        }

        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex]; // 가장 꼭대기 값을 꺼낸다.
        values[topIndex] = 0; // 꼭대기 값을 지운다.
        sizes[stackNum]--; // 스택의 크기를 줄인다.
        return value;
    }

    // 꼭대기 원소 반환
    public int peek(int stackNum){
        if (isEmpty(stackNum)){
            throw new EmptyStackException();
        }
        return values[indexOfTop(stackNum)];
    }

    public boolean isEmpty(int stackNum){
        return sizes[stackNum] == 0;
    }

    /* 스택이 꽉 차 있으면 true를 반환한다. */
    public boolean isFull(int stackNum){
        return sizes[stackNum] == stackCapacity;
    }

    private int indexOfTop(int stackNum){
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }

    public static void main(String[] args) {
        // 배열 하나로 스택 3개 구현
        FixedMultiStack fixedMultiStack = new FixedMultiStack(10);
        // 0번 스택에 3개 값 넣기
        fixedMultiStack.push(0, 111);
        fixedMultiStack.push(0, 112);
        fixedMultiStack.push(0, 113);
        // 1번 스택에 3개 값 넣기
        fixedMultiStack.push(1, 221);
        fixedMultiStack.push(1, 222);
        fixedMultiStack.push(1, 223);
        // 2번 스택에 3개 값 넣기
        fixedMultiStack.push(2, 331);
        fixedMultiStack.push(2, 332);
        fixedMultiStack.push(2, 333);


        System.out.println(fixedMultiStack.pop(0));
        System.out.println(fixedMultiStack.pop(1));
        System.out.println(fixedMultiStack.pop(2));

        System.out.println(fixedMultiStack.pop(0));
        System.out.println(fixedMultiStack.pop(1));
        System.out.println(fixedMultiStack.pop(2));

        System.out.println(fixedMultiStack.pop(0));
        System.out.println(fixedMultiStack.pop(1));
        System.out.println(fixedMultiStack.pop(2));
    }
}
