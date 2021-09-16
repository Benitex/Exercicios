import java.util.Scanner;

public class Pokemon {
    private int vida,ataque,speed;
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

    public void setAttributes(String especie){
        this.especie = especie;
        if(especie.equalsIgnoreCase("Turtwig")){
            vida = 55;
            ataque = 10;
            speed = 55;
            tipo[0] = "Grass";
            golpe[0] = "Tackle";
            golpe[1] = "Growl";
        }else if(especie.equalsIgnoreCase("Bulbasaur")){
            vida = 45;
            ataque = 11;
            speed = 65;
            tipo[0] = "Grass";
            tipo[1] = "Poison";
            golpe[0] = "Tackle";
            golpe[1] = "Withdraw";
        }
    }

    public int ataque (int vida, Scanner s){
        int golpeEscolhido;
        
        System.out.println("Escolha o golpe do "+especie+":");
        System.out.println("1 - "+golpe[0]+"\t2 - "+golpe[1]+"\t3 - "+golpe[2] + "\t4 - "+golpe[3]);
        do{
            golpeEscolhido = s.nextInt() - 1;
            if (golpeEscolhido < 0 || golpeEscolhido > 3)
                System.out.println("Escolha um valor entre 1 e 4.");
        }while(golpeEscolhido<0||golpeEscolhido > 3);
        System.out.println(especie+" utilizou "+golpe[golpeEscolhido]);
        if(golpe[golpeEscolhido] == "Tackle")
            return vida - ataque;
        else
            return vida;
    }
}