package aula7;

import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

public class Parte1 {
    public static void main(String[] args) {
        HashSet conjunto = new HashSet();
        conjunto.add(9);
        conjunto.add(5);
        conjunto.add(7);
        System.out.println(mediaIdades(conjunto));
    }

    public static double mediaIdades(Set conjunto) {
        double media = 0;
        Iterator seta = conjunto.iterator();
        while (seta.hasNext()) {
            media += (double) seta.next();
            /* Código utilizando Pessoa, não utilizado por não haver HashCode
            Pessoa x = (Pessoa) seta.next();
            media += x.getIdade();
            */
        }
        return (double)media/conjunto.size();
    }
}