public class Speed extends Thread {
    private final Sensor sensor;
    private final int init;
    private final int speedDevi; // allow deviation value of speed
    private final int dist; // the distance from front car
    private final int distDevi; // allow deviation value of dist

    // constructor
    public Speed(Sensor sensor, int init, int speedDevi, int dist, int distDevi) {
        this.sensor = sensor;
        this.init = init;
        this.speedDevi = speedDevi;
        this.dist = dist;
        this.distDevi = distDevi;
    }

    public void run() {
        // repeat 15 times
        for(int i=0 ; i<10 ; i++) {
            try {
                this.sensor.updateSpeed();  // update speed value
                this.sensor.updateDist();   // update distance value

                // normal speed issue
                if(this.sensor.getCurSpeed() < init-speedDevi) {
                    this.sensor.speedEvent(init);
                }

                // manipulate speed issue (adaptive dist)
                if(this.sensor.getDistFront() > dist+distDevi) {
                    this.sensor.farDistEvent(init);
                }

                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
