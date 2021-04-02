import java.util.Random;

public class Sensor {
    private final Blackbox blackBox; // blackbox
    private int curSpeed;      // current speed
    private int temp;          // current temperature
    private int distFront;     // the distance from Front car
    private boolean centered;  // the line centering
    private boolean redLight;  // the led traffic Light
    private boolean ped;       // the pedestrian approach
    private boolean animal;    // the animal approach
    private final Random random;     // random machine for event generator

    // constructor
    // initiation each sensor data
    public Sensor(Blackbox blackBox, int initSpeed, int initTemp, int initDist) {
        this.blackBox = blackBox;
        this.curSpeed = initSpeed;
        this.temp = initTemp;
        this.distFront = initDist;
        this.centered = true;  // initial state = centered
        this.redLight = false; // redLight state = false
        this.ped = false;      // pedestrian state = false
        this.animal = false;   // animal state = false
        this.random = new Random(); // create random machine
    }

    // setter
    // the event generator - by random generator
    public void updateSpeed() { this.curSpeed = this.random.nextInt(30) + 60; }
    public void updateTemp() { this.temp = this.random.nextInt(12) + 18; }
    public void updateDist() { this.distFront = this.random.nextInt(70) + 30; }
    public void updateCent() { this.centered = (this.random.nextInt(2) == 1) ? true : false; }
    public void updateRedLight() { this.redLight = (this.random.nextInt(2) == 1) ? true : false; }
    public void updatePed() { this.ped = (this.random.nextInt(2) == 1) ? true : false; }
    public void updateAnimal() { this.animal = (this.random.nextInt(2) == 1) ? true : false; }

    // getter
    public int getCurSpeed() { return this.curSpeed; }
    public int getTemp() { return this.temp; }
    public int getDistFront() { return this.distFront; }
    public boolean getCentered() { return this.centered; }
    public boolean getRedLight() { return this.redLight; }
    public boolean getPed() { return this.ped; }
    public boolean getAnimal() { return this.animal; }

    // Other feature
    // the event about speedup
    synchronized public void speedEvent(int init) {
        // wait();
        System.out.println("  => Push Accelerator");
        this.curSpeed = init;
    }

    // the event about speed down
    synchronized public void brakeEvent(int init) {
        System.out.println("  => Push brake");
        this.curSpeed = init;
    }

    // the event about line centering
    synchronized public void laneEvent() {
        blackBox.setCentEvent(); // set data
        System.out.println("Event Generated — Not in Lane Center");
        System.out.println("Not in Lane Center ...");
        System.out.println("Correcting Car Position on Lane Center ...");
        this.centered = true; // adjust the lane center.
    }

    // the event about temperature - 1
    synchronized public void hotEvent(int init) {
        blackBox.setAirconEvent(); // set data
        System.out.println("Thread for Air Conditioner Control, current Temperature : " + temp);
        System.out.println("Turn on the aircon to lower temperature");
        this.temp = init;
    }

    // the event about temperature - 2
    synchronized public void coldEvent(int init) {
        blackBox.setHeatEvent(); // set data
        System.out.println("Thread for Air Conditioner Control, current Temperature : " + temp);
        System.out.println("Turn on the heater to increase temperature");
        this.temp = init;
    }

    // the event about adaptive distance - 1
    synchronized public void farDistEvent(int init) {
        blackBox.setDistEvent(); // set data
        System.out.println("Event Generated — Distance Getting Far from the Front Car");
        System.out.println("the Speed of Front Car Increasing Fast: speed up to keep distance...");
        speedEvent(curSpeed + random.nextInt(10)+30);
        System.out.println("Current Increased Speed for Distance from the Car Ahead : " + curSpeed);
    }

    // the event about adaptive distance - 2
    synchronized public void closeDistEvent(int init) {
        blackBox.setDistEvent(); // set data
        System.out.println("Event Generated — Distance Getting Closer from the Front Car");
        System.out.println("the Speed of Front Car Dropping Fast: slow down to keep distance...");
        brakeEvent(curSpeed - random.nextInt(10)+30);
        System.out.println("Current Decreased Speed for Distance from the Car Ahead : " + curSpeed);
    }

    // the event for pedestrian
    synchronized public void pedestEvent() {
        blackBox.setPedestEvent(); // set data
        System.out.println("Event Generated -- Pedestrian");
        System.out.println("Pedestrian Crossing the Road: slow down to stop!");
        System.out.println("Current Decreased Speed while a Pedestrian Crossing: " + curSpeed);
        brakeEvent(0); // stop
        System.out.println("Now the car made a full stop for pedestrians.");
        System.out.println("Now the Pedestrian in Safe Area and the Road Cleared");
        speedEvent(curSpeed+ random.nextInt(10)+30); // accelerate
        System.out.println("Current Increased Speed after Passing a Pedestrian in Safe Area: " + curSpeed);
    }

    // the event for animal
    synchronized public void animalEvent() {
        blackBox.setAnimalEvent();
        System.out.println("Event Generated — Animal");
        System.out.println("Animal Crossing Sensed: slow down ...!");
        brakeEvent(curSpeed - random.nextInt(20)+30);
        System.out.println("Current Decreased Speed in front of an Animal: " + curSpeed);
        System.out.println("Road Cleared of Animal: Increase Speed");
        speedEvent(curSpeed + random.nextInt(20)+30);
        System.out.println("Current Increased Speed after Passing an Animal: " + curSpeed);
    }

    // the event about red traffic right
    synchronized public void redLightEvent() {
        blackBox.setRLightEvent();
        System.out.println("Event Generated — Red Traffic Light");
        System.out.println("Red Traffic Light Sensed...");
        System.out.println("Slowing down speed to stop at red light...");
        System.out.println("Current Decreased Speed in Front of Red Light : " + curSpeed);
        brakeEvent(0); // stop
        System.out.println("Now the car made a complete stop.");
        System.out.println("Now Green Light Turned on");
        speedEvent(curSpeed + random.nextInt(10)+30);
        System.out.println("Current Increased Speed on Green Traffic Light : " + curSpeed);
    }
}