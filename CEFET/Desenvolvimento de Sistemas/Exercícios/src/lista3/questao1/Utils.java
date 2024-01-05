/* Em seguida, crie uma classe chamada Utils e implemente um método em Utils com a seguinte assinatura: 
public static boolean existe (List x, Produto y); considere que a lista 
possui objetos do tipo Produto, mas podendo possuir objetos de outros tipos. Escreva esse método 
de  forma  que  seja  verificada  a  existência  do  objeto  Produto  representado  por  y  na  lista 
representada por x; retorne verdadeiro se o objeto existir na lista e falso se não existir. Considere 
que dois objetos Produto são iguais se possuem o mesmo id. Não é permitida qualquer iteração 
para realizar esse item, ou seja, não use for, iterator, etc. */

package lista3.questao1;

import java.util.List;

public class Utils {
    public static boolean existe(List x, Produto y) {
        return x.contains(y);
    }
}
