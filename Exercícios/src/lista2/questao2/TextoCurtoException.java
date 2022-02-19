/* Crie  também  a  classe  dessa exceção.  Quando  essa  exceção  for  lançada,  deve  ser  
passada  uma  mensagem  para  o construtor dela, informando quantos caracteres possui o “texto” 
inserido pelo usuário. Ex: texto inserido com 4 caracteres. */

package lista2.questao2;

public class TextoCurtoException extends Exception {
    public TextoCurtoException(int numeroDeLetras) {
        System.out.println("Texto inserido com " + numeroDeLetras +  " caracteres");
    }
}
