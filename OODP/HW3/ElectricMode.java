public class ElectricMode implements DriveMode {
    private HybridCar hybridCar; // the hybridCar object

    // constructor
    public ElectricMode(HybridCar hybridCar)
    {
        this.hybridCar = hybridCar;
        System.out.println("Main and Secondary Batteries have enough power.");
        hybridCar.printBatStat(); // print the battery status
        hybridCar.modeChange(); // print mode change information
        System.out.println("( For Electric Mode)Cut Fuel to engine");
    }

    public void start()
    {
        System.out.println("Supply electricity to front and rear motors of electric hybridCar");
        System.out.println("Regenerative brake energy charges battery..");
        this.hybridCar.updateCharge(); // update battery charge level
        this.hybridCar.speedChange(); // update current speed level
        System.out.println("(Hybrid Mode) Current Speed: " + this.hybridCar.get_speed());
        System.out.println(""); // for readability
    }
}
