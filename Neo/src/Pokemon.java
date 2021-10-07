public class Pokemon {
    private int vida, ataque, defesa, speed;
    private String especie, golpe[]={"-","-","-","-"};
    private String tipo[] = new String[2];
    
    public Pokemon(String especie){
        this.especie = especie;
        if (especie.equalsIgnoreCase("Turtwig")){
            vida = 55;
            ataque = 68;
            defesa = 64;
            speed = 55;
            tipo[0] = "Grass";
            golpe[0] = "Tackle";
            golpe[1] = "Growl";
        }else if (especie.equalsIgnoreCase("Bulbasaur")){
            vida = 45;
            ataque = 49;
            defesa = 49;
            speed = 65;
            tipo[0] = "Grass";
            tipo[1] = "Poison";
            golpe[0] = "Tackle";
            golpe[1] = "Withdraw";
        }
    }

    public void setVida(int vida){
        this.vida = vida;
    }
    public void setDefesa(int defesa){
        this.defesa = defesa;
    }
    public int getVida(){
        return vida;
    }
    public int getDefesa(){
        return defesa;
    }
    public int getSpeed(){
        return speed;
    }
    public String getEspecie(){
        return especie;
    }
    public void getGolpe(String golpe[]){
        for (int tempo = 0; tempo < golpe.length; tempo++) {
            golpe[tempo] = this.golpe[tempo];
        }
    }

    public void atacar(Pokemon atacante, Pokemon atacado, String golpeEscolhido){
        Golpe definiçõesGolpe = new Golpe(golpeEscolhido);
        System.out.println(especie+" utilizou "+golpeEscolhido);
        if (definiçõesGolpe.getDano() == true)
            atacado.vida -= ataque + definiçõesGolpe.getPoder() - atacado.defesa;
        if (definiçõesGolpe.getOponente() == true){
            if (definiçõesGolpe.getReducaoStatus() == true)
                definiçõesGolpe.reducaoStatus(atacado,definiçõesGolpe);
            if (definiçõesGolpe.getBuffStatus() == true)
                definiçõesGolpe.buffStatus(atacado,definiçõesGolpe);
        }
        if (definiçõesGolpe.getNeleMesmo() == true){
            if (definiçõesGolpe.getReducaoStatus() == true)
                definiçõesGolpe.reducaoStatus(atacante,definiçõesGolpe);
            if (definiçõesGolpe.getBuffStatus() == true)
                definiçõesGolpe.buffStatus(atacante,definiçõesGolpe);
        }
    }
}