package aula7;

public class ContaCorrente {
    private double saldo;

    public double getSaldo() {
        return saldo;
    }
    public void deposita(double valor) {
        saldo += valor;
    }
}
