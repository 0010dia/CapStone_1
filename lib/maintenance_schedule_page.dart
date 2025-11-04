import 'package:flutter/material.dart';
import 'package:table_calendar/table_calendar.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:intl/intl.dart';

class MaintenanceSchedulePage extends StatefulWidget {
  const MaintenanceSchedulePage({super.key});

  @override
  State<MaintenanceSchedulePage> createState() => _MaintenanceSchedulePageState();
}

class _MaintenanceSchedulePageState extends State<MaintenanceSchedulePage> {
  DateTime _focusedDay = DateTime.now();
  DateTime? _selectedDay;
  final TextEditingController _memoController = TextEditingController();
  Map<DateTime, String> _events = {};

  @override
  void initState() {
    super.initState();
    _loadSchedules();
  }

  // 🔹 Firestore에서 일정 불러오기
  Future<void> _loadSchedules() async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) return;

    final snapshot = await FirebaseFirestore.instance
        .collection('users')
        .doc(user.uid)
        .collection('maintenance_schedules')
        .get();

    final Map<DateTime, String> loadedEvents = {};
    for (var doc in snapshot.docs) {
      final data = doc.data();
      final date = (data['date'] as Timestamp).toDate();
      loadedEvents[DateTime(date.year, date.month, date.day)] = data['memo'] ?? '';
    }

    setState(() {
      _events = loadedEvents;
    });
  }

  // 🔹 일정 저장
  Future<void> _saveSchedule() async {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null || _selectedDay == null) return;

    final dateKey = DateTime(_selectedDay!.year, _selectedDay!.month, _selectedDay!.day);

    await FirebaseFirestore.instance
        .collection('users')
        .doc(user.uid)
        .collection('maintenance_schedules')
        .doc(DateFormat('yyyy-MM-dd').format(dateKey))
        .set({
      'date': dateKey,
      'memo': _memoController.text.trim(),
      'createdAt': FieldValue.serverTimestamp(),
    });

    setState(() {
      _events[dateKey] = _memoController.text.trim();
      _memoController.clear();
    });

    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(content: Text('점검 일정이 저장되었습니다.')),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('점검 일정'),
        centerTitle: true,
      ),
      body: Column(
        children: [
          TableCalendar(
            locale: 'ko_KR',
            firstDay: DateTime.utc(2020, 1, 1),
            lastDay: DateTime.utc(2035, 12, 31),
            focusedDay: _focusedDay,
            selectedDayPredicate: (day) =>
                isSameDay(_selectedDay, day),
            onDaySelected: (selectedDay, focusedDay) {
              setState(() {
                _selectedDay = selectedDay;
                _focusedDay = focusedDay;
                _memoController.text = _events[selectedDay] ?? '';
              });
            },
            calendarStyle: CalendarStyle(
              todayDecoration: BoxDecoration(
                color: Colors.blueAccent.withOpacity(0.5),
                shape: BoxShape.circle,
              ),
              selectedDecoration: const BoxDecoration(
                color: Colors.blue,
                shape: BoxShape.circle,
              ),
              markerDecoration: const BoxDecoration(
                color: Colors.red,
                shape: BoxShape.circle,
              ),
            ),
            eventLoader: (day) {
              return _events.containsKey(day)
                  ? [_events[day]!]
                  : [];
            },
          ),
          const SizedBox(height: 20),
          if (_selectedDay != null) ...[
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 16.0),
              child: Column(
                children: [
                  Text(
                    DateFormat('yyyy년 MM월 dd일').format(_selectedDay!),
                    style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                  ),
                  const SizedBox(height: 8),
                  TextField(
                    controller: _memoController,
                    decoration: const InputDecoration(
                      labelText: '메모를 입력하세요',
                      border: OutlineInputBorder(),
                    ),
                    maxLines: 3,
                  ),
                  const SizedBox(height: 10),
                  ElevatedButton.icon(
                    onPressed: _saveSchedule,
                    icon: const Icon(Icons.save),
                    label: const Text('저장'),
                    style: ElevatedButton.styleFrom(
                      backgroundColor: Colors.blueAccent,
                      foregroundColor: Colors.white,
                    ),
                  ),
                ],
              ),
            ),
          ],
        ],
      ),
    );
  }
}
