import java.io.IOException;
import java.util.Random;

public class Wheel implements Component, Cloneable {
    private int location;        // 1 : fl, 2 : fr, 3 : bl, 4 : br
    private int type;            // 1 - pebble, 2 - Mushy 3 - slippery
    private int status;          // 1~10 - 3~10(good), 1~2(problem)
    private final Random random; // the random machine

    // constructor
    public Wheel(int location) {
        this.location = location;
        this.status = 10; // initialize the status value
        this.random = new Random(); // generate random machine
        this.type = random.nextInt(3)+1;
    }

    public String getLocation() {
        if(location == 1)
            return "Front Left";
        else if(location == 2)
            return "Front Right";
        else if(location == 3)
            return "Back Left";
        else // location == 4
            return "Back Right";
    }

    public String getType() {
        if(this.type == 1)
            return "Pebble Ground";
        else if(this.type == 2)
            return "Mushy Ground";
        else // this.type == 3
            return "Slippery Ground";
    }

    public int getStatus() {
        return status;
    }

    public int getLocationCode() {
        return location;
    }

    public void update_status() {
        this.status = this.random.nextInt(11);
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
