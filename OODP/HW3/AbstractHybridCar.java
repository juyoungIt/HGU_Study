import java.util.Random;

public abstract class AbstractHybridCar {
    protected int speed;    // current speed
    protected final Random randGen;  // the random number generator

    // constructor
    public AbstractHybridCar()
    {
        this.speed = 0;
        this.randGen = new Random(); // create random machine
    }

    // abstract method related to mode
    public abstract void set_preMode(String mode);
    public abstract void set_curMode(String mode);
    public abstract void updateCharge();
    public abstract void printBatStat();
    public abstract boolean checkMainBat();
    public abstract boolean checkSecondBat();
    public abstract void modeChange();

    public int get_speed() {
        return this.speed;
    }

    // speed updater
    public void updateSpeed()
    {
        this.speed = randGen.nextInt(70) + 40;
    }
}