package miniprojetos.febs;
import miniprojetos.utils.Utils;

public class Character {
    private int HP, strength, magic, defense, resistence, speed, luck;
    private boolean alive;
    private Weapon weapon;

    public boolean isAlive() {
        return alive;
    }
    public void setWeapon(Weapon weapon) {
        this.weapon = weapon;
    }

    public void atack(Character opponent, boolean hasDefense) {
        int evasion = (int) (opponent.speed * 1.5 + opponent.luck * 0.5);
        if (Utils.rolarNumeroAleatorio(100) + this.luck > weapon.getAccuracy() + evasion) {
            if (weapon.isMagical()) {
                opponent.HP -= this.magic + this.weapon.getDamage() - opponent.resistence;
            } else {
                opponent.HP -= this.strength + this.weapon.getDamage() - opponent.defense;
            }
            if (opponent.HP > 0) {
                opponent.atack(this, false);
                if (this.speed - opponent.speed >= 5) {
                    this.atack(opponent, false);
                } else if (opponent.speed - this.speed >= 5) {
                    opponent.atack(this, false);
                }
            } else {
                opponent.alive = false;
            }
        }
    }
}
