import java.io.IOException;

public interface Html_Visitor_Interface {
    public abstract void visit(BlackBox c);
    public abstract void visit(Camera c) throws IOException;
    public abstract void visit(Motor c) throws IOException;
    public abstract void visit(Wheel c) throws IOException;
    public abstract void visit(Robot_arm c1, Robot_arm c2) throws IOException;
    public abstract void visit(Solar_panel c) throws IOException;
}
