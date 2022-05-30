package 컴포넌트간의이벤트;

public class Main {
    public static void main(String[] args) {
        Person person = new Person();

        person.addHungerListener(()->{
            System.err.print("배가 고파졌습니다!\n");
            new Oven().makeFood();
        });

        // 알람 호출
        person.becomesHungry();
    }
}
