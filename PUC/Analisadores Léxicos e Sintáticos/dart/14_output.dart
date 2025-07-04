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
  dynamic temFiltroDeAgua = 0;
  dynamic temChip = 0;
  temFiltroDeAgua = true;
  temChip = true;
  if (temFiltroDeAgua && temChip) {
    for (String deviceName in ["Celular"]) {
      alerta(deviceName, "teste", null.toString());
    }
  }
}
