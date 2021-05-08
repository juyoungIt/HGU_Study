public class ModeControl {
    private DriveMode driveMode; // the drive mode

    // constructor
    public ModeControl(DriveMode driveMode)
    {
        this.driveMode = driveMode;
    }

    public void runVehicle()
    {
        this.driveMode.start();
    }
}
