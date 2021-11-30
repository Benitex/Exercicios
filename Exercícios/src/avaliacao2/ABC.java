package avaliacao2;
import java.util.ArrayList;

public class ABC {
    public static double calculaMedia(ArrayList g, int cargo) {
        double numFuncionarios = 0;
        double somaSalarios = 0;
        for (int tempo = 0; tempo < g.size(); tempo++) {
            String funcionario = (String) g.get(tempo);
            String[] f = funcionario.split("#");
            if (Integer.parseInt(f[1]) == cargo) {
                numFuncionarios++;
                somaSalarios += Double.parseDouble(f[2]);
            }
        }
        return somaSalarios/numFuncionarios;
    }
}