/*
F – Crie uma nova classe, denominada ProgramaPrincipal. O programa deverá receber do
console 5 Strings no seguinte formato: id#nome#salario#tipo (i.e., mesmo formato explicado
no item E). Utilizando os métodos já criados, exiba no console os nomes e salários dos
funcionários.
*/
package aula6;
import java.util.ArrayList;
import java.util.Scanner;

public class ProgramaPrincipal {
    public static void main(String[] args){
        Scanner resposta = new Scanner(System.in);
        String[] funcionario = new String[5];
        for (int tempo = 0; tempo < funcionario.length; tempo++) {
            System.out.println("Insira o funcionário no padrão id#nome#salario#tipo.");
            funcionario[tempo] = resposta.nextLine();
        }
        resposta.close();
        ArrayList funcionarios = (ArrayList) Utils.retornaDados(funcionario);
        for (int tempo = 0; tempo < funcionarios.size(); tempo++) {
            Funcionario f = (Funcionario) funcionarios.get(tempo);
            System.out.println(f.getNome() + " recebe " + f.getSalario());
        }
        Utils.mediaSalarial(funcionarios);
    }
}
