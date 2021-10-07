package br.com.lojavirtual.main;

import br.com.lojavirtual.informatica.Teclado;

public class TesteSistema {
    public static void main(String args[]){
        Teclado tc = new Teclado();
        tc.setQtdTeclas(102);
        tc.setUSB(true);
    }
}