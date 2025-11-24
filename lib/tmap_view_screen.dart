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
import 'package:geolocator/geolocator.dart';

Future<RoutePoint> _getCurrentLocationAsRoutePoint() async {
  bool serviceEnabled = await Geolocator.isLocationServiceEnabled();
  if (!serviceEnabled) {
    log("위치 서비스가 꺼져 있습니다.");
    throw Exception("위치 서비스 꺼짐");
  }

  LocationPermission permission = await Geolocator.checkPermission();
  if (permission == LocationPermission.denied) {
    permission = await Geolocator.requestPermission();
    if (permission == LocationPermission.denied) {
      log("위치 권한이 거부되었습니다.");
      throw Exception("위치 권한 거부");
    }
  }

  Position position = await Geolocator.getCurrentPosition();
  return RoutePoint(
    name: "현재 위치",
    latitude: position.latitude,
    longitude: position.longitude,
  );
}

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

  void _setupRouteAndPrepareUI() async {
    try {
      RoutePoint currentLocation = await _getCurrentLocationAsRoutePoint();

      _routeRequestData = RouteRequestData(
        source: currentLocation,
        destination: widget.destination,
        routeOption: [PlanningOption.recommend],
        safeDriving: false,
      );

      if (mounted) {
        setState(() {
          _isReady = true;
        });
      }
    } catch (e) {
      log("현재 위치를 가져오는 데 실패했습니다: ${e.toString()}");
      if (mounted) Navigator.pop(context);
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