/*
1.3 – Modifique a classe Carro adicionando uma lista de acessórios. A lista DEVE ser privada. 
Essa  lista  conterá  os  acessórios  que  o  carro  vai  ter.  Não  amarre  o  sistema.  Crie  mais  métodos  se 
necessário (não precisa reescrever a classe carro toda, só a declaração da classe e o que for inserir 
a mais, além do que já aparece na figura).
*/

package lista2.questao1;

import java.util.ArrayList;

public class Carro {
    private String placa, cor, renavan;
    private int ano;
    private ArrayList<Acessorio> acessorios = new ArrayList<Acessorio>();

    public void setPlaca(String placa) {
        this.placa = placa;
    }
    public String getPlaca() {
        return placa;
    }
    public void setCor(String cor) {
        this.cor = cor;
    }
    public String getCor() {
        return cor;
    }
    public void setRenavan(String renavan) {
        this.renavan = renavan;
    }public String getRenavan() {
        return renavan;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }
    public int getAno() {
        return ano;
    }
    public void setAcessorios(ArrayList<Acessorio> acessorios) {
        this.acessorios = acessorios;
    }
    public ArrayList<Acessorio> getAcessorios() {
        return acessorios;
    }

    public void adicionarAcessorio(Acessorio acessorio) {
        acessorios.add(acessorio);
    }
}
