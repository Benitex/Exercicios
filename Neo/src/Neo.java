import java.util.Scanner;

public class Neo{
    public static void main(String[] args){
        boolean continuar = true;
        Scanner s = new Scanner(System.in);
        do {
            Pokemon p1 = new Pokemon(definirEspecie(s));
            Pokemon p2 = new Pokemon(definirEspecie(s));
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

    public static void batalha(Pokemon p1, Pokemon p2, Scanner s){
        while (p1.getVida()>0 && p2.getVida()>0){
            if (p1.getSpeed()>p2.getSpeed()){
                p1.ataque(p1,p2,definirGolpe(p1,s));
                p2.ataque(p2,p1,definirGolpe(p2,s));
            }else{
                p2.ataque(p2,p1,definirGolpe(p2,s));
                p1.ataque(p1,p2,definirGolpe(p1,s));
            }
            System.out.println("Vida de "+p1.getEspecie()+": "+p1.getVida());
            System.out.println("Vida de "+p2.getEspecie()+": "+p2.getVida());
        }
        if (p2.getVida() < 0)
            System.out.println(p2.getEspecie()+" não consegue mais se mover!\n"+p1.getEspecie()+" venceu!\n");
        else
            System.out.println(p1.getEspecie()+" não consegue mais se mover!\n"+p2.getEspecie()+" venceu!\n");
    }

    public static String definirEspecie(Scanner s){
        boolean especieIncluida = false;
        String especie = null;

        while (especieIncluida == false) {
            System.out.println("Escolha o pokemon.");
            especie = s.next();
            if (especie.equalsIgnoreCase("Turtwig")||especie.equalsIgnoreCase("Bulbasaur"))
                especieIncluida = true;
            else
                System.out.println(especie+" não é um dos pokemon disponíveis, por favor insira outro.");
        }
        return especie;
    }

    public static String definirGolpe(Pokemon p, Scanner s){
        String golpeEscolhido;
        int golpeEscolhidoNum = 5;
        String golpe[] = new String[4];

        p.getGolpe(golpe);
        System.out.println("\nEscolha o golpe do "+p.getEspecie()+":");
        System.out.println("1 - "+golpe[0]+"\t2 - "+golpe[1]+"\t3 - "+golpe[2] + "\t4 - "+golpe[3]);
        do {
            s.nextLine();
            golpeEscolhido = s.nextLine();
            for (int tempo = 0; tempo < golpe.length; tempo++) {
                if (golpeEscolhido.equalsIgnoreCase(golpe[tempo])){
                    golpeEscolhidoNum = tempo;
                }
            }
            if (golpeEscolhidoNum == 5)
                if (golpeEscolhido.equalsIgnoreCase("1") || golpeEscolhido.equalsIgnoreCase("2") || golpeEscolhido.equalsIgnoreCase("3") || golpeEscolhido.equalsIgnoreCase("4")){
                    for (int tempo = 0; tempo < golpe.length; tempo++) {
                        if (Integer.parseInt(golpeEscolhido)-1 == tempo)
                            golpeEscolhido = golpe[tempo];
                    }
                    golpeEscolhidoNum = Integer.parseInt(golpeEscolhido) - 1;
                }else
                    System.out.println("Escolha um golpe válido.");
        }while(golpeEscolhidoNum < 0 || golpeEscolhidoNum > 3);
        return golpeEscolhido;
    }
}