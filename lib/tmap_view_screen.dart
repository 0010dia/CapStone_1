import 'dart:developer';
import 'package:flutter/material.dart';
import 'package:permission_handler/permission_handler.dart';
import 'package:tmap_ui_sdk/auth/data/auth_data.dart';
import 'package:tmap_ui_sdk/auth/data/init_result.dart';
import 'package:tmap_ui_sdk/route/data/planning_option.dart';
import 'package:tmap_ui_sdk/route/data/route_point.dart';
import 'package:tmap_ui_sdk/route/data/route_request_data.dart';
import 'package:tmap_ui_sdk/tmap_ui_sdk_manager.dart';
import 'package:tmap_ui_sdk/widget/tmap_view_widget.dart';

class TmapViewScreen extends StatefulWidget {
  final RoutePoint destination;

  const TmapViewScreen({required this.destination, super.key});

  @override
  State<TmapViewScreen> createState() => _TmapViewScreenState();
}

class _TmapViewScreenState extends State<TmapViewScreen> {
  bool _isReady = false;
  late final RouteRequestData _routeRequestData;

  @override
  void initState() {
    super.initState();
    _initializeSDK();
  }

  Future<void> _initializeSDK() async {
    var status = await Permission.location.request();
    if (!status.isGranted) {
      log("위치 권한이 거부되었습니다.");
      if (mounted) Navigator.pop(context); // 권한 없으면 이전 화면으로
      return;
    }

    try {
      // ⭐️ TMAP API 키를 입력해주세요.
      AuthData authData = AuthData(clientApiKey: "TVMJeizEiy5QbSXYsFRjc4jFTReqEChe5X8TGPQM");
      InitResult? result = await TmapUISDKManager().initSDK(authData);

      if (result == InitResult.granted) {
        log("TMAP SDK 초기화 성공");
        _setupRouteAndPrepareUI();
      } else {
        log("TMAP SDK 초기화 실패: $result");
      }
    } catch (e) {
      log("TMAP SDK 초기화 중 오류 발생: ${e.toString()}");
    }
  }

  void _setupRouteAndPrepareUI() {
    _routeRequestData = RouteRequestData(
      // ⭐️ 출발지를 '서울시청'으로 임의 설정
      source: RoutePoint(name: "서울시청", latitude: 37.5665, longitude: 126.9780),
      // NaviPage에서 전달받은 목적지 사용
      destination: widget.destination,
      routeOption: [PlanningOption.recommend],
      safeDriving: false,
    );

    if (mounted) {
      setState(() {
        _isReady = true;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('${widget.destination.name} 길안내')),
      body: _isReady
          ? TmapViewWidget(data: _routeRequestData)
          : const Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            CircularProgressIndicator(),
            SizedBox(height: 16),
            Text('TMAP 내비게이션을 준비 중입니다...'),
          ],
        ),
      ),
    );
  }
}