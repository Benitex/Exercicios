/*
Observe a classe abaixo e sobrescreva o método equals (de object) em Quadrado (considerando o local marcado com um //equals) da seguinte maneira: 
dois Quadrados são iguais se suas alturas (alt) e larguras (larg) forem iguais. 
Dessa maneira, se (i) um Quadrado referenciado por A possui altura 2 e largura 3; 
(ii) um Quadrado referenciado por B possui altura 2 e largura 3; 
(c) a chamada a A.equals(B) deve retornar true. Caso contrário, deve retornar false. 
*/
package avaliacao2;

public class Quadrado {
	private double alt;
	private double larg;
	public double getAlt() {
		return alt;
	}
	public void setAlt(double alt) {
		this.alt = alt;
	}
	public double getLarg() {
		return larg;
	}
	public void setLarg(double larg) {
		this.larg = larg;
	}
    
    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (obj == this) {
            return true;
        }
        if (obj instanceof Quadrado) {
            Quadrado x = (Quadrado) obj;
            if (x.alt == this.alt && x.larg == this.larg) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}