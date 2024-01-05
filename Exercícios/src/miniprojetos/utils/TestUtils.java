package miniprojetos.utils;

import java.util.Scanner;

public class TestUtils {
    public static void main(String[] args) {
        System.out.println("O que gostaria de fazer?");
        Scanner scanner = new Scanner(System.in);
        String operacao = scanner.nextLine();
        operacao = operacao.trim();

        if (operacao.equalsIgnoreCase("Bhaskara")){
            System.out.println("Insira o valor de a.");
            double a = scanner.nextDouble();
            System.out.println("Insira o valor de b.");
            double b = scanner.nextDouble();
            System.out.println("Insira o valor de c.");
            double c = scanner.nextDouble();
            Utils.bhaskara(a, b, c);
        }

        else if (operacao.equalsIgnoreCase("Media")){
            System.out.println("Quantos elementos?");
            double n[] = new double[scanner.nextInt()];
            for (int tempo = 0; tempo < n.length; tempo++) {
                System.out.println("Qual o valor do elemento "+tempo+"?");
                n[tempo] = scanner.nextDouble();
            }
            System.out.println(Utils.calculaMedia(n));
        }

        else if (operacao.equalsIgnoreCase("Numero aleatorio")) {
            System.out.println("Insira o valor mínimo e máximo divididos por um espaço.");
            String resposta = scanner.nextLine();
            String[] valores = resposta.split(" ");
            int valor1 = Integer.parseInt(valores[0]);
            int valor2 = Integer.parseInt(valores[1]);
            if (valor1 == 1) {
                System.out.println(Utils.rolarNumeroAleatorio(valor2));
            } else {
                System.out.println(Utils.rolarNumeroAleatorio(valor1, valor2));
            }
        }

        else if (operacao.equalsIgnoreCase("Maior numero")) {
            System.out.println("Quantos valores serão comparados?");
            double[] n = new double[scanner.nextInt()];
            for (int tempo = 0; tempo < n.length; tempo++) {
                System.out.println("Insira o próximo valor.");
                n[tempo] = scanner.nextDouble();
            }
            System.out.println(Utils.maiorNumero(n) + " é o maior número do array.");
        }

        else if (operacao.equalsIgnoreCase("Repeticoes")) {
            System.out.println("Insira os valores do array.");
            double[] n = new double[scanner.nextInt()];
            for (int tempo = 0; tempo < n.length; tempo++) {
                System.out.println("Insira o próximo valor.");
                n[tempo] = scanner.nextDouble();
            }
            System.out.println("Qual é o valor que será contado na lista?");
            double valor = scanner.nextDouble();
            System.out.println("O numero " + valor + " aparece " + Utils.repeticoes(valor, n) + " vezes no array.");
        }

        scanner.close();
    }
}