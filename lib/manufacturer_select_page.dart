import 'package:flutter/material.dart';
import 'model_select_page.dart';

class ManufacturerSelectPage extends StatelessWidget {
  const ManufacturerSelectPage({super.key});

  static const List<Map<String, String>> manufacturers = [
    {'name': '혼다', 'logo': 'assets/logos/honda.png'},
    {'name': 'BMW', 'logo': 'assets/logos/bmw.png'},
    {'name': '야마하', 'logo': 'assets/logos/yamaha.png'},
    {'name': '두카티', 'logo': 'assets/logos/ducati.png'},
    {'name': '스즈키', 'logo': 'assets/logos/suzuki.png'},
  ];

  @override
  Widget build(BuildContext context) {
    final manuController = TextEditingController();
    final modelController = TextEditingController();

    return Scaffold(
      appBar: AppBar(title: const Text('제조사 선택')),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            const Text('직접 입력', style: TextStyle(fontSize: 18)),
            const SizedBox(height: 8),
            Card(
              child: Padding(
                padding: const EdgeInsets.all(16.0),
                child: Column(
                  children: [
                    TextField(
                      controller: manuController,
                      decoration:
                      const InputDecoration(labelText: '제조사'),
                    ),
                    const SizedBox(height: 8),
                    TextField(
                      controller: modelController,
                      decoration:
                      const InputDecoration(labelText: '차량 모델'),
                    ),
                    const SizedBox(height: 16),
                    ElevatedButton(
                      onPressed: () {
                        if (manuController.text.isNotEmpty &&
                            modelController.text.isNotEmpty) {
                          Navigator.of(context).pop({
                            'manufacturer': manuController.text,
                            'model': modelController.text,
                          });
                        }
                      },
                      child: const Text('입력 완료'),
                    )
                  ],
                ),
              ),
            ),
            const SizedBox(height: 24),
            const Text('제조사 선택', style: TextStyle(fontSize: 18)),
            const SizedBox(height: 8),
            GridView.builder(
              physics: const NeverScrollableScrollPhysics(),
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
                    final model = await Navigator.push<String>(
                      context,
                      MaterialPageRoute(
                        builder: (context) =>
                            ModelSelectPage(manufacturerName: manu['name']!),
                      ),
                    );
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
