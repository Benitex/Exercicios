void ligar(String namedevice) {
  print("$namedevice ligado!");
}

void desligar(String namedevice) {
  print("$namedevice desligado!");
}

void alerta(String namedevice, String msg, [String? observation]) {
  print("$namedevice recebeu o alerta:");
  if (observation == null) {
    print(msg);
  } else {
    print("$msg $observation");
  }
}

void main() {
  dynamic umidade = 0;
  dynamic estaLigada = 0;
  umidade = 50;
  estaLigada = false;
  if (umidade < 40 && estaLigada) {
    desligar("Lampada");
  }
}
