import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:intl/intl.dart';

class FuelHistoryPage extends StatelessWidget {
  const FuelHistoryPage({super.key});

  @override
  Widget build(BuildContext context) {
    final user = FirebaseAuth.instance.currentUser;

    if (user == null) {
      return const Scaffold(
        body: Center(child: Text('로그인이 필요합니다.')),
      );
    }

    return Scaffold(
      backgroundColor: Colors.grey[100],
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 1,
        title: const Text('주유 내역', style: TextStyle(color: Colors.black)),
        centerTitle: true,
      ),
      body: StreamBuilder<QuerySnapshot>(
        stream: FirebaseFirestore.instance
            .collection('users')
            .doc(user.uid)
            .collection('fuel_records')
            .orderBy('date', descending: true)
            .snapshots(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Center(child: CircularProgressIndicator());
          }

          if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
            return const Center(child: Text('저장된 주유 기록이 없습니다.'));
          }

          final records = snapshot.data!.docs.map((doc) {
            final data = doc.data() as Map<String, dynamic>;
            return {
              'date': data['date'] ?? '',
              'amount': data['amount'] ?? 0.0,
              'price': data['price'] ?? 0,
              'station': data['station'] ?? '',
              'createdAt': (data['createdAt'] as Timestamp?)?.toDate(),
            };
          }).toList();

          // 🔹 월별 그룹화
          final Map<String, List<Map<String, dynamic>>> grouped = {};
          for (var r in records) {
            if (r['date'] == '') continue;
            final monthKey = r['date'].substring(0, 7); // yyyy-MM
            grouped.putIfAbsent(monthKey, () => []).add(r);
          }

          // 🔹 전체 통계 계산
          double totalFuel = 0;
          int totalCost = 0;
          for (var r in records) {
            totalFuel += (r['amount'] as num).toDouble();
            totalCost += (r['price'] as num).toInt();
          }

          return ListView(
            children: [
              _buildOverallSummary(totalFuel, totalCost),
              for (var entry in grouped.entries)
                _buildMonthlyRecord(entry.key, entry.value),
            ],
          );
        },
      ),
    );
  }

  // ✅ 전체 요약 카드
  Widget _buildOverallSummary(double totalFuel, int totalCost) {
    return Container(
      color: Colors.teal.shade300,
      padding: const EdgeInsets.all(16.0),
      child: Column(
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              _buildSummaryMetric(label: '총 주유량', value: totalFuel.toStringAsFixed(2), unit: 'L'),
              _buildSummaryMetric(label: '총 주유비', value: '₩ ${NumberFormat("#,###").format(totalCost)}'),
            ],
          ),
        ],
      ),
    );
  }

  // ✅ 월별 기록 섹션
  Widget _buildMonthlyRecord(String month, List<Map<String, dynamic>> records) {
    double totalFuel = 0;
    int totalCost = 0;

    for (var r in records) {
      totalFuel += (r['amount'] as num).toDouble();
      totalCost += (r['price'] as num).toInt();
    }

    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 16.0, vertical: 8.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(
            '${month.split('-')[1]}월',
            style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
          ),
          const SizedBox(height: 8),
          Container(
            padding: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(12),
            ),
            child: Column(
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    _buildSummaryMetric(label: '총 주유량', value: '${totalFuel.toStringAsFixed(2)} L', textColor: Colors.black87),
                    _buildSummaryMetric(label: '총 주유비', value: '₩ ${NumberFormat("#,###").format(totalCost)}', textColor: Colors.black87),
                  ],
                ),
                const SizedBox(height: 12),
                const Divider(),
                for (var r in records)
                  _buildFuelRecordItem(
                    date: r['date'].substring(5), // MM-dd → dd만
                    fuelAmount: '${r['amount']}L',
                    station: r['station'],
                    totalCost: '₩ ${NumberFormat("#,###").format(r['price'])}',
                  ),
              ],
            ),
          ),
        ],
      ),
    );
  }

  // ✅ 요약 정보 위젯
  Widget _buildSummaryMetric({
    required String label,
    required String value,
    String? unit,
    Color textColor = Colors.white,
  }) {
    return Expanded(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(label, style: TextStyle(color: textColor.withOpacity(0.7), fontSize: 12)),
          Row(
            crossAxisAlignment: CrossAxisAlignment.baseline,
            textBaseline: TextBaseline.alphabetic,
            children: [
              Text(value, style: TextStyle(color: textColor, fontSize: 16, fontWeight: FontWeight.bold)),
              if (unit != null)
                Text(' $unit', style: TextStyle(color: textColor.withOpacity(0.7), fontSize: 12)),
            ],
          )
        ],
      ),
    );
  }

  // ✅ 개별 주유 기록 위젯
  Widget _buildFuelRecordItem({
    required String date,
    required String fuelAmount,
    required String station,
    required String totalCost,
  }) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: Row(
        children: [
          CircleAvatar(
            backgroundColor: Colors.blueAccent,
            radius: 22,
            child: const Icon(Icons.local_gas_station, color: Colors.white, size: 24),
          ),
          const SizedBox(width: 12),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text("주유 $fuelAmount", style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
                Text(station, overflow: TextOverflow.ellipsis, style: TextStyle(color: Colors.grey[600])),
              ],
            ),
          ),
          Column(
            crossAxisAlignment: CrossAxisAlignment.end,
            children: [
              Text(totalCost, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
              Text(date, style: TextStyle(color: Colors.grey[600], fontSize: 12)),
            ],
          ),
        ],
      ),
    );
  }
}
