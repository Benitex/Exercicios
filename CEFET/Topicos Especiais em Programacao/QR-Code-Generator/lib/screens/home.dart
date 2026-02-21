import 'package:flutter/material.dart';
import 'package:qr_code_generator/models/qr_code_details.dart';
import 'package:qr_code_generator/widgets/new_qr_code_dialog.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:qr_code_generator/providers/qr_codes_provider.dart';
import 'package:qr_code_generator/widgets/qr_code_tile.dart';

class Home extends ConsumerWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final qrCodes = ref.watch(qrCodesProvider);

    return Scaffold(
      appBar: AppBar(title: const Text("QR Code Generator")),

      body: ListView(
        padding: const EdgeInsets.all(12),
        children: (qrCodes.isNotEmpty) ? [
          for (QrCodeDetails qrCode in qrCodes)
            QrCodeTile(qrCode: qrCode),
        ] : const [Text("No QR Codes registered yet!")],
      ),

      floatingActionButton: FloatingActionButton(
        onPressed: () => showDialog(
          context: context,
          builder: (context) => NewQrCodeDialog(),
        ),
        child: const Icon(Icons.add),
      ),
    );
  }
}
