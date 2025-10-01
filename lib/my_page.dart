import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

import 'car_info_page.dart';
import 'edit_profile_page.dart'; // 내 정보 수정 페이지 import
import 'login_page.dart';
import 'password_change_page.dart'; // ⭐️ 이름을 원래대로 password_change_page.dart로 되돌립니다.

class MyPage extends StatefulWidget {
  const MyPage({super.key});

  @override
  State<MyPage> createState() => _MyPageState();
}

class _MyPageState extends State<MyPage> {

  Future<void> _showDeleteAccountDialog() async {
    if (!mounted) return;
    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return AlertDialog(
          title: const Text('회원 탈퇴'),
          content: const Text('정말로 탈퇴하시겠습니까?\n모든 정보가 영구적으로 삭제되며 복구할 수 없습니다.'),
          actions: [
            TextButton(
              child: const Text('취소'),
              onPressed: () {
                Navigator.of(dialogContext).pop();
              },
            ),
            TextButton(
              style: TextButton.styleFrom(foregroundColor: Colors.red),
              child: const Text('탈퇴'),
              onPressed: () async {
                final prefs = await SharedPreferences.getInstance();
                await prefs.setBool('isLoggedIn', false);
                if (mounted) {
                  Navigator.of(context).pushAndRemoveUntil(
                    MaterialPageRoute(builder: (context) => const LoginPage()),
                        (Route<dynamic> route) => false,
                  );
                }
              },
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('마이페이지'),
        actions: [
          IconButton(
            icon: const Icon(Icons.edit_outlined),
            tooltip: '내 정보 수정',
            onPressed: () {
              Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => const EditProfilePage()),
              );
            },
          ),
        ],
      ),
      body: ListView(
        children: [
          // 사용자 정보 섹션
          _buildInfoTile(
            icon: Icons.person_outline,
            title: '닉네임',
            subtitle: 'test_user',
          ),
          _buildInfoTile(
            icon: Icons.email_outlined,
            title: '이메일',
            subtitle: 'test@test.com',
          ),
          _buildInfoTile(
            icon: Icons.phone_android_outlined,
            title: '휴대폰 번호',
            subtitle: '010-1234-5678',
          ),
          const Divider(height: 20, thickness: 1),
          // 설정 및 관리 섹션
          _buildActionTile(
            icon: Icons.motorcycle_outlined,
            title: '차량 정보 관리',
            onTap: () {
              Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => const CarInfoPage()),
              );
            },
          ),
          _buildActionTile(
            icon: Icons.lock_outline,
            title: '비밀번호 변경',
            onTap: () {
              Navigator.push(
                context,
                // ⭐️ 연결 페이지를 PasswordChangePage로 되돌립니다.
                MaterialPageRoute(builder: (context) => const PasswordChangePage()),
              );
            },
          ),
          const Divider(),
          ListTile(
            leading: Icon(Icons.delete_forever_outlined, color: Colors.red[700]),
            title: Text(
              '회원 탈퇴',
              style: TextStyle(fontSize: 16, color: Colors.red[700]),
            ),
            onTap: _showDeleteAccountDialog,
          ),
        ],
      ),
    );
  }

  Widget _buildInfoTile({
    required IconData icon,
    required String title,
    required String subtitle,
  }) {
    return ListTile(
      leading: Icon(icon, color: Colors.grey[600]),
      title: Text(title, style: const TextStyle(fontWeight: FontWeight.bold)),
      subtitle: Text(subtitle, style: const TextStyle(fontSize: 16)),
    );
  }

  Widget _buildActionTile({
    required IconData icon,
    required String title,
    required VoidCallback onTap,
  }) {
    return ListTile(
      leading: Icon(icon, color: Colors.grey[800]),
      title: Text(title, style: const TextStyle(fontSize: 16)),
      trailing: const Icon(Icons.chevron_right),
      onTap: onTap,
    );
  }
}