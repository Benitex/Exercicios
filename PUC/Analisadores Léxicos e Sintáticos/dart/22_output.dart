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
  for (String deviceName in ["Termometro"]) {
    alerta(deviceName, " Temperatura esta em", temperatura.toString());
  }
}
