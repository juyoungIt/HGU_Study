import java.io.IOException;
import java.util.ArrayList;

public class BlackBox implements Component, Cloneable {
    private int num_of_record; // the number of record
    private static BlackBox blackBox = new BlackBox();
    private ArrayList<String> history;

    // constructor
    private BlackBox(){
        history = new ArrayList<String>(); // generate storage list
    }

    // return the instance of Blackbox
    public static BlackBox getInstance() {
        return blackBox;
    }

    public void add_data(String code) {
        history.add(code);
    }

    public void clear_data() {
        history.clear();
    }

    public String encoder1(char c) {
        if(c == '0')
            return "Alarm";
        else
            return "Action";
    }

    public String encoder2(char c0, char c1, char c2) {
        if(encoder1(c0).equals("Alarm")) {
            if(c1 == '0') // wheel
                return "Mud and Dust on Wheel Axle of " + encoder3(c2) + "wheel";
            else if(c1 == '1') // motor
                return "Weak Power to " + encoder3(c2) + " Motor";
            else if(c1 == '2') // solar panel
                return "Low Electricity Generated to Solar Panel " + c2;
            else if(c1 == '3')
                return encoder4(c2) + " Robot Arm Not Working Properly";
            else // c1 == 4
                return "Camera Not Working Properly";
        }
        else { // encoder1(c0).equals("Action")
            if(c1 == '0') // wheel
                return "Removing Mud/Dust from " + encoder3(c2) + " Axle";
            else if(c1 == '1') // motor
                return "Supply more power to " + encoder3(c2) + " Motor";
            else if(c1 == '2') // solar panel
                return "Replacing Solar Panel " + c2;
            else if(c1 == '3')
                return encoder4(c2) + " Robot Arm Replaced by Prototype " + encoder4(c2) + " Arm Clone";
            else // c1 == 4
                return "Repair Camera";
        }
    }

    public String encoder3(char c) {
        if(c == '1')
            return "Front Left";
        else if(c == '2')
            return "Front Right";
        else if(c == '3')
            return "Back Left";
        else // c == 4
            return "Back Right";
    }

    public String encoder4(char c) {
        if(c == '1')
            return "Front";
        else // c == 2
            return "Rear";
    }

    public void printAllRecord() {
        System.out.println("\n+++Major Checking and Action from Blackbox+++");

        for(int i=0 ; i< history.size() ; i++) {
            String type = encoder1(history.get(i).charAt(0));
            String statement = encoder2(history.get(i).charAt(0), history.get(i).charAt(1), history.get(i).charAt(2));
            System.out.println(i+1 + ": " + type + ": " + statement);
        }

        System.out.println("+++Blackbox Displayed Finished +++");
    }

    public void accept(EventCheck_Visitor v) {
        v.visit(this, "null");
    }

    public void accept(EventHandle_Visitor v) {
        v.visit(this, "null");
    }

    public void accept(Html_Visitor v) {
        v.visit(this);
    }

    public void accept(Html_Visitor v, Robot_arm c) throws IOException { }
}
