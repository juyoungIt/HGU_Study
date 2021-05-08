public class HybridMode implements DriveMode {
    private HybridCar hybridCar;

    public HybridMode(HybridCar hybridCar)
    {
        this.hybridCar = hybridCar;
        System.out.println("Main Battery has enough power. But secondary battery needs more charging.");
        this.hybridCar.printBatStat(); // print the battery status
        hybridCar.modeChange(); // print mode change information
        System.out.println("( For Hybrid Mode) Fuel Engine Started if engine is in sleep mode.");
        System.out.println("Supply electricity to front motor of hybrid hybridCar");
    }

    public void start()
    {
        System.out.println("Continue to run fuel engine.");
        System.out.println("Main generator charges battery.");
        System.out.println("Regenerative brake energy charges battery.");
        this.hybridCar.updateCharge(); // update battery charge level
        this.hybridCar.speedChange(); // update current speed level
        System.out.println("(Hybrid Mode) Current Speed: " + this.hybridCar.get_speed());
        System.out.println(""); // for readability
    }
}
