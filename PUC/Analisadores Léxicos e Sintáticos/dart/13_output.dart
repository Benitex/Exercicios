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
  dynamic temperatura = 0;
  dynamic umidade = 0;
  dynamic velocidade = 0;
  if (umidade != 50 && temperatura > 25 && velocidade < 1) {
    ligar("Ventilador");
  }
}
