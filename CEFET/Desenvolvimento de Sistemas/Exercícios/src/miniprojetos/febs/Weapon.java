package miniprojetos.febs;

public class Weapon {
    private int damage, accuracy;
    private String type;
    private boolean magical;

    public int getDamage() {
        return damage;
    }
    public String getType() {
        return type;
    }
    public int getAccuracy() {
        return accuracy;
    }
    public boolean isMagical() {
        return magical;
    }
}
