import 'package:flutter/material.dart';
import 'kakao_map_screen.dart';
import 'tmap_view_screen.dart';
import 'package:tmap_ui_sdk/route/data/route_point.dart';

class NaviPage extends StatefulWidget {
  const NaviPage({super.key});

  @override
  State<NaviPage> createState() => _NaviPageState();
}

class _NaviPageState extends State<NaviPage> {
  RoutePoint? _destination;

  @override
  Widget build(BuildContext context) {
    // ⭐️ 불필요한 Scaffold를 제거하고 Center 위젯부터 시작합니다.
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(20.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            if (_destination != null)
              Card(
                elevation: 2,
                child: Padding(
                  padding: const EdgeInsets.all(16.0),
                  child: Column(
                    children: [
                      Text(
                        _destination!.name,
                        style: const TextStyle(
                            fontSize: 18, fontWeight: FontWeight.bold),
                      ),
                      const SizedBox(height: 8),
                      Text(
                          '위도: ${_destination!.latitude}, 경도: ${_destination!.longitude}'),
                    ],
                  ),
                ),
              ),
            if (_destination == null)
              const Text(
                '목적지를 검색해주세요.',
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 16),
              ),
            const SizedBox(height: 20),
            ElevatedButton.icon(
              icon: const Icon(Icons.search),
              label: const Text('목적지 검색하기'),
              style: ElevatedButton.styleFrom(
                padding: const EdgeInsets.symmetric(vertical: 12),
                textStyle: const TextStyle(fontSize: 16),
              ),
              onPressed: () async {
                final result = await Navigator.push(
                  context,
                  MaterialPageRoute(
                      builder: (context) => const KakaoMapScreen()),
                );

                if (result != null && result is RoutePoint) {
                  setState(() {
                    _destination = result;
                  });
                }
              },
            ),
            const SizedBox(height: 10),
            ElevatedButton.icon(
              icon: const Icon(Icons.navigation_outlined),
              label: const Text('길안내 시작'),
              style: ElevatedButton.styleFrom(
                padding: const EdgeInsets.symmetric(vertical: 12),
                backgroundColor: Colors.lightBlue,
                foregroundColor: Colors.white,
                textStyle: const TextStyle(fontSize: 16),
                disabledBackgroundColor: Colors.grey,
              ),
              onPressed: _destination == null
                  ? null
                  : () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) =>
                        TmapViewScreen(destination: _destination!),
                  ),
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}