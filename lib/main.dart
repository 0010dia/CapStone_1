import 'package:flutter/material.dart';
import 'package:flutter_speed_dial/flutter_speed_dial.dart';
import 'package:intl/date_symbol_data_local.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';

import 'home.dart';
import 'navi.dart';
import 'notifications.dart';
import 'more.dart';
import 'fuel_record_page.dart';
import 'login_page.dart';
import 'firebase_options.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await initializeDateFormatting();

  // ✅ Firebase 초기화
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );

  runApp(const MyCarApp());
}

class MyCarApp extends StatelessWidget {
  const MyCarApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '신속정확배달',
      debugShowCheckedModeBanner: false,
      // ✅ FirebaseAuth 상태에 따라 로그인 여부를 자동으로 감지
      home: StreamBuilder<User?>(
        stream: FirebaseAuth.instance.authStateChanges(),
        builder: (context, snapshot) {
          // Firebase 초기화 중 로딩 표시
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Scaffold(
              body: Center(child: CircularProgressIndicator()),
            );
          }

          // 로그인 상태라면 메인 페이지로
          if (snapshot.hasData) {
            return const MainPage();
          }

          // 로그아웃 상태라면 로그인 페이지로
          return const LoginPage();
        },
      ),
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

  // 🔹 로그아웃 기능 추가
  Future<void> _logout() async {
    await FirebaseAuth.instance.signOut();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[100],
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 0,
        title: Text(
          _pageLabels[_selectedIndex],
          style: const TextStyle(
            color: Colors.black,
            fontWeight: FontWeight.bold,
            fontSize: 25,
          ),
        ),
        centerTitle: false,
        actions: [
          IconButton(
            icon: const Icon(Icons.logout, color: Colors.red),
            onPressed: _logout, // ✅ 로그아웃 버튼
          ),
        ],
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
