// use the flyweight pattern here...

import java.io.IOException;
import java.util.Random;
import java.util.Map;
import java.util.HashMap;

public class Solar_panel implements Component, Cloneable {
    private int number;          // 1 to 6 - given to parameter
    private int capacity;        // 20, 22, 24, 26 is available
    private double electricity;     // the value of generating electricity
    private final Random random; // the random machine

    public Solar_panel(int number, int capacity) {
        this.number = number;
        this.random = new Random(); // generate random machine
        this.capacity = capacity;
        this.electricity = this.capacity;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public double getElectricity() {
        return electricity;
    }

    public int getCapacity() {
        return capacity;
    }

    public void generate_electricity() {
        this.electricity = this.capacity * ((this.random.nextInt(100)+1) / 100.0);
    }

    public void accept(EventCheck_Visitor v) {
        v.visit(this);
    }

    public void accept(EventHandle_Visitor v) {
        v.visit(this);
    }

    public void accept(Html_Visitor v) throws IOException {
        v.visit(this);
    }

    public void accept(Html_Visitor v, Robot_arm c) throws IOException { }
}
