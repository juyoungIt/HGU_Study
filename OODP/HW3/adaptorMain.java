public class adaptorMain {
    public static void main(String[] args) {
        HybridCar hybridCar = new HybridCar(); // create a hybridCar
        ModeControl mode;    // the driving mode

        for(int i=0 ; i<10 ; i++)
        {
            hybridCar.updateCharge(); // update the charge level
            // electric mode
            if(hybridCar.checkMainBat() && hybridCar.checkSecondBat()) {
                hybridCar.set_curMode("electric");
                mode = new ModeControl(new ElectricMode(hybridCar));
                mode.runVehicle();
            }
            // hybrid mode
            else if(hybridCar.checkMainBat() && !hybridCar.checkSecondBat()) {
                hybridCar.set_curMode("hybrid");
                mode = new ModeControl(new HybridMode(hybridCar));
                mode.runVehicle();
            }
            // fuel mode
            else if(!hybridCar.checkMainBat() && !hybridCar.checkSecondBat()) {
                hybridCar.set_curMode("fuel");
                mode = new ModeControl(new FuelMode(hybridCar));
                mode.runVehicle();
            }
        }
    }
}
