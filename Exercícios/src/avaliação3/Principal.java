package avaliação3;

import java.util.List;
import java.util.Collections;

public class Principal {
    public static void main(String[] args) {
        List listaCachorros = Dados.getDados();
        Collections.sort(listaCachorros);
        for (int i=0; i<listaCachorros.size(); i++) {
            System.out.println(listaCachorros.get(i));
        }
    }
}
