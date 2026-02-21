import 'package:flutter/material.dart';
import 'package:qr_code_generator/models/qr_code_details.dart';

class QrCode extends StatelessWidget {
  const QrCode({super.key, required this.qrCode});

  final QrCodeDetails qrCode;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(qrCode.name)),

      body: qrCode.image,
    );
  }
}
