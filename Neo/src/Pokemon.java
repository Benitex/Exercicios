import java.util.Scanner;

public class Pokemon {
    int vida,ataque,speed;
    String nome,golpe[]={"Splash","Splash","Splash","Splash"};

    public void definirEspécie (){
        boolean especieIncluida=false;
        System.out.println("Escolha o pokemon.");
        Scanner scanner = new Scanner(System.in);
        while(especieIncluida==false){
            nome=scanner.nextLine();
            scanner.close();
            especieIncluida=true;
            if(nome=="Turtwig"){
                vida=55;
                ataque=10;
                speed=55;
                golpe[0]="Tackle";
                golpe[1]="Growl";
            }else if(nome=="Bulbasaur"){
                vida=45;
                ataque=11;
                speed=65;
                golpe[0]="Tackle";
                golpe[1]="Withdraw";
            }else{
                System.out.println(nome+" não é um dos pokemon disponíveis, por favor insira outro.");
                especieIncluida=false;
            }
        }
    }

    public void ataque (int vida){
        int golpeEscolhido;
        
        System.out.println("Escolha o golpe do "+nome+": ");
        System.out.println("1 - "+golpe[1]+"2 - "+golpe[2]+"3 - "+golpe[3] + "4 - "+golpe[4]);
        Scanner scanner = new Scanner(System.in);
        do{
            golpeEscolhido = scanner.nextInt()-1;
            scanner.close();
            if (golpeEscolhido<1||golpeEscolhido>4)
                System.out.println("Escolha um valor entre 1 e 4.");
        }while(golpeEscolhido<1||golpeEscolhido>4);
        System.out.println(nome+" utilizou "+golpeEscolhido);
        if(golpe[golpeEscolhido]=="Tackle")
            vida-=ataque;
    }
}