/* B1 – Escreva uma classe Produto com 3 atributos: id (String), cor (String) e preco (double). 
Crie os getters e setters apenas se precisar. Crie em Produto APENAS UM construtor que recebe o id 
como argumento. */

package lista3.questao1;

public class Produto {
    private String id, cor;
    private double preco;

    public Produto(String id) {
        this.id = id;
    }
    public double getPreco() {
        return preco;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        } else if (obj == this) {
            return true;   
        } else if (!(obj instanceof Produto)) {
            return false;
        } else {
            Produto prod = (Produto) obj;
            if (prod.id.equals(this.id)) {
                return true;
            } else {
                return false;
            }
        }
    }

    /* B1.5 – Dado que b é uma referência a um objeto do tipo Produto, implemente o código que faz com 
    que, caso essa referência seja impressa com o System.out.println, seja apresentado no console o 
    id, cor e preço do produto no seguinte formato: [id – cor - preco]. Ex: [COD001 - amarelo -  3000.67]. */
    @Override
    public String toString() {
        return id + " - " + cor + " - " + preco;
    }
}
