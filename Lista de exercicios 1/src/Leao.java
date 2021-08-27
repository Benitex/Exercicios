public class Leao {
    boolean vivo;
    private String cor,nome;
    private int idade;

    public Leao() {
    }

    public void setCor(String novaCor) {
        cor=novaCor;
    }
    public String getCor() {
        return cor;
    }
    public void setNome(String novoNome) {
        nome=novoNome;
    }
    public String getNome() {
        return nome;
    }
    public void setIdade(int novaIdade) {
        idade = novaIdade;
    }
    public int getIdade() {
        return idade;
    }

    public void rugir() {
        System.out.println("Leao rugindo");
    }
}