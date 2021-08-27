public class Cobra {
    boolean vivo;
    private String cor,nome;
    private int idade;

    public Cobra() {
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

    public void sibilar() {
        System.out.println("Cobra sibilando");
    }
}