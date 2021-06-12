import java.io.IOException;

public class PageMaker {
    public void buildHtmlPage(Html_Visitor visitor, Component[] list) throws IOException {
        visitor.title("Rover Running");
        list[0].accept(visitor);
        list[1].accept(visitor);
        list[2].accept(visitor);
        list[3].accept(visitor);
        list[4].accept(visitor);
        list[5].accept(visitor);
        list[6].accept(visitor);
        list[7].accept(visitor);
        list[8].accept(visitor);
        list[9].accept(visitor);
        list[10].accept(visitor);
        list[11].accept(visitor);
        list[12].accept(visitor);
        list[13].accept(visitor);
        list[14].accept(visitor, (Robot_arm)list[15]);
        list[16].accept(visitor);
        visitor.close();
    }
}
