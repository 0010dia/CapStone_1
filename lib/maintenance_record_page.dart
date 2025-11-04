import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';

class MaintenanceItem {
  String? selectedType;
  final TextEditingController costController = TextEditingController();
  final TextEditingController memoController = TextEditingController();

  MaintenanceItem({this.selectedType});

  Map<String, dynamic> toMap() {
    return {
      'type': selectedType,
      'cost': costController.text.trim(),
      'memo': memoController.text.trim(),
    };
  }
}

class MaintenanceRecordPage extends StatefulWidget {
  const MaintenanceRecordPage({super.key});

  @override
  State<MaintenanceRecordPage> createState() => _MaintenanceRecordPageState();
}

class _MaintenanceRecordPageState extends State<MaintenanceRecordPage> {
  final List<MaintenanceItem> _maintenanceItems = [];
  final List<String> _maintenanceTypes = ['엔진 오일', '타이어', '브레이크', '체인', '기타'];
  final TextEditingController _odometerController = TextEditingController();

  @override
  void initState() {
    super.initState();
    _addNewItem();
  }

  @override
  void dispose() {
    _odometerController.dispose();
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
    if (_maintenanceItems.length > 1) {
      setState(() {
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

  Future<void> _saveRecord() async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('로그인이 필요합니다.')),
      );
      return;
    }

    try {
      final recordData = {
        'date': DateTime.now(),
        'odometer': _odometerController.text.trim(),
        'items': _maintenanceItems.map((item) => item.toMap()).toList(),
      };

      await FirebaseFirestore.instance
          .collection('users')
          .doc(user.uid)
          .collection('maintenance_records')
          .add(recordData);

      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('정비 기록이 저장되었습니다.')),
      );

      Navigator.of(context).pop();
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('저장 실패: $e')),
      );
    }
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
            onPressed: _saveRecord,
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
            ListView.builder(
              shrinkWrap: true,
              physics: const NeverScrollableScrollPhysics(),
              itemCount: _maintenanceItems.length,
              itemBuilder: (context, index) => _buildMaintenanceItemCard(index),
            ),
            const SizedBox(height: 16),
            _buildAddRemoveButtons(),
          ],
        ),
      ),
    );
  }

  Widget _buildOdometerRow() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(8),
        border: Border.all(color: Colors.grey.shade300),
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
              controller: _odometerController,
              textAlign: TextAlign.end,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                border: InputBorder.none,
                hintText: '예: 3123.1',
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
