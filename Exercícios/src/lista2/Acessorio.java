/*
1.1 – Crie uma classe chamada Acessorio. Essa classe terá diversas subclasses, não permita 
a criação de objetos da classe Acessorio. Essa classe possui apenas dois atributos (marca e 
preço).  Utilize  os  tipos  apropriados.  Crie  os  gettars  e  setters.  Crie  um  método  chamado 
"calcularImpostoRenda"  que  retorne  um  double.  Crie  esse  método  de  maneira  que  todas  as 
subclasses  de  Acessorio  sejam  obrigadas  a  implementar  esse  método.  Crie  apenas  um  construtor 
em Acessorio. Esse construtor deve receber a marca e o preço.
*/

package lista2;

public abstract class Acessorio {
    private double preco;
    private String marca;

    public Acessorio(double preco, String marca) {
        this.preco = preco;
        this.marca = marca;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }
    public double getPreco() {
        return preco;
    }
    public void setMarca(String marca) {
        this.marca = marca;
    }
    public String getMarca() {
        return marca;
    }

    public double calcularImpostoRenda() {
        return 0;
    }
}
