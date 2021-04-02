// Blackbox.java
// the definition about blackbox object

public class Blackbox implements Runnable {
    private int distEvent;    // the number of distance event
    private int animalEvent;  // the number of animal event
    private int pedestEvent;  // the number of pedestrian event
    private int rLightEvent;  // the number of red light event
    private int centEvent;    // the number of line centering event
    private int heatEvent;    // the number of heater activated
    private int airconEvent;  // the number of air-con activated

    public void run() {
        for(int i=0 ; i<10 ; i++) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        printResult();
    }

    // constructor, initiate all count value
    public Blackbox() {
        this.distEvent = 0;
        this.animalEvent = 0;
        this.pedestEvent = 0;
        this.rLightEvent = 0;
        this.centEvent = 0;
        this.heatEvent = 0;
        this.airconEvent = 0;
    }

    // setter
    // update each count value
    public void setDistEvent() { this.distEvent += 1; }
    public void setAnimalEvent() { this.animalEvent += 1; }
    public void setPedestEvent() { this.pedestEvent += 1; }
    public void setRLightEvent() { this.rLightEvent += 1; }
    public void setCentEvent() { this.centEvent += 1; }
    public void setHeatEvent() { this.heatEvent += 1; }
    public void setAirconEvent() { this.airconEvent += 1; }

    // getter
    // return each count value
    public int getDistEvent() { return this.distEvent; }
    public int getAnimalEvent() { return this.animalEvent; }
    public int getPedestEvent() { return this.pedestEvent; }
    public int getRLightEvent() { return this.rLightEvent; }
    public int getCentEvent() { return this.centEvent; }
    public int getHeatEvent() { return this.heatEvent; }
    public int getAirconEvent() { return this.airconEvent; }

    // print current information
    public void printResult() {
        System.out.println(""); // For readability
        System.out.println("=== Black Box Data ===");
        System.out.println("Speed Control terminating.");
        System.out.println("Number of Animals Sensed: " + getAnimalEvent());
        System.out.println("Number of Pedestrian Sensed: " + getPedestEvent());
        System.out.println("Number of Red Traffic Lights Sensed: " + getRLightEvent());
        System.out.println("Number of Distance Control: " + getDistEvent());
        System.out.println("Number of Heater Turned On: " + getHeatEvent());
        System.out.println("Number of Aircon Turned On: " + getAirconEvent());
        System.out.println("Number of Lane Centering Activated: " + getCentEvent());
        System.out.println("=== Black Box in Sleep Mode ===");
    }
}