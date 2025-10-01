import 'package:flutter/material.dart';
import 'my_page.dart'; // 새로 만든 마이페이지 import

class More extends StatelessWidget {
  const More({super.key});

  @override
  Widget build(BuildContext context) {
    return ListView(
      children: [
        ListTile(
          leading: const Icon(Icons.person, size: 28),
          title: const Text('마이페이지', style: TextStyle(fontSize: 18)),
          trailing: const Icon(Icons.chevron_right),
          onTap: () {
            // 마이페이지로 이동
            Navigator.push(
              context,
              MaterialPageRoute(builder: (context) => const MyPage()),
            );
          },
        ),
        const Divider(),
        // TODO: 추후 다른 메뉴들을 여기에 추가할 수 있습니다.
        // 예: 공지사항, 고객센터 등
      ],
    );
  }
}