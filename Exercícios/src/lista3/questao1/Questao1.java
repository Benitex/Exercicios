/* C2- Crie um programa (classe) principal que receba do console o id de um Produto. Em seguida, 
verifique, com base no código desenvolvido no item B1, se o Produto existe na lista retornada por 
Utils2.getLista().  Caso  sim,  exiba  no  console  o  id,  cor  e  preço  do  Produto  existente  na  lista 
retornada ao invocar o método Utils2.getLista(). */

package lista3.questao1;

import java.util.List;
import java.util.Scanner;

public class Questao1 {
    public static void main(String[] args) {
        Scanner resposta = new Scanner(System.in);
        List<Object> lista = Utils2.getLista();
        System.out.println("Insira o id do produto.");
        Produto produtoAVerificar = new Produto(resposta.nextLine());
        resposta.close();

        if (Utils.existe(lista, produtoAVerificar)) {
            for (int tempo = 0; tempo < lista.size(); tempo++) {
                if (lista.get(tempo) instanceof Produto) {
                    Produto prod = (Produto) lista.get(tempo);  
                    if (prod.equals(produtoAVerificar)) {
                        System.out.println(prod);
                    } 
                }
            }
        }
    
    }

    /* C3 – Ainda na classe principal, crie um método denominado transformaListEmArray que receba 
    uma lista k de objetos (de diversos tipos (ex: Elefante, Carro, Conta), incluindo Produtos) e retorna 
    um array de Produtos, contendo os objetos do tipo Produto na lista representada por k. O array 
    DEVE ter o comprimento do número de Produtos em k. Ex: se em k existem 10 Produtos e 15 
    Carros, o array DEVE ter tamanho 10 e estar preenchido com os 10 Produtos. */
    public static Produto[] transformaListEmArray(List<Object> k) {
        int numeroDeProdutos = 0, tempo = 0;

        for (Object object : k) {
            if (object instanceof Produto) {
                numeroDeProdutos++;
            }
        }
        Produto [] produtos = new Produto[numeroDeProdutos];

        for (Object object : k) {
            if (object instanceof Produto) {
                produtos[tempo] = (Produto) object;
                tempo++;
            }
        }

        return produtos;
    }

    // D – Em seguida, crie um método para retornar a soma de todos os preços no array de Produtos criado no item C3. 
    public static double somarPrecos(Produto[] produtos) {
        double soma = 0;
        for (Produto produto : produtos) {
            soma += produto.getPreco();
        }

        return soma;
    }
}
