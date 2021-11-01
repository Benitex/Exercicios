/*
B – Crie uma classe chamada Utils. Implemente um método na classe Utils com a seguinte
assinatura: public static boolean existe (List x, Funcionario y). Escreva esse método de forma
que seja verificada a existência do objeto Funcionario representado por y na lista
representada por x, retorne verdadeiro se existir e falso se não existir. Considere que dois
objetos Funcionario são iguais se possuem o mesmo id. Não é permitida qualquer iteração
para realizar esse item, ou seja, não use for, iterator, etc. Implemente o que for necessário
para o funcionamento. Dica: você precisa criar uma alteração na classe Funcionario para
resolver esse item.
*/
package aula6;

import java.util.List;
import java.util.ArrayList;

public class Utils {
        public static boolean existe(List x, Funcionario y) {
            if (x.contains(y))
                return true;
            else
                return false;
        }

        /*
        E – Ainda na classe Utils, crie o método public List retornaDados(String []
        array_funcionarios);

        Considere que o array recebido como argumento (array_ funcionarios) contém Strings no
        seguinte formato: id#nome#salario#tipo. Por exemplo, considere os elementos desse array
        como as Strings (154-3#Simba Silva#3200#A, 553-2#Juju Juba#10000.0#P, etc.). Esses
        valores representam id, nome, salário e tipo do Funcionario (AnalistaSistemas ou
        Programador). Dessa maneira, implemente o método retornaDados de forma que seja
        retornado uma lista da seguinte forma: os elementos de array_ funcionarios devem ser
        percorridos e serão criados objetos do tipo AnalistaSistemas ou Programador. Resumindo,
        você irá criar um objeto AnalistaSistemas (se o último caractere da String for A) ou
        Programador (se o último caractere da string for P) e adicionar à lista.
        */
        public static List retornaDados(String[] arrayFuncionarios) {
            ArrayList funcionarios = new ArrayList();
            for (int tempo = 0; tempo < arrayFuncionarios.length; tempo++) {
                String[] dados = arrayFuncionarios[tempo].split("#");
                if (dados[3].equals("A")) {
                    AnalistaSistemas analista = new AnalistaSistemas(dados[0]);
                    analista.setNome(dados[1]);
                    analista.setSalario(dados[2]);
                    funcionarios.add(analista);
                } else if (dados[3].equals("P")) {
                    Programador programador = new Programador(dados[0]);
                    programador.setNome(dados[1]);
                    programador.setSalario(dados[2]);
                    funcionarios.add(programador);
                }
            }
            return funcionarios;
        }

        /*
        G – Exiba a média salarial dos analistas e dos programadores separadamente (ou seja, uma
        média para os analistas e uma média para os programadores). Para isso, crie um novo
        método em Utils.
        */
        public static void mediaSalarial(List funcionarios) {
            double mediaA = 0;
            int numA = 0;
            double mediaP = 0;
            int numP = 0;
            for (int tempo = 0; tempo < funcionarios.size(); tempo++) {
                Funcionario funcionario = (Funcionario) funcionarios.get(tempo);
                if (funcionario instanceof Programador) {
                    numP++;
                    mediaP += (Double) funcionario.getSalario();
                } else if (funcionario instanceof AnalistaSistemas) {
                    numA++;
                    mediaA += (Double) funcionario.getSalario();
                }
            }
            if (numP > 0) {
                System.out.println("Media do salário de programadores: " + (mediaP/numP));
            }
            if (numA > 0) {
                System.out.println("Media do salário de analistas: " + (mediaA/numA));
            }
        }
}