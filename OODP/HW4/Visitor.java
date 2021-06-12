import java.io.IOException;

public interface Visitor {
    public abstract void visit(BlackBox c, String number_code);
    public abstract void visit(Camera c) throws IOException;
    public abstract void visit(Motor c) throws IOException;
    public abstract void visit(Wheel c) throws IOException;
    public abstract void visit(Robot_arm c) throws IOException;
    public abstract void visit(Solar_panel c) throws IOException;
}
