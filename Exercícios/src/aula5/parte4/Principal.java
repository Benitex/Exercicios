package aula5.parte4;

import java.util.ArrayList;

public class Principal {
    public static void main(String args[]) {
        ArrayList lista = new ArrayList();
        Urso ursaring = new Urso();
        Carro tesla = new Carro();
        Doce bala =  new Doce();
        lista.add(ursaring);
        lista.add(tesla);
        lista.add(bala);
        corre(lista);
    }
    public static void corre(ArrayList lista){
        Urso urso = new Urso();
        Carro carro = new Carro();
        for (int tempo = 0; tempo < lista.size(); tempo++) {
            Corredor corredor = (Corredor) lista.get(tempo);
            if (corredor.equals(urso)||corredor.equals(carro)) {
                corredor.correr();
            }
        }
    }
}
