package utils;

import java.util.Scanner;

public class TestUtils {
    public static void main(String[] args) {
        System.out.println("O que gostaria de fazer?");
        Scanner scanner = new Scanner(System.in);
        String operacao = scanner.nextLine();

        if (operacao.equalsIgnoreCase("Bhaskara")){
            System.out.println("Insira o valor de a.");
            float a = scanner.nextFloat();
            System.out.println("Insira o valor de b.");
            float b = scanner.nextFloat();
            System.out.println("Insira o valor de c.");
            float c = scanner.nextFloat();
            Utils.bhaskara(a, b, c);
        }
        
        else if (operacao.equalsIgnoreCase("Media")){
            int quantidade = 0;
            System.out.println("Quantos elementos?");
            quantidade = scanner.nextInt();
            double n[] = new double[quantidade];
            for (int tempo = 0; tempo < n.length; tempo++) {
                System.out.println("Qual o valor do elemento "+tempo+"?");
                n[tempo] = scanner.nextDouble();
            }
            System.out.println(Utils.calculaMedia(n));
        }

        else if (operacao.equalsIgnoreCase("Número aleatório")) {
            System.out.println("Insira o valor mínimo e máximo divididos por um espaço.");
            String resposta = scanner.nextLine();
            String[] valores = resposta.split(" ");
            int valor1 = Integer.parseInt(valores[0]);
            int valor2 = Integer.parseInt(valores[1]);
            if (valor2 == 1) {
                System.out.println(Utils.rolarNumeroAleatorio(valor2));
            } else {
                System.out.println(Utils.rolarNumeroAleatorio(valor1, valor2));
            }
        }
        
        scanner.close();
    }
}