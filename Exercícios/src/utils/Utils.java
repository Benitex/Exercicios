package utils;

import java.lang.Math;

public class Utils{
    public static double calculaMedia(double[] array) {
        int tempo;
        double soma = 0;
        for (tempo = 0; tempo < array.length; tempo++) {
            soma += array[tempo];
        }
        return soma/tempo;
    }

    public static void bhaskara(double a, double b, double c) {
        double delta = ((b * b) - (4 * a * c));
        if (delta < 0) {
            System.out.println("Raízes imaginárias.");
        } else if (delta == 0) {
            System.out.println("Raiz única = "+((-b + Math.pow(delta,0.5)) / (2 * a)));
        } else {
            System.out.println("Raizes distintas. x1 = "+((-b + Math.pow(delta,0.5)) / (2 * a))+" e x2= "+(-b -Math.pow(delta,0.5)) / (2 * a));
        }
    }

    public static int rolarNumeroAleatorio(int maxNum) {
        return (int) ((Math.random() * maxNum) + 1);
    }
    public static int rolarNumeroAleatorio(int minNum, int maxNum) {
        return (int) ((Math.random() * (maxNum - minNum + 1)) + minNum);
    }

    public static double maiorNumero(double[] array) {
        double maior = array[0];
        for (int tempo = 0; tempo < array.length; tempo++) {
            if (array[tempo] > maior) {
                maior = array[tempo];
            }
        }
        return maior;
    }
}