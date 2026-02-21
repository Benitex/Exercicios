import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:qr_code_generator/models/qr_code_details.dart';

final qrCodesProvider = NotifierProvider<QrCodesNotifier, List<QrCodeDetails>>(QrCodesNotifier.new);

class QrCodesNotifier extends Notifier<List<QrCodeDetails>> {
  @override
  List<QrCodeDetails> build() => [];

  void add(QrCodeDetails qrCode) {
    state = [...state, qrCode];
  }

  void remove(QrCodeDetails qrCode) {
    state = [
      for (QrCodeDetails currentQrCode in state)
        if (currentQrCode != qrCode) currentQrCode,
    ];
  }
}
