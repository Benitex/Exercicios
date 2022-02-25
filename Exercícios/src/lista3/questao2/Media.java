/* Questão 2: Crie uma classe denominada Media com um método estático denominado 
calcula (String numeros) com retorno do tipo double. Considere que o formato da String que 
esse método receberá é composto por N números separados pelo caractere #. Ex1: 15#3#8; 
Ex2: 3#1#1#1#4. Retorne a média dos números. */

package lista3.questao2;

public class Media {
    public static double calcula(String numeros) {
        String[] arrayNumero = numeros.split("#");
        double soma = 0;
        for (String numero : arrayNumero) {
            soma += Double.parseDouble(numero);
        }
        return soma/arrayNumero.length;
    }
}