import java.util.Scanner;

public class Neo {
    public static void main(String[] args) {
        boolean continuar = true;
        while(continuar == true){
            Pokemon p1 = new Pokemon();
            p1.definirEspécie();
            Pokemon p2 = new Pokemon();
            p2.definirEspécie();

            while (p1.vida>0||p2.vida>0){
                if(p1.speed>p2.speed){
                    p1.ataque (p2.vida);
                    p2.ataque(p1.vida);
                }else{
                    p2.ataque(p1.vida);
                    p1.ataque (p2.vida);
                }
                System.out.println("Vida de "+p1.nome+": "+p1.vida);
                System.out.println("Vida de "+p2.nome+": "+p2.vida);
            }
            if (p2.vida < 0)
                System.out.println(p2.nome+" não consegue mais se mover!\n"+p1.nome+" venceu!");
            else
                System.out.println(p1.nome+" não consegue mais se mover!\n"+p2.nome+" venceu!");
            
            Scanner s = new Scanner(System.in);
            System.out.println("Gostaria de continuar jogado? (s/n)");
            String resposta;
            do{
                resposta =  s.nextLine();
                if (resposta.equalsIgnoreCase("s")){
                    System.out.println("Reiniciando.");
                    continuar=true;
                }
                else if (resposta.equalsIgnoreCase("n")){
                    System.out.println("Por favor, insira s para sim ou n para não.");
                    continuar=false;
                }
                else
                    System.out.println("Por favor, insira s para sim ou n para não.");
            }while (!resposta.equalsIgnoreCase("s") && !resposta.equalsIgnoreCase("n"));
            s.close();
        }
    }
}