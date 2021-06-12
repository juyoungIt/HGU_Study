import java.io.IOException;
import java.util.Random;

public class Robot_arm implements Component, Cloneable {
    private int location; // 1 : front, 2 : lear
    private int status; // 1~10 - 3~10(good), 1~2(problem)
    private final Random random; // the random machine
    private int calibration;

    public Robot_arm(int location) {
        this.location = location;
        this.status = 10; // initialize the status value
        this.random = new Random(); // generate random machine
        this.calibration = random.nextInt(2);
    }

    public Object clone() {
        Object clone = null;
        try {
            clone = super.clone();
        }
        catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return clone;
    }

    public String getLocation() {
        if(location == 1)
            return "Front";
        else // location == 2
            return "Rear";
    }

    public int getLocationCode() {
        return location;
    }

    public int getCalibration() {
        return calibration;
    }

    public void setStatus(int statue) {
        this.status = status;
    }

    public int getStatus() {
        return status;
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
    public void accept(Html_Visitor v, Robot_arm c) throws IOException {
        v.visit(this, c);
    }
}
