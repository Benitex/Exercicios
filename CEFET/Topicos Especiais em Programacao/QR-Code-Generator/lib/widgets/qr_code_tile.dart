import 'package:flutter/material.dart';
import 'package:qr_code_generator/models/qr_code_details.dart';
import 'package:qr_code_generator/screens/qr_code.dart';

class QrCodeTile extends StatelessWidget {
  const QrCodeTile({super.key, required this.qrCode});

  final QrCodeDetails qrCode;

  @override
  Widget build(BuildContext context) {
    return ListTile(
      leading: Icon(Icons.text_fields),
      title: Text(qrCode.name),
      onTap: () => Navigator.of(context).push(
        MaterialPageRoute(builder: (context) => QrCode(qrCode: qrCode)),
      ),
    );
  }
}
