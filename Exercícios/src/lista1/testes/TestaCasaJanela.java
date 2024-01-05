package lista1.testes;

import lista1.classes.Casa;
import lista1.classes.Janela;

/*
Exercício 6 – Crie uma nova classe chamada TestaCasaJanela com o método main.
    A- Crie um novo objeto Janela e atribua valores a ele.
    B- Crie um novo objeto Casa e atribua valores a ele, inclusive a Janela criada acima (item A).
    C- Faça o debug e entenda o que acontece.
    D- A partir da referencia da Casa, imprima os valores dos atributos da casa e da janela.
*/
public class TestaCasaJanela {
    public static void main(String[] args){
        Janela janelaCozinha = new Janela();
        janelaCozinha.cor = "Marrom";
        janelaCozinha.material = "Madeira";

        Casa casaBraba = new Casa();
        casaBraba.cor = "Dourada";
        casaBraba.numero = 100000;
        casaBraba.janela = janelaCozinha;

        System.out.println("A casa "+casaBraba.cor+" correspondente ao número "+casaBraba.numero+" tem uma janela "+casaBraba.janela.cor+" de "+casaBraba.janela.material+".");
    }
}