import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:qr_code_generator/models/qr_code_details.dart';
import 'package:qr_code_generator/providers/qr_codes_provider.dart';
import 'package:qr_flutter/qr_flutter.dart';

class NewQrCodeDialog extends ConsumerWidget {
  NewQrCodeDialog({super.key});

  final formKey = GlobalKey<FormState>();
  final TextEditingController nameFieldController = TextEditingController();
  final TextEditingController dataFieldController = TextEditingController();

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    var qrCodesNotifier = ref.read(qrCodesProvider.notifier);

    return AlertDialog(
      title: const Text("Add new QR Code"),

      content: Form(key: formKey,
        child: Column(children: [
          TextFormField(
            controller: nameFieldController,
            validator: (value) {
              if (value == null || value.isEmpty) {
                return "This field is required";
              }
              return null;
            },
            decoration: const InputDecoration(hintText: "Name"),
          ),

          TextFormField(
            controller: dataFieldController,
            validator: (value) {
              if (value == null || value.isEmpty) {
                return "This field is required";
              }
              return null;
            },
            decoration: const InputDecoration(hintText: "Address, phone number, etc."),
          ),
        ]),
      ),

      actions: [
        TextButton(
          onPressed: () => Navigator.of(context).pop(),
          child: const Text("Cancel"),
        ),

        Consumer(builder: (context, ref, child) => TextButton(
          onPressed: () {
            if (!formKey.currentState!.validate()) return;

            qrCodesNotifier.add(
              QrCodeDetails(
                name: nameFieldController.text,
                image: QrImageView(data: dataFieldController.text),
              ),
            );

            Navigator.of(context).pop();
          },
          child: const Text("Save"),
        )),
      ],
    );
  }
}
