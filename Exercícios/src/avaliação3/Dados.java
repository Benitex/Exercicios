package avaliação3;

import java.util.ArrayList;

public class Dados {
    public static ArrayList<Cachorro> getDados() {
        ArrayList<Cachorro> listaCachorros = new ArrayList<Cachorro>();

        Cachorro c = new Cachorro();
        c.setIdade(10);
        c.setNome("nome");
        listaCachorros.add(c);
        
        Cachorro c2 = new Cachorro("Alfredo", 12, 30);
        listaCachorros.add(c2);

        Cachorro c3 = new Cachorro("Godofredo", 6, 20);
        listaCachorros.add(c3);

        return listaCachorros;
    }
}
