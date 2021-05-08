public class HybridCar extends AbstractHybridCar {
    private String preMode; // previous mode (fuel, hybrid, electric)
    private String curMode; // current mode (fuel, hybrid, electric)
    private int mBattery; // the charge rate of main battery
    private int sBattery; // the charge rate of secondary battery

    // constructor
    public HybridCar()
    {
        preMode = "fuel";
        curMode = "fuel";
        this.mBattery = 75;
        this.sBattery = 75;
    }

    public void set_preMode(String mode) {
        this.preMode = mode;
    }
    public void set_curMode(String mode) {
        set_preMode(this.curMode); // backup
        this.curMode = mode;
    }

    public int get_mBattery() {
        return this.mBattery;
    }
    public int get_sBattery() {
        return this.sBattery;
    }
    public int get_speed() {
        return super.speed;
    }

    // battery charge updater
    public void updateCharge()
    {
        int charge1 = randGen.nextInt(20) - 10;
        int charge2 = randGen.nextInt(20) - 10;

        this.mBattery += charge1; // update main battery level
        this.sBattery += charge2; // update secondary battery level

        if(mBattery < sBattery) {
            int tmp = sBattery;
            sBattery = mBattery;
            mBattery = tmp;
        }

        // Exception handling - 1
        if(this.mBattery > 100)
            this.mBattery = 100;
        if(this.sBattery > 100)
            this.sBattery = 100;
        // Exception handling - 2
        if(this.mBattery < 0)
            this.mBattery = 0;
        if(this.sBattery < 0)
            this.sBattery = 0;
    }

    // speed updater
    public void updateSpeed()
    {
        this.speed = randGen.nextInt(70) + 40;
    }

    // main battery level checker
    public boolean checkMainBat()
    {
        return (this.mBattery >= 75); // check the battery charge level
    }

    // secondary battery level checker
    public boolean checkSecondBat()
    {
        return (this.sBattery >= 75); // check the battery charge level
    }

    // print battery status
    public void printBatStat()
    {
        System.out.println("Main Battery:-> " + this.mBattery + "% Charged");
        System.out.println("Secondary Battery:-> " + this.sBattery + "% Charged");
    }

    // print mode change information
    public void modeChange()
    {
        if(preMode.equals(curMode))
            System.out.println("Keep " + curMode + " car mode");
        else
            System.out.println("Convert from " + preMode + " mode to " + curMode + " car mode");
    }

    // adaptor pattern
    public void speedChange()
    {
        super.updateSpeed();
    }
}