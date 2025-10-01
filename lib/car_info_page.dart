import 'package:flutter/material.dart';
import 'manufacturer_select_page.dart';

class CarInfoPage extends StatefulWidget {
  const CarInfoPage({super.key});

  @override
  State<CarInfoPage> createState() => _CarInfoPageState();
}

class _CarInfoPageState extends State<CarInfoPage> {
  // 차량 정보 상태 관리
  String _manufacturer = "PCX";
  String _model = "pcx 125";
  String _logoAsset = "assets/logos/honda.png"; // 예시 로고 경로

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: IconButton(
          icon: const Icon(Icons.close),
          onPressed: () => Navigator.of(context).pop(),
        ),
        title: const Text('차량 정보'),
        actions: [
          TextButton(
            onPressed: () {
              // TODO: 저장 로직 구현
              Navigator.of(context).pop();
            },
            child: const Text('저장', style: TextStyle(fontSize: 16)),
          ),
        ],
      ),
      body: ListView(
        padding: const EdgeInsets.all(16.0),
        children: [
          _buildSectionHeader('기본 정보'),
          _buildBasicInfoCard(),
          const SizedBox(height: 24),
          _buildSectionHeader('상세 정보'),
          _buildDetailInfoGrid(),
        ],
      ),
    );
  }

  // '기본 정보', '상세 정보' 같은 섹션 제목
  Widget _buildSectionHeader(String title) {
    return Padding(
      padding: const EdgeInsets.only(bottom: 8.0),
      child: Text(title,
          style: TextStyle(fontSize: 16, color: Colors.blue.shade700)),
    );
  }

  // 제조사/차량모델 카드
  Widget _buildBasicInfoCard() {
    return Card(
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Row(
          children: [
            // Image.asset(_logoAsset, width: 48, height: 48), // 로고 이미지
            const SizedBox(width: 16),
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text('제조사 / 차량모델',
                      style: TextStyle(color: Colors.grey.shade600)),
                  const SizedBox(height: 4),
                  Text('$_manufacturer / $_model',
                      style: const TextStyle(
                          fontSize: 18, fontWeight: FontWeight.bold)),
                ],
              ),
            ),
            OutlinedButton(
              onPressed: () async {
                // 변경 버튼 클릭 시 제조사 선택 페이지로 이동하고 결과를 받음
                final result = await Navigator.push<Map<String, String>>(
                  context,
                  MaterialPageRoute(
                      builder: (context) => const ManufacturerSelectPage()),
                );

                // 결과가 있으면 상태 업데이트
                if (result != null && result.containsKey('manufacturer')) {
                  setState(() {
                    _manufacturer = result['manufacturer']!;
                    _model = result['model']!;
                    // TODO: 로고 경로도 결과에 따라 업데이트
                    // _logoAsset = result['logoAsset']!;
                  });
                }
              },
              child: const Text('변경'),
            ),
          ],
        ),
      ),
    );
  }

  // 상세 정보 입력 필드
  Widget _buildDetailInfoGrid() {
    return Card(
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            _buildDetailRow('연식', '2025.03', isDropdown: true),
            const Divider(),
            _buildDetailRow('변속기', '자동', isDropdown: true),
            const Divider(),
            _buildDetailRow('연료 종류', '휘발유', isDropdown: true),
            const Divider(),
            _buildDetailRow('연료탱크 용량', '15', unit: 'L'),
            const Divider(),
            _buildDetailRow('공인연비', '24', unit: 'KM/L'),
            const Divider(),
            _buildDetailRow('배기량', '650', unit: 'CC'),
          ],
        ),
      ),
    );
  }

  // 상세 정보 한 줄을 만드는 위젯
  Widget _buildDetailRow(String label, String value,
      {String? unit, bool isDropdown = false}) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(label, style: TextStyle(color: Colors.grey.shade600)),
          Row(
            children: [
              Text(value,
                  style: const TextStyle(
                      fontSize: 16, fontWeight: FontWeight.w500)),
              if (isDropdown) const Icon(Icons.arrow_drop_down),
              if (unit != null) ...[
                const SizedBox(width: 8),
                Text(unit, style: TextStyle(color: Colors.grey.shade600)),
              ],
            ],
          ),
        ],
      ),
    );
  }
}