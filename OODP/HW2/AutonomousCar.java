import java.util.Scanner;

public class AutonomousCar {
    public static void main(String[] args) {
        // enter the initial value for program
        System.out.println("Self Driving Car Control");
        Scanner keyboard = new Scanner(System.in);

        // enter the speed information
        System.out.println("------------------------------------------");
        System.out.print("Car Speed (60~100) : ");
        int initSpeed = keyboard.nextInt();
        System.out.print("Deviation : ");
        int speedDiv = keyboard.nextInt();
        System.out.println("  => Speed set to " + initSpeed);
        System.out.println("  => Speed Deviation set to " + speedDiv);
        System.out.println("------------------------------------------");

        // enter the temperature information
        System.out.print("Temperature (18~30) : ");
        int initTemp = keyboard.nextInt();
        System.out.print("Deviation : ");
        int tempDiv = keyboard.nextInt();
        System.out.println("  => Temperature set to " + initTemp);
        System.out.println("  => Temperature Deviation set to " + tempDiv);
        System.out.println("------------------------------------------");

        // enter the distance information
        System.out.print("Front car distance (30~100): ");
        int initDist = keyboard.nextInt();
        System.out.print("Deviation : ");
        int distDiv = keyboard.nextInt();
        System.out.println("  => Front car distance set to " + initDist);
        System.out.println("  => Front car distance Deviation set to " + distDiv);
        System.out.println("------------------------------------------");

        // create object and thread start
        Blackbox blackbox = new Blackbox(); // create the blackbox
        Thread bBoxThread = new Thread(blackbox);
        bBoxThread.setPriority(Thread.MIN_PRIORITY);
        System.out.println("Blackbox recording start.");
        Sensor sensor = new Sensor(blackbox, initSpeed, initTemp, initDist);       // create the sensor

        // run the multiple thread and set the priority
        Speed speedTh = new Speed(sensor, initSpeed, speedDiv, initDist, distDiv);
        speedTh.setPriority(Thread.NORM_PRIORITY); // set the default priority to speed
        Brake brakeTh = new Brake(sensor, initSpeed, speedDiv, initDist, distDiv);
        brakeTh.setPriority(Thread.MAX_PRIORITY); // set the max priority to brake
        Temperature tempTh = new Temperature(sensor, initTemp, tempDiv);
        tempTh.setPriority(Thread.MIN_PRIORITY); // set the min priority to temperature
        LaneCentering laneCentTh = new LaneCentering(sensor);
        laneCentTh.setPriority(Thread.MAX_PRIORITY); // set the max priority to lane centering

        // thread start
        bBoxThread.start();
        speedTh.start();
        brakeTh.start();
        tempTh.start();
        laneCentTh.start();
    }
}
