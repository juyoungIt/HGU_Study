import javax.swing.text.html.HTMLWriter;
import java.io.Writer;
import java.io.IOException;

public class Html_Visitor implements Html_Visitor_Interface {

    private Writer writer;

    public Html_Visitor(Writer writer) {
        this.writer = writer;
    }

    public void title(String title) throws IOException {
        writer.write("<html>\n");
        writer.write("<head>\n");
        writer.write("<title>" + title + "</title>\n");
        writer.write("</head>\n");
        writer.write("<body>\n");
        writer.write("<h1>" + title + "</h1>\n");
    }

    public void visit(Wheel c) throws IOException {
        String event_message1 = "Enlarge " + c.getLocation() + " Wheel Thread";
        String event_message2 = "Widen " + c.getLocation() + " Wheel Width";
        String event_message3 = "Extrude Spike from " + c.getLocation() + " Wheel Shoe";

        String event_message;

        if(c.getType().equals("Pebble Ground"))
            event_message = event_message1;
        else if(c.getType().equals("Mushy Ground"))
            event_message = event_message2;
        else // c.getType().equals("Slippery Ground")
            event_message = event_message3;

        if(c.getLocation().equals("Front Left"))
            writer.write("<p>Each Wheel Turns Adapting to Terrain State</p>\n");

        writer.write("<ul>\n");
        writer.write("<li>" + "Turning" + c.getLocation() + " wheel</li>\n");
        writer.write("<li>" + c.getType() + " --> " + event_message + "</li>\n");
        writer.write("</ul>\n");
    }

    public void visit(Motor c) throws IOException {
        String event_message1 = "Decrease Power to " + c.getLocation() + " Motor";
        String event_message2 = "Increase Power to " + c.getLocation() + " Motor";
        String event_message3 = "Keep the Same Power to " + c.getLocation() + "Motor";

        String event_message;

        if(c.getRPMStatus().equals("RPM Increased"))
            event_message = event_message1;
        else if(c.getRPMStatus().equals("RPM Decreased"))
            event_message = event_message2;
        else // c.getRPMStatus().equals("Constant RPM")
            event_message = event_message3;

        if(c.getLocation().equals("Front Left"))
            writer.write("<p>Each Motor Controls Power Consumption</p>\n");

        writer.write("<ul>\n");
        writer.write("<li>" + "Control of " + c.getLocation() + " Motor</li>\n");
        writer.write("<li>" + c.getRPMStatus() + " --> " + event_message + "</li>\n");
        writer.write("</ul>\n");
    }

    public void visit(Solar_panel c) throws IOException {
        String event_message = "Solar Panel " + c.getNumber() + " Generating Electricity...";

        if(c.getNumber() == 1)
            writer.write("<p>Solar Panel Generating Electricity</p>\n");

        writer.write("<ul>\n");
        writer.write("<li>" + event_message + "</li>\n");
        writer.write("<li> Charging " + c.getElectricity() + " KW </li>\n");
        writer.write("</ul>\n");
    }

    public void visit(Robot_arm c1, Robot_arm c2) throws IOException {
        String event_message1 = " Robot Arm in Fine Calibration";
        String event_message2 = "Both Front and Rear Robot Arms in Fine Calibration";
        String event_message3 = "Robot Arm in Complete Calibration";

        String event_message;

        if(c1.getCalibration() == 1 && c2.getCalibration() == 1)
            event_message = event_message2;
        else if(c1.getCalibration() == 1 && c2.getCalibration() != 1)
            event_message = c1.getLocation() + event_message1;
        else if(c1.getCalibration() != 1 && c2.getCalibration() == 1)
            event_message = c2.getLocation() + event_message1;
        else
            event_message = event_message3;

        writer.write("<p>Robot Arm in Operation</p>\n");
        writer.write("<ul>\n");
        writer.write("<li>" + event_message + "</li>\n");
        writer.write("</ul>\n");
    }

    public void visit(Robot_arm c1) throws IOException { }

    public void visit(Camera c) throws IOException {
        writer.write("<p>Camera in Operation</p>\n");
        writer.write("<ul>\n");
        writer.write("<li> Camera Taking Pictures of " + c.getDegree() + " degrees View</li>\n");
        writer.write("</ul>\n");
    }

    public void visit(BlackBox c) {

    }

    public void close() throws IOException {
        writer.write("</body>\n");
        writer.write("</html>\n");
        writer.close();
    }
}
