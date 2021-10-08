import java.util.Scanner;

public class Pokemon {
    private int vida, ataque, defesa, speed;
    private String especie, tipo[] = new String[2];
    private Golpe[] golpe = new Golpe[4];

    public Pokemon(Scanner s){
        boolean especieIncluida = false;
        while (especieIncluida == false) {
            System.out.println("Escolha o pokemon.");
            especie = s.next();
            if (especie.equalsIgnoreCase("Turtwig")||especie.equalsIgnoreCase("Bulbasaur"))
                especieIncluida = true;
            else
                System.out.println(especie+" não é um dos pokemon disponíveis, por favor insira outro.");
        }

        if (especie.equalsIgnoreCase("Turtwig")){
            vida = 55;
            ataque = 68;
            defesa = 64;
            speed = 55;
            tipo[0] = "Grass";
            golpe[0] = new Golpe("Tackle");
            golpe[1] = new Golpe("Growl");
        }else if (especie.equalsIgnoreCase("Bulbasaur")){
            vida = 45;
            ataque = 49;
            defesa = 49;
            speed = 65;
            tipo[0] = "Grass";
            tipo[1] = "Poison";
            golpe[0] = new Golpe("Tackle");
            golpe[1] = new Golpe("Withdraw");
        }
    }

    public void setVida(int vida){
        this.vida = vida;
    }
    public void setDefesa(int defesa){
        this.defesa = defesa;
    }
    public int getVida(){
        return vida;
    }
    public int getDefesa(){
        return defesa;
    }
    public int getSpeed(){
        return speed;
    }
    public String getEspecie(){
        return especie;
    }
    public Golpe[] getGolpe(){
        return this.golpe;
    }        

    public void atacar(Pokemon atacado, Scanner s){
        Golpe golpeEscolhido = this.golpe[definirGolpe(s)];
        System.out.println(especie+" utilizou "+golpeEscolhido.toString());
        if (golpeEscolhido.isDano() == true)
            atacado.vida -= ataque - atacado.defesa + golpeEscolhido.getPoder();
        if (golpeEscolhido.isOponente() == true){
            if (golpeEscolhido.isReducaoStatus() == true)
                golpeEscolhido.reduzirStatus(atacado);
            if (golpeEscolhido.isBuffStatus() == true)
                golpeEscolhido.buffarStatus(atacado);
        }
        if (golpeEscolhido.isNeleMesmo() == true){
            if (golpeEscolhido.isReducaoStatus() == true)
                golpeEscolhido.reduzirStatus(this);
            if (golpeEscolhido.isBuffStatus() == true)
                golpeEscolhido.buffarStatus(this);
        }
    }

    private int definirGolpe(Scanner s){
        String golpeEscolhido;
        int golpeEscolhidoNum = 4;

        System.out.println("\nEscolha o golpe do "+this.especie+":");
        System.out.println("1 - "+golpe[0].toString()+"\t2 - "+golpe[1].toString()+"\t3 - "+golpe[2].toString() + "\t4 - "+golpe[3].toString());
        do {
            s.nextLine();
            golpeEscolhido = s.nextLine();
            for (int tempo = 0; tempo < golpe.length; tempo++) {
                if (golpeEscolhido.equalsIgnoreCase(golpe[tempo].toString())){
                    golpeEscolhidoNum = tempo;
                }
            }
            if (golpeEscolhidoNum == 4)
                if (golpeEscolhido.equalsIgnoreCase("1") || golpeEscolhido.equalsIgnoreCase("2") || golpeEscolhido.equalsIgnoreCase("3") || golpeEscolhido.equalsIgnoreCase("4"))
                    for (int tempo = 0; tempo < golpe.length; tempo++)
                        if (Integer.parseInt(golpeEscolhido)-1 == tempo)
                            golpeEscolhidoNum = tempo;
                else
                    System.out.println("Escolha um golpe válido.");
        }while(golpeEscolhidoNum < 0 || golpeEscolhidoNum > 3);
        return golpeEscolhidoNum;
    }
}