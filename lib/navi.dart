import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:permission_handler/permission_handler.dart';
import 'package:tmap_ui_sdk/auth/data/auth_data.dart';
import 'package:tmap_ui_sdk/auth/data/init_result.dart';
import 'package:tmap_ui_sdk/route/data/planning_option.dart';
import 'package:tmap_ui_sdk/route/data/route_point.dart';
import 'package:tmap_ui_sdk/route/data/route_request_data.dart';
// TMAP SDK 관련 import - 이 세 줄이 핵심입니다.
import 'package:tmap_ui_sdk/tmap_ui_sdk.dart';
import 'package:tmap_ui_sdk/tmap_ui_sdk_manager.dart';
import 'package:tmap_ui_sdk/widget/tmap_view_widget.dart';

class Navi extends StatefulWidget {
  const Navi({super.key});

  @override
  State<Navi> createState() => _NaviState();
}

class _NaviState extends State<Navi> {
  // SDK 초기화 및 경로 데이터 준비 상태를 관리하는 변수
  bool _isReady = false;
  // TMAP 길안내 UI에 전달할 경로 데이터
  late final RouteRequestData _routeRequestData;

  @override
  void initState() {
    super.initState();
    _initializeSDK();
  }

  Future<void> _initializeSDK() async {
    // 1. 위치 권한 확인
    var status = await Permission.location.request();
    if (!status.isGranted) {
      log("위치 권한이 거부되었습니다.");
      return;
    }

    // 2. TMAP SDK 초기화 (인증)
    try {
      AuthData authData = AuthData(
        clientApiKey: "JyGHyqXAWxpxwvkbbPJg3yg7xIdtTDc95jsdWDfi",
      );

      InitResult? result = await TmapUISDKManager().initSDK(authData);

      if (result == InitResult.granted) {
        log("TMAP SDK 초기화 성공");
        // 3. 경로 데이터 설정 및 화면 준비
        _setupRouteAndPrepareUI();
      } else {
        log("TMAP SDK 초기화 실패: $result");
      }
    } catch (e) {
      log("TMAP SDK 초기화 중 오류 발생: ${e.toString()}");
    }
  }

  void _setupRouteAndPrepareUI() {
    // 공식 샘플 코드와 동일한 방식으로 경로 데이터 생성
    _routeRequestData = RouteRequestData(
      // 출발지를 null로 설정하면 SDK가 현재 위치를 자동으로 사용합니다.
      source: RoutePoint(
        name: "강남역",
        latitude: 37.4979,
        longitude: 127.0276,
      ),
      // 목적지 정보 (RoutePoint 클래스 사용)
      destination: RoutePoint(
        name: "SKT타워",
        latitude: 37.566491,
        longitude: 126.985146,
      ),
      // 경로 옵션 (PlanningOption 클래스 사용)
      routeOption: [
        PlanningOption.recommend, // 추천 경로
      ],
      // 안심주행 모드 여부
      safeDriving: false,
    );

    // 모든 준비가 끝났으므로, 화면을 다시 그려 TMAP 지도를 표시하도록 상태를 변경합니다.
    if (mounted) {
      setState(() {
        _isReady = true;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    if (!_isReady) {
      // 준비가 되기 전까지 로딩 화면 표시
      return const Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            CircularProgressIndicator(),
            SizedBox(height: 16),
            Text('TMAP 내비게이션을 준비 중입니다...'),
          ],
        ),
      );
    } else {
      // 준비 완료 시 TmapViewWidget에 데이터를 전달하여 표시
      return TmapViewWidget(data: _routeRequestData);
    }
  }
}