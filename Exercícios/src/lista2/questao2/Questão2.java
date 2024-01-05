/* Crie um programa que receba do console (entrada do teclado) uma frase. Em seguida, esse 
programa deve chamar o método Utils.verifica(String texto). */

package lista2.questao2;

import java.util.Scanner;

public class Questão2 {
    public static void main(String[] args) {
        Scanner resposta = new Scanner(System.in);
        System.out.println("Insira a frase.");
        String frase = resposta.nextLine();
        try {
            Utils.verifica(frase);
        } catch (TextoCurtoException e) {
            System.out.println("Frase muito curta.");
        }
        System.out.println(Utils.moderar(frase));
        resposta.close();
    }
}
