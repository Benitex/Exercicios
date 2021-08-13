/*
Exercício 2 – Crie uma classe chamada GatoTeste com o método main
    A – crie 3 instâncias de Gato. Atribua a cada uma das instâncias valores para as variáveis vivo, cor, idade, nome de forma que cada instância tenha valores diferentes.
    B – imprima o valor dos atributos de cada Gato no console. O valor dos atributos de cada Gato deve estar em uma linha, ou seja, um System.out para cada objeto.
*/
public class GatoTeste {
    public static void main(String[] args) {
        Gato gato1 = new Gato();
        gato1.vivo = true;
        gato1.cor = "Branco";
        gato1.idade = 10;
        gato1.nome = "Meowth";

        Gato gato2 = new Gato();
        gato2.vivo = true;
        gato2.cor = "Cinza";
        gato2.idade = 7;
        gato2.nome = "Glameow";

        Gato gato3 = new Gato();
        gato3.vivo = false;
        gato3.cor = "Preto";
        gato3.idade = 5;
        gato3.nome = "Litten";

        System.out.println("Nome: "+gato1.nome+"\tCor: "+gato1.cor+"\tIdade: "+gato1.idade+"\tVivo? "+gato1.vivo);
        System.out.println("Nome: "+gato2.nome+"\tCor: "+gato2.cor+"\tIdade: "+gato1.idade+"\tVivo? "+gato2.vivo);
        System.out.println("Nome: "+gato3.nome+"\tCor: "+gato3.cor+"\tIdade: "+gato1.idade+"\tVivo? "+gato3.vivo);
    }
}