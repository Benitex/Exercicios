public class Golpe {
    int poder;
    boolean dano = false;

    public Golpe(String nome){
        if(nome.equalsIgnoreCase("Tackle")){
            poder = 40;
            dano = true;
        }
        if(nome.equalsIgnoreCase("Tail Whip")){
            dano = false;
        }
        if(nome.equalsIgnoreCase("Tail Whip")){
            dano = false;
        }
    }
}