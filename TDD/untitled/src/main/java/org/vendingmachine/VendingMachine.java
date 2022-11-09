package org.vendingmachine;

public class VendingMachine {
    private int changes;

    public VendingMachine(){
        this(0);
    }

    public VendingMachine(final int changes){
        this.changes = changes;
    }

    public void put(final int changes){
        this.changes += changes;
    }

    public int getChanges(){
        return changes;
    }


}
