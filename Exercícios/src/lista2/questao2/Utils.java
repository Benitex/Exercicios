package lista2.questao2;

import java.util.HashSet;

public class Utils {
    /* Esse método é responsável por verificar se o texto (variável “texto“) tem menos de 10 caracteres 
    e, caso tenha, deve lançar uma  exceção  checked  denominada  TextoCurtoException. */
    public static void verifica(String texto) throws TextoCurtoException {
        if (texto == null || texto.length() < 10) {
            throw new TextoCurtoException("Texto inserido com " + texto.length() +  " caracteres");
        }
    }

    /* Em seguida, crie o método Utils.moderar(String texto): String. Esse método deve substituir 
    todos os palavrões encontrados em “texto” por “####” -> Cada caractere do palavrão deve ser 
    substituído por um caractere #. Ou seja, se o palavrão tiver 6 caracteres, o palavrão no texto 
    deverá ser substituído por ######. */
    public static String moderar(String texto) {
        HashSet<String> palavroes = (HashSet<String>) Utilidades.getPalavroes();
        String[] palavras = texto.split(" ");
        texto = "";

        for (String palavra : palavras) {
            if (palavroes.contains(palavra.toLowerCase())) {
                char[] letras = palavra.toCharArray();
                palavra = "";

                for (char letra : letras) {
                    letra = '#';
                    palavra += letra;
                }
            }

            if (texto.length() == 0) {
                texto += palavra;
            } else {
                texto += " " + palavra;
            }
        }

        return texto;
    }
}
