package aula8;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;

public class Exercicio {
    /*
    1 – Crie um sistema que contenha algumas classes, como desejar. No entanto, crie 
    obrigatoriamente uma classe denominada Funcionario com os atributos privados 
    nome e salário. Crie os gets e sets. Receba do console nomes e funcionários de sua 
    empresa a armazene em uma estrutura adequada. Serialize a lista de funcionários. 
    */
    public static void main(String[] args) throws Exception {
        //ArrayList<Funcionario> lista = (ArrayList<Funcionario>) load("Exercícios/src/aula8/Arquivo.txt");
        //System.out.println(lista);
        
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();

        Funcionario func = new Funcionario();
        func.setNome("João");
        func.setSalario(500);
        funcionarios.add(func);

        Funcionario func2 = new Funcionario();
        func2.setNome("Enzo");
        func2.setSalario(20);
        funcionarios.add(func2);

        ordenarPorSalario(funcionarios);
        System.out.println(funcionarios);
        save(funcionarios);
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
