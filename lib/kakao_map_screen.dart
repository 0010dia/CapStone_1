import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'package:tmap_ui_sdk/route/data/route_point.dart';
import 'package:webview_flutter/webview_flutter.dart';
// ⭐️ 복잡한 설정을 위해 필요했던 아래 import는 이제 필요 없습니다.
// import 'package:webview_flutter_android/webview_flutter_android.dart';

class KakaoMapScreen extends StatefulWidget {
  const KakaoMapScreen({super.key});
  @override
  State<KakaoMapScreen> createState() => _KakaoMapScreenState();
}

class _KakaoMapScreenState extends State<KakaoMapScreen> {
  // ⭐️ WebViewController를 가장 단순한 방식으로 생성합니다.
  late final WebViewController _controller = WebViewController()
    ..setJavaScriptMode(JavaScriptMode.unrestricted)
    ..addJavaScriptChannel('onComplete',
        onMessageReceived: (JavaScriptMessage message) {
          _handleAddressData(message.message);
        })
  // ⭐️ 검증된 외부 인터넷 주소를 사용합니다.
    ..loadRequest(Uri.parse(
        'https://0010dia.github.io/postcode-page/kakao_postcode.html'));

  final String kakaoRestApiKey = '9fa294df4030268d4db11bad1a33122a';

  void _handleAddressData(String jsonData) async {
    final data = jsonDecode(jsonData);
    final address = data['address'] as String;
    final placeName = data['buildingName'] as String? ?? address;
    final coordinates = await _getCoordinates(address);
    if (coordinates != null && mounted) {
      final destination = RoutePoint(
        name: placeName,
        latitude: coordinates['latitude']!,
        longitude: coordinates['longitude']!,
      );
      Navigator.pop(context, destination);
    }
  }

  Future<Map<String, double>?> _getCoordinates(String address) async {
    final url = Uri.parse(
        'https://dapi.kakao.com/v2/local/search/address.json?query=${Uri.encodeComponent(address)}');
    try {
      final response = await http.get(
        url,
        headers: {'Authorization': 'KakaoAK $kakaoRestApiKey'},
      );
      print('카카오 API 응답: ${response.statusCode}, ${response.body}');
      if (response.statusCode == 200) {
        final data = jsonDecode(response.body);
        if (data['documents'].isNotEmpty) {
          final doc = data['documents'][0];
          return {
            'latitude': double.parse(doc['y']),
            'longitude': double.parse(doc['x']),
          };
        }
      }
    } catch (e) {
      debugPrint('좌표 변환 중 오류 발생: $e');
    }
    return null;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('주소 검색')),
      body: WebViewWidget(controller: _controller),
    );
  }
}