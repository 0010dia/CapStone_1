import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';

class StatisticsPage extends StatelessWidget {
  const StatisticsPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFF2C2C2E), // 어두운 배경색
      appBar: AppBar(
        backgroundColor: Colors.transparent,
        elevation: 0,
        leading: const BackButton(color: Colors.white),
        title: Row(
          mainAxisSize: MainAxisSize.min,
          children: const [
            Text('전체', style: TextStyle(color: Colors.white)),
            SizedBox(width: 4),
            Text('2025년', style: TextStyle(color: Colors.white)),
            Icon(Icons.arrow_drop_down, color: Colors.white),
          ],
        ),
        centerTitle: true,
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            _buildSummaryHeader(),
            const SizedBox(height: 30),
            _buildMonthlyExpenseChart(),
            const SizedBox(height: 30),
            _buildChartSection(
              title: '월별 평균연비',
              unit: '단위 km/L',
              chart: _buildBarChart(
                data: {7: 29.68, 8: 25.24, 9: 20.64},
                barColor: Colors.cyan,
              ),
            ),
            const SizedBox(height: 30),
            _buildChartSection(
              title: '월별 주유량',
              unit: '단위 L',
              chart: _buildBarChart(
                data: {7: 5.31, 8: 27.65, 9: 8.49},
                barColor: Colors.redAccent,
              ),
            ),
            const SizedBox(height: 30),
            _buildChartSection(
              title: '월별 운행거리 (주유)',
              unit: '단위 km',
              chart: _buildBarChart(
                data: {7: 157.6, 8: 697.9, 9: 175.2},
                barColor: Colors.tealAccent,
                maxY: 1000,
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildSummaryHeader() {
    return Container(
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: Colors.teal,
        borderRadius: BorderRadius.circular(12),
      ),
      child: Column(
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              _buildSummaryMetric('총 주유비', '₩218,616'),
              _buildSummaryMetric('총 정비/기타비', '₩0'),
              _buildSummaryMetric('총 지출', '₩218,616'),
            ],
          ),
          const SizedBox(height: 16),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              _buildSummaryMetric('평균 연비', '22.28', 'km/L'),
              _buildSummaryMetric('총 주유량', '139.9', 'L'),
              _buildSummaryMetric('총 운행거리 (주유)', '2,923.1', 'km'),
            ],
          ),
        ],
      ),
    );
  }

  Widget _buildSummaryMetric(String label, String value, [String? unit]) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(label, style: TextStyle(color: Colors.white.withOpacity(0.8))),
        Row(
          crossAxisAlignment: CrossAxisAlignment.baseline,
          textBaseline: TextBaseline.alphabetic,
          children: [
            Text(value, style: const TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
            if (unit != null) ...[
              const SizedBox(width: 4),
              Text(unit, style: TextStyle(color: Colors.white.withOpacity(0.8))),
            ]
          ],
        )
      ],
    );
  }

  Widget _buildMonthlyExpenseChart() {
    return _buildChartSection(
      title: '월별 지출',
      unit: '단위 ₩1,000',
      chart: _buildBarChart(
        data: {7: 12, 8: 45, 9: 15},
        barColor: Colors.blueAccent,
      ),
    );
  }

  Widget _buildChartSection({
    required String title,
    required String unit,
    required Widget chart,
  }) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(title, style: const TextStyle(color: Colors.white, fontSize: 18, fontWeight: FontWeight.bold)),
        Text(unit, style: TextStyle(color: Colors.white.withOpacity(0.7))),
        const SizedBox(height: 16),
        SizedBox(height: 150, child: chart),
      ],
    );
  }

  // BarChart를 만드는 공통 함수
  Widget _buildBarChart({
    required Map<int, double> data,
    required Color barColor,
    double? maxY,
  }) {
    return BarChart(
      BarChartData(
        maxY: maxY,
        barTouchData: BarTouchData(
          touchTooltipData: BarTouchTooltipData(
            getTooltipColor: (group) => Colors.grey[700]!, // 수정된 부분
            getTooltipItem: (group, groupIndex, rod, rodIndex) {
              return BarTooltipItem(
                rod.toY.toStringAsFixed(2),
                const TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
              );
            },
          ),
        ),
        titlesData: FlTitlesData(
          show: true,
          rightTitles: const AxisTitles(sideTitles: SideTitles(showTitles: false)),
          topTitles: const AxisTitles(sideTitles: SideTitles(showTitles: false)),
          bottomTitles: AxisTitles(
            sideTitles: SideTitles(
              showTitles: true,
              reservedSize: 30,
              // ⭐️⭐️⭐️ 오류가 발생했던 핵심 수정 부분 ⭐️⭐️⭐️
              getTitlesWidget: (double value, TitleMeta meta) {
                return SideTitleWidget(
                  axisSide: meta.axisSide,
                  space: 8.0,
                  child: Text('${value.toInt()}월', style: const TextStyle(color: Colors.white70, fontSize: 12)),
                );
              },
            ),
          ),
          leftTitles: AxisTitles(
            sideTitles: SideTitles(
              showTitles: true,
              reservedSize: 35,
              // ⭐️⭐️⭐️ 오류가 발생했던 핵심 수정 부분 ⭐️⭐️⭐️
              getTitlesWidget: (double value, TitleMeta meta) {
                if (value == 0) return const SizedBox.shrink();
                return Text(value.toInt().toString(), style: const TextStyle(color: Colors.white70, fontSize: 12));
              },
            ),
          ),
        ),
        borderData: FlBorderData(show: false),
        gridData: FlGridData(
          show: true,
          drawVerticalLine: false,
          horizontalInterval: maxY != null ? maxY / 5 : null,
          getDrawingHorizontalLine: (value) {
            return FlLine(color: Colors.white24, strokeWidth: 0.5);
          },
        ),
        barGroups: data.entries.map((entry) {
          return BarChartGroupData(
            x: entry.key,
            barRods: [
              BarChartRodData(
                toY: entry.value,
                color: barColor,
                width: 20,
                borderRadius: const BorderRadius.only(
                  topLeft: Radius.circular(6),
                  topRight: Radius.circular(6),
                ),
              ),
            ],
          );
        }).toList(),
      ),
    );
  }
}