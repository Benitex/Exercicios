/*
1. Crie uma classe denominada Carro. Crie dois atributos denominados placa e ano (escolha os tipos adequados).  
Crie um método denominado correr que não retorne nada e que não tenha argumentos. 
Esse método, ao ser chamado, deve imprimir no console a placa e o ano do carro da seguinte maneira: 
“O carro com a placa XXX e do ano YYY esta correndo...”, em que XXX corresponde à placa do carro e YYY ao ano.
*/
package avaliacao1;

public class Carro {
    String placa;
    int ano;

    public void correr() {
        System.out.println("O carro com a placa "+placa+" e do ano "+ano+" esta correndo...");
    }
}