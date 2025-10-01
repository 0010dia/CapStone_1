import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:intl/intl.dart';

// ⭐️ 1. '가득/부분 주유' 선택을 위한 enum 삭제
// enum FuelingType { full, partial }

class FuelRecordPage extends StatefulWidget {
  const FuelRecordPage({super.key});

  @override
  State<FuelRecordPage> createState() => _FuelRecordPageState();
}

class _FuelRecordPageState extends State<FuelRecordPage> {
  // ⭐️ 2. '가득/부분 주유' 상태 관리 변수 삭제
  // FuelingType? _fuelingType = FuelingType.full;

  String getToday() {
    return DateFormat('yyyy.MM.dd (E)', 'ko_KR').format(DateTime.now());
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[100],
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 1,
        leading: IconButton(
          icon: const Icon(Icons.close, color: Colors.black),
          onPressed: () => Navigator.of(context).pop(),
        ),
        title: Column(
          children: [
            const Text('주유 기록', style: TextStyle(color: Colors.black, fontSize: 18)),
            Text(
              getToday(),
              style: TextStyle(color: Colors.grey[600], fontSize: 14),
            ),
          ],
        ),
        centerTitle: true,
        actions: [
          TextButton(
            onPressed: () {
              Navigator.of(context).pop();
            },
            child: const Text('완료', style: TextStyle(color: Colors.blue, fontSize: 16)),
          )
        ],
      ),
      body: GestureDetector(
        onTap: () => FocusScope.of(context).unfocus(),
        child: ListView(
          padding: const EdgeInsets.all(16.0),
          children: [
            _buildLocationInput(),
            const SizedBox(height: 16),
            _buildNumericInputRow(
              icon: Icons.speed_outlined,
              label: '누적주행거리',
              unit: 'km',
              isDropdown: true,
            ),
            const SizedBox(height: 16),
            _buildNumericInputRow(
              icon: Icons.receipt_long_outlined,
              label: '주유금액',
              unit: '₩',
            ),
            const SizedBox(height: 16),
            _buildNumericInputRow(
              icon: Icons.local_gas_station_outlined,
              label: '휘발유',
              unit: '₩',
              isDropdown: true,
            ),
            const SizedBox(height: 16),
            _buildNumericInputRow(
              icon: Icons.opacity_outlined,
              label: '주유량',
              unit: 'L',
            ),
            const SizedBox(height: 24),
            // ⭐️ 3. '가득/부분 주유' 선택 위젯과 '세차비' 입력 위젯 호출 코드 삭제
            // _buildFuelingTypeSelector(),
            // const SizedBox(height: 24),
            // _buildNumericInputRow(
            //   icon: Icons.wash_outlined,
            //   label: '세차비',
            //   unit: '₩',
            // ),
            // const SizedBox(height: 24),
            _buildMemoInput(),
          ],
        ),
      ),
    );
  }

  Widget _buildLocationInput() {
    return Container(
      padding: const EdgeInsets.all(12),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(8),
      ),
      child: Row(
        children: [
          const Icon(Icons.location_on_outlined, color: Colors.grey),
          const SizedBox(width: 12),
          Expanded(
            child: TextFormField(
              initialValue: '송정주유소',
              decoration: const InputDecoration(
                hintText: '주유소 이름을 입력하세요',
                border: InputBorder.none,
                isDense: true,
              ),
              style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
          ),
          TextButton(
            onPressed: () {},
            child: const Text('변경'),
          ),
        ],
      ),
    );
  }

  Widget _buildNumericInputRow({
    required IconData icon,
    required String label,
    required String unit,
    bool isDropdown = false,
  }) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(8),
      ),
      child: Row(
        children: [
          Icon(icon, color: Colors.grey[600]),
          const SizedBox(width: 12),
          Text(label, style: const TextStyle(fontSize: 16)),
          if (isDropdown) const Icon(Icons.arrow_drop_down, color: Colors.grey),
          const Spacer(),
          SizedBox(
            width: 120,
            child: TextFormField(
              textAlign: TextAlign.end,
              keyboardType: const TextInputType.numberWithOptions(decimal: true),
              inputFormatters: [FilteringTextInputFormatter.allow(RegExp(r'^\d+\.?\d*'))],
              decoration: const InputDecoration(
                hintText: '0',
                border: InputBorder.none,
                isDense: true,
                contentPadding: EdgeInsets.zero,
              ),
              style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
          ),
          const SizedBox(width: 8),
          Text(unit, style: TextStyle(fontSize: 16, color: Colors.grey[700])),
        ],
      ),
    );
  }

  // ⭐️ 4. '가득/부분 주유' 위젯을 만드는 함수 전체 삭제
  // Widget _buildFuelingTypeSelector() { ... }

  Widget _buildMemoInput() {
    return Container(
      padding: const EdgeInsets.all(12),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(8),
      ),
      child: Row(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Icon(Icons.notes_outlined, color: Colors.grey[600]),
          const SizedBox(width: 12),
          Expanded(
            child: TextFormField(
              maxLines: 4,
              maxLength: 250,
              decoration: const InputDecoration(
                hintText: '메모, 특이사항 (250자, 이모티콘 불가)',
                border: InputBorder.none,
                counterText: '',
              ),
            ),
          ),
        ],
      ),
    );
  }
}