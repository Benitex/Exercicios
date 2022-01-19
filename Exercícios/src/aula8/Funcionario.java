package aula8;

import java.io.Serializable;

public class Funcionario implements Serializable, Comparable<Funcionario> {
    private static final long serialVersionUID = 3L;
    private String nome;
    private int salario;

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
    public void setSalario(int salario) {
        this.salario = salario;
    }
    public int getSalario() {
        return salario;
    }

    @Override
    public String toString() {
        return "Nome: " + this.nome + " - " + " Salário: " + this.salario;
    }
    @Override
    public int compareTo(Funcionario obj) {
        Integer salario = new Integer(this.salario);
        return salario.compareTo(obj.salario);
    }
}
