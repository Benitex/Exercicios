import java.util.Scanner;

public class Pokemon {
    private int vida,ataque,defesa,speed;
    private String especie,golpe[]={"-","-","-","-"};
    private String tipo[] = new String[2];

    public void setVida(int vida){
        this.vida = vida;
    }
    public int getVida(){
        return vida;
    }
    public int getSpeed(){
        return speed;
    }
    public String getEspecie(){
        return especie;
    }

    public Pokemon(String especie){
        this.especie = especie;
        if(especie.equalsIgnoreCase("Turtwig")){
            vida = 55;
            ataque = 68;
            defesa = 64;
            speed = 55;
            tipo[0] = "Grass";
            golpe[0] = "Tackle";
            golpe[1] = "Growl";
        }else if(especie.equalsIgnoreCase("Bulbasaur")){
            vida = 45;
            ataque = 49;
            defesa = 49;
            speed = 65;
            tipo[0] = "Grass";
            tipo[1] = "Poison";
            golpe[0] = "Tackle";
            golpe[1] = "Withdraw";
        }
    }

    public int ataque(int vida, Scanner s){
        String golpeEscolhido;
        int golpeEscolhidoNum = 5;
        
        System.out.println("Escolha o golpe do "+especie+":");
        System.out.println("1 - "+golpe[0]+"\t2 - "+golpe[1]+"\t3 - "+golpe[2] + "\t4 - "+golpe[3]);
        do{
            s.nextLine();
            golpeEscolhido = s.nextLine();
            for (int tempo = 0; tempo < golpe.length; tempo++) {
                if(golpeEscolhido.equalsIgnoreCase(golpe[tempo])){
                    golpeEscolhidoNum = tempo;
                }
            }
            if(golpeEscolhidoNum == 5)
                if(golpeEscolhido.equalsIgnoreCase("1") || golpeEscolhido.equalsIgnoreCase("2") || golpeEscolhido.equalsIgnoreCase("3") || golpeEscolhido.equalsIgnoreCase("4")){
                    for (int tempo = 0; tempo < golpe.length; tempo++) {
                        if(Integer.parseInt(golpeEscolhido) == tempo)
                            golpeEscolhido = golpe[tempo];
                    }
                    golpeEscolhidoNum = Integer.parseInt(golpeEscolhido) - 1;
                }else
                    System.out.println("Escolha um golpe válido.");
        }while(golpeEscolhidoNum<0||golpeEscolhidoNum > 3);
        Golpe definiçõesGolpe = new Golpe(golpeEscolhido);
        System.out.println(especie+" utilizou "+golpe[golpeEscolhidoNum]);
        if(definiçõesGolpe.dano == true)
            return vida - (ataque + definiçõesGolpe.poder - defesa);
        else
            return vida;
    }
}