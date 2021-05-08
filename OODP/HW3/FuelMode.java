public class FuelMode implements DriveMode {
    private HybridCar hybridCar; // the hybridCar object

    // constructor
    public FuelMode(HybridCar hybridCar)
    {
        this.hybridCar = hybridCar;
        System.out.println("Main battery and secondary battery have low power level.");
        this.hybridCar.printBatStat(); // print battery status
        hybridCar.modeChange(); // print mode change information
        System.out.println("( For Fuel Mode)Fuel Engine Started if engine is in sleep mode.");
        System.out.println("( For Fuel Mode)Cut Electricity to motor");
    }

    public void start() {
        System.out.println("Continue to run fuel engine.");
        System.out.println("Main generator charges battery.");
        System.out.println("Regenerative brake energy charges battery.");
        this.hybridCar.updateCharge(); // update battery charge level
        this.hybridCar.speedChange(); // update current speed level
        System.out.println("(Fuel Mode) Current Speed: " + this.hybridCar.get_speed());
        System.out.println(""); // for readability
    }
}
