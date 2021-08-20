import java.util.Scanner;

public class Neo {
    public static void main(String[] args) {
        boolean continuar = true;
        while(continuar == true){
            Pokemon p1 = new Pokemon();
            Pokemon p2 = new Pokemon();
            while (p1.getVida()>0||p2.getVida()>0){
                if(p1.getSpeed()>p2.getSpeed()){
                    p1.ataque(p2.getVida());
                    p2.ataque(p1.getVida());
                }else{
                    p2.ataque(p1.getVida());
                    p1.ataque(p2.getVida());
                }
                System.out.println("Vida de "+p1.getEspecie()+": "+p1.getVida());
                System.out.println("Vida de "+p2.getEspecie()+": "+p2.getVida());
            }
            if (p2.getVida() < 0)
                System.out.println(p2.getEspecie()+" não consegue mais se mover!\n"+p1.getEspecie()+" venceu!");
            else
                System.out.println(p1.getEspecie()+" não consegue mais se mover!\n"+p2.getEspecie()+" venceu!");
            
            Scanner s = new Scanner(System.in);
            System.out.println("Gostaria de continuar jogado? (s/n)");
            String resposta;
            do{
                resposta =  s.nextLine();
                if (resposta.equalsIgnoreCase("s")){
                    System.out.println("Reiniciando.");
                    continuar=true;
                }else if (resposta.equalsIgnoreCase("n")){
                    System.out.println("Por favor, insira s para sim ou n para não.");
                    continuar=false;
                }else
                    System.out.println("Por favor, insira s para sim ou n para não.");
            }while (!resposta.equalsIgnoreCase("s") && !resposta.equalsIgnoreCase("n"));
            s.close();
        }
    }
}