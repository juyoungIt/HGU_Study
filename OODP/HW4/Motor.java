import java.io.IOException;
import java.util.Random;

public class Motor implements Component, Cloneable {
    private int location; // 1 : fl, 2 : fr, 3 : bl, 4 : br
    private int status; // 1~10 - 3~10(good), 1~2(problem)
    private int rpm_status; // 1 : increased, 2 : decreased, 3: constant
    private final Random random; // the random machine

    public Motor(int location) {
        this.location = location;
        this.status = 10; // initialize the status value
        this.random = new Random(); // generate random machine
        this.rpm_status = random.nextInt(2)+1;
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

    public int getLocationCode() {
        return location;
    }

    public String getRPMStatus() {
        if(rpm_status == 1)
            return "RPM Increased";
        else if(rpm_status == 2)
            return "RPM Decreased";
        else // rpm_status == 3
            return "Constant RPM";
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

    public void accept(Html_Visitor v, Robot_arm c) throws IOException { }
}
