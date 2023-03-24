package 스택과_큐;

import java.util.Stack;

public class MyQueue {
    Stack<Integer> stackNewest;
    Stack<Integer> stackOldest;

    public MyQueue(){
        stackOldest = new Stack();
        stackNewest = new Stack();
    }

    public int size(){
        return stackOldest.size() + stackNewest.size();
    }

    public void add(int value){
        // 새로운 원소가 상단에 놓이도록 stackNewest에 원소를 삽입한다.
        stackNewest.push(value);
    }

    public int peek(){
        shiftStacks();
        return stackOldest.peek(); // 가장 오래된 원소를 반환한다.
    }

    // stackNewest에서 stackOldest로 원소를 옮긴다. stackOldest 연산을 수행하기 위한 작업이다.
    public void shiftStacks(){
        if (stackOldest.isEmpty()){
            while (!stackNewest.isEmpty()){
                stackOldest.push(stackNewest.pop());
            }
        }
    }

    public int pop(){
        shiftStacks(); // stackOldest에 현재 원소들이 들어 있다.
        return stackOldest.pop(); // 가장 오래된 원소를 제거한다.
    }

    public static void main(String[] args) {
        MyQueue myQueue = new MyQueue();
        myQueue.add(1);
        myQueue.add(2);
        myQueue.add(3);

        for (int i = 0; i < 3; i++){
            System.out.print(myQueue.pop() + " "); // 1. 1 2 3
        }


//        System.out.print(myQueue.pop() + " "); // 1 삭제 반환
//        System.out.print(myQueue.peek()); // 2


    }


}
