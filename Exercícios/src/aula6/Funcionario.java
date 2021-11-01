/*
A – Escreva uma classe Funcionario com 3 atributos privados: id (String), nome (String) e
salario (double). Crie os getters e setters apenas se precisar. Crie em Funcionario APENAS
UM construtor, que recebe o id como argumento.
*/
package aula6;

public class Funcionario {
    private String id;
    private String nome;
    private double salario;

    public Funcionario(String id) {
        this.id = id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
    public void setSalario(String salario) {
        this.salario = Double.parseDouble(salario);
    }
    public double getSalario() {
        return salario;
    }

    public boolean equals(Object obj) {
        if (obj == null)
            return false;
        else if (this == obj)
            return true;
        else if (!(obj instanceof Funcionario))
            return false;
        else {
            Funcionario f = (Funcionario) obj;
            if (id.equals(f.id))
                return true;
            else
                return false;
        }
    }
    
    /*
    C – Considere o cenário que ao utilizar o System.out.println em um objeto do tipo
    Funcionario, deve sair no console o id, nome e salário desse funcionário. Ex: 123 – Arthur
    Matias – R$ 12000. Modifique a classe Funcionario de maneira que isso seja refletido.
    */
    public String toString() {
        return id + " - " + nome + " - " + salario;
    }
}
