/*
Observe a classe abaixo. Escreva o código que deve ser incluído para substituir o comentário //código. 

O ArrayList referenciado por g conterá Strings no formato codigo#cargo#salário que representam o código de funcionários, 
um caractere que sempre será # e em seguida, o código do cargo do funcionário (1,2,3,4, etc...). 
Depois disso, virá novamente um caractere que sempre será # seguido do salário dos funcionários.

Observe agora o método calculaMedia da classe ABC. O parâmetro cargo, indica qual o código do cargo do funcionário que será 
usado para calcular a média dos salários. Ao invocar o calculaMedia com o código fonte da classe DataBase, apenas os funcionários 
com código 1234 e 4343 devem ser utilizados para calcular a média do salário, dado que eles são os únicos que possuem o código 1, 
conforme invocado em calculaMedia(m, 1); Ou seja, o segundo parâmetro do método calcularMedia recebe o código do cargo que será 
utilizado para calcular as médias dos salários. Apenas funcionários com esse código de cargo serão considerados para calcular a média. 
Escreva APENAS o código que deve ser inserido no método calculaMedia. Como informativo, os códigos 1, 2, 3, etc, 
são códigos referentes aos tipos dos funcionários (analista, gerente, etc.). O método calculaMedia deve retornar a média calculada. 
Considere que podem ser passados ArrayLists nesse mesmo formato contendo centenas de valores, ou seja, 
não considere que serão apenas os 4 elementos inseridos no ArrayList pela classe DataBase.
*/
package avaliacao2;
import java.util.ArrayList;

public class DataBase {
	public static void main(String[] args) {
		ArrayList m = new ArrayList();
		m.add("1234#1#1000");
		m.add("553742#3#2000");
		m.add("12#2#1300");
		m.add("4343#1#4020");
		double med = ABC.calculaMedia(m, 1); //essa chamada deve calcular a média dos salários dos funcionários com código do cargo = 1.
        System.out.println(med);
	}
}