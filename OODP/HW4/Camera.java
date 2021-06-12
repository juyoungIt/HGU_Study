import java.io.IOException;
import java.util.Random;

public class Camera implements Component, Cloneable {
    private int status; // 1~10 - 3~10(good), 1~2(problem)
    private final Random random; // the random machine
    private int degree;

    public Camera() {
        this.status = 10; // initialize the status value
        this.random = new Random(); // generate random machine
        this.degree = random.nextInt(360)+1;
    }

    public int getStatus() {
        return status;
    }

    public int getDegree() {
        return degree;
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
