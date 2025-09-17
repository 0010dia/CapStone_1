// NcVoiceService.h

// 작성자 : 정대연
// 작성일 : 2009.10.10
// 설  명 :

#ifndef __NCSERVICELIST_H
#define __NCSERVICELIST_H


#ifndef MAX_NUM_OF_WAV
#define MAX_NUM_OF_WAV 30
#endif
#define NUM_SOUND_CHANNELS 3

#define RG_TURN_NONE	0
#define RG_TURN_LEFT	1
#define RG_TURN_RIGHT	2

//////////////////////////////////////////////////////////////////////////
// 서비스 Define
#define	IDV_RG_turn_pt_map	1	//	도곽에 의한 점
#define	IDV_RG_turn_pt_tile	2	//	타일에 의한 점
#define	IDV_RG_turn_not_ser_exp	3	//	고속도로에 의한 안내없음
#define	IDV_RG_turn_not_ser_normal	4	//	일반도로에 의한 안내없음
#define	IDV_RG_turn_not_ser_spec	5	//	특수한 경우 안내없음
#define	IDV_RG_str_right	6	//	Y자 오른쪽 안내없음
#define	IDV_RG_str_left	7	//	Y자 왼쪽 안내없음

#define	IDV_RG_turn_str	11	//	직진
#define	IDV_RG_turn_left	12	//	좌회전
#define	IDV_RG_turn_right	13	//	우회전
#define	IDV_RG_turn_Uturn	14	//	U-turn
#define	IDV_RG_turn_pturn	15	//	P-turn
#define	IDV_RG_turn_left_8	16	//	8시 방향 좌회전
#define	IDV_RG_turn_left_10	17	//	10시 방향 좌회전
#define	IDV_RG_turn_rignt_2	18	//	2시 방향 우회전
#define	IDV_RG_turn_rignt_4	19	//	4시 방향 우회전

#define	IDV_RG_turn_dir_1	31	//	1시 방향
#define	IDV_RG_turn_dir_2	32	//	2시 방향
#define	IDV_RG_turn_dir_3	33	//	3시 방향
#define	IDV_RG_turn_dir_4	34	//	4시 방향
#define	IDV_RG_turn_dir_5	35	//	5시 방향
#define	IDV_RG_turn_dir_6	36	//	6시 방향
#define	IDV_RG_turn_dir_7	37	//	7시 방향
#define	IDV_RG_turn_dir_8	38	//	8시 방향
#define	IDV_RG_turn_dir_9	39	//	9시 방향
#define	IDV_RG_turn_dir_10	40	//	10시 방향
#define	IDV_RG_turn_dir_11	41	//	11시 방향
#define	IDV_RG_turn_dir_12	42	//	12시 방향
#define	IDV_RG_turn_str_right	43	//	오른쪽
#define	IDV_RG_turn_str_left	44	//	왼쪽

#define	IDV_RG_lane_str	51	//	직진방향
#define	IDV_RG_lane_left	52	//	왼쪽차선
#define	IDV_RG_lane_right	53	//	오른쪽차선
#define	IDV_RG_lane_1	54	//	1차선
#define	IDV_RG_lane_2	55	//	2차선
#define	IDV_RG_lane_3	56	//	3차선
#define	IDV_RG_lane_4	57	//	4차선
#define	IDV_RG_lane_5	58	//	5차선
#define	IDV_RG_lane_6	59	//	6차선
#define	IDV_RG_lane_7	60	//	7차선
#define	IDV_RG_lane_8	61	//	8차선
#define	IDV_RG_lane_9	62	//	9차선
#define	IDV_RG_lane_10	63	//	10차선

#define IDV_RG_Light_Green_Lane 64  // 연두색 차선
#define	IDV_RG_Green_Lane       65  // 초록색 차선
#define	IDV_RG_Pink_Lane        66  // 분홍색 차선
#define	IDV_RG_Blue_Lane        67  // 파란색 차선
#define	IDV_RG_Yellow_Lane      68  // 노란색 차선
#define	IDV_RG_Left_Way         69  // 왼쪽 길
#define	IDV_RG_Right_Way        70  // 오른쪽 길

#define	IDV_RG_first_exit	    71	//	첫번째 출구
#define	IDV_RG_sec_exit	        72	//	두번째 출구
#define	IDV_RG_first_lane_right	73	//	첫번째 오른쪽 길
#define	IDV_RG_sec_lane_right	74	//	두번째 오른쪽 길
#define	IDV_RG_first_lane_left	75	//	첫번째 왼쪽 길
#define	IDV_RG_sec_lane_left	76	//	두번째 왼쪽 길

#define	IDV_RG_LeftExit         77  // 왼쪽 출구
#define	IDV_RG_RightExit        78  // 오른쪽 출구

#define IDV_RG_Highpath_left	80 // 하이패스차로는 좌측에 있습니다.
#define IDV_RG_Highpath_right	81 // 하이패스차로는 우측에 있습니다.
#define IDV_RG_Highpath_center	82 // 하이패스차로는 중앙에 있습니다.

#define	IDV_RG_Left_Lane1       85  // 왼쪽 첫번째 차로
#define	IDV_RG_Left_Lane2       86  // 왼쪽 두번째 차로
#define	IDV_RG_Left_Lane3       87  // 왼쪽 세번째 차로
#define	IDV_RG_Left_Lane4       88  // 왼쪽 네번째 차로
#define	IDV_RG_Right_Lane1      89  // 오른쪽 첫번째 차로
#define	IDV_RG_Right_Lane2      90  // 오른쪽 두번째 차로
#define	IDV_RG_Right_Lane3      91  // 오른쪽 세번째 차로
#define	IDV_RG_Right_Lane4      92  // 오른쪽 네번째 차로
#define	IDV_RG_Left_1_Lane      93  // 왼쪽 1개 차로
#define	IDV_RG_Left_2_Lane      94  // 왼쪽 2개 차로
#define	IDV_RG_Left_3_Lane      95  // 왼쪽 3개 차로
#define	IDV_RG_Left_4_Lane      96  // 왼쪽 4개 차로
#define	IDV_RG_Right_1_Lane     97  // 오른쪽 1개 차로
#define	IDV_RG_Right_2_Lane     98  // 오른쪽 2개 차로
#define	IDV_RG_Right_3_Lane     99  // 오른쪽 3개 차로
#define	IDV_RG_Right_4_Lane     100  // 오른쪽 4개 차로

#define	IDV_RG_exp_in_right	101	//	오른쪽방향에 고속도로 입구
#define	IDV_RG_exp_in_left	102	//	왼쪽방향에 고속도로 입구
#define	IDV_RG_exp_in_str	103	//	직진방향에 고속도로 입구
#define	IDV_RG_exp_out_right	104	//	오른쪽방향에 고속도로 출구
#define	IDV_RG_exp_out_left	105	//	왼쪽방향에 고속도로 출구
#define	IDV_RG_exp_out_str	106	//	직진방향에 고속도로 출구

#define	IDV_RG_saexp_in_right	111	//	오른쪽방향에 도시고속도로 입구
#define	IDV_RG_saexp_in_left	112	//	왼쪽방향에 도시고속도로 입구
#define	IDV_RG_saexp_in_str	113	//	직진방향에 도시고속도로 입구
#define	IDV_RG_saexp_out_right	114	//	오른쪽방향에 도시고속도로 출구
#define	IDV_RG_saexp_out_left	115	//	왼쪽방향에 도시고속도로 출구
#define	IDV_RG_saexp_out_str	116	//	직진방향에 도시고속도로 출구
#define	IDV_RG_road_right	117	//	오른쪽 도로
#define	IDV_RG_road_left	118	//	왼쪽 도로
#define	IDV_RG_under_in	119	//	지하도로
#define	IDV_RG_sky_in	120	//	고가도로
#define	IDV_RG_tunnel_in	121	//	터널
#define	IDV_RG_bridge	122	//	교량
#define	IDV_RG_under_out	123	//	지하도로 옆
#define	IDV_RG_sky_out	124	//	고가도로 옆

#define	IDV_RG_dir_1	131	//	1시방향
#define	IDV_RG_dir_2	132	//	2시방향
#define	IDV_RG_dir_3	133	//	3시방향
#define	IDV_RG_dir_4	134	//	4시방향
#define	IDV_RG_dir_5	135	//	5시방향
#define	IDV_RG_dir_6	136	//	6시방향
#define	IDV_RG_dir_7	137	//	7시방향
#define	IDV_RG_dir_8	138	//	8시방향
#define	IDV_RG_dir_9	139	//	9시방향
#define	IDV_RG_dir_10	140	//	10시방향
#define	IDV_RG_dir_11	141	//	11시방향
#define	IDV_RG_dir_12	142	//	12시방향

#define	IDV_RG_rest	150	//	졸음 쉼터
#define	IDV_RG_sa	151	//	휴게소
#define IDV_RG_sa_in 152 // 휴게소 진입
#define IDV_RG_Tol_exp 153 //톨게이트 고속
#define IDV_RG_Tol_normal 154 //톨게이트 일반
#define IDV_RG_ferry_in	   155	// 페리항로 진입
#define IDV_RG_ferry_out   156  // 페리항로 진출

#define	IDV_RG_startdir_1	161	// 경로시작점안내	1시방향
#define	IDV_RG_startdir_2	162	// 경로시작점안내	2시방향
#define	IDV_RG_startdir_3	163	// 경로시작점안내	3시방향
#define	IDV_RG_startdir_4	164	// 경로시작점안내	4시방향
#define	IDV_RG_startdir_5	165	// 경로시작점안내	5시방향
#define	IDV_RG_startdir_6	166	// 경로시작점안내	6시방향
#define	IDV_RG_startdir_7	167	// 경로시작점안내	7시방향
#define	IDV_RG_startdir_8	168	// 경로시작점안내	8시방향
#define	IDV_RG_startdir_9	169	// 경로시작점안내	9시방향
#define	IDV_RG_startdir_10	170	// 경로시작점안내	10시방향
#define	IDV_RG_startdir_11	171	// 경로시작점안내	11시방향
#define	IDV_RG_startdir_12	172	// 경로시작점안내	12시방향

#define	IDV_RG_dest_str	181	// 목적지	직진방향
#define	IDV_RG_dest_left	182	// 목적지	왼쪽방향
#define	IDV_RG_dest_right	183	// 목적지	오른쪽방향

#define	IDV_RG_pos_right	184	//	경유지
#define	IDV_RG_via_1	185	//	첫번째 경유지
#define	IDV_RG_via_2	186	//	두번째 경유지
#define	IDV_RG_via_3	187	//	세번째 경유지
#define	IDV_RG_via_4	188	//	네번째 경유지
#define	IDV_RG_via_5	189	//	다섯번째 경유지

#define	IDV_RG_notice_speed	191	//	제한속도
#define	IDV_RG_notice_Accident	192	//	사고다발
#define	IDV_RG_notice_turn	193	//	급커브
#define	IDV_RG_notice_rock	194	//	낙석주의지역

#define	IDV_RG_notice_pol	195	//	경찰청 고속도로 차로 통행준순 안내
#define	IDV_RG_notice_pol2	196	//	경찰청 고속도로 차로 통행준순 안내

#define	IDV_RG_start	200	//	출발지
#define	IDV_RG_pos_goal	201	//	목적지
#define	IDV_RG_go_straight	202	//	다음 안내시 까지 직진입니다.
#define	IDV_RG_goal_cross	203	//	건너편에 목적지가 있습니다.
#define	IDV_RG_in_Route	210	//	경로 진입 안내음.
#define	IDV_RG_in_exp	220	//	고속도로에 있습니까?
#define	IDV_RG_in_saexp	221	//	도시고속도로에 있습니까?
#define	IDV_RG_in_sky	222	//	고가도로에 있습니까?
#define	IDV_RG_in_under	223	//	지하도로에 있습니까?



// 2011.06 회전교차로 안내 추가
#define	IDV_RG_RDir_1	231	//	1시방향
#define	IDV_RG_RDir_2	232	//	2시방향
#define	IDV_RG_RDir_3	233	//	3시방향
#define	IDV_RG_RDir_4	234	//	4시방향
#define	IDV_RG_RDir_5	235	//	5시방향
#define	IDV_RG_RDir_6	236	//	6시방향
#define	IDV_RG_RDir_7	237	//	7시방향
#define	IDV_RG_RDir_8	238	//	8시방향
#define	IDV_RG_RDir_9	239	//	9시방향
#define	IDV_RG_RDir_10	240	//	10시방향
#define	IDV_RG_RDir_11	241	//	11시방향
#define	IDV_RG_RDir_12	242	//	12시방향



#define IDV_RG_Tollgate 249 // 톨게이트입니다.

#define IDV_RG_end 250 // 경로안내를 종료합니다.

#define IDV_RG_via_N 251 // 경유지 N (6번째 이상 경유지)

#endif
