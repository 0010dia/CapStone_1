import 'package:flutter/material.dart';

class ModelSelectPage extends StatelessWidget {
  final String manufacturerName;

  const ModelSelectPage({super.key, required this.manufacturerName});

  // 예시 데이터
  static const Map<String, List<String>> modelsByManufacturer = {
    '혼다': ['슈퍼커브', 'PCX125', 'Rebel 500', '벤리110', 'CB650R'],
    'BMW': ['R 1250 GS', 'S 1000 RR', 'G 310 R'],
    '야마하': ['MT-09', 'YZF-R3', 'NMAX 125'],
    // ... 다른 제조사별 모델 리스트
  };

  @override
  Widget build(BuildContext context) {
    final models = modelsByManufacturer[manufacturerName] ?? [];

    return Scaffold(
      appBar: AppBar(
        title: const Text('차종은 무엇인가요?'),
      ),
      body: ListView.separated(
        itemCount: models.length,
        itemBuilder: (context, index) {
          final model = models[index];
          return ListTile(
            title: Text(model),
            trailing: const Icon(Icons.chevron_right),
            onTap: () {
              // 모델 선택 시, 이전 페이지로 모델명 전달
              Navigator.of(context).pop(model);
            },
          );
        },
        separatorBuilder: (context, index) => const Divider(),
      ),
    );
  }
}