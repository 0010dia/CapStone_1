import 'package:flutter/material.dart';

class ModelSelectPage extends StatelessWidget {
  final String manufacturerName;
  const ModelSelectPage({super.key, required this.manufacturerName});

  static const Map<String, List<String>> modelsByManufacturer = {
    '혼다': ['슈퍼커브', 'PCX125', 'Rebel 500', '벤리110', 'CB650R'],
    'BMW': ['R 1250 GS', 'S 1000 RR', 'G 310 R'],
    '야마하': ['MT-09', 'YZF-R3', 'NMAX 125'],
    '두카티': ['몬스터', '파니갈레', '스크램블러'],
    '스즈키': ['GSX-R1000', 'SV650', 'V-Strom 650'],
  };

  @override
  Widget build(BuildContext context) {
    final models = modelsByManufacturer[manufacturerName] ?? [];

    if (models.isEmpty) {
      return Scaffold(
        appBar: AppBar(title: const Text('차종 선택')),
        body: const Center(child: Text('선택 가능한 모델이 없습니다.')),
      );
    }

    return Scaffold(
      appBar: AppBar(title: const Text('차종 선택')),
      body: ListView.separated(
        itemCount: models.length,
        itemBuilder: (context, index) {
          final model = models[index];
          return ListTile(
            title: Text(model),
            trailing: const Icon(Icons.chevron_right),
            onTap: () => Navigator.of(context).pop(model),
          );
        },
        separatorBuilder: (context, index) => const Divider(),
      ),
    );
  }
}
