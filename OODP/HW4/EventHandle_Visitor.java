public class EventHandle_Visitor implements Visitor {

    private static BlackBox blackBox = BlackBox.getInstance();

    public void visit(Wheel c) {
        String noEvent_message = "No Action on ";
        String event_message = "--> Action: Removing Mud/Dust from ";
        String backup_message;

        if(c.getLocation().equals("Front Left"))
            System.out.println("\n*** Start Working on Wheel ***");

        System.out.println("Acting on " + c.getLocation() + " Axle");
        if(c.getStatus() <= 2) {
            System.out.println(event_message + c.getLocation() + " Axle");
            backup_message = "1" + "0" + c.getLocationCode();
            visit(blackBox, backup_message);
        }
        else
            System.out.println(noEvent_message + c.getLocation());
    }

    public void visit(Motor c) {
        String noEvent_message = "No Action on ";
        String event_message = "==> Action: Supply more power to ";
        String backup_message;

        if(c.getLocation().equals("Front Left"))
            System.out.println("\n### Start Working on Motor ###");

        System.out.println("Acting on " + c.getLocation() + " Motor");
        if(c.getStatus() <= 2) {
            System.out.println(event_message + c.getLocation() + " Motor");
            backup_message = "1" + "1" + c.getLocationCode();
            visit(blackBox, backup_message);
        }
        else
            System.out.println(noEvent_message + c.getLocation());
    }

    public void visit(Solar_panel c) {
        String normal_message = "No Action on Solar Panel ";
        String event_message = "==> Action: repairing Solar Panel ";
        String backup_message;

        if(c.getNumber() == 1)
            System.out.println("\n!!! Start Working on Solar Panel !!!");

        System.out.println("Acting on Solar Panel " + c.getNumber());
        if(c.getElectricity() <= c.getCapacity() * 0.2) {
            System.out.println(event_message + c.getNumber());
            Panel_storage storage = Panel_storage.getInstance(); // get the instance of panel storage
            Solar_panel newPanel = storage.lookup(c.getCapacity()); // get the new solar panel
            newPanel.setNumber(c.getNumber());
            c = newPanel;
            System.out.println("A Troublesome Panel Replaced by " + c.getCapacity() + " KW Panel");
            backup_message = "1" + "2" + c.getNumber();
            visit(blackBox, backup_message);
        }
        else
            System.out.println(normal_message + c.getNumber());
    }

    public void visit(Robot_arm c) {
        String event_message1 = "==> Action: ";
        String event_message2 = " Robot Arm Replaced by Prototype ";
        String event_message3 = " Robot Arm Clone Made from Prototype";
        String backup_message;

        if(c.getLocation().equals("Front")) {
            System.out.println("\n... Start Working on RobotArm ...");
            System.out.println("Action on RobotArm");
        }

        if(c.getStatus() <= 2) {
            Robot_arm newArm = (Robot_arm)c.clone(); // clone the new arm
            newArm.setStatus(10); // set the new arm
            c = newArm; // replace the arm
            System.out.println(event_message1 + c.getLocation() + event_message2
                    + c.getLocation() + " Arm Clone " + c.getLocation() + event_message3);
            backup_message = "1" + "3" + c.getLocationCode();
            visit(blackBox, backup_message);
        }
    }

    public void visit(Camera c) {
        String event_message = "==> Action: Repair Camera";
        String backup_message;

        System.out.println("\n... Start Working on Camera ...");
        System.out.println("Action on Camera");
        if(c.getStatus() <= 2) {
            System.out.println(event_message);
            backup_message = "1" + "4" + "0";
            visit(blackBox, backup_message);
        }
    }

    public void visit(BlackBox c, String number_code) {
        c.add_data(number_code);
    }
}
