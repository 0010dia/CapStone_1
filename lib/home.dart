import 'package:flutter/material.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Column(
        children: [
          _buildCarInfoCard(),
          const SizedBox(height: 10),
          const Padding(
            padding: EdgeInsets.symmetric(horizontal: 16.0),
            child: Row(
              children: [
                Text("최근 기록", style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                Spacer(),
                Text("더보기", style: TextStyle(color: Colors.grey)),
              ],
            ),
          ),
          const SizedBox(height: 10),
          _buildFuelItem("보성주유소", "6.96L", "157 km", "22.57", "1,608", "₩11,187", "08.15", Colors.red),
          _buildFuelItem("세방주유소", "7.28L", "179 km", "24.54", "1,585", "₩11,540", "08.14", Colors.blue),
          _buildFuelItem("만남의셀프주유소", "8.95L", "174 km", "19.44", "1,565", "₩13,997", "08.13", Colors.amber[700]!),
        ],
      ),
    );
  }

  Widget _buildCarInfoCard() {
    return Container(
      margin: const EdgeInsets.all(16),
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: const Color.fromARGB(255, 160, 160, 160),
        borderRadius: BorderRadius.circular(12),
      ),
      child: Column(
        children: [
          Stack(
            children: [
              Row(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  //
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        const Text("pcx", style: TextStyle(color: Colors.white, fontSize: 30, fontWeight: FontWeight.bold)),
                        const Text("172일 째 관리 중", style: TextStyle(color: Colors.white)),
                        const SizedBox(height: 8),
                        ElevatedButton(
                          onPressed: () {},
                          style: ElevatedButton.styleFrom(backgroundColor: Colors.grey[700]),
                          child: const Text("내 차 정보", style: TextStyle(color: Colors.white)),
                        ),
                      ],
                    ),
                  ),
                   Image.asset("assets/img.PNG", width: 150),
                ],
              ),
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
                  Text("2,947.9 km", style: TextStyle(color: Colors.white, fontSize: 18, fontWeight: FontWeight.bold)),
                ],
              ),
              const Divider(color: Colors.white24, height: 20),
              Column(
                children: [
                  Text("평균 연비", style: TextStyle(color: Colors.white)),
                  SizedBox(height: 4),
                  Text("22.4 km/L", style: TextStyle(color: Colors.white, fontSize: 18, fontWeight: FontWeight.bold)),
                ],
              ),
            ],
          ),
        ],
      ),
    );
  }

  Widget _buildFuelItem(String station, String fuel, String distance, String efficiency, String pricePerL, String totalCost, String date, Color color) {
    return Card(
      margin: const EdgeInsets.symmetric(horizontal: 16, vertical: 6),
      child: ListTile(
        leading: CircleAvatar(
          backgroundColor: color,
          child: const Icon(Icons.local_gas_station, color: Colors.white),
        ),
        title: Text("주유 $fuel · $station"),
        subtitle: Text("$date · 구간 $distance · $efficiency km/L"),
        trailing: Column(
          crossAxisAlignment: CrossAxisAlignment.end,
          children: [
            Text("$totalCost", style: const TextStyle(fontSize: 15, fontWeight: FontWeight.bold)),
            Text("$pricePerL원/L", style: const TextStyle(fontSize: 12, color: Colors.grey)),
          ],
        ),
      ),
    );
  }
}