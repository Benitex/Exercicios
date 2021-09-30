package listas.lista1.classes;
/*
Exercício 1 – Crie uma classe chamada Gato
    A – crie 4 atributos:
        vivo: boolean //identifica se o animal está vivo
        cor: String
        idade: int
        nome: String
    B – crie um método chamado miar() que imprima no console: “Gato miando“
*/

public class Gato extends Animal{
    public Gato(){
    }
    public void miar() {
        System.out.println("Gato miando");
    }
}