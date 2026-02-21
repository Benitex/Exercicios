import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:qr_code_generator/screens/home.dart';

void main() => runApp(
  const ProviderScope(child: QrCodeGenerator())
);

class QrCodeGenerator extends StatelessWidget {
  const QrCodeGenerator({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: const Home(),
      theme: ThemeData().copyWith(
        appBarTheme: ThemeData.dark().appBarTheme.copyWith(
          backgroundColor: ThemeData().colorScheme.primary,
        ),
      ),
      debugShowCheckedModeBanner: false,
    );
  }
}
