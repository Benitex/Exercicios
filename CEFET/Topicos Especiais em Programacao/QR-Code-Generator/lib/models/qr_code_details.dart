import 'package:qr_flutter/qr_flutter.dart';

class QrCodeDetails {
  const QrCodeDetails({required this.image, required this.name});
  
  final String name;
  final QrImageView image;
}
