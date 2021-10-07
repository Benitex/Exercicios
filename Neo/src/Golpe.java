public class Golpe {
    private int poder, quantidadeStatus;
    private String status;
    private boolean dano = false, oponente = false, neleMesmo = false, reducaoStatus = false, buffStatus = false;

    public Golpe(String nome){
        if (nome.equalsIgnoreCase("Tackle")){
            poder = 40;
            dano = true;
        }
        if (nome.equalsIgnoreCase("Tail Whip")){
            reducaoStatus = true;
            status = "Defesa";
            quantidadeStatus = 1;
            oponente = true;
        }
        if (nome.equalsIgnoreCase("Withdraw")){
            buffStatus = true;
            status = "Defesa";
            quantidadeStatus = 1;
            neleMesmo = true;
        }
    }

    public int getPoder(){
        return poder;
    }
    public boolean getDano(){
        return dano;
    }
    public boolean getOponente(){
        return oponente;
    }
    public boolean getNeleMesmo(){
        return neleMesmo;
    }
    public boolean getReducaoStatus(){
        return reducaoStatus;
    }
    public boolean getBuffStatus(){
        return buffStatus;
    }

    public void reducaoStatus(Pokemon p, Golpe golpe){
        if (golpe.status.equalsIgnoreCase("Defesa"))
            p.setDefesa((int)(p.getDefesa() * (1 - (golpe.quantidadeStatus * 0.2))));
    }
    public void buffStatus(Pokemon p, Golpe golpe){
        if (golpe.status.equalsIgnoreCase("Defesa"))
            p.setDefesa((int)(p.getDefesa() * (1 + (golpe.quantidadeStatus * 0.2))));
    }
}