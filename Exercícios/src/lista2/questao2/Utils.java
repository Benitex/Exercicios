package lista2.questao2;

import java.util.ArrayList;

public class Utils {
    /*
    Esse método é responsável por verificar se o texto (variável “texto“) tem menos de 10 caracteres 
    e, caso tenha, deve lançar uma  exceção  checked  denominada  TextoCurtoException.  
    */
    public static void verifica(String texto) {
        if (texto.length() < 10) {
            throw new TextoCurtoException(texto.length());
        }
    }

    /*
    Em seguida, crie o método Utils.moderar(String texto): String. Esse método deve substituir 
    todos os palavrões encontrados em “texto” por “####” -> Cada caractere do palavrão deve ser 
    substituído por um caractere #. Ou seja, se o palavrão tiver 6 caracteres, o palavrão no texto 
    deverá ser substituído por ######.
    */
    public static String moderar(String texto) {
        String[] palavras = texto.split(" ");
        ArrayList<String> palavroes = (ArrayList<String>) Utilidades.getPalavroes();
        for (String palavra : palavras) {
            for (String palavrao : palavroes) {
                if (palavra.equalsIgnoreCase(palavrao)) {
                    char[] letras = palavra.toCharArray();
                    for (char letra : letras) {
                        letra = '#';
                    }
                }
            }
        }

        String textoModerado = "";
        for (String palavra : palavras) {
            textoModerado += palavra;
        }
        return textoModerado;
    }
}
