import 'package:flutter/material.dart';
import 'model_select_page.dart';

class ManufacturerSelectPage extends StatelessWidget {
  const ManufacturerSelectPage({super.key});

  // 예시 데이터 (실제 앱에서는 서버나 DB에서 가져와야 함)
  static const List<Map<String, String>> manufacturers = [
    {'name': '혼다', 'logo': 'assets/logos/honda.png'},
    {'name': 'BMW', 'logo': 'assets/logos/bmw.png'},
    {'name': '두카티', 'logo': 'assets/logos/ducati.png'},
    {'name': '야마하', 'logo': 'assets/logos/yamaha.png'},
    {'name': '스즈키', 'logo': 'assets/logos/suzuki.png'},
    {'name': '가와사키', 'logo': 'assets/logos/kawasaki.png'},
    {'name': '할리데이비슨', 'logo': 'assets/logos/harley.png'},
    {'name': 'KTM', 'logo': 'assets/logos/ktm.png'},
    // ... 더 많은 제조사 추가
  ];

  @override
  Widget build(BuildContext context) {
    final manufacturerController = TextEditingController();
    final modelController = TextEditingController();

    return Scaffold(
      appBar: AppBar(
        title: const Text('어떤 차를 타고 계신가요?'),
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text('직접 입력',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
            const SizedBox(height: 8),
            Card(
              child: Padding(
                padding: const EdgeInsets.all(16.0),
                child: Column(
                  children: [
                    TextField(
                      controller: manufacturerController,
                      decoration: const InputDecoration(labelText: '제조사'),
                    ),
                    const SizedBox(height: 8),
                    TextField(
                      controller: modelController,
                      decoration: const InputDecoration(labelText: '차량모델'),
                    ),
                    const SizedBox(height: 16),
                    ElevatedButton(
                      onPressed: () {
                        // 입력 완료 시, 이전 페이지로 결과 전달
                        if (manufacturerController.text.isNotEmpty &&
                            modelController.text.isNotEmpty) {
                          Navigator.of(context).pop({
                            'manufacturer': manufacturerController.text,
                            'model': modelController.text,
                          });
                        }
                      },
                      style: ElevatedButton.styleFrom(
                        minimumSize: const Size(double.infinity, 48),
                      ),
                      child: const Text('입력 완료'),
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 24),
            const Text('제조사 선택',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
            const SizedBox(height: 8),
            GridView.builder(
              physics: const NeverScrollableScrollPhysics(), // 중첩 스크롤 방지
              shrinkWrap: true,
              gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                crossAxisCount: 4,
                crossAxisSpacing: 16,
                mainAxisSpacing: 16,
              ),
              itemCount: manufacturers.length,
              itemBuilder: (context, index) {
                final manu = manufacturers[index];
                return GestureDetector(
                  onTap: () async {
                    // 모델 선택 페이지로 이동하고 결과를 받음
                    final model = await Navigator.push<String>(
                      context,
                      MaterialPageRoute(
                        builder: (context) => ModelSelectPage(
                          manufacturerName: manu['name']!,
                        ),
                      ),
                    );

                    // 모델이 선택되었다면, 차량 정보 페이지로 최종 결과 전달
                    if (model != null) {
                      Navigator.of(context).pop({
                        'manufacturer': manu['name'],
                        'model': model,
                        'logoAsset': manu['logo'],
                      });
                    }
                  },
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      // Image.asset(manu['logo']!, width: 48, height: 48),
                      const SizedBox(height: 8),
                      Text(manu['name']!),
                    ],
                  ),
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}