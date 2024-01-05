/* 1.4 – Crie uma classe principal que seja responsável por criar uma lista de carros. Crie dois 
carros e insira na lista. Em cada carro, adicione um Acessorio Som e um Acessorio 
VidroEletrico. */

package lista2.questao1;

import java.util.ArrayList;

public class Questao1 {
    public static void main(String[] args) {
        ArrayList<Carro> carros = new ArrayList<Carro>();

        Carro carro1 = new Carro();
        carro1.setPlaca("123");
        carro1.adicionarAcessorio(new Som(1100, "Marca Top"));
        carro1.adicionarAcessorio(new VidroEletrico(5000, "Marca Top"));
        carros.add(carro1);

        Carro carro2 = new Carro();
        carro2.setPlaca("987");
        carro2.adicionarAcessorio(new Som(100, "Marca Terrível"));
        carro2.adicionarAcessorio(new VidroEletrico(10, "Vidros Inquebráveis"));
        carros.add(carro2);

        System.out.println(carros);
        Utils2.imprimirCustos(carros);
        System.out.println(Utils2.transformaListaEmMapa(carros));
    }
}
