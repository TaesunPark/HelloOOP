package 컴포넌트간의이벤트;

import java.util.ArrayList;
import java.util.List;

public class Person {

    private List<HungerListener> listeners = new ArrayList<>();

    public void addHungerListener(HungerListener listener){
        listeners.add(listener);
    }

    public HungerListener removeHungerListener(){
        return listeners.remove(listeners.size() - 1);
    }

    public void becomesHungry(){
        for (HungerListener listener: listeners){
            listener.hungry();
        }
    }

}
