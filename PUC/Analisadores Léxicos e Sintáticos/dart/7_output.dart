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
  if (umidade < 40) {
    for (String deviceName in ["Monitor"]) {
      alerta(deviceName, "Ar seco detectado", null.toString());
    }
  }
}
