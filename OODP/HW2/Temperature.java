public class Temperature extends Thread {
    private final Sensor sensor;
    private final int init;
    private final int devi; // allowed deviation value

    // constructor
    public Temperature(Sensor sensor, int init, int devi) {
        this.sensor = sensor;
        this.init = init;
        this.devi = devi;
    }

    public void run() {
        // repeat 15 times
        for(int i=0 ; i<10 ; i++) {
            try {
                this.sensor.updateTemp(); // update the temp
                // hot event
                if (this.sensor.getTemp() > init+devi) {
                    this.sensor.hotEvent(init);
                }
                // cold event
                else if (this.sensor.getTemp() < init-devi) {
                    this.sensor.coldEvent(init);
                }
                Thread.sleep(400);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
