import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'model_select_page.dart';

class ManufacturerSelectPage extends StatelessWidget {
  const ManufacturerSelectPage({super.key});

  static const List<Map<String, String>> manufacturers = [
    {'name': 'honda', 'logo': 'assets/logos/honda.png'},
  ];

  Future<void> _saveVehicleInfo({
    required String manufacturer,
    required String model,
    String? logoAsset,
  }) async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) return;

    final docRef = FirebaseFirestore.instance
        .collection('users')
        .doc(user.uid); // ✅ vehicle_info 제거

    await docRef.set({
      'manufacturer': manufacturer,
      'model': model,
      'logoAsset': logoAsset ?? '',
      'updatedAt': FieldValue.serverTimestamp(),
    }, SetOptions(merge: true));
  }

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
                      decoration: const InputDecoration(labelText: '제조사'),
                    ),
                    const SizedBox(height: 8),
                    TextField(
                      controller: modelController,
                      decoration: const InputDecoration(labelText: '차량 모델'),
                    ),
                    const SizedBox(height: 16),
                    ElevatedButton(
                      onPressed: () async {
                        if (manuController.text.isNotEmpty &&
                            modelController.text.isNotEmpty) {
                          await _saveVehicleInfo(
                            manufacturer: manuController.text,
                            model: modelController.text,
                          );

                          ScaffoldMessenger.of(context).showSnackBar(
                            const SnackBar(
                                content: Text('차량 정보가 저장되었습니다.')),
                          );
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
                crossAxisCount: 2,
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

                    if (model != null && context.mounted) {
                      await _saveVehicleInfo(
                        manufacturer: manu['name']!,
                        model: model,
                        logoAsset: manu['logo'],
                      );

                      ScaffoldMessenger.of(context).showSnackBar(
                        SnackBar(
                            content: Text('${manu['name']} $model 정보가 저장되었습니다.')),
                      );
                    }
                  },
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Image.asset(
                        manu['logo']!,
                        height: 80,
                        errorBuilder: (context, error, stackTrace) =>
                        const Icon(
                          Icons.motorcycle,
                          size: 60,
                          color: Colors.grey,
                        ),
                      ),
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