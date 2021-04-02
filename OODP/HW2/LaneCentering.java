public class LaneCentering extends Thread {
    private final Sensor sensor; // store object of Sensor class

    // constructor
    // set the sensor information
    public LaneCentering(Sensor sensor) {
        this.sensor = sensor;
    }

    public void run() {
        for(int i=0 ; i<10 ; i++) {
            try {
                this.sensor.updateCent(); // update lane status
                if(!this.sensor.getCentered()) {
                    this.sensor.laneEvent(); // adjust lane status
                }
                Thread.sleep(300);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
