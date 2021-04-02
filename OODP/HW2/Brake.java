public class Brake extends Thread {
    private final Sensor sensor;
    private final int init;
    private final int speedDevi; // allow deviation value of speed
    private final int dist; // the distance from front car
    private final int distDevi; // allow deviation value of dist

    // constructor
    public Brake(Sensor sensor, int init, int speedDevi, int dist, int distDevi) {
        this.sensor = sensor;
        this.init = init;
        this.speedDevi = speedDevi;
        this.dist = dist;
        this.distDevi = distDevi;
    }

    public void run() {
        // repeat 15 times
        for(int i=0 ; i<10 ; i++) {
            if (this.sensor.getCurSpeed() > init) {
                this.sensor.brakeEvent(init);
            }

            try {
                this.sensor.updateDist(); // update dist value
                this.sensor.updateSpeed(); // update speed value
                this.sensor.updatePed();    // update pedestrian value
                this.sensor.updateAnimal(); // update animal value
                this.sensor.updateRedLight(); // update red light status

                // stop issue (pedestrian, animal, traffic light red)
                if(this.sensor.getPed()) { this.sensor.pedestEvent(); }
                if(this.sensor.getAnimal()) { this.sensor.animalEvent(); }
                if(this.sensor.getRedLight()) { this.sensor.redLightEvent(); }

                // manipulate speed issue (adaptive distance)
                if(this.sensor.getDistFront() < dist-distDevi) { this.sensor.closeDistEvent(init); }

                // normal speed issue
                if(this.sensor.getCurSpeed() > init+speedDevi) { this.sensor.brakeEvent(init); }

                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
