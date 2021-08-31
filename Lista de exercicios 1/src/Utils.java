import java.lang.Math;

public class Utils{
    static double calculaMedia(double x,double y){
        return (x+y)/2;
    }
    static double calculaMedia(double x, double y, double z){
        return (x+y+z)/3;
    }
    static double calculaMedia(double a, double b, double c, double d){
        return (a+b+c+d)/4;
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