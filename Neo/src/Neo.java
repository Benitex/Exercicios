public class Neo {
    public static void main(String[] args) {
        Pokemon p1 = new Pokemon();
        p1.nivel=5;
        p1.nome="Turtwig";

        System.out.println("Nome do pokemon: "+p1.nome);
        p1.ataque();
    }
}