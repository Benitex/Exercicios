package aula5.parte4;

import java.util.ArrayList;

public class Principal {
    public static void main(String args[]) {
        ArrayList<Object> lista = new ArrayList<>();
        Urso ursaring = new Urso();
        Carro tesla = new Carro();
        Doce bala =  new Doce();
        lista.add(ursaring);
        lista.add(tesla);
        lista.add(bala);
        corre(lista);
    }
    public static void corre(ArrayList<Object> lista){
        for (int tempo = 0; tempo < lista.size(); tempo++) {
            if (lista.get(tempo) instanceof Corredor){
                Corredor corredor = (Corredor) lista.get(tempo);
                corredor.correr();
            }
        }
    }
}
