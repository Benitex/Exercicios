import java.util.Scanner;

public class Neo{
    public static void main(String[] args){
        boolean continuar = true;
        Scanner s = new Scanner(System.in);
        do {
            Pokemon p1 = new Pokemon(s);
            Pokemon p2 = new Pokemon(s);
            batalha(p1, p2, s);
            System.out.println("Gostaria de continuar jogado? (s/n)");
            String resposta;
            do{
                resposta = s.nextLine();
                if (resposta.equalsIgnoreCase("s")){
                    System.out.println("Reiniciando.");
                    continuar=true;
                }else if (resposta.equalsIgnoreCase("n")){
                    System.out.println("Por favor, insira s para sim ou n para não.");
                    continuar=false;
                }else
                    System.out.println("Por favor, insira s para sim ou n para não.");
            }while (!resposta.equalsIgnoreCase("s") && !resposta.equalsIgnoreCase("n"));
        }while(continuar == true);
        s.close();
    }

    private static void batalha(Pokemon p1, Pokemon p2, Scanner s){
        while (p1.getVida()>0 && p2.getVida()>0){
            if (p1.getSpeed()>p2.getSpeed()){
                p1.atacar(p2,s);
                p2.atacar(p1,s);
            }else{
                p2.atacar(p2,s);
                p1.atacar(p1,s);
            }
            System.out.println("Vida de "+p1.getEspecie()+": "+p1.getVida());
            System.out.println("Vida de "+p2.getEspecie()+": "+p2.getVida());
        }
        if (p2.getVida() < 0)
            System.out.println(p2.getEspecie()+" não consegue mais se mover!\n"+p1.getEspecie()+" venceu!\n");
        else
            System.out.println(p1.getEspecie()+" não consegue mais se mover!\n"+p2.getEspecie()+" venceu!\n");
    }
}