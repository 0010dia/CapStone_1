import 'package:flutter/material.dart';

class FuelHistoryPage extends StatelessWidget {
  const FuelHistoryPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[100],
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 1,
        title: Row(
          mainAxisSize: MainAxisSize.min,
          children: const [
            Text('전체', style: TextStyle(color: Colors.black)),
            SizedBox(width: 4),
            Text('2025년', style: TextStyle(color: Colors.black)),
            Icon(Icons.arrow_drop_down, color: Colors.black),
          ],
        ),
        centerTitle: true,
        actions: [
          IconButton(
            icon: const Icon(Icons.search, color: Colors.black),
            onPressed: () {},
          ),
        ],
      ),
      body: ListView(
        children: [
          _buildOverallSummary(),
          _buildMonthlyRecord(
            month: '09',
            totalFuel: '8.49 L',
            totalDistance: '175.2 km',
            avgEfficiency: '20.64 km/L',
            totalCost: '₩ 13,479',
            records: [
              _buildFuelRecordItem(
                iconColor: Colors.teal, date: "09.27", fuelAmount: "8.49L",
                station: "대성산업(주)대성물류터미널2주유소", distance: "175 km",
                efficiency: "20.64 km/L", totalCost: "₩13,479", pricePerLiter: "1,588₩/L",
              ),
            ],
          ),
          _buildMonthlyRecord(
            month: '08',
            totalFuel: '27.65 L',
            totalDistance: '697.9 km',
            avgEfficiency: '25.24 km/L',
            totalCost: '₩ 43,808',
            records: [
              _buildFuelRecordItem(
                iconColor: Colors.orange, date: "08.15", fuelAmount: "6.96L",
                station: "보성주유소", distance: "157 km",
                efficiency: "22.57 km/L", totalCost: "₩11,187", pricePerLiter: "1,608₩/L",
              ),
              _buildFuelRecordItem(
                iconColor: Colors.blue, date: "08.14", fuelAmount: "7.28L",
                station: "세방주유소", distance: "179 km",
                efficiency: "24.54 km/L", totalCost: "₩11,540", pricePerLiter: "1,585₩/L",
              ),
              _buildFuelRecordItem(
                iconColor: Colors.yellow.shade700, date: "08.13", fuelAmount: "8.95L",
                station: "만남의셀프주유소", distance: "224 km",
                efficiency: "25.01 km/L", totalCost: "₩14,047", pricePerLiter: "1,569₩/L",
              ),
              _buildFuelRecordItem(
                iconColor: Colors.red, date: "08.03", fuelAmount: "4.46L",
                station: "원평동양주유소", distance: "138 km",
                efficiency: "31.02 km/L", totalCost: "₩7,034", pricePerLiter: "1,570₩/L",
              ),
            ],
          ),
          _buildMonthlyRecord(
            month: '07',
            totalFuel: '5.31 L',
            totalDistance: '157.6 km',
            avgEfficiency: '29.68 km/L',
            totalCost: '₩ 8,496',
            records: [
              _buildFuelRecordItem(
                iconColor: Colors.green, date: "07.25", fuelAmount: "5.31L",
                station: "지에스칼텍스(주)직영 가능주유소", distance: "157.6 km",
                efficiency: "29.68 km/L", totalCost: "₩8,496", pricePerLiter: "1,600₩/L",
              ),
            ],
          ),
        ],
      ),
      floatingActionButton: FloatingActionButton.extended(
        onPressed: () {},
        icon: const Icon(Icons.edit),
        label: const Text('기록하기'),
        backgroundColor: Colors.blue,
      ),
    );
  }

  // 연간 전체 요약 카드
  Widget _buildOverallSummary() {
    return Container(
      color: Colors.teal.shade300,
      padding: const EdgeInsets.all(16.0),
      child: Column(
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              _buildSummaryMetric(label: '총 주유량', value: '139.9', unit: 'L'),
              _buildSummaryMetric(label: '총 운행거리 (주유)', value: '2,923.1', unit: 'km'),
            ],
          ),
          const SizedBox(height: 16),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              _buildSummaryMetric(label: '평균 연비', value: '22.28', unit: 'km/L'),
              _buildSummaryMetric(label: '총 주유비', value: '₩ 218,616'),
            ],
          ),
          const SizedBox(height: 16),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              _buildSummaryMetric(label: '총 지출', value: '₩ 218,616'),
              const Spacer(),
            ],
          )
        ],
      ),
    );
  }

  // 월별 기록 섹션
  Widget _buildMonthlyRecord({
    required String month,
    required String totalFuel,
    required String totalDistance,
    required String avgEfficiency,
    required String totalCost,
    required List<Widget> records,
  }) {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 16.0, vertical: 8.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Padding(
            padding: const EdgeInsets.symmetric(vertical: 8.0),
            child: Text('$month 월', style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
          ),
          Container(
            padding: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(12),
            ),
            child: Column(
              children: [
                // 월별 요약 정보
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    _buildSummaryMetric(label: '총 주유량', value: totalFuel, textColor: Colors.black87),
                    _buildSummaryMetric(label: '총 운행거리 (주유)', value: totalDistance, textColor: Colors.black87),
                  ],
                ),
                const SizedBox(height: 12),
                Row(
                  children: [
                    _buildSummaryMetric(label: '평균 연비', value: avgEfficiency, textColor: Colors.black87),
                    _buildSummaryMetric(label: '총 주유비', value: totalCost, textColor: Colors.black87),
                  ],
                ),
                const SizedBox(height: 12),
                Row(
                  children: [
                    _buildSummaryMetric(label: '총 지출', value: totalCost, textColor: Colors.black87),
                    const Spacer(),
                  ],
                ),
                if (records.isNotEmpty) const Divider(height: 24),
                // 개별 주유 기록
                ...records,
              ],
            ),
          ),
        ],
      ),
    );
  }

  // 요약 정보 항목 위젯
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
              if (unit != null) ...[
                const SizedBox(width: 4),
                Text(unit, style: TextStyle(color: textColor.withOpacity(0.7), fontSize: 12)),
              ]
            ],
          )
        ],
      ),
    );
  }

  // 개별 주유 기록 아이템 위젯
  Widget _buildFuelRecordItem({
    required Color iconColor,
    required String date,
    required String fuelAmount,
    required String station,
    required String distance,
    required String efficiency,
    required String totalCost,
    required String pricePerLiter,
  }) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: Row(
        children: [
          Column(
            children: [
              // ⭐️ 이 부분을 수정하여 아이콘을 추가합니다.
              CircleAvatar(
                backgroundColor: iconColor,
                radius: 22,
                child: const Icon(Icons.local_gas_station, color: Colors.white, size: 24),
              ),
              const SizedBox(height: 4),
              Text(date, style: TextStyle(color: Colors.grey[600], fontSize: 12)),
            ],
          ),
          const SizedBox(width: 12),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  children: [
                    Text("주유 $fuelAmount", style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
                    const SizedBox(width: 4),
                    Container(
                      padding: const EdgeInsets.symmetric(horizontal: 6, vertical: 2),
                      decoration: BoxDecoration(
                        border: Border.all(color: Colors.grey.shade300),
                        borderRadius: BorderRadius.circular(4),
                      ),
                      child: const Text("가득", style: TextStyle(fontSize: 10, color: Colors.grey)),
                    ),
                  ],
                ),
                Text(station, overflow: TextOverflow.ellipsis, style: TextStyle(color: Colors.grey[600])),
                Row(
                  children: [
                    Text("구간 $distance", style: const TextStyle(fontSize: 12)),
                    const SizedBox(width: 8),
                    Text(efficiency, style: const TextStyle(fontSize: 12)),
                  ],
                ),
              ],
            ),
          ),
          Column(
            crossAxisAlignment: CrossAxisAlignment.end,
            children: [
              Text(totalCost, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
              Text(pricePerLiter, style: TextStyle(color: Colors.grey[600], fontSize: 12)),
            ],
          ),
        ],
      ),
    );
  }
}