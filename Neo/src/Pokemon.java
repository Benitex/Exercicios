import java.util.Scanner;

public class Pokemon {
    public int vida;
    private int ataque,speed;
    private String especie,golpe[]={"Splash","Splash","Splash","Splash"};

    public int getSpeed(){
        return speed;
    }
    public String getEspecie(){
        return especie;
    }

    public void setAttributes(String especieEscolhida){
        especie = especieEscolhida;
        if(especieEscolhida.equalsIgnoreCase("Turtwig")){
            vida=55;
            ataque=10;
            speed=55;
            golpe[0]="Tackle";
            golpe[1]="Growl";
        }else if(especieEscolhida.equalsIgnoreCase("Bulbasaur")){
            vida=45;
            ataque=11;
            speed=65;
            golpe[0]="Tackle";
            golpe[1]="Withdraw";
        }
    }

    public void ataque (int vida, Scanner s){
        int golpeEscolhido;
        
        System.out.println("Escolha o golpe do "+especie+":");
        System.out.println("1 - "+golpe[0]+"\t2 - "+golpe[1]+"\t3 - "+golpe[2] + "\t4 - "+golpe[3]);
        do{
            golpeEscolhido = s.nextInt()-1;
            if (golpeEscolhido<0||golpeEscolhido>3)
                System.out.println("Escolha um valor entre 1 e 4.");
        }while(golpeEscolhido<0||golpeEscolhido>3);
        System.out.println(especie+" utilizou "+golpe[golpeEscolhido]);
        if(golpe[golpeEscolhido]=="Tackle")
            vida-=ataque;
    }
}