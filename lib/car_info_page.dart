import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'manufacturer_select_page.dart';

class CarInfoPage extends StatefulWidget {
  const CarInfoPage({super.key});

  @override
  State<CarInfoPage> createState() => _CarInfoPageState();
}

class _CarInfoPageState extends State<CarInfoPage> {
  // 기본 차량 정보
  String _manufacturer = "PCX";
  String _model = "pcx 125";
  String _logoAsset = "assets/logos/honda.png";

  // 상세 정보
  late TextEditingController _yearController;
  late TextEditingController _tankCapacityController;
  late TextEditingController _fuelEfficiencyController;
  late TextEditingController _displacementController;

  String _selectedTransmission = "자동";
  String _selectedFuelType = "휘발유";

  bool _isLoading = true;

  @override
  void initState() {
    super.initState();

    // 컨트롤러 초기화
    _yearController = TextEditingController(text: "2025.03");
    _tankCapacityController = TextEditingController(text: "15");
    _fuelEfficiencyController = TextEditingController(text: "24");
    _displacementController = TextEditingController(text: "650");

    _loadCarInfo();
  }

  @override
  void dispose() {
    _yearController.dispose();
    _tankCapacityController.dispose();
    _fuelEfficiencyController.dispose();
    _displacementController.dispose();
    super.dispose();
  }

  // Firestore에서 차량 정보 불러오기
  Future<void> _loadCarInfo() async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) return;

    final docRef = FirebaseFirestore.instance.collection('users').doc(user.uid);
    final doc = await docRef.get();

    if (doc.exists) {
      final data = doc.data()!;
      setState(() {
        _manufacturer = data['manufacturer'] ?? _manufacturer;
        _model = data['model'] ?? _model;
        _logoAsset = data['logoAsset'] ?? _logoAsset;
        _yearController.text = data['year'] ?? _yearController.text;
        _selectedTransmission = data['transmission'] ?? _selectedTransmission;
        _selectedFuelType = data['fuelType'] ?? _selectedFuelType;
        _tankCapacityController.text = data['tankCapacity'] ?? _tankCapacityController.text;
        _fuelEfficiencyController.text = data['fuelEfficiency'] ?? _fuelEfficiencyController.text;
        _displacementController.text = data['displacement'] ?? _displacementController.text;
        _isLoading = false;
      });
    } else {
      await docRef.set({
        'manufacturer': _manufacturer,
        'model': _model,
        'logoAsset': _logoAsset,
        'year': _yearController.text,
        'transmission': _selectedTransmission,
        'fuelType': _selectedFuelType,
        'tankCapacity': _tankCapacityController.text,
        'fuelEfficiency': _fuelEfficiencyController.text,
        'displacement': _displacementController.text,
      });
      setState(() {
        _isLoading = false;
      });
    }
  }

  // Firestore에 차량 정보 저장
  Future<void> _saveCarInfo() async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) return;

    await FirebaseFirestore.instance.collection('users').doc(user.uid).set({
      'manufacturer': _manufacturer,
      'model': _model,
      'logoAsset': _logoAsset,
      'year': _yearController.text,
      'transmission': _selectedTransmission,
      'fuelType': _selectedFuelType,
      'tankCapacity': _tankCapacityController.text,
      'fuelEfficiency': _fuelEfficiencyController.text,
      'displacement': _displacementController.text,
      'updatedAt': FieldValue.serverTimestamp(),
    }, SetOptions(merge: true));

    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(content: Text('차량 정보가 저장되었습니다.')),
    );
    Navigator.of(context).pop();
  }

  @override
  Widget build(BuildContext context) {
    if (_isLoading) {
      return const Scaffold(
        body: Center(child: CircularProgressIndicator()),
      );
    }

    return Scaffold(
      appBar: AppBar(
        leading: IconButton(
          icon: const Icon(Icons.close),
          onPressed: () => Navigator.of(context).pop(),
        ),
        title: const Text('차량 정보'),
        actions: [
          TextButton(
            onPressed: _saveCarInfo,
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

  Widget _buildSectionHeader(String title) {
    return Padding(
      padding: const EdgeInsets.only(bottom: 8.0),
      child: Text(title,
          style: TextStyle(fontSize: 16, color: Colors.blue.shade700)),
    );
  }

  Widget _buildBasicInfoCard() {
    return Card(
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Row(
          children: [
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
                final result = await Navigator.push<Map<String, String>>(
                  context,
                  MaterialPageRoute(
                      builder: (context) => const ManufacturerSelectPage()),
                );

                if (result != null && result.containsKey('manufacturer')) {
                  setState(() {
                    _manufacturer = result['manufacturer']!;
                    _model = result['model']!;
                    _logoAsset = result['logoAsset'] ?? _logoAsset;
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

  Widget _buildDetailInfoGrid() {
    return Card(
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            _buildDetailRow("연식", controller: _yearController),
            const Divider(),
            _buildDetailRow("변속기",
                value: _selectedTransmission, dropdownItems: ["자동", "수동"]),
            const Divider(),
            _buildDetailRow("연료 종류",
                value: _selectedFuelType, dropdownItems: ["휘발유", "경유", "전기"]),
            const Divider(),
            _buildDetailRow("연료탱크 용량", controller: _tankCapacityController, unit: "L"),
            const Divider(),
            _buildDetailRow("공인연비", controller: _fuelEfficiencyController, unit: "KM/L"),
            const Divider(),
            _buildDetailRow("배기량", controller: _displacementController, unit: "CC"),
          ],
        ),
      ),
    );
  }

  Widget _buildDetailRow(String label,
      {TextEditingController? controller,
        String? value,
        List<String>? dropdownItems,
        String? unit}) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(label, style: TextStyle(color: Colors.grey.shade600)),
          if (controller != null)
            SizedBox(
              width: 120,
              child: TextField(
                controller: controller,
                textAlign: TextAlign.right,
                decoration: const InputDecoration(isDense: true, border: OutlineInputBorder()),
              ),
            )
          else if (dropdownItems != null)
            DropdownButton<String>(
              value: value,
              items: dropdownItems
                  .map((item) => DropdownMenuItem(
                value: item,
                child: Text(item),
              ))
                  .toList(),
              onChanged: (val) {
                setState(() {
                  if (label == "변속기") _selectedTransmission = val!;
                  if (label == "연료 종류") _selectedFuelType = val!;
                });
              },
            )
          else
            Text(value ?? ""),
          if (unit != null) ...[
            const SizedBox(width: 8),
            Text(unit, style: TextStyle(color: Colors.grey.shade600)),
          ]
        ],
      ),
    );
  }
}
