public class Neo {
    public static void main(String[] args) {
        Pokemon p1 = new Pokemon();
        p1.nome="Turtwig";
        p1.definirEspécie();

        Pokemon p2 =new Pokemon();
        p2.nome="Bulbassaur";
        p2.definirEspécie();

        while (p1.vida>=0||p2.vida>=0){
            p1.ataque (p2.vida);
            p2.ataque(p1.vida);
            System.out.println("Vida de "+p1.nome+": "+p1.vida);
            System.out.println("Vida de "+p2.nome+": "+p2.vida);
        }
    }
}