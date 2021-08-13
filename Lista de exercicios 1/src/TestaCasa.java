/*
Exercício 4 – Crie uma classe chamada TestaCasa com o método main
    A- crie dois objetos do tipo Casa.
    B- Atribua valores às variáveis de instância
    C- Imprima no console os valores cor e número de cada casa no seguinte formato: A casa de número X tem cor Y.
*/
public class TestaCasa {
    public static void main(String[] args){
    Casa casa1 = new Casa();
    casa1.cor = "Amarela";
    casa1.numero = 0;

    Casa casa2 = new Casa();
    casa2.cor = "Vermelha";
    casa2.numero = 5;

    System.out.println("A casa de número "+casa1.numero+" tem cor "+casa1.cor+".");
    System.out.println("A casa de número "+casa2.numero+" tem cor "+casa2.cor+".");
    }
}