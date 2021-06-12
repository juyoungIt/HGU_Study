import java.io.IOException;

public interface Component {
    public abstract void accept(EventCheck_Visitor v);
    public abstract void accept(EventHandle_Visitor v);
    public abstract void accept(Html_Visitor v) throws IOException;
    public abstract void accept(Html_Visitor v, Robot_arm c) throws IOException;
}
