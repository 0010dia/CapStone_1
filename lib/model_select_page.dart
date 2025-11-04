import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';

class ModelSelectPage extends StatelessWidget {
  final String manufacturerName;
  const ModelSelectPage({super.key, required this.manufacturerName});

  Future<List<String>> _fetchModels() async {
    try {
      final doc = await FirebaseFirestore.instance
          .collection('manufacturers')
          .doc(manufacturerName)
          .get();

      if (doc.exists) {
        final data = doc.data();
        final List<dynamic> models = data?['models'] ?? [];
        return models.map((e) => e.toString()).toList();
      } else {
        return [];
      }
    } catch (e) {
      debugPrint('모델 불러오기 실패: $e');
      return [];
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('차종 선택')),
      body: FutureBuilder<List<String>>(
        future: _fetchModels(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Center(child: CircularProgressIndicator());
          }
          if (snapshot.hasError) {
            return const Center(child: Text('데이터를 불러오는 중 오류가 발생했습니다.'));
          }

          final models = snapshot.data ?? [];
          if (models.isEmpty) {
            return Center(
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  const Text('선택 가능한 모델이 없습니다.'),
                  const SizedBox(height: 16),
                  ElevatedButton(
                    onPressed: () {
                      WidgetsBinding.instance.addPostFrameCallback((_) {
                        Navigator.of(context).pop(null);
                      });
                    },
                    child: const Text('뒤로가기'),
                  ),
                ],
              ),
            );
          }

          return ListView.separated(
            itemCount: models.length,
            itemBuilder: (context, index) {
              final model = models[index];
              return ListTile(
                title: Text(model),
                trailing: const Icon(Icons.chevron_right),
                onTap: () {
                  WidgetsBinding.instance.addPostFrameCallback((_) {
                    Navigator.of(context).pop(model);
                  });
                },
              );
            },
            separatorBuilder: (context, index) => const Divider(),
          );
        },
      ),
    );
  }
}