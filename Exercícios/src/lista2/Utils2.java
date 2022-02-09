/*
1.5 – Crie uma classe chamada Utils2 que possua apenas um método estático sem retorno: 
imprimirCustos. Esse método receberá a lista de carros. Imprima o total do preço de todos os 
acessórios de todos os carros e o total de imposto de renda de todos os acessórios de todos 
os carros.
*/

package lista2;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

public class Utils2 {
    public static void imprimirCustos(ArrayList<Carro> carros) {
        double precoAcessorios = 0, precoImpostos = 0;
        for (Carro carro : carros) {
            for (Acessorio acessorio : carro.getAcessorios()) {
                precoAcessorios += acessorio.getPreco();
                precoImpostos += acessorio.calcularImpostoRenda();
            }
        }
        System.out.println("Acessórios custam: " + precoAcessorios + "Impostos são: " + precoImpostos);
    }

    /*
    1.6 – Crie um método, também em Utils2 denominado transformaListaEmMapa(List carros): Map que
    recebe uma lista de carros e retorna um mapa, em que as “chaves” são as placas dos carros e os
    “valores” são os objetos do tipo carro. Não modifique a assinatura do método. Utilize o itetator nessa
    questão.
    */
    public static Map<String, Carro> transformaListaEmMapa(List carros) {
        Map<String, Carro> mapaDeCarros = new HashMap<String, Carro>();
        Iterator<Carro> iterator = carros.iterator();
        while (iterator.hasNext()) {
            Carro carro = iterator.next();
            mapaDeCarros.put(carro.getPlaca(), carro);
        }
        return mapaDeCarros;
    }
}
