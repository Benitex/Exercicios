/*
2. Crie uma classe Principal. Crie um array de carros. 
Preencha esse array com 1000 carros em que os dados são recebidos do console, 
ou seja, insira a placa e ano dos carros a partir da entrada do teclado.
*/
package avaliacao1;
import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Carro carros[] = new Carro[1000];
        for (int tempo = 0; tempo < carros.length; tempo++) {
            carros[tempo] = new Carro();
            System.out.println("Insira a placa do veiculo "+tempo+".");
            carros[tempo].placa = s.next();
            System.out.println("Insira o ano do veiculo "+tempo+".");
            carros[tempo].ano = s.nextInt();
        }
        s.close();
        System.out.println("A média dos anos dos carros é: "+Principal.mediaAnos(carros)+".");
    }
    /*
    3. Em seguida, crie, ainda na classe Principal, um outro método, que receba como argumento um array de carros. 
    Percorra esse array e retorne no método a média dos anos dos carros no array recebido.
    */
    public static int mediaAnos(Carro[] carros) {
        int media = 0;
        for (int tempo = 0; tempo < carros.length; tempo++) {
            media+=carros[tempo].ano;
        }
        return media/carros.length;
    }
}