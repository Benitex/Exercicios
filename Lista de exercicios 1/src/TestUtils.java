import java.util.Scanner;

public class TestUtils {
    public static void main(String[] args) {
        System.out.println("O que gostaria de fazer?");
        Scanner scanner = new Scanner(System.in);
        String operacao = scanner.nextLine();
        if (operacao.equalsIgnoreCase("Bhaskara")){

        }
        else if (operacao.equalsIgnoreCase("Media")){
            double n[] = new double[6];
            int quantidade = 1;
            while(n[quantidade-1]!=0){
                if(quantidade<=4){
                    System.out.println("Insira o "+quantidade+"° número.");
                    n[quantidade] = scanner.nextDouble();
                    quantidade++;
                }else
                    n[quantidade] = 0;
            }
            if (quantidade == 2)
                Utils.calculaMedia(n[1], n[2]);
            else if (quantidade == 3)
                Utils.calculaMedia(n[1], n[2], n[3]);
            else if (quantidade == 4)
                Utils.calculaMedia(n[1], n[2], n[3], n[4]);
        }
        scanner.close();
    }
}