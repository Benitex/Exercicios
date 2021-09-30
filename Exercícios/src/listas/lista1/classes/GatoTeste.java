package listas.lista1.classes;
/*
Exercício 2 – Crie uma classe chamada GatoTeste com o método main
    A – crie 3 instâncias de Gato. Atribua a cada uma das instâncias valores para as variáveis vivo, cor, idade, nome de forma que cada instância tenha valores diferentes.
    B – imprima o valor dos atributos de cada Gato no console. O valor dos atributos de cada Gato deve estar em uma linha, ou seja, um System.out para cada objeto.
*/
public class GatoTeste {
    public static void main(String[] args) {
        Leao gato1 = new Leao();
        gato1.vivo = true;
        gato1.setCor("Branco");
        gato1.setIdade(10);
        gato1.setNome("Meowth");

        Leao gato2 = new Leao();
        gato2.vivo = true;
        gato2.setCor("Cinza");
        gato2.setIdade(7);
        gato2.setNome("Glameow");

        Leao gato3 = new Leao();
        gato3.vivo = false;
        gato3.setCor("Preto");
        gato3.setIdade(5);
        gato3.setNome("Litten");

        System.out.println("Nome: "+gato1.getNome()+"\tCor: "+gato1.getCor()+"\tIdade: "+gato1.getIdade()+"\tVivo? "+gato1.vivo);
        System.out.println("Nome: "+gato2.getNome()+"\tCor: "+gato2.getCor()+"\tIdade: "+gato2.getIdade()+"\tVivo? "+gato2.vivo);
        System.out.println("Nome: "+gato3.getNome()+"\tCor: "+gato3.getCor()+"\tIdade: "+gato3.getIdade()+"\tVivo? "+gato3.vivo);
    }
}