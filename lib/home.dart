import 'package:flutter/material.dart';
import 'car_info_page.dart';
import 'fuel_history_page.dart';
import 'maintenance_record_page.dart';
import 'statistics_page.dart';


class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[100],
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.symmetric(vertical: 10.0),
          child: Column(
            children: [
              _buildCarInfoCard(context),
              const SizedBox(height: 12),
              _buildRecentRecordsCard(context), // context 전달
              const SizedBox(height: 12),
              _buildMaintenanceCard(context), // context 전달
            ],
          ),
        ),
      ),
    );
  }

  // '내 차 정보' 카드
  Widget _buildCarInfoCard(BuildContext context) {
    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 16),
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: const Color.fromARGB(255, 160, 160, 160),
        borderRadius: BorderRadius.circular(12),
      ),
      child: Column(
        children: [
          Row(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Text("pcx",
                        style: TextStyle(
                            color: Colors.white,
                            fontSize: 30,
                            fontWeight: FontWeight.bold)),
                    const Text("172일 째 관리 중",
                        style: TextStyle(color: Colors.white)),
                    const SizedBox(height: 8),
                    ElevatedButton(
                      onPressed: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                              builder: (context) => const CarInfoPage()),
                        );
                      },
                      style: ElevatedButton.styleFrom(
                          backgroundColor: Colors.grey[700]),
                      child: const Text("내 차 정보",
                          style: TextStyle(color: Colors.white)),
                    ),
                  ],
                ),
              ),
              // assets/img.PNG 경로에 파일이 있는지 꼭 확인해주세요!
              Image.asset("assets/img.PNG", width: 150),
            ],
          ),
          const Divider(color: Colors.white24, height: 20),
          const Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              Column(
                children: [
                  Text("누적주행거리", style: TextStyle(color: Colors.white)),
                  SizedBox(height: 4),
                  Text("2,947.9 km",
                      style: TextStyle(
                          color: Colors.white,
                          fontSize: 18,
                          fontWeight: FontWeight.bold)),
                ],
              ),
              SizedBox(
                  height: 30, child: VerticalDivider(color: Colors.white24)),
              Column(
                children: [
                  Text("평균 연비", style: TextStyle(color: Colors.white)),
                  SizedBox(height: 4),
                  Text("22.4 km/L",
                      style: TextStyle(
                          color: Colors.white,
                          fontSize: 18,
                          fontWeight: FontWeight.bold)),
                ],
              ),
            ],
          ),
        ],
      ),
    );
  }

  // '최근 기록' 카드 위젯
  Widget _buildRecentRecordsCard(BuildContext context) {
    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 16),
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
              const Text("최근 기록",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
              GestureDetector(
                onTap: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                        builder: (context) => const FuelHistoryPage()),
                  );
                },
                child: Text("더보기 >", style: TextStyle(color: Colors.grey[600])),
              ),
            ],
          ),
          const SizedBox(height: 10),
          _buildFuelRecordItem(
            iconColor: Colors.teal,
            date: "09.27",
            fuelAmount: "8.49L",
            station: "대성산업(주)대성물류터미널2주유소",
            distance: "175 km",
            efficiency: "20.64 km/L",
            totalCost: "₩13,479",
            pricePerLiter: "1,588₩/L",
          ),
          const Divider(),
          _buildFuelRecordItem(
            iconColor: Colors.orange,
            date: "08.15",
            fuelAmount: "6.96L",
            station: "보성주유소",
            distance: "157 km",
            efficiency: "22.57 km/L",
            totalCost: "₩11,187",
            pricePerLiter: "1,608₩/L",
          ),
          const Divider(),
          _buildFuelRecordItem(
            iconColor: Colors.blue,
            date: "08.14",
            fuelAmount: "7.28L",
            station: "세방주유소",
            distance: "179 km",
            efficiency: "24.54 km/L",
            totalCost: "₩11,540",
            pricePerLiter: "1,585₩/L",
          ),
        ],
      ),
    );
  }

  // '정비 목록' 및 통계 카드 위젯
  Widget _buildMaintenanceCard(BuildContext context) {
    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 16),
      padding: const EdgeInsets.symmetric(vertical: 8),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        children: [
          _buildMaintenanceButton(
              context, Icons.build_circle_outlined, "정비목록"),
          _buildMaintenanceButton(context, Icons.article_outlined, "기록"),
          _buildMaintenanceButton(context, Icons.bar_chart_outlined, "통계"),
          _buildMaintenanceButton(
              context, Icons.calendar_today_outlined, "점검일정"),
        ],
      ),
    );
  }

  // 주유 기록 아이템 위젯
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
              CircleAvatar(
                backgroundColor: iconColor,
                radius: 22,
                child: const Icon(Icons.local_gas_station,
                    color: Colors.white, size: 24),
              ),
              const SizedBox(height: 4),
              Text(date,
                  style: TextStyle(color: Colors.grey[600], fontSize: 12)),
            ],
          ),
          const SizedBox(width: 12),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  children: [
                    Text("주유 $fuelAmount",
                        style: const TextStyle(
                            fontWeight: FontWeight.bold, fontSize: 16)),
                    const SizedBox(width: 4),
                    Container(
                      padding: const EdgeInsets.symmetric(
                          horizontal: 6, vertical: 2),
                      decoration: BoxDecoration(
                        border: Border.all(color: Colors.grey.shade300),
                        borderRadius: BorderRadius.circular(4),
                      ),
                      child: const Text("가득",
                          style: TextStyle(fontSize: 10, color: Colors.grey)),
                    ),
                  ],
                ),
                Text(station,
                    overflow: TextOverflow.ellipsis,
                    style: TextStyle(color: Colors.grey[600])),
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
              Text(totalCost,
                  style: const TextStyle(
                      fontWeight: FontWeight.bold, fontSize: 16)),
              Text(pricePerLiter,
                  style: TextStyle(color: Colors.grey[600], fontSize: 12)),
            ],
          ),
        ],
      ),
    );
  }

  // 정비 카드 내부 버튼 위젯
  Widget _buildMaintenanceButton(
      BuildContext context, IconData icon, String label) {
    return TextButton(
      onPressed: () {
        if (label == "통계") {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const StatisticsPage()),
          );
        }
        if (label == "기록") {
          Navigator.push(
            context,
            MaterialPageRoute(
                builder: (context) => const MaintenanceRecordPage()),
          );
        }
      },
      child: Column(
        children: [
          Icon(icon, color: Colors.blue[700], size: 28),
          const SizedBox(height: 4),
          Text(label, style: const TextStyle(color: Colors.black87)),
        ],
      ),
    );
  }
}