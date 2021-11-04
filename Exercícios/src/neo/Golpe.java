package neo;

public class Golpe {
    private int poder, quantidadeStatusAlterado;
    private String statusAlterado, nome;
    private boolean dano = false, oponente = false, neleMesmo = false, reducaoStatus = false, buffStatus = false;

    public Golpe(String nome){
        this.nome = nome;
        if (nome.equalsIgnoreCase("Tackle")){
            poder = 40;
            dano = true;
        }
        if (nome.equalsIgnoreCase("Tail Whip")){
            reducaoStatus = true;
            statusAlterado = "Defesa";
            quantidadeStatusAlterado = 1;
            oponente = true;
        }
        if (nome.equalsIgnoreCase("Withdraw")){
            buffStatus = true;
            statusAlterado = "Defesa";
            quantidadeStatusAlterado = 1;
            neleMesmo = true;
        }
    }

    public String getNome(){
        return nome;
    }
    public int getPoder(){
        return poder;
    }
    public boolean isDano(){
        return dano;
    }
    public boolean isOponente(){
        return oponente;
    }
    public boolean isNeleMesmo(){
        return neleMesmo;
    }
    public boolean isReducaoStatus(){
        return reducaoStatus;
    }
    public boolean isBuffStatus(){
        return buffStatus;
    }

    public void reduzirStatus(Pokemon p){
        if (this.statusAlterado.equalsIgnoreCase("Defesa"))
            p.setDefesa((int)(p.getDefesa() * (1 - (this.quantidadeStatusAlterado * 0.2))));
    }
    public void buffarStatus(Pokemon p){
        if (this.statusAlterado.equalsIgnoreCase("Defesa"))
            p.setDefesa((int)(p.getDefesa() * (1 + (this.quantidadeStatusAlterado * 0.2))));
    }

    public String toString(){
        return this.nome;
    }
}