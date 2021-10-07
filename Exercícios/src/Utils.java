import java.lang.Math;

public class Utils{
    static double calculaMedia(double[] array) {
        int tempo;
        double soma = 0;
        for (tempo = 0; tempo < array.length; tempo++) {
            soma += array[tempo];
        }
        return soma/tempo;
    }

    static void bhaskara(float a, float b, float c) {
        float delta = ((b*b)-(4*a*c));
        if (delta<0)
            System.out.println("Raízes imaginárias.");
        else if (delta==0)
            System.out.println("Raiz única = "+(((-b+Math.pow(delta,0.5)))/(2*a)));
        else
            System.out.println("Raizes distintas. x1 = "+(((-b+Math.pow(delta,0.5)))/(2*a))+" e x2= "+((-b-Math.pow(delta,0.5)))/(2*a));
    }
}