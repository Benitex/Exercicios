package aula8;

import java.io.Serializable;

public class Funcionario implements Serializable, Comparable<Funcionario> {
    private static final long serialVersionUID = 3L;
    private String nome;
    private double salario;

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
    public void setSalario(double salario) {
        this.salario = salario;
    }
    public double getSalario() {
        return salario;
    }

    @Override
    public String toString() {
        return this.nome + " - " + this.salario;
    }
    @Override
    public int compareTo(Funcionario obj) {
        return Double.compare(salario, obj.salario);
    }
}
