/* B2- Crie 1 subclasse da classe Produto: Notebook.  Faça essa classe implementar a interface 
Eletronico. */

package lista3.questao1;

public class Notebook extends Produto implements Eletronico {
    public Notebook(String id) {
        super(id);
    }

    @Override
    public void ligar() {
    }
    @Override
    public void desligar() {
    }
}
