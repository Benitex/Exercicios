package aula7;

import java.util.Map;
import java.util.HashMap;

public class Parte2 {

    public static void main(String[] args) {
        ContaCorrente c1 = new ContaCorrente();
        c1.deposita(10000);

        ContaCorrente c2 = new ContaCorrente();
        c2.deposita(3000);

        // cria o mapa
        Map mapaDeContas = new HashMap();

        // adiciona duas chaves e seus respectivos valores
        mapaDeContas.put("diretor", c1);
        mapaDeContas.put("gerente", c2);
        
        // qual a conta do diretor?
        ContaCorrente contadoDiretor = (ContaCorrente) mapaDeContas.get("diretor");
        System.out.println(contadoDiretor.getSaldo());
    }
}