import 'package:flutter/material.dart';

class SignUpPage extends StatefulWidget {
  const SignUpPage({super.key});

  @override
  State<SignUpPage> createState() => _SignUpPageState();
}

class _SignUpPageState extends State<SignUpPage> {
  // 각 입력 필드의 유효성 검사 상태를 추적하기 위한 GlobalKey
  final _formKey = GlobalKey<FormState>();

  // 입력된 텍스트를 제어하기 위한 컨트롤러
  final _emailController = TextEditingController();
  final _passwordController = TextEditingController();
  final _confirmPasswordController = TextEditingController();
  final _nicknameController = TextEditingController();

  // 위젯이 dispose될 때 컨트롤러도 정리하여 메모리 누수 방지
  @override
  void dispose() {
    _emailController.dispose();
    _passwordController.dispose();
    _confirmPasswordController.dispose();
    _nicknameController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('회원가입'),
        elevation: 0,
      ),
      body: GestureDetector(
        // 화면의 다른 곳을 탭하면 키보드가 사라지도록 설정
        onTap: () => FocusScope.of(context).unfocus(),
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(24.0),
          child: Form(
            key: _formKey, // Form 위젯에 GlobalKey 연결
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: [
                const SizedBox(height: 20),
                const Text(
                  '환영합니다!',
                  style: TextStyle(fontSize: 28, fontWeight: FontWeight.bold),
                ),
                const SizedBox(height: 8),
                Text(
                  '아래 정보를 입력하여 가입을 완료하세요.',
                  style: TextStyle(fontSize: 16, color: Colors.grey[600]),
                ),
                const SizedBox(height: 40),

                // 이메일 입력 필드
                _buildTextFormField(
                  controller: _emailController,
                  labelText: '이메일',
                  validator: (value) {
                    if (value == null || value.isEmpty) {
                      return '이메일을 입력해주세요.';
                    }
                    // 간단한 이메일 형식 검사
                    if (!RegExp(r'^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$').hasMatch(value)) {
                      return '올바른 이메일 형식이 아닙니다.';
                    }
                    return null;
                  },
                ),
                const SizedBox(height: 16),

                // 비밀번호 입력 필드
                _buildTextFormField(
                  controller: _passwordController,
                  labelText: '비밀번호',
                  obscureText: true, // 비밀번호 숨김 처리
                  validator: (value) {
                    if (value == null || value.isEmpty) {
                      return '비밀번호를 입력해주세요.';
                    }
                    if (value.length < 8) {
                      return '비밀번호는 8자 이상이어야 합니다.';
                    }
                    return null;
                  },
                ),
                const SizedBox(height: 16),

                // 비밀번호 확인 필드
                _buildTextFormField(
                  controller: _confirmPasswordController,
                  labelText: '비밀번호 확인',
                  obscureText: true,
                  validator: (value) {
                    if (value == null || value.isEmpty) {
                      return '비밀번호를 다시 한번 입력해주세요.';
                    }
                    if (value != _passwordController.text) {
                      return '비밀번호가 일치하지 않습니다.';
                    }
                    return null;
                  },
                ),
                const SizedBox(height: 16),

                // 닉네임 입력 필드
                _buildTextFormField(
                  controller: _nicknameController,
                  labelText: '닉네임',
                  validator: (value) {
                    if (value == null || value.isEmpty) {
                      return '닉네임을 입력해주세요.';
                    }
                    if (value.length < 2) {
                      return '닉네임은 2자 이상이어야 합니다.';
                    }
                    return null;
                  },
                ),
                const SizedBox(height: 40),

                // 회원가입 버튼
                ElevatedButton(
                  onPressed: () {
                    // Form의 유효성 검사를 통과하면 true, 아니면 false 반환
                    if (_formKey.currentState!.validate()) {
                      // 유효성 검사 통과 시 실행할 로직
                      // (예: 서버로 회원가입 정보 전송)
                      ScaffoldMessenger.of(context).showSnackBar(
                        const SnackBar(content: Text('회원가입 처리 중...')),
                      );
                      // TODO: 실제 회원가입 로직 구현
                    }
                  },
                  style: ElevatedButton.styleFrom(
                    padding: const EdgeInsets.symmetric(vertical: 16),
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(8),
                    ),
                  ),
                  child: const Text('가입하기', style: TextStyle(fontSize: 18)),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  // 반복되는 TextFormField를 위한 헬퍼 함수
  TextFormField _buildTextFormField({
    required TextEditingController controller,
    required String labelText,
    bool obscureText = false,
    required String? Function(String?) validator,
  }) {
    return TextFormField(
      controller: controller,
      obscureText: obscureText,
      decoration: InputDecoration(
        labelText: labelText,
        border: OutlineInputBorder(
          borderRadius: BorderRadius.circular(8.0),
        ),
        filled: true,
        fillColor: Colors.grey[100],
      ),
      validator: validator, // 유효성 검사 함수 연결
      autovalidateMode: AutovalidateMode.onUserInteraction, // 사용자가 입력할 때마다 검사
    );
  }
}