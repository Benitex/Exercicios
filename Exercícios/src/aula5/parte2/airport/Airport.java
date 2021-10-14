package aula5.parte2.airport;
import aula5.parte2.flyers.*;
import java.lang.Math;

public class Airport {
    private String nome;  
    public static void main(String[] args){
        Airport metropolisAirport = new Airport();
        metropolisAirport.nome = "Galeão";
        Helicopter copter = new Helicopter();
        SeaPlane sPlane = new SeaPlane();

        metropolisAirport.givePermissiontoLand(copter);
        metropolisAirport.givePermissiontoLand(sPlane);
        decolar(retornaAleatório());
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    private void givePermissiontoLand(Flyer f) {
        System.out.println("Aeroporto ["+nome+"] vai dar permissão para pouso.");
        f.land();
    }
    public static Airplane[] retornaAleatório() {
        int numeroAeronaves = (int)(Math.random() * 101);
        int totalAeronaves = numeroAeronaves;
        numeroAeronaves = 0;
        Airplane[] aeronaves = new Airplane[totalAeronaves];
        while(numeroAeronaves < totalAeronaves){
            if (alea() != 0)
                aeronaves[numeroAeronaves] = new Helicopter();
            else
                aeronaves[numeroAeronaves] = new SeaPlane();
            numeroAeronaves++;
        }
        return aeronaves;
    }
    public static int alea(){
        return (int)(Math.random() * 2);
    }
    public static void decolar(Airplane[] aeronaves) {
        for (int tempo = 0; tempo < aeronaves.length; tempo++) {
            if (aeronaves[tempo] instanceof Helicopter){
                Helicopter copter = (Helicopter) aeronaves[tempo];
                copter.ligarHelice();
            }else if (aeronaves[tempo] instanceof SeaPlane){
                SeaPlane sPlane = (SeaPlane) aeronaves[tempo];
                sPlane.ligarTurbinas();
            }
            aeronaves[tempo].takeOff();
        }
    }
}