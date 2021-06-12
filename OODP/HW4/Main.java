import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Main
{
    public static Random random = new Random();
    // make the component object
    public static Component[] list
            = { new Wheel(1), new Wheel(2),
            new Wheel(3), new Wheel(4),
            new Motor(1),  new Motor(2),
            new Motor(3),  new Motor(4),
            new Solar_panel(1, 20 + 2 * random.nextInt(4)),
            new Solar_panel(2, 20 + 2 * random.nextInt(4)),
            new Solar_panel(3, 20 + 2 * random.nextInt(4)),
            new Solar_panel(4, 20 + 2 * random.nextInt(4)),
            new Solar_panel(5, 20 + 2 * random.nextInt(4)),
            new Solar_panel(6, 20 + 2 * random.nextInt(4)),
            new Robot_arm(1), new Robot_arm(2),
            new Camera() };

    public static void main(String[] args) throws IOException {
        // Create Visitor
        EventCheck_Visitor first_visitor = new EventCheck_Visitor();
        EventHandle_Visitor second_visitor = new EventHandle_Visitor();
        Html_Visitor third_visitor = new Html_Visitor(new FileWriter("Rover_Running.html"));
        PageMaker pageMaker = new PageMaker();
        BlackBox blackBox = BlackBox.getInstance();

        // execute the each job
        System.out.println("The First Visitor for Checking Components\n");
        for (Component comp : list)
            comp.accept(first_visitor);
        System.out.println("The Second Visitor for Maintaining Components\n");
        for (Component comp : list)
            comp.accept(second_visitor);
        System.out.println("\nThe Third Visitor for Rover Movement\n");
        pageMaker.buildHtmlPage(third_visitor, list);
        System.out.println("Operation History Being Recorded in HTML file");
        System.out.println("Rover_Running.html is made");

        blackBox.printAllRecord();
    }
}
