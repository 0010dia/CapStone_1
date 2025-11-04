import 'package:flutter/material.dart';
import 'car_info_page.dart';
import 'fuel_history_page.dart';
import 'maintenance_record_page.dart';
import 'statistics_page.dart';
import 'maintenance_list_page.dart';
import 'maintenance_schedule_page.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';

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
    final user = FirebaseAuth.instance.currentUser;

    if (user == null) {
      return const Center(
        child: Text('로그인이 필요합니다.'),
      );
    }

    return StreamBuilder<DocumentSnapshot>(
      stream: FirebaseFirestore.instance
          .collection('users')
          .doc(user.uid)
          .snapshots(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator());
        }

        if (!snapshot.hasData || !snapshot.data!.exists) {
          return Container(
            margin: const EdgeInsets.symmetric(horizontal: 16),
            padding: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: Colors.grey[300],
              borderRadius: BorderRadius.circular(12),
            ),
            child: const Text(
              '차량 정보가 없습니다.\n"내 차 정보" 페이지에서 등록해주세요.',
              textAlign: TextAlign.center,
            ),
          );
        }

        final data = snapshot.data!.data() as Map<String, dynamic>;
        final manufacturer = (data['manufacturer'] ?? '제조사 정보 없음').toString();
        final model = (data['model'] ?? '모델 정보 없음').toString();
        final year = (data['year'] ?? '연식 정보 없음').toString();
        final fuelType = (data['fuelType'] ?? '연료 정보 없음').toString();

        // 🔹 manufacturer에 따라 로컬 로고 자동 매칭
        String logoPath = 'assets/logos/${manufacturer.toLowerCase()}.png';

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
                        Text(
                          '$manufacturer / $model',
                          style: const TextStyle(
                            color: Colors.white,
                            fontSize: 24,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
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
                  Image.asset(
                    logoPath,
                    width: 80,
                    height: 80,
                    fit: BoxFit.contain,
                    errorBuilder: (context, error, stackTrace) {
                      return Image.network(
                        'https://cdn-icons-png.flaticon.com/512/1995/1995574.png',
                        width: 80,
                        height: 80,
                      );
                    },
                  ),
                ],
              ),
              const Divider(color: Colors.white24, height: 20),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  Column(
                    children: [
                      const Text("연식", style: TextStyle(color: Colors.white)),
                      const SizedBox(height: 4),
                      Text(
                        year,
                        style: const TextStyle(
                          color: Colors.white,
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    ],
                  ),
                  const SizedBox(
                      height: 30, child: VerticalDivider(color: Colors.white24)),
                  Column(
                    children: [
                      const Text("연료 종류", style: TextStyle(color: Colors.white)),
                      const SizedBox(height: 4),
                      Text(
                        fuelType,
                        style: const TextStyle(
                          color: Colors.white,
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    ],
                  ),
                ],
              ),
            ],
          ),
        );
      },
    );
  }





  // '최근 기록' 카드 위젯
  Widget _buildRecentRecordsCard(BuildContext context) {
    final user = FirebaseAuth.instance.currentUser;

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
              const Text(
                "최근 기록",
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
              ),
              GestureDetector(
                onTap: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => const FuelHistoryPage(),
                    ),
                  );
                },
                child: Text("더보기 >", style: TextStyle(color: Colors.grey[600])),
              ),
            ],
          ),
          const SizedBox(height: 10),

          // ✅ Firestore에서 주유기록 실시간 가져오기
          if (user == null)
            const Text('로그인이 필요합니다.')
          else
            StreamBuilder<QuerySnapshot>(
              stream: FirebaseFirestore.instance
                  .collection('users')
                  .doc(user.uid)
                  .collection('fuel_records')
                  .orderBy('createdAt', descending: true)
                  .limit(3) // 🔹 최근 3개만 표시
                  .snapshots(),
              builder: (context, snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return const Center(child: CircularProgressIndicator());
                }

                if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
                  return const Padding(
                    padding: EdgeInsets.all(8.0),
                    child: Text('최근 주유 기록이 없습니다.'),
                  );
                }

                final records = snapshot.data!.docs;

                return Column(
                  children: records.map((doc) {
                    final data = doc.data() as Map<String, dynamic>;

                    final date = data['date'] ?? '-';
                    final amount = data['amount']?.toString() ?? '-';
                    final price = data['price']?.toString() ?? '-';
                    final station = data['station'] ?? '주유소 미입력';

                    return Column(
                      children: [
                        _buildFuelRecordItem(
                          iconColor: Colors.teal,
                          date: date,
                          fuelAmount: "${amount}L",
                          station: station,
                          distance: "", // 거리 계산 기능 추가 가능
                          efficiency: "",
                          totalCost: "₩$price",
                          pricePerLiter: "",
                        ),
                        if (records.last.id != doc.id) const Divider(),
                      ],
                    );
                  }).toList(),
                );
              },
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
        if (label == "정비목록") {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => const MaintenanceListPage(),
            ),
          );
        } else if (label == "기록") {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => const MaintenanceRecordPage(),
            ),
          );
        } else if (label == "통계") {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => const StatisticsPage(),
            ),
          );
        } else if (label == "점검일정") {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => const MaintenanceSchedulePage(),
            ),
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