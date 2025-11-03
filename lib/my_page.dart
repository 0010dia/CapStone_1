import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:shared_preferences/shared_preferences.dart';

import 'car_info_page.dart';
import 'edit_profile_page.dart';
import 'login_page.dart';
import 'password_change_page.dart';

class MyPage extends StatefulWidget {
  const MyPage({super.key});

  @override
  State<MyPage> createState() => _MyPageState();
}

class _MyPageState extends State<MyPage> {
  bool _isLoading = true;
  String _nickname = '';
  String _email = '';
  String _phone = '';

  @override
  void initState() {
    super.initState();
    _loadUserInfo();
  }

  Future<void> _loadUserInfo() async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) return;

    final docRef = FirebaseFirestore.instance.collection('users').doc(user.uid);
    final doc = await docRef.get();

    if (doc.exists) {
      final data = doc.data()!;
      setState(() {
        _nickname = data['nickname'] ?? '';
        _email = data['email'] ?? user.email ?? '';
        _phone = data['phone'] ?? '';
        _isLoading = false;
      });
    } else {
      setState(() {
        _nickname = '';
        _email = user.email ?? '';
        _phone = '';
        _isLoading = false;
      });
    }
  }

  Future<void> _showDeleteAccountDialog() async {
    if (!mounted) return;
    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return AlertDialog(
          title: const Text('회원 탈퇴'),
          content: const Text(
              '정말로 탈퇴하시겠습니까?\n모든 정보가 영구적으로 삭제되며 복구할 수 없습니다.'),
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
    if (_isLoading) {
      return const Scaffold(
        body: Center(child: CircularProgressIndicator()),
      );
    }

    return Scaffold(
      appBar: AppBar(
        title: const Text('마이페이지'),
        actions: [
          IconButton(
            icon: const Icon(Icons.edit_outlined),
            tooltip: '내 정보 수정',
            onPressed: () async {
              // EditProfilePage에서 돌아오면 정보 다시 불러오기
              await Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => const EditProfilePage()),
              );
              _loadUserInfo();
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
            subtitle: _nickname,
          ),
          _buildInfoTile(
            icon: Icons.email_outlined,
            title: '이메일',
            subtitle: _email,
          ),
          _buildInfoTile(
            icon: Icons.phone_android_outlined,
            title: '휴대폰 번호',
            subtitle: _phone,
          ),
          const Divider(height: 20, thickness: 1),
          // 설정 및 관리 섹션
          _buildActionTile(
            icon: Icons.motorcycle_outlined,
            title: '차량 정보 관리',
            onTap: () async {
              await Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => const CarInfoPage()),
              );
              _loadUserInfo(); // 필요 시 정보 갱신
            },
          ),
          _buildActionTile(
            icon: Icons.lock_outline,
            title: '비밀번호 변경',
            onTap: () {
              Navigator.push(
                context,
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
