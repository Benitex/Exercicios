package aula7;

import java.util.HashMap;
import java.util.Scanner;

public class Exercicio {
    public static void main(String[] args) {
        /*
        1- Crie um programa que receba um texto como entrada do teclado. Esse programa deve
        criar um mapa para guardar a contagem de palavras do texto entrado. Assim, as chaves do
        mapa devem ser as palavras e os valores associados às chaves devem ser as contagens
        dessas palavras. Exemplo de mapa: {"a",15}, {"casa", 2}, etc.
        */
        Scanner resposta = new Scanner(System.in);
        HashMap mapa = new HashMap();
        System.out.println("Insira o texto.");
        String texto = resposta.nextLine();
        String[] palavras = texto.split(" ");
        for (int tempo = 0; tempo < palavras.length; tempo++) {
            if (mapa.containsKey(palavras[tempo])) {
                mapa.put(palavras[tempo], mapa.get(palavras[tempo] + 1));
            } else {
                mapa.put(palavras[tempo], 1);
            }
        }
        //2 - Imprima no console a lista de palavras.
        for (int tempo = 0; tempo < palavras.length; tempo++) {
            System.out.println(palavras[tempo]);
        }
        //3- Imprima no console a lista de palavras com a quantidade de ocorrência de cada palavra.
        System.out.println("\n" + mapa.toString());
    }
}
