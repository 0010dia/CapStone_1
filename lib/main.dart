import 'package:flutter/material.dart';
import 'package:flutter_speed_dial/flutter_speed_dial.dart';
import 'package:intl/date_symbol_data_local.dart';
import 'package:shared_preferences/shared_preferences.dart';

import 'home.dart';
import 'navi.dart';
import 'notifications.dart';
import 'more.dart';
import 'fuel_record_page.dart';
import 'login_page.dart'; // 로그인 페이지 import

void main() async {
  // main 함수에서 비동기 작업을 수행하기 위해 async로 변경하고 아래 2줄 추가
  WidgetsFlutterBinding.ensureInitialized();
  await initializeDateFormatting();

  // SharedPreferences 인스턴스를 가져옵니다.
  final prefs = await SharedPreferences.getInstance();
  // 'isLoggedIn' 키의 값을 읽어옵니다. 값이 없으면 false를 기본값으로 사용합니다.
  final bool isLoggedIn = prefs.getBool('isLoggedIn') ?? false;

  runApp(MyCarApp(isLoggedIn: isLoggedIn)); // MyCarApp에 로그인 상태 전달
}

class MyCarApp extends StatelessWidget {
  final bool isLoggedIn;

  // 생성자를 통해 로그인 상태를 받습니다.
  const MyCarApp({super.key, required this.isLoggedIn});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '신속정확배달',
      // isLoggedIn 값에 따라 첫 화면을 결정합니다.
      // true이면 MainPage, false이면 LoginPage 를 보여줍니다.
      home: isLoggedIn ? const MainPage() : const MainPage(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  int _selectedIndex = 0;

  static const List<String> _pageLabels = ['홈', '네비', '알림', '더보기'];

  static final List<Widget> _widgetOptions = <Widget>[
    const Home(),
    const NaviPage(),
    const Notifications(),
    const More(),
  ];

  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[100],
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 0,
        title: Text(_pageLabels[_selectedIndex],
            style: const TextStyle(
                color: Colors.black,
                fontWeight: FontWeight.bold,
                fontSize: 25)),
        centerTitle: false,
      ),
      body: _widgetOptions.elementAt(_selectedIndex),
      floatingActionButton: _selectedIndex == 0 ? _buildSpeedDial() : null,
      bottomNavigationBar: BottomNavigationBar(
        type: BottomNavigationBarType.fixed,
        selectedItemColor: Colors.lightBlue,
        unselectedItemColor: Colors.grey,
        currentIndex: _selectedIndex,
        onTap: _onItemTapped,
        items: [
          BottomNavigationBarItem(
              icon: const Icon(Icons.home), label: _pageLabels[0]),
          BottomNavigationBarItem(
              icon: const Icon(Icons.motorcycle), label: _pageLabels[1]),
          BottomNavigationBarItem(
              icon: const Icon(Icons.notifications), label: _pageLabels[2]),
          BottomNavigationBarItem(
              icon: const Icon(Icons.more_horiz), label: _pageLabels[3]),
        ],
      ),
    );
  }

  SpeedDial _buildSpeedDial() {
    return SpeedDial(
      icon: Icons.edit,
      activeIcon: Icons.close,
      backgroundColor: Colors.lightBlue,
      foregroundColor: Colors.white,
      overlayColor: Colors.black,
      overlayOpacity: 0.4,
      spacing: 12,
      spaceBetweenChildren: 12,
      children: [
        SpeedDialChild(
          child: const Icon(Icons.local_gas_station, color: Colors.white),
          label: '주유 기록',
          backgroundColor: Colors.blue,
          onTap: () {
            Navigator.push(
              context,
              MaterialPageRoute(builder: (context) => const FuelRecordPage()),
            );
          },
        ),
        SpeedDialChild(
          child: const Icon(Icons.build, color: Colors.white),
          label: '정비 기록',
          backgroundColor: Colors.orange,
          onTap: () {
            print('정비 기록 추가');
          },
        ),
        SpeedDialChild(
          child: const Icon(Icons.receipt_long, color: Colors.white),
          label: '기타 지출',
          backgroundColor: Colors.green,
          onTap: () {
            print('기타 지출 추가');
          },
        ),
        SpeedDialChild(
          child: const Icon(Icons.drive_eta, color: Colors.white),
          label: '주행 기록',
          backgroundColor: Colors.indigo,
          onTap: () {
            print('주행 기록 추가');
          },
        ),
        SpeedDialChild(
          child: const Icon(Icons.car_crash, color: Colors.white),
          label: '사고 기록',
          backgroundColor: Colors.red,
          onTap: () {
            print('사고 기록 추가');
          },
        ),
      ],
    );
  }
}