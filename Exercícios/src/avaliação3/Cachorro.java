/*Insira no campo de resposta apenas o código da classe cachorro da seguinte maneira:

(a) a classe cachorro deve ter os atributos privados nome (String), idade (int) e peso (double), além de seus getters e setters.
(b) a classe cachorro deve ter dois construtores. Um vazio e um que faz a atribuição dos três atributos.
(c) a linha 3 deve ordenar a lista pela idade dos cachorros, de maneira crescente.
(d) a linha 5, ao ser invocada, deve exibir no console os valores dos atributos nome, idade e peso de cada cachorro separados por um traço e com um "kg" ao final. 
    Ex: "Bidu - 15 - 30kg". vale destacar, que por conta do item (c), o resultado deve sair ordenado.
*/

package avaliação3;

public class Cachorro implements Comparable<Cachorro> {
    private String nome;
    private int idade;
    private double peso;

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public int getIdade() {
        return idade;
    }
    public void setPeso(double peso) {
        this.peso = peso;
    }
    public double getPeso() {
        return peso;
    }

    public Cachorro() {
    }
    public Cachorro( String nome, int idade, double peso) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
    }

    @Override
    public int compareTo(Cachorro o) {
        return Integer.compare(idade, o.idade);
    }
    @Override
    public String toString() {
        return nome + " - " + idade + " - " + peso + "kg";
    }
}
