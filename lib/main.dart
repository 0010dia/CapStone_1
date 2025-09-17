import 'dart:developer';

import 'package:flutter/material.dart';


// 새로 만든 페이지 파일들을 import 합니다.
import '/home.dart';
import '/navi.dart';
import '/notifications.dart';
import '/more.dart';

void main() {
  runApp(const MyCarApp());

}

class MyCarApp extends StatelessWidget {
  const MyCarApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: '신속정확배달',
      home: MainPage(),
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

  // 1. 페이지 라벨/타이틀 목록 생성
  static const List<String> _pageLabels = ['홈', '네비', '알림', '더보기'];

  static final List<Widget> _widgetOptions = <Widget>[
    Home(),
    Navi(),
    Notifications(),
    More(),
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
        // 2. 선택된 인덱스에 따라 AppBar 타이틀 변경
        title: Text(_pageLabels[_selectedIndex], style: const TextStyle(color: Colors.black, fontWeight: FontWeight.bold, fontSize: 25)),
        centerTitle: false, // 제목 왼쪽 정렬
      ),
      body: _widgetOptions.elementAt(_selectedIndex),
      floatingActionButton: _selectedIndex == 0
          ? FloatingActionButton(
        onPressed: () {},
        backgroundColor: Colors.lightBlue,
        child: const Icon(Icons.edit),
      )
          : null,
      bottomNavigationBar: BottomNavigationBar(
        type: BottomNavigationBarType.fixed,
        selectedItemColor: Colors.lightBlue,
        unselectedItemColor: Colors.grey,
        currentIndex: _selectedIndex,
        onTap: _onItemTapped,
        // 3. 각 아이템의 label도 위 목록을 사용하면 더 일관성 있게 관리할 수 있습니다.
        items: [
          BottomNavigationBarItem(icon: const Icon(Icons.home), label: _pageLabels[0]),
          BottomNavigationBarItem(icon: const Icon(Icons.motorcycle), label: _pageLabels[1]),
          BottomNavigationBarItem(icon: const Icon(Icons.notifications), label: _pageLabels[2]),
          BottomNavigationBarItem(icon: const Icon(Icons.more_horiz), label: _pageLabels[3]),
        ],
      ),
    );
  }


}