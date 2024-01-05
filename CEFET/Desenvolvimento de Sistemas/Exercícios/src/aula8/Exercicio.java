package aula8;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Exercicio {
    /*
    1 – Crie um sistema que contenha algumas classes, como desejar. No entanto, crie 
    obrigatoriamente uma classe denominada Funcionario com os atributos privados 
    nome e salário. Crie os gets e sets. Receba do console nomes e funcionários de sua 
    empresa a armazene em uma estrutura adequada. Serialize a lista de funcionários. 
    */
    public static void main(String[] args) throws Exception {
        final int TAM = 2;
        Scanner resposta = new Scanner(System.in);
        File arquivo = new File("Exercícios/src/aula8/Arquivo.txt");
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();

        if (arquivo.exists()) {
            // Lê a lista de arquivos
            funcionarios = (ArrayList<Funcionario>) load("Exercícios/src/aula8/Arquivo.txt");
        } else {
            // Registra uma lista de funcionários
            for (int tempo = 0; tempo < TAM; tempo++) {
                Funcionario func = new Funcionario();
                System.out.println("Insira o nome do funcionário.");
                func.setNome(resposta.next());
                System.out.println("Insira o salário do funcionário.");
                func.setSalario(resposta.nextDouble());
                funcionarios.add(func);
            }

            ordenarPorSalario(funcionarios);
            save(funcionarios);
        }
        System.out.println(funcionarios);

        resposta.close();
    }

    public static void save(Object obj) throws IOException {
        ObjectOutputStream save = new ObjectOutputStream(new FileOutputStream("Exercícios/src/aula8/Arquivo.txt"));
        save.writeObject(obj);
        save.close();
    }
    public static Object load(String arquivo) throws Exception {
        ObjectInputStream load = new ObjectInputStream(new FileInputStream(arquivo));
        Object func = load.readObject();
        load.close();
        return func;
    }

    //2- Crie uma nova classe que leia a lista de funcionários, ordene em ordem crescente do salário e imprima no console essa lista ordenada.
    public static void ordenarPorSalario(ArrayList<Funcionario> lista) {
        Collections.sort(lista);
    }
}
