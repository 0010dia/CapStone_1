import 'package:flutter/material.dart';
import 'package:intl/intl.dart';

// 정비 항목 하나를 나타내는 데이터 클래스
class MaintenanceItem {
  String? selectedType;
  final TextEditingController costController = TextEditingController();
  final TextEditingController memoController = TextEditingController();

  MaintenanceItem({this.selectedType});
}

class MaintenanceRecordPage extends StatefulWidget {
  const MaintenanceRecordPage({super.key});

  @override
  State<MaintenanceRecordPage> createState() => _MaintenanceRecordPageState();
}

class _MaintenanceRecordPageState extends State<MaintenanceRecordPage> {
  // 동적으로 추가/삭제될 정비 항목 리스트
  final List<MaintenanceItem> _maintenanceItems = [];
  final List<String> _maintenanceTypes = ['엔진 오일', '타이어', '브레이크', '체인', '기타'];

  @override
  void initState() {
    super.initState();
    // 페이지가 시작될 때 기본 항목 하나를 추가
    _addNewItem();
  }

  @override
  void dispose() {
    // 모든 컨트롤러를 정리하여 메모리 누수 방지
    for (var item in _maintenanceItems) {
      item.costController.dispose();
      item.memoController.dispose();
    }
    super.dispose();
  }

  void _addNewItem() {
    setState(() {
      _maintenanceItems.add(MaintenanceItem(selectedType: _maintenanceTypes.first));
    });
  }

  void _removeItem(int index) {
    // 항목이 최소 1개는 유지되도록 함
    if (_maintenanceItems.length > 1) {
      setState(() {
        // dispose를 호출하여 컨트롤러 정리
        _maintenanceItems[index].costController.dispose();
        _maintenanceItems[index].memoController.dispose();
        _maintenanceItems.removeAt(index);
      });
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('최소 1개의 항목이 필요합니다.')),
      );
    }
  }

  String getToday() {
    return DateFormat('yyyy.MM.dd (E)', 'ko_KR').format(DateTime.now());
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: IconButton(
          icon: const Icon(Icons.close),
          onPressed: () => Navigator.of(context).pop(),
        ),
        title: Column(
          children: [
            const Text('정비 기록', style: TextStyle(fontSize: 18)),
            Text(getToday(), style: TextStyle(fontSize: 14, color: Colors.grey[600])),
          ],
        ),
        centerTitle: true,
        actions: [
          TextButton(
            onPressed: () {
              // TODO: 저장 로직 구현
              Navigator.of(context).pop();
            },
            child: const Text('완료', style: TextStyle(fontSize: 16)),
          ),
        ],
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            _buildOdometerRow(),
            const SizedBox(height: 24),
            // 정비 항목 리스트를 동적으로 구성
            ListView.builder(
              shrinkWrap: true,
              physics: const NeverScrollableScrollPhysics(),
              itemCount: _maintenanceItems.length,
              itemBuilder: (context, index) {
                return _buildMaintenanceItemCard(index);
              },
            ),
            const SizedBox(height: 16),
            _buildAddRemoveButtons(),
          ],
        ),
      ),
    );
  }

  // 누적주행거리 입력 위젯
  Widget _buildOdometerRow() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(8),
          border: Border.all(color: Colors.grey.shade300)
      ),
      child: Row(
        children: [
          const Icon(Icons.speed_outlined, color: Colors.grey),
          const SizedBox(width: 12),
          const Text('누적주행거리', style: TextStyle(fontSize: 16)),
          const Spacer(),
          SizedBox(
            width: 120,
            child: TextFormField(
              initialValue: '3,123.1',
              textAlign: TextAlign.end,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                border: InputBorder.none,
                isDense: true,
                contentPadding: EdgeInsets.zero,
              ),
              style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
          ),
          const SizedBox(width: 8),
          Text('km', style: TextStyle(fontSize: 16, color: Colors.grey[700])),
        ],
      ),
    );
  }

  // 개별 정비 항목 카드
  Widget _buildMaintenanceItemCard(int index) {
    final item = _maintenanceItems[index];
    return Card(
      margin: const EdgeInsets.only(bottom: 16),
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            Row(
              children: [
                const Icon(Icons.settings_outlined, color: Colors.grey),
                const SizedBox(width: 12),
                Expanded(
                  child: DropdownButton<String>(
                    value: item.selectedType,
                    isExpanded: true,
                    underline: const SizedBox.shrink(),
                    items: _maintenanceTypes.map((String value) {
                      return DropdownMenuItem<String>(
                        value: value,
                        child: Text(value),
                      );
                    }).toList(),
                    onChanged: (newValue) {
                      setState(() {
                        item.selectedType = newValue;
                      });
                    },
                  ),
                ),
              ],
            ),
            const Divider(),
            TextField(
              controller: item.costController,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                labelText: '지출금액',
                border: InputBorder.none,
                suffixText: '₩',
              ),
            ),
            const Divider(),
            TextField(
              controller: item.memoController,
              decoration: const InputDecoration(
                labelText: '메모, 특이사항',
                hintText: '(250자, 이모티콘 불가)',
                border: InputBorder.none,
              ),
              maxLength: 250,
            ),
          ],
        ),
      ),
    );
  }

  // 항목 추가/삭제 버튼
  Widget _buildAddRemoveButtons() {
    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        TextButton.icon(
          onPressed: () => _removeItem(_maintenanceItems.length - 1),
          icon: const Icon(Icons.close),
          label: const Text('항목 삭제'),
        ),
        const SizedBox(height: 20, child: VerticalDivider()),
        TextButton.icon(
          onPressed: _addNewItem,
          icon: const Icon(Icons.add),
          label: const Text('항목 추가'),
        ),
      ],
    );
  }
}