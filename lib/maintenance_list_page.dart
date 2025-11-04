import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:intl/intl.dart';

class MaintenanceListPage extends StatelessWidget {
  const MaintenanceListPage({super.key});

  String formatDate(DateTime date) {
    return DateFormat('yyyy.MM.dd (E)', 'ko_KR').format(date);
  }

  @override
  Widget build(BuildContext context) {
    final user = FirebaseAuth.instance.currentUser;

    if (user == null) {
      return Scaffold(
        appBar: AppBar(title: const Text('정비 목록')),
        body: const Center(
          child: Text('로그인이 필요합니다.'),
        ),
      );
    }

    final Stream<QuerySnapshot> maintenanceStream = FirebaseFirestore.instance
        .collection('users')
        .doc(user.uid)
        .collection('maintenance_records')
        .orderBy('date', descending: true)
        .snapshots();

    return Scaffold(
      appBar: AppBar(
        title: const Text('정비 목록'),
        centerTitle: true,
      ),
      body: StreamBuilder<QuerySnapshot>(
        stream: maintenanceStream,
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Center(child: CircularProgressIndicator());
          }
          if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
            return const Center(
              child: Text('등록된 정비 기록이 없습니다.'),
            );
          }

          final records = snapshot.data!.docs;

          return ListView.builder(
            itemCount: records.length,
            itemBuilder: (context, index) {
              final data = records[index].data() as Map<String, dynamic>;

              final date = (data['date'] as Timestamp).toDate();
              final odometer = data['odometer'] ?? '';
              final items = List<Map<String, dynamic>>.from(data['items'] ?? []);

              return Card(
                margin: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
                elevation: 2,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(10),
                ),
                child: ExpansionTile(
                  title: Text(
                    formatDate(date),
                    style: const TextStyle(fontWeight: FontWeight.bold),
                  ),
                  subtitle: Text('주행거리: $odometer km'),
                  children: items.map((item) {
                    return ListTile(
                      leading: const Icon(Icons.settings_outlined, color: Colors.blueGrey),
                      title: Text(item['type'] ?? '항목 없음'),
                      subtitle: Text(item['memo']?.isNotEmpty == true
                          ? item['memo']
                          : '메모 없음'),
                      trailing: Text(
                        item['cost']?.isNotEmpty == true
                            ? '₩${item['cost']}'
                            : '',
                        style: const TextStyle(
                            fontWeight: FontWeight.bold, color: Colors.black87),
                      ),
                    );
                  }).toList(),
                ),
              );
            },
          );
        },
      ),
    );
  }
}
