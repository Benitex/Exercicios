public class Pokemon {
    int vida,golpe,ataque;
    String nome,golpeEscolhido,golpe1="Splash",golpe2="Splash",golpe3="Splash",golpe4="Splash";

    public void definirEspécie (){
        System.out.println("Escolha o pokemon.");
        //comando para definir o pokemon
        if(nome=="Turtwig"){
            vida=55;
            ataque=10;
            golpe1="Tackle";
            golpe2="Growl";
        }
        if(nome=="Bulbasaur"){
            vida=45;
            ataque=11;
            golpe1="Tackle";
            golpe2="Withdraw";
        }
    }

    public void ataque (int vida){
        System.out.println("Escolha o golpe do "+nome+": ");
        System.out.println("1 - " + golpe1 + "2 - " + golpe2 + "3 - " + golpe3 + "4 - " + golpe4);
        while(golpe>4||golpe<1){
            //comando para decidir o golpe
            golpe=1;    
            //isso vai substituir por enquanto
            if (golpe==1)
                golpeEscolhido=golpe1;
            else if (golpe == 2)
                golpeEscolhido=golpe2;
            else if (golpe == 3)
                golpeEscolhido=golpe3;
            else if (golpe == 4)
                golpeEscolhido=golpe4;
            else
                System.out.println("Escolha um valor entre 1 e 4.");
        }
        System.out.println(nome + " utilizou " + golpeEscolhido);
        if(golpeEscolhido=="Tackle")
            vida-=ataque;
    }
}