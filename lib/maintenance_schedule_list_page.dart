import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:intl/intl.dart';

class MaintenanceScheduleListPage extends StatelessWidget {
  const MaintenanceScheduleListPage({super.key});

  @override
  Widget build(BuildContext context) {
    final user = FirebaseAuth.instance.currentUser;
    if (user == null) {
      return const Scaffold(
        body: Center(child: Text('로그인이 필요합니다.')),
      );
    }

    final schedulesRef = FirebaseFirestore.instance
        .collection('users')
        .doc(user.uid)
        .collection('maintenance_schedules')
        .orderBy('date');

    return Scaffold(
      appBar: AppBar(
        title: const Text('점검 일정 목록'),
        actions: [
          IconButton(
            icon: const Icon(Icons.add),
            onPressed: () {
              Navigator.pushNamed(context, '/add_schedule');
            },
          ),
        ],
      ),
      body: StreamBuilder<QuerySnapshot>(
        stream: schedulesRef.snapshots(),
        builder: (context, snapshot) {
          if (!snapshot.hasData) return const Center(child: CircularProgressIndicator());
          final docs = snapshot.data!.docs;

          if (docs.isEmpty) {
            return const Center(child: Text('등록된 점검 일정이 없습니다.'));
          }

          return ListView.builder(
            itemCount: docs.length,
            itemBuilder: (context, index) {
              final data = docs[index].data() as Map<String, dynamic>;
              final date = (data['date'] as Timestamp).toDate();
              return ListTile(
                title: Text(data['title'] ?? ''),
                subtitle: Text(DateFormat('yyyy.MM.dd').format(date)),
                trailing: Icon(
                  data['isCompleted'] ? Icons.check_circle : Icons.pending,
                  color: data['isCompleted'] ? Colors.green : Colors.orange,
                ),
                onTap: () {
                  // 상세보기나 수정 화면으로 이동 가능
                },
              );
            },
          );
        },
      ),
    );
  }
}
