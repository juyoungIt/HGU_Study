import com.sun.jdi.event.EventIterator;

public class EventCheck_Visitor implements Visitor {
    private static BlackBox blackBox = BlackBox.getInstance();

    public void visit(Wheel c) {
        String normal_message = "Wheel Axle OK";
        String event_message = ">> Alarm: Mud and Dust on Wheel Axle of ";
        String backup_message; // to blackbox

        if(c.getLocation().equals("Front Left"))
            System.out.println("\n *** Start Checking Wheel ***\n ");

        c.update_status();

        System.out.println("Checking " + c.getLocation() + " Axel");
        if(c.getStatus() <= 2) {
            System.out.println(event_message + c.getLocation() + " wheel");
            backup_message = "0" + "0" + c.getLocationCode();
            visit(blackBox, backup_message);
        }
        else
            System.out.println(normal_message);
    }

    public void visit(Motor c) {
        String normal_message = "Power is OK";
        String event_message = ">>>> Alarm: Weak Power to ";
        String backup_message;

        if(c.getLocation().equals("Front Left"))
            System.out.println("\n ### Start Checking Motor ###\n ");

        c.update_status();

        System.out.println("Checking " + c.getLocation() + " Motor");
        if(c.getStatus() <= 2) {
            System.out.println(event_message + c.getLocation() + " Motor");
            backup_message = "0" + "1" + c.getLocationCode();
            visit(blackBox, backup_message);
        }

        else
            System.out.println(normal_message);
    }

    public void visit(Solar_panel c) {
        String normal_message = "Solar Panel is OK";
        String event_message = ">>>> Alarm: Low Electricity Generated to Solar Panel ";
        String backup_message;

        if(c.getNumber() == 1)
            System.out.println("\n !!! Start Checking Solar Panel !!!\n ");

        c.generate_electricity();

        System.out.println("Checking Solar Panel " + c.getNumber());
        if(c.getElectricity() <= c.getCapacity() * 0.2) {
            System.out.println(event_message + c.getNumber());
            backup_message = "0" + "2" + c.getNumber();
            visit(blackBox, backup_message);
        }
        else
            System.out.println(normal_message);
    }

    public void visit(Robot_arm c) {
        String event_message1 = ".. Alarm: ";
        String event_message2 = " Robot Arm Not Working Properly";
        String backup_message;

        if(c.getLocation().equals("Front"))
            System.out.println("\n ... Start Checking Robot Arm ...");

        c.update_status();

        System.out.println("Checking robot arm");
        if(c.getStatus() <= 2) {
            System.out.println(event_message1 + c.getLocation() + event_message2);
            backup_message = "0" + "3" + c.getLocationCode();
            visit(blackBox, backup_message);
        }
    }

    public void visit(Camera c) {
        String event_message = ".. Alarm: Robot Not Working Properly";
        String backup_message;

        c.update_status();

        System.out.println("\n ... Start Checking Camera ...");
        System.out.println("Checking camera");
        if(c.getStatus() <= 2) {
            System.out.println(event_message);
            backup_message = "0" + "1" + "0";
            visit(blackBox, backup_message);
        }
    }

    public void visit(BlackBox c, String number_code) {
        c.add_data(number_code);
    }
}
