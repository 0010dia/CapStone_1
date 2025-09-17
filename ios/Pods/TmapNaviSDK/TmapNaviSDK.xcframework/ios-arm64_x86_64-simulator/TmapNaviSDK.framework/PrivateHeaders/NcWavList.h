// NcWavList.h

// 작성자 : 정대연
// 작성일 : 2009.10.10
// 설  명 :

#ifndef __NCWAVLIST_H
#define __NCWAVLIST_H


//////////////////////////////////////////////////////////////////////////
// 기본 시나리오 define
#define	IDW_00h	0	//	00h.wav
#define	IDW_01h	1	//	01h.wav
#define	IDW_02h	2	//	02h.wav
#define	IDW_03h	3	//	03h.wav
#define	IDW_04h	4	//	04h.wav
#define	IDW_05h	5	//	05h.wav
#define	IDW_06h	6	//	06h.wav
#define	IDW_07h	7	//	07h.wav
#define	IDW_08h	8	//	08h.wav
#define	IDW_09h	9	//	09h.wav
#define	IDW_10h	10	//	10h.wav
#define	IDW_11h	11	//	11h.wav
#define	IDW_12h	12	//	12h.wav
#define	IDW_13h	13	//	13h.wav
#define	IDW_14h	14	//	14h.wav
#define	IDW_15h	15	//	15h.wav
#define	IDW_16h	16	//	16h.wav
#define	IDW_17h	17	//	17h.wav
#define	IDW_18h	18	//	18h.wav
#define	IDW_19h	19	//	19h.wav
#define	IDW_20h	20	//	20h.wav
#define	IDW_21h	21	//	21h.wav
#define	IDW_22h	22	//	22h.wav
#define	IDW_23h	23	//	23h.wav
#define	IDW_c_route	24	//	c_route.wav
#define	IDW_click	25	//	click.wav
#define	IDW_clock	26	//	clock.wav
#define	IDW_d_route	27	//	d_route.wav
#define	IDW_ending	28	//	ending.wav
#define	IDW_fix_cam_300	29	//	fix_cam_300.wav
#define	IDW_fix_cam_600	30	//	fix_cam_600.wav
#define	IDW_intro1	31	//	intro1.wav
#define	IDW_intro2	32	//	intro2.wav
#define	IDW_mov_cam_300	33	//	mov_cam_300.wav
#define	IDW_overspeed	34	//	overspeed.wav
#define	IDW_re_route	35	//	re_route.wav
#define	IDW_route_out	36	//	route_out.wav
#define	IDW_route_success	37	//	route_success.wav
#define	IDW_safe_noti	38	//	safe_noti.wav
#define	IDW_safe_pass	39	//	safe_pass.wav
#define	IDW_show_icon	40	//	show_icon.wav
#define	IDW_tbt_noti	41	//	tbt_noti.wav
#define	IDW_HELLO	42	//	안녕하세요
#define	IDW_NOTI_DRIVING	43	//	운전중 조작은 위험하오니 반드시 정차 후 사용하시기 바랍니다.
#define	IDW_NOTI_SEATBELT	44	//	운행 중 안전을 위해 안전벨트를 착용하여 주십시요.
#define	IDW_NOTI_SLEEPINESS	45	//	졸음 운전이 빈번한 시간입니다. 안전운전 하십시오.
#define	IDW_NOTI_LONGIDLING	46	//	차량이 장시간 미주행 상태입니다. 장시간 공회전을 피하십시오.
#define	IDW_NOTI_REGISTERED_POINT	47	//	주변에 사용자 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDW_NOTI_REGISTERED	48	//	등록되었습니다.
#define	IDW_NOTI_ALREADY_REGISTERED	49	//	이미 등록되었습니다.
#define	IDW_NOTI_NEW_SAFEDATA	50	//	새로운 안전 운전 데이터가 수신되었습니다.
#define	IDW_NOTI_UPDATE_COMPLETE	51	//	업데이트가 완료 되었습니다.
#define	IDW_NOTI_NOT_TPEC_SERVICE	52	//	티팩 서비스 미가입 상태입니다.
#define	IDW_NOTI_GPS_NOTCONNECTED	53	//	GPS가 연결되었습니다.
#define	IDW_CURRENTPOSITION	54	//	현위치는
#define	IDW_NOT_SERVICE_FRONT_TRAFFIC	55	//	"전방 교통정보 미제공 구간입니다..wav"""
#define	IDW_NOT_SERVICE_AROUND_TRAFFIC	56	//	"주변 교통정보 미제공 구간입니다..wav"""
#define	IDG_RG_START	57	//	경로안내를 시작합니다.
#define	IDG_RG_END	58	//	경로안내를 종료합니다.
#define	IDG_RG_TMAP_START	59	//	티맵 빠른 길 안내를 시작합니다.
#define	IDG_REROUTE	60	//	경로를 재탐색합니다.
#define	IDG_TRAFFIC_REROUTE	61	//	새로운 교통정보를 반영하여 경로를 재탐색합니다.
#define	IDG_CANCEL_ROUTE	62	//	경로가 취소 되었습니다.
#define	IDG_NEXT_RG	63	//	다음안내시까지
#define	IDG_REMAIN	64	//	남았습니다.
#define	IDG_BREATH	65	//	이어서
#define	IDG_IS_PATH_ROUTE	66	//	를 경유하는 경로입니다.
#define	IDG_AFTER_A_WHILE	67	//	잠시후
#define	IDG_AHEAD	68	//	앞에
#define	IDG_AHEAD1	69	//	전방
#define	IDG_AHEAD2	70	//	전방에
#define	IDG_KM_AT	71	//	킬로미터 앞
#define	IDG_M_AT	72	//	미터 앞
#define	IDG_KM	73	//	킬로미터
#define	IDG_M	74	//	미터
#define	IDG_CUR_RUNROAD	75	//	현재 주행도로는
#define	IDG_IS	76	//	입니다.
#define	IDG_GO	77	//	직진입니다.
#define	IDG_LEFT	78	//	좌회전입니다.
#define	IDG_RIGHT	79	//	우회전입니다.
#define	IDG_UTRUN	80	//	유턴입니다.
#define	IDG_PTURN	81	//	피턴입니다.
#define	IDG_SI08	82	//	8시방향 좌회전입니다.
#define	IDG_SI10	83	//	10시방향 좌회전입니다.
#define	IDG_SI02	84	//	2시방향 우회전입니다.
#define	IDG_SI04	85	//	4시방향 우회전입니다.
#define	IDG_FROM	86	//	에서
#define	IDG_DIR	87	//	방면
#define	IDG_TO_EXP_IN_RIGHT	88	//	오른쪽 고속도로입구로 진입하십시요.
#define	IDG_TO_EXP_IN_LEFT	89	//	왼쪽 고속도로입구로 진입하십시요.
#define	IDG_TO_EXP_IN_CENTER	90	//	직진방향 고속도로입구로 진입하십시요.
#define	IDG_TO_EXP_OUT_RIGHT	91	//	오른쪽 고속도로출구로 진출하십시요.
#define	IDG_TO_EXP_OUT_LEFT	92	//	왼쪽 고속도로출구로 진출하십시요.
#define	IDG_TO_EXP_OUT_CENTER	93	//	직진방향 고속도로출구로 진출하십시요.
#define	IDG_TO_UEXP_IN_RIGHT	94	//	오른쪽 고속화도로 입구로 진입하십시요.
#define	IDG_TO_UEXP_IN_LEFT	95	//	왼쪽 고속화도로 입구로 진입하십시요.
#define	IDG_TO_UEXP_IN_CENTER	96	//	직진방향 고속화도로 입구로 진입하십시요.
#define	IDG_TO_UEXP_OUT_RIGHT	97	//	오른쪽 고속화도로 출구로 진출하십시요.
#define	IDG_TO_UEXP_OUT_LEFT	98	//	왼쪽 고속화도로 출구로 진출하십시요.
#define	IDG_TO_UEXP_OUT_CENTER	99	//	직진방향 고속화도로 출구로 진출하십시요.
#define	IDG_ROAD_RIGHT	100	//	오른쪽 도로입니다.
#define	IDG_ROAD_LEFT	101	//	왼쪽 도로입니다.
#define	IDG_GO_LANE_CENTER	102	//	직진차로로 주앵하십시요.
#define	IDG_GO_LANE_LEFT	103	//	왼쪽차로로 주앵하십시요.
#define	IDG_GO_LANE_RIGHT	104	//	오른쪽차로로 주앵하십시요.
#define	IDG_GO_LANE_1	105	//	1차로로 주앵하십시요.
#define	IDG_GO_LANE_2	106	//	2차로로 주앵하십시요.
#define	IDG_GO_LANE_3	107	//	3차로로 주앵하십시요.
#define	IDG_GO_LANE_4	108	//	4차로로 주앵하십시요.
#define	IDG_GO_LANE_5	109	//	5차로로 주앵하십시요.
#define	IDG_GO_LANE_6	110	//	6차로로 주앵하십시요.
#define	IDG_GO_LANE_7	111	//	7차로로 주앵하십시요.
#define	IDG_GO_LANE_8	112	//	8차로로 주앵하십시요.
#define	IDG_GO_LANE_9	113	//	9차로로 주앵하십시요.
#define	IDG_GO_LANE_10	114	//	10차로로 주앵하십시요.
#define	IDG_1ST_OUT	115	//	첫번째 출구입니다.
#define	IDG_2ND_OUT	116	//	두번째 출구입니다.
#define	IDG_1ST_ROAD_RIGHT	117	//	첫번째 오른쪽길입니다.
#define	IDG_2ND_ROAD_RIGHT	118	//	두번째 오른쪽길입니다.
#define	IDG_1ST_ROAD_LEFT	119	//	첫번째 왼쪽길입니다.
#define	IDG_2ND_ROAD_LEFT	120	//	두번째 왼쪽길입니다.
#define	IDG_SAFETY_BELT	121	//	운행 중 안전을 위해 전 좌석 안전벨트를 착용하십시오.
#define	IDG_FROM_ROTARY	122	//	로터리에서
#define	IDG_ROTARY_1	123	//	1시방향 출구입니다.
#define	IDG_ROTARY_2	124	//	2시방향 출구입니다.
#define	IDG_ROTARY_3	125	//	3시방향 출구입니다.
#define	IDG_ROTARY_4	126	//	4시방향 출구입니다.
#define	IDG_ROTARY_5	127	//	5시방향 출구입니다.
#define	IDG_ROTARY_6	128	//	6시방향 출구입니다.
#define	IDG_ROTARY_7	129	//	7시방향 출구입니다.
#define	IDG_ROTARY_8	130	//	8시방향 출구입니다.
#define	IDG_ROTARY_9	131	//	9시방향 출구입니다.
#define	IDG_ROTARY_10	132	//	10시방향 출구입니다.
#define	IDG_ROTARY_11	133	//	11시방향 출구입니다.
#define	IDG_ROTARY_12	134	//	12시방향 출구입니다.
#define	IDG_IN_UNDER_PATH	135	//	지하차도 지니빕니다.
#define	IDG_IN_OVER_PATH	136	//	고가차도 지니빕니다.
#define	IDG_NOT_UNDER_PATH	137	//	지하차도 옆길 입니다.
#define	IDG_NOT_OVER_PATH	138	//	고가차도 옆길 입니다.
#define	IDG_IN_TUNNEL	139	//	터널입니다.
#define	IDG_SA	140	//	다음휴게소는
#define	IDG_SA2	141	//	다음휴게소까지는
#define	IDG_SA3	142	//	휴게소
#define	IDG_SA4	143	//	휴게소입니다.
#define	IDG_LAST_SA	144	//	마지막 휴게소입니다.
#define	IDG_IS_OIL	145	//	주유소와 충전소가 있습니다.
#define	IDG_IS_GAS_STATION	146	//	주유소가 있습니다.
#define	IDG_IS_TOL	147	//	톨게이트 입니다.
#define	IDG_IS_TOL_CHARGE	148	//	통앵요금은
#define	IDG_IS_MONEY	149	//	원 입니다.
#define	IDG_HIGHPATH_LEFT	150	//	하이패스차로는 좌측에 있습니다.
#define	IDG_HIGHPATH_RIGHT	151	//	하이패스차로는 우측에 있습니다.
#define	IDG_HIGHPATH_CENTER	152	//	하이패스차로는 중앙에 있습니다.
#define	IDG_NEAR_GOTH	153	//	경유지가 있습니다.
#define	IDG_GOAL	154	//	목적지가 있습니다.
#define	IDG_FRONT	155	//	앞
#define	IDG_SPACE03	156	//	무음-0_3
#define	IDG_SPACE05	157	//	무음-0_5
#define	IDG_SPACE07	158	//	무음-0_7
#define	IDG_SPACE08	159	//	무음-0_8
#define	IDG_SPACE10	160	//	무음-1_0
#define	IDG_BRANCH	161	//	분기점에서
#define	IDG_CROSSROAD	162	//	교차로에서
#define	IDG_ENTER	163	//	지니빕니다.
#define	IDG_BYWAY	164	//	옆길 입니다.
#define	IDG_IS_PATTERN_ROUTE	165	//	패턴교통정보로 탐색되었습니다.
#define	IDG_TPEG_RECEIPT_REROUTE	166	//	교통정보가 수신되면 재탐색 합니다.
#define	IDG_TPEG_RECEIPTED	167	//	교통정보 수신이 완료되었습니다.
#define	IDG_NOW	168	//	현재
#define	IDG_BY_PASS	169	//	를 지나고 있습니다.
#define	IDG_TOL	170	//	톨게이트
#define	IDG_ROTARY	171	//	로터리
#define	IDG_FAIL_ROUTE	172	//	경로 탐색에 실패하였습니다. 출발지 목적지를 확인해주세요.
#define	IDG_NEXT_RUN_APPLY	173	//	다음 실행시에 적용됩니다.
#define	IDG_ETC	174	//	기타
#define	IDG_GS	175	//	GS
#define	IDG_OILBANK	176	//	오일뱅크
#define	IDG_OVER_SPEED	177	//	차량이 급가속 중입니다. 경제 주행 하십시오.
#define	IDG_SELECT_SIX	178	//	여섯개가 모두 선택되었습니다.
#define	IDG_SK	179	//	SK
#define	IDG_SOIL	180	//	SOIL
#define	IDG_TIGER_OIL	181	//	타이거오일
#define	IDG_BUDDHA	182	//	휴일이 많은 5월 오늘은 석가탄신일 입니다.
#define	IDG_CHILDREN	183	//	가정의 달 5월에 가장 먼저 맞이하는 휴일 어린이날 입니다.
#define	IDG_CHUSEOK	184	//	풍요롭고 넉넉한 음식이 가득한 추석입니다. 설레는 고향길 ???와 함께 안전운행 하세요.
#define	IDG_FRIDAY	185	//	금요일이 주는 여유가 있어 즐거운 마음이 절로 드는 아침입니다. 기분 좋은 하루 보내세요!
#define	IDG_GACHUNJEOL	186	//	민족의 시작을 기념하는 개천철 휴일입니다.
#define	IDG_GWANGBOK	187	//	광복의 기쁨을 기념하는 오늘은 광복절 휴일입니다.
#define	IDG_MONDAY	188	//	활기차게 보낸 주말로 인해 월요병에 시달리고 계시나요? 활기찬 월요일 신나는 한 주 되세요!
#define	IDG_NEWYEAR	189	//	새해 첫 날이 밝았습니다. 새해 복 많이 받으세요!
#define	IDG_SAMILJEOL	190	//	봄이 시작되는 3월의 첫 날 삼일절 휴일입니다.
#define	IDG_SATURDAY	191	//	한 주 내내 기다리고 기다리던 토요일 입니다. 즐거운 하루 보내세요!
#define	IDG_SUNDAY	192	//	오늘은 어떤 계획 있으세요? 즐거운 일요일 활기찬 하루 보내세요!
#define	IDG_THURSDAY	193	//	마음은 벌써 주말 드라이브를 떠나고 계시지 않으세요? 몸도 마음도 가벼워지는 목요일 아침입니다!
#define	IDG_TUESDAY	194	//	바쁜 월요일을 지나 화요일이 되었습니다. 어제 보다 여유있고 즐거운 하루 보내세요!
#define	IDG_VALENTINE	195	//	달콤한 초콜릿 준비하셨나요? 설레이는 아침 발렌타인데이입니다.
#define	IDG_WEDNESDAY	196	//	남은 한 주가 길어 보이시나요? 오늘만 지나면 주말이 까가워지네요 조금만 힘내세요!
#define	IDG_WHITEDAY	197	//	새봄과 함께 찾아온 3월의 설레임 화이트데이입니다.
#define	IDG_XMAS	198	//	한해의 마지막 휴일 성탄절 입니다. 메리크리스마스!
#define	IDG_XMASEVE	199	//	설레이는 아침 크리스마스 이브입니다.
#define	IDG_MAX10	200	//	이 도로의 최고속도는 시속 10km입니다.
#define	IDG_MAX20	201	//	이 도로의 최고속도는 시속 20km입니다.
#define	IDG_MAX30	202	//	이 도로의 최고속도는 시속 30km입니다.
#define	IDG_MAX40	203	//	이 도로의 최고속도는 시속 40km입니다.
#define	IDG_MAX50	204	//	이 도로의 최고속도는 시속 50km입니다.
#define	IDG_MAX60	205	//	이 도로의 최고속도는 시속 60km입니다.
#define	IDG_MAX70	206	//	이 도로의 최고속도는 시속 70km입니다.
#define	IDG_MAX80	207	//	이 도로의 최고속도는 시속 80km입니다.
#define	IDG_MAX90	208	//	이 도로의 최고속도는 시속 90km입니다.
#define	IDG_MAX100	209	//	이 도로의 최고속도는 시속 100km입니다.
#define	IDG_MAX110	210	//	이 도로의 최고속도는 시속 110km입니다.
#define	IDG_MAX120	211	//	이 도로의 최고속도는 시속 120km입니다.
#define	IDG_MAX130	212	//	이 도로의 최고속도는 시속 130km입니다.
#define	IDG_MAX140	213	//	이 도로의 최고속도는 시속 140km입니다.
#define	IDG_MAX150	214	//	이 도로의 최고속도는 시속 150km입니다.
#define	IDG_LANE_ENTER	215	//	으로 진입하세요.
#define	IDG_LANE_GUIDE	216	//	차로를 이용하세요.
#define	IDG_LANE_HIGHPASS	217	//	하이패스 차로는
#define	IDG_LANE_IS	218	//	차로 입니다.
#define	IDG_LANE_NAME_1	219	//	1 일
#define	IDG_LANE_NAME_2	220	//	2 이
#define	IDG_LANE_NAME_3	221	//	3 삼
#define	IDG_LANE_NAME_4	222	//	4 사
#define	IDG_LANE_NAME_5	223	//	5 오
#define	IDG_LANE_NAME_6	224	//	6 육
#define	IDG_LANE_NAME_7	225	//	7 칠
#define	IDG_LANE_NAME_8	226	//	8 팔
#define	IDG_LANE_NAME_9	227	//	9 구
#define	IDG_LANE_NAME_10	228	//	10 십
#define	IDG_LANE_NAME_11	229	//	11 십일
#define	IDG_LANE_NAME_12	230	//	12 십이
#define	IDG_LANE_NAME_13	231	//	13 십삼
#define	IDG_LANE_NAME_14	232	//	14 십사
#define	IDG_LANE_NAME_15	233	//	15 십오
#define	IDG_LANE_NAME_16	234	//	16 십육
#define	IDG_LANE_NAME_17	235	//	17 십칠
#define	IDG_LANE_NAME_18	236	//	18 십팔
#define	IDG_LANE_NAME_19	237	//	19 십구
#define	IDG_LANE_NAME_20	238	//	20 이십
#define	IDG_LANE_OPPOSITE	239	//	일방통행 도로에 진입하셨습니다. 역주행에 주의 하세요.
#define	IDG_LANE_MUTE03	240	//	무음0.3초
#define	IDG_LANE_MUTE06	241	//	무음0.6초
#define	IDG_TIME_COMMENT1	242	//	도착 예정 시간은
#define	IDG_TIME_COMMENT2	243	//	예상 소요 시간은
#define	IDG_TIME_G_AM	244	//	오전
#define	IDG_TIME_G_PM	245	//	오후
#define	IDG_TIME_H1_01	246	//	1시
#define	IDG_TIME_H1_02	247	//	2시
#define	IDG_TIME_H1_03	248	//	3시
#define	IDG_TIME_H1_04	249	//	4시
#define	IDG_TIME_H1_05	250	//	5시
#define	IDG_TIME_H1_06	251	//	6시
#define	IDG_TIME_H1_07	252	//	7시
#define	IDG_TIME_H1_08	253	//	8시
#define	IDG_TIME_H1_09	254	//	9시
#define	IDG_TIME_H1_10	255	//	10시
#define	IDG_TIME_H1_11	256	//	11시
#define	IDG_TIME_H1_12	257	//	12시
#define	IDG_TIME_H2_01	258	//	1시간
#define	IDG_TIME_H2_02	259	//	2시간
#define	IDG_TIME_H2_03	260	//	3시간
#define	IDG_TIME_H2_04	261	//	4시간
#define	IDG_TIME_H2_05	262	//	5시간
#define	IDG_TIME_H2_06	263	//	6시간
#define	IDG_TIME_H2_07	264	//	7시간
#define	IDG_TIME_H2_08	265	//	8시간
#define	IDG_TIME_H2_09	266	//	9시간
#define	IDG_TIME_H2_10	267	//	10시간
#define	IDG_TIME_H2_11	268	//	11시간
#define	IDG_TIME_H2_12	269	//	12시간
#define	IDG_TIME_H2_13	270	//	13시간
#define	IDG_TIME_H2_14	271	//	14시간
#define	IDG_TIME_H2_15	272	//	15시간
#define	IDG_TIME_H2_16	273	//	16시간
#define	IDG_TIME_H2_17	274	//	17시간
#define	IDG_TIME_H2_18	275	//	18시간
#define	IDG_TIME_H2_19	276	//	19시간
#define	IDG_TIME_H2_20	277	//	20시간
#define	IDG_TIME_H2_21	278	//	21시간
#define	IDG_TIME_H2_22	279	//	22시간
#define	IDG_TIME_H2_23	280	//	23시간
#define	IDG_TIME_M_01	281	//	1분
#define	IDG_TIME_M_02	282	//	2분
#define	IDG_TIME_M_03	283	//	3분
#define	IDG_TIME_M_04	284	//	4분
#define	IDG_TIME_M_05	285	//	5분
#define	IDG_TIME_M_06	286	//	6분
#define	IDG_TIME_M_07	287	//	7분
#define	IDG_TIME_M_08	288	//	8분
#define	IDG_TIME_M_09	289	//	9분
#define	IDG_TIME_M_10	290	//	10분
#define	IDG_TIME_M_11	291	//	11분
#define	IDG_TIME_M_12	292	//	12분
#define	IDG_TIME_M_13	293	//	13분
#define	IDG_TIME_M_14	294	//	14분
#define	IDG_TIME_M_15	295	//	15분
#define	IDG_TIME_M_16	296	//	16분
#define	IDG_TIME_M_17	297	//	17분
#define	IDG_TIME_M_18	298	//	18분
#define	IDG_TIME_M_19	299	//	19분
#define	IDG_TIME_M_20	300	//	20분
#define	IDG_TIME_M_21	301	//	21분
#define	IDG_TIME_M_22	302	//	22분
#define	IDG_TIME_M_23	303	//	23분
#define	IDG_TIME_M_24	304	//	24분
#define	IDG_TIME_M_25	305	//	25분
#define	IDG_TIME_M_26	306	//	26분
#define	IDG_TIME_M_27	307	//	27분
#define	IDG_TIME_M_28	308	//	28분
#define	IDG_TIME_M_29	309	//	29분
#define	IDG_TIME_M_30	310	//	30분
#define	IDG_TIME_M_31	311	//	31분
#define	IDG_TIME_M_32	312	//	32분
#define	IDG_TIME_M_33	313	//	33분
#define	IDG_TIME_M_34	314	//	34분
#define	IDG_TIME_M_35	315	//	35분
#define	IDG_TIME_M_36	316	//	36분
#define	IDG_TIME_M_37	317	//	37분
#define	IDG_TIME_M_38	318	//	38분
#define	IDG_TIME_M_39	319	//	39분
#define	IDG_TIME_M_40	320	//	40분
#define	IDG_TIME_M_41	321	//	41분
#define	IDG_TIME_M_42	322	//	42분
#define	IDG_TIME_M_43	323	//	43분
#define	IDG_TIME_M_44	324	//	44분
#define	IDG_TIME_M_45	325	//	45분
#define	IDG_TIME_M_46	326	//	46분
#define	IDG_TIME_M_47	327	//	47분
#define	IDG_TIME_M_48	328	//	48분
#define	IDG_TIME_M_49	329	//	49분
#define	IDG_TIME_M_50	330	//	50분
#define	IDG_TIME_M_51	331	//	51분
#define	IDG_TIME_M_52	332	//	52분
#define	IDG_TIME_M_53	333	//	53분
#define	IDG_TIME_M_54	334	//	54분
#define	IDG_TIME_M_55	335	//	55분
#define	IDG_TIME_M_56	336	//	56분
#define	IDG_TIME_M_57	337	//	57분
#define	IDG_TIME_M_58	338	//	58분
#define	IDG_TIME_M_59	339	//	59분
#define	IDG_ACCIDENT_SIDEWAY	340	//	갓길 사고 다발지점입니다
#define	IDG_ACCIDENT_OVERSPEED	341	//	과속 사고 다발지점입니다
#define	IDG_ACCIDENT_SLEEP	342	//	졸음 사고 다발지점입니다
#define	IDG_USER_INTEREST	343	//	사용자 관심 지점이 있습니다
#define	IDG_ENTER_FERRY	344	//	패리항로 진입입니다
#define	IDM_0000010	345	//	10미터
#define	IDM_0000020	346	//	20미터
#define	IDM_0000030	347	//	30미터
#define	IDM_0000040	348	//	40미터
#define	IDM_0000050	349	//	50미터
#define	IDM_0000060	350	//	60미터
#define	IDM_0000070	351	//	70미터
#define	IDM_0000080	352	//	80미터
#define	IDM_0000090	353	//	90미터
#define	IDM_0000100	354	//	100미터
#define	IDM_0000110	355	//	110미터
#define	IDM_0000120	356	//	120미터
#define	IDM_0000130	357	//	130미터
#define	IDM_0000140	358	//	140미터
#define	IDM_0000150	359	//	150미터
#define	IDM_0000160	360	//	160미터
#define	IDM_0000170	361	//	170미터
#define	IDM_0000180	362	//	180미터
#define	IDM_0000190	363	//	190미터
#define	IDM_0000200	364	//	200미터
#define	IDM_0000210	365	//	210미터
#define	IDM_0000220	366	//	220미터
#define	IDM_0000230	367	//	230미터
#define	IDM_0000240	368	//	240미터
#define	IDM_0000250	369	//	250미터
#define	IDM_0000260	370	//	260미터
#define	IDM_0000270	371	//	270미터
#define	IDM_0000280	372	//	280미터
#define	IDM_0000290	373	//	290미터
#define	IDM_0000300	374	//	300미터
#define	IDM_0000310	375	//	310미터
#define	IDM_0000320	376	//	320미터
#define	IDM_0000330	377	//	330미터
#define	IDM_0000340	378	//	340미터
#define	IDM_0000350	379	//	350미터
#define	IDM_0000360	380	//	360미터
#define	IDM_0000370	381	//	370미터
#define	IDM_0000380	382	//	380미터
#define	IDM_0000390	383	//	390미터
#define	IDM_0000400	384	//	400미터
#define	IDM_0000410	385	//	410미터
#define	IDM_0000420	386	//	420미터
#define	IDM_0000430	387	//	430미터
#define	IDM_0000440	388	//	440미터
#define	IDM_0000450	389	//	450미터
#define	IDM_0000460	390	//	460미터
#define	IDM_0000470	391	//	470미터
#define	IDM_0000480	392	//	480미터
#define	IDM_0000490	393	//	490미터
#define	IDM_0000500	394	//	500미터
#define	IDM_0000510	395	//	510미터
#define	IDM_0000520	396	//	520미터
#define	IDM_0000530	397	//	530미터
#define	IDM_0000540	398	//	540미터
#define	IDM_0000550	399	//	550미터
#define	IDM_0000560	400	//	560미터
#define	IDM_0000570	401	//	570미터
#define	IDM_0000580	402	//	580미터
#define	IDM_0000590	403	//	590미터
#define	IDM_0000600	404	//	600미터
#define	IDM_0000610	405	//	610미터
#define	IDM_0000620	406	//	620미터
#define	IDM_0000630	407	//	630미터
#define	IDM_0000640	408	//	640미터
#define	IDM_0000650	409	//	650미터
#define	IDM_0000660	410	//	660미터
#define	IDM_0000670	411	//	670미터
#define	IDM_0000680	412	//	680미터
#define	IDM_0000690	413	//	690미터
#define	IDM_0000700	414	//	700미터
#define	IDM_0000710	415	//	710미터
#define	IDM_0000720	416	//	720미터
#define	IDM_0000730	417	//	730미터
#define	IDM_0000740	418	//	740미터
#define	IDM_0000750	419	//	750미터
#define	IDM_0000760	420	//	760미터
#define	IDM_0000770	421	//	770미터
#define	IDM_0000780	422	//	780미터
#define	IDM_0000790	423	//	790미터
#define	IDM_0000800	424	//	800미터
#define	IDM_0000810	425	//	810미터
#define	IDM_0000820	426	//	820미터
#define	IDM_0000830	427	//	830미터
#define	IDM_0000840	428	//	840미터
#define	IDM_0000850	429	//	850미터
#define	IDM_0000860	430	//	860미터
#define	IDM_0000870	431	//	870미터
#define	IDM_0000880	432	//	880미터
#define	IDM_0000890	433	//	890미터
#define	IDM_0000900	434	//	900미터
#define	IDM_0000910	435	//	910미터
#define	IDM_0000920	436	//	920미터
#define	IDM_0000930	437	//	930미터
#define	IDM_0000940	438	//	940미터
#define	IDM_0000950	439	//	950미터
#define	IDM_0000960	440	//	960미터
#define	IDM_0000970	441	//	970미터
#define	IDM_0000980	442	//	980미터
#define	IDM_0000990	443	//	990미터
#define	IDM_0001000	444	//	1킬로미터
#define	IDM_0001100	445	//	1.1킬로미터
#define	IDM_0001200	446	//	1.2킬로미터
#define	IDM_0001300	447	//	1.3킬로미터
#define	IDM_0001400	448	//	1.4킬로미터
#define	IDM_0001500	449	//	1.5킬로미터
#define	IDM_0001600	450	//	1.6킬로미터
#define	IDM_0001700	451	//	1.7킬로미터
#define	IDM_0001800	452	//	1.8킬로미터
#define	IDM_0001900	453	//	1.9킬로미터
#define	IDM_0002000	454	//	2킬로미터
#define	IDM_0002100	455	//	2.1킬로미터
#define	IDM_0002200	456	//	2.2킬로미터
#define	IDM_0002300	457	//	2.3킬로미터
#define	IDM_0002400	458	//	2.4킬로미터
#define	IDM_0002500	459	//	2.5킬로미터
#define	IDM_0002600	460	//	2.6킬로미터
#define	IDM_0002700	461	//	2.7킬로미터
#define	IDM_0002800	462	//	2.8킬로미터
#define	IDM_0002900	463	//	2.9킬로미터
#define	IDM_0003000	464	//	3킬로미터
#define	IDM_0003100	465	//	3.1킬로미터
#define	IDM_0003200	466	//	3.2킬로미터
#define	IDM_0003300	467	//	3.3킬로미터
#define	IDM_0003400	468	//	3.4킬로미터
#define	IDM_0003500	469	//	3.5킬로미터
#define	IDM_0003600	470	//	3.6킬로미터
#define	IDM_0003700	471	//	3.7킬로미터
#define	IDM_0003800	472	//	3.8킬로미터
#define	IDM_0003900	473	//	3.9킬로미터
#define	IDM_0004000	474	//	4킬로미터
#define	IDM_0004100	475	//	4.1킬로미터
#define	IDM_0004200	476	//	4.2킬로미터
#define	IDM_0004300	477	//	4.3킬로미터
#define	IDM_0004400	478	//	4.4킬로미터
#define	IDM_0004500	479	//	4.5킬로미터
#define	IDM_0004600	480	//	4.6킬로미터
#define	IDM_0004700	481	//	4.7킬로미터
#define	IDM_0004800	482	//	4.8킬로미터
#define	IDM_0004900	483	//	4.9킬로미터
#define	IDM_0005000	484	//	5킬로미터
#define	IDM_0005100	485	//	5.1킬로미터
#define	IDM_0005200	486	//	5.2킬로미터
#define	IDM_0005300	487	//	5.3킬로미터
#define	IDM_0005400	488	//	5.4킬로미터
#define	IDM_0005500	489	//	5.5킬로미터
#define	IDM_0005600	490	//	5.6킬로미터
#define	IDM_0005700	491	//	5.7킬로미터
#define	IDM_0005800	492	//	5.8킬로미터
#define	IDM_0005900	493	//	5.9킬로미터
#define	IDM_0006000	494	//	6킬로미터
#define	IDM_0006100	495	//	6.1킬로미터
#define	IDM_0006200	496	//	6.2킬로미터
#define	IDM_0006300	497	//	6.3킬로미터
#define	IDM_0006400	498	//	6.4킬로미터
#define	IDM_0006500	499	//	6.5킬로미터
#define	IDM_0006600	500	//	6.6킬로미터
#define	IDM_0006700	501	//	6.7킬로미터
#define	IDM_0006800	502	//	6.8킬로미터
#define	IDM_0006900	503	//	6.9킬로미터
#define	IDM_0007000	504	//	7킬로미터
#define	IDM_0007100	505	//	7.1킬로미터
#define	IDM_0007200	506	//	7.2킬로미터
#define	IDM_0007300	507	//	7.3킬로미터
#define	IDM_0007400	508	//	7.4킬로미터
#define	IDM_0007500	509	//	7.5킬로미터
#define	IDM_0007600	510	//	7.6킬로미터
#define	IDM_0007700	511	//	7.7킬로미터
#define	IDM_0007800	512	//	7.8킬로미터
#define	IDM_0007900	513	//	7.9킬로미터
#define	IDM_0008000	514	//	8킬로미터
#define	IDM_0008100	515	//	8.1킬로미터
#define	IDM_0008200	516	//	8.2킬로미터
#define	IDM_0008300	517	//	8.3킬로미터
#define	IDM_0008400	518	//	8.4킬로미터
#define	IDM_0008500	519	//	8.5킬로미터
#define	IDM_0008600	520	//	8.6킬로미터
#define	IDM_0008700	521	//	8.7킬로미터
#define	IDM_0008800	522	//	8.8킬로미터
#define	IDM_0008900	523	//	8.9킬로미터
#define	IDM_0009000	524	//	9킬로미터
#define	IDM_0009100	525	//	9.1킬로미터
#define	IDM_0009200	526	//	9.2킬로미터
#define	IDM_0009300	527	//	9.3킬로미터
#define	IDM_0009400	528	//	9.4킬로미터
#define	IDM_0009500	529	//	9.5킬로미터
#define	IDM_0009600	530	//	9.6킬로미터
#define	IDM_0009700	531	//	9.7킬로미터
#define	IDM_0009800	532	//	9.8킬로미터
#define	IDM_0009900	533	//	9.9킬로미터
#define	IDM_0010000	534	//	10킬로미터
#define	IDM_0010100	535	//	10.1킬로미터
#define	IDM_0010200	536	//	10.2킬로미터
#define	IDM_0010300	537	//	10.3킬로미터
#define	IDM_0010400	538	//	10.4킬로미터
#define	IDM_0010500	539	//	10.5킬로미터
#define	IDM_0010600	540	//	10.6킬로미터
#define	IDM_0010700	541	//	10.7킬로미터
#define	IDM_0010800	542	//	10.8킬로미터
#define	IDM_0010900	543	//	10.9킬로미터
#define	IDM_0011000	544	//	11킬로미터
#define	IDM_0011100	545	//	11.1킬로미터
#define	IDM_0011200	546	//	11.2킬로미터
#define	IDM_0011300	547	//	11.3킬로미터
#define	IDM_0011400	548	//	11.4킬로미터
#define	IDM_0011500	549	//	11.5킬로미터
#define	IDM_0011600	550	//	11.6킬로미터
#define	IDM_0011700	551	//	11.7킬로미터
#define	IDM_0011800	552	//	11.8킬로미터
#define	IDM_0011900	553	//	11.9킬로미터
#define	IDM_0012000	554	//	12킬로미터
#define	IDM_0012100	555	//	12.1킬로미터
#define	IDM_0012200	556	//	12.2킬로미터
#define	IDM_0012300	557	//	12.3킬로미터
#define	IDM_0012400	558	//	12.4킬로미터
#define	IDM_0012500	559	//	12.5킬로미터
#define	IDM_0012600	560	//	12.6킬로미터
#define	IDM_0012700	561	//	12.7킬로미터
#define	IDM_0012800	562	//	12.8킬로미터
#define	IDM_0012900	563	//	12.9킬로미터
#define	IDM_0013000	564	//	13킬로미터
#define	IDM_0013100	565	//	13.1킬로미터
#define	IDM_0013200	566	//	13.2킬로미터
#define	IDM_0013300	567	//	13.3킬로미터
#define	IDM_0013400	568	//	13.4킬로미터
#define	IDM_0013500	569	//	13.5킬로미터
#define	IDM_0013600	570	//	13.6킬로미터
#define	IDM_0013700	571	//	13.7킬로미터
#define	IDM_0013800	572	//	13.8킬로미터
#define	IDM_0013900	573	//	13.9킬로미터
#define	IDM_0014000	574	//	14킬로미터
#define	IDM_0014100	575	//	14.1킬로미터
#define	IDM_0014200	576	//	14.2킬로미터
#define	IDM_0014300	577	//	14.3킬로미터
#define	IDM_0014400	578	//	14.4킬로미터
#define	IDM_0014500	579	//	14.5킬로미터
#define	IDM_0014600	580	//	14.6킬로미터
#define	IDM_0014700	581	//	14.7킬로미터
#define	IDM_0014800	582	//	14.8킬로미터
#define	IDM_0014900	583	//	14.9킬로미터
#define	IDM_0015000	584	//	15킬로미터
#define	IDM_0015100	585	//	15.1킬로미터
#define	IDM_0015200	586	//	15.2킬로미터
#define	IDM_0015300	587	//	15.3킬로미터
#define	IDM_0015400	588	//	15.4킬로미터
#define	IDM_0015500	589	//	15.5킬로미터
#define	IDM_0015600	590	//	15.6킬로미터
#define	IDM_0015700	591	//	15.7킬로미터
#define	IDM_0015800	592	//	15.8킬로미터
#define	IDM_0015900	593	//	15.9킬로미터
#define	IDM_0016000	594	//	16킬로미터
#define	IDM_0016100	595	//	16.1킬로미터
#define	IDM_0016200	596	//	16.2킬로미터
#define	IDM_0016300	597	//	16.3킬로미터
#define	IDM_0016400	598	//	16.4킬로미터
#define	IDM_0016500	599	//	16.5킬로미터
#define	IDM_0016600	600	//	16.6킬로미터
#define	IDM_0016700	601	//	16.7킬로미터
#define	IDM_0016800	602	//	16.8킬로미터
#define	IDM_0016900	603	//	16.9킬로미터
#define	IDM_0017000	604	//	17킬로미터
#define	IDM_0017100	605	//	17.1킬로미터
#define	IDM_0017200	606	//	17.2킬로미터
#define	IDM_0017300	607	//	17.3킬로미터
#define	IDM_0017400	608	//	17.4킬로미터
#define	IDM_0017500	609	//	17.5킬로미터
#define	IDM_0017600	610	//	17.6킬로미터
#define	IDM_0017700	611	//	17.7킬로미터
#define	IDM_0017800	612	//	17.8킬로미터
#define	IDM_0017900	613	//	17.9킬로미터
#define	IDM_0018000	614	//	18킬로미터
#define	IDM_0018100	615	//	18.1킬로미터
#define	IDM_0018200	616	//	18.2킬로미터
#define	IDM_0018300	617	//	18.3킬로미터
#define	IDM_0018400	618	//	18.4킬로미터
#define	IDM_0018500	619	//	18.5킬로미터
#define	IDM_0018600	620	//	18.6킬로미터
#define	IDM_0018700	621	//	18.7킬로미터
#define	IDM_0018800	622	//	18.8킬로미터
#define	IDM_0018900	623	//	18.9킬로미터
#define	IDM_0019000	624	//	19킬로미터
#define	IDM_0019100	625	//	19.1킬로미터
#define	IDM_0019200	626	//	19.2킬로미터
#define	IDM_0019300	627	//	19.3킬로미터
#define	IDM_0019400	628	//	19.4킬로미터
#define	IDM_0019500	629	//	19.5킬로미터
#define	IDM_0019600	630	//	19.6킬로미터
#define	IDM_0019700	631	//	19.7킬로미터
#define	IDM_0019800	632	//	19.8킬로미터
#define	IDM_0019900	633	//	19.9킬로미터
#define	IDM_0020000	634	//	20킬로미터
#define	IDM_0020100	635	//	20.1킬로미터
#define	IDM_0020200	636	//	20.2킬로미터
#define	IDM_0020300	637	//	20.3킬로미터
#define	IDM_0020400	638	//	20.4킬로미터
#define	IDM_0020500	639	//	20.5킬로미터
#define	IDM_0020600	640	//	20.6킬로미터
#define	IDM_0020700	641	//	20.7킬로미터
#define	IDM_0020800	642	//	20.8킬로미터
#define	IDM_0020900	643	//	20.9킬로미터
#define	IDM_0021000	644	//	21킬로미터
#define	IDM_0021100	645	//	21.1킬로미터
#define	IDM_0021200	646	//	21.2킬로미터
#define	IDM_0021300	647	//	21.3킬로미터
#define	IDM_0021400	648	//	21.4킬로미터
#define	IDM_0021500	649	//	21.5킬로미터
#define	IDM_0021600	650	//	21.6킬로미터
#define	IDM_0021700	651	//	21.7킬로미터
#define	IDM_0021800	652	//	21.8킬로미터
#define	IDM_0021900	653	//	21.9킬로미터
#define	IDM_0022000	654	//	22킬로미터
#define	IDM_0022100	655	//	22.1킬로미터
#define	IDM_0022200	656	//	22.2킬로미터
#define	IDM_0022300	657	//	22.3킬로미터
#define	IDM_0022400	658	//	22.4킬로미터
#define	IDM_0022500	659	//	22.5킬로미터
#define	IDM_0022600	660	//	22.6킬로미터
#define	IDM_0022700	661	//	22.7킬로미터
#define	IDM_0022800	662	//	22.8킬로미터
#define	IDM_0022900	663	//	22.9킬로미터
#define	IDM_0023000	664	//	23킬로미터
#define	IDM_0023100	665	//	23.1킬로미터
#define	IDM_0023200	666	//	23.2킬로미터
#define	IDM_0023300	667	//	23.3킬로미터
#define	IDM_0023400	668	//	23.4킬로미터
#define	IDM_0023500	669	//	23.5킬로미터
#define	IDM_0023600	670	//	23.6킬로미터
#define	IDM_0023700	671	//	23.7킬로미터
#define	IDM_0023800	672	//	23.8킬로미터
#define	IDM_0023900	673	//	23.9킬로미터
#define	IDM_0024000	674	//	24킬로미터
#define	IDM_0024100	675	//	24.1킬로미터
#define	IDM_0024200	676	//	24.2킬로미터
#define	IDM_0024300	677	//	24.3킬로미터
#define	IDM_0024400	678	//	24.4킬로미터
#define	IDM_0024500	679	//	24.5킬로미터
#define	IDM_0024600	680	//	24.6킬로미터
#define	IDM_0024700	681	//	24.7킬로미터
#define	IDM_0024800	682	//	24.8킬로미터
#define	IDM_0024900	683	//	24.9킬로미터
#define	IDM_0025000	684	//	25킬로미터
#define	IDM_0025100	685	//	25.1킬로미터
#define	IDM_0025200	686	//	25.2킬로미터
#define	IDM_0025300	687	//	25.3킬로미터
#define	IDM_0025400	688	//	25.4킬로미터
#define	IDM_0025500	689	//	25.5킬로미터
#define	IDM_0025600	690	//	25.6킬로미터
#define	IDM_0025700	691	//	25.7킬로미터
#define	IDM_0025800	692	//	25.8킬로미터
#define	IDM_0025900	693	//	25.9킬로미터
#define	IDM_0026000	694	//	26킬로미터
#define	IDM_0026100	695	//	26.1킬로미터
#define	IDM_0026200	696	//	26.2킬로미터
#define	IDM_0026300	697	//	26.3킬로미터
#define	IDM_0026400	698	//	26.4킬로미터
#define	IDM_0026500	699	//	26.5킬로미터
#define	IDM_0026600	700	//	26.6킬로미터
#define	IDM_0026700	701	//	26.7킬로미터
#define	IDM_0026800	702	//	26.8킬로미터
#define	IDM_0026900	703	//	26.9킬로미터
#define	IDM_0027000	704	//	27킬로미터
#define	IDM_0027100	705	//	27.1킬로미터
#define	IDM_0027200	706	//	27.2킬로미터
#define	IDM_0027300	707	//	27.3킬로미터
#define	IDM_0027400	708	//	27.4킬로미터
#define	IDM_0027500	709	//	27.5킬로미터
#define	IDM_0027600	710	//	27.6킬로미터
#define	IDM_0027700	711	//	27.7킬로미터
#define	IDM_0027800	712	//	27.8킬로미터
#define	IDM_0027900	713	//	27.9킬로미터
#define	IDM_0028000	714	//	28킬로미터
#define	IDM_0028100	715	//	28.1킬로미터
#define	IDM_0028200	716	//	28.2킬로미터
#define	IDM_0028300	717	//	28.3킬로미터
#define	IDM_0028400	718	//	28.4킬로미터
#define	IDM_0028500	719	//	28.5킬로미터
#define	IDM_0028600	720	//	28.6킬로미터
#define	IDM_0028700	721	//	28.7킬로미터
#define	IDM_0028800	722	//	28.8킬로미터
#define	IDM_0028900	723	//	28.9킬로미터
#define	IDM_0029000	724	//	29킬로미터
#define	IDM_0029100	725	//	29.1킬로미터
#define	IDM_0029200	726	//	29.2킬로미터
#define	IDM_0029300	727	//	29.3킬로미터
#define	IDM_0029400	728	//	29.4킬로미터
#define	IDM_0029500	729	//	29.5킬로미터
#define	IDM_0029600	730	//	29.6킬로미터
#define	IDM_0029700	731	//	29.7킬로미터
#define	IDM_0029800	732	//	29.8킬로미터
#define	IDM_0029900	733	//	29.9킬로미터
#define	IDM_0030000	734	//	30킬로미터
#define	IDM_0030100	735	//	30.1킬로미터
#define	IDM_0030200	736	//	30.2킬로미터
#define	IDM_0030300	737	//	30.3킬로미터
#define	IDM_0030400	738	//	30.4킬로미터
#define	IDM_0030500	739	//	30.5킬로미터
#define	IDM_0030600	740	//	30.6킬로미터
#define	IDM_0030700	741	//	30.7킬로미터
#define	IDM_0030800	742	//	30.8킬로미터
#define	IDM_0030900	743	//	30.9킬로미터
#define	IDM_0031000	744	//	31킬로미터
#define	IDM_0031100	745	//	31.1킬로미터
#define	IDM_0031200	746	//	31.2킬로미터
#define	IDM_0031300	747	//	31.3킬로미터
#define	IDM_0031400	748	//	31.4킬로미터
#define	IDM_0031500	749	//	31.5킬로미터
#define	IDM_0031600	750	//	31.6킬로미터
#define	IDM_0031700	751	//	31.7킬로미터
#define	IDM_0031800	752	//	31.8킬로미터
#define	IDM_0031900	753	//	31.9킬로미터
#define	IDM_0032000	754	//	32킬로미터
#define	IDM_0032100	755	//	32.1킬로미터
#define	IDM_0032200	756	//	32.2킬로미터
#define	IDM_0032300	757	//	32.3킬로미터
#define	IDM_0032400	758	//	32.4킬로미터
#define	IDM_0032500	759	//	32.5킬로미터
#define	IDM_0032600	760	//	32.6킬로미터
#define	IDM_0032700	761	//	32.7킬로미터
#define	IDM_0032800	762	//	32.8킬로미터
#define	IDM_0032900	763	//	32.9킬로미터
#define	IDM_0033000	764	//	33킬로미터
#define	IDM_0033100	765	//	33.1킬로미터
#define	IDM_0033200	766	//	33.2킬로미터
#define	IDM_0033300	767	//	33.3킬로미터
#define	IDM_0033400	768	//	33.4킬로미터
#define	IDM_0033500	769	//	33.5킬로미터
#define	IDM_0033600	770	//	33.6킬로미터
#define	IDM_0033700	771	//	33.7킬로미터
#define	IDM_0033800	772	//	33.8킬로미터
#define	IDM_0033900	773	//	33.9킬로미터
#define	IDM_0034000	774	//	34킬로미터
#define	IDM_0034100	775	//	34.1킬로미터
#define	IDM_0034200	776	//	34.2킬로미터
#define	IDM_0034300	777	//	34.3킬로미터
#define	IDM_0034400	778	//	34.4킬로미터
#define	IDM_0034500	779	//	34.5킬로미터
#define	IDM_0034600	780	//	34.6킬로미터
#define	IDM_0034700	781	//	34.7킬로미터
#define	IDM_0034800	782	//	34.8킬로미터
#define	IDM_0034900	783	//	34.9킬로미터
#define	IDM_0035000	784	//	35킬로미터
#define	IDM_0035100	785	//	35.1킬로미터
#define	IDM_0035200	786	//	35.2킬로미터
#define	IDM_0035300	787	//	35.3킬로미터
#define	IDM_0035400	788	//	35.4킬로미터
#define	IDM_0035500	789	//	35.5킬로미터
#define	IDM_0035600	790	//	35.6킬로미터
#define	IDM_0035700	791	//	35.7킬로미터
#define	IDM_0035800	792	//	35.8킬로미터
#define	IDM_0035900	793	//	35.9킬로미터
#define	IDM_0036000	794	//	36킬로미터
#define	IDM_0036100	795	//	36.1킬로미터
#define	IDM_0036200	796	//	36.2킬로미터
#define	IDM_0036300	797	//	36.3킬로미터
#define	IDM_0036400	798	//	36.4킬로미터
#define	IDM_0036500	799	//	36.5킬로미터
#define	IDM_0036600	800	//	36.6킬로미터
#define	IDM_0036700	801	//	36.7킬로미터
#define	IDM_0036800	802	//	36.8킬로미터
#define	IDM_0036900	803	//	36.9킬로미터
#define	IDM_0037000	804	//	37킬로미터
#define	IDM_0037100	805	//	37.1킬로미터
#define	IDM_0037200	806	//	37.2킬로미터
#define	IDM_0037300	807	//	37.3킬로미터
#define	IDM_0037400	808	//	37.4킬로미터
#define	IDM_0037500	809	//	37.5킬로미터
#define	IDM_0037600	810	//	37.6킬로미터
#define	IDM_0037700	811	//	37.7킬로미터
#define	IDM_0037800	812	//	37.8킬로미터
#define	IDM_0037900	813	//	37.9킬로미터
#define	IDM_0038000	814	//	38킬로미터
#define	IDM_0038100	815	//	38.1킬로미터
#define	IDM_0038200	816	//	38.2킬로미터
#define	IDM_0038300	817	//	38.3킬로미터
#define	IDM_0038400	818	//	38.4킬로미터
#define	IDM_0038500	819	//	38.5킬로미터
#define	IDM_0038600	820	//	38.6킬로미터
#define	IDM_0038700	821	//	38.7킬로미터
#define	IDM_0038800	822	//	38.8킬로미터
#define	IDM_0038900	823	//	38.9킬로미터
#define	IDM_0039000	824	//	39킬로미터
#define	IDM_0039100	825	//	39.1킬로미터
#define	IDM_0039200	826	//	39.2킬로미터
#define	IDM_0039300	827	//	39.3킬로미터
#define	IDM_0039400	828	//	39.4킬로미터
#define	IDM_0039500	829	//	39.5킬로미터
#define	IDM_0039600	830	//	39.6킬로미터
#define	IDM_0039700	831	//	39.7킬로미터
#define	IDM_0039800	832	//	39.8킬로미터
#define	IDM_0039900	833	//	39.9킬로미터
#define	IDM_0040000	834	//	40킬로미터
#define	IDM_0040100	835	//	40.1킬로미터
#define	IDM_0040200	836	//	40.2킬로미터
#define	IDM_0040300	837	//	40.3킬로미터
#define	IDM_0040400	838	//	40.4킬로미터
#define	IDM_0040500	839	//	40.5킬로미터
#define	IDM_0040600	840	//	40.6킬로미터
#define	IDM_0040700	841	//	40.7킬로미터
#define	IDM_0040800	842	//	40.8킬로미터
#define	IDM_0040900	843	//	40.9킬로미터
#define	IDM_0041000	844	//	41킬로미터
#define	IDM_0041100	845	//	41.1킬로미터
#define	IDM_0041200	846	//	41.2킬로미터
#define	IDM_0041300	847	//	41.3킬로미터
#define	IDM_0041400	848	//	41.4킬로미터
#define	IDM_0041500	849	//	41.5킬로미터
#define	IDM_0041600	850	//	41.6킬로미터
#define	IDM_0041700	851	//	41.7킬로미터
#define	IDM_0041800	852	//	41.8킬로미터
#define	IDM_0041900	853	//	41.9킬로미터
#define	IDM_0042000	854	//	42킬로미터
#define	IDM_0042100	855	//	42.1킬로미터
#define	IDM_0042200	856	//	42.2킬로미터
#define	IDM_0042300	857	//	42.3킬로미터
#define	IDM_0042400	858	//	42.4킬로미터
#define	IDM_0042500	859	//	42.5킬로미터
#define	IDM_0042600	860	//	42.6킬로미터
#define	IDM_0042700	861	//	42.7킬로미터
#define	IDM_0042800	862	//	42.8킬로미터
#define	IDM_0042900	863	//	42.9킬로미터
#define	IDM_0043000	864	//	43킬로미터
#define	IDM_0043100	865	//	43.1킬로미터
#define	IDM_0043200	866	//	43.2킬로미터
#define	IDM_0043300	867	//	43.3킬로미터
#define	IDM_0043400	868	//	43.4킬로미터
#define	IDM_0043500	869	//	43.5킬로미터
#define	IDM_0043600	870	//	43.6킬로미터
#define	IDM_0043700	871	//	43.7킬로미터
#define	IDM_0043800	872	//	43.8킬로미터
#define	IDM_0043900	873	//	43.9킬로미터
#define	IDM_0044000	874	//	44킬로미터
#define	IDM_0044100	875	//	44.1킬로미터
#define	IDM_0044200	876	//	44.2킬로미터
#define	IDM_0044300	877	//	44.3킬로미터
#define	IDM_0044400	878	//	44.4킬로미터
#define	IDM_0044500	879	//	44.5킬로미터
#define	IDM_0044600	880	//	44.6킬로미터
#define	IDM_0044700	881	//	44.7킬로미터
#define	IDM_0044800	882	//	44.8킬로미터
#define	IDM_0044900	883	//	44.9킬로미터
#define	IDM_0045000	884	//	45킬로미터
#define	IDM_0045100	885	//	45.1킬로미터
#define	IDM_0045200	886	//	45.2킬로미터
#define	IDM_0045300	887	//	45.3킬로미터
#define	IDM_0045400	888	//	45.4킬로미터
#define	IDM_0045500	889	//	45.5킬로미터
#define	IDM_0045600	890	//	45.6킬로미터
#define	IDM_0045700	891	//	45.7킬로미터
#define	IDM_0045800	892	//	45.8킬로미터
#define	IDM_0045900	893	//	45.9킬로미터
#define	IDM_0046000	894	//	46킬로미터
#define	IDM_0046100	895	//	46.1킬로미터
#define	IDM_0046200	896	//	46.2킬로미터
#define	IDM_0046300	897	//	46.3킬로미터
#define	IDM_0046400	898	//	46.4킬로미터
#define	IDM_0046500	899	//	46.5킬로미터
#define	IDM_0046600	900	//	46.6킬로미터
#define	IDM_0046700	901	//	46.7킬로미터
#define	IDM_0046800	902	//	46.8킬로미터
#define	IDM_0046900	903	//	46.9킬로미터
#define	IDM_0047000	904	//	47킬로미터
#define	IDM_0047100	905	//	47.1킬로미터
#define	IDM_0047200	906	//	47.2킬로미터
#define	IDM_0047300	907	//	47.3킬로미터
#define	IDM_0047400	908	//	47.4킬로미터
#define	IDM_0047500	909	//	47.5킬로미터
#define	IDM_0047600	910	//	47.6킬로미터
#define	IDM_0047700	911	//	47.7킬로미터
#define	IDM_0047800	912	//	47.8킬로미터
#define	IDM_0047900	913	//	47.9킬로미터
#define	IDM_0048000	914	//	48킬로미터
#define	IDM_0048100	915	//	48.1킬로미터
#define	IDM_0048200	916	//	48.2킬로미터
#define	IDM_0048300	917	//	48.3킬로미터
#define	IDM_0048400	918	//	48.4킬로미터
#define	IDM_0048500	919	//	48.5킬로미터
#define	IDM_0048600	920	//	48.6킬로미터
#define	IDM_0048700	921	//	48.7킬로미터
#define	IDM_0048800	922	//	48.8킬로미터
#define	IDM_0048900	923	//	48.9킬로미터
#define	IDM_0049000	924	//	49킬로미터
#define	IDM_0049100	925	//	49.1킬로미터
#define	IDM_0049200	926	//	49.2킬로미터
#define	IDM_0049300	927	//	49.3킬로미터
#define	IDM_0049400	928	//	49.4킬로미터
#define	IDM_0049500	929	//	49.5킬로미터
#define	IDM_0049600	930	//	49.6킬로미터
#define	IDM_0049700	931	//	49.7킬로미터
#define	IDM_0049800	932	//	49.8킬로미터
#define	IDM_0049900	933	//	49.9킬로미터
#define	IDM_0050000	934	//	50킬로미터
#define	IDM_0050100	935	//	50.1킬로미터
#define	IDM_0050200	936	//	50.2킬로미터
#define	IDM_0050300	937	//	50.3킬로미터
#define	IDM_0050400	938	//	50.4킬로미터
#define	IDM_0050500	939	//	50.5킬로미터
#define	IDM_0050600	940	//	50.6킬로미터
#define	IDM_0050700	941	//	50.7킬로미터
#define	IDM_0050800	942	//	50.8킬로미터
#define	IDM_0050900	943	//	50.9킬로미터
#define	IDM_0051000	944	//	51킬로미터
#define	IDM_0051100	945	//	51.1킬로미터
#define	IDM_0051200	946	//	51.2킬로미터
#define	IDM_0051300	947	//	51.3킬로미터
#define	IDM_0051400	948	//	51.4킬로미터
#define	IDM_0051500	949	//	51.5킬로미터
#define	IDM_0051600	950	//	51.6킬로미터
#define	IDM_0051700	951	//	51.7킬로미터
#define	IDM_0051800	952	//	51.8킬로미터
#define	IDM_0051900	953	//	51.9킬로미터
#define	IDM_0052000	954	//	52킬로미터
#define	IDM_0052100	955	//	52.1킬로미터
#define	IDM_0052200	956	//	52.2킬로미터
#define	IDM_0052300	957	//	52.3킬로미터
#define	IDM_0052400	958	//	52.4킬로미터
#define	IDM_0052500	959	//	52.5킬로미터
#define	IDM_0052600	960	//	52.6킬로미터
#define	IDM_0052700	961	//	52.7킬로미터
#define	IDM_0052800	962	//	52.8킬로미터
#define	IDM_0052900	963	//	52.9킬로미터
#define	IDM_0053000	964	//	53킬로미터
#define	IDM_0053100	965	//	53.1킬로미터
#define	IDM_0053200	966	//	53.2킬로미터
#define	IDM_0053300	967	//	53.3킬로미터
#define	IDM_0053400	968	//	53.4킬로미터
#define	IDM_0053500	969	//	53.5킬로미터
#define	IDM_0053600	970	//	53.6킬로미터
#define	IDM_0053700	971	//	53.7킬로미터
#define	IDM_0053800	972	//	53.8킬로미터
#define	IDM_0053900	973	//	53.9킬로미터
#define	IDM_0054000	974	//	54킬로미터
#define	IDM_0054100	975	//	54.1킬로미터
#define	IDM_0054200	976	//	54.2킬로미터
#define	IDM_0054300	977	//	54.3킬로미터
#define	IDM_0054400	978	//	54.4킬로미터
#define	IDM_0054500	979	//	54.5킬로미터
#define	IDM_0054600	980	//	54.6킬로미터
#define	IDM_0054700	981	//	54.7킬로미터
#define	IDM_0054800	982	//	54.8킬로미터
#define	IDM_0054900	983	//	54.9킬로미터
#define	IDM_0055000	984	//	55킬로미터
#define	IDM_0055100	985	//	55.1킬로미터
#define	IDM_0055200	986	//	55.2킬로미터
#define	IDM_0055300	987	//	55.3킬로미터
#define	IDM_0055400	988	//	55.4킬로미터
#define	IDM_0055500	989	//	55.5킬로미터
#define	IDM_0055600	990	//	55.6킬로미터
#define	IDM_0055700	991	//	55.7킬로미터
#define	IDM_0055800	992	//	55.8킬로미터
#define	IDM_0055900	993	//	55.9킬로미터
#define	IDM_0056000	994	//	56킬로미터
#define	IDM_0056100	995	//	56.1킬로미터
#define	IDM_0056200	996	//	56.2킬로미터
#define	IDM_0056300	997	//	56.3킬로미터
#define	IDM_0056400	998	//	56.4킬로미터
#define	IDM_0056500	999	//	56.5킬로미터
#define	IDM_0056600	1000	//	56.6킬로미터
#define	IDM_0056700	1001	//	56.7킬로미터
#define	IDM_0056800	1002	//	56.8킬로미터
#define	IDM_0056900	1003	//	56.9킬로미터
#define	IDM_0057000	1004	//	57킬로미터
#define	IDM_0057100	1005	//	57.1킬로미터
#define	IDM_0057200	1006	//	57.2킬로미터
#define	IDM_0057300	1007	//	57.3킬로미터
#define	IDM_0057400	1008	//	57.4킬로미터
#define	IDM_0057500	1009	//	57.5킬로미터
#define	IDM_0057600	1010	//	57.6킬로미터
#define	IDM_0057700	1011	//	57.7킬로미터
#define	IDM_0057800	1012	//	57.8킬로미터
#define	IDM_0057900	1013	//	57.9킬로미터
#define	IDM_0058000	1014	//	58킬로미터
#define	IDM_0058100	1015	//	58.1킬로미터
#define	IDM_0058200	1016	//	58.2킬로미터
#define	IDM_0058300	1017	//	58.3킬로미터
#define	IDM_0058400	1018	//	58.4킬로미터
#define	IDM_0058500	1019	//	58.5킬로미터
#define	IDM_0058600	1020	//	58.6킬로미터
#define	IDM_0058700	1021	//	58.7킬로미터
#define	IDM_0058800	1022	//	58.8킬로미터
#define	IDM_0058900	1023	//	58.9킬로미터
#define	IDM_0059000	1024	//	59킬로미터
#define	IDM_0059100	1025	//	59.1킬로미터
#define	IDM_0059200	1026	//	59.2킬로미터
#define	IDM_0059300	1027	//	59.3킬로미터
#define	IDM_0059400	1028	//	59.4킬로미터
#define	IDM_0059500	1029	//	59.5킬로미터
#define	IDM_0059600	1030	//	59.6킬로미터
#define	IDM_0059700	1031	//	59.7킬로미터
#define	IDM_0059800	1032	//	59.8킬로미터
#define	IDM_0059900	1033	//	59.9킬로미터
#define	IDM_0060000	1034	//	60킬로미터
#define	IDM_0060100	1035	//	60.1킬로미터
#define	IDM_0060200	1036	//	60.2킬로미터
#define	IDM_0060300	1037	//	60.3킬로미터
#define	IDM_0060400	1038	//	60.4킬로미터
#define	IDM_0060500	1039	//	60.5킬로미터
#define	IDM_0060600	1040	//	60.6킬로미터
#define	IDM_0060700	1041	//	60.7킬로미터
#define	IDM_0060800	1042	//	60.8킬로미터
#define	IDM_0060900	1043	//	60.9킬로미터
#define	IDM_0061000	1044	//	61킬로미터
#define	IDM_0061100	1045	//	61.1킬로미터
#define	IDM_0061200	1046	//	61.2킬로미터
#define	IDM_0061300	1047	//	61.3킬로미터
#define	IDM_0061400	1048	//	61.4킬로미터
#define	IDM_0061500	1049	//	61.5킬로미터
#define	IDM_0061600	1050	//	61.6킬로미터
#define	IDM_0061700	1051	//	61.7킬로미터
#define	IDM_0061800	1052	//	61.8킬로미터
#define	IDM_0061900	1053	//	61.9킬로미터
#define	IDM_0062000	1054	//	62킬로미터
#define	IDM_0062100	1055	//	62.1킬로미터
#define	IDM_0062200	1056	//	62.2킬로미터
#define	IDM_0062300	1057	//	62.3킬로미터
#define	IDM_0062400	1058	//	62.4킬로미터
#define	IDM_0062500	1059	//	62.5킬로미터
#define	IDM_0062600	1060	//	62.6킬로미터
#define	IDM_0062700	1061	//	62.7킬로미터
#define	IDM_0062800	1062	//	62.8킬로미터
#define	IDM_0062900	1063	//	62.9킬로미터
#define	IDM_0063000	1064	//	63킬로미터
#define	IDM_0063100	1065	//	63.1킬로미터
#define	IDM_0063200	1066	//	63.2킬로미터
#define	IDM_0063300	1067	//	63.3킬로미터
#define	IDM_0063400	1068	//	63.4킬로미터
#define	IDM_0063500	1069	//	63.5킬로미터
#define	IDM_0063600	1070	//	63.6킬로미터
#define	IDM_0063700	1071	//	63.7킬로미터
#define	IDM_0063800	1072	//	63.8킬로미터
#define	IDM_0063900	1073	//	63.9킬로미터
#define	IDM_0064000	1074	//	64킬로미터
#define	IDM_0064100	1075	//	64.1킬로미터
#define	IDM_0064200	1076	//	64.2킬로미터
#define	IDM_0064300	1077	//	64.3킬로미터
#define	IDM_0064400	1078	//	64.4킬로미터
#define	IDM_0064500	1079	//	64.5킬로미터
#define	IDM_0064600	1080	//	64.6킬로미터
#define	IDM_0064700	1081	//	64.7킬로미터
#define	IDM_0064800	1082	//	64.8킬로미터
#define	IDM_0064900	1083	//	64.9킬로미터
#define	IDM_0065000	1084	//	65킬로미터
#define	IDM_0065100	1085	//	65.1킬로미터
#define	IDM_0065200	1086	//	65.2킬로미터
#define	IDM_0065300	1087	//	65.3킬로미터
#define	IDM_0065400	1088	//	65.4킬로미터
#define	IDM_0065500	1089	//	65.5킬로미터
#define	IDM_0065600	1090	//	65.6킬로미터
#define	IDM_0065700	1091	//	65.7킬로미터
#define	IDM_0065800	1092	//	65.8킬로미터
#define	IDM_0065900	1093	//	65.9킬로미터
#define	IDM_0066000	1094	//	66킬로미터
#define	IDM_0066100	1095	//	66.1킬로미터
#define	IDM_0066200	1096	//	66.2킬로미터
#define	IDM_0066300	1097	//	66.3킬로미터
#define	IDM_0066400	1098	//	66.4킬로미터
#define	IDM_0066500	1099	//	66.5킬로미터
#define	IDM_0066600	1100	//	66.6킬로미터
#define	IDM_0066700	1101	//	66.7킬로미터
#define	IDM_0066800	1102	//	66.8킬로미터
#define	IDM_0066900	1103	//	66.9킬로미터
#define	IDM_0067000	1104	//	67킬로미터
#define	IDM_0067100	1105	//	67.1킬로미터
#define	IDM_0067200	1106	//	67.2킬로미터
#define	IDM_0067300	1107	//	67.3킬로미터
#define	IDM_0067400	1108	//	67.4킬로미터
#define	IDM_0067500	1109	//	67.5킬로미터
#define	IDM_0067600	1110	//	67.6킬로미터
#define	IDM_0067700	1111	//	67.7킬로미터
#define	IDM_0067800	1112	//	67.8킬로미터
#define	IDM_0067900	1113	//	67.9킬로미터
#define	IDM_0068000	1114	//	68킬로미터
#define	IDM_0068100	1115	//	68.1킬로미터
#define	IDM_0068200	1116	//	68.2킬로미터
#define	IDM_0068300	1117	//	68.3킬로미터
#define	IDM_0068400	1118	//	68.4킬로미터
#define	IDM_0068500	1119	//	68.5킬로미터
#define	IDM_0068600	1120	//	68.6킬로미터
#define	IDM_0068700	1121	//	68.7킬로미터
#define	IDM_0068800	1122	//	68.8킬로미터
#define	IDM_0068900	1123	//	68.9킬로미터
#define	IDM_0069000	1124	//	69킬로미터
#define	IDM_0069100	1125	//	69.1킬로미터
#define	IDM_0069200	1126	//	69.2킬로미터
#define	IDM_0069300	1127	//	69.3킬로미터
#define	IDM_0069400	1128	//	69.4킬로미터
#define	IDM_0069500	1129	//	69.5킬로미터
#define	IDM_0069600	1130	//	69.6킬로미터
#define	IDM_0069700	1131	//	69.7킬로미터
#define	IDM_0069800	1132	//	69.8킬로미터
#define	IDM_0069900	1133	//	69.9킬로미터
#define	IDM_0070000	1134	//	70킬로미터
#define	IDM_0070100	1135	//	70.1킬로미터
#define	IDM_0070200	1136	//	70.2킬로미터
#define	IDM_0070300	1137	//	70.3킬로미터
#define	IDM_0070400	1138	//	70.4킬로미터
#define	IDM_0070500	1139	//	70.5킬로미터
#define	IDM_0070600	1140	//	70.6킬로미터
#define	IDM_0070700	1141	//	70.7킬로미터
#define	IDM_0070800	1142	//	70.8킬로미터
#define	IDM_0070900	1143	//	70.9킬로미터
#define	IDM_0071000	1144	//	71킬로미터
#define	IDM_0071100	1145	//	71.1킬로미터
#define	IDM_0071200	1146	//	71.2킬로미터
#define	IDM_0071300	1147	//	71.3킬로미터
#define	IDM_0071400	1148	//	71.4킬로미터
#define	IDM_0071500	1149	//	71.5킬로미터
#define	IDM_0071600	1150	//	71.6킬로미터
#define	IDM_0071700	1151	//	71.7킬로미터
#define	IDM_0071800	1152	//	71.8킬로미터
#define	IDM_0071900	1153	//	71.9킬로미터
#define	IDM_0072000	1154	//	72킬로미터
#define	IDM_0072100	1155	//	72.1킬로미터
#define	IDM_0072200	1156	//	72.2킬로미터
#define	IDM_0072300	1157	//	72.3킬로미터
#define	IDM_0072400	1158	//	72.4킬로미터
#define	IDM_0072500	1159	//	72.5킬로미터
#define	IDM_0072600	1160	//	72.6킬로미터
#define	IDM_0072700	1161	//	72.7킬로미터
#define	IDM_0072800	1162	//	72.8킬로미터
#define	IDM_0072900	1163	//	72.9킬로미터
#define	IDM_0073000	1164	//	73킬로미터
#define	IDM_0073100	1165	//	73.1킬로미터
#define	IDM_0073200	1166	//	73.2킬로미터
#define	IDM_0073300	1167	//	73.3킬로미터
#define	IDM_0073400	1168	//	73.4킬로미터
#define	IDM_0073500	1169	//	73.5킬로미터
#define	IDM_0073600	1170	//	73.6킬로미터
#define	IDM_0073700	1171	//	73.7킬로미터
#define	IDM_0073800	1172	//	73.8킬로미터
#define	IDM_0073900	1173	//	73.9킬로미터
#define	IDM_0074000	1174	//	74킬로미터
#define	IDM_0074100	1175	//	74.1킬로미터
#define	IDM_0074200	1176	//	74.2킬로미터
#define	IDM_0074300	1177	//	74.3킬로미터
#define	IDM_0074400	1178	//	74.4킬로미터
#define	IDM_0074500	1179	//	74.5킬로미터
#define	IDM_0074600	1180	//	74.6킬로미터
#define	IDM_0074700	1181	//	74.7킬로미터
#define	IDM_0074800	1182	//	74.8킬로미터
#define	IDM_0074900	1183	//	74.9킬로미터
#define	IDM_0075000	1184	//	75킬로미터
#define	IDM_0075100	1185	//	75.1킬로미터
#define	IDM_0075200	1186	//	75.2킬로미터
#define	IDM_0075300	1187	//	75.3킬로미터
#define	IDM_0075400	1188	//	75.4킬로미터
#define	IDM_0075500	1189	//	75.5킬로미터
#define	IDM_0075600	1190	//	75.6킬로미터
#define	IDM_0075700	1191	//	75.7킬로미터
#define	IDM_0075800	1192	//	75.8킬로미터
#define	IDM_0075900	1193	//	75.9킬로미터
#define	IDM_0076000	1194	//	76킬로미터
#define	IDM_0076100	1195	//	76.1킬로미터
#define	IDM_0076200	1196	//	76.2킬로미터
#define	IDM_0076300	1197	//	76.3킬로미터
#define	IDM_0076400	1198	//	76.4킬로미터
#define	IDM_0076500	1199	//	76.5킬로미터
#define	IDM_0076600	1200	//	76.6킬로미터
#define	IDM_0076700	1201	//	76.7킬로미터
#define	IDM_0076800	1202	//	76.8킬로미터
#define	IDM_0076900	1203	//	76.9킬로미터
#define	IDM_0077000	1204	//	77킬로미터
#define	IDM_0077100	1205	//	77.1킬로미터
#define	IDM_0077200	1206	//	77.2킬로미터
#define	IDM_0077300	1207	//	77.3킬로미터
#define	IDM_0077400	1208	//	77.4킬로미터
#define	IDM_0077500	1209	//	77.5킬로미터
#define	IDM_0077600	1210	//	77.6킬로미터
#define	IDM_0077700	1211	//	77.7킬로미터
#define	IDM_0077800	1212	//	77.8킬로미터
#define	IDM_0077900	1213	//	77.9킬로미터
#define	IDM_0078000	1214	//	78킬로미터
#define	IDM_0078100	1215	//	78.1킬로미터
#define	IDM_0078200	1216	//	78.2킬로미터
#define	IDM_0078300	1217	//	78.3킬로미터
#define	IDM_0078400	1218	//	78.4킬로미터
#define	IDM_0078500	1219	//	78.5킬로미터
#define	IDM_0078600	1220	//	78.6킬로미터
#define	IDM_0078700	1221	//	78.7킬로미터
#define	IDM_0078800	1222	//	78.8킬로미터
#define	IDM_0078900	1223	//	78.9킬로미터
#define	IDM_0079000	1224	//	79킬로미터
#define	IDM_0079100	1225	//	79.1킬로미터
#define	IDM_0079200	1226	//	79.2킬로미터
#define	IDM_0079300	1227	//	79.3킬로미터
#define	IDM_0079400	1228	//	79.4킬로미터
#define	IDM_0079500	1229	//	79.5킬로미터
#define	IDM_0079600	1230	//	79.6킬로미터
#define	IDM_0079700	1231	//	79.7킬로미터
#define	IDM_0079800	1232	//	79.8킬로미터
#define	IDM_0079900	1233	//	79.9킬로미터
#define	IDM_0080000	1234	//	80킬로미터
#define	IDM_0080100	1235	//	80.1킬로미터
#define	IDM_0080200	1236	//	80.2킬로미터
#define	IDM_0080300	1237	//	80.3킬로미터
#define	IDM_0080400	1238	//	80.4킬로미터
#define	IDM_0080500	1239	//	80.5킬로미터
#define	IDM_0080600	1240	//	80.6킬로미터
#define	IDM_0080700	1241	//	80.7킬로미터
#define	IDM_0080800	1242	//	80.8킬로미터
#define	IDM_0080900	1243	//	80.9킬로미터
#define	IDM_0081000	1244	//	81킬로미터
#define	IDM_0081100	1245	//	81.1킬로미터
#define	IDM_0081200	1246	//	81.2킬로미터
#define	IDM_0081300	1247	//	81.3킬로미터
#define	IDM_0081400	1248	//	81.4킬로미터
#define	IDM_0081500	1249	//	81.5킬로미터
#define	IDM_0081600	1250	//	81.6킬로미터
#define	IDM_0081700	1251	//	81.7킬로미터
#define	IDM_0081800	1252	//	81.8킬로미터
#define	IDM_0081900	1253	//	81.9킬로미터
#define	IDM_0082000	1254	//	82킬로미터
#define	IDM_0082100	1255	//	82.1킬로미터
#define	IDM_0082200	1256	//	82.2킬로미터
#define	IDM_0082300	1257	//	82.3킬로미터
#define	IDM_0082400	1258	//	82.4킬로미터
#define	IDM_0082500	1259	//	82.5킬로미터
#define	IDM_0082600	1260	//	82.6킬로미터
#define	IDM_0082700	1261	//	82.7킬로미터
#define	IDM_0082800	1262	//	82.8킬로미터
#define	IDM_0082900	1263	//	82.9킬로미터
#define	IDM_0083000	1264	//	83킬로미터
#define	IDM_0083100	1265	//	83.1킬로미터
#define	IDM_0083200	1266	//	83.2킬로미터
#define	IDM_0083300	1267	//	83.3킬로미터
#define	IDM_0083400	1268	//	83.4킬로미터
#define	IDM_0083500	1269	//	83.5킬로미터
#define	IDM_0083600	1270	//	83.6킬로미터
#define	IDM_0083700	1271	//	83.7킬로미터
#define	IDM_0083800	1272	//	83.8킬로미터
#define	IDM_0083900	1273	//	83.9킬로미터
#define	IDM_0084000	1274	//	84킬로미터
#define	IDM_0084100	1275	//	84.1킬로미터
#define	IDM_0084200	1276	//	84.2킬로미터
#define	IDM_0084300	1277	//	84.3킬로미터
#define	IDM_0084400	1278	//	84.4킬로미터
#define	IDM_0084500	1279	//	84.5킬로미터
#define	IDM_0084600	1280	//	84.6킬로미터
#define	IDM_0084700	1281	//	84.7킬로미터
#define	IDM_0084800	1282	//	84.8킬로미터
#define	IDM_0084900	1283	//	84.9킬로미터
#define	IDM_0085000	1284	//	85킬로미터
#define	IDM_0085100	1285	//	85.1킬로미터
#define	IDM_0085200	1286	//	85.2킬로미터
#define	IDM_0085300	1287	//	85.3킬로미터
#define	IDM_0085400	1288	//	85.4킬로미터
#define	IDM_0085500	1289	//	85.5킬로미터
#define	IDM_0085600	1290	//	85.6킬로미터
#define	IDM_0085700	1291	//	85.7킬로미터
#define	IDM_0085800	1292	//	85.8킬로미터
#define	IDM_0085900	1293	//	85.9킬로미터
#define	IDM_0086000	1294	//	86킬로미터
#define	IDM_0086100	1295	//	86.1킬로미터
#define	IDM_0086200	1296	//	86.2킬로미터
#define	IDM_0086300	1297	//	86.3킬로미터
#define	IDM_0086400	1298	//	86.4킬로미터
#define	IDM_0086500	1299	//	86.5킬로미터
#define	IDM_0086600	1300	//	86.6킬로미터
#define	IDM_0086700	1301	//	86.7킬로미터
#define	IDM_0086800	1302	//	86.8킬로미터
#define	IDM_0086900	1303	//	86.9킬로미터
#define	IDM_0087000	1304	//	87킬로미터
#define	IDM_0087100	1305	//	87.1킬로미터
#define	IDM_0087200	1306	//	87.2킬로미터
#define	IDM_0087300	1307	//	87.3킬로미터
#define	IDM_0087400	1308	//	87.4킬로미터
#define	IDM_0087500	1309	//	87.5킬로미터
#define	IDM_0087600	1310	//	87.6킬로미터
#define	IDM_0087700	1311	//	87.7킬로미터
#define	IDM_0087800	1312	//	87.8킬로미터
#define	IDM_0087900	1313	//	87.9킬로미터
#define	IDM_0088000	1314	//	88킬로미터
#define	IDM_0088100	1315	//	88.1킬로미터
#define	IDM_0088200	1316	//	88.2킬로미터
#define	IDM_0088300	1317	//	88.3킬로미터
#define	IDM_0088400	1318	//	88.4킬로미터
#define	IDM_0088500	1319	//	88.5킬로미터
#define	IDM_0088600	1320	//	88.6킬로미터
#define	IDM_0088700	1321	//	88.7킬로미터
#define	IDM_0088800	1322	//	88.8킬로미터
#define	IDM_0088900	1323	//	88.9킬로미터
#define	IDM_0089000	1324	//	89킬로미터
#define	IDM_0089100	1325	//	89.1킬로미터
#define	IDM_0089200	1326	//	89.2킬로미터
#define	IDM_0089300	1327	//	89.3킬로미터
#define	IDM_0089400	1328	//	89.4킬로미터
#define	IDM_0089500	1329	//	89.5킬로미터
#define	IDM_0089600	1330	//	89.6킬로미터
#define	IDM_0089700	1331	//	89.7킬로미터
#define	IDM_0089800	1332	//	89.8킬로미터
#define	IDM_0089900	1333	//	89.9킬로미터
#define	IDM_0090000	1334	//	90킬로미터
#define	IDM_0090100	1335	//	90.1킬로미터
#define	IDM_0090200	1336	//	90.2킬로미터
#define	IDM_0090300	1337	//	90.3킬로미터
#define	IDM_0090400	1338	//	90.4킬로미터
#define	IDM_0090500	1339	//	90.5킬로미터
#define	IDM_0090600	1340	//	90.6킬로미터
#define	IDM_0090700	1341	//	90.7킬로미터
#define	IDM_0090800	1342	//	90.8킬로미터
#define	IDM_0090900	1343	//	90.9킬로미터
#define	IDM_0091000	1344	//	91킬로미터
#define	IDM_0091100	1345	//	91.1킬로미터
#define	IDM_0091200	1346	//	91.2킬로미터
#define	IDM_0091300	1347	//	91.3킬로미터
#define	IDM_0091400	1348	//	91.4킬로미터
#define	IDM_0091500	1349	//	91.5킬로미터
#define	IDM_0091600	1350	//	91.6킬로미터
#define	IDM_0091700	1351	//	91.7킬로미터
#define	IDM_0091800	1352	//	91.8킬로미터
#define	IDM_0091900	1353	//	91.9킬로미터
#define	IDM_0092000	1354	//	92킬로미터
#define	IDM_0092100	1355	//	92.1킬로미터
#define	IDM_0092200	1356	//	92.2킬로미터
#define	IDM_0092300	1357	//	92.3킬로미터
#define	IDM_0092400	1358	//	92.4킬로미터
#define	IDM_0092500	1359	//	92.5킬로미터
#define	IDM_0092600	1360	//	92.6킬로미터
#define	IDM_0092700	1361	//	92.7킬로미터
#define	IDM_0092800	1362	//	92.8킬로미터
#define	IDM_0092900	1363	//	92.9킬로미터
#define	IDM_0093000	1364	//	93킬로미터
#define	IDM_0093100	1365	//	93.1킬로미터
#define	IDM_0093200	1366	//	93.2킬로미터
#define	IDM_0093300	1367	//	93.3킬로미터
#define	IDM_0093400	1368	//	93.4킬로미터
#define	IDM_0093500	1369	//	93.5킬로미터
#define	IDM_0093600	1370	//	93.6킬로미터
#define	IDM_0093700	1371	//	93.7킬로미터
#define	IDM_0093800	1372	//	93.8킬로미터
#define	IDM_0093900	1373	//	93.9킬로미터
#define	IDM_0094000	1374	//	94킬로미터
#define	IDM_0094100	1375	//	94.1킬로미터
#define	IDM_0094200	1376	//	94.2킬로미터
#define	IDM_0094300	1377	//	94.3킬로미터
#define	IDM_0094400	1378	//	94.4킬로미터
#define	IDM_0094500	1379	//	94.5킬로미터
#define	IDM_0094600	1380	//	94.6킬로미터
#define	IDM_0094700	1381	//	94.7킬로미터
#define	IDM_0094800	1382	//	94.8킬로미터
#define	IDM_0094900	1383	//	94.9킬로미터
#define	IDM_0095000	1384	//	95킬로미터
#define	IDM_0095100	1385	//	95.1킬로미터
#define	IDM_0095200	1386	//	95.2킬로미터
#define	IDM_0095300	1387	//	95.3킬로미터
#define	IDM_0095400	1388	//	95.4킬로미터
#define	IDM_0095500	1389	//	95.5킬로미터
#define	IDM_0095600	1390	//	95.6킬로미터
#define	IDM_0095700	1391	//	95.7킬로미터
#define	IDM_0095800	1392	//	95.8킬로미터
#define	IDM_0095900	1393	//	95.9킬로미터
#define	IDM_0096000	1394	//	96킬로미터
#define	IDM_0096100	1395	//	96.1킬로미터
#define	IDM_0096200	1396	//	96.2킬로미터
#define	IDM_0096300	1397	//	96.3킬로미터
#define	IDM_0096400	1398	//	96.4킬로미터
#define	IDM_0096500	1399	//	96.5킬로미터
#define	IDM_0096600	1400	//	96.6킬로미터
#define	IDM_0096700	1401	//	96.7킬로미터
#define	IDM_0096800	1402	//	96.8킬로미터
#define	IDM_0096900	1403	//	96.9킬로미터
#define	IDM_0097000	1404	//	97킬로미터
#define	IDM_0097100	1405	//	97.1킬로미터
#define	IDM_0097200	1406	//	97.2킬로미터
#define	IDM_0097300	1407	//	97.3킬로미터
#define	IDM_0097400	1408	//	97.4킬로미터
#define	IDM_0097500	1409	//	97.5킬로미터
#define	IDM_0097600	1410	//	97.6킬로미터
#define	IDM_0097700	1411	//	97.7킬로미터
#define	IDM_0097800	1412	//	97.8킬로미터
#define	IDM_0097900	1413	//	97.9킬로미터
#define	IDM_0098000	1414	//	98킬로미터
#define	IDM_0098100	1415	//	98.1킬로미터
#define	IDM_0098200	1416	//	98.2킬로미터
#define	IDM_0098300	1417	//	98.3킬로미터
#define	IDM_0098400	1418	//	98.4킬로미터
#define	IDM_0098500	1419	//	98.5킬로미터
#define	IDM_0098600	1420	//	98.6킬로미터
#define	IDM_0098700	1421	//	98.7킬로미터
#define	IDM_0098800	1422	//	98.8킬로미터
#define	IDM_0098900	1423	//	98.9킬로미터
#define	IDM_0099000	1424	//	99킬로미터
#define	IDM_0099100	1425	//	99.1킬로미터
#define	IDM_0099200	1426	//	99.2킬로미터
#define	IDM_0099300	1427	//	99.3킬로미터
#define	IDM_0099400	1428	//	99.4킬로미터
#define	IDM_0099500	1429	//	99.5킬로미터
#define	IDM_0099600	1430	//	99.6킬로미터
#define	IDM_0099700	1431	//	99.7킬로미터
#define	IDM_0099800	1432	//	99.8킬로미터
#define	IDM_0099900	1433	//	99.9킬로미터
#define	IDM_0100000	1434	//	100킬로미터
#define	IDM_0110000	1435	//	110킬로미터
#define	IDM_0120000	1436	//	120킬로미터
#define	IDM_0130000	1437	//	130킬로미터
#define	IDM_0140000	1438	//	140킬로미터
#define	IDM_0150000	1439	//	150킬로미터
#define	IDM_0160000	1440	//	160킬로미터
#define	IDM_0170000	1441	//	170킬로미터
#define	IDM_0180000	1442	//	180킬로미터
#define	IDM_0190000	1443	//	190킬로미터
#define	IDM_0200000	1444	//	200킬로미터
#define	IDM_0210000	1445	//	210킬로미터
#define	IDM_0220000	1446	//	220킬로미터
#define	IDM_0230000	1447	//	230킬로미터
#define	IDM_0240000	1448	//	240킬로미터
#define	IDM_0250000	1449	//	250킬로미터
#define	IDM_0260000	1450	//	260킬로미터
#define	IDM_0270000	1451	//	270킬로미터
#define	IDM_0280000	1452	//	280킬로미터
#define	IDM_0290000	1453	//	290킬로미터
#define	IDM_0300000	1454	//	300킬로미터
#define	IDM_0310000	1455	//	310킬로미터
#define	IDM_0320000	1456	//	320킬로미터
#define	IDM_0330000	1457	//	330킬로미터
#define	IDM_0340000	1458	//	340킬로미터
#define	IDM_0350000	1459	//	350킬로미터
#define	IDM_0360000	1460	//	360킬로미터
#define	IDM_0370000	1461	//	370킬로미터
#define	IDM_0380000	1462	//	380킬로미터
#define	IDM_0390000	1463	//	390킬로미터
#define	IDM_0400000	1464	//	400킬로미터
#define	IDM_0410000	1465	//	410킬로미터
#define	IDM_0420000	1466	//	420킬로미터
#define	IDM_0430000	1467	//	430킬로미터
#define	IDM_0440000	1468	//	440킬로미터
#define	IDM_0450000	1469	//	450킬로미터
#define	IDM_0460000	1470	//	460킬로미터
#define	IDM_0470000	1471	//	470킬로미터
#define	IDM_0480000	1472	//	480킬로미터
#define	IDM_0490000	1473	//	490킬로미터
#define	IDM_0500000	1474	//	500킬로미터
#define	IDM_0510000	1475	//	510킬로미터
#define	IDM_0520000	1476	//	520킬로미터
#define	IDM_0530000	1477	//	530킬로미터
#define	IDM_0540000	1478	//	540킬로미터
#define	IDM_0550000	1479	//	550킬로미터
#define	IDM_0560000	1480	//	560킬로미터
#define	IDM_0570000	1481	//	570킬로미터
#define	IDM_0580000	1482	//	580킬로미터
#define	IDM_0590000	1483	//	590킬로미터
#define	IDM_0600000	1484	//	600킬로미터
#define	IDM_0610000	1485	//	610킬로미터
#define	IDM_0620000	1486	//	620킬로미터
#define	IDM_0630000	1487	//	630킬로미터
#define	IDM_0640000	1488	//	640킬로미터
#define	IDM_0650000	1489	//	650킬로미터
#define	IDM_0660000	1490	//	660킬로미터
#define	IDM_0670000	1491	//	670킬로미터
#define	IDM_0680000	1492	//	680킬로미터
#define	IDM_0690000	1493	//	690킬로미터
#define	IDM_0700000	1494	//	700킬로미터
#define	IDM_0710000	1495	//	710킬로미터
#define	IDM_0720000	1496	//	720킬로미터
#define	IDM_0730000	1497	//	730킬로미터
#define	IDM_0740000	1498	//	740킬로미터
#define	IDM_0750000	1499	//	750킬로미터
#define	IDM_0760000	1500	//	760킬로미터
#define	IDM_0770000	1501	//	770킬로미터
#define	IDM_0780000	1502	//	780킬로미터
#define	IDM_0790000	1503	//	790킬로미터
#define	IDM_0800000	1504	//	800킬로미터
#define	IDM_0810000	1505	//	810킬로미터
#define	IDM_0820000	1506	//	820킬로미터
#define	IDM_0830000	1507	//	830킬로미터
#define	IDM_0840000	1508	//	840킬로미터
#define	IDM_0850000	1509	//	850킬로미터
#define	IDM_0860000	1510	//	860킬로미터
#define	IDM_0870000	1511	//	870킬로미터
#define	IDM_0880000	1512	//	880킬로미터
#define	IDM_0890000	1513	//	890킬로미터
#define	IDM_0900000	1514	//	900킬로미터
#define	IDM_0910000	1515	//	910킬로미터
#define	IDM_0920000	1516	//	920킬로미터
#define	IDM_0930000	1517	//	930킬로미터
#define	IDM_0940000	1518	//	940킬로미터
#define	IDM_0950000	1519	//	950킬로미터
#define	IDM_0960000	1520	//	960킬로미터
#define	IDM_0970000	1521	//	970킬로미터
#define	IDM_0980000	1522	//	980킬로미터
#define	IDM_0990000	1523	//	990킬로미터
#define	IDM_1000000	1524	//	1000킬로미터
#define	IDM_0000010_AH	1525	//	10미터앞
#define	IDM_0000020_AH	1526	//	20미터앞
#define	IDM_0000030_AH	1527	//	30미터앞
#define	IDM_0000040_AH	1528	//	40미터앞
#define	IDM_0000050_AH	1529	//	50미터앞
#define	IDM_0000060_AH	1530	//	60미터앞
#define	IDM_0000070_AH	1531	//	70미터앞
#define	IDM_0000080_AH	1532	//	80미터앞
#define	IDM_0000090_AH	1533	//	90미터앞
#define	IDM_0000100_AH	1534	//	100미터앞
#define	IDM_0000110_AH	1535	//	110미터앞
#define	IDM_0000120_AH	1536	//	120미터앞
#define	IDM_0000130_AH	1537	//	130미터앞
#define	IDM_0000140_AH	1538	//	140미터앞
#define	IDM_0000150_AH	1539	//	150미터앞
#define	IDM_0000160_AH	1540	//	160미터앞
#define	IDM_0000170_AH	1541	//	170미터앞
#define	IDM_0000180_AH	1542	//	180미터앞
#define	IDM_0000190_AH	1543	//	190미터앞
#define	IDM_0000200_AH	1544	//	200미터앞
#define	IDM_0000210_AH	1545	//	210미터앞
#define	IDM_0000220_AH	1546	//	220미터앞
#define	IDM_0000230_AH	1547	//	230미터앞
#define	IDM_0000240_AH	1548	//	240미터앞
#define	IDM_0000250_AH	1549	//	250미터앞
#define	IDM_0000260_AH	1550	//	260미터앞
#define	IDM_0000270_AH	1551	//	270미터앞
#define	IDM_0000280_AH	1552	//	280미터앞
#define	IDM_0000290_AH	1553	//	290미터앞
#define	IDM_0000300_AH	1554	//	300미터앞
#define	IDM_0000310_AH	1555	//	310미터앞
#define	IDM_0000320_AH	1556	//	320미터앞
#define	IDM_0000330_AH	1557	//	330미터앞
#define	IDM_0000340_AH	1558	//	340미터앞
#define	IDM_0000350_AH	1559	//	350미터앞
#define	IDM_0000360_AH	1560	//	360미터앞
#define	IDM_0000370_AH	1561	//	370미터앞
#define	IDM_0000380_AH	1562	//	380미터앞
#define	IDM_0000390_AH	1563	//	390미터앞
#define	IDM_0000400_AH	1564	//	400미터앞
#define	IDM_0000410_AH	1565	//	410미터앞
#define	IDM_0000420_AH	1566	//	420미터앞
#define	IDM_0000430_AH	1567	//	430미터앞
#define	IDM_0000440_AH	1568	//	440미터앞
#define	IDM_0000450_AH	1569	//	450미터앞
#define	IDM_0000460_AH	1570	//	460미터앞
#define	IDM_0000470_AH	1571	//	470미터앞
#define	IDM_0000480_AH	1572	//	480미터앞
#define	IDM_0000490_AH	1573	//	490미터앞
#define	IDM_0000500_AH	1574	//	500미터앞
#define	IDM_0000510_AH	1575	//	510미터앞
#define	IDM_0000520_AH	1576	//	520미터앞
#define	IDM_0000530_AH	1577	//	530미터앞
#define	IDM_0000540_AH	1578	//	540미터앞
#define	IDM_0000550_AH	1579	//	550미터앞
#define	IDM_0000560_AH	1580	//	560미터앞
#define	IDM_0000570_AH	1581	//	570미터앞
#define	IDM_0000580_AH	1582	//	580미터앞
#define	IDM_0000590_AH	1583	//	590미터앞
#define	IDM_0000600_AH	1584	//	600미터앞
#define	IDM_0000610_AH	1585	//	610미터앞
#define	IDM_0000620_AH	1586	//	620미터앞
#define	IDM_0000630_AH	1587	//	630미터앞
#define	IDM_0000640_AH	1588	//	640미터앞
#define	IDM_0000650_AH	1589	//	650미터앞
#define	IDM_0000660_AH	1590	//	660미터앞
#define	IDM_0000670_AH	1591	//	670미터앞
#define	IDM_0000680_AH	1592	//	680미터앞
#define	IDM_0000690_AH	1593	//	690미터앞
#define	IDM_0000700_AH	1594	//	700미터앞
#define	IDM_0000710_AH	1595	//	710미터앞
#define	IDM_0000720_AH	1596	//	720미터앞
#define	IDM_0000730_AH	1597	//	730미터앞
#define	IDM_0000740_AH	1598	//	740미터앞
#define	IDM_0000750_AH	1599	//	750미터앞
#define	IDM_0000760_AH	1600	//	760미터앞
#define	IDM_0000770_AH	1601	//	770미터앞
#define	IDM_0000780_AH	1602	//	780미터앞
#define	IDM_0000790_AH	1603	//	790미터앞
#define	IDM_0000800_AH	1604	//	800미터앞
#define	IDM_0000810_AH	1605	//	810미터앞
#define	IDM_0000820_AH	1606	//	820미터앞
#define	IDM_0000830_AH	1607	//	830미터앞
#define	IDM_0000840_AH	1608	//	840미터앞
#define	IDM_0000850_AH	1609	//	850미터앞
#define	IDM_0000860_AH	1610	//	860미터앞
#define	IDM_0000870_AH	1611	//	870미터앞
#define	IDM_0000880_AH	1612	//	880미터앞
#define	IDM_0000890_AH	1613	//	890미터앞
#define	IDM_0000900_AH	1614	//	900미터앞
#define	IDM_0000910_AH	1615	//	910미터앞
#define	IDM_0000920_AH	1616	//	920미터앞
#define	IDM_0000930_AH	1617	//	930미터앞
#define	IDM_0000940_AH	1618	//	940미터앞
#define	IDM_0000950_AH	1619	//	950미터앞
#define	IDM_0000960_AH	1620	//	960미터앞
#define	IDM_0000970_AH	1621	//	970미터앞
#define	IDM_0000980_AH	1622	//	980미터앞
#define	IDM_0000990_AH	1623	//	990미터앞
#define	IDM_0001000_AH	1624	//	1킬로미터앞
#define	IDM_0001100_AH	1625	//	1.1킬로미터앞
#define	IDM_0001200_AH	1626	//	1.2킬로미터앞
#define	IDM_0001300_AH	1627	//	1.3킬로미터앞
#define	IDM_0001400_AH	1628	//	1.4킬로미터앞
#define	IDM_0001500_AH	1629	//	1.5킬로미터앞
#define	IDM_0001600_AH	1630	//	1.6킬로미터앞
#define	IDM_0001700_AH	1631	//	1.7킬로미터앞
#define	IDM_0001800_AH	1632	//	1.8킬로미터앞
#define	IDM_0001900_AH	1633	//	1.9킬로미터앞
#define	IDM_0002000_AH	1634	//	2킬로미터앞
#define	IDM_0002100_AH	1635	//	2.1킬로미터앞
#define	IDM_0002200_AH	1636	//	2.2킬로미터앞
#define	IDM_0002300_AH	1637	//	2.3킬로미터앞
#define	IDM_0002400_AH	1638	//	2.4킬로미터앞
#define	IDM_0002500_AH	1639	//	2.5킬로미터앞
#define	IDM_0002600_AH	1640	//	2.6킬로미터앞
#define	IDM_0002700_AH	1641	//	2.7킬로미터앞
#define	IDM_0002800_AH	1642	//	2.8킬로미터앞
#define	IDM_0002900_AH	1643	//	2.9킬로미터앞
#define	IDM_0003000_AH	1644	//	3킬로미터앞
#define	IDM_0003100_AH	1645	//	3.1킬로미터앞
#define	IDM_0003200_AH	1646	//	3.2킬로미터앞
#define	IDM_0003300_AH	1647	//	3.3킬로미터앞
#define	IDM_0003400_AH	1648	//	3.4킬로미터앞
#define	IDM_0003500_AH	1649	//	3.5킬로미터앞
#define	IDM_0003600_AH	1650	//	3.6킬로미터앞
#define	IDM_0003700_AH	1651	//	3.7킬로미터앞
#define	IDM_0003800_AH	1652	//	3.8킬로미터앞
#define	IDM_0003900_AH	1653	//	3.9킬로미터앞
#define	IDM_0004000_AH	1654	//	4킬로미터앞
#define	IDM_0004100_AH	1655	//	4.1킬로미터앞
#define	IDM_0004200_AH	1656	//	4.2킬로미터앞
#define	IDM_0004300_AH	1657	//	4.3킬로미터앞
#define	IDM_0004400_AH	1658	//	4.4킬로미터앞
#define	IDM_0004500_AH	1659	//	4.5킬로미터앞
#define	IDM_0004600_AH	1660	//	4.6킬로미터앞
#define	IDM_0004700_AH	1661	//	4.7킬로미터앞
#define	IDM_0004800_AH	1662	//	4.8킬로미터앞
#define	IDM_0004900_AH	1663	//	4.9킬로미터앞
#define	IDM_0005000_AH	1664	//	5킬로미터앞
#define	IDM_0005100_AH	1665	//	5.1킬로미터앞
#define	IDM_0005200_AH	1666	//	5.2킬로미터앞
#define	IDM_0005300_AH	1667	//	5.3킬로미터앞
#define	IDM_0005400_AH	1668	//	5.4킬로미터앞
#define	IDM_0005500_AH	1669	//	5.5킬로미터앞
#define	IDM_0005600_AH	1670	//	5.6킬로미터앞
#define	IDM_0005700_AH	1671	//	5.7킬로미터앞
#define	IDM_0005800_AH	1672	//	5.8킬로미터앞
#define	IDM_0005900_AH	1673	//	5.9킬로미터앞
#define	IDM_0006000_AH	1674	//	6킬로미터앞
#define	IDM_0006100_AH	1675	//	6.1킬로미터앞
#define	IDM_0006200_AH	1676	//	6.2킬로미터앞
#define	IDM_0006300_AH	1677	//	6.3킬로미터앞
#define	IDM_0006400_AH	1678	//	6.4킬로미터앞
#define	IDM_0006500_AH	1679	//	6.5킬로미터앞
#define	IDM_0006600_AH	1680	//	6.6킬로미터앞
#define	IDM_0006700_AH	1681	//	6.7킬로미터앞
#define	IDM_0006800_AH	1682	//	6.8킬로미터앞
#define	IDM_0006900_AH	1683	//	6.9킬로미터앞
#define	IDM_0007000_AH	1684	//	7킬로미터앞
#define	IDM_0007100_AH	1685	//	7.1킬로미터앞
#define	IDM_0007200_AH	1686	//	7.2킬로미터앞
#define	IDM_0007300_AH	1687	//	7.3킬로미터앞
#define	IDM_0007400_AH	1688	//	7.4킬로미터앞
#define	IDM_0007500_AH	1689	//	7.5킬로미터앞
#define	IDM_0007600_AH	1690	//	7.6킬로미터앞
#define	IDM_0007700_AH	1691	//	7.7킬로미터앞
#define	IDM_0007800_AH	1692	//	7.8킬로미터앞
#define	IDM_0007900_AH	1693	//	7.9킬로미터앞
#define	IDM_0008000_AH	1694	//	8킬로미터앞
#define	IDM_0008100_AH	1695	//	8.1킬로미터앞
#define	IDM_0008200_AH	1696	//	8.2킬로미터앞
#define	IDM_0008300_AH	1697	//	8.3킬로미터앞
#define	IDM_0008400_AH	1698	//	8.4킬로미터앞
#define	IDM_0008500_AH	1699	//	8.5킬로미터앞
#define	IDM_0008600_AH	1700	//	8.6킬로미터앞
#define	IDM_0008700_AH	1701	//	8.7킬로미터앞
#define	IDM_0008800_AH	1702	//	8.8킬로미터앞
#define	IDM_0008900_AH	1703	//	8.9킬로미터앞
#define	IDM_0009000_AH	1704	//	9킬로미터앞
#define	IDM_0009100_AH	1705	//	9.1킬로미터앞
#define	IDM_0009200_AH	1706	//	9.2킬로미터앞
#define	IDM_0009300_AH	1707	//	9.3킬로미터앞
#define	IDM_0009400_AH	1708	//	9.4킬로미터앞
#define	IDM_0009500_AH	1709	//	9.5킬로미터앞
#define	IDM_0009600_AH	1710	//	9.6킬로미터앞
#define	IDM_0009700_AH	1711	//	9.7킬로미터앞
#define	IDM_0009800_AH	1712	//	9.8킬로미터앞
#define	IDM_0009900_AH	1713	//	9.9킬로미터앞
#define	IDM_0010000_AH	1714	//	10킬로미터앞
#define	IDM_0010100_AH	1715	//	10.1킬로미터앞
#define	IDM_0010200_AH	1716	//	10.2킬로미터앞
#define	IDM_0010300_AH	1717	//	10.3킬로미터앞
#define	IDM_0010400_AH	1718	//	10.4킬로미터앞
#define	IDM_0010500_AH	1719	//	10.5킬로미터앞
#define	IDM_0010600_AH	1720	//	10.6킬로미터앞
#define	IDM_0010700_AH	1721	//	10.7킬로미터앞
#define	IDM_0010800_AH	1722	//	10.8킬로미터앞
#define	IDM_0010900_AH	1723	//	10.9킬로미터앞
#define	IDM_0011000_AH	1724	//	11킬로미터앞
#define	IDM_0011100_AH	1725	//	11.1킬로미터앞
#define	IDM_0011200_AH	1726	//	11.2킬로미터앞
#define	IDM_0011300_AH	1727	//	11.3킬로미터앞
#define	IDM_0011400_AH	1728	//	11.4킬로미터앞
#define	IDM_0011500_AH	1729	//	11.5킬로미터앞
#define	IDM_0011600_AH	1730	//	11.6킬로미터앞
#define	IDM_0011700_AH	1731	//	11.7킬로미터앞
#define	IDM_0011800_AH	1732	//	11.8킬로미터앞
#define	IDM_0011900_AH	1733	//	11.9킬로미터앞
#define	IDM_0012000_AH	1734	//	12킬로미터앞
#define	IDM_0012100_AH	1735	//	12.1킬로미터앞
#define	IDM_0012200_AH	1736	//	12.2킬로미터앞
#define	IDM_0012300_AH	1737	//	12.3킬로미터앞
#define	IDM_0012400_AH	1738	//	12.4킬로미터앞
#define	IDM_0012500_AH	1739	//	12.5킬로미터앞
#define	IDM_0012600_AH	1740	//	12.6킬로미터앞
#define	IDM_0012700_AH	1741	//	12.7킬로미터앞
#define	IDM_0012800_AH	1742	//	12.8킬로미터앞
#define	IDM_0012900_AH	1743	//	12.9킬로미터앞
#define	IDM_0013000_AH	1744	//	13킬로미터앞
#define	IDM_0013100_AH	1745	//	13.1킬로미터앞
#define	IDM_0013200_AH	1746	//	13.2킬로미터앞
#define	IDM_0013300_AH	1747	//	13.3킬로미터앞
#define	IDM_0013400_AH	1748	//	13.4킬로미터앞
#define	IDM_0013500_AH	1749	//	13.5킬로미터앞
#define	IDM_0013600_AH	1750	//	13.6킬로미터앞
#define	IDM_0013700_AH	1751	//	13.7킬로미터앞
#define	IDM_0013800_AH	1752	//	13.8킬로미터앞
#define	IDM_0013900_AH	1753	//	13.9킬로미터앞
#define	IDM_0014000_AH	1754	//	14킬로미터앞
#define	IDM_0014100_AH	1755	//	14.1킬로미터앞
#define	IDM_0014200_AH	1756	//	14.2킬로미터앞
#define	IDM_0014300_AH	1757	//	14.3킬로미터앞
#define	IDM_0014400_AH	1758	//	14.4킬로미터앞
#define	IDM_0014500_AH	1759	//	14.5킬로미터앞
#define	IDM_0014600_AH	1760	//	14.6킬로미터앞
#define	IDM_0014700_AH	1761	//	14.7킬로미터앞
#define	IDM_0014800_AH	1762	//	14.8킬로미터앞
#define	IDM_0014900_AH	1763	//	14.9킬로미터앞
#define	IDM_0015000_AH	1764	//	15킬로미터앞
#define	IDM_0015100_AH	1765	//	15.1킬로미터앞
#define	IDM_0015200_AH	1766	//	15.2킬로미터앞
#define	IDM_0015300_AH	1767	//	15.3킬로미터앞
#define	IDM_0015400_AH	1768	//	15.4킬로미터앞
#define	IDM_0015500_AH	1769	//	15.5킬로미터앞
#define	IDM_0015600_AH	1770	//	15.6킬로미터앞
#define	IDM_0015700_AH	1771	//	15.7킬로미터앞
#define	IDM_0015800_AH	1772	//	15.8킬로미터앞
#define	IDM_0015900_AH	1773	//	15.9킬로미터앞
#define	IDM_0016000_AH	1774	//	16킬로미터앞
#define	IDM_0016100_AH	1775	//	16.1킬로미터앞
#define	IDM_0016200_AH	1776	//	16.2킬로미터앞
#define	IDM_0016300_AH	1777	//	16.3킬로미터앞
#define	IDM_0016400_AH	1778	//	16.4킬로미터앞
#define	IDM_0016500_AH	1779	//	16.5킬로미터앞
#define	IDM_0016600_AH	1780	//	16.6킬로미터앞
#define	IDM_0016700_AH	1781	//	16.7킬로미터앞
#define	IDM_0016800_AH	1782	//	16.8킬로미터앞
#define	IDM_0016900_AH	1783	//	16.9킬로미터앞
#define	IDM_0017000_AH	1784	//	17킬로미터앞
#define	IDM_0017100_AH	1785	//	17.1킬로미터앞
#define	IDM_0017200_AH	1786	//	17.2킬로미터앞
#define	IDM_0017300_AH	1787	//	17.3킬로미터앞
#define	IDM_0017400_AH	1788	//	17.4킬로미터앞
#define	IDM_0017500_AH	1789	//	17.5킬로미터앞
#define	IDM_0017600_AH	1790	//	17.6킬로미터앞
#define	IDM_0017700_AH	1791	//	17.7킬로미터앞
#define	IDM_0017800_AH	1792	//	17.8킬로미터앞
#define	IDM_0017900_AH	1793	//	17.9킬로미터앞
#define	IDM_0018000_AH	1794	//	18킬로미터앞
#define	IDM_0018100_AH	1795	//	18.1킬로미터앞
#define	IDM_0018200_AH	1796	//	18.2킬로미터앞
#define	IDM_0018300_AH	1797	//	18.3킬로미터앞
#define	IDM_0018400_AH	1798	//	18.4킬로미터앞
#define	IDM_0018500_AH	1799	//	18.5킬로미터앞
#define	IDM_0018600_AH	1800	//	18.6킬로미터앞
#define	IDM_0018700_AH	1801	//	18.7킬로미터앞
#define	IDM_0018800_AH	1802	//	18.8킬로미터앞
#define	IDM_0018900_AH	1803	//	18.9킬로미터앞
#define	IDM_0019000_AH	1804	//	19킬로미터앞
#define	IDM_0019100_AH	1805	//	19.1킬로미터앞
#define	IDM_0019200_AH	1806	//	19.2킬로미터앞
#define	IDM_0019300_AH	1807	//	19.3킬로미터앞
#define	IDM_0019400_AH	1808	//	19.4킬로미터앞
#define	IDM_0019500_AH	1809	//	19.5킬로미터앞
#define	IDM_0019600_AH	1810	//	19.6킬로미터앞
#define	IDM_0019700_AH	1811	//	19.7킬로미터앞
#define	IDM_0019800_AH	1812	//	19.8킬로미터앞
#define	IDM_0019900_AH	1813	//	19.9킬로미터앞
#define	IDM_0020000_AH	1814	//	20킬로미터앞
#define	IDM_0020100_AH	1815	//	20.1킬로미터앞
#define	IDM_0020200_AH	1816	//	20.2킬로미터앞
#define	IDM_0020300_AH	1817	//	20.3킬로미터앞
#define	IDM_0020400_AH	1818	//	20.4킬로미터앞
#define	IDM_0020500_AH	1819	//	20.5킬로미터앞
#define	IDM_0020600_AH	1820	//	20.6킬로미터앞
#define	IDM_0020700_AH	1821	//	20.7킬로미터앞
#define	IDM_0020800_AH	1822	//	20.8킬로미터앞
#define	IDM_0020900_AH	1823	//	20.9킬로미터앞
#define	IDM_0021000_AH	1824	//	21킬로미터앞
#define	IDM_0021100_AH	1825	//	21.1킬로미터앞
#define	IDM_0021200_AH	1826	//	21.2킬로미터앞
#define	IDM_0021300_AH	1827	//	21.3킬로미터앞
#define	IDM_0021400_AH	1828	//	21.4킬로미터앞
#define	IDM_0021500_AH	1829	//	21.5킬로미터앞
#define	IDM_0021600_AH	1830	//	21.6킬로미터앞
#define	IDM_0021700_AH	1831	//	21.7킬로미터앞
#define	IDM_0021800_AH	1832	//	21.8킬로미터앞
#define	IDM_0021900_AH	1833	//	21.9킬로미터앞
#define	IDM_0022000_AH	1834	//	22킬로미터앞
#define	IDM_0022100_AH	1835	//	22.1킬로미터앞
#define	IDM_0022200_AH	1836	//	22.2킬로미터앞
#define	IDM_0022300_AH	1837	//	22.3킬로미터앞
#define	IDM_0022400_AH	1838	//	22.4킬로미터앞
#define	IDM_0022500_AH	1839	//	22.5킬로미터앞
#define	IDM_0022600_AH	1840	//	22.6킬로미터앞
#define	IDM_0022700_AH	1841	//	22.7킬로미터앞
#define	IDM_0022800_AH	1842	//	22.8킬로미터앞
#define	IDM_0022900_AH	1843	//	22.9킬로미터앞
#define	IDM_0023000_AH	1844	//	23킬로미터앞
#define	IDM_0023100_AH	1845	//	23.1킬로미터앞
#define	IDM_0023200_AH	1846	//	23.2킬로미터앞
#define	IDM_0023300_AH	1847	//	23.3킬로미터앞
#define	IDM_0023400_AH	1848	//	23.4킬로미터앞
#define	IDM_0023500_AH	1849	//	23.5킬로미터앞
#define	IDM_0023600_AH	1850	//	23.6킬로미터앞
#define	IDM_0023700_AH	1851	//	23.7킬로미터앞
#define	IDM_0023800_AH	1852	//	23.8킬로미터앞
#define	IDM_0023900_AH	1853	//	23.9킬로미터앞
#define	IDM_0024000_AH	1854	//	24킬로미터앞
#define	IDM_0024100_AH	1855	//	24.1킬로미터앞
#define	IDM_0024200_AH	1856	//	24.2킬로미터앞
#define	IDM_0024300_AH	1857	//	24.3킬로미터앞
#define	IDM_0024400_AH	1858	//	24.4킬로미터앞
#define	IDM_0024500_AH	1859	//	24.5킬로미터앞
#define	IDM_0024600_AH	1860	//	24.6킬로미터앞
#define	IDM_0024700_AH	1861	//	24.7킬로미터앞
#define	IDM_0024800_AH	1862	//	24.8킬로미터앞
#define	IDM_0024900_AH	1863	//	24.9킬로미터앞
#define	IDM_0025000_AH	1864	//	25킬로미터앞
#define	IDM_0025100_AH	1865	//	25.1킬로미터앞
#define	IDM_0025200_AH	1866	//	25.2킬로미터앞
#define	IDM_0025300_AH	1867	//	25.3킬로미터앞
#define	IDM_0025400_AH	1868	//	25.4킬로미터앞
#define	IDM_0025500_AH	1869	//	25.5킬로미터앞
#define	IDM_0025600_AH	1870	//	25.6킬로미터앞
#define	IDM_0025700_AH	1871	//	25.7킬로미터앞
#define	IDM_0025800_AH	1872	//	25.8킬로미터앞
#define	IDM_0025900_AH	1873	//	25.9킬로미터앞
#define	IDM_0026000_AH	1874	//	26킬로미터앞
#define	IDM_0026100_AH	1875	//	26.1킬로미터앞
#define	IDM_0026200_AH	1876	//	26.2킬로미터앞
#define	IDM_0026300_AH	1877	//	26.3킬로미터앞
#define	IDM_0026400_AH	1878	//	26.4킬로미터앞
#define	IDM_0026500_AH	1879	//	26.5킬로미터앞
#define	IDM_0026600_AH	1880	//	26.6킬로미터앞
#define	IDM_0026700_AH	1881	//	26.7킬로미터앞
#define	IDM_0026800_AH	1882	//	26.8킬로미터앞
#define	IDM_0026900_AH	1883	//	26.9킬로미터앞
#define	IDM_0027000_AH	1884	//	27킬로미터앞
#define	IDM_0027100_AH	1885	//	27.1킬로미터앞
#define	IDM_0027200_AH	1886	//	27.2킬로미터앞
#define	IDM_0027300_AH	1887	//	27.3킬로미터앞
#define	IDM_0027400_AH	1888	//	27.4킬로미터앞
#define	IDM_0027500_AH	1889	//	27.5킬로미터앞
#define	IDM_0027600_AH	1890	//	27.6킬로미터앞
#define	IDM_0027700_AH	1891	//	27.7킬로미터앞
#define	IDM_0027800_AH	1892	//	27.8킬로미터앞
#define	IDM_0027900_AH	1893	//	27.9킬로미터앞
#define	IDM_0028000_AH	1894	//	28킬로미터앞
#define	IDM_0028100_AH	1895	//	28.1킬로미터앞
#define	IDM_0028200_AH	1896	//	28.2킬로미터앞
#define	IDM_0028300_AH	1897	//	28.3킬로미터앞
#define	IDM_0028400_AH	1898	//	28.4킬로미터앞
#define	IDM_0028500_AH	1899	//	28.5킬로미터앞
#define	IDM_0028600_AH	1900	//	28.6킬로미터앞
#define	IDM_0028700_AH	1901	//	28.7킬로미터앞
#define	IDM_0028800_AH	1902	//	28.8킬로미터앞
#define	IDM_0028900_AH	1903	//	28.9킬로미터앞
#define	IDM_0029000_AH	1904	//	29킬로미터앞
#define	IDM_0029100_AH	1905	//	29.1킬로미터앞
#define	IDM_0029200_AH	1906	//	29.2킬로미터앞
#define	IDM_0029300_AH	1907	//	29.3킬로미터앞
#define	IDM_0029400_AH	1908	//	29.4킬로미터앞
#define	IDM_0029500_AH	1909	//	29.5킬로미터앞
#define	IDM_0029600_AH	1910	//	29.6킬로미터앞
#define	IDM_0029700_AH	1911	//	29.7킬로미터앞
#define	IDM_0029800_AH	1912	//	29.8킬로미터앞
#define	IDM_0029900_AH	1913	//	29.9킬로미터앞
#define	IDM_0030000_AH	1914	//	30킬로미터앞
#define	IDM_0030100_AH	1915	//	30.1킬로미터앞
#define	IDM_0030200_AH	1916	//	30.2킬로미터앞
#define	IDM_0030300_AH	1917	//	30.3킬로미터앞
#define	IDM_0030400_AH	1918	//	30.4킬로미터앞
#define	IDM_0030500_AH	1919	//	30.5킬로미터앞
#define	IDM_0030600_AH	1920	//	30.6킬로미터앞
#define	IDM_0030700_AH	1921	//	30.7킬로미터앞
#define	IDM_0030800_AH	1922	//	30.8킬로미터앞
#define	IDM_0030900_AH	1923	//	30.9킬로미터앞
#define	IDM_0031000_AH	1924	//	31킬로미터앞
#define	IDM_0031100_AH	1925	//	31.1킬로미터앞
#define	IDM_0031200_AH	1926	//	31.2킬로미터앞
#define	IDM_0031300_AH	1927	//	31.3킬로미터앞
#define	IDM_0031400_AH	1928	//	31.4킬로미터앞
#define	IDM_0031500_AH	1929	//	31.5킬로미터앞
#define	IDM_0031600_AH	1930	//	31.6킬로미터앞
#define	IDM_0031700_AH	1931	//	31.7킬로미터앞
#define	IDM_0031800_AH	1932	//	31.8킬로미터앞
#define	IDM_0031900_AH	1933	//	31.9킬로미터앞
#define	IDM_0032000_AH	1934	//	32킬로미터앞
#define	IDM_0032100_AH	1935	//	32.1킬로미터앞
#define	IDM_0032200_AH	1936	//	32.2킬로미터앞
#define	IDM_0032300_AH	1937	//	32.3킬로미터앞
#define	IDM_0032400_AH	1938	//	32.4킬로미터앞
#define	IDM_0032500_AH	1939	//	32.5킬로미터앞
#define	IDM_0032600_AH	1940	//	32.6킬로미터앞
#define	IDM_0032700_AH	1941	//	32.7킬로미터앞
#define	IDM_0032800_AH	1942	//	32.8킬로미터앞
#define	IDM_0032900_AH	1943	//	32.9킬로미터앞
#define	IDM_0033000_AH	1944	//	33킬로미터앞
#define	IDM_0033100_AH	1945	//	33.1킬로미터앞
#define	IDM_0033200_AH	1946	//	33.2킬로미터앞
#define	IDM_0033300_AH	1947	//	33.3킬로미터앞
#define	IDM_0033400_AH	1948	//	33.4킬로미터앞
#define	IDM_0033500_AH	1949	//	33.5킬로미터앞
#define	IDM_0033600_AH	1950	//	33.6킬로미터앞
#define	IDM_0033700_AH	1951	//	33.7킬로미터앞
#define	IDM_0033800_AH	1952	//	33.8킬로미터앞
#define	IDM_0033900_AH	1953	//	33.9킬로미터앞
#define	IDM_0034000_AH	1954	//	34킬로미터앞
#define	IDM_0034100_AH	1955	//	34.1킬로미터앞
#define	IDM_0034200_AH	1956	//	34.2킬로미터앞
#define	IDM_0034300_AH	1957	//	34.3킬로미터앞
#define	IDM_0034400_AH	1958	//	34.4킬로미터앞
#define	IDM_0034500_AH	1959	//	34.5킬로미터앞
#define	IDM_0034600_AH	1960	//	34.6킬로미터앞
#define	IDM_0034700_AH	1961	//	34.7킬로미터앞
#define	IDM_0034800_AH	1962	//	34.8킬로미터앞
#define	IDM_0034900_AH	1963	//	34.9킬로미터앞
#define	IDM_0035000_AH	1964	//	35킬로미터앞
#define	IDM_0035100_AH	1965	//	35.1킬로미터앞
#define	IDM_0035200_AH	1966	//	35.2킬로미터앞
#define	IDM_0035300_AH	1967	//	35.3킬로미터앞
#define	IDM_0035400_AH	1968	//	35.4킬로미터앞
#define	IDM_0035500_AH	1969	//	35.5킬로미터앞
#define	IDM_0035600_AH	1970	//	35.6킬로미터앞
#define	IDM_0035700_AH	1971	//	35.7킬로미터앞
#define	IDM_0035800_AH	1972	//	35.8킬로미터앞
#define	IDM_0035900_AH	1973	//	35.9킬로미터앞
#define	IDM_0036000_AH	1974	//	36킬로미터앞
#define	IDM_0036100_AH	1975	//	36.1킬로미터앞
#define	IDM_0036200_AH	1976	//	36.2킬로미터앞
#define	IDM_0036300_AH	1977	//	36.3킬로미터앞
#define	IDM_0036400_AH	1978	//	36.4킬로미터앞
#define	IDM_0036500_AH	1979	//	36.5킬로미터앞
#define	IDM_0036600_AH	1980	//	36.6킬로미터앞
#define	IDM_0036700_AH	1981	//	36.7킬로미터앞
#define	IDM_0036800_AH	1982	//	36.8킬로미터앞
#define	IDM_0036900_AH	1983	//	36.9킬로미터앞
#define	IDM_0037000_AH	1984	//	37킬로미터앞
#define	IDM_0037100_AH	1985	//	37.1킬로미터앞
#define	IDM_0037200_AH	1986	//	37.2킬로미터앞
#define	IDM_0037300_AH	1987	//	37.3킬로미터앞
#define	IDM_0037400_AH	1988	//	37.4킬로미터앞
#define	IDM_0037500_AH	1989	//	37.5킬로미터앞
#define	IDM_0037600_AH	1990	//	37.6킬로미터앞
#define	IDM_0037700_AH	1991	//	37.7킬로미터앞
#define	IDM_0037800_AH	1992	//	37.8킬로미터앞
#define	IDM_0037900_AH	1993	//	37.9킬로미터앞
#define	IDM_0038000_AH	1994	//	38킬로미터앞
#define	IDM_0038100_AH	1995	//	38.1킬로미터앞
#define	IDM_0038200_AH	1996	//	38.2킬로미터앞
#define	IDM_0038300_AH	1997	//	38.3킬로미터앞
#define	IDM_0038400_AH	1998	//	38.4킬로미터앞
#define	IDM_0038500_AH	1999	//	38.5킬로미터앞
#define	IDM_0038600_AH	2000	//	38.6킬로미터앞
#define	IDM_0038700_AH	2001	//	38.7킬로미터앞
#define	IDM_0038800_AH	2002	//	38.8킬로미터앞
#define	IDM_0038900_AH	2003	//	38.9킬로미터앞
#define	IDM_0039000_AH	2004	//	39킬로미터앞
#define	IDM_0039100_AH	2005	//	39.1킬로미터앞
#define	IDM_0039200_AH	2006	//	39.2킬로미터앞
#define	IDM_0039300_AH	2007	//	39.3킬로미터앞
#define	IDM_0039400_AH	2008	//	39.4킬로미터앞
#define	IDM_0039500_AH	2009	//	39.5킬로미터앞
#define	IDM_0039600_AH	2010	//	39.6킬로미터앞
#define	IDM_0039700_AH	2011	//	39.7킬로미터앞
#define	IDM_0039800_AH	2012	//	39.8킬로미터앞
#define	IDM_0039900_AH	2013	//	39.9킬로미터앞
#define	IDM_0040000_AH	2014	//	40킬로미터앞
#define	IDM_0040100_AH	2015	//	40.1킬로미터앞
#define	IDM_0040200_AH	2016	//	40.2킬로미터앞
#define	IDM_0040300_AH	2017	//	40.3킬로미터앞
#define	IDM_0040400_AH	2018	//	40.4킬로미터앞
#define	IDM_0040500_AH	2019	//	40.5킬로미터앞
#define	IDM_0040600_AH	2020	//	40.6킬로미터앞
#define	IDM_0040700_AH	2021	//	40.7킬로미터앞
#define	IDM_0040800_AH	2022	//	40.8킬로미터앞
#define	IDM_0040900_AH	2023	//	40.9킬로미터앞
#define	IDM_0041000_AH	2024	//	41킬로미터앞
#define	IDM_0041100_AH	2025	//	41.1킬로미터앞
#define	IDM_0041200_AH	2026	//	41.2킬로미터앞
#define	IDM_0041300_AH	2027	//	41.3킬로미터앞
#define	IDM_0041400_AH	2028	//	41.4킬로미터앞
#define	IDM_0041500_AH	2029	//	41.5킬로미터앞
#define	IDM_0041600_AH	2030	//	41.6킬로미터앞
#define	IDM_0041700_AH	2031	//	41.7킬로미터앞
#define	IDM_0041800_AH	2032	//	41.8킬로미터앞
#define	IDM_0041900_AH	2033	//	41.9킬로미터앞
#define	IDM_0042000_AH	2034	//	42킬로미터앞
#define	IDM_0042100_AH	2035	//	42.1킬로미터앞
#define	IDM_0042200_AH	2036	//	42.2킬로미터앞
#define	IDM_0042300_AH	2037	//	42.3킬로미터앞
#define	IDM_0042400_AH	2038	//	42.4킬로미터앞
#define	IDM_0042500_AH	2039	//	42.5킬로미터앞
#define	IDM_0042600_AH	2040	//	42.6킬로미터앞
#define	IDM_0042700_AH	2041	//	42.7킬로미터앞
#define	IDM_0042800_AH	2042	//	42.8킬로미터앞
#define	IDM_0042900_AH	2043	//	42.9킬로미터앞
#define	IDM_0043000_AH	2044	//	43킬로미터앞
#define	IDM_0043100_AH	2045	//	43.1킬로미터앞
#define	IDM_0043200_AH	2046	//	43.2킬로미터앞
#define	IDM_0043300_AH	2047	//	43.3킬로미터앞
#define	IDM_0043400_AH	2048	//	43.4킬로미터앞
#define	IDM_0043500_AH	2049	//	43.5킬로미터앞
#define	IDM_0043600_AH	2050	//	43.6킬로미터앞
#define	IDM_0043700_AH	2051	//	43.7킬로미터앞
#define	IDM_0043800_AH	2052	//	43.8킬로미터앞
#define	IDM_0043900_AH	2053	//	43.9킬로미터앞
#define	IDM_0044000_AH	2054	//	44킬로미터앞
#define	IDM_0044100_AH	2055	//	44.1킬로미터앞
#define	IDM_0044200_AH	2056	//	44.2킬로미터앞
#define	IDM_0044300_AH	2057	//	44.3킬로미터앞
#define	IDM_0044400_AH	2058	//	44.4킬로미터앞
#define	IDM_0044500_AH	2059	//	44.5킬로미터앞
#define	IDM_0044600_AH	2060	//	44.6킬로미터앞
#define	IDM_0044700_AH	2061	//	44.7킬로미터앞
#define	IDM_0044800_AH	2062	//	44.8킬로미터앞
#define	IDM_0044900_AH	2063	//	44.9킬로미터앞
#define	IDM_0045000_AH	2064	//	45킬로미터앞
#define	IDM_0045100_AH	2065	//	45.1킬로미터앞
#define	IDM_0045200_AH	2066	//	45.2킬로미터앞
#define	IDM_0045300_AH	2067	//	45.3킬로미터앞
#define	IDM_0045400_AH	2068	//	45.4킬로미터앞
#define	IDM_0045500_AH	2069	//	45.5킬로미터앞
#define	IDM_0045600_AH	2070	//	45.6킬로미터앞
#define	IDM_0045700_AH	2071	//	45.7킬로미터앞
#define	IDM_0045800_AH	2072	//	45.8킬로미터앞
#define	IDM_0045900_AH	2073	//	45.9킬로미터앞
#define	IDM_0046000_AH	2074	//	46킬로미터앞
#define	IDM_0046100_AH	2075	//	46.1킬로미터앞
#define	IDM_0046200_AH	2076	//	46.2킬로미터앞
#define	IDM_0046300_AH	2077	//	46.3킬로미터앞
#define	IDM_0046400_AH	2078	//	46.4킬로미터앞
#define	IDM_0046500_AH	2079	//	46.5킬로미터앞
#define	IDM_0046600_AH	2080	//	46.6킬로미터앞
#define	IDM_0046700_AH	2081	//	46.7킬로미터앞
#define	IDM_0046800_AH	2082	//	46.8킬로미터앞
#define	IDM_0046900_AH	2083	//	46.9킬로미터앞
#define	IDM_0047000_AH	2084	//	47킬로미터앞
#define	IDM_0047100_AH	2085	//	47.1킬로미터앞
#define	IDM_0047200_AH	2086	//	47.2킬로미터앞
#define	IDM_0047300_AH	2087	//	47.3킬로미터앞
#define	IDM_0047400_AH	2088	//	47.4킬로미터앞
#define	IDM_0047500_AH	2089	//	47.5킬로미터앞
#define	IDM_0047600_AH	2090	//	47.6킬로미터앞
#define	IDM_0047700_AH	2091	//	47.7킬로미터앞
#define	IDM_0047800_AH	2092	//	47.8킬로미터앞
#define	IDM_0047900_AH	2093	//	47.9킬로미터앞
#define	IDM_0048000_AH	2094	//	48킬로미터앞
#define	IDM_0048100_AH	2095	//	48.1킬로미터앞
#define	IDM_0048200_AH	2096	//	48.2킬로미터앞
#define	IDM_0048300_AH	2097	//	48.3킬로미터앞
#define	IDM_0048400_AH	2098	//	48.4킬로미터앞
#define	IDM_0048500_AH	2099	//	48.5킬로미터앞
#define	IDM_0048600_AH	2100	//	48.6킬로미터앞
#define	IDM_0048700_AH	2101	//	48.7킬로미터앞
#define	IDM_0048800_AH	2102	//	48.8킬로미터앞
#define	IDM_0048900_AH	2103	//	48.9킬로미터앞
#define	IDM_0049000_AH	2104	//	49킬로미터앞
#define	IDM_0049100_AH	2105	//	49.1킬로미터앞
#define	IDM_0049200_AH	2106	//	49.2킬로미터앞
#define	IDM_0049300_AH	2107	//	49.3킬로미터앞
#define	IDM_0049400_AH	2108	//	49.4킬로미터앞
#define	IDM_0049500_AH	2109	//	49.5킬로미터앞
#define	IDM_0049600_AH	2110	//	49.6킬로미터앞
#define	IDM_0049700_AH	2111	//	49.7킬로미터앞
#define	IDM_0049800_AH	2112	//	49.8킬로미터앞
#define	IDM_0049900_AH	2113	//	49.9킬로미터앞
#define	IDM_0050000_AH	2114	//	50킬로미터앞
#define	IDM_0050100_AH	2115	//	50.1킬로미터앞
#define	IDM_0050200_AH	2116	//	50.2킬로미터앞
#define	IDM_0050300_AH	2117	//	50.3킬로미터앞
#define	IDM_0050400_AH	2118	//	50.4킬로미터앞
#define	IDM_0050500_AH	2119	//	50.5킬로미터앞
#define	IDM_0050600_AH	2120	//	50.6킬로미터앞
#define	IDM_0050700_AH	2121	//	50.7킬로미터앞
#define	IDM_0050800_AH	2122	//	50.8킬로미터앞
#define	IDM_0050900_AH	2123	//	50.9킬로미터앞
#define	IDM_0051000_AH	2124	//	51킬로미터앞
#define	IDM_0051100_AH	2125	//	51.1킬로미터앞
#define	IDM_0051200_AH	2126	//	51.2킬로미터앞
#define	IDM_0051300_AH	2127	//	51.3킬로미터앞
#define	IDM_0051400_AH	2128	//	51.4킬로미터앞
#define	IDM_0051500_AH	2129	//	51.5킬로미터앞
#define	IDM_0051600_AH	2130	//	51.6킬로미터앞
#define	IDM_0051700_AH	2131	//	51.7킬로미터앞
#define	IDM_0051800_AH	2132	//	51.8킬로미터앞
#define	IDM_0051900_AH	2133	//	51.9킬로미터앞
#define	IDM_0052000_AH	2134	//	52킬로미터앞
#define	IDM_0052100_AH	2135	//	52.1킬로미터앞
#define	IDM_0052200_AH	2136	//	52.2킬로미터앞
#define	IDM_0052300_AH	2137	//	52.3킬로미터앞
#define	IDM_0052400_AH	2138	//	52.4킬로미터앞
#define	IDM_0052500_AH	2139	//	52.5킬로미터앞
#define	IDM_0052600_AH	2140	//	52.6킬로미터앞
#define	IDM_0052700_AH	2141	//	52.7킬로미터앞
#define	IDM_0052800_AH	2142	//	52.8킬로미터앞
#define	IDM_0052900_AH	2143	//	52.9킬로미터앞
#define	IDM_0053000_AH	2144	//	53킬로미터앞
#define	IDM_0053100_AH	2145	//	53.1킬로미터앞
#define	IDM_0053200_AH	2146	//	53.2킬로미터앞
#define	IDM_0053300_AH	2147	//	53.3킬로미터앞
#define	IDM_0053400_AH	2148	//	53.4킬로미터앞
#define	IDM_0053500_AH	2149	//	53.5킬로미터앞
#define	IDM_0053600_AH	2150	//	53.6킬로미터앞
#define	IDM_0053700_AH	2151	//	53.7킬로미터앞
#define	IDM_0053800_AH	2152	//	53.8킬로미터앞
#define	IDM_0053900_AH	2153	//	53.9킬로미터앞
#define	IDM_0054000_AH	2154	//	54킬로미터앞
#define	IDM_0054100_AH	2155	//	54.1킬로미터앞
#define	IDM_0054200_AH	2156	//	54.2킬로미터앞
#define	IDM_0054300_AH	2157	//	54.3킬로미터앞
#define	IDM_0054400_AH	2158	//	54.4킬로미터앞
#define	IDM_0054500_AH	2159	//	54.5킬로미터앞
#define	IDM_0054600_AH	2160	//	54.6킬로미터앞
#define	IDM_0054700_AH	2161	//	54.7킬로미터앞
#define	IDM_0054800_AH	2162	//	54.8킬로미터앞
#define	IDM_0054900_AH	2163	//	54.9킬로미터앞
#define	IDM_0055000_AH	2164	//	55킬로미터앞
#define	IDM_0055100_AH	2165	//	55.1킬로미터앞
#define	IDM_0055200_AH	2166	//	55.2킬로미터앞
#define	IDM_0055300_AH	2167	//	55.3킬로미터앞
#define	IDM_0055400_AH	2168	//	55.4킬로미터앞
#define	IDM_0055500_AH	2169	//	55.5킬로미터앞
#define	IDM_0055600_AH	2170	//	55.6킬로미터앞
#define	IDM_0055700_AH	2171	//	55.7킬로미터앞
#define	IDM_0055800_AH	2172	//	55.8킬로미터앞
#define	IDM_0055900_AH	2173	//	55.9킬로미터앞
#define	IDM_0056000_AH	2174	//	56킬로미터앞
#define	IDM_0056100_AH	2175	//	56.1킬로미터앞
#define	IDM_0056200_AH	2176	//	56.2킬로미터앞
#define	IDM_0056300_AH	2177	//	56.3킬로미터앞
#define	IDM_0056400_AH	2178	//	56.4킬로미터앞
#define	IDM_0056500_AH	2179	//	56.5킬로미터앞
#define	IDM_0056600_AH	2180	//	56.6킬로미터앞
#define	IDM_0056700_AH	2181	//	56.7킬로미터앞
#define	IDM_0056800_AH	2182	//	56.8킬로미터앞
#define	IDM_0056900_AH	2183	//	56.9킬로미터앞
#define	IDM_0057000_AH	2184	//	57킬로미터앞
#define	IDM_0057100_AH	2185	//	57.1킬로미터앞
#define	IDM_0057200_AH	2186	//	57.2킬로미터앞
#define	IDM_0057300_AH	2187	//	57.3킬로미터앞
#define	IDM_0057400_AH	2188	//	57.4킬로미터앞
#define	IDM_0057500_AH	2189	//	57.5킬로미터앞
#define	IDM_0057600_AH	2190	//	57.6킬로미터앞
#define	IDM_0057700_AH	2191	//	57.7킬로미터앞
#define	IDM_0057800_AH	2192	//	57.8킬로미터앞
#define	IDM_0057900_AH	2193	//	57.9킬로미터앞
#define	IDM_0058000_AH	2194	//	58킬로미터앞
#define	IDM_0058100_AH	2195	//	58.1킬로미터앞
#define	IDM_0058200_AH	2196	//	58.2킬로미터앞
#define	IDM_0058300_AH	2197	//	58.3킬로미터앞
#define	IDM_0058400_AH	2198	//	58.4킬로미터앞
#define	IDM_0058500_AH	2199	//	58.5킬로미터앞
#define	IDM_0058600_AH	2200	//	58.6킬로미터앞
#define	IDM_0058700_AH	2201	//	58.7킬로미터앞
#define	IDM_0058800_AH	2202	//	58.8킬로미터앞
#define	IDM_0058900_AH	2203	//	58.9킬로미터앞
#define	IDM_0059000_AH	2204	//	59킬로미터앞
#define	IDM_0059100_AH	2205	//	59.1킬로미터앞
#define	IDM_0059200_AH	2206	//	59.2킬로미터앞
#define	IDM_0059300_AH	2207	//	59.3킬로미터앞
#define	IDM_0059400_AH	2208	//	59.4킬로미터앞
#define	IDM_0059500_AH	2209	//	59.5킬로미터앞
#define	IDM_0059600_AH	2210	//	59.6킬로미터앞
#define	IDM_0059700_AH	2211	//	59.7킬로미터앞
#define	IDM_0059800_AH	2212	//	59.8킬로미터앞
#define	IDM_0059900_AH	2213	//	59.9킬로미터앞
#define	IDM_0060000_AH	2214	//	60킬로미터앞
#define	IDM_0060100_AH	2215	//	60.1킬로미터앞
#define	IDM_0060200_AH	2216	//	60.2킬로미터앞
#define	IDM_0060300_AH	2217	//	60.3킬로미터앞
#define	IDM_0060400_AH	2218	//	60.4킬로미터앞
#define	IDM_0060500_AH	2219	//	60.5킬로미터앞
#define	IDM_0060600_AH	2220	//	60.6킬로미터앞
#define	IDM_0060700_AH	2221	//	60.7킬로미터앞
#define	IDM_0060800_AH	2222	//	60.8킬로미터앞
#define	IDM_0060900_AH	2223	//	60.9킬로미터앞
#define	IDM_0061000_AH	2224	//	61킬로미터앞
#define	IDM_0061100_AH	2225	//	61.1킬로미터앞
#define	IDM_0061200_AH	2226	//	61.2킬로미터앞
#define	IDM_0061300_AH	2227	//	61.3킬로미터앞
#define	IDM_0061400_AH	2228	//	61.4킬로미터앞
#define	IDM_0061500_AH	2229	//	61.5킬로미터앞
#define	IDM_0061600_AH	2230	//	61.6킬로미터앞
#define	IDM_0061700_AH	2231	//	61.7킬로미터앞
#define	IDM_0061800_AH	2232	//	61.8킬로미터앞
#define	IDM_0061900_AH	2233	//	61.9킬로미터앞
#define	IDM_0062000_AH	2234	//	62킬로미터앞
#define	IDM_0062100_AH	2235	//	62.1킬로미터앞
#define	IDM_0062200_AH	2236	//	62.2킬로미터앞
#define	IDM_0062300_AH	2237	//	62.3킬로미터앞
#define	IDM_0062400_AH	2238	//	62.4킬로미터앞
#define	IDM_0062500_AH	2239	//	62.5킬로미터앞
#define	IDM_0062600_AH	2240	//	62.6킬로미터앞
#define	IDM_0062700_AH	2241	//	62.7킬로미터앞
#define	IDM_0062800_AH	2242	//	62.8킬로미터앞
#define	IDM_0062900_AH	2243	//	62.9킬로미터앞
#define	IDM_0063000_AH	2244	//	63킬로미터앞
#define	IDM_0063100_AH	2245	//	63.1킬로미터앞
#define	IDM_0063200_AH	2246	//	63.2킬로미터앞
#define	IDM_0063300_AH	2247	//	63.3킬로미터앞
#define	IDM_0063400_AH	2248	//	63.4킬로미터앞
#define	IDM_0063500_AH	2249	//	63.5킬로미터앞
#define	IDM_0063600_AH	2250	//	63.6킬로미터앞
#define	IDM_0063700_AH	2251	//	63.7킬로미터앞
#define	IDM_0063800_AH	2252	//	63.8킬로미터앞
#define	IDM_0063900_AH	2253	//	63.9킬로미터앞
#define	IDM_0064000_AH	2254	//	64킬로미터앞
#define	IDM_0064100_AH	2255	//	64.1킬로미터앞
#define	IDM_0064200_AH	2256	//	64.2킬로미터앞
#define	IDM_0064300_AH	2257	//	64.3킬로미터앞
#define	IDM_0064400_AH	2258	//	64.4킬로미터앞
#define	IDM_0064500_AH	2259	//	64.5킬로미터앞
#define	IDM_0064600_AH	2260	//	64.6킬로미터앞
#define	IDM_0064700_AH	2261	//	64.7킬로미터앞
#define	IDM_0064800_AH	2262	//	64.8킬로미터앞
#define	IDM_0064900_AH	2263	//	64.9킬로미터앞
#define	IDM_0065000_AH	2264	//	65킬로미터앞
#define	IDM_0065100_AH	2265	//	65.1킬로미터앞
#define	IDM_0065200_AH	2266	//	65.2킬로미터앞
#define	IDM_0065300_AH	2267	//	65.3킬로미터앞
#define	IDM_0065400_AH	2268	//	65.4킬로미터앞
#define	IDM_0065500_AH	2269	//	65.5킬로미터앞
#define	IDM_0065600_AH	2270	//	65.6킬로미터앞
#define	IDM_0065700_AH	2271	//	65.7킬로미터앞
#define	IDM_0065800_AH	2272	//	65.8킬로미터앞
#define	IDM_0065900_AH	2273	//	65.9킬로미터앞
#define	IDM_0066000_AH	2274	//	66킬로미터앞
#define	IDM_0066100_AH	2275	//	66.1킬로미터앞
#define	IDM_0066200_AH	2276	//	66.2킬로미터앞
#define	IDM_0066300_AH	2277	//	66.3킬로미터앞
#define	IDM_0066400_AH	2278	//	66.4킬로미터앞
#define	IDM_0066500_AH	2279	//	66.5킬로미터앞
#define	IDM_0066600_AH	2280	//	66.6킬로미터앞
#define	IDM_0066700_AH	2281	//	66.7킬로미터앞
#define	IDM_0066800_AH	2282	//	66.8킬로미터앞
#define	IDM_0066900_AH	2283	//	66.9킬로미터앞
#define	IDM_0067000_AH	2284	//	67킬로미터앞
#define	IDM_0067100_AH	2285	//	67.1킬로미터앞
#define	IDM_0067200_AH	2286	//	67.2킬로미터앞
#define	IDM_0067300_AH	2287	//	67.3킬로미터앞
#define	IDM_0067400_AH	2288	//	67.4킬로미터앞
#define	IDM_0067500_AH	2289	//	67.5킬로미터앞
#define	IDM_0067600_AH	2290	//	67.6킬로미터앞
#define	IDM_0067700_AH	2291	//	67.7킬로미터앞
#define	IDM_0067800_AH	2292	//	67.8킬로미터앞
#define	IDM_0067900_AH	2293	//	67.9킬로미터앞
#define	IDM_0068000_AH	2294	//	68킬로미터앞
#define	IDM_0068100_AH	2295	//	68.1킬로미터앞
#define	IDM_0068200_AH	2296	//	68.2킬로미터앞
#define	IDM_0068300_AH	2297	//	68.3킬로미터앞
#define	IDM_0068400_AH	2298	//	68.4킬로미터앞
#define	IDM_0068500_AH	2299	//	68.5킬로미터앞
#define	IDM_0068600_AH	2300	//	68.6킬로미터앞
#define	IDM_0068700_AH	2301	//	68.7킬로미터앞
#define	IDM_0068800_AH	2302	//	68.8킬로미터앞
#define	IDM_0068900_AH	2303	//	68.9킬로미터앞
#define	IDM_0069000_AH	2304	//	69킬로미터앞
#define	IDM_0069100_AH	2305	//	69.1킬로미터앞
#define	IDM_0069200_AH	2306	//	69.2킬로미터앞
#define	IDM_0069300_AH	2307	//	69.3킬로미터앞
#define	IDM_0069400_AH	2308	//	69.4킬로미터앞
#define	IDM_0069500_AH	2309	//	69.5킬로미터앞
#define	IDM_0069600_AH	2310	//	69.6킬로미터앞
#define	IDM_0069700_AH	2311	//	69.7킬로미터앞
#define	IDM_0069800_AH	2312	//	69.8킬로미터앞
#define	IDM_0069900_AH	2313	//	69.9킬로미터앞
#define	IDM_0070000_AH	2314	//	70킬로미터앞
#define	IDM_0070100_AH	2315	//	70.1킬로미터앞
#define	IDM_0070200_AH	2316	//	70.2킬로미터앞
#define	IDM_0070300_AH	2317	//	70.3킬로미터앞
#define	IDM_0070400_AH	2318	//	70.4킬로미터앞
#define	IDM_0070500_AH	2319	//	70.5킬로미터앞
#define	IDM_0070600_AH	2320	//	70.6킬로미터앞
#define	IDM_0070700_AH	2321	//	70.7킬로미터앞
#define	IDM_0070800_AH	2322	//	70.8킬로미터앞
#define	IDM_0070900_AH	2323	//	70.9킬로미터앞
#define	IDM_0071000_AH	2324	//	71킬로미터앞
#define	IDM_0071100_AH	2325	//	71.1킬로미터앞
#define	IDM_0071200_AH	2326	//	71.2킬로미터앞
#define	IDM_0071300_AH	2327	//	71.3킬로미터앞
#define	IDM_0071400_AH	2328	//	71.4킬로미터앞
#define	IDM_0071500_AH	2329	//	71.5킬로미터앞
#define	IDM_0071600_AH	2330	//	71.6킬로미터앞
#define	IDM_0071700_AH	2331	//	71.7킬로미터앞
#define	IDM_0071800_AH	2332	//	71.8킬로미터앞
#define	IDM_0071900_AH	2333	//	71.9킬로미터앞
#define	IDM_0072000_AH	2334	//	72킬로미터앞
#define	IDM_0072100_AH	2335	//	72.1킬로미터앞
#define	IDM_0072200_AH	2336	//	72.2킬로미터앞
#define	IDM_0072300_AH	2337	//	72.3킬로미터앞
#define	IDM_0072400_AH	2338	//	72.4킬로미터앞
#define	IDM_0072500_AH	2339	//	72.5킬로미터앞
#define	IDM_0072600_AH	2340	//	72.6킬로미터앞
#define	IDM_0072700_AH	2341	//	72.7킬로미터앞
#define	IDM_0072800_AH	2342	//	72.8킬로미터앞
#define	IDM_0072900_AH	2343	//	72.9킬로미터앞
#define	IDM_0073000_AH	2344	//	73킬로미터앞
#define	IDM_0073100_AH	2345	//	73.1킬로미터앞
#define	IDM_0073200_AH	2346	//	73.2킬로미터앞
#define	IDM_0073300_AH	2347	//	73.3킬로미터앞
#define	IDM_0073400_AH	2348	//	73.4킬로미터앞
#define	IDM_0073500_AH	2349	//	73.5킬로미터앞
#define	IDM_0073600_AH	2350	//	73.6킬로미터앞
#define	IDM_0073700_AH	2351	//	73.7킬로미터앞
#define	IDM_0073800_AH	2352	//	73.8킬로미터앞
#define	IDM_0073900_AH	2353	//	73.9킬로미터앞
#define	IDM_0074000_AH	2354	//	74킬로미터앞
#define	IDM_0074100_AH	2355	//	74.1킬로미터앞
#define	IDM_0074200_AH	2356	//	74.2킬로미터앞
#define	IDM_0074300_AH	2357	//	74.3킬로미터앞
#define	IDM_0074400_AH	2358	//	74.4킬로미터앞
#define	IDM_0074500_AH	2359	//	74.5킬로미터앞
#define	IDM_0074600_AH	2360	//	74.6킬로미터앞
#define	IDM_0074700_AH	2361	//	74.7킬로미터앞
#define	IDM_0074800_AH	2362	//	74.8킬로미터앞
#define	IDM_0074900_AH	2363	//	74.9킬로미터앞
#define	IDM_0075000_AH	2364	//	75킬로미터앞
#define	IDM_0075100_AH	2365	//	75.1킬로미터앞
#define	IDM_0075200_AH	2366	//	75.2킬로미터앞
#define	IDM_0075300_AH	2367	//	75.3킬로미터앞
#define	IDM_0075400_AH	2368	//	75.4킬로미터앞
#define	IDM_0075500_AH	2369	//	75.5킬로미터앞
#define	IDM_0075600_AH	2370	//	75.6킬로미터앞
#define	IDM_0075700_AH	2371	//	75.7킬로미터앞
#define	IDM_0075800_AH	2372	//	75.8킬로미터앞
#define	IDM_0075900_AH	2373	//	75.9킬로미터앞
#define	IDM_0076000_AH	2374	//	76킬로미터앞
#define	IDM_0076100_AH	2375	//	76.1킬로미터앞
#define	IDM_0076200_AH	2376	//	76.2킬로미터앞
#define	IDM_0076300_AH	2377	//	76.3킬로미터앞
#define	IDM_0076400_AH	2378	//	76.4킬로미터앞
#define	IDM_0076500_AH	2379	//	76.5킬로미터앞
#define	IDM_0076600_AH	2380	//	76.6킬로미터앞
#define	IDM_0076700_AH	2381	//	76.7킬로미터앞
#define	IDM_0076800_AH	2382	//	76.8킬로미터앞
#define	IDM_0076900_AH	2383	//	76.9킬로미터앞
#define	IDM_0077000_AH	2384	//	77킬로미터앞
#define	IDM_0077100_AH	2385	//	77.1킬로미터앞
#define	IDM_0077200_AH	2386	//	77.2킬로미터앞
#define	IDM_0077300_AH	2387	//	77.3킬로미터앞
#define	IDM_0077400_AH	2388	//	77.4킬로미터앞
#define	IDM_0077500_AH	2389	//	77.5킬로미터앞
#define	IDM_0077600_AH	2390	//	77.6킬로미터앞
#define	IDM_0077700_AH	2391	//	77.7킬로미터앞
#define	IDM_0077800_AH	2392	//	77.8킬로미터앞
#define	IDM_0077900_AH	2393	//	77.9킬로미터앞
#define	IDM_0078000_AH	2394	//	78킬로미터앞
#define	IDM_0078100_AH	2395	//	78.1킬로미터앞
#define	IDM_0078200_AH	2396	//	78.2킬로미터앞
#define	IDM_0078300_AH	2397	//	78.3킬로미터앞
#define	IDM_0078400_AH	2398	//	78.4킬로미터앞
#define	IDM_0078500_AH	2399	//	78.5킬로미터앞
#define	IDM_0078600_AH	2400	//	78.6킬로미터앞
#define	IDM_0078700_AH	2401	//	78.7킬로미터앞
#define	IDM_0078800_AH	2402	//	78.8킬로미터앞
#define	IDM_0078900_AH	2403	//	78.9킬로미터앞
#define	IDM_0079000_AH	2404	//	79킬로미터앞
#define	IDM_0079100_AH	2405	//	79.1킬로미터앞
#define	IDM_0079200_AH	2406	//	79.2킬로미터앞
#define	IDM_0079300_AH	2407	//	79.3킬로미터앞
#define	IDM_0079400_AH	2408	//	79.4킬로미터앞
#define	IDM_0079500_AH	2409	//	79.5킬로미터앞
#define	IDM_0079600_AH	2410	//	79.6킬로미터앞
#define	IDM_0079700_AH	2411	//	79.7킬로미터앞
#define	IDM_0079800_AH	2412	//	79.8킬로미터앞
#define	IDM_0079900_AH	2413	//	79.9킬로미터앞
#define	IDM_0080000_AH	2414	//	80킬로미터앞
#define	IDM_0080100_AH	2415	//	80.1킬로미터앞
#define	IDM_0080200_AH	2416	//	80.2킬로미터앞
#define	IDM_0080300_AH	2417	//	80.3킬로미터앞
#define	IDM_0080400_AH	2418	//	80.4킬로미터앞
#define	IDM_0080500_AH	2419	//	80.5킬로미터앞
#define	IDM_0080600_AH	2420	//	80.6킬로미터앞
#define	IDM_0080700_AH	2421	//	80.7킬로미터앞
#define	IDM_0080800_AH	2422	//	80.8킬로미터앞
#define	IDM_0080900_AH	2423	//	80.9킬로미터앞
#define	IDM_0081000_AH	2424	//	81킬로미터앞
#define	IDM_0081100_AH	2425	//	81.1킬로미터앞
#define	IDM_0081200_AH	2426	//	81.2킬로미터앞
#define	IDM_0081300_AH	2427	//	81.3킬로미터앞
#define	IDM_0081400_AH	2428	//	81.4킬로미터앞
#define	IDM_0081500_AH	2429	//	81.5킬로미터앞
#define	IDM_0081600_AH	2430	//	81.6킬로미터앞
#define	IDM_0081700_AH	2431	//	81.7킬로미터앞
#define	IDM_0081800_AH	2432	//	81.8킬로미터앞
#define	IDM_0081900_AH	2433	//	81.9킬로미터앞
#define	IDM_0082000_AH	2434	//	82킬로미터앞
#define	IDM_0082100_AH	2435	//	82.1킬로미터앞
#define	IDM_0082200_AH	2436	//	82.2킬로미터앞
#define	IDM_0082300_AH	2437	//	82.3킬로미터앞
#define	IDM_0082400_AH	2438	//	82.4킬로미터앞
#define	IDM_0082500_AH	2439	//	82.5킬로미터앞
#define	IDM_0082600_AH	2440	//	82.6킬로미터앞
#define	IDM_0082700_AH	2441	//	82.7킬로미터앞
#define	IDM_0082800_AH	2442	//	82.8킬로미터앞
#define	IDM_0082900_AH	2443	//	82.9킬로미터앞
#define	IDM_0083000_AH	2444	//	83킬로미터앞
#define	IDM_0083100_AH	2445	//	83.1킬로미터앞
#define	IDM_0083200_AH	2446	//	83.2킬로미터앞
#define	IDM_0083300_AH	2447	//	83.3킬로미터앞
#define	IDM_0083400_AH	2448	//	83.4킬로미터앞
#define	IDM_0083500_AH	2449	//	83.5킬로미터앞
#define	IDM_0083600_AH	2450	//	83.6킬로미터앞
#define	IDM_0083700_AH	2451	//	83.7킬로미터앞
#define	IDM_0083800_AH	2452	//	83.8킬로미터앞
#define	IDM_0083900_AH	2453	//	83.9킬로미터앞
#define	IDM_0084000_AH	2454	//	84킬로미터앞
#define	IDM_0084100_AH	2455	//	84.1킬로미터앞
#define	IDM_0084200_AH	2456	//	84.2킬로미터앞
#define	IDM_0084300_AH	2457	//	84.3킬로미터앞
#define	IDM_0084400_AH	2458	//	84.4킬로미터앞
#define	IDM_0084500_AH	2459	//	84.5킬로미터앞
#define	IDM_0084600_AH	2460	//	84.6킬로미터앞
#define	IDM_0084700_AH	2461	//	84.7킬로미터앞
#define	IDM_0084800_AH	2462	//	84.8킬로미터앞
#define	IDM_0084900_AH	2463	//	84.9킬로미터앞
#define	IDM_0085000_AH	2464	//	85킬로미터앞
#define	IDM_0085100_AH	2465	//	85.1킬로미터앞
#define	IDM_0085200_AH	2466	//	85.2킬로미터앞
#define	IDM_0085300_AH	2467	//	85.3킬로미터앞
#define	IDM_0085400_AH	2468	//	85.4킬로미터앞
#define	IDM_0085500_AH	2469	//	85.5킬로미터앞
#define	IDM_0085600_AH	2470	//	85.6킬로미터앞
#define	IDM_0085700_AH	2471	//	85.7킬로미터앞
#define	IDM_0085800_AH	2472	//	85.8킬로미터앞
#define	IDM_0085900_AH	2473	//	85.9킬로미터앞
#define	IDM_0086000_AH	2474	//	86킬로미터앞
#define	IDM_0086100_AH	2475	//	86.1킬로미터앞
#define	IDM_0086200_AH	2476	//	86.2킬로미터앞
#define	IDM_0086300_AH	2477	//	86.3킬로미터앞
#define	IDM_0086400_AH	2478	//	86.4킬로미터앞
#define	IDM_0086500_AH	2479	//	86.5킬로미터앞
#define	IDM_0086600_AH	2480	//	86.6킬로미터앞
#define	IDM_0086700_AH	2481	//	86.7킬로미터앞
#define	IDM_0086800_AH	2482	//	86.8킬로미터앞
#define	IDM_0086900_AH	2483	//	86.9킬로미터앞
#define	IDM_0087000_AH	2484	//	87킬로미터앞
#define	IDM_0087100_AH	2485	//	87.1킬로미터앞
#define	IDM_0087200_AH	2486	//	87.2킬로미터앞
#define	IDM_0087300_AH	2487	//	87.3킬로미터앞
#define	IDM_0087400_AH	2488	//	87.4킬로미터앞
#define	IDM_0087500_AH	2489	//	87.5킬로미터앞
#define	IDM_0087600_AH	2490	//	87.6킬로미터앞
#define	IDM_0087700_AH	2491	//	87.7킬로미터앞
#define	IDM_0087800_AH	2492	//	87.8킬로미터앞
#define	IDM_0087900_AH	2493	//	87.9킬로미터앞
#define	IDM_0088000_AH	2494	//	88킬로미터앞
#define	IDM_0088100_AH	2495	//	88.1킬로미터앞
#define	IDM_0088200_AH	2496	//	88.2킬로미터앞
#define	IDM_0088300_AH	2497	//	88.3킬로미터앞
#define	IDM_0088400_AH	2498	//	88.4킬로미터앞
#define	IDM_0088500_AH	2499	//	88.5킬로미터앞
#define	IDM_0088600_AH	2500	//	88.6킬로미터앞
#define	IDM_0088700_AH	2501	//	88.7킬로미터앞
#define	IDM_0088800_AH	2502	//	88.8킬로미터앞
#define	IDM_0088900_AH	2503	//	88.9킬로미터앞
#define	IDM_0089000_AH	2504	//	89킬로미터앞
#define	IDM_0089100_AH	2505	//	89.1킬로미터앞
#define	IDM_0089200_AH	2506	//	89.2킬로미터앞
#define	IDM_0089300_AH	2507	//	89.3킬로미터앞
#define	IDM_0089400_AH	2508	//	89.4킬로미터앞
#define	IDM_0089500_AH	2509	//	89.5킬로미터앞
#define	IDM_0089600_AH	2510	//	89.6킬로미터앞
#define	IDM_0089700_AH	2511	//	89.7킬로미터앞
#define	IDM_0089800_AH	2512	//	89.8킬로미터앞
#define	IDM_0089900_AH	2513	//	89.9킬로미터앞
#define	IDM_0090000_AH	2514	//	90킬로미터앞
#define	IDM_0090100_AH	2515	//	90.1킬로미터앞
#define	IDM_0090200_AH	2516	//	90.2킬로미터앞
#define	IDM_0090300_AH	2517	//	90.3킬로미터앞
#define	IDM_0090400_AH	2518	//	90.4킬로미터앞
#define	IDM_0090500_AH	2519	//	90.5킬로미터앞
#define	IDM_0090600_AH	2520	//	90.6킬로미터앞
#define	IDM_0090700_AH	2521	//	90.7킬로미터앞
#define	IDM_0090800_AH	2522	//	90.8킬로미터앞
#define	IDM_0090900_AH	2523	//	90.9킬로미터앞
#define	IDM_0091000_AH	2524	//	91킬로미터앞
#define	IDM_0091100_AH	2525	//	91.1킬로미터앞
#define	IDM_0091200_AH	2526	//	91.2킬로미터앞
#define	IDM_0091300_AH	2527	//	91.3킬로미터앞
#define	IDM_0091400_AH	2528	//	91.4킬로미터앞
#define	IDM_0091500_AH	2529	//	91.5킬로미터앞
#define	IDM_0091600_AH	2530	//	91.6킬로미터앞
#define	IDM_0091700_AH	2531	//	91.7킬로미터앞
#define	IDM_0091800_AH	2532	//	91.8킬로미터앞
#define	IDM_0091900_AH	2533	//	91.9킬로미터앞
#define	IDM_0092000_AH	2534	//	92킬로미터앞
#define	IDM_0092100_AH	2535	//	92.1킬로미터앞
#define	IDM_0092200_AH	2536	//	92.2킬로미터앞
#define	IDM_0092300_AH	2537	//	92.3킬로미터앞
#define	IDM_0092400_AH	2538	//	92.4킬로미터앞
#define	IDM_0092500_AH	2539	//	92.5킬로미터앞
#define	IDM_0092600_AH	2540	//	92.6킬로미터앞
#define	IDM_0092700_AH	2541	//	92.7킬로미터앞
#define	IDM_0092800_AH	2542	//	92.8킬로미터앞
#define	IDM_0092900_AH	2543	//	92.9킬로미터앞
#define	IDM_0093000_AH	2544	//	93킬로미터앞
#define	IDM_0093100_AH	2545	//	93.1킬로미터앞
#define	IDM_0093200_AH	2546	//	93.2킬로미터앞
#define	IDM_0093300_AH	2547	//	93.3킬로미터앞
#define	IDM_0093400_AH	2548	//	93.4킬로미터앞
#define	IDM_0093500_AH	2549	//	93.5킬로미터앞
#define	IDM_0093600_AH	2550	//	93.6킬로미터앞
#define	IDM_0093700_AH	2551	//	93.7킬로미터앞
#define	IDM_0093800_AH	2552	//	93.8킬로미터앞
#define	IDM_0093900_AH	2553	//	93.9킬로미터앞
#define	IDM_0094000_AH	2554	//	94킬로미터앞
#define	IDM_0094100_AH	2555	//	94.1킬로미터앞
#define	IDM_0094200_AH	2556	//	94.2킬로미터앞
#define	IDM_0094300_AH	2557	//	94.3킬로미터앞
#define	IDM_0094400_AH	2558	//	94.4킬로미터앞
#define	IDM_0094500_AH	2559	//	94.5킬로미터앞
#define	IDM_0094600_AH	2560	//	94.6킬로미터앞
#define	IDM_0094700_AH	2561	//	94.7킬로미터앞
#define	IDM_0094800_AH	2562	//	94.8킬로미터앞
#define	IDM_0094900_AH	2563	//	94.9킬로미터앞
#define	IDM_0095000_AH	2564	//	95킬로미터앞
#define	IDM_0095100_AH	2565	//	95.1킬로미터앞
#define	IDM_0095200_AH	2566	//	95.2킬로미터앞
#define	IDM_0095300_AH	2567	//	95.3킬로미터앞
#define	IDM_0095400_AH	2568	//	95.4킬로미터앞
#define	IDM_0095500_AH	2569	//	95.5킬로미터앞
#define	IDM_0095600_AH	2570	//	95.6킬로미터앞
#define	IDM_0095700_AH	2571	//	95.7킬로미터앞
#define	IDM_0095800_AH	2572	//	95.8킬로미터앞
#define	IDM_0095900_AH	2573	//	95.9킬로미터앞
#define	IDM_0096000_AH	2574	//	96킬로미터앞
#define	IDM_0096100_AH	2575	//	96.1킬로미터앞
#define	IDM_0096200_AH	2576	//	96.2킬로미터앞
#define	IDM_0096300_AH	2577	//	96.3킬로미터앞
#define	IDM_0096400_AH	2578	//	96.4킬로미터앞
#define	IDM_0096500_AH	2579	//	96.5킬로미터앞
#define	IDM_0096600_AH	2580	//	96.6킬로미터앞
#define	IDM_0096700_AH	2581	//	96.7킬로미터앞
#define	IDM_0096800_AH	2582	//	96.8킬로미터앞
#define	IDM_0096900_AH	2583	//	96.9킬로미터앞
#define	IDM_0097000_AH	2584	//	97킬로미터앞
#define	IDM_0097100_AH	2585	//	97.1킬로미터앞
#define	IDM_0097200_AH	2586	//	97.2킬로미터앞
#define	IDM_0097300_AH	2587	//	97.3킬로미터앞
#define	IDM_0097400_AH	2588	//	97.4킬로미터앞
#define	IDM_0097500_AH	2589	//	97.5킬로미터앞
#define	IDM_0097600_AH	2590	//	97.6킬로미터앞
#define	IDM_0097700_AH	2591	//	97.7킬로미터앞
#define	IDM_0097800_AH	2592	//	97.8킬로미터앞
#define	IDM_0097900_AH	2593	//	97.9킬로미터앞
#define	IDM_0098000_AH	2594	//	98킬로미터앞
#define	IDM_0098100_AH	2595	//	98.1킬로미터앞
#define	IDM_0098200_AH	2596	//	98.2킬로미터앞
#define	IDM_0098300_AH	2597	//	98.3킬로미터앞
#define	IDM_0098400_AH	2598	//	98.4킬로미터앞
#define	IDM_0098500_AH	2599	//	98.5킬로미터앞
#define	IDM_0098600_AH	2600	//	98.6킬로미터앞
#define	IDM_0098700_AH	2601	//	98.7킬로미터앞
#define	IDM_0098800_AH	2602	//	98.8킬로미터앞
#define	IDM_0098900_AH	2603	//	98.9킬로미터앞
#define	IDM_0099000_AH	2604	//	99킬로미터앞
#define	IDM_0099100_AH	2605	//	99.1킬로미터앞
#define	IDM_0099200_AH	2606	//	99.2킬로미터앞
#define	IDM_0099300_AH	2607	//	99.3킬로미터앞
#define	IDM_0099400_AH	2608	//	99.4킬로미터앞
#define	IDM_0099500_AH	2609	//	99.5킬로미터앞
#define	IDM_0099600_AH	2610	//	99.6킬로미터앞
#define	IDM_0099700_AH	2611	//	99.7킬로미터앞
#define	IDM_0099800_AH	2612	//	99.8킬로미터앞
#define	IDM_0099900_AH	2613	//	99.9킬로미터앞
#define	IDM_0100000_AH	2614	//	100킬로미터앞
#define	IDM_0110000_AH	2615	//	110킬로미터앞
#define	IDM_0120000_AH	2616	//	120킬로미터앞
#define	IDM_0130000_AH	2617	//	130킬로미터앞
#define	IDM_0140000_AH	2618	//	140킬로미터앞
#define	IDM_0150000_AH	2619	//	150킬로미터앞
#define	IDM_0160000_AH	2620	//	160킬로미터앞
#define	IDM_0170000_AH	2621	//	170킬로미터앞
#define	IDM_0180000_AH	2622	//	180킬로미터앞
#define	IDM_0190000_AH	2623	//	190킬로미터앞
#define	IDM_0200000_AH	2624	//	200킬로미터앞
#define	IDM_0210000_AH	2625	//	210킬로미터앞
#define	IDM_0220000_AH	2626	//	220킬로미터앞
#define	IDM_0230000_AH	2627	//	230킬로미터앞
#define	IDM_0240000_AH	2628	//	240킬로미터앞
#define	IDM_0250000_AH	2629	//	250킬로미터앞
#define	IDM_0260000_AH	2630	//	260킬로미터앞
#define	IDM_0270000_AH	2631	//	270킬로미터앞
#define	IDM_0280000_AH	2632	//	280킬로미터앞
#define	IDM_0290000_AH	2633	//	290킬로미터앞
#define	IDM_0300000_AH	2634	//	300킬로미터앞
#define	IDM_0310000_AH	2635	//	310킬로미터앞
#define	IDM_0320000_AH	2636	//	320킬로미터앞
#define	IDM_0330000_AH	2637	//	330킬로미터앞
#define	IDM_0340000_AH	2638	//	340킬로미터앞
#define	IDM_0350000_AH	2639	//	350킬로미터앞
#define	IDM_0360000_AH	2640	//	360킬로미터앞
#define	IDM_0370000_AH	2641	//	370킬로미터앞
#define	IDM_0380000_AH	2642	//	380킬로미터앞
#define	IDM_0390000_AH	2643	//	390킬로미터앞
#define	IDM_0400000_AH	2644	//	400킬로미터앞
#define	IDM_0410000_AH	2645	//	410킬로미터앞
#define	IDM_0420000_AH	2646	//	420킬로미터앞
#define	IDM_0430000_AH	2647	//	430킬로미터앞
#define	IDM_0440000_AH	2648	//	440킬로미터앞
#define	IDM_0450000_AH	2649	//	450킬로미터앞
#define	IDM_0460000_AH	2650	//	460킬로미터앞
#define	IDM_0470000_AH	2651	//	470킬로미터앞
#define	IDM_0480000_AH	2652	//	480킬로미터앞
#define	IDM_0490000_AH	2653	//	490킬로미터앞
#define	IDM_0500000_AH	2654	//	500킬로미터앞
#define	IDM_0510000_AH	2655	//	510킬로미터앞
#define	IDM_0520000_AH	2656	//	520킬로미터앞
#define	IDM_0530000_AH	2657	//	530킬로미터앞
#define	IDM_0540000_AH	2658	//	540킬로미터앞
#define	IDM_0550000_AH	2659	//	550킬로미터앞
#define	IDM_0560000_AH	2660	//	560킬로미터앞
#define	IDM_0570000_AH	2661	//	570킬로미터앞
#define	IDM_0580000_AH	2662	//	580킬로미터앞
#define	IDM_0590000_AH	2663	//	590킬로미터앞
#define	IDM_0600000_AH	2664	//	600킬로미터앞
#define	IDM_0610000_AH	2665	//	610킬로미터앞
#define	IDM_0620000_AH	2666	//	620킬로미터앞
#define	IDM_0630000_AH	2667	//	630킬로미터앞
#define	IDM_0640000_AH	2668	//	640킬로미터앞
#define	IDM_0650000_AH	2669	//	650킬로미터앞
#define	IDM_0660000_AH	2670	//	660킬로미터앞
#define	IDM_0670000_AH	2671	//	670킬로미터앞
#define	IDM_0680000_AH	2672	//	680킬로미터앞
#define	IDM_0690000_AH	2673	//	690킬로미터앞
#define	IDM_0700000_AH	2674	//	700킬로미터앞
#define	IDM_0710000_AH	2675	//	710킬로미터앞
#define	IDM_0720000_AH	2676	//	720킬로미터앞
#define	IDM_0730000_AH	2677	//	730킬로미터앞
#define	IDM_0740000_AH	2678	//	740킬로미터앞
#define	IDM_0750000_AH	2679	//	750킬로미터앞
#define	IDM_0760000_AH	2680	//	760킬로미터앞
#define	IDM_0770000_AH	2681	//	770킬로미터앞
#define	IDM_0780000_AH	2682	//	780킬로미터앞
#define	IDM_0790000_AH	2683	//	790킬로미터앞
#define	IDM_0800000_AH	2684	//	800킬로미터앞
#define	IDM_0810000_AH	2685	//	810킬로미터앞
#define	IDM_0820000_AH	2686	//	820킬로미터앞
#define	IDM_0830000_AH	2687	//	830킬로미터앞
#define	IDM_0840000_AH	2688	//	840킬로미터앞
#define	IDM_0850000_AH	2689	//	850킬로미터앞
#define	IDM_0860000_AH	2690	//	860킬로미터앞
#define	IDM_0870000_AH	2691	//	870킬로미터앞
#define	IDM_0880000_AH	2692	//	880킬로미터앞
#define	IDM_0890000_AH	2693	//	890킬로미터앞
#define	IDM_0900000_AH	2694	//	900킬로미터앞
#define	IDM_0910000_AH	2695	//	910킬로미터앞
#define	IDM_0920000_AH	2696	//	920킬로미터앞
#define	IDM_0930000_AH	2697	//	930킬로미터앞
#define	IDM_0940000_AH	2698	//	940킬로미터앞
#define	IDM_0950000_AH	2699	//	950킬로미터앞
#define	IDM_0960000_AH	2700	//	960킬로미터앞
#define	IDM_0970000_AH	2701	//	970킬로미터앞
#define	IDM_0980000_AH	2702	//	980킬로미터앞
#define	IDM_0990000_AH	2703	//	990킬로미터앞
#define	IDM_1000000_AH	2704	//	1000킬로미터앞
#define	IDS_0000100_AH	2705	//	100미터앞에
#define	IDS_0000200_AH	2706	//	200미터앞에
#define	IDS_0000300_AH	2707	//	300미터앞에
#define	IDS_0000400_AH	2708	//	400미터앞에
#define	IDS_0000500_AH	2709	//	500미터앞에
#define	IDS_0000600_AH	2710	//	600미터앞에
#define	IDS_0000700_AH	2711	//	700미터앞에
#define	IDS_0000800_AH	2712	//	800미터앞에
#define	IDS_0000900_AH	2713	//	900미터앞에
#define	IDS_0001000_AH	2714	//	1킬로미터앞에
#define	IDS_0001100_AH	2715	//	1.1킬로미터앞에
#define	IDS_0001200_AH	2716	//	1.2킬로미터앞에
#define	IDS_0001300_AH	2717	//	1.3킬로미터앞에
#define	IDS_0001400_AH	2718	//	1.4킬로미터앞에
#define	IDS_0001500_AH	2719	//	1.5킬로미터앞에
#define	IDS_0001600_AH	2720	//	1.6킬로미터앞에
#define	IDS_0001700_AH	2721	//	1.7킬로미터앞에
#define	IDS_0001800_AH	2722	//	1.8킬로미터앞에
#define	IDS_0001900_AH	2723	//	1.9킬로미터앞에
#define	IDS_0002000_AH	2724	//	2킬로미터앞에
#define	IDS_SPEED10	2725	//	시속 10킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED20	2726	//	시속 20킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED30	2727	//	시속 30킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED40	2728	//	시속 40킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED50	2729	//	시속 50킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED60	2730	//	시속 60킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED70	2731	//	시속 70킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED80	2732	//	시속 80킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED90	2733	//	시속 90킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED100	2734	//	시속 100킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED110	2735	//	시속 110킬로미터 이하로 주앵하십시오.
#define	IDS_SPEED120	2736	//	시속 120킬로미터 이하로 주앵하십시오.
#define	IDS_FIXEDSPEED	2737	//	과속단속 구간입니다.
#define	IDS_SPEED_SIGNAL	2738	//	신호과속단속 구간입니다.
#define	IDS_SIGNAL	2739	//	교통신호단속 구간입니다.
#define	IDS_SPEED_MOBILE	2740	//	이동식단속 구간입니다.
#define	IDS_BUSONLY	2741	//	버스전용차로 단속 구간입니다.
#define	IDS_HEAVY	2742	//	과적단속 구간입니다.
#define	IDS_PARKING	2743	//	주차단속 구간입니다.
#define	IDS_SIDEROAD	2744	//	갓길단속 구간입니다.
#define	IDS_INTUDE	2745	//	끼어들기단속 구간입니다.
#define	IDS_STOWAGE	2746	//	적재불량단속 구간입니다.
#define	IDS_SECTIONSTART	2747	//	구간단속 시작지점입니다.
#define	IDS_SECTIONEND	2748	//	구간단속 끝지점입니다.
#define	IDS_CHANGEABLE_ROAD	2749	//	가변차로 단속 구간입니다.
#define	IDS_ACCIDENT	2750	//	사고다발구간입니다.
#define	IDS_TRAFFIC	2751	//	교통정보수집 구간입니다.
#define	IDS_SHAEPBEND	2752	//	급커브 구간입니다.
#define	IDS_FOGZONE	2753	//	안개주의 구간입니다.
#define	IDS_INJURIOUS_MATTER	2754	//	유해물질 구간입니다.
#define	IDS_RESTAREA	2755	//	휴게소가 있습니다.
#define	IDS_TOLLGATE	2756	//	톨게이트가 있습니다.
#define	IDS_LPG_CHARGINGSTATION	2757	//	LPG 충전소가 있습니다.
#define	IDS_TUNNEL	2758	//	터널이 있습니다.
#define	IDS_CARCONTROL_AREA	2759	//	차량 통제 입니다.
#define	IDS_ACCIDENT_AREA	2760	//	사고 구간 입니다.
#define	IDS_CAPSIZE_AREA	2761	//	전복 사고 구간 입니다.
#define	IDS_FIRE_AREA	2762	//	화재 사고 구간 입니다.
#define	IDS_CONSTRUCTION_AREA	2763	//	공사 구간 입니다.
#define	IDS_REPAVING_AREA	2764	//	재포장 공사 구간 입니다.
#define	IDS_UNDERGRAOUND_AREA	2765	//	지하 공사 구간 입니다.
#define	IDS_DRAINAGE_AREA	2766	//	하수 및 배수구 공사 구간 입니다.
#define	IDS_ROADREPAIRING_AREA	2767	//	도로 선형 변경 공사 구간 입니다.
#define	IDS_ROADLANE_AREA	2768	//	차선 도색 공사 구간 입니다.
#define	IDS_ROAD_DRAINAGE_AREA	2769	//	도로 배수 공사 구간 입니다.
#define	IDS_EVENT_AREA	2770	//	행사 구간 입니다.
#define	IDS_ASSEMBLY_AREA	2771	//	집회 행사 구간 입니다.
#define	IDS_NATION_EVENT_AREA	2772	//	국가 행사 구간 입니다.
#define	IDS_NOTICE_AREA	2773	//	주의 구간 입니다.
#define	IDS_SNOWSLIDE_AREA	2774	//	눈사태 주의 구간 입니다.
#define	IDS_WASHOUT_AREA	2775	//	토사 주의 구간 입니다.
#define	IDS_FALLINGROCK_AREA	2776	//	낙석 주의 구간 입니다.
#define	IDS_SNOWFALL_AREA	2777	//	폭설 구간 입니다.
#define	IDS_FREEZING_AREA	2778	//	결빙 구간 입니다.
#define	IDS_FLOOD_AREA	2779	//	홍수 구간 입니다.
#define	IDS_BADROAD_AREA	2780	//	노면 불량 구간 입니다.
#define	IDS_FOG_AREA	2781	//	안개 지역 입니다.
#define	IDS_NOTOVERSPEED_AREA	2782	//	과속방지턱 구간입니다.
#define	IDS_SCHOOLZONE_AREA	2783	//	스쿨존 구간입니다.
#define	IDS_RAILROAD_AREA	2784	//	철도건널목 구간입니다.
#define	IDS_HUMP_ZONE	2785	//	과속방지턱이 있습니다.
#define	IDS_MULTI_HUMP_ZONE	2786	//	연속으로 과속방지턱이 있습니다.
#define	IDG_IS_CHILD_PROTECTZONE	2787	//	어린이 보호 구역입니다.
#define	IDS_RAILROAD_ZONE	2788	//	철도건널목이 있습니다.
#define	IDS_MULIT_RAILROAD_ZONE	2789	//	연속으로 철도건널목이 있습니다.
#define	IDS_00001	2790	//	안전운전 하십시오.
#define	IDS_00002	2791	//	주의하십시오.
#define	IDS_00003	2792	//	주변에 사용자 안전운전 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00004	2793	//	주변에 과속 카메라 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00005	2794	//	주변에 이동식 카메라 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00006	2795	//	주변에 구간단속 카메라 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00007	2796	//	주변에 신호과속 카메라 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00008	2797	//	주변에 신호단속 카메라 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00009	2798	//	주변에 버스전용차로 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00010	2799	//	주변에 주차단속 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00011	2800	//	주변에 가변차로 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00012	2801	//	주변에 갓길감시 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00013	2802	//	주변에 끼어들기 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00014	2803	//	주변에 과적차량 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00015	2804	//	주변에 적재불량 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00016	2805	//	주변에 사용자 안전운전 등록 지점이 있습니다. 주의 운전 하십시요.
#define	IDS_00017	2806	//	주앵전방
#define	IDS_00018	2807	//	차량 통제
#define	IDS_00019	2808	//	사고 구간
#define	IDS_00020	2809	//	전복 사고 구간
#define	IDS_00021	2810	//	화재 사고 구간
#define	IDS_00022	2811	//	공사 구간
#define	IDS_00023	2812	//	재포장 공사 구간
#define	IDS_00024	2813	//	지하 공사 구간
#define	IDS_00025	2814	//	하수 및 배수구 공사 구간
#define	IDS_00026	2815	//	도로 선형 변경 공사 구간
#define	IDS_00027	2816	//	차선 도색 공사 구간
#define	IDS_00028	2817	//	도로 배수 공사 구간
#define	IDS_00029	2818	//	행사 구간
#define	IDS_00030	2819	//	집회 행사 구간
#define	IDS_00031	2820	//	국가 행사 구간
#define	IDS_00032	2821	//	주의 구간
#define	IDS_00033	2822	//	눈사태 주의 구간
#define	IDS_00034	2823	//	토사 주의 구간
#define	IDS_00035	2824	//	낙석 주의 구간
#define	IDS_00036	2825	//	폭설 구간
#define	IDS_00037	2826	//	결빙 구간
#define	IDS_00038	2827	//	홍수 구간
#define	IDS_00039	2828	//	노면 불량 구간
#define	IDS_00040	2829	//	안개 지역
#define	IDS_00041	2830	//	박스형 과속단속구간입니다.
#define	IDS_00042	2831	//	방범용CCTV가 있습니다.
#define	IDS_00043	2832	//	시야불량지점입니다.
#define	IDS_00044	2833	//	신호위반 다발구간입니다.
#define	IDS_00045	2834	//	과속운행 다발구간입니다.
#define	IDS_00046	2835	//	교통혼잡지역입니다.
#define	IDS_00047	2836	//	방향별 차로선택이 필요한 교차로입니다.
#define	IDS_00048	2837	//	무단횡단 보행자 사고 다발지점입니다.
#define	IDS_00049	2838	//	일방통행도로가 있습니다.
#define	IDS_00050	2839	//	급경사 구간입니다.
#define	IDS_00051	2840	//	우측 돌출차량에 주의하십시오.
#define	IDS_00052	2841	//	좌우측 돌출차량에 주의하십시오.
#define	IDS_00053	2842	//	좌측 돌출차량에 주의하십시오.
#define	IDS_00054	2843	//	신호를 준수하십시오.
#define	IDS_00055	2844	//	제한속도를 준수하십시오.
#define	IDS_00056	2845	//	양보운전 하십시오.
#define	IDS_00057	2846	//	목적지를 확인하십시오.
#define	IDS_00058	2847	//	서행운전하십시오.
#define	IDS_00059	2848	//	진행방향을 확인하십시오
#define	IDS_00060	2849	//	야생동물 출현이 잦은 구간입니다
#define	IDWA_001	2850	//	환동해의 중심도시 강릉시입니다
#define	IDWA_002	2851	//	해오름의 고장 아름다운바다의 도시 동해시입니다
#define	IDWA_003	2852	//	세계적인 동굴 도시 삼척시입니다
#define	IDWA_004	2853	//	관광과 해양중심도시 속초시입니다
#define	IDWA_005	2854	//	대한민국 대표 건강도시 원주시입니다
#define	IDWA_006	2855	//	희망이 흐르는 도시 춘천시입니다
#define	IDWA_007	2856	//	레저 스포츠의 도시 태백시입니다
#define	IDWA_008	2857	//	천연 자연의 고장 강원도입니다
#define	IDWA_009	2858	//	"꿈이 있는, 꿈을이루는 도시 고양시입니다"
#define	IDWA_010	2859	//	언제까지나 살고싶은 도시 과천시입니다
#define	IDWA_011	2860	//	변화하는 미래도시 광명시입니다
#define	IDWA_012	2861	//	맑고 풍요로운 도시 광주시입니다
#define	IDWA_013	2862	//	고구려의 기상과 조선왕조의 얼이 서려 있는 세계속의 구리시입니다
#define	IDWA_014	2863	//	"튼튼한 도시, 활기찬 시민 군포시입니다"
#define	IDWA_015	2864	//	아름다운 웰빙 도시 김포시입니다
#define	IDWA_016	2865	//	"희망찬 미래의 명품 도시, 남양주시입니다"
#define	IDWA_017	2866	//	꿈을 두드리는 도시 동두천시입니다
#define	IDWA_018	2867	//	첨단산업과 함께하는 문화도시 부천시입니다
#define	IDWA_019	2868	//	미래형 첨단도시 이푸른성남시입니다
#define	IDWA_020	2869	//	더불어 사는 행복한 도시 수원시입니다
#define	IDWA_021	2870	//	미래를 키우는 생명도시 시흥시입니다
#define	IDWA_022	2871	//	1등도시 안산시입니다
#define	IDWA_023	2872	//	세계적인 예술문화의 도시 안성시입니다
#define	IDWA_024	2873	//	아름다운 도시 행복한 안양시입니다
#define	IDWA_025	2874	//	시민이 만드는 행복도시 양주시입니다
#define	IDWA_026	2875	//	"새로운 도약, 살고싶은 오산시입니다"
#define	IDWA_027	2876	//	세계최고 선진용인시입니다
#define	IDWA_028	2877	//	"희망을 주는 도시, 살고싶은 의왕시입니다"
#define	IDWA_029	2878	//	자랑스런 시민 살맛나는 의정부시입니다
#define	IDWA_030	2879	//	창조적으로 변화 도약하는 이천시입니다
#define	IDWA_031	2880	//	대한민국 대표도시 지엔지 파주시입니다
#define	IDWA_032	2881	//	세계속의 일류평택 평택시입니다
#define	IDWA_033	2882	//	시민중심 행복도시 포천시입니다
#define	IDWA_034	2883	//	새롭게 도약하는 살고싶은 하남시입니다
#define	IDWA_035	2884	//	서해안시대를 여는 화성시입니다
#define	IDWA_036	2885	//	세계속의 경기도입니다
#define	IDWA_037	2886	//	푸른 바다와 넉넉한 인심이 가득한 거제시입니다
#define	IDWA_038	2887	//	문화의 고장 김해시입니다
#define	IDWA_039	2888	//	꿈의 항만도시 마산시입니다
#define	IDWA_040	2889	//	역사와 문화 관광의 도시 밀양시입니다
#define	IDWA_041	2890	//	첨단항공산업의 메카 사천시입니다
#define	IDWA_042	2891	//	"행복을 열어가는, 으뜸도시 양산시입니다"
#define	IDWA_043	2892	//	살기 좋은 환경도시 진주시입니다
#define	IDWA_044	2893	//	꿈과 희망의 비전도시 진해시입니다
#define	IDWA_045	2894	//	유구한 역사와 문화 전통의 도시 창원시입니다
#define	IDWA_046	2895	//	아름다운 해양관광 휴양도시 통영시입니다
#define	IDWA_047	2896	//	한국의 미래 경상남도입니다
#define	IDWA_048	2897	//	시민과 함께하는 역동적인 경산시입니다
#define	IDWA_049	2898	//	역사의 도시 경주시입니다
#define	IDWA_050	2899	//	젊고 활기찬 도시 테크노폴리스 구미시입니다
#define	IDWA_051	2900	//	대한민국의 중심 살기 좋은 행복도시 김천시입니다
#define	IDWA_052	2901	//	또 하나의 도전 문경시입니다
#define	IDWA_053	2902	//	사람과 자연이 하나되는 도시 상주시입니다
#define	IDWA_054	2903	//	한국정신문화의 수도 안동시입니다
#define	IDWA_055	2904	//	살기 좋은 고품격 도시 영주시입니다
#define	IDWA_056	2905	//	"깨끗한 시정, 잘사는 영천시입니다"
#define	IDWA_057	2906	//	꿈과 희망의 글로벌도시 포항시입니다
#define	IDWA_058	2907	//	한국의 미래 경상북도입니다
#define	IDWA_059	2908	//	시민과 함께 만드는 꿈과희망의 도시 광양시입니다
#define	IDWA_060	2909	//	"시민과 함께여는 새로운 영산강 시대, 나주시입니다"
#define	IDWA_061	2910	//	"멋과 낭만, 꿈이 있는 도시 목포시입니다"
#define	IDWA_062	2911	//	대한민국 생태수도 순천시입니다
#define	IDWA_063	2912	//	멋과 낭만이 있는 희망의도시 여수시입니다
#define	IDWA_064	2913	//	풍요로운 미래도시 전라남도입니다
#define	IDWA_065	2914	//	환황해권의 경제중심도시 군산시입니다
#define	IDWA_066	2915	//	활기차고 신명나는 김제시입니다
#define	IDWA_067	2916	//	"활기찬 경제, 행복한 남원시입니다"
#define	IDWA_068	2917	//	백제의 향기가 살아숨쉬는 익산시입니다
#define	IDWA_069	2918	//	더 큰 미래를 열어가는 천년전주시입니다
#define	IDWA_070	2919	//	시민이 잘사는 정읍시입니다
#define	IDWA_071	2920	//	문화의 도시 전라북도입니다
#define	IDWA_072	2921	//	행복과 희망의 1번지 제주특별자치도 서귀포시입니다
#define	IDWA_073	2922	//	희망찬 평화의섬 제주시입니다
#define	IDWA_074	2923	//	새로운 도전 제주도입니다
#define	IDWA_075	2924	//	시민 중심의 모범도시 계룡시입니다
#define	IDWA_076	2925	//	힘찬도전 위대한 공주시입니다
#define	IDWA_077	2926	//	"함께하는 시민, 번영하는 논산시입니다"
#define	IDWA_078	2927	//	쾌적하고 살기 좋은 도시 보령시입니다
#define	IDWA_079	2928	//	생동하는 도시 행복한 서산시입니다
#define	IDWA_080	2929	//	최첨단녹색도시 스마트 안산시입니다
#define	IDWA_081	2930	//	희망이 넘치는 미래도시 천안시입니다
#define	IDWA_082	2931	//	한국의 중심 충청남도입니다
#define	IDWA_083	2932	//	한방건강과 영상문화의 도시 제천시입니다
#define	IDWA_084	2933	//	살맛나는 행복한 청주시입니다
#define	IDWA_085	2934	//	"활기찬 경제, 역동하는 충주시입니다"
#define	IDWA_086	2935	//	행복한 시민이 있는곳 충청북도입니다
#define	IDWA_087	2936	//	매력있는 세계의 도시 서울특별시입니다
#define	IDWA_088	2937	//	동북아 시대의 해양수도 부산광역시입니다
#define	IDWA_089	2938	//	동북아의 허브도시 인천광역시입니다
#define	IDWA_090	2939	//	"21세기 세계 도시, 대구광역시입니다"
#define	IDWA_091	2940	//	살기 좋은 도시 울산광역시입니다
#define	IDWA_092	2941	//	첨단산업문화의 수도 광주광역시입니다
#define	IDWA_093	2942	//	과학과 미래의 도시 대전광역시입니다
#define	IDW_0000100_W	2943	//	100
#define	IDW_0000150_W	2944	//	150
#define	IDW_0000200_W	2945	//	200
#define	IDW_0000250_W	2946	//	250
#define	IDW_0000300_W	2947	//	300
#define	IDW_0000350_W	2948	//	350
#define	IDW_0000400_W	2949	//	400
#define	IDW_0000450_W	2950	//	450
#define	IDW_0000500_W	2951	//	500
#define	IDW_0000550_W	2952	//	550
#define	IDW_0000600_W	2953	//	600
#define	IDW_0000650_W	2954	//	650
#define	IDW_0000700_W	2955	//	700
#define	IDW_0000750_W	2956	//	750
#define	IDW_0000800_W	2957	//	800
#define	IDW_0000850_W	2958	//	850
#define	IDW_0000900_W	2959	//	900
#define	IDW_0000950_W	2960	//	950
#define	IDW_0001000_W	2961	//	1000
#define	IDW_0001050_W	2962	//	1050
#define	IDW_0001100_W	2963	//	1100
#define	IDW_0001150_W	2964	//	1150
#define	IDW_0001200_W	2965	//	1200
#define	IDW_0001250_W	2966	//	1250
#define	IDW_0001300_W	2967	//	1300
#define	IDW_0001350_W	2968	//	1350
#define	IDW_0001400_W	2969	//	1400
#define	IDW_0001450_W	2970	//	1450
#define	IDW_0001500_W	2971	//	1500
#define	IDW_0001550_W	2972	//	1550
#define	IDW_0001600_W	2973	//	1600
#define	IDW_0001650_W	2974	//	1650
#define	IDW_0001700_W	2975	//	1700
#define	IDW_0001750_W	2976	//	1750
#define	IDW_0001800_W	2977	//	1800
#define	IDW_0001850_W	2978	//	1850
#define	IDW_0001900_W	2979	//	1900
#define	IDW_0001950_W	2980	//	1950
#define	IDW_0002000_W	2981	//	2000
#define	IDW_0002050_W	2982	//	2050
#define	IDW_0002100_W	2983	//	2100
#define	IDW_0002150_W	2984	//	2150
#define	IDW_0002200_W	2985	//	2200
#define	IDW_0002250_W	2986	//	2250
#define	IDW_0002300_W	2987	//	2300
#define	IDW_0002350_W	2988	//	2350
#define	IDW_0002400_W	2989	//	2400
#define	IDW_0002450_W	2990	//	2450
#define	IDW_0002500_W	2991	//	2500
#define	IDW_0002550_W	2992	//	2550
#define	IDW_0002600_W	2993	//	2600
#define	IDW_0002650_W	2994	//	2650
#define	IDW_0002700_W	2995	//	2700
#define	IDW_0002750_W	2996	//	2750
#define	IDW_0002800_W	2997	//	2800
#define	IDW_0002850_W	2998	//	2850
#define	IDW_0002900_W	2999	//	2900
#define	IDW_0002950_W	3000	//	2950
#define	IDW_0003000_W	3001	//	3000
#define	IDW_0003050_W	3002	//	3050
#define	IDW_0003100_W	3003	//	3100
#define	IDW_0003150_W	3004	//	3150
#define	IDW_0003200_W	3005	//	3200
#define	IDW_0003250_W	3006	//	3250
#define	IDW_0003300_W	3007	//	3300
#define	IDW_0003350_W	3008	//	3350
#define	IDW_0003400_W	3009	//	3400
#define	IDW_0003450_W	3010	//	3450
#define	IDW_0003500_W	3011	//	3500
#define	IDW_0003550_W	3012	//	3550
#define	IDW_0003600_W	3013	//	3600
#define	IDW_0003650_W	3014	//	3650
#define	IDW_0003700_W	3015	//	3700
#define	IDW_0003750_W	3016	//	3750
#define	IDW_0003800_W	3017	//	3800
#define	IDW_0003850_W	3018	//	3850
#define	IDW_0003900_W	3019	//	3900
#define	IDW_0003950_W	3020	//	3950
#define	IDW_0004000_W	3021	//	4000
#define	IDW_0004050_W	3022	//	4050
#define	IDW_0004100_W	3023	//	4100
#define	IDW_0004150_W	3024	//	4150
#define	IDW_0004200_W	3025	//	4200
#define	IDW_0004250_W	3026	//	4250
#define	IDW_0004300_W	3027	//	4300
#define	IDW_0004350_W	3028	//	4350
#define	IDW_0004400_W	3029	//	4400
#define	IDW_0004450_W	3030	//	4450
#define	IDW_0004500_W	3031	//	4500
#define	IDW_0004550_W	3032	//	4550
#define	IDW_0004600_W	3033	//	4600
#define	IDW_0004650_W	3034	//	4650
#define	IDW_0004700_W	3035	//	4700
#define	IDW_0004750_W	3036	//	4750
#define	IDW_0004800_W	3037	//	4800
#define	IDW_0004850_W	3038	//	4850
#define	IDW_0004900_W	3039	//	4900
#define	IDW_0004950_W	3040	//	4950
#define	IDW_0005000_W	3041	//	5000
#define	IDW_0005050_W	3042	//	5050
#define	IDW_0005100_W	3043	//	5100
#define	IDW_0005150_W	3044	//	5150
#define	IDW_0005200_W	3045	//	5200
#define	IDW_0005250_W	3046	//	5250
#define	IDW_0005300_W	3047	//	5300
#define	IDW_0005350_W	3048	//	5350
#define	IDW_0005400_W	3049	//	5400
#define	IDW_0005450_W	3050	//	5450
#define	IDW_0005500_W	3051	//	5500
#define	IDW_0005550_W	3052	//	5550
#define	IDW_0005600_W	3053	//	5600
#define	IDW_0005650_W	3054	//	5650
#define	IDW_0005700_W	3055	//	5700
#define	IDW_0005750_W	3056	//	5750
#define	IDW_0005800_W	3057	//	5800
#define	IDW_0005850_W	3058	//	5850
#define	IDW_0005900_W	3059	//	5900
#define	IDW_0005950_W	3060	//	5950
#define	IDW_0006000_W	3061	//	6000
#define	IDW_0006050_W	3062	//	6050
#define	IDW_0006100_W	3063	//	6100
#define	IDW_0006150_W	3064	//	6150
#define	IDW_0006200_W	3065	//	6200
#define	IDW_0006250_W	3066	//	6250
#define	IDW_0006300_W	3067	//	6300
#define	IDW_0006350_W	3068	//	6350
#define	IDW_0006400_W	3069	//	6400
#define	IDW_0006450_W	3070	//	6450
#define	IDW_0006500_W	3071	//	6500
#define	IDW_0006550_W	3072	//	6550
#define	IDW_0006600_W	3073	//	6600
#define	IDW_0006650_W	3074	//	6650
#define	IDW_0006700_W	3075	//	6700
#define	IDW_0006750_W	3076	//	6750
#define	IDW_0006800_W	3077	//	6800
#define	IDW_0006850_W	3078	//	6850
#define	IDW_0006900_W	3079	//	6900
#define	IDW_0006950_W	3080	//	6950
#define	IDW_0007000_W	3081	//	7000
#define	IDW_0007050_W	3082	//	7050
#define	IDW_0007100_W	3083	//	7100
#define	IDW_0007150_W	3084	//	7150
#define	IDW_0007200_W	3085	//	7200
#define	IDW_0007250_W	3086	//	7250
#define	IDW_0007300_W	3087	//	7300
#define	IDW_0007350_W	3088	//	7350
#define	IDW_0007400_W	3089	//	7400
#define	IDW_0007450_W	3090	//	7450
#define	IDW_0007500_W	3091	//	7500
#define	IDW_0007550_W	3092	//	7550
#define	IDW_0007600_W	3093	//	7600
#define	IDW_0007650_W	3094	//	7650
#define	IDW_0007700_W	3095	//	7700
#define	IDW_0007750_W	3096	//	7750
#define	IDW_0007800_W	3097	//	7800
#define	IDW_0007850_W	3098	//	7850
#define	IDW_0007900_W	3099	//	7900
#define	IDW_0007950_W	3100	//	7950
#define	IDW_0008000_W	3101	//	8000
#define	IDW_0008050_W	3102	//	8050
#define	IDW_0008100_W	3103	//	8100
#define	IDW_0008150_W	3104	//	8150
#define	IDW_0008200_W	3105	//	8200
#define	IDW_0008250_W	3106	//	8250
#define	IDW_0008300_W	3107	//	8300
#define	IDW_0008350_W	3108	//	8350
#define	IDW_0008400_W	3109	//	8400
#define	IDW_0008450_W	3110	//	8450
#define	IDW_0008500_W	3111	//	8500
#define	IDW_0008550_W	3112	//	8550
#define	IDW_0008600_W	3113	//	8600
#define	IDW_0008650_W	3114	//	8650
#define	IDW_0008700_W	3115	//	8700
#define	IDW_0008750_W	3116	//	8750
#define	IDW_0008800_W	3117	//	8800
#define	IDW_0008850_W	3118	//	8850
#define	IDW_0008900_W	3119	//	8900
#define	IDW_0008950_W	3120	//	8950
#define	IDW_0009000_W	3121	//	9000
#define	IDW_0009050_W	3122	//	9050
#define	IDW_0009100_W	3123	//	9100
#define	IDW_0009150_W	3124	//	9150
#define	IDW_0009200_W	3125	//	9200
#define	IDW_0009250_W	3126	//	9250
#define	IDW_0009300_W	3127	//	9300
#define	IDW_0009350_W	3128	//	9350
#define	IDW_0009400_W	3129	//	9400
#define	IDW_0009450_W	3130	//	9450
#define	IDW_0009500_W	3131	//	9500
#define	IDW_0009550_W	3132	//	9550
#define	IDW_0009600_W	3133	//	9600
#define	IDW_0009650_W	3134	//	9650
#define	IDW_0009700_W	3135	//	9700
#define	IDW_0009750_W	3136	//	9750
#define	IDW_0009800_W	3137	//	9800
#define	IDW_0009850_W	3138	//	9850
#define	IDW_0009900_W	3139	//	9900
#define	IDW_0009950_W	3140	//	9950
#define	IDW_0010000_W	3141	//	10000
#define	IDW_0010050_W	3142	//	10050
#define	IDW_0010100_W	3143	//	10100
#define	IDW_0010150_W	3144	//	10150
#define	IDW_0010200_W	3145	//	10200
#define	IDW_0010250_W	3146	//	10250
#define	IDW_0010300_W	3147	//	10300
#define	IDW_0010350_W	3148	//	10350
#define	IDW_0010400_W	3149	//	10400
#define	IDW_0010450_W	3150	//	10450
#define	IDW_0010500_W	3151	//	10500
#define	IDW_0010550_W	3152	//	10550
#define	IDW_0010600_W	3153	//	10600
#define	IDW_0010650_W	3154	//	10650
#define	IDW_0010700_W	3155	//	10700
#define	IDW_0010750_W	3156	//	10750
#define	IDW_0010800_W	3157	//	10800
#define	IDW_0010850_W	3158	//	10850
#define	IDW_0010900_W	3159	//	10900
#define	IDW_0010950_W	3160	//	10950
#define	IDW_0011000_W	3161	//	11000
#define	IDW_0011050_W	3162	//	11050
#define	IDW_0011100_W	3163	//	11100
#define	IDW_0011150_W	3164	//	11150
#define	IDW_0011200_W	3165	//	11200
#define	IDW_0011250_W	3166	//	11250
#define	IDW_0011300_W	3167	//	11300
#define	IDW_0011350_W	3168	//	11350
#define	IDW_0011400_W	3169	//	11400
#define	IDW_0011450_W	3170	//	11450
#define	IDW_0011500_W	3171	//	11500
#define	IDW_0011550_W	3172	//	11550
#define	IDW_0011600_W	3173	//	11600
#define	IDW_0011650_W	3174	//	11650
#define	IDW_0011700_W	3175	//	11700
#define	IDW_0011750_W	3176	//	11750
#define	IDW_0011800_W	3177	//	11800
#define	IDW_0011850_W	3178	//	11850
#define	IDW_0011900_W	3179	//	11900
#define	IDW_0011950_W	3180	//	11950
#define	IDW_0012000_W	3181	//	12000
#define	IDW_0012050_W	3182	//	12050
#define	IDW_0012100_W	3183	//	12100
#define	IDW_0012150_W	3184	//	12150
#define	IDW_0012200_W	3185	//	12200
#define	IDW_0012250_W	3186	//	12250
#define	IDW_0012300_W	3187	//	12300
#define	IDW_0012350_W	3188	//	12350
#define	IDW_0012400_W	3189	//	12400
#define	IDW_0012450_W	3190	//	12450
#define	IDW_0012500_W	3191	//	12500
#define	IDW_0012550_W	3192	//	12550
#define	IDW_0012600_W	3193	//	12600
#define	IDW_0012650_W	3194	//	12650
#define	IDW_0012700_W	3195	//	12700
#define	IDW_0012750_W	3196	//	12750
#define	IDW_0012800_W	3197	//	12800
#define	IDW_0012850_W	3198	//	12850
#define	IDW_0012900_W	3199	//	12900
#define	IDW_0012950_W	3200	//	12950
#define	IDW_0013000_W	3201	//	13000
#define	IDW_0013050_W	3202	//	13050
#define	IDW_0013100_W	3203	//	13100
#define	IDW_0013150_W	3204	//	13150
#define	IDW_0013200_W	3205	//	13200
#define	IDW_0013250_W	3206	//	13250
#define	IDW_0013300_W	3207	//	13300
#define	IDW_0013350_W	3208	//	13350
#define	IDW_0013400_W	3209	//	13400
#define	IDW_0013450_W	3210	//	13450
#define	IDW_0013500_W	3211	//	13500
#define	IDW_0013550_W	3212	//	13550
#define	IDW_0013600_W	3213	//	13600
#define	IDW_0013650_W	3214	//	13650
#define	IDW_0013700_W	3215	//	13700
#define	IDW_0013750_W	3216	//	13750
#define	IDW_0013800_W	3217	//	13800
#define	IDW_0013850_W	3218	//	13850
#define	IDW_0013900_W	3219	//	13900
#define	IDW_0013950_W	3220	//	13950
#define	IDW_0014000_W	3221	//	14000
#define	IDW_0014050_W	3222	//	14050
#define	IDW_0014100_W	3223	//	14100
#define	IDW_0014150_W	3224	//	14150
#define	IDW_0014200_W	3225	//	14200
#define	IDW_0014250_W	3226	//	14250
#define	IDW_0014300_W	3227	//	14300
#define	IDW_0014350_W	3228	//	14350
#define	IDW_0014400_W	3229	//	14400
#define	IDW_0014450_W	3230	//	14450
#define	IDW_0014500_W	3231	//	14500
#define	IDW_0014550_W	3232	//	14550
#define	IDW_0014600_W	3233	//	14600
#define	IDW_0014650_W	3234	//	14650
#define	IDW_0014700_W	3235	//	14700
#define	IDW_0014750_W	3236	//	14750
#define	IDW_0014800_W	3237	//	14800
#define	IDW_0014850_W	3238	//	14850
#define	IDW_0014900_W	3239	//	14900
#define	IDW_0014950_W	3240	//	14950
#define	IDW_0015000_W	3241	//	15000
#define	IDW_0015050_W	3242	//	15050
#define	IDW_0015100_W	3243	//	15100
#define	IDW_0015150_W	3244	//	15150
#define	IDW_0015200_W	3245	//	15200
#define	IDW_0015250_W	3246	//	15250
#define	IDW_0015300_W	3247	//	15300
#define	IDW_0015350_W	3248	//	15350
#define	IDW_0015400_W	3249	//	15400
#define	IDW_0015450_W	3250	//	15450
#define	IDW_0015500_W	3251	//	15500
#define	IDW_0015550_W	3252	//	15550
#define	IDW_0015600_W	3253	//	15600
#define	IDW_0015650_W	3254	//	15650
#define	IDW_0015700_W	3255	//	15700
#define	IDW_0015750_W	3256	//	15750
#define	IDW_0015800_W	3257	//	15800
#define	IDW_0015850_W	3258	//	15850
#define	IDW_0015900_W	3259	//	15900
#define	IDW_0015950_W	3260	//	15950
#define	IDW_0016000_W	3261	//	16000
#define	IDW_0016050_W	3262	//	16050
#define	IDW_0016100_W	3263	//	16100
#define	IDW_0016150_W	3264	//	16150
#define	IDW_0016200_W	3265	//	16200
#define	IDW_0016250_W	3266	//	16250
#define	IDW_0016300_W	3267	//	16300
#define	IDW_0016350_W	3268	//	16350
#define	IDW_0016400_W	3269	//	16400
#define	IDW_0016450_W	3270	//	16450
#define	IDW_0016500_W	3271	//	16500
#define	IDW_0016550_W	3272	//	16550
#define	IDW_0016600_W	3273	//	16600
#define	IDW_0016650_W	3274	//	16650
#define	IDW_0016700_W	3275	//	16700
#define	IDW_0016750_W	3276	//	16750
#define	IDW_0016800_W	3277	//	16800
#define	IDW_0016850_W	3278	//	16850
#define	IDW_0016900_W	3279	//	16900
#define	IDW_0016950_W	3280	//	16950
#define	IDW_0017000_W	3281	//	17000
#define	IDW_0017050_W	3282	//	17050
#define	IDW_0017100_W	3283	//	17100
#define	IDW_0017150_W	3284	//	17150
#define	IDW_0017200_W	3285	//	17200
#define	IDW_0017250_W	3286	//	17250
#define	IDW_0017300_W	3287	//	17300
#define	IDW_0017350_W	3288	//	17350
#define	IDW_0017400_W	3289	//	17400
#define	IDW_0017450_W	3290	//	17450
#define	IDW_0017500_W	3291	//	17500
#define	IDW_0017550_W	3292	//	17550
#define	IDW_0017600_W	3293	//	17600
#define	IDW_0017650_W	3294	//	17650
#define	IDW_0017700_W	3295	//	17700
#define	IDW_0017750_W	3296	//	17750
#define	IDW_0017800_W	3297	//	17800
#define	IDW_0017850_W	3298	//	17850
#define	IDW_0017900_W	3299	//	17900
#define	IDW_0017950_W	3300	//	17950
#define	IDW_0018000_W	3301	//	18000
#define	IDW_0018050_W	3302	//	18050
#define	IDW_0018100_W	3303	//	18100
#define	IDW_0018150_W	3304	//	18150
#define	IDW_0018200_W	3305	//	18200
#define	IDW_0018250_W	3306	//	18250
#define	IDW_0018300_W	3307	//	18300
#define	IDW_0018350_W	3308	//	18350
#define	IDW_0018400_W	3309	//	18400
#define	IDW_0018450_W	3310	//	18450
#define	IDW_0018500_W	3311	//	18500
#define	IDW_0018550_W	3312	//	18550
#define	IDW_0018600_W	3313	//	18600
#define	IDW_0018650_W	3314	//	18650
#define	IDW_0018700_W	3315	//	18700
#define	IDW_0018750_W	3316	//	18750
#define	IDW_0018800_W	3317	//	18800
#define	IDW_0018850_W	3318	//	18850
#define	IDW_0018900_W	3319	//	18900
#define	IDW_0018950_W	3320	//	18950
#define	IDW_0019000_W	3321	//	19000
#define	IDW_0019050_W	3322	//	19050
#define	IDW_0019100_W	3323	//	19100
#define	IDW_0019150_W	3324	//	19150
#define	IDW_0019200_W	3325	//	19200
#define	IDW_0019250_W	3326	//	19250
#define	IDW_0019300_W	3327	//	19300
#define	IDW_0019350_W	3328	//	19350
#define	IDW_0019400_W	3329	//	19400
#define	IDW_0019450_W	3330	//	19450
#define	IDW_0019500_W	3331	//	19500
#define	IDW_0019550_W	3332	//	19550
#define	IDW_0019600_W	3333	//	19600
#define	IDW_0019650_W	3334	//	19650
#define	IDW_0019700_W	3335	//	19700
#define	IDW_0019750_W	3336	//	19750
#define	IDW_0019800_W	3337	//	19800
#define	IDW_0019850_W	3338	//	19850
#define	IDW_0019900_W	3339	//	19900
#define	IDW_0019950_W	3340	//	19950
#define	IDW_0020000_W	3341	//	20000
#define	IDW_0020050_W	3342	//	20050
#define	IDW_0020100_W	3343	//	20100
#define	IDW_0020150_W	3344	//	20150
#define	IDW_0020200_W	3345	//	20200
#define	IDW_0020250_W	3346	//	20250
#define	IDW_0020300_W	3347	//	20300
#define	IDW_0020350_W	3348	//	20350
#define	IDW_0020400_W	3349	//	20400
#define	IDW_0020450_W	3350	//	20450
#define	IDW_0020500_W	3351	//	20500
#define	IDW_0020550_W	3352	//	20550
#define	IDW_0020600_W	3353	//	20600
#define	IDW_0020650_W	3354	//	20650
#define	IDW_0020700_W	3355	//	20700
#define	IDW_0020750_W	3356	//	20750
#define	IDW_0020800_W	3357	//	20800
#define	IDW_0020850_W	3358	//	20850
#define	IDW_0020900_W	3359	//	20900
#define	IDW_0020950_W	3360	//	20950
#define	IDW_0021000_W	3361	//	21000
#define	IDW_0021050_W	3362	//	21050
#define	IDW_0021100_W	3363	//	21100
#define	IDW_0021150_W	3364	//	21150
#define	IDW_0021200_W	3365	//	21200
#define	IDW_0021250_W	3366	//	21250
#define	IDW_0021300_W	3367	//	21300
#define	IDW_0021350_W	3368	//	21350
#define	IDW_0021400_W	3369	//	21400
#define	IDW_0021450_W	3370	//	21450
#define	IDW_0021500_W	3371	//	21500
#define	IDW_0021550_W	3372	//	21550
#define	IDW_0021600_W	3373	//	21600
#define	IDW_0021650_W	3374	//	21650
#define	IDW_0021700_W	3375	//	21700
#define	IDW_0021750_W	3376	//	21750
#define	IDW_0021800_W	3377	//	21800
#define	IDW_0021850_W	3378	//	21850
#define	IDW_0021900_W	3379	//	21900
#define	IDW_0021950_W	3380	//	21950
#define	IDW_0022000_W	3381	//	22000
#define	IDW_0022050_W	3382	//	22050
#define	IDW_0022100_W	3383	//	22100
#define	IDW_0022150_W	3384	//	22150
#define	IDW_0022200_W	3385	//	22200
#define	IDW_0022250_W	3386	//	22250
#define	IDW_0022300_W	3387	//	22300
#define	IDW_0022350_W	3388	//	22350
#define	IDW_0022400_W	3389	//	22400
#define	IDW_0022450_W	3390	//	22450
#define	IDW_0022500_W	3391	//	22500
#define	IDW_0022550_W	3392	//	22550
#define	IDW_0022600_W	3393	//	22600
#define	IDW_0022650_W	3394	//	22650
#define	IDW_0022700_W	3395	//	22700
#define	IDW_0022750_W	3396	//	22750
#define	IDW_0022800_W	3397	//	22800
#define	IDW_0022850_W	3398	//	22850
#define	IDW_0022900_W	3399	//	22900
#define	IDW_0022950_W	3400	//	22950
#define	IDW_0023000_W	3401	//	23000
#define	IDW_0023050_W	3402	//	23050
#define	IDW_0023100_W	3403	//	23100
#define	IDW_0023150_W	3404	//	23150
#define	IDW_0023200_W	3405	//	23200
#define	IDW_0023250_W	3406	//	23250
#define	IDW_0023300_W	3407	//	23300
#define	IDW_0023350_W	3408	//	23350
#define	IDW_0023400_W	3409	//	23400
#define	IDW_0023450_W	3410	//	23450
#define	IDW_0023500_W	3411	//	23500
#define	IDW_0023550_W	3412	//	23550
#define	IDW_0023600_W	3413	//	23600
#define	IDW_0023650_W	3414	//	23650
#define	IDW_0023700_W	3415	//	23700
#define	IDW_0023750_W	3416	//	23750
#define	IDW_0023800_W	3417	//	23800
#define	IDW_0023850_W	3418	//	23850
#define	IDW_0023900_W	3419	//	23900
#define	IDW_0023950_W	3420	//	23950
#define	IDW_0024000_W	3421	//	24000
#define	IDW_0024050_W	3422	//	24050
#define	IDW_0024100_W	3423	//	24100
#define	IDW_0024150_W	3424	//	24150
#define	IDW_0024200_W	3425	//	24200
#define	IDW_0024250_W	3426	//	24250
#define	IDW_0024300_W	3427	//	24300
#define	IDW_0024350_W	3428	//	24350
#define	IDW_0024400_W	3429	//	24400
#define	IDW_0024450_W	3430	//	24450
#define	IDW_0024500_W	3431	//	24500
#define	IDW_0024550_W	3432	//	24550
#define	IDW_0024600_W	3433	//	24600
#define	IDW_0024650_W	3434	//	24650
#define	IDW_0024700_W	3435	//	24700
#define	IDW_0024750_W	3436	//	24750
#define	IDW_0024800_W	3437	//	24800
#define	IDW_0024850_W	3438	//	24850
#define	IDW_0024900_W	3439	//	24900
#define	IDW_0024950_W	3440	//	24950
#define	IDW_0025000_W	3441	//	25000
#define	IDW_0025050_W	3442	//	25050
#define	IDW_0025100_W	3443	//	25100
#define	IDW_0025150_W	3444	//	25150
#define	IDW_0025200_W	3445	//	25200
#define	IDW_0025250_W	3446	//	25250
#define	IDW_0025300_W	3447	//	25300
#define	IDW_0025350_W	3448	//	25350
#define	IDW_0025400_W	3449	//	25400
#define	IDW_0025450_W	3450	//	25450
#define	IDW_0025500_W	3451	//	25500
#define	IDW_0025550_W	3452	//	25550
#define	IDW_0025600_W	3453	//	25600
#define	IDW_0025650_W	3454	//	25650
#define	IDW_0025700_W	3455	//	25700
#define	IDW_0025750_W	3456	//	25750
#define	IDW_0025800_W	3457	//	25800
#define	IDW_0025850_W	3458	//	25850
#define	IDW_0025900_W	3459	//	25900
#define	IDW_0025950_W	3460	//	25950
#define	IDW_0026000_W	3461	//	26000
#define	IDW_0026050_W	3462	//	26050
#define	IDW_0026100_W	3463	//	26100
#define	IDW_0026150_W	3464	//	26150
#define	IDW_0026200_W	3465	//	26200
#define	IDW_0026250_W	3466	//	26250
#define	IDW_0026300_W	3467	//	26300
#define	IDW_0026350_W	3468	//	26350
#define	IDW_0026400_W	3469	//	26400
#define	IDW_0026450_W	3470	//	26450
#define	IDW_0026500_W	3471	//	26500
#define	IDW_0026550_W	3472	//	26550
#define	IDW_0026600_W	3473	//	26600
#define	IDW_0026650_W	3474	//	26650
#define	IDW_0026700_W	3475	//	26700
#define	IDW_0026750_W	3476	//	26750
#define	IDW_0026800_W	3477	//	26800
#define	IDW_0026850_W	3478	//	26850
#define	IDW_0026900_W	3479	//	26900
#define	IDW_0026950_W	3480	//	26950
#define	IDW_0027000_W	3481	//	27000
#define	IDW_0027050_W	3482	//	27050
#define	IDW_0027100_W	3483	//	27100
#define	IDW_0027150_W	3484	//	27150
#define	IDW_0027200_W	3485	//	27200
#define	IDW_0027250_W	3486	//	27250
#define	IDW_0027300_W	3487	//	27300
#define	IDW_0027350_W	3488	//	27350
#define	IDW_0027400_W	3489	//	27400
#define	IDW_0027450_W	3490	//	27450
#define	IDW_0027500_W	3491	//	27500
#define	IDW_0027550_W	3492	//	27550
#define	IDW_0027600_W	3493	//	27600
#define	IDW_0027650_W	3494	//	27650
#define	IDW_0027700_W	3495	//	27700
#define	IDW_0027750_W	3496	//	27750
#define	IDW_0027800_W	3497	//	27800
#define	IDW_0027850_W	3498	//	27850
#define	IDW_0027900_W	3499	//	27900
#define	IDW_0027950_W	3500	//	27950
#define	IDW_0028000_W	3501	//	28000
#define	IDW_0028050_W	3502	//	28050
#define	IDW_0028100_W	3503	//	28100
#define	IDW_0028150_W	3504	//	28150
#define	IDW_0028200_W	3505	//	28200
#define	IDW_0028250_W	3506	//	28250
#define	IDW_0028300_W	3507	//	28300
#define	IDW_0028350_W	3508	//	28350
#define	IDW_0028400_W	3509	//	28400
#define	IDW_0028450_W	3510	//	28450
#define	IDW_0028500_W	3511	//	28500
#define	IDW_0028550_W	3512	//	28550
#define	IDW_0028600_W	3513	//	28600
#define	IDW_0028650_W	3514	//	28650
#define	IDW_0028700_W	3515	//	28700
#define	IDW_0028750_W	3516	//	28750
#define	IDW_0028800_W	3517	//	28800
#define	IDW_0028850_W	3518	//	28850
#define	IDW_0028900_W	3519	//	28900
#define	IDW_0028950_W	3520	//	28950
#define	IDW_0029000_W	3521	//	29000
#define	IDW_0029050_W	3522	//	29050
#define	IDW_0029100_W	3523	//	29100
#define	IDW_0029150_W	3524	//	29150
#define	IDW_0029200_W	3525	//	29200
#define	IDW_0029250_W	3526	//	29250
#define	IDW_0029300_W	3527	//	29300
#define	IDW_0029350_W	3528	//	29350
#define	IDW_0029400_W	3529	//	29400
#define	IDW_0029450_W	3530	//	29450
#define	IDW_0029500_W	3531	//	29500
#define	IDW_0029550_W	3532	//	29550
#define	IDW_0029600_W	3533	//	29600
#define	IDW_0029650_W	3534	//	29650
#define	IDW_0029700_W	3535	//	29700
#define	IDW_0029750_W	3536	//	29750
#define	IDW_0029800_W	3537	//	29800
#define	IDW_0029850_W	3538	//	29850
#define	IDW_0029900_W	3539	//	29900
#define	IDW_0029950_W	3540	//	29950
#define	IDW_0030000_W	3541	//	30000
#define	IDW_0030050_W	3542	//	30050
#define	IDW_0030100_W	3543	//	30100
#define	IDW_0030150_W	3544	//	30150
#define	IDW_0030200_W	3545	//	30200
#define	IDW_0030250_W	3546	//	30250
#define	IDW_0030300_W	3547	//	30300
#define	IDW_0030350_W	3548	//	30350
#define	IDW_0030400_W	3549	//	30400
#define	IDW_0030450_W	3550	//	30450
#define	IDW_0030500_W	3551	//	30500
#define	IDW_0030550_W	3552	//	30550
#define	IDW_0030600_W	3553	//	30600
#define	IDW_0030650_W	3554	//	30650
#define	IDW_0030700_W	3555	//	30700
#define	IDW_0030750_W	3556	//	30750
#define	IDW_0030800_W	3557	//	30800
#define	IDW_0030850_W	3558	//	30850
#define	IDW_0030900_W	3559	//	30900
#define	IDW_0030950_W	3560	//	30950
#define	IDW_0031000_W	3561	//	31000
#define	IDW_0031050_W	3562	//	31050
#define	IDW_0031100_W	3563	//	31100
#define	IDW_0031150_W	3564	//	31150
#define	IDW_0031200_W	3565	//	31200
#define	IDW_0031250_W	3566	//	31250
#define	IDW_0031300_W	3567	//	31300
#define	IDW_0031350_W	3568	//	31350
#define	IDW_0031400_W	3569	//	31400
#define	IDW_0031450_W	3570	//	31450
#define	IDW_0031500_W	3571	//	31500
#define	IDW_0031550_W	3572	//	31550
#define	IDW_0031600_W	3573	//	31600
#define	IDW_0031650_W	3574	//	31650
#define	IDW_0031700_W	3575	//	31700
#define	IDW_0031750_W	3576	//	31750
#define	IDW_0031800_W	3577	//	31800
#define	IDW_0031850_W	3578	//	31850
#define	IDW_0031900_W	3579	//	31900
#define	IDW_0031950_W	3580	//	31950
#define	IDW_0032000_W	3581	//	32000
#define	IDW_0032050_W	3582	//	32050
#define	IDW_0032100_W	3583	//	32100
#define	IDW_0032150_W	3584	//	32150
#define	IDW_0032200_W	3585	//	32200
#define	IDW_0032250_W	3586	//	32250
#define	IDW_0032300_W	3587	//	32300
#define	IDW_0032350_W	3588	//	32350
#define	IDW_0032400_W	3589	//	32400
#define	IDW_0032450_W	3590	//	32450
#define	IDW_0032500_W	3591	//	32500
#define	IDW_0032550_W	3592	//	32550
#define	IDW_0032600_W	3593	//	32600
#define	IDW_0032650_W	3594	//	32650
#define	IDW_0032700_W	3595	//	32700
#define	IDW_0032750_W	3596	//	32750
#define	IDW_0032800_W	3597	//	32800
#define	IDW_0032850_W	3598	//	32850
#define	IDW_0032900_W	3599	//	32900
#define	IDW_0032950_W	3600	//	32950
#define	IDW_0033000_W	3601	//	33000
#define	IDW_0033050_W	3602	//	33050
#define	IDW_0033100_W	3603	//	33100
#define	IDW_0033150_W	3604	//	33150
#define	IDW_0033200_W	3605	//	33200
#define	IDW_0033250_W	3606	//	33250
#define	IDW_0033300_W	3607	//	33300
#define	IDW_0033350_W	3608	//	33350
#define	IDW_0033400_W	3609	//	33400
#define	IDW_0033450_W	3610	//	33450
#define	IDW_0033500_W	3611	//	33500
#define	IDW_0033550_W	3612	//	33550
#define	IDW_0033600_W	3613	//	33600
#define	IDW_0033650_W	3614	//	33650
#define	IDW_0033700_W	3615	//	33700
#define	IDW_0033750_W	3616	//	33750
#define	IDW_0033800_W	3617	//	33800
#define	IDW_0033850_W	3618	//	33850
#define	IDW_0033900_W	3619	//	33900
#define	IDW_0033950_W	3620	//	33950
#define	IDW_0034000_W	3621	//	34000
#define	IDW_0034050_W	3622	//	34050
#define	IDW_0034100_W	3623	//	34100
#define	IDW_0034150_W	3624	//	34150
#define	IDW_0034200_W	3625	//	34200
#define	IDW_0034250_W	3626	//	34250
#define	IDW_0034300_W	3627	//	34300
#define	IDW_0034350_W	3628	//	34350
#define	IDW_0034400_W	3629	//	34400
#define	IDW_0034450_W	3630	//	34450
#define	IDW_0034500_W	3631	//	34500
#define	IDW_0034550_W	3632	//	34550
#define	IDW_0034600_W	3633	//	34600
#define	IDW_0034650_W	3634	//	34650
#define	IDW_0034700_W	3635	//	34700
#define	IDW_0034750_W	3636	//	34750
#define	IDW_0034800_W	3637	//	34800
#define	IDW_0034850_W	3638	//	34850
#define	IDW_0034900_W	3639	//	34900
#define	IDW_0034950_W	3640	//	34950
#define	IDW_0035000_W	3641	//	35000
#define	IDW_0035050_W	3642	//	35050
#define	IDW_0035100_W	3643	//	35100
#define	IDW_0035150_W	3644	//	35150
#define	IDW_0035200_W	3645	//	35200
#define	IDW_0035250_W	3646	//	35250
#define	IDW_0035300_W	3647	//	35300
#define	IDW_0035350_W	3648	//	35350
#define	IDW_0035400_W	3649	//	35400
#define	IDW_0035450_W	3650	//	35450
#define	IDW_0035500_W	3651	//	35500
#define	IDW_0035550_W	3652	//	35550
#define	IDW_0035600_W	3653	//	35600
#define	IDW_0035650_W	3654	//	35650
#define	IDW_0035700_W	3655	//	35700
#define	IDW_0035750_W	3656	//	35750
#define	IDW_0035800_W	3657	//	35800
#define	IDW_0035850_W	3658	//	35850
#define	IDW_0035900_W	3659	//	35900
#define	IDW_0035950_W	3660	//	35950
#define	IDW_0036000_W	3661	//	36000
#define	IDW_0036050_W	3662	//	36050
#define	IDW_0036100_W	3663	//	36100
#define	IDW_0036150_W	3664	//	36150
#define	IDW_0036200_W	3665	//	36200
#define	IDW_0036250_W	3666	//	36250
#define	IDW_0036300_W	3667	//	36300
#define	IDW_0036350_W	3668	//	36350
#define	IDW_0036400_W	3669	//	36400
#define	IDW_0036450_W	3670	//	36450
#define	IDW_0036500_W	3671	//	36500
#define	IDW_0036550_W	3672	//	36550
#define	IDW_0036600_W	3673	//	36600
#define	IDW_0036650_W	3674	//	36650
#define	IDW_0036700_W	3675	//	36700
#define	IDW_0036750_W	3676	//	36750
#define	IDW_0036800_W	3677	//	36800
#define	IDW_0036850_W	3678	//	36850
#define	IDW_0036900_W	3679	//	36900
#define	IDW_0036950_W	3680	//	36950
#define	IDW_0037000_W	3681	//	37000
#define	IDW_0037050_W	3682	//	37050
#define	IDW_0037100_W	3683	//	37100
#define	IDW_0037150_W	3684	//	37150
#define	IDW_0037200_W	3685	//	37200
#define	IDW_0037250_W	3686	//	37250
#define	IDW_0037300_W	3687	//	37300
#define	IDW_0037350_W	3688	//	37350
#define	IDW_0037400_W	3689	//	37400
#define	IDW_0037450_W	3690	//	37450
#define	IDW_0037500_W	3691	//	37500
#define	IDW_0037550_W	3692	//	37550
#define	IDW_0037600_W	3693	//	37600
#define	IDW_0037650_W	3694	//	37650
#define	IDW_0037700_W	3695	//	37700
#define	IDW_0037750_W	3696	//	37750
#define	IDW_0037800_W	3697	//	37800
#define	IDW_0037850_W	3698	//	37850
#define	IDW_0037900_W	3699	//	37900
#define	IDW_0037950_W	3700	//	37950
#define	IDW_0038000_W	3701	//	38000
#define	IDW_0038050_W	3702	//	38050
#define	IDW_0038100_W	3703	//	38100
#define	IDW_0038150_W	3704	//	38150
#define	IDW_0038200_W	3705	//	38200
#define	IDW_0038250_W	3706	//	38250
#define	IDW_0038300_W	3707	//	38300
#define	IDW_0038350_W	3708	//	38350
#define	IDW_0038400_W	3709	//	38400
#define	IDW_0038450_W	3710	//	38450
#define	IDW_0038500_W	3711	//	38500
#define	IDW_0038550_W	3712	//	38550
#define	IDW_0038600_W	3713	//	38600
#define	IDW_0038650_W	3714	//	38650
#define	IDW_0038700_W	3715	//	38700
#define	IDW_0038750_W	3716	//	38750
#define	IDW_0038800_W	3717	//	38800
#define	IDW_0038850_W	3718	//	38850
#define	IDW_0038900_W	3719	//	38900
#define	IDW_0038950_W	3720	//	38950
#define	IDW_0039000_W	3721	//	39000
#define	IDW_0039050_W	3722	//	39050
#define	IDW_0039100_W	3723	//	39100
#define	IDW_0039150_W	3724	//	39150
#define	IDW_0039200_W	3725	//	39200
#define	IDW_0039250_W	3726	//	39250
#define	IDW_0039300_W	3727	//	39300
#define	IDW_0039350_W	3728	//	39350
#define	IDW_0039400_W	3729	//	39400
#define	IDW_0039450_W	3730	//	39450
#define	IDW_0039500_W	3731	//	39500
#define	IDW_0039550_W	3732	//	39550
#define	IDW_0039600_W	3733	//	39600
#define	IDW_0039650_W	3734	//	39650
#define	IDW_0039700_W	3735	//	39700
#define	IDW_0039750_W	3736	//	39750
#define	IDW_0039800_W	3737	//	39800
#define	IDW_0039850_W	3738	//	39850
#define	IDW_0039900_W	3739	//	39900
#define	IDW_0039950_W	3740	//	39950
#define	IDW_0040000_W	3741	//	40000
#define	IDW_0040050_W	3742	//	40050
#define	IDW_0040100_W	3743	//	40100
#define	IDW_0040150_W	3744	//	40150
#define	IDW_0040200_W	3745	//	40200
#define	IDW_0040250_W	3746	//	40250
#define	IDW_0040300_W	3747	//	40300
#define	IDW_0040350_W	3748	//	40350
#define	IDW_0040400_W	3749	//	40400
#define	IDW_0040450_W	3750	//	40450
#define	IDW_0040500_W	3751	//	40500
#define	IDW_0040550_W	3752	//	40550
#define	IDW_0040600_W	3753	//	40600
#define	IDW_0040650_W	3754	//	40650
#define	IDW_0040700_W	3755	//	40700
#define	IDW_0040750_W	3756	//	40750
#define	IDW_0040800_W	3757	//	40800
#define	IDW_0040850_W	3758	//	40850
#define	IDW_0040900_W	3759	//	40900
#define	IDW_0040950_W	3760	//	40950
#define	IDW_0041000_W	3761	//	41000
#define	IDW_0041050_W	3762	//	41050
#define	IDW_0041100_W	3763	//	41100
#define	IDW_0041150_W	3764	//	41150
#define	IDW_0041200_W	3765	//	41200
#define	IDW_0041250_W	3766	//	41250
#define	IDW_0041300_W	3767	//	41300
#define	IDW_0041350_W	3768	//	41350
#define	IDW_0041400_W	3769	//	41400
#define	IDW_0041450_W	3770	//	41450
#define	IDW_0041500_W	3771	//	41500
#define	IDW_0041550_W	3772	//	41550
#define	IDW_0041600_W	3773	//	41600
#define	IDW_0041650_W	3774	//	41650
#define	IDW_0041700_W	3775	//	41700
#define	IDW_0041750_W	3776	//	41750
#define	IDW_0041800_W	3777	//	41800
#define	IDW_0041850_W	3778	//	41850
#define	IDW_0041900_W	3779	//	41900
#define	IDW_0041950_W	3780	//	41950
#define	IDW_0042000_W	3781	//	42000
#define	IDW_0042050_W	3782	//	42050
#define	IDW_0042100_W	3783	//	42100
#define	IDW_0042150_W	3784	//	42150
#define	IDW_0042200_W	3785	//	42200
#define	IDW_0042250_W	3786	//	42250
#define	IDW_0042300_W	3787	//	42300
#define	IDW_0042350_W	3788	//	42350
#define	IDW_0042400_W	3789	//	42400
#define	IDW_0042450_W	3790	//	42450
#define	IDW_0042500_W	3791	//	42500
#define	IDW_0042550_W	3792	//	42550
#define	IDW_0042600_W	3793	//	42600
#define	IDW_0042650_W	3794	//	42650
#define	IDW_0042700_W	3795	//	42700
#define	IDW_0042750_W	3796	//	42750
#define	IDW_0042800_W	3797	//	42800
#define	IDW_0042850_W	3798	//	42850
#define	IDW_0042900_W	3799	//	42900
#define	IDW_0042950_W	3800	//	42950
#define	IDW_0043000_W	3801	//	43000
#define	IDW_0043050_W	3802	//	43050
#define	IDW_0043100_W	3803	//	43100
#define	IDW_0043150_W	3804	//	43150
#define	IDW_0043200_W	3805	//	43200
#define	IDW_0043250_W	3806	//	43250
#define	IDW_0043300_W	3807	//	43300
#define	IDW_0043350_W	3808	//	43350
#define	IDW_0043400_W	3809	//	43400
#define	IDW_0043450_W	3810	//	43450
#define	IDW_0043500_W	3811	//	43500
#define	IDW_0043550_W	3812	//	43550
#define	IDW_0043600_W	3813	//	43600
#define	IDW_0043650_W	3814	//	43650
#define	IDW_0043700_W	3815	//	43700
#define	IDW_0043750_W	3816	//	43750
#define	IDW_0043800_W	3817	//	43800
#define	IDW_0043850_W	3818	//	43850
#define	IDW_0043900_W	3819	//	43900
#define	IDW_0043950_W	3820	//	43950
#define	IDW_0044000_W	3821	//	44000
#define	IDW_0044050_W	3822	//	44050
#define	IDW_0044100_W	3823	//	44100
#define	IDW_0044150_W	3824	//	44150
#define	IDW_0044200_W	3825	//	44200
#define	IDW_0044250_W	3826	//	44250
#define	IDW_0044300_W	3827	//	44300
#define	IDW_0044350_W	3828	//	44350
#define	IDW_0044400_W	3829	//	44400
#define	IDW_0044450_W	3830	//	44450
#define	IDW_0044500_W	3831	//	44500
#define	IDW_0044550_W	3832	//	44550
#define	IDW_0044600_W	3833	//	44600
#define	IDW_0044650_W	3834	//	44650
#define	IDW_0044700_W	3835	//	44700
#define	IDW_0044750_W	3836	//	44750
#define	IDW_0044800_W	3837	//	44800
#define	IDW_0044850_W	3838	//	44850
#define	IDW_0044900_W	3839	//	44900
#define	IDW_0044950_W	3840	//	44950
#define	IDW_0045000_W	3841	//	45000
#define	IDW_0045050_W	3842	//	45050
#define	IDW_0045100_W	3843	//	45100
#define	IDW_0045150_W	3844	//	45150
#define	IDW_0045200_W	3845	//	45200
#define	IDW_0045250_W	3846	//	45250
#define	IDW_0045300_W	3847	//	45300
#define	IDW_0045350_W	3848	//	45350
#define	IDW_0045400_W	3849	//	45400
#define	IDW_0045450_W	3850	//	45450
#define	IDW_0045500_W	3851	//	45500
#define	IDW_0045550_W	3852	//	45550
#define	IDW_0045600_W	3853	//	45600
#define	IDW_0045650_W	3854	//	45650
#define	IDW_0045700_W	3855	//	45700
#define	IDW_0045750_W	3856	//	45750
#define	IDW_0045800_W	3857	//	45800
#define	IDW_0045850_W	3858	//	45850
#define	IDW_0045900_W	3859	//	45900
#define	IDW_0045950_W	3860	//	45950
#define	IDW_0046000_W	3861	//	46000
#define	IDW_0046050_W	3862	//	46050
#define	IDW_0046100_W	3863	//	46100
#define	IDW_0046150_W	3864	//	46150
#define	IDW_0046200_W	3865	//	46200
#define	IDW_0046250_W	3866	//	46250
#define	IDW_0046300_W	3867	//	46300
#define	IDW_0046350_W	3868	//	46350
#define	IDW_0046400_W	3869	//	46400
#define	IDW_0046450_W	3870	//	46450
#define	IDW_0046500_W	3871	//	46500
#define	IDW_0046550_W	3872	//	46550
#define	IDW_0046600_W	3873	//	46600
#define	IDW_0046650_W	3874	//	46650
#define	IDW_0046700_W	3875	//	46700
#define	IDW_0046750_W	3876	//	46750
#define	IDW_0046800_W	3877	//	46800
#define	IDW_0046850_W	3878	//	46850
#define	IDW_0046900_W	3879	//	46900
#define	IDW_0046950_W	3880	//	46950
#define	IDW_0047000_W	3881	//	47000
#define	IDW_0047050_W	3882	//	47050
#define	IDW_0047100_W	3883	//	47100
#define	IDW_0047150_W	3884	//	47150
#define	IDW_0047200_W	3885	//	47200
#define	IDW_0047250_W	3886	//	47250
#define	IDW_0047300_W	3887	//	47300
#define	IDW_0047350_W	3888	//	47350
#define	IDW_0047400_W	3889	//	47400
#define	IDW_0047450_W	3890	//	47450
#define	IDW_0047500_W	3891	//	47500
#define	IDW_0047550_W	3892	//	47550
#define	IDW_0047600_W	3893	//	47600
#define	IDW_0047650_W	3894	//	47650
#define	IDW_0047700_W	3895	//	47700
#define	IDW_0047750_W	3896	//	47750
#define	IDW_0047800_W	3897	//	47800
#define	IDW_0047850_W	3898	//	47850
#define	IDW_0047900_W	3899	//	47900
#define	IDW_0047950_W	3900	//	47950
#define	IDW_0048000_W	3901	//	48000
#define	IDW_0048050_W	3902	//	48050
#define	IDW_0048100_W	3903	//	48100
#define	IDW_0048150_W	3904	//	48150
#define	IDW_0048200_W	3905	//	48200
#define	IDW_0048250_W	3906	//	48250
#define	IDW_0048300_W	3907	//	48300
#define	IDW_0048350_W	3908	//	48350
#define	IDW_0048400_W	3909	//	48400
#define	IDW_0048450_W	3910	//	48450
#define	IDW_0048500_W	3911	//	48500
#define	IDW_0048550_W	3912	//	48550
#define	IDW_0048600_W	3913	//	48600
#define	IDW_0048650_W	3914	//	48650
#define	IDW_0048700_W	3915	//	48700
#define	IDW_0048750_W	3916	//	48750
#define	IDW_0048800_W	3917	//	48800
#define	IDW_0048850_W	3918	//	48850
#define	IDW_0048900_W	3919	//	48900
#define	IDW_0048950_W	3920	//	48950
#define	IDW_0049000_W	3921	//	49000
#define	IDW_0049050_W	3922	//	49050
#define	IDW_0049100_W	3923	//	49100
#define	IDW_0049150_W	3924	//	49150
#define	IDW_0049200_W	3925	//	49200
#define	IDW_0049250_W	3926	//	49250
#define	IDW_0049300_W	3927	//	49300
#define	IDW_0049350_W	3928	//	49350
#define	IDW_0049400_W	3929	//	49400
#define	IDW_0049450_W	3930	//	49450
#define	IDW_0049500_W	3931	//	49500
#define	IDW_0049550_W	3932	//	49550
#define	IDW_0049600_W	3933	//	49600
#define	IDW_0049650_W	3934	//	49650
#define	IDW_0049700_W	3935	//	49700
#define	IDW_0049750_W	3936	//	49750
#define	IDW_0049800_W	3937	//	49800
#define	IDW_0049850_W	3938	//	49850
#define	IDW_0049900_W	3939	//	49900
#define	IDW_0049950_W	3940	//	49950
#define	IDW_0050000_W	3941	//	50000
#define	IDW_0050050_W	3942	//	50050
#define	IDW_0050100_W	3943	//	50100
#define	IDW_0050150_W	3944	//	50150
#define	IDW_0050200_W	3945	//	50200
#define	IDW_0050250_W	3946	//	50250
#define	IDW_0050300_W	3947	//	50300
#define	IDW_0050350_W	3948	//	50350
#define	IDW_0050400_W	3949	//	50400
#define	IDW_0050450_W	3950	//	50450
#define	IDW_0050500_W	3951	//	50500
#define	IDW_0050550_W	3952	//	50550
#define	IDW_0050600_W	3953	//	50600
#define	IDW_0050650_W	3954	//	50650
#define	IDW_0050700_W	3955	//	50700
#define	IDW_0050750_W	3956	//	50750
#define	IDW_0050800_W	3957	//	50800
#define	IDW_0050850_W	3958	//	50850
#define	IDW_0050900_W	3959	//	50900
#define	IDW_0050950_W	3960	//	50950
#define	IDW_0051000_W	3961	//	51000
#define	IDW_0051050_W	3962	//	51050
#define	IDW_0051100_W	3963	//	51100
#define	IDW_0051150_W	3964	//	51150
#define	IDW_0051200_W	3965	//	51200
#define	IDW_0051250_W	3966	//	51250
#define	IDW_0051300_W	3967	//	51300
#define	IDW_0051350_W	3968	//	51350
#define	IDW_0051400_W	3969	//	51400
#define	IDW_0051450_W	3970	//	51450
#define	IDW_0051500_W	3971	//	51500
#define	IDW_0051550_W	3972	//	51550
#define	IDW_0051600_W	3973	//	51600
#define	IDW_0051650_W	3974	//	51650
#define	IDW_0051700_W	3975	//	51700
#define	IDW_0051750_W	3976	//	51750
#define	IDW_0051800_W	3977	//	51800
#define	IDW_0051850_W	3978	//	51850
#define	IDW_0051900_W	3979	//	51900
#define	IDW_0051950_W	3980	//	51950
#define	IDW_0052000_W	3981	//	52000
#define	IDW_0052050_W	3982	//	52050
#define	IDW_0052100_W	3983	//	52100
#define	IDW_0052150_W	3984	//	52150
#define	IDW_0052200_W	3985	//	52200
#define	IDW_0052250_W	3986	//	52250
#define	IDW_0052300_W	3987	//	52300
#define	IDW_0052350_W	3988	//	52350
#define	IDW_0052400_W	3989	//	52400
#define	IDW_0052450_W	3990	//	52450
#define	IDW_0052500_W	3991	//	52500
#define	IDW_0052550_W	3992	//	52550
#define	IDW_0052600_W	3993	//	52600
#define	IDW_0052650_W	3994	//	52650
#define	IDW_0052700_W	3995	//	52700
#define	IDW_0052750_W	3996	//	52750
#define	IDW_0052800_W	3997	//	52800
#define	IDW_0052850_W	3998	//	52850
#define	IDW_0052900_W	3999	//	52900
#define	IDW_0052950_W	4000	//	52950
#define	IDW_0053000_W	4001	//	53000
#define	IDW_0053050_W	4002	//	53050
#define	IDW_0053100_W	4003	//	53100
#define	IDW_0053150_W	4004	//	53150
#define	IDW_0053200_W	4005	//	53200
#define	IDW_0053250_W	4006	//	53250
#define	IDW_0053300_W	4007	//	53300
#define	IDW_0053350_W	4008	//	53350
#define	IDW_0053400_W	4009	//	53400
#define	IDW_0053450_W	4010	//	53450
#define	IDW_0053500_W	4011	//	53500
#define	IDW_0053550_W	4012	//	53550
#define	IDW_0053600_W	4013	//	53600
#define	IDW_0053650_W	4014	//	53650
#define	IDW_0053700_W	4015	//	53700
#define	IDW_0053750_W	4016	//	53750
#define	IDW_0053800_W	4017	//	53800
#define	IDW_0053850_W	4018	//	53850
#define	IDW_0053900_W	4019	//	53900
#define	IDW_0053950_W	4020	//	53950
#define	IDW_0054000_W	4021	//	54000
#define	IDW_0054050_W	4022	//	54050
#define	IDW_0054100_W	4023	//	54100
#define	IDW_0054150_W	4024	//	54150
#define	IDW_0054200_W	4025	//	54200
#define	IDW_0054250_W	4026	//	54250
#define	IDW_0054300_W	4027	//	54300
#define	IDW_0054350_W	4028	//	54350
#define	IDW_0054400_W	4029	//	54400
#define	IDW_0054450_W	4030	//	54450
#define	IDW_0054500_W	4031	//	54500
#define	IDW_0054550_W	4032	//	54550
#define	IDW_0054600_W	4033	//	54600
#define	IDW_0054650_W	4034	//	54650
#define	IDW_0054700_W	4035	//	54700
#define	IDW_0054750_W	4036	//	54750
#define	IDW_0054800_W	4037	//	54800
#define	IDW_0054850_W	4038	//	54850
#define	IDW_0054900_W	4039	//	54900
#define	IDW_0054950_W	4040	//	54950
#define	IDW_0055000_W	4041	//	55000
#define	IDW_0055050_W	4042	//	55050
#define	IDW_0055100_W	4043	//	55100
#define	IDW_0055150_W	4044	//	55150
#define	IDW_0055200_W	4045	//	55200
#define	IDW_0055250_W	4046	//	55250
#define	IDW_0055300_W	4047	//	55300
#define	IDW_0055350_W	4048	//	55350
#define	IDW_0055400_W	4049	//	55400
#define	IDW_0055450_W	4050	//	55450
#define	IDW_0055500_W	4051	//	55500
#define	IDW_0055550_W	4052	//	55550
#define	IDW_0055600_W	4053	//	55600
#define	IDW_0055650_W	4054	//	55650
#define	IDW_0055700_W	4055	//	55700
#define	IDW_0055750_W	4056	//	55750
#define	IDW_0055800_W	4057	//	55800
#define	IDW_0055850_W	4058	//	55850
#define	IDW_0055900_W	4059	//	55900
#define	IDW_0055950_W	4060	//	55950
#define	IDW_0056000_W	4061	//	56000
#define	IDW_0056050_W	4062	//	56050
#define	IDW_0056100_W	4063	//	56100
#define	IDW_0056150_W	4064	//	56150
#define	IDW_0056200_W	4065	//	56200
#define	IDW_0056250_W	4066	//	56250
#define	IDW_0056300_W	4067	//	56300
#define	IDW_0056350_W	4068	//	56350
#define	IDW_0056400_W	4069	//	56400
#define	IDW_0056450_W	4070	//	56450
#define	IDW_0056500_W	4071	//	56500
#define	IDW_0056550_W	4072	//	56550
#define	IDW_0056600_W	4073	//	56600
#define	IDW_0056650_W	4074	//	56650
#define	IDW_0056700_W	4075	//	56700
#define	IDW_0056750_W	4076	//	56750
#define	IDW_0056800_W	4077	//	56800
#define	IDW_0056850_W	4078	//	56850
#define	IDW_0056900_W	4079	//	56900
#define	IDW_0056950_W	4080	//	56950
#define	IDW_0057000_W	4081	//	57000
#define	IDW_0057050_W	4082	//	57050
#define	IDW_0057100_W	4083	//	57100
#define	IDW_0057150_W	4084	//	57150
#define	IDW_0057200_W	4085	//	57200
#define	IDW_0057250_W	4086	//	57250
#define	IDW_0057300_W	4087	//	57300
#define	IDW_0057350_W	4088	//	57350
#define	IDW_0057400_W	4089	//	57400
#define	IDW_0057450_W	4090	//	57450
#define	IDW_0057500_W	4091	//	57500
#define	IDW_0057550_W	4092	//	57550
#define	IDW_0057600_W	4093	//	57600
#define	IDW_0057650_W	4094	//	57650
#define	IDW_0057700_W	4095	//	57700
#define	IDW_0057750_W	4096	//	57750
#define	IDW_0057800_W	4097	//	57800
#define	IDW_0057850_W	4098	//	57850
#define	IDW_0057900_W	4099	//	57900
#define	IDW_0057950_W	4100	//	57950
#define	IDW_0058000_W	4101	//	58000
#define	IDW_0058050_W	4102	//	58050
#define	IDW_0058100_W	4103	//	58100
#define	IDW_0058150_W	4104	//	58150
#define	IDW_0058200_W	4105	//	58200
#define	IDW_0058250_W	4106	//	58250
#define	IDW_0058300_W	4107	//	58300
#define	IDW_0058350_W	4108	//	58350
#define	IDW_0058400_W	4109	//	58400
#define	IDW_0058450_W	4110	//	58450
#define	IDW_0058500_W	4111	//	58500
#define	IDW_0058550_W	4112	//	58550
#define	IDW_0058600_W	4113	//	58600
#define	IDW_0058650_W	4114	//	58650
#define	IDW_0058700_W	4115	//	58700
#define	IDW_0058750_W	4116	//	58750
#define	IDW_0058800_W	4117	//	58800
#define	IDW_0058850_W	4118	//	58850
#define	IDW_0058900_W	4119	//	58900
#define	IDW_0058950_W	4120	//	58950
#define	IDW_0059000_W	4121	//	59000
#define	IDW_0059050_W	4122	//	59050
#define	IDW_0059100_W	4123	//	59100
#define	IDW_0059150_W	4124	//	59150
#define	IDW_0059200_W	4125	//	59200
#define	IDW_0059250_W	4126	//	59250
#define	IDW_0059300_W	4127	//	59300
#define	IDW_0059350_W	4128	//	59350
#define	IDW_0059400_W	4129	//	59400
#define	IDW_0059450_W	4130	//	59450
#define	IDW_0059500_W	4131	//	59500
#define	IDW_0059550_W	4132	//	59550
#define	IDW_0059600_W	4133	//	59600
#define	IDW_0059650_W	4134	//	59650
#define	IDW_0059700_W	4135	//	59700
#define	IDW_0059750_W	4136	//	59750
#define	IDW_0059800_W	4137	//	59800
#define	IDW_0059850_W	4138	//	59850
#define	IDW_0059900_W	4139	//	59900
#define	IDW_0059950_W	4140	//	59950
#define	IDW_0060000_W	4141	//	60000
#define	IDW_0060050_W	4142	//	60050
#define	IDW_0060100_W	4143	//	60100
#define	IDW_0060150_W	4144	//	60150
#define	IDW_0060200_W	4145	//	60200
#define	IDW_0060250_W	4146	//	60250
#define	IDW_0060300_W	4147	//	60300
#define	IDW_0060350_W	4148	//	60350
#define	IDW_0060400_W	4149	//	60400
#define	IDW_0060450_W	4150	//	60450
#define	IDW_0060500_W	4151	//	60500
#define	IDW_0060550_W	4152	//	60550
#define	IDW_0060600_W	4153	//	60600
#define	IDW_0060650_W	4154	//	60650
#define	IDW_0060700_W	4155	//	60700
#define	IDW_0060750_W	4156	//	60750
#define	IDW_0060800_W	4157	//	60800
#define	IDW_0060850_W	4158	//	60850
#define	IDW_0060900_W	4159	//	60900
#define	IDW_0060950_W	4160	//	60950
#define	IDW_0061000_W	4161	//	61000
#define	IDW_0061050_W	4162	//	61050
#define	IDW_0061100_W	4163	//	61100
#define	IDW_0061150_W	4164	//	61150
#define	IDW_0061200_W	4165	//	61200
#define	IDW_0061250_W	4166	//	61250
#define	IDW_0061300_W	4167	//	61300
#define	IDW_0061350_W	4168	//	61350
#define	IDW_0061400_W	4169	//	61400
#define	IDW_0061450_W	4170	//	61450
#define	IDW_0061500_W	4171	//	61500
#define	IDW_0061550_W	4172	//	61550
#define	IDW_0061600_W	4173	//	61600
#define	IDW_0061650_W	4174	//	61650
#define	IDW_0061700_W	4175	//	61700
#define	IDW_0061750_W	4176	//	61750
#define	IDW_0061800_W	4177	//	61800
#define	IDW_0061850_W	4178	//	61850
#define	IDW_0061900_W	4179	//	61900
#define	IDW_0061950_W	4180	//	61950
#define	IDW_0062000_W	4181	//	62000
#define	IDW_0062050_W	4182	//	62050
#define	IDW_0062100_W	4183	//	62100
#define	IDW_0062150_W	4184	//	62150
#define	IDW_0062200_W	4185	//	62200
#define	IDW_0062250_W	4186	//	62250
#define	IDW_0062300_W	4187	//	62300
#define	IDW_0062350_W	4188	//	62350
#define	IDW_0062400_W	4189	//	62400
#define	IDW_0062450_W	4190	//	62450
#define	IDW_0062500_W	4191	//	62500
#define	IDW_0062550_W	4192	//	62550
#define	IDW_0062600_W	4193	//	62600
#define	IDW_0062650_W	4194	//	62650
#define	IDW_0062700_W	4195	//	62700
#define	IDW_0062750_W	4196	//	62750
#define	IDW_0062800_W	4197	//	62800
#define	IDW_0062850_W	4198	//	62850
#define	IDW_0062900_W	4199	//	62900
#define	IDW_0062950_W	4200	//	62950
#define	IDW_0063000_W	4201	//	63000
#define	IDW_0063050_W	4202	//	63050
#define	IDW_0063100_W	4203	//	63100
#define	IDW_0063150_W	4204	//	63150
#define	IDW_0063200_W	4205	//	63200
#define	IDW_0063250_W	4206	//	63250
#define	IDW_0063300_W	4207	//	63300
#define	IDW_0063350_W	4208	//	63350
#define	IDW_0063400_W	4209	//	63400
#define	IDW_0063450_W	4210	//	63450
#define	IDW_0063500_W	4211	//	63500
#define	IDW_0063550_W	4212	//	63550
#define	IDW_0063600_W	4213	//	63600
#define	IDW_0063650_W	4214	//	63650
#define	IDW_0063700_W	4215	//	63700
#define	IDW_0063750_W	4216	//	63750
#define	IDW_0063800_W	4217	//	63800
#define	IDW_0063850_W	4218	//	63850
#define	IDW_0063900_W	4219	//	63900
#define	IDW_0063950_W	4220	//	63950
#define	IDW_0064000_W	4221	//	64000
#define	IDW_0064050_W	4222	//	64050
#define	IDW_0064100_W	4223	//	64100
#define	IDW_0064150_W	4224	//	64150
#define	IDW_0064200_W	4225	//	64200
#define	IDW_0064250_W	4226	//	64250
#define	IDW_0064300_W	4227	//	64300
#define	IDW_0064350_W	4228	//	64350
#define	IDW_0064400_W	4229	//	64400
#define	IDW_0064450_W	4230	//	64450
#define	IDW_0064500_W	4231	//	64500
#define	IDW_0064550_W	4232	//	64550
#define	IDW_0064600_W	4233	//	64600
#define	IDW_0064650_W	4234	//	64650
#define	IDW_0064700_W	4235	//	64700
#define	IDW_0064750_W	4236	//	64750
#define	IDW_0064800_W	4237	//	64800
#define	IDW_0064850_W	4238	//	64850
#define	IDW_0064900_W	4239	//	64900
#define	IDW_0064950_W	4240	//	64950
#define	IDW_0065000_W	4241	//	65000
#define	IDW_0065050_W	4242	//	65050
#define	IDW_0065100_W	4243	//	65100
#define	IDW_0065150_W	4244	//	65150
#define	IDW_0065200_W	4245	//	65200
#define	IDW_0065250_W	4246	//	65250
#define	IDW_0065300_W	4247	//	65300
#define	IDW_0065350_W	4248	//	65350
#define	IDW_0065400_W	4249	//	65400
#define	IDW_0065450_W	4250	//	65450
#define	IDW_0065500_W	4251	//	65500
#define	IDW_0065550_W	4252	//	65550
#define	IDW_0065600_W	4253	//	65600
#define	IDW_0065650_W	4254	//	65650
#define	IDW_0065700_W	4255	//	65700
#define	IDW_0065750_W	4256	//	65750
#define	IDW_0065800_W	4257	//	65800
#define	IDW_0065850_W	4258	//	65850
#define	IDW_0065900_W	4259	//	65900
#define	IDW_0065950_W	4260	//	65950
#define	IDW_0066000_W	4261	//	66000
#define	IDW_0066050_W	4262	//	66050
#define	IDW_0066100_W	4263	//	66100
#define	IDW_0066150_W	4264	//	66150
#define	IDW_0066200_W	4265	//	66200
#define	IDW_0066250_W	4266	//	66250
#define	IDW_0066300_W	4267	//	66300
#define	IDW_0066350_W	4268	//	66350
#define	IDW_0066400_W	4269	//	66400
#define	IDW_0066450_W	4270	//	66450
#define	IDW_0066500_W	4271	//	66500
#define	IDW_0066550_W	4272	//	66550
#define	IDW_0066600_W	4273	//	66600
#define	IDW_0066650_W	4274	//	66650
#define	IDW_0066700_W	4275	//	66700
#define	IDW_0066750_W	4276	//	66750
#define	IDW_0066800_W	4277	//	66800
#define	IDW_0066850_W	4278	//	66850
#define	IDW_0066900_W	4279	//	66900
#define	IDW_0066950_W	4280	//	66950
#define	IDW_0067000_W	4281	//	67000
#define	IDW_0067050_W	4282	//	67050
#define	IDW_0067100_W	4283	//	67100
#define	IDW_0067150_W	4284	//	67150
#define	IDW_0067200_W	4285	//	67200
#define	IDW_0067250_W	4286	//	67250
#define	IDW_0067300_W	4287	//	67300
#define	IDW_0067350_W	4288	//	67350
#define	IDW_0067400_W	4289	//	67400
#define	IDW_0067450_W	4290	//	67450
#define	IDW_0067500_W	4291	//	67500
#define	IDW_0067550_W	4292	//	67550
#define	IDW_0067600_W	4293	//	67600
#define	IDW_0067650_W	4294	//	67650
#define	IDW_0067700_W	4295	//	67700
#define	IDW_0067750_W	4296	//	67750
#define	IDW_0067800_W	4297	//	67800
#define	IDW_0067850_W	4298	//	67850
#define	IDW_0067900_W	4299	//	67900
#define	IDW_0067950_W	4300	//	67950
#define	IDW_0068000_W	4301	//	68000
#define	IDW_0068050_W	4302	//	68050
#define	IDW_0068100_W	4303	//	68100
#define	IDW_0068150_W	4304	//	68150
#define	IDW_0068200_W	4305	//	68200
#define	IDW_0068250_W	4306	//	68250
#define	IDW_0068300_W	4307	//	68300
#define	IDW_0068350_W	4308	//	68350
#define	IDW_0068400_W	4309	//	68400
#define	IDW_0068450_W	4310	//	68450
#define	IDW_0068500_W	4311	//	68500
#define	IDW_0068550_W	4312	//	68550
#define	IDW_0068600_W	4313	//	68600
#define	IDW_0068650_W	4314	//	68650
#define	IDW_0068700_W	4315	//	68700
#define	IDW_0068750_W	4316	//	68750
#define	IDW_0068800_W	4317	//	68800
#define	IDW_0068850_W	4318	//	68850
#define	IDW_0068900_W	4319	//	68900
#define	IDW_0068950_W	4320	//	68950
#define	IDW_0069000_W	4321	//	69000
#define	IDW_0069050_W	4322	//	69050
#define	IDW_0069100_W	4323	//	69100
#define	IDW_0069150_W	4324	//	69150
#define	IDW_0069200_W	4325	//	69200
#define	IDW_0069250_W	4326	//	69250
#define	IDW_0069300_W	4327	//	69300
#define	IDW_0069350_W	4328	//	69350
#define	IDW_0069400_W	4329	//	69400
#define	IDW_0069450_W	4330	//	69450
#define	IDW_0069500_W	4331	//	69500
#define	IDW_0069550_W	4332	//	69550
#define	IDW_0069600_W	4333	//	69600
#define	IDW_0069650_W	4334	//	69650
#define	IDW_0069700_W	4335	//	69700
#define	IDW_0069750_W	4336	//	69750
#define	IDW_0069800_W	4337	//	69800
#define	IDW_0069850_W	4338	//	69850
#define	IDW_0069900_W	4339	//	69900
#define	IDW_0069950_W	4340	//	69950
#define	IDW_0070000_W	4341	//	70000
#define	IDW_0070050_W	4342	//	70050
#define	IDW_0070100_W	4343	//	70100
#define	IDW_0070150_W	4344	//	70150
#define	IDW_0070200_W	4345	//	70200
#define	IDW_0070250_W	4346	//	70250
#define	IDW_0070300_W	4347	//	70300
#define	IDW_0070350_W	4348	//	70350
#define	IDW_0070400_W	4349	//	70400
#define	IDW_0070450_W	4350	//	70450
#define	IDW_0070500_W	4351	//	70500
#define	IDW_0070550_W	4352	//	70550
#define	IDW_0070600_W	4353	//	70600
#define	IDW_0070650_W	4354	//	70650
#define	IDW_0070700_W	4355	//	70700
#define	IDW_0070750_W	4356	//	70750
#define	IDW_0070800_W	4357	//	70800
#define	IDW_0070850_W	4358	//	70850
#define	IDW_0070900_W	4359	//	70900
#define	IDW_0070950_W	4360	//	70950
#define	IDW_0071000_W	4361	//	71000
#define	IDW_0071050_W	4362	//	71050
#define	IDW_0071100_W	4363	//	71100
#define	IDW_0071150_W	4364	//	71150
#define	IDW_0071200_W	4365	//	71200
#define	IDW_0071250_W	4366	//	71250
#define	IDW_0071300_W	4367	//	71300
#define	IDW_0071350_W	4368	//	71350
#define	IDW_0071400_W	4369	//	71400
#define	IDW_0071450_W	4370	//	71450
#define	IDW_0071500_W	4371	//	71500
#define	IDW_0071550_W	4372	//	71550
#define	IDW_0071600_W	4373	//	71600
#define	IDW_0071650_W	4374	//	71650
#define	IDW_0071700_W	4375	//	71700
#define	IDW_0071750_W	4376	//	71750
#define	IDW_0071800_W	4377	//	71800
#define	IDW_0071850_W	4378	//	71850
#define	IDW_0071900_W	4379	//	71900
#define	IDW_0071950_W	4380	//	71950
#define	IDW_0072000_W	4381	//	72000
#define	IDW_0072050_W	4382	//	72050
#define	IDW_0072100_W	4383	//	72100
#define	IDW_0072150_W	4384	//	72150
#define	IDW_0072200_W	4385	//	72200
#define	IDW_0072250_W	4386	//	72250
#define	IDW_0072300_W	4387	//	72300
#define	IDW_0072350_W	4388	//	72350
#define	IDW_0072400_W	4389	//	72400
#define	IDW_0072450_W	4390	//	72450
#define	IDW_0072500_W	4391	//	72500
#define	IDW_0072550_W	4392	//	72550
#define	IDW_0072600_W	4393	//	72600
#define	IDW_0072650_W	4394	//	72650
#define	IDW_0072700_W	4395	//	72700
#define	IDW_0072750_W	4396	//	72750
#define	IDW_0072800_W	4397	//	72800
#define	IDW_0072850_W	4398	//	72850
#define	IDW_0072900_W	4399	//	72900
#define	IDW_0072950_W	4400	//	72950
#define	IDW_0073000_W	4401	//	73000
#define	IDW_0073050_W	4402	//	73050
#define	IDW_0073100_W	4403	//	73100
#define	IDW_0073150_W	4404	//	73150
#define	IDW_0073200_W	4405	//	73200
#define	IDW_0073250_W	4406	//	73250
#define	IDW_0073300_W	4407	//	73300
#define	IDW_0073350_W	4408	//	73350
#define	IDW_0073400_W	4409	//	73400
#define	IDW_0073450_W	4410	//	73450
#define	IDW_0073500_W	4411	//	73500
#define	IDW_0073550_W	4412	//	73550
#define	IDW_0073600_W	4413	//	73600
#define	IDW_0073650_W	4414	//	73650
#define	IDW_0073700_W	4415	//	73700
#define	IDW_0073750_W	4416	//	73750
#define	IDW_0073800_W	4417	//	73800
#define	IDW_0073850_W	4418	//	73850
#define	IDW_0073900_W	4419	//	73900
#define	IDW_0073950_W	4420	//	73950
#define	IDW_0074000_W	4421	//	74000
#define	IDW_0074050_W	4422	//	74050
#define	IDW_0074100_W	4423	//	74100
#define	IDW_0074150_W	4424	//	74150
#define	IDW_0074200_W	4425	//	74200
#define	IDW_0074250_W	4426	//	74250
#define	IDW_0074300_W	4427	//	74300
#define	IDW_0074350_W	4428	//	74350
#define	IDW_0074400_W	4429	//	74400
#define	IDW_0074450_W	4430	//	74450
#define	IDW_0074500_W	4431	//	74500
#define	IDW_0074550_W	4432	//	74550
#define	IDW_0074600_W	4433	//	74600
#define	IDW_0074650_W	4434	//	74650
#define	IDW_0074700_W	4435	//	74700
#define	IDW_0074750_W	4436	//	74750
#define	IDW_0074800_W	4437	//	74800
#define	IDW_0074850_W	4438	//	74850
#define	IDW_0074900_W	4439	//	74900
#define	IDW_0074950_W	4440	//	74950
#define	IDW_0075000_W	4441	//	75000
#define	IDW_0075050_W	4442	//	75050
#define	IDW_0075100_W	4443	//	75100
#define	IDW_0075150_W	4444	//	75150
#define	IDW_0075200_W	4445	//	75200
#define	IDW_0075250_W	4446	//	75250
#define	IDW_0075300_W	4447	//	75300
#define	IDW_0075350_W	4448	//	75350
#define	IDW_0075400_W	4449	//	75400
#define	IDW_0075450_W	4450	//	75450
#define	IDW_0075500_W	4451	//	75500
#define	IDW_0075550_W	4452	//	75550
#define	IDW_0075600_W	4453	//	75600
#define	IDW_0075650_W	4454	//	75650
#define	IDW_0075700_W	4455	//	75700
#define	IDW_0075750_W	4456	//	75750
#define	IDW_0075800_W	4457	//	75800
#define	IDW_0075850_W	4458	//	75850
#define	IDW_0075900_W	4459	//	75900
#define	IDW_0075950_W	4460	//	75950
#define	IDW_0076000_W	4461	//	76000
#define	IDW_0076050_W	4462	//	76050
#define	IDW_0076100_W	4463	//	76100
#define	IDW_0076150_W	4464	//	76150
#define	IDW_0076200_W	4465	//	76200
#define	IDW_0076250_W	4466	//	76250
#define	IDW_0076300_W	4467	//	76300
#define	IDW_0076350_W	4468	//	76350
#define	IDW_0076400_W	4469	//	76400
#define	IDW_0076450_W	4470	//	76450
#define	IDW_0076500_W	4471	//	76500
#define	IDW_0076550_W	4472	//	76550
#define	IDW_0076600_W	4473	//	76600
#define	IDW_0076650_W	4474	//	76650
#define	IDW_0076700_W	4475	//	76700
#define	IDW_0076750_W	4476	//	76750
#define	IDW_0076800_W	4477	//	76800
#define	IDW_0076850_W	4478	//	76850
#define	IDW_0076900_W	4479	//	76900
#define	IDW_0076950_W	4480	//	76950
#define	IDW_0077000_W	4481	//	77000
#define	IDW_0077050_W	4482	//	77050
#define	IDW_0077100_W	4483	//	77100
#define	IDW_0077150_W	4484	//	77150
#define	IDW_0077200_W	4485	//	77200
#define	IDW_0077250_W	4486	//	77250
#define	IDW_0077300_W	4487	//	77300
#define	IDW_0077350_W	4488	//	77350
#define	IDW_0077400_W	4489	//	77400
#define	IDW_0077450_W	4490	//	77450
#define	IDW_0077500_W	4491	//	77500
#define	IDW_0077550_W	4492	//	77550
#define	IDW_0077600_W	4493	//	77600
#define	IDW_0077650_W	4494	//	77650
#define	IDW_0077700_W	4495	//	77700
#define	IDW_0077750_W	4496	//	77750
#define	IDW_0077800_W	4497	//	77800
#define	IDW_0077850_W	4498	//	77850
#define	IDW_0077900_W	4499	//	77900
#define	IDW_0077950_W	4500	//	77950
#define	IDW_0078000_W	4501	//	78000
#define	IDW_0078050_W	4502	//	78050
#define	IDW_0078100_W	4503	//	78100
#define	IDW_0078150_W	4504	//	78150
#define	IDW_0078200_W	4505	//	78200
#define	IDW_0078250_W	4506	//	78250
#define	IDW_0078300_W	4507	//	78300
#define	IDW_0078350_W	4508	//	78350
#define	IDW_0078400_W	4509	//	78400
#define	IDW_0078450_W	4510	//	78450
#define	IDW_0078500_W	4511	//	78500
#define	IDW_0078550_W	4512	//	78550
#define	IDW_0078600_W	4513	//	78600
#define	IDW_0078650_W	4514	//	78650
#define	IDW_0078700_W	4515	//	78700
#define	IDW_0078750_W	4516	//	78750
#define	IDW_0078800_W	4517	//	78800
#define	IDW_0078850_W	4518	//	78850
#define	IDW_0078900_W	4519	//	78900
#define	IDW_0078950_W	4520	//	78950
#define	IDW_0079000_W	4521	//	79000
#define	IDW_0079050_W	4522	//	79050
#define	IDW_0079100_W	4523	//	79100
#define	IDW_0079150_W	4524	//	79150
#define	IDW_0079200_W	4525	//	79200
#define	IDW_0079250_W	4526	//	79250
#define	IDW_0079300_W	4527	//	79300
#define	IDW_0079350_W	4528	//	79350
#define	IDW_0079400_W	4529	//	79400
#define	IDW_0079450_W	4530	//	79450
#define	IDW_0079500_W	4531	//	79500
#define	IDW_0079550_W	4532	//	79550
#define	IDW_0079600_W	4533	//	79600
#define	IDW_0079650_W	4534	//	79650
#define	IDW_0079700_W	4535	//	79700
#define	IDW_0079750_W	4536	//	79750
#define	IDW_0079800_W	4537	//	79800
#define	IDW_0079850_W	4538	//	79850
#define	IDW_0079900_W	4539	//	79900
#define	IDW_0079950_W	4540	//	79950
#define	IDW_0080000_W	4541	//	80000
#define	IDW_0080050_W	4542	//	80050
#define	IDW_0080100_W	4543	//	80100
#define	IDW_0080150_W	4544	//	80150
#define	IDW_0080200_W	4545	//	80200
#define	IDW_0080250_W	4546	//	80250
#define	IDW_0080300_W	4547	//	80300
#define	IDW_0080350_W	4548	//	80350
#define	IDW_0080400_W	4549	//	80400
#define	IDW_0080450_W	4550	//	80450
#define	IDW_0080500_W	4551	//	80500
#define	IDW_0080550_W	4552	//	80550
#define	IDW_0080600_W	4553	//	80600
#define	IDW_0080650_W	4554	//	80650
#define	IDW_0080700_W	4555	//	80700
#define	IDW_0080750_W	4556	//	80750
#define	IDW_0080800_W	4557	//	80800
#define	IDW_0080850_W	4558	//	80850
#define	IDW_0080900_W	4559	//	80900
#define	IDW_0080950_W	4560	//	80950
#define	IDW_0081000_W	4561	//	81000
#define	IDW_0081050_W	4562	//	81050
#define	IDW_0081100_W	4563	//	81100
#define	IDW_0081150_W	4564	//	81150
#define	IDW_0081200_W	4565	//	81200
#define	IDW_0081250_W	4566	//	81250
#define	IDW_0081300_W	4567	//	81300
#define	IDW_0081350_W	4568	//	81350
#define	IDW_0081400_W	4569	//	81400
#define	IDW_0081450_W	4570	//	81450
#define	IDW_0081500_W	4571	//	81500
#define	IDW_0081550_W	4572	//	81550
#define	IDW_0081600_W	4573	//	81600
#define	IDW_0081650_W	4574	//	81650
#define	IDW_0081700_W	4575	//	81700
#define	IDW_0081750_W	4576	//	81750
#define	IDW_0081800_W	4577	//	81800
#define	IDW_0081850_W	4578	//	81850
#define	IDW_0081900_W	4579	//	81900
#define	IDW_0081950_W	4580	//	81950
#define	IDW_0082000_W	4581	//	82000
#define	IDW_0082050_W	4582	//	82050
#define	IDW_0082100_W	4583	//	82100
#define	IDW_0082150_W	4584	//	82150
#define	IDW_0082200_W	4585	//	82200
#define	IDW_0082250_W	4586	//	82250
#define	IDW_0082300_W	4587	//	82300
#define	IDW_0082350_W	4588	//	82350
#define	IDW_0082400_W	4589	//	82400
#define	IDW_0082450_W	4590	//	82450
#define	IDW_0082500_W	4591	//	82500
#define	IDW_0082550_W	4592	//	82550
#define	IDW_0082600_W	4593	//	82600
#define	IDW_0082650_W	4594	//	82650
#define	IDW_0082700_W	4595	//	82700
#define	IDW_0082750_W	4596	//	82750
#define	IDW_0082800_W	4597	//	82800
#define	IDW_0082850_W	4598	//	82850
#define	IDW_0082900_W	4599	//	82900
#define	IDW_0082950_W	4600	//	82950
#define	IDW_0083000_W	4601	//	83000
#define	IDW_0083050_W	4602	//	83050
#define	IDW_0083100_W	4603	//	83100
#define	IDW_0083150_W	4604	//	83150
#define	IDW_0083200_W	4605	//	83200
#define	IDW_0083250_W	4606	//	83250
#define	IDW_0083300_W	4607	//	83300
#define	IDW_0083350_W	4608	//	83350
#define	IDW_0083400_W	4609	//	83400
#define	IDW_0083450_W	4610	//	83450
#define	IDW_0083500_W	4611	//	83500
#define	IDW_0083550_W	4612	//	83550
#define	IDW_0083600_W	4613	//	83600
#define	IDW_0083650_W	4614	//	83650
#define	IDW_0083700_W	4615	//	83700
#define	IDW_0083750_W	4616	//	83750
#define	IDW_0083800_W	4617	//	83800
#define	IDW_0083850_W	4618	//	83850
#define	IDW_0083900_W	4619	//	83900
#define	IDW_0083950_W	4620	//	83950
#define	IDW_0084000_W	4621	//	84000
#define	IDW_0084050_W	4622	//	84050
#define	IDW_0084100_W	4623	//	84100
#define	IDW_0084150_W	4624	//	84150
#define	IDW_0084200_W	4625	//	84200
#define	IDW_0084250_W	4626	//	84250
#define	IDW_0084300_W	4627	//	84300
#define	IDW_0084350_W	4628	//	84350
#define	IDW_0084400_W	4629	//	84400
#define	IDW_0084450_W	4630	//	84450
#define	IDW_0084500_W	4631	//	84500
#define	IDW_0084550_W	4632	//	84550
#define	IDW_0084600_W	4633	//	84600
#define	IDW_0084650_W	4634	//	84650
#define	IDW_0084700_W	4635	//	84700
#define	IDW_0084750_W	4636	//	84750
#define	IDW_0084800_W	4637	//	84800
#define	IDW_0084850_W	4638	//	84850
#define	IDW_0084900_W	4639	//	84900
#define	IDW_0084950_W	4640	//	84950
#define	IDW_0085000_W	4641	//	85000
#define	IDW_0085050_W	4642	//	85050
#define	IDW_0085100_W	4643	//	85100
#define	IDW_0085150_W	4644	//	85150
#define	IDW_0085200_W	4645	//	85200
#define	IDW_0085250_W	4646	//	85250
#define	IDW_0085300_W	4647	//	85300
#define	IDW_0085350_W	4648	//	85350
#define	IDW_0085400_W	4649	//	85400
#define	IDW_0085450_W	4650	//	85450
#define	IDW_0085500_W	4651	//	85500
#define	IDW_0085550_W	4652	//	85550
#define	IDW_0085600_W	4653	//	85600
#define	IDW_0085650_W	4654	//	85650
#define	IDW_0085700_W	4655	//	85700
#define	IDW_0085750_W	4656	//	85750
#define	IDW_0085800_W	4657	//	85800
#define	IDW_0085850_W	4658	//	85850
#define	IDW_0085900_W	4659	//	85900
#define	IDW_0085950_W	4660	//	85950
#define	IDW_0086000_W	4661	//	86000
#define	IDW_0086050_W	4662	//	86050
#define	IDW_0086100_W	4663	//	86100
#define	IDW_0086150_W	4664	//	86150
#define	IDW_0086200_W	4665	//	86200
#define	IDW_0086250_W	4666	//	86250
#define	IDW_0086300_W	4667	//	86300
#define	IDW_0086350_W	4668	//	86350
#define	IDW_0086400_W	4669	//	86400
#define	IDW_0086450_W	4670	//	86450
#define	IDW_0086500_W	4671	//	86500
#define	IDW_0086550_W	4672	//	86550
#define	IDW_0086600_W	4673	//	86600
#define	IDW_0086650_W	4674	//	86650
#define	IDW_0086700_W	4675	//	86700
#define	IDW_0086750_W	4676	//	86750
#define	IDW_0086800_W	4677	//	86800
#define	IDW_0086850_W	4678	//	86850
#define	IDW_0086900_W	4679	//	86900
#define	IDW_0086950_W	4680	//	86950
#define	IDW_0087000_W	4681	//	87000
#define	IDW_0087050_W	4682	//	87050
#define	IDW_0087100_W	4683	//	87100
#define	IDW_0087150_W	4684	//	87150
#define	IDW_0087200_W	4685	//	87200
#define	IDW_0087250_W	4686	//	87250
#define	IDW_0087300_W	4687	//	87300
#define	IDW_0087350_W	4688	//	87350
#define	IDW_0087400_W	4689	//	87400
#define	IDW_0087450_W	4690	//	87450
#define	IDW_0087500_W	4691	//	87500
#define	IDW_0087550_W	4692	//	87550
#define	IDW_0087600_W	4693	//	87600
#define	IDW_0087650_W	4694	//	87650
#define	IDW_0087700_W	4695	//	87700
#define	IDW_0087750_W	4696	//	87750
#define	IDW_0087800_W	4697	//	87800
#define	IDW_0087850_W	4698	//	87850
#define	IDW_0087900_W	4699	//	87900
#define	IDW_0087950_W	4700	//	87950
#define	IDW_0088000_W	4701	//	88000
#define	IDW_0088050_W	4702	//	88050
#define	IDW_0088100_W	4703	//	88100
#define	IDW_0088150_W	4704	//	88150
#define	IDW_0088200_W	4705	//	88200
#define	IDW_0088250_W	4706	//	88250
#define	IDW_0088300_W	4707	//	88300
#define	IDW_0088350_W	4708	//	88350
#define	IDW_0088400_W	4709	//	88400
#define	IDW_0088450_W	4710	//	88450
#define	IDW_0088500_W	4711	//	88500
#define	IDW_0088550_W	4712	//	88550
#define	IDW_0088600_W	4713	//	88600
#define	IDW_0088650_W	4714	//	88650
#define	IDW_0088700_W	4715	//	88700
#define	IDW_0088750_W	4716	//	88750
#define	IDW_0088800_W	4717	//	88800
#define	IDW_0088850_W	4718	//	88850
#define	IDW_0088900_W	4719	//	88900
#define	IDW_0088950_W	4720	//	88950
#define	IDW_0089000_W	4721	//	89000
#define	IDW_0089050_W	4722	//	89050
#define	IDW_0089100_W	4723	//	89100
#define	IDW_0089150_W	4724	//	89150
#define	IDW_0089200_W	4725	//	89200
#define	IDW_0089250_W	4726	//	89250
#define	IDW_0089300_W	4727	//	89300
#define	IDW_0089350_W	4728	//	89350
#define	IDW_0089400_W	4729	//	89400
#define	IDW_0089450_W	4730	//	89450
#define	IDW_0089500_W	4731	//	89500
#define	IDW_0089550_W	4732	//	89550
#define	IDW_0089600_W	4733	//	89600
#define	IDW_0089650_W	4734	//	89650
#define	IDW_0089700_W	4735	//	89700
#define	IDW_0089750_W	4736	//	89750
#define	IDW_0089800_W	4737	//	89800
#define	IDW_0089850_W	4738	//	89850
#define	IDW_0089900_W	4739	//	89900
#define	IDW_0089950_W	4740	//	89950
#define	IDW_0090000_W	4741	//	90000
#define	IDW_0090050_W	4742	//	90050
#define	IDW_0090100_W	4743	//	90100
#define	IDW_0090150_W	4744	//	90150
#define	IDW_0090200_W	4745	//	90200
#define	IDW_0090250_W	4746	//	90250
#define	IDW_0090300_W	4747	//	90300
#define	IDW_0090350_W	4748	//	90350
#define	IDW_0090400_W	4749	//	90400
#define	IDW_0090450_W	4750	//	90450
#define	IDW_0090500_W	4751	//	90500
#define	IDW_0090550_W	4752	//	90550
#define	IDW_0090600_W	4753	//	90600
#define	IDW_0090650_W	4754	//	90650
#define	IDW_0090700_W	4755	//	90700
#define	IDW_0090750_W	4756	//	90750
#define	IDW_0090800_W	4757	//	90800
#define	IDW_0090850_W	4758	//	90850
#define	IDW_0090900_W	4759	//	90900
#define	IDW_0090950_W	4760	//	90950
#define	IDW_0091000_W	4761	//	91000
#define	IDW_0091050_W	4762	//	91050
#define	IDW_0091100_W	4763	//	91100
#define	IDW_0091150_W	4764	//	91150
#define	IDW_0091200_W	4765	//	91200
#define	IDW_0091250_W	4766	//	91250
#define	IDW_0091300_W	4767	//	91300
#define	IDW_0091350_W	4768	//	91350
#define	IDW_0091400_W	4769	//	91400
#define	IDW_0091450_W	4770	//	91450
#define	IDW_0091500_W	4771	//	91500
#define	IDW_0091550_W	4772	//	91550
#define	IDW_0091600_W	4773	//	91600
#define	IDW_0091650_W	4774	//	91650
#define	IDW_0091700_W	4775	//	91700
#define	IDW_0091750_W	4776	//	91750
#define	IDW_0091800_W	4777	//	91800
#define	IDW_0091850_W	4778	//	91850
#define	IDW_0091900_W	4779	//	91900
#define	IDW_0091950_W	4780	//	91950
#define	IDW_0092000_W	4781	//	92000
#define	IDW_0092050_W	4782	//	92050
#define	IDW_0092100_W	4783	//	92100
#define	IDW_0092150_W	4784	//	92150
#define	IDW_0092200_W	4785	//	92200
#define	IDW_0092250_W	4786	//	92250
#define	IDW_0092300_W	4787	//	92300
#define	IDW_0092350_W	4788	//	92350
#define	IDW_0092400_W	4789	//	92400
#define	IDW_0092450_W	4790	//	92450
#define	IDW_0092500_W	4791	//	92500
#define	IDW_0092550_W	4792	//	92550
#define	IDW_0092600_W	4793	//	92600
#define	IDW_0092650_W	4794	//	92650
#define	IDW_0092700_W	4795	//	92700
#define	IDW_0092750_W	4796	//	92750
#define	IDW_0092800_W	4797	//	92800
#define	IDW_0092850_W	4798	//	92850
#define	IDW_0092900_W	4799	//	92900
#define	IDW_0092950_W	4800	//	92950
#define	IDW_0093000_W	4801	//	93000
#define	IDW_0093050_W	4802	//	93050
#define	IDW_0093100_W	4803	//	93100
#define	IDW_0093150_W	4804	//	93150
#define	IDW_0093200_W	4805	//	93200
#define	IDW_0093250_W	4806	//	93250
#define	IDW_0093300_W	4807	//	93300
#define	IDW_0093350_W	4808	//	93350
#define	IDW_0093400_W	4809	//	93400
#define	IDW_0093450_W	4810	//	93450
#define	IDW_0093500_W	4811	//	93500
#define	IDW_0093550_W	4812	//	93550
#define	IDW_0093600_W	4813	//	93600
#define	IDW_0093650_W	4814	//	93650
#define	IDW_0093700_W	4815	//	93700
#define	IDW_0093750_W	4816	//	93750
#define	IDW_0093800_W	4817	//	93800
#define	IDW_0093850_W	4818	//	93850
#define	IDW_0093900_W	4819	//	93900
#define	IDW_0093950_W	4820	//	93950
#define	IDW_0094000_W	4821	//	94000
#define	IDW_0094050_W	4822	//	94050
#define	IDW_0094100_W	4823	//	94100
#define	IDW_0094150_W	4824	//	94150
#define	IDW_0094200_W	4825	//	94200
#define	IDW_0094250_W	4826	//	94250
#define	IDW_0094300_W	4827	//	94300
#define	IDW_0094350_W	4828	//	94350
#define	IDW_0094400_W	4829	//	94400
#define	IDW_0094450_W	4830	//	94450
#define	IDW_0094500_W	4831	//	94500
#define	IDW_0094550_W	4832	//	94550
#define	IDW_0094600_W	4833	//	94600
#define	IDW_0094650_W	4834	//	94650
#define	IDW_0094700_W	4835	//	94700
#define	IDW_0094750_W	4836	//	94750
#define	IDW_0094800_W	4837	//	94800
#define	IDW_0094850_W	4838	//	94850
#define	IDW_0094900_W	4839	//	94900
#define	IDW_0094950_W	4840	//	94950
#define	IDW_0095000_W	4841	//	95000
#define	IDW_0095050_W	4842	//	95050
#define	IDW_0095100_W	4843	//	95100
#define	IDW_0095150_W	4844	//	95150
#define	IDW_0095200_W	4845	//	95200
#define	IDW_0095250_W	4846	//	95250
#define	IDW_0095300_W	4847	//	95300
#define	IDW_0095350_W	4848	//	95350
#define	IDW_0095400_W	4849	//	95400
#define	IDW_0095450_W	4850	//	95450
#define	IDW_0095500_W	4851	//	95500
#define	IDW_0095550_W	4852	//	95550
#define	IDW_0095600_W	4853	//	95600
#define	IDW_0095650_W	4854	//	95650
#define	IDW_0095700_W	4855	//	95700
#define	IDW_0095750_W	4856	//	95750
#define	IDW_0095800_W	4857	//	95800
#define	IDW_0095850_W	4858	//	95850
#define	IDW_0095900_W	4859	//	95900
#define	IDW_0095950_W	4860	//	95950
#define	IDW_0096000_W	4861	//	96000
#define	IDW_0096050_W	4862	//	96050
#define	IDW_0096100_W	4863	//	96100
#define	IDW_0096150_W	4864	//	96150
#define	IDW_0096200_W	4865	//	96200
#define	IDW_0096250_W	4866	//	96250
#define	IDW_0096300_W	4867	//	96300
#define	IDW_0096350_W	4868	//	96350
#define	IDW_0096400_W	4869	//	96400
#define	IDW_0096450_W	4870	//	96450
#define	IDW_0096500_W	4871	//	96500
#define	IDW_0096550_W	4872	//	96550
#define	IDW_0096600_W	4873	//	96600
#define	IDW_0096650_W	4874	//	96650
#define	IDW_0096700_W	4875	//	96700
#define	IDW_0096750_W	4876	//	96750
#define	IDW_0096800_W	4877	//	96800
#define	IDW_0096850_W	4878	//	96850
#define	IDW_0096900_W	4879	//	96900
#define	IDW_0096950_W	4880	//	96950
#define	IDW_0097000_W	4881	//	97000
#define	IDW_0097050_W	4882	//	97050
#define	IDW_0097100_W	4883	//	97100
#define	IDW_0097150_W	4884	//	97150
#define	IDW_0097200_W	4885	//	97200
#define	IDW_0097250_W	4886	//	97250
#define	IDW_0097300_W	4887	//	97300
#define	IDW_0097350_W	4888	//	97350
#define	IDW_0097400_W	4889	//	97400
#define	IDW_0097450_W	4890	//	97450
#define	IDW_0097500_W	4891	//	97500
#define	IDW_0097550_W	4892	//	97550
#define	IDW_0097600_W	4893	//	97600
#define	IDW_0097650_W	4894	//	97650
#define	IDW_0097700_W	4895	//	97700
#define	IDW_0097750_W	4896	//	97750
#define	IDW_0097800_W	4897	//	97800
#define	IDW_0097850_W	4898	//	97850
#define	IDW_0097900_W	4899	//	97900
#define	IDW_0097950_W	4900	//	97950
#define	IDW_0098000_W	4901	//	98000
#define	IDW_0098050_W	4902	//	98050
#define	IDW_0098100_W	4903	//	98100
#define	IDW_0098150_W	4904	//	98150
#define	IDW_0098200_W	4905	//	98200
#define	IDW_0098250_W	4906	//	98250
#define	IDW_0098300_W	4907	//	98300
#define	IDW_0098350_W	4908	//	98350
#define	IDW_0098400_W	4909	//	98400
#define	IDW_0098450_W	4910	//	98450
#define	IDW_0098500_W	4911	//	98500
#define	IDW_0098550_W	4912	//	98550
#define	IDW_0098600_W	4913	//	98600
#define	IDW_0098650_W	4914	//	98650
#define	IDW_0098700_W	4915	//	98700
#define	IDW_0098750_W	4916	//	98750
#define	IDW_0098800_W	4917	//	98800
#define	IDW_0098850_W	4918	//	98850
#define	IDW_0098900_W	4919	//	98900
#define	IDW_0098950_W	4920	//	98950
#define	IDW_0099000_W	4921	//	99000
#define	IDW_0099050_W	4922	//	99050
#define	IDW_0099100_W	4923	//	99100
#define	IDW_0099150_W	4924	//	99150
#define	IDW_0099200_W	4925	//	99200
#define	IDW_0099250_W	4926	//	99250
#define	IDW_0099300_W	4927	//	99300
#define	IDW_0099350_W	4928	//	99350
#define	IDW_0099400_W	4929	//	99400
#define	IDW_0099450_W	4930	//	99450
#define	IDW_0099500_W	4931	//	99500
#define	IDW_0099550_W	4932	//	99550
#define	IDW_0099600_W	4933	//	99600
#define	IDW_0099650_W	4934	//	99650
#define	IDW_0099700_W	4935	//	99700
#define	IDW_0099750_W	4936	//	99750
#define	IDW_0099800_W	4937	//	99800
#define	IDW_0099850_W	4938	//	99850
#define	IDW_0099900_W	4939	//	99900
#define	IDW_0099950_W	4940	//	99950
#define	IDS_SDI_TAIL	4941	//	신호위반 및 꼬리물기단속구간입니다. (아래 포함 총4건 : LocalSDI안내 추가)
#define	IDS_SDI_HWA03	4942	//	제동장치사고 다발지점입니다
#define	IDS_SDI_HWA06	4943	//	중앙선 침범사고 다발지점입니다
#define	IDS_SDI_HWA09	4944	//	통행 위반사고 다발지점입니다
#define	IDS_SDI_POL	4945	//	지정차로 통행을 준수하십시오.(경찰청 고속도로 지정차로 통행준수 안내 서비스 대응)
#define	IDW_NOT_ENTER_REQUEST_ROUTE	4946	//	경로에 진입하지 못했습니다 경로를 다시 요청합니다.
#define	IDW_NOT_ENTER_QUESTION_ROUTE	4947	//	경로에 진입하지 못했습니다 다시 요청하겠습니까?
#define	IDW_LEAVE_REQUEST_ROUTE	4948	//	경로를 벗어났습니다 경로를 다시 요청합니다
#define	IDW_LEAVE_QUESTION_ROUTE	4949	//	경로를 벗어났습니다 경로를 다시 요청하시겠습니까?
#define	IDW_NOT_SAVE_CONTINUE_DATA	4950	//	저장된 경로가 없습니다
#define	IDW_CONTINUE_ROUTE	4951	//	저장된 경로를 안내하겠습니다
#define	IDW_DETAIL_QUESTION_IS_OVERPASS	4952	//	현재 고가도로에 있습니까?
#define	IDW_DETAIL_QUESTION_IS_EXPRESSWAY	4953	//	현재 도시고속도로에 있습니까?
#define	IDW_DETAIL_QUESTION_IS_HIGHWAY	4954	//	현재 고속도로에 있습니까?
#define	IDW_DETAIL_QUESTION_IS_UNDERPASS	4955	//	현재 지하도로에 있습니까?
#define	NV_SOUND_STARTING	4956	//	초기구동멘트
#define	NV_SOUND_VOL_UP	4957	//	볼륨 업
#define	NV_SOUND_VOL_DOWN	4958	//	볼륨 다운
#define	NV_SOUND_POP_QUESTION	4959	//	팝업 질문
#define	NV_SOUND_POP_NOTI	4960	//	팝업 알림
#define	NV_SOUND_MENU_MOVE	4961	//	메뉴 이동
#define	NV_SOUND_ENTER_PATH	4962	//	경로 진입음
#define	IDG_IS_LPG_STATION	4963	//	LPG 충전소가 있습니다.
#define	IDG_OIL_AND	4964	//	주유소와
#define	IDG_NC	4965	//	NC
#define	IDG_NH	4966	//	NH
#define	IDG_OIL_1	4967	//	알뜰
#define	IDG_OIL_2	4968	//	무폴
#define	IDG_sevenD	4969	//	세븐디
#define IDG_GOAL_CROSS 4970 // 주행 경로 건너편에 목적지가 있습니다.
#define IDG_REST_PLACE 4971 // 졸음쉼터가 있습니다.

// T map 6.0 추가 녹음
#define IDG_RG_START_ROAD_1   4972    // 로 안내하겠습니다.
#define IDG_RG_START_MAP_CHK   4973    // 지도를 확인하고 출발하세요
#define IDG_CANCEL_ROUTE_2   4974    // 경로 안내가 취소되었습니다.
#define IDG_TRAFFIC_REFLECT   4975    // 교통정보를 반영하여
#define IDG_MORE_FAST   4976    // 더 빠른
#define IDG_RG_START_ROAD_2   4977    // 로 안내합니다.
#define IDG_FOR_ACCIDENT   4978    // 사고로 인해
#define IDG_FOR_CONSTRUCTION   4979    // 공사로 인해
#define IDG_FOR_EVENT   4980    // 행사로 인해
#define IDG_FOR_DAMAGED_ROAD   4981    // 도로 파손으로 인해
#define IDG_OPTIMAL_ROUTE   4982    // 티맵 최적길
#define IDG_TIMEMIN_ROUTE   4983    // 최소시간경로
#define IDG_LENGTHMIN_ROUTE   4984    // 최단거리경로
#define IDG_FREEROAD_ROUTE   4985    // 무료도로경로
#define IDG_BIKE_ROUTE   4986    // 이륜차경로
#define IDG_HIGHWAY_ROUTE   4987    // 고속도로우선경로
#define IDG_BEGINER_ROUTE   4988    // 초보자경로
#define IDG_TRUCK_ROUTE   4989    // 화물차경로
#define IDG_EV_ROUTE   4990    // 전기차경로
#define IDG_IS_BYWAY_ROUTE   4991    // 를 경유합니다.
#define IDG_TO_GO   4992    // 까지 직진입니다.
#define IDG_LANE_GUIDE_GO   4993    // 직진차로로 주행하세요
#define IDG_LANE_GUIDE_LEFT   4994    // 왼쪽차로로 주행하세요
#define IDG_LANE_GUIDE_LIGHT   4995    // 오른쪽차로로 주행하세요
#define IDG_LANE_GUIDE_01   4996    // 1차로로 주행하세요
#define IDG_LANE_GUIDE_02   4997    // 2차로로 주행하세요
#define IDG_LANE_GUIDE_03   4998    // 3차로로 주행하세요
#define IDG_LANE_GUIDE_04   4999    // 4차로로 주행하세요
#define IDG_LANE_GUIDE_05   5000    // 5차로로 주행하세요
#define IDG_LANE_GUIDE_06   5001    // 6차로로 주행하세요
#define IDG_LANE_GUIDE_07   5002    // 7차로로 주행하세요
#define IDG_LANE_GUIDE_08   5003    // 8차로로 주행하세요
#define IDG_LANE_GUIDE_09   5004    // 9차로로 주행하세요
#define IDG_LANE_GUIDE_10   5005    // 10차로로 주행하세요
#define IDW_NOTI_SEATBELT_SIMPLE   5006    // 전 좌석 안전벨트를 착용하세요.
#define IDG_3_CROSS   5007    // 삼거리
#define IDG_4_CROSS   5008    // 사거리
#define IDG_5_CROSS   5009    // 오거리
#define IDG_CROSS   5010    // 교차로
#define IDG_ALLEY   5011    // 골목길
#define IDG_ROTARY_DOWN   5012    // 로터리
#define IDG_ROUNDABOUT   5013    // 회전교차로
#define IDG_TO   5014    // 전에서
#define IDS_NOTICE_ANOTHERROAD   5015    // 다른 가까운 도로에 주의하세요
#define IDG_IMMEDIATELY   5016    // 바로
#define IDG_RIGHT_01   5017    // 오른쪽 한시방향
#define IDG_RIGHT_02   5018    // 오른쪽 두시방향
#define IDG_RIGHT_03   5019    // 오른쪽 세시방향
#define IDG_RIGHT_04   5020    // 오른쪽 네시방향
#define IDG_RIGHT_05   5021    // 오른쪽 다섯시방향
#define IDG_CENTER_06   5022    // 여섯시방향
#define IDG_LEFT_07   5023    // 왼쪽 일곱시방향
#define IDG_LEFT_08   5024    // 왼쪽 여덟시방향
#define IDG_LEFT_09   5025    // 왼쪽 아홉시방향
#define IDG_LEFT_10   5026    // 왼쪽 열시방향
#define IDG_LEFT_11   5027    // 왼쪽 열한시방향
#define IDG_CENTER_12   5028    // 열두시방향
#define IDG_EXIT   5029    // 출구입니다
#define IDG_JOIN_ROAD   5030    // 다시 합쳐지는 도로입니다
#define IDG_IS_IN_TUNNEL   5031    // 터널 진입입니다.
#define IDG_TUNNEL_AFTER_OUT   5032    // 터널 진출 직후
#define IDG_TOLL   5033    // 요금은
#define IDG_IS_WAYPOINT   5034    // 경유지입니다
#define IDG_IS_DESTINATION   5035    // 목적지입니다
#define IDG_IS_ABOUT_DESTINATION   5036    // 목적지 부근에 도착했습니다.
#define IDG_DRIVED   5037    // 주행했습니다.
#define IDG_HOURLY_SPEED   5038    // 시속
#define IDG_IS_BUST   5039    // 단속구간입니다.
#define IDG_SECTIONSPEED_ENDPOINT   5040    // 구간단속 종료지점입니다.
#define IDG_SECTIONSPEED_ING   5041    // 구간단속 중입니다.
#define IDG_AVERAGE_SPEED_CHECK   5042    // 평균속도를 확인하세요
#define IDG_FIRETRUCK   5043    // 소방차 통행로입니다. 주정차를 피해주세요.
#define IDG_PARKING_SPOT   5044    // 주정차 단속 지점입니다.
#define IDG_PARKING_AREA   5045    // 주정차 단속 지역입니다.
#define IDG_SIGNAL   5046    // 신호를 지켜주세요
#define IDG_MAXSPEED   5047    // 제한속도를 지켜주세요
#define IDG_YIELD   5048    // 양보운전 하세요
#define IDG_DESTINATION   5049    // 목적지를 확인하세요
#define IDG_SLOWDOWN   5050    // 서행해 주세요
#define IDG_DIRECTION   5051    // 진행방향을 확인하세요
#define IDG_SPEEDDOWN   5052    // 속도를 줄여주세요
#define IDG_VEHICLE_CONTROL   5053    // 차량 통제 구간입니다.
#define IDG_JAM_AREA_START   5054    // 정체구간이 시작됩니다.
#define IDG_DECELERATION   5055    // 급감속에 대비하세요
#define IDG_CRASH   5056    // 추돌에 주의하세요
#define IDG_JAM_AREA   5057    // 정체구간입니다.
#define IDG_FOR_ACCIDENT_1   5058    // 사고로 인한
#define IDG_FOR_CONSTRUCTION_1   5059    // 공사로 인한
#define IDG_FOR_EVENT_1   5060    // 행사로 인한
#define IDG_FOR_ROAD_DAMAGE   5061    // 도로 파손으로 인한
#define IDG_JAM_PREDICT   5062    // 가량 정체가 예상됩니다.
#define IDG_FROM_LOCATION   5063    // 부터
#define IDG_TO_LOCATION   5064    // 까지
#define IDG_JAM_ING   5065    // 구간 정체중입니다.
#define IDG_GA   5066    // 가
#define IDG_II   5067    // 이
#define IDG_IS_MOREFAST   5068    // 더 빠릅니다.
#define IDG_TO_RIGHT   5069    // 오른쪽
#define IDG_TO_LEFT   5070    // 왼쪽
#define IDG_STRAIGHT   5071    // 직진방향
#define IDG_IS_IN   5072    // 로 진입하세요.
#define IDG_RIGHT_ROAD   5073    // 오른쪽 도로
#define IDG_LEFT_ROAD   5074    // 왼쪽 도로
#define IDG_TO_EXP_OUT_RIGHT_NEW   5075    // 오른쪽 고속도로출구로 진출하세요.
#define IDG_TO_EXP_OUT_LEFT_NEW   5076    // 왼쪽 고속도로출구로 진출하세요
#define IDG_TO_EXP_OUT_CENTER_NEW   5077    // 직진방향 고속도로출구로 진출하세요.
#define IDG_TO_UEXP_OUT_RIGHT_NEW   5078    // 오른쪽 고속화도로 출구로 진출하세요
#define IDG_TO_UEXP_OUT_LEFT_NEW   5079    // 왼쪽 고속화도로 출구로 진출하세요
#define IDG_TO_UEXP_OUT_CENTER_NEW   5080    // 직진방향 고속화도로 출구로 진출하세요.
#define IDG_1ST   5081    // 첫번째
#define IDG_2ND   5082    // 두번째
#define IDG_3RD   5083    // 세번째
#define IDG_4TH   5084    // 네번째
#define IDG_5TH   5085    // 다섯번째
#define IDG_6TH   5086    // 여섯번째
#define IDG_7TH   5087    // 일곱번째
#define IDG_8TH   5088    // 여덟번째
#define IDG_9TH   5089    // 아홉번째
#define IDG_10TH   5090    // 열번째
#define IDG_TORIGHT   5091    // 오른쪽에
#define IDG_TOLEFT   5092    // 왼쪽에
#define IDG_TOSTRAIGHT   5093    // 직진방향에
#define IDG_IN_TUNNEL_AFTER   5094    // 터널 진입 후
#define IDS_CHECK_SIGN   5095    // 표지판을 확인하세요
#define IDS_CHANGABLE_SECTION_START   5096    // 가변 구간 단속 시작지점입니다
#define IDS_CHECK_SPEED_SIGN   5097    // 속도 표지판을 확인하세요
#define IDS_CHANGABLE_SECTION_CHECKING   5098    // 가변 구간 단속 중입니다
#define IDS_CHANGABLE_SECTION_END   5099    // 가변 구간 단속 종료 지점입니다
#define IDG_ABOUT   5100    // 약
#define IDS_SPEED10_ONLY   5101    // 시속 10km
#define IDS_SPEED20_ONLY   5102    // 시속 20km
#define IDS_SPEED30_ONLY   5103    // 시속 30km
#define IDS_SPEED40_ONLY   5104    // 시속 40km
#define IDS_SPEED50_ONLY   5105    // 시속 50km
#define IDS_SPEED60_ONLY   5106    // 시속 60km
#define IDS_SPEED70_ONLY   5107    // 시속 70km
#define IDS_SPEED80_ONLY   5108    // 시속 80km
#define IDS_SPEED90_ONLY   5109    // 시속 90km
#define IDS_SPEED100_ONLY   5110    // 시속 100km
#define IDS_SPEED110_ONLY   5111    // 시속 110km
#define IDS_SPEED120_ONLY   5112    // 시속 120km
#define IDS_SPEED130_ONLY   5113    // 시속 130km
#define IDS_SPEED140_ONLY   5114    // 시속 140km
#define IDS_SPEED150_ONLY   5115    // 시속 150km
#define IDM_0001000_UPTO   5116    // 1킬로미터까지
#define IDM_0001100_UPTO   5117    // 1.1킬로미터까지
#define IDM_0001200_UPTO   5118    // 1.2킬로미터까지
#define IDM_0001300_UPTO   5119    // 1.3킬로미터까지
#define IDM_0001400_UPTO   5120    // 1.4킬로미터까지
#define IDM_0001500_UPTO   5121    // 1.5킬로미터까지
#define IDM_0001600_UPTO   5122    // 1.6킬로미터까지
#define IDM_0001700_UPTO   5123    // 1.7킬로미터까지
#define IDM_0001800_UPTO   5124    // 1.8킬로미터까지
#define IDM_0001900_UPTO   5125    // 1.9킬로미터까지
#define IDM_0002000_UPTO   5126    // 2킬로미터까지
#define IDM_0002100_UPTO   5127    // 2.1킬로미터까지
#define IDM_0002200_UPTO   5128    // 2.2킬로미터까지
#define IDM_0002300_UPTO   5129    // 2.3킬로미터까지
#define IDM_0002400_UPTO   5130    // 2.4킬로미터까지
#define IDM_0002500_UPTO   5131    // 2.5킬로미터까지
#define IDM_0002600_UPTO   5132    // 2.6킬로미터까지
#define IDM_0002700_UPTO   5133    // 2.7킬로미터까지
#define IDM_0002800_UPTO   5134    // 2.8킬로미터까지
#define IDM_0002900_UPTO   5135    // 2.9킬로미터까지
#define IDM_0003000_UPTO   5136    // 3킬로미터까지
#define IDM_0003100_UPTO   5137    // 3.1킬로미터까지
#define IDM_0003200_UPTO   5138    // 3.2킬로미터까지
#define IDM_0003300_UPTO   5139    // 3.3킬로미터까지
#define IDM_0003400_UPTO   5140    // 3.4킬로미터까지
#define IDM_0003500_UPTO   5141    // 3.5킬로미터까지
#define IDM_0003600_UPTO   5142    // 3.6킬로미터까지
#define IDM_0003700_UPTO   5143    // 3.7킬로미터까지
#define IDM_0003800_UPTO   5144    // 3.8킬로미터까지
#define IDM_0003900_UPTO   5145    // 3.9킬로미터까지
#define IDM_0004000_UPTO   5146    // 4킬로미터까지
#define IDM_0004100_UPTO   5147    // 4.1킬로미터까지
#define IDM_0004200_UPTO   5148    // 4.2킬로미터까지
#define IDM_0004300_UPTO   5149    // 4.3킬로미터까지
#define IDM_0004400_UPTO   5150    // 4.4킬로미터까지
#define IDM_0004500_UPTO   5151    // 4.5킬로미터까지
#define IDM_0004600_UPTO   5152    // 4.6킬로미터까지
#define IDM_0004700_UPTO   5153    // 4.7킬로미터까지
#define IDM_0004800_UPTO   5154    // 4.8킬로미터까지
#define IDM_0004900_UPTO   5155    // 4.9킬로미터까지
#define IDM_0005000_UPTO   5156    // 5킬로미터까지
#define IDM_0005100_UPTO   5157    // 5.1킬로미터까지
#define IDM_0005200_UPTO   5158    // 5.2킬로미터까지
#define IDM_0005300_UPTO   5159    // 5.3킬로미터까지
#define IDM_0005400_UPTO   5160    // 5.4킬로미터까지
#define IDM_0005500_UPTO   5161    // 5.5킬로미터까지
#define IDM_0005600_UPTO   5162    // 5.6킬로미터까지
#define IDM_0005700_UPTO   5163    // 5.7킬로미터까지
#define IDM_0005800_UPTO   5164    // 5.8킬로미터까지
#define IDM_0005900_UPTO   5165    // 5.9킬로미터까지
#define IDM_0006000_UPTO   5166    // 6킬로미터까지
#define IDM_0006100_UPTO   5167    // 6.1킬로미터까지
#define IDM_0006200_UPTO   5168    // 6.2킬로미터까지
#define IDM_0006300_UPTO   5169    // 6.3킬로미터까지
#define IDM_0006400_UPTO   5170    // 6.4킬로미터까지
#define IDM_0006500_UPTO   5171    // 6.5킬로미터까지
#define IDM_0006600_UPTO   5172    // 6.6킬로미터까지
#define IDM_0006700_UPTO   5173    // 6.7킬로미터까지
#define IDM_0006800_UPTO   5174    // 6.8킬로미터까지
#define IDM_0006900_UPTO   5175    // 6.9킬로미터까지
#define IDM_0007000_UPTO   5176    // 7킬로미터까지
#define IDM_0007100_UPTO   5177    // 7.1킬로미터까지
#define IDM_0007200_UPTO   5178    // 7.2킬로미터까지
#define IDM_0007300_UPTO   5179    // 7.3킬로미터까지
#define IDM_0007400_UPTO   5180    // 7.4킬로미터까지
#define IDM_0007500_UPTO   5181    // 7.5킬로미터까지
#define IDM_0007600_UPTO   5182    // 7.6킬로미터까지
#define IDM_0007700_UPTO   5183    // 7.7킬로미터까지
#define IDM_0007800_UPTO   5184    // 7.8킬로미터까지
#define IDM_0007900_UPTO   5185    // 7.9킬로미터까지
#define IDM_0008000_UPTO   5186    // 8킬로미터까지
#define IDM_0008100_UPTO   5187    // 8.1킬로미터까지
#define IDM_0008200_UPTO   5188    // 8.2킬로미터까지
#define IDM_0008300_UPTO   5189    // 8.3킬로미터까지
#define IDM_0008400_UPTO   5190    // 8.4킬로미터까지
#define IDM_0008500_UPTO   5191    // 8.5킬로미터까지
#define IDM_0008600_UPTO   5192    // 8.6킬로미터까지
#define IDM_0008700_UPTO   5193    // 8.7킬로미터까지
#define IDM_0008800_UPTO   5194    // 8.8킬로미터까지
#define IDM_0008900_UPTO   5195    // 8.9킬로미터까지
#define IDM_0009000_UPTO   5196    // 9킬로미터까지
#define IDM_0009100_UPTO   5197    // 9.1킬로미터까지
#define IDM_0009200_UPTO   5198    // 9.2킬로미터까지
#define IDM_0009300_UPTO   5199    // 9.3킬로미터까지
#define IDM_0009400_UPTO   5200    // 9.4킬로미터까지
#define IDM_0009500_UPTO   5201    // 9.5킬로미터까지
#define IDM_0009600_UPTO   5202    // 9.6킬로미터까지
#define IDM_0009700_UPTO   5203    // 9.7킬로미터까지
#define IDM_0009800_UPTO   5204    // 9.8킬로미터까지
#define IDM_0009900_UPTO   5205    // 9.9킬로미터까지
#define IDM_0010000_UPTO   5206    // 10킬로미터까지
#define IDM_0010100_UPTO   5207    // 10.1킬로미터까지
#define IDM_0010200_UPTO   5208    // 10.2킬로미터까지
#define IDM_0010300_UPTO   5209    // 10.3킬로미터까지
#define IDM_0010400_UPTO   5210    // 10.4킬로미터까지
#define IDM_0010500_UPTO   5211    // 10.5킬로미터까지
#define IDM_0010600_UPTO   5212    // 10.6킬로미터까지
#define IDM_0010700_UPTO   5213    // 10.7킬로미터까지
#define IDM_0010800_UPTO   5214    // 10.8킬로미터까지
#define IDM_0010900_UPTO   5215    // 10.9킬로미터까지
#define IDM_0011000_UPTO   5216    // 11킬로미터까지
#define IDM_0011100_UPTO   5217    // 11.1킬로미터까지
#define IDM_0011200_UPTO   5218    // 11.2킬로미터까지
#define IDM_0011300_UPTO   5219    // 11.3킬로미터까지
#define IDM_0011400_UPTO   5220    // 11.4킬로미터까지
#define IDM_0011500_UPTO   5221    // 11.5킬로미터까지
#define IDM_0011600_UPTO   5222    // 11.6킬로미터까지
#define IDM_0011700_UPTO   5223    // 11.7킬로미터까지
#define IDM_0011800_UPTO   5224    // 11.8킬로미터까지
#define IDM_0011900_UPTO   5225    // 11.9킬로미터까지
#define IDM_0012000_UPTO   5226    // 12킬로미터까지
#define IDM_0012100_UPTO   5227    // 12.1킬로미터까지
#define IDM_0012200_UPTO   5228    // 12.2킬로미터까지
#define IDM_0012300_UPTO   5229    // 12.3킬로미터까지
#define IDM_0012400_UPTO   5230    // 12.4킬로미터까지
#define IDM_0012500_UPTO   5231    // 12.5킬로미터까지
#define IDM_0012600_UPTO   5232    // 12.6킬로미터까지
#define IDM_0012700_UPTO   5233    // 12.7킬로미터까지
#define IDM_0012800_UPTO   5234    // 12.8킬로미터까지
#define IDM_0012900_UPTO   5235    // 12.9킬로미터까지
#define IDM_0013000_UPTO   5236    // 13킬로미터까지
#define IDM_0013100_UPTO   5237    // 13.1킬로미터까지
#define IDM_0013200_UPTO   5238    // 13.2킬로미터까지
#define IDM_0013300_UPTO   5239    // 13.3킬로미터까지
#define IDM_0013400_UPTO   5240    // 13.4킬로미터까지
#define IDM_0013500_UPTO   5241    // 13.5킬로미터까지
#define IDM_0013600_UPTO   5242    // 13.6킬로미터까지
#define IDM_0013700_UPTO   5243    // 13.7킬로미터까지
#define IDM_0013800_UPTO   5244    // 13.8킬로미터까지
#define IDM_0013900_UPTO   5245    // 13.9킬로미터까지
#define IDM_0014000_UPTO   5246    // 14킬로미터까지
#define IDM_0014100_UPTO   5247    // 14.1킬로미터까지
#define IDM_0014200_UPTO   5248    // 14.2킬로미터까지
#define IDM_0014300_UPTO   5249    // 14.3킬로미터까지
#define IDM_0014400_UPTO   5250    // 14.4킬로미터까지
#define IDM_0014500_UPTO   5251    // 14.5킬로미터까지
#define IDM_0014600_UPTO   5252    // 14.6킬로미터까지
#define IDM_0014700_UPTO   5253    // 14.7킬로미터까지
#define IDM_0014800_UPTO   5254    // 14.8킬로미터까지
#define IDM_0014900_UPTO   5255    // 14.9킬로미터까지
#define IDM_0015000_UPTO   5256    // 15킬로미터까지
#define IDM_0015100_UPTO   5257    // 15.1킬로미터까지
#define IDM_0015200_UPTO   5258    // 15.2킬로미터까지
#define IDM_0015300_UPTO   5259    // 15.3킬로미터까지
#define IDM_0015400_UPTO   5260    // 15.4킬로미터까지
#define IDM_0015500_UPTO   5261    // 15.5킬로미터까지
#define IDM_0015600_UPTO   5262    // 15.6킬로미터까지
#define IDM_0015700_UPTO   5263    // 15.7킬로미터까지
#define IDM_0015800_UPTO   5264    // 15.8킬로미터까지
#define IDM_0015900_UPTO   5265    // 15.9킬로미터까지
#define IDM_0016000_UPTO   5266    // 16킬로미터까지
#define IDM_0016100_UPTO   5267    // 16.1킬로미터까지
#define IDM_0016200_UPTO   5268    // 16.2킬로미터까지
#define IDM_0016300_UPTO   5269    // 16.3킬로미터까지
#define IDM_0016400_UPTO   5270    // 16.4킬로미터까지
#define IDM_0016500_UPTO   5271    // 16.5킬로미터까지
#define IDM_0016600_UPTO   5272    // 16.6킬로미터까지
#define IDM_0016700_UPTO   5273    // 16.7킬로미터까지
#define IDM_0016800_UPTO   5274    // 16.8킬로미터까지
#define IDM_0016900_UPTO   5275    // 16.9킬로미터까지
#define IDM_0017000_UPTO   5276    // 17킬로미터까지
#define IDM_0017100_UPTO   5277    // 17.1킬로미터까지
#define IDM_0017200_UPTO   5278    // 17.2킬로미터까지
#define IDM_0017300_UPTO   5279    // 17.3킬로미터까지
#define IDM_0017400_UPTO   5280    // 17.4킬로미터까지
#define IDM_0017500_UPTO   5281    // 17.5킬로미터까지
#define IDM_0017600_UPTO   5282    // 17.6킬로미터까지
#define IDM_0017700_UPTO   5283    // 17.7킬로미터까지
#define IDM_0017800_UPTO   5284    // 17.8킬로미터까지
#define IDM_0017900_UPTO   5285    // 17.9킬로미터까지
#define IDM_0018000_UPTO   5286    // 18킬로미터까지
#define IDM_0018100_UPTO   5287    // 18.1킬로미터까지
#define IDM_0018200_UPTO   5288    // 18.2킬로미터까지
#define IDM_0018300_UPTO   5289    // 18.3킬로미터까지
#define IDM_0018400_UPTO   5290    // 18.4킬로미터까지
#define IDM_0018500_UPTO   5291    // 18.5킬로미터까지
#define IDM_0018600_UPTO   5292    // 18.6킬로미터까지
#define IDM_0018700_UPTO   5293    // 18.7킬로미터까지
#define IDM_0018800_UPTO   5294    // 18.8킬로미터까지
#define IDM_0018900_UPTO   5295    // 18.9킬로미터까지
#define IDM_0019000_UPTO   5296    // 19킬로미터까지
#define IDM_0019100_UPTO   5297    // 19.1킬로미터까지
#define IDM_0019200_UPTO   5298    // 19.2킬로미터까지
#define IDM_0019300_UPTO   5299    // 19.3킬로미터까지
#define IDM_0019400_UPTO   5300    // 19.4킬로미터까지
#define IDM_0019500_UPTO   5301    // 19.5킬로미터까지
#define IDM_0019600_UPTO   5302    // 19.6킬로미터까지
#define IDM_0019700_UPTO   5303    // 19.7킬로미터까지
#define IDM_0019800_UPTO   5304    // 19.8킬로미터까지
#define IDM_0019900_UPTO   5305    // 19.9킬로미터까지
#define IDM_0020000_UPTO   5306    // 20킬로미터까지
#define IDM_0020000_OVER   5307    // 20킬로미터이상
#define IDG_TIME_ABOUT_01_H   5308    // 1시간 가량
#define IDG_TIME_ABOUT_02_H   5309    // 2시간 가량
#define IDG_TIME_ABOUT_03_H   5310    // 3시간 가량
#define IDG_TIME_ABOUT_04_H   5311    // 4시간 가량
#define IDG_TIME_ABOUT_05_H   5312    // 5시간 가량
#define IDG_TIME_ABOUT_06_H   5313    // 6시간 가량
#define IDG_TIME_ABOUT_07_H   5314    // 7시간 가량
#define IDG_TIME_ABOUT_08_H   5315    // 8시간 가량
#define IDG_TIME_ABOUT_09_H   5316    // 9시간 가량
#define IDG_TIME_ABOUT_10_H   5317    // 10시간 가량
#define IDG_TIME_ABOUT_11_H   5318    // 11시간 가량
#define IDG_TIME_ABOUT_12_H   5319    // 12시간 가량
#define IDG_TIME_ABOUT_13_H   5320    // 13시간 가량
#define IDG_TIME_ABOUT_14_H   5321    // 14시간 가량
#define IDG_TIME_ABOUT_15_H   5322    // 15시간 가량
#define IDG_TIME_ABOUT_16_H   5323    // 16시간 가량
#define IDG_TIME_ABOUT_17_H   5324    // 17시간 가량
#define IDG_TIME_ABOUT_18_H   5325    // 18시간 가량
#define IDG_TIME_ABOUT_19_H   5326    // 19시간 가량
#define IDG_TIME_ABOUT_20_H   5327    // 20시간 가량
#define IDG_TIME_ABOUT_21_H   5328    // 21시간 가량
#define IDG_TIME_ABOUT_22_H   5329    // 22시간 가량
#define IDG_TIME_ABOUT_23_H   5330    // 23시간 가량
#define IDG_TIME_ABOUT_01_M   5331    // 1분 가량
#define IDG_TIME_ABOUT_02_M   5332    // 2분 가량
#define IDG_TIME_ABOUT_03_M   5333    // 3분 가량
#define IDG_TIME_ABOUT_04_M   5334    // 4분 가량
#define IDG_TIME_ABOUT_05_M   5335    // 5분 가량
#define IDG_TIME_ABOUT_06_M   5336    // 6분 가량
#define IDG_TIME_ABOUT_07_M   5337    // 7분 가량
#define IDG_TIME_ABOUT_08_M   5338    // 8분 가량
#define IDG_TIME_ABOUT_09_M   5339    // 9분 가량
#define IDG_TIME_ABOUT_10_M   5340    // 10분 가량
#define IDG_TIME_ABOUT_11_M   5341    // 11분 가량
#define IDG_TIME_ABOUT_12_M   5342    // 12분 가량
#define IDG_TIME_ABOUT_13_M   5343    // 13분 가량
#define IDG_TIME_ABOUT_14_M   5344    // 14분 가량
#define IDG_TIME_ABOUT_15_M   5345    // 15분 가량
#define IDG_TIME_ABOUT_16_M   5346    // 16분 가량
#define IDG_TIME_ABOUT_17_M   5347    // 17분 가량
#define IDG_TIME_ABOUT_18_M   5348    // 18분 가량
#define IDG_TIME_ABOUT_19_M   5349    // 19분 가량
#define IDG_TIME_ABOUT_20_M   5350    // 20분 가량
#define IDG_TIME_ABOUT_21_M   5351    // 21분 가량
#define IDG_TIME_ABOUT_22_M   5352    // 22분 가량
#define IDG_TIME_ABOUT_23_M   5353    // 23분 가량
#define IDG_TIME_ABOUT_24_M   5354    // 24분 가량
#define IDG_TIME_ABOUT_25_M   5355    // 25분 가량
#define IDG_TIME_ABOUT_26_M   5356    // 26분 가량
#define IDG_TIME_ABOUT_27_M   5357    // 27분 가량
#define IDG_TIME_ABOUT_28_M   5358    // 28분 가량
#define IDG_TIME_ABOUT_29_M   5359    // 29분 가량
#define IDG_TIME_ABOUT_30_M   5360    // 30분 가량
#define IDG_TIME_ABOUT_31_M   5361    // 31분 가량
#define IDG_TIME_ABOUT_32_M   5362    // 32분 가량
#define IDG_TIME_ABOUT_33_M   5363    // 33분 가량
#define IDG_TIME_ABOUT_34_M   5364    // 34분 가량
#define IDG_TIME_ABOUT_35_M   5365    // 35분 가량
#define IDG_TIME_ABOUT_36_M   5366    // 36분 가량
#define IDG_TIME_ABOUT_37_M   5367    // 37분 가량
#define IDG_TIME_ABOUT_38_M   5368    // 38분 가량
#define IDG_TIME_ABOUT_39_M   5369    // 39분 가량
#define IDG_TIME_ABOUT_40_M   5370    // 40분 가량
#define IDG_TIME_ABOUT_41_M   5371    // 41분 가량
#define IDG_TIME_ABOUT_42_M   5372    // 42분 가량
#define IDG_TIME_ABOUT_43_M   5373    // 43분 가량
#define IDG_TIME_ABOUT_44_M   5374    // 44분 가량
#define IDG_TIME_ABOUT_45_M   5375    // 45분 가량
#define IDG_TIME_ABOUT_46_M   5376    // 46분 가량
#define IDG_TIME_ABOUT_47_M   5377    // 47분 가량
#define IDG_TIME_ABOUT_48_M   5378    // 48분 가량
#define IDG_TIME_ABOUT_49_M   5379    // 49분 가량
#define IDG_TIME_ABOUT_50_M   5380    // 50분 가량
#define IDG_TIME_ABOUT_51_M   5381    // 51분 가량
#define IDG_TIME_ABOUT_52_M   5382    // 52분 가량
#define IDG_TIME_ABOUT_53_M   5383    // 53분 가량
#define IDG_TIME_ABOUT_54_M   5384    // 54분 가량
#define IDG_TIME_ABOUT_55_M   5385    // 55분 가량
#define IDG_TIME_ABOUT_56_M   5386    // 56분 가량
#define IDG_TIME_ABOUT_57_M   5387    // 57분 가량
#define IDG_TIME_ABOUT_58_M   5388    // 58분 가량
#define IDG_TIME_ABOUT_59_M   5389    // 59분 가량
#define IDM_0000500_AH_UPTO   5390    // 500미터앞까지
#define IDM_0000510_AH_UPTO   5391    // 510미터앞까지
#define IDM_0000520_AH_UPTO   5392    // 520미터앞까지
#define IDM_0000530_AH_UPTO   5393    // 530미터앞까지
#define IDM_0000540_AH_UPTO   5394    // 540미터앞까지
#define IDM_0000550_AH_UPTO   5395    // 550미터앞까지
#define IDM_0000560_AH_UPTO   5396    // 560미터앞까지
#define IDM_0000570_AH_UPTO   5397    // 570미터앞까지
#define IDM_0000580_AH_UPTO   5398    // 580미터앞까지
#define IDM_0000590_AH_UPTO   5399    // 590미터앞까지
#define IDM_0000600_AH_UPTO   5400    // 600미터앞까지
#define IDM_0000610_AH_UPTO   5401    // 610미터앞까지
#define IDM_0000620_AH_UPTO   5402    // 620미터앞까지
#define IDM_0000630_AH_UPTO   5403    // 630미터앞까지
#define IDM_0000640_AH_UPTO   5404    // 640미터앞까지
#define IDM_0000650_AH_UPTO   5405    // 650미터앞까지
#define IDM_0000660_AH_UPTO   5406    // 660미터앞까지
#define IDM_0000670_AH_UPTO   5407    // 670미터앞까지
#define IDM_0000680_AH_UPTO   5408    // 680미터앞까지
#define IDM_0000690_AH_UPTO   5409    // 690미터앞까지
#define IDM_0000700_AH_UPTO   5410    // 700미터앞까지
#define IDM_0000710_AH_UPTO   5411    // 710미터앞까지
#define IDM_0000720_AH_UPTO   5412    // 720미터앞까지
#define IDM_0000730_AH_UPTO   5413    // 730미터앞까지
#define IDM_0000740_AH_UPTO   5414    // 740미터앞까지
#define IDM_0000750_AH_UPTO   5415    // 750미터앞까지
#define IDM_0000760_AH_UPTO   5416    // 760미터앞까지
#define IDM_0000770_AH_UPTO   5417    // 770미터앞까지
#define IDM_0000780_AH_UPTO   5418    // 780미터앞까지
#define IDM_0000790_AH_UPTO   5419    // 790미터앞까지
#define IDM_0000800_AH_UPTO   5420    // 800미터앞까지
#define IDM_0000810_AH_UPTO   5421    // 810미터앞까지
#define IDM_0000820_AH_UPTO   5422    // 820미터앞까지
#define IDM_0000830_AH_UPTO   5423    // 830미터앞까지
#define IDM_0000840_AH_UPTO   5424    // 840미터앞까지
#define IDM_0000850_AH_UPTO   5425    // 850미터앞까지
#define IDM_0000860_AH_UPTO   5426    // 860미터앞까지
#define IDM_0000870_AH_UPTO   5427    // 870미터앞까지
#define IDM_0000880_AH_UPTO   5428    // 880미터앞까지
#define IDM_0000890_AH_UPTO   5429    // 890미터앞까지
#define IDM_0000900_AH_UPTO   5430    // 900미터앞까지
#define IDM_0000910_AH_UPTO   5431    // 910미터앞까지
#define IDM_0000920_AH_UPTO   5432    // 920미터앞까지
#define IDM_0000930_AH_UPTO   5433    // 930미터앞까지
#define IDM_0000940_AH_UPTO   5434    // 940미터앞까지
#define IDM_0000950_AH_UPTO   5435    // 950미터앞까지
#define IDM_0000960_AH_UPTO   5436    // 960미터앞까지
#define IDM_0000970_AH_UPTO   5437    // 970미터앞까지
#define IDM_0000980_AH_UPTO   5438    // 980미터앞까지
#define IDM_0000990_AH_UPTO   5439    // 990미터앞까지
#define IDM_0001000_AH_UPTO   5440    // 1킬로미터앞까지
#define IDM_0001100_AH_UPTO   5441    // 1.1킬로미터앞까지
#define IDM_0001200_AH_UPTO   5442    // 1.2킬로미터앞까지
#define IDM_0001300_AH_UPTO   5443    // 1.3킬로미터앞까지
#define IDM_0001400_AH_UPTO   5444    // 1.4킬로미터앞까지
#define IDM_0001500_AH_UPTO   5445    // 1.5킬로미터앞까지
#define IDM_0001600_AH_UPTO   5446    // 1.6킬로미터앞까지
#define IDM_0001700_AH_UPTO   5447    // 1.7킬로미터앞까지
#define IDM_0001800_AH_UPTO   5448    // 1.8킬로미터앞까지
#define IDM_0001900_AH_UPTO   5449    // 1.9킬로미터앞까지
#define IDM_0002000_AH_UPTO   5450    // 2킬로미터앞까지
#define IDM_0002100_AH_UPTO   5451    // 2.1킬로미터앞까지
#define IDM_0002200_AH_UPTO   5452    // 2.2킬로미터앞까지
#define IDM_0002300_AH_UPTO   5453    // 2.3킬로미터앞까지
#define IDM_0002400_AH_UPTO   5454    // 2.4킬로미터앞까지
#define IDM_0002500_AH_UPTO   5455    // 2.5킬로미터앞까지
#define IDM_0002600_AH_UPTO   5456    // 2.6킬로미터앞까지
#define IDM_0002700_AH_UPTO   5457    // 2.7킬로미터앞까지
#define IDM_0002800_AH_UPTO   5458    // 2.8킬로미터앞까지
#define IDM_0002900_AH_UPTO   5459    // 2.9킬로미터앞까지
#define IDM_0003000_AH_UPTO   5460    // 3킬로미터앞까지
#define IDM_0003100_AH_UPTO   5461    // 3.1킬로미터앞까지
#define IDM_0003200_AH_UPTO   5462    // 3.2킬로미터앞까지
#define IDM_0003300_AH_UPTO   5463    // 3.3킬로미터앞까지
#define IDM_0003400_AH_UPTO   5464    // 3.4킬로미터앞까지
#define IDM_0003500_AH_UPTO   5465    // 3.5킬로미터앞까지
#define IDM_0003600_AH_UPTO   5466    // 3.6킬로미터앞까지
#define IDM_0003700_AH_UPTO   5467    // 3.7킬로미터앞까지
#define IDM_0003800_AH_UPTO   5468    // 3.8킬로미터앞까지
#define IDM_0003900_AH_UPTO   5469    // 3.9킬로미터앞까지
#define IDM_0004000_AH_UPTO   5470    // 4킬로미터앞까지
#define IDM_0004100_AH_UPTO   5471    // 4.1킬로미터앞까지
#define IDM_0004200_AH_UPTO   5472    // 4.2킬로미터앞까지
#define IDM_0004300_AH_UPTO   5473    // 4.3킬로미터앞까지
#define IDM_0004400_AH_UPTO   5474    // 4.4킬로미터앞까지
#define IDM_0004500_AH_UPTO   5475    // 4.5킬로미터앞까지
#define IDM_0004600_AH_UPTO   5476    // 4.6킬로미터앞까지
#define IDM_0004700_AH_UPTO   5477    // 4.7킬로미터앞까지
#define IDM_0004800_AH_UPTO   5478    // 4.8킬로미터앞까지
#define IDM_0004900_AH_UPTO   5479    // 4.9킬로미터앞까지
#define IDM_0005000_AH_UPTO   5480    // 5킬로미터앞까지
#define IDM_0005100_AH_UPTO   5481    // 5.1킬로미터앞까지
#define IDM_0005200_AH_UPTO   5482    // 5.2킬로미터앞까지
#define IDM_0005300_AH_UPTO   5483    // 5.3킬로미터앞까지
#define IDM_0005400_AH_UPTO   5484    // 5.4킬로미터앞까지
#define IDM_0005500_AH_UPTO   5485    // 5.5킬로미터앞까지
#define IDM_0005600_AH_UPTO   5486    // 5.6킬로미터앞까지
#define IDM_0005700_AH_UPTO   5487    // 5.7킬로미터앞까지
#define IDM_0005800_AH_UPTO   5488    // 5.8킬로미터앞까지
#define IDM_0005900_AH_UPTO   5489    // 5.9킬로미터앞까지
#define IDM_0006000_AH_UPTO   5490    // 6킬로미터앞까지
#define IDM_0006100_AH_UPTO   5491    // 6.1킬로미터앞까지
#define IDM_0006200_AH_UPTO   5492    // 6.2킬로미터앞까지
#define IDM_0006300_AH_UPTO   5493    // 6.3킬로미터앞까지
#define IDM_0006400_AH_UPTO   5494    // 6.4킬로미터앞까지
#define IDM_0006500_AH_UPTO   5495    // 6.5킬로미터앞까지
#define IDM_0006600_AH_UPTO   5496    // 6.6킬로미터앞까지
#define IDM_0006700_AH_UPTO   5497    // 6.7킬로미터앞까지
#define IDM_0006800_AH_UPTO   5498    // 6.8킬로미터앞까지
#define IDM_0006900_AH_UPTO   5499    // 6.9킬로미터앞까지
#define IDM_0007000_AH_UPTO   5500    // 7킬로미터앞까지
#define IDM_0007100_AH_UPTO   5501    // 7.1킬로미터앞까지
#define IDM_0007200_AH_UPTO   5502    // 7.2킬로미터앞까지
#define IDM_0007300_AH_UPTO   5503    // 7.3킬로미터앞까지
#define IDM_0007400_AH_UPTO   5504    // 7.4킬로미터앞까지
#define IDM_0007500_AH_UPTO   5505    // 7.5킬로미터앞까지
#define IDM_0007600_AH_UPTO   5506    // 7.6킬로미터앞까지
#define IDM_0007700_AH_UPTO   5507    // 7.7킬로미터앞까지
#define IDM_0007800_AH_UPTO   5508    // 7.8킬로미터앞까지
#define IDM_0007900_AH_UPTO   5509    // 7.9킬로미터앞까지
#define IDM_0008000_AH_UPTO   5510    // 8킬로미터앞까지
#define IDM_0008100_AH_UPTO   5511    // 8.1킬로미터앞까지
#define IDM_0008200_AH_UPTO   5512    // 8.2킬로미터앞까지
#define IDM_0008300_AH_UPTO   5513    // 8.3킬로미터앞까지
#define IDM_0008400_AH_UPTO   5514    // 8.4킬로미터앞까지
#define IDM_0008500_AH_UPTO   5515    // 8.5킬로미터앞까지
#define IDM_0008600_AH_UPTO   5516    // 8.6킬로미터앞까지
#define IDM_0008700_AH_UPTO   5517    // 8.7킬로미터앞까지
#define IDM_0008800_AH_UPTO   5518    // 8.8킬로미터앞까지
#define IDM_0008900_AH_UPTO   5519    // 8.9킬로미터앞까지
#define IDM_0009000_AH_UPTO   5520    // 9킬로미터앞까지
#define IDM_0009100_AH_UPTO   5521    // 9.1킬로미터앞까지
#define IDM_0009200_AH_UPTO   5522    // 9.2킬로미터앞까지
#define IDM_0009300_AH_UPTO   5523    // 9.3킬로미터앞까지
#define IDM_0009400_AH_UPTO   5524    // 9.4킬로미터앞까지
#define IDM_0009500_AH_UPTO   5525    // 9.5킬로미터앞까지
#define IDM_0009600_AH_UPTO   5526    // 9.6킬로미터앞까지
#define IDM_0009700_AH_UPTO   5527    // 9.7킬로미터앞까지
#define IDM_0009800_AH_UPTO   5528    // 9.8킬로미터앞까지
#define IDM_0009900_AH_UPTO   5529    // 9.9킬로미터앞까지
#define IDM_0010000_AH_UPTO   5530    // 10킬로미터앞까지
#define IDM_0011000_AH_UPTO   5531    // 11킬로미터앞까지
#define IDM_0012000_AH_UPTO   5532    // 12킬로미터앞까지
#define IDM_0013000_AH_UPTO   5533    // 13킬로미터앞까지
#define IDM_0014000_AH_UPTO   5534    // 14킬로미터앞까지
#define IDM_0015000_AH_UPTO   5535    // 15킬로미터앞까지
#define IDM_0016000_AH_UPTO   5536    // 16킬로미터앞까지
#define IDM_0017000_AH_UPTO   5537    // 17킬로미터앞까지
#define IDM_0018000_AH_UPTO   5538    // 18킬로미터앞까지
#define IDM_0019000_AH_UPTO   5539    // 19킬로미터앞까지
#define IDM_0020000_AH_UPTO   5540    // 20킬로미터앞까지
#define IDM_0021000_AH_UPTO   5541    // 21킬로미터앞까지
#define IDM_0022000_AH_UPTO   5542    // 22킬로미터앞까지
#define IDM_0023000_AH_UPTO   5543    // 23킬로미터앞까지
#define IDM_0024000_AH_UPTO   5544    // 24킬로미터앞까지
#define IDM_0025000_AH_UPTO   5545    // 25킬로미터앞까지
#define IDM_0026000_AH_UPTO   5546    // 26킬로미터앞까지
#define IDM_0027000_AH_UPTO   5547    // 27킬로미터앞까지
#define IDM_0028000_AH_UPTO   5548    // 28킬로미터앞까지
#define IDM_0029000_AH_UPTO   5549    // 29킬로미터앞까지
#define IDM_0030000_AH_UPTO   5550    // 30킬로미터앞까지
#define IDM_0031000_AH_UPTO   5551    // 31킬로미터앞까지
#define IDM_0032000_AH_UPTO   5552    // 32킬로미터앞까지
#define IDM_0033000_AH_UPTO   5553    // 33킬로미터앞까지
#define IDM_0034000_AH_UPTO   5554    // 34킬로미터앞까지
#define IDM_0035000_AH_UPTO   5555    // 35킬로미터앞까지
#define IDM_0036000_AH_UPTO   5556    // 36킬로미터앞까지
#define IDM_0037000_AH_UPTO   5557    // 37킬로미터앞까지
#define IDM_0038000_AH_UPTO   5558    // 38킬로미터앞까지
#define IDM_0039000_AH_UPTO   5559    // 39킬로미터앞까지
#define IDM_0040000_AH_UPTO   5560    // 40킬로미터앞까지
#define IDM_0041000_AH_UPTO   5561    // 41킬로미터앞까지
#define IDM_0042000_AH_UPTO   5562    // 42킬로미터앞까지
#define IDM_0043000_AH_UPTO   5563    // 43킬로미터앞까지
#define IDM_0044000_AH_UPTO   5564    // 44킬로미터앞까지
#define IDM_0045000_AH_UPTO   5565    // 45킬로미터앞까지
#define IDM_0046000_AH_UPTO   5566    // 46킬로미터앞까지
#define IDM_0047000_AH_UPTO   5567    // 47킬로미터앞까지
#define IDM_0048000_AH_UPTO   5568    // 48킬로미터앞까지
#define IDM_0049000_AH_UPTO   5569    // 49킬로미터앞까지
#define IDM_0050000_AH_UPTO   5570    // 50킬로미터앞까지
#define IDM_0051000_AH_UPTO   5571    // 51킬로미터앞까지
#define IDM_0052000_AH_UPTO   5572    // 52킬로미터앞까지
#define IDM_0053000_AH_UPTO   5573    // 53킬로미터앞까지
#define IDM_0054000_AH_UPTO   5574    // 54킬로미터앞까지
#define IDM_0055000_AH_UPTO   5575    // 55킬로미터앞까지
#define IDM_0056000_AH_UPTO   5576    // 56킬로미터앞까지
#define IDM_0057000_AH_UPTO   5577    // 57킬로미터앞까지
#define IDM_0058000_AH_UPTO   5578    // 58킬로미터앞까지
#define IDM_0059000_AH_UPTO   5579    // 59킬로미터앞까지
#define IDM_0060000_AH_UPTO   5580    // 60킬로미터앞까지
#define IDM_0061000_AH_UPTO   5581    // 61킬로미터앞까지
#define IDM_0062000_AH_UPTO   5582    // 62킬로미터앞까지
#define IDM_0063000_AH_UPTO   5583    // 63킬로미터앞까지
#define IDM_0064000_AH_UPTO   5584    // 64킬로미터앞까지
#define IDM_0065000_AH_UPTO   5585    // 65킬로미터앞까지
#define IDM_0066000_AH_UPTO   5586    // 66킬로미터앞까지
#define IDM_0067000_AH_UPTO   5587    // 67킬로미터앞까지
#define IDM_0068000_AH_UPTO   5588    // 68킬로미터앞까지
#define IDM_0069000_AH_UPTO   5589    // 69킬로미터앞까지
#define IDM_0070000_AH_UPTO   5590    // 70킬로미터앞까지
#define IDM_0071000_AH_UPTO   5591    // 71킬로미터앞까지
#define IDM_0072000_AH_UPTO   5592    // 72킬로미터앞까지
#define IDM_0073000_AH_UPTO   5593    // 73킬로미터앞까지
#define IDM_0074000_AH_UPTO   5594    // 74킬로미터앞까지
#define IDM_0075000_AH_UPTO   5595    // 75킬로미터앞까지
#define IDM_0076000_AH_UPTO   5596    // 76킬로미터앞까지
#define IDM_0077000_AH_UPTO   5597    // 77킬로미터앞까지
#define IDM_0078000_AH_UPTO   5598    // 78킬로미터앞까지
#define IDM_0079000_AH_UPTO   5599    // 79킬로미터앞까지
#define IDM_0080000_AH_UPTO   5600    // 80킬로미터앞까지
#define IDM_0081000_AH_UPTO   5601    // 81킬로미터앞까지
#define IDM_0082000_AH_UPTO   5602    // 82킬로미터앞까지
#define IDM_0083000_AH_UPTO   5603    // 83킬로미터앞까지
#define IDM_0084000_AH_UPTO   5604    // 84킬로미터앞까지
#define IDM_0085000_AH_UPTO   5605    // 85킬로미터앞까지
#define IDM_0086000_AH_UPTO   5606    // 86킬로미터앞까지
#define IDM_0087000_AH_UPTO   5607    // 87킬로미터앞까지
#define IDM_0088000_AH_UPTO   5608    // 88킬로미터앞까지
#define IDM_0089000_AH_UPTO   5609    // 89킬로미터앞까지
#define IDM_0090000_AH_UPTO   5610    // 90킬로미터앞까지
#define IDM_0091000_AH_UPTO   5611    // 91킬로미터앞까지
#define IDM_0092000_AH_UPTO   5612    // 92킬로미터앞까지
#define IDM_0093000_AH_UPTO   5613    // 93킬로미터앞까지
#define IDM_0094000_AH_UPTO   5614    // 94킬로미터앞까지
#define IDM_0095000_AH_UPTO   5615    // 95킬로미터앞까지
#define IDM_0096000_AH_UPTO   5616    // 96킬로미터앞까지
#define IDM_0097000_AH_UPTO   5617    // 97킬로미터앞까지
#define IDM_0098000_AH_UPTO   5618    // 98킬로미터앞까지
#define IDM_0099000_AH_UPTO   5619    // 99킬로미터앞까지
#define IDM_0100000_AH_UPTO   5620    // 100킬로미터앞까지
#define IDG_NEXT_RG_GO   5621    // 다음 안내시까지 직진입니다
#define IDG_ENTER_ENTRANCE   5622    // 입구로 진입하세요
#define IDG_RG_TRAFFIC_OTHER_ROUTE   5623    // 교통정보를 반영하여 다른 경로로 안내합니다
#define IDG_RG_TRAFFIC_NEW_ROUTE   5624    // 교통정보를 반영하여 새로운 경로로 안내합니다
#define IDG_RG_GUIDE   5625    // 로 안내합니다
#define IDS_SDI_CHAGNE_ROAD_IN_TUNNEL   5626    // 터널 내 차로 변경 단속 구간입니다
#define IDS_SDI_ASSIGN_ROAD   5627    // 지정차로 단속 구간입니다
#define IDG_T_MEMBERSHIP_DISCOUNT   5628    // T맴버십으로 할인 받으실 수 있습니다
#define IDG_T_MEMBERSHIP_DISCOUNT_REST_PLACE   5629    // 이 휴게소는 T맴버십 할인 휴게소입니다
#define IDG_IC   5630    // IC
#define IDG_JC   5631    // JC
#define IDG_RG_ONLY_CHARGING   5632    // 유료도로가 포함된 경로만 존재합니다
#define IDG_RG_LOWEST_CHARGING   5633    // 최소비용 경로로 안내합니다
#define IDG_RG_CAR_ONLY_ROARD   5634    // 자동차 전용도로가 포함된 경로만 존재합니다
#define IDG_RG_GUIDE_ROUTE   5635    // 경로로 안내합니다
#define IDG_TIME_H2_01_UP   5636    // 1시간
#define IDG_TIME_H2_02_UP   5637    // 2시간
#define IDG_TIME_H2_03_UP   5638    // 3시간
#define IDG_TIME_H2_04_UP   5639    // 4시간
#define IDG_TIME_H2_05_UP   5640    // 5시간
#define IDG_TIME_H2_06_UP   5641    // 6시간
#define IDG_TIME_H2_07_UP   5642    // 7시간
#define IDG_TIME_H2_08_UP   5643    // 8시간
#define IDG_TIME_H2_09_UP   5644    // 9시간
#define IDG_TIME_H2_10_UP   5645    // 10시간
#define IDG_TIME_H2_11_UP   5646    // 11시간
#define IDG_TIME_H2_12_UP   5647    // 12시간
#define IDG_SDI_ROTATING_CAR   5648    // 회전 중인 차량에 주의하세요
#define IDG_SDI_REVERSE_DRIVING   5649    // 역주행 사고 다발 구간입니다.
#define IDG_2ND_CROSSLOAD   5650// 두번째 교차로입니다.
#define IDG_AHEAD_LEFT    5651  // 전방 좌회전입니다.
#define IDG_START    5652  // 안내를 시작합니다.
#define IDG_END      5653  // 안내를 종료합니다.

#define IDG_PEDESTRIAN_ACCIDENT				 5654   //보행자 사고다발 구간입니다.
#define IDG_RG_REALTIME_TRAFFIC              5655   //실시간 교통정보를 반영하여 안내합니다.
#define IDG_REALTIME_TRAFFIC                 5656   //실시간 교통정보를 반영하여
#define IDG_EXISTING_ROUTE                   5657   //기존 경로보다
#define IDG_OTHER_ROUTE                      5658   //다른 경로보다
#define IDG_FAST                             5659   //빠릅니다.
#define IDG_RG_FAST                          5660   //빠르게 안내합니다.
#define IDG_FROM_ROUNDABOUT                  5661   //회전 교차로에서
#define IDG_RG_ICY_ROAD_SIGNS                5662   //결빙 위험 구간입니다.
#define IDG_RG_TMAP_RECOMMAND_ROUTE_S        5663   //티맵추천 경로로 안내를 시작합니다.
#define IDG_RG_TIMEMIN_ROUTE_S               5664   //최소시간 경로로 안내를 시작합니다.
#define IDG_RG_LENGTHMIN_ROUTE_S             5665   //최단거리 경로로 안내를 시작합니다.
#define IDG_RG_FREEROAD_ROUTE_S              5666   //무료도로 우선 경로로 안내를 시작합니다.
#define IDG_RG_HIGHWAY_ROUTE_S               5667   //고속도로 우선 경로로 안내를 시작합니다.
#define IDG_RG_EASYROAD_ROUTE_S              5668   //편한길 우선 경로로 안내를 시작합니다.
#define IDG_RG_BIKE_ROUTE_S                  5669   //이륜차 통행 경로로 안내를 시작합니다.
#define IDG_RG_TMAP_RECOMMAND_ROUTE          5670   //티맵추천 경로로 안내합니다.
#define IDG_RG_TIMEMIN_ROUTE                 5671   //최소시간 경로로 안내합니다.
#define IDG_RG_LENGTHMIN_ROUTE               5672   //최단거리 경로로 안내합니다.
#define IDG_RG_FREEROAD_ROUTE                5673   //무료도로 우선 경로로 안내합니다.
#define IDG_RG_HIGHWAY_ROUTE                 5674   //고속도로 우선 경로로 안내합니다.
#define IDG_RG_EASYROAD_ROUTE                5675   //편한길 우선 경로로 안내합니다.
#define IDG_RG_BIKE_ROUTE                    5676   //이륜차 통행 경로로 안내합니다.
#define IDG_TO_DESTINATION                   5677   //목적지까지
#define IDG_KEEP_ROUTE                       5678   //현재 경로를 유지합니다.
#define IDG_NO_BIKE_KEEP_ROUTE               5679   //이륜차 통행 경로가 없어, 현재 경로를 유지합니다.
#define IDG_NO_FREEROAD_FEEMIN_ROUTE         5680   //무료 도로가 없어, 최소비용 경로로 안내합니다.
#define IDG_RE_ROUTE                         5681   //경로를 다시 탐색합니다.
#define IDG_LEAVE_RG_FREQUENT_ROUTE          5682   //경로를 벗어났습니다. 자주 가는 길로 돌아가도록 안내합니다.
#define IDG_LEAVE_NO_REQUENT_RECOMMAND_ROUTE 5683   //경로를 벗어났습니다. 자주 가는 길로 돌아갈 수 없어, 티맵추천 경로로 안내합니다.
#define IDG_LEFT_DESTINATION_RG_CONTINUE     5684   //왼쪽에 목적지가 있습니다. 안내를 계속합니다.
#define IDG_ONLY_HIPASS_TOLLGATE             5685   //하이패스 전용 톨게이트입니다.
#define IDG_RG_NO_FREEROAD_FEEMIN_ROUTE      5686   //무료 도로가 없어, 비용이 가장 적은 경로로 안내합니다.
#define IDG_RG_OLD_EXHAUST_GAS_GRADE         5687   //녹색 교통지역 단속구간입니다.
#define IDS_VIOLATION_SIGNAL                 5688   //신호위반 단속구간입니다.
#define IDG_RIGHT_EXIT						 5689   // 오른쪽 출구입니다.
#define IDG_LEFT_EXIT						 5690   // 왼쪽 출구입니다.
#define IDG_RIGHT_WAY						 5691   // 오른쪽 길입니다
#define IDG_LEFT_WAY						 5692   // 왼쪽 길입니다.
#define IDG_RIGHT_LANE_1					 5693   // 오른쪽 1개 차선으로 주행하세요.
#define IDG_RIGHT_LANE_2					 5694   // 오른쪽 2개 차선으로 주행하세요.
#define IDG_RIGHT_LANE_3					 5695   // 오른쪽 3개 차선으로 주행하세요.
#define IDG_RIGHT_LANE_4					 5696   // 오른쪽 4개 차선으로 주행하세요.
#define IDG_RIGHT_LANE_5					 5697   // 오른쪽 5개 차선으로 주행하세요.
#define IDG_LEFT_LANE_1						 5698   // 왼쪽 1개 차선으로 주행하세요.
#define IDG_LEFT_LANE_2						 5699   // 왼쪽 2개 차선으로 주행하세요.
#define IDG_LEFT_LANE_3						 5700   // 왼쪽 3개 차선으로 주행하세요.
#define IDG_LEFT_LANE_4						 5701   // 왼쪽 4개 차선으로 주행하세요.
#define IDG_LEFT_LANE_5						 5702   // 왼쪽 5개 차선으로 주행하세요.
#define IDG_RIGHT_LANE_1TH					 5703   // 오른쪽 1번째 차선으로 주행하세요.
#define IDG_RIGHT_LANE_2TH					 5704   // 오른쪽 2번째 차선으로 주행하세요.
#define IDG_RIGHT_LANE_3TH					 5705   // 오른쪽 3번째 차선으로 주행하세요.
#define IDG_RIGHT_LANE_4TH					 5706   // 오른쪽 4번째 차선으로 주행하세요.
#define IDG_RIGHT_LANE_5TH					 5707   // 오른쪽 5번째 차선으로 주행하세요.
#define IDG_LEFT_LANE_1TH					 5708   // 왼쪽 1번째 차선으로 주행하세요.
#define IDG_LEFT_LANE_2TH					 5709   // 왼쪽 2번째 차선으로 주행하세요.
#define IDG_LEFT_LANE_3TH					 5710   // 왼쪽 3번째 차선으로 주행하세요.
#define IDG_LEFT_LANE_4TH					 5711   // 왼쪽 4번째 차선으로 주행하세요.
#define IDG_LEFT_LANE_5TH					 5712   // 왼쪽 5번째 차선으로 주행하세요.
#define IDG_FOLLOW_PINK_LEAD_LINE			 5713   // 분홍색 주행유도선을 따라가세요.
#define IDG_FOLLOW_GREEN_LEAD_LINE			 5714   // 초록색 주행유도선을 따라가세요.
#define IDG_FOLLOW_LEAD_LINE				 5715   // 주행유도선을 따라가세요.
#define IDG_BLUE_HIPASS_LINE				 5716   // 파란색 하이패스 차선을 따라가세요.
#define IDS_SDI_INTERVAL_CRACKDOWN			 5717   // 교통경찰의 단속이 수시로 이루어지는 구간입니다.
#define IDS_SDI_CHANGE_LANE_ZONE			 5718   // 차로 변경 단속구간입니다.
#define IDS_KEEP_LANE						 5719   // 현재 차로를 유지하세요.
#define IDS_PROTECT_PEDESTRIAN				 5720   // 교통약자 보호구역입니다.
#define IDS_REST_DROWSE						 5721   // 졸음이 오면 쉬어가세요.
#define IDG_IN_ROUNDABOUT					 5722   // 회전교차로 진입입니다.
#define IDG_CONCESSION_DRIVING				 5723   // 주행하고 있는 차량에 양보 운전 하세요.
#define IDG_AHEAD_ACCIDENT					 5724   // 전방에 교통사고가 발생했습니다.
#define IDG_AHEAD_CONGEST_NEW_ROUTE			 5725   // 전방에 정체가 있어, 새로운 길로 안내합니다.
#define IDG_AHEAD_ACCIDENT_NEW_ROUTE		 5726   // 전방에 사고가 있어, 새로운 길로 안내합니다.
#define IDG_AHEAD_CONSTRUCT_NEW_ROUTE		 5727   // 전방에 공사가 있어, 새로운 길로 안내합니다.
#define IDG_AHEAD_EVENT_NEW_ROUTE			 5728   // 전방에 행사가 있어, 새로운 길로 안내합니다.
#define IDG_AHEAD_DISASTER_NEW_ROUTE		 5729   // 전방에 재해가 있어, 새로운 길로 안내합니다.
#define IDG_ACCIDENT_NEW_ROUTE				 5730   // 전방에 사고가 발생하여 새로운 길로 안내합니다.
#define IDG_DISASTER_NEW_ROUTE				 5731   // 전방에 재해가 발생하여 새로운 길로 안내합니다.
#define IDG_RAILROAD						 5732   // 철도 건널목이 있습니다.
#define IDG_CAUTION_FIVE_GRADE				 5733   // 5등급 차량은 주의하세요.
#define IDG_CRACKDOWN_ZONE					 5734   // 단속 지점입니다.
#define IDG_IS_POINT						     5735   // 지점입니다.
#define IDG_CAUTION_FIXED_CONTROL			 5736   // 고정식 단속을 주의하세요.
#define IDG_CAUTION_FIXED_CONTROL1			 5737   // 고정식 단속에 주의하세요.
#define IDG_CAUTION_CRACKDOWN				 5738   // 단속을 주의하세요.
#define IDG_CAUTION_CRACKDOWN1				 5739   // 단속에 주의하세요.
#define IDG_FOLLOW_BLUE_LEAD_LINE			 5740   // 파란색 주행유도선을 따라가세요.


#define IDG_RG_EXHAUST_GAS_GRADE            	5741	// 녹색교통지역 단속지점입니다.
#define IDG_RG_AHEAD_LOOK                   	5742	// 전방을 주시하세요.
#define IDG_RG_CAMPING_SAFE_ACCIDENTS       	5743	// 캠핑장 안전 사고에 유의하세요.
#define IDG_MULTIPLE                        	5744	// 연달아
#define IDG_MULTI                           	5745	// 연속으로
#define IDG_AFTER_ANOTHER                   	5746	// 연이어
#define IDG_HAS                             	5747	// 있습니다.
#define IDG_RG_FAVORITE_ROUTE_START         	5748	// 즐겨찾는 경로로 안내를 시작합니다.
#define IDG_FAVORITE_ROUTE_START            	5749	// 즐겨찾는 경로로 안내합니다.
#define IDG_RG_START_CANNOT_FAVORITE_REJOIN 	5750	// 경로로 안내합니다. 즐겨찾는 경로로 재합류할 수 없습니다.
#define IDG_RG_START_CANNOT_FAVORITE_REJOIN2	5751	// 경로로 안내합니다. 즐겨찾는 경로로 재합류할 수 없어요.
#define IDG_FAVORITE_REJOIN_NAVIGATE        	5752	// 즐겨찾는 경로로 재합류하는 경로를 탐색합니다.
#define IDG_FAVORITE_REJOIN_RE_NAVIGATE     	5753	// 즐겨찾는 경로로 재합류하는 경로를 다시 탐색합니다.
#define IDG_RG_FAVORITE_REJOIN_RE_NAVIGATE  	5754	// 경로를 다시 탐색해 즐겨찾는 경로로 재합류하는 경로를 안내합니다.
#define IDG_RG_FAVORITE_REJOIN_NAVIGATE     	5755	// 경로를 탐색해 즐겨찾는 경로로 재합류하는 경로를 안내합니다.
#define IDG_FAVORITE_REJOIN                 	5756	// 즐겨찾는 경로로 재합류합니다.
#define IDG_FAVORITE_ROUTE                  	5757	// 즐겨찾는 경로인
#define IDG_RG_ROUTE_START                  	5758	// 경로로 안내합니다.
#define IDG_X_OIL                           	5759	// 엑스오일
#define IDG_EX_OIL                          	5760	// 이엑스오일
#define IDG_E1                              	5761	// 이원
#define IDG_BLACKICE_DANGER_AREA            	5762	// 블랙아이스 위험 구간입니다.
#define IDG_BLACKICE_CAUTION_AREA           	5763	// 블랙아이스 주의 구간입니다.
#define IDG_BLACKICE_ACCIDENT               	5764	// 블랙아이스 사고다발 구간입니다.
#define IDG_FIXEDSPEED                      	5765	// 과속 단속
#define IDG_SPEEDSIGNAL                     	5766	// 신호과속 단속
#define IDG_SPEED_MOVING                    	5767	// 이동식 단속
#define IDG_BOX_FIXEDSPEED                  	5768	// 박스형 과속단속
#define IDG_SECTIONSPEED                    	5769	// 구간 단속
#define IDG_SECTIONSPEED_START              	5770	// 구간 단속 시작
#define IDG_SECTIONSPEED_END                	5771	// 구간 단속 종료
#define IDG_CHANGEABLE_SECTIONSPEED         	5772	// 가변 구간 단속
#define IDG_CHANGEABLE_SECTIONSPEED_TIME    	5773	// 가변 구간 단속 시작
#define IDG_CHANGEABLE_SECTIONSPEED_END     	5774	// 가변 구간 단속 종료
#define IDG_POINT                           	5775	// 지점
#define IDG_SECTION                         	5776	// 구간
#define IDG_IS_SECTION                      	5777	// 구간입니다.
#define IDG_IS_SCHOOLZONE                   	5778	// 스쿨존입니다.
#define IDG_CHILD_PROTECTZONE_START         	5779	// 어린이보호구역 시작 지점입니다.
#define IDG_CHILD_PROTECTZONE_START_POINT   	5780	// 어린이보호구역 시점입니다.
#define IDG_CHILD_PROTECTZONE_END           	5781	// 어린이보호구역 종료 지점입니다.
#define IDG_CHILD_PROTECTZONE_END_POINT     	5782	// 어린이보호구역 종점입니다.
#define IDG_SCHOOLZONE_START                	5783	// 스쿨존 시작 지점입니다.
#define IDG_SCHOOLZONE_START_POINT          	5784	// 스쿨존 시점입니다.
#define IDG_SCHOOLZONE_END                  	5785	// 스쿨존 종료 지점입니다.
#define IDG_SCHOOLZONE_END_POINT            	5786	// 스쿨존 종점입니다.
#define IDG_AHEAD_WATCH                     	5787	// 전방을 주시하세요.
#define IDG_ACCIDENT_SAFE                   	5788	// 안전 사고에 유의하세요.
#define IDG_KEEP_LIMIT_SPEED                	5789	// 제한속도를 준수하세요.
#define IDS_VIOLATIONSIGNAL                 	5790	// 신호위반 단속

#define CHILD_FIXEDSPEED                    	5791	// 과속 단속
#define CHILD_SPEEDSIGNAL                   	5792	// 신호과속 단속
#define CHILD_SPEED_MOVING                  	5793	// 이동식 단속
#define CHILD_BOX_FIXEDSPEED                	5794	// 박스형 과속 단속
#define CHILD_SECTIONSPEED                  	5795	// 구간 단속
#define CHILD_SECTIONSPEED_START            	5796	// 구간 단속 시작
#define CHILD_SECTIONSPEED_END              	5797	// 구간 단속 종료
#define CHILD_CHANGEABLE_SECTIONSPEED       	5798	// 가변 구간 단속
#define CHILD_CHANGEABLE_SECTIONSPEED_START  	5799	// 가변 구간 단속 시작
#define CHILD_CHANGEABLE_SECTIONSPEED_END   	5800	// 가변 구간 단속 종료
#define CHILD_POINT                         	5801	// 지점
#define CHILD_IS_POINT                      	5802	// 지점입니다.
#define CHILD_SECTION                       	5803	// 구간
#define CHILD_IS_SECTION                    	5804	// 구간입니다.
#define CHILD_AHEAD                         	5805	// 전방에
#define CHILD_IS_CHILD_PROTECTZONE          	5806	// 어린이보호구역입니다.
#define CHILD_IS_SCHOOLZONE                 	5807	// 스쿨존입니다.
#define CHILD_CHILD_PROTECTZONE_START       	5808	// 어린이보호구역 시작 지점입니다.
#define CHILD_CHILD_PROTECTZONE_START_POINT 	5809	// 어린이보호구역 시점입니다.
#define CHILD_CHILD_PROTECTZONE_END         	5810	// 어린이보호구역 종료 지점입니다.
#define CHILD_CHILD_PROTECTZONE_END_POINT   	5811	// 어린이보호구역 종점입니다.
#define CHILD_SCHOOLZONE_START              	5812	// 스쿨존 시작 지점입니다.
#define CHILD_SCHOOLZONE_START_POINT        	5813	// 스쿨존 시점입니다.
#define CHILD_SCHOOLZONE_END                	5814	// 스쿨존 종료 지점입니다.
#define CHILD_SCHOOLZONE_END_POINT          	5815	// 스쿨존 종점입니다.
#define CHILD_AHEAD_WATCH                   	5816	// 전방을 주시하세요.
#define CHILD_ACCIDENT_SAFE                 	5817	// 안전 사고에 유의하세요.
#define CHILD_KEEP_LIMIT_SPEED              	5818	// 제한속도를 준수하세요.
#define CHILD_AFTER_A_WHILE                 	5819	// 잠시후
#define CHILD_100M_AHEAD                    	5820	// 100 미터 앞에
#define CHILD_200M_AHEAD                    	5821	// 200 미터 앞에
#define CHILD_300M_AHEAD                    	5822	// 300 미터 앞에
#define CHILD_400M_AHEAD                    	5823	// 400 미터 앞에
#define CHILD_500M_AHEAD                    	5824	// 500 미터 앞에
#define CHILD_600M_AHEAD                    	5825	// 600 미터 앞에
#define CHILD_1KM_AHEAD                     	5826	// 1km 앞에
#define CHILD_SPEED10_ONLY                  	5827	// 시속 10 키로미터
#define CHILD_SPEED20_ONLY                  	5828	// 시속 20 키로미터
#define CHILD_SPEED30_ONLY                  	5829	// 시속 30 키로미터
#define CHILD_SPEED40_ONLY                  	5830	// 시속 40 키로미터
#define CHILD_SPEED50_ONLY                  	5831	// 시속 50 키로미터
#define CHILD_SPEED60_ONLY                  	5832	// 시속 60 키로미터
#define CHILD_SPEED70_ONLY                  	5833	// 시속 70 키로미터
#define CHILD_SPEED80_ONLY                  	5834	// 시속 80 키로미터
#define CHILD_SPEED90_ONLY                  	5835	// 시속 90 키로미터
#define CHILD_SPEED100_ONLY                 	5836	// 시속 100 키로미터
#define CHILD_FIXED_SPEED                   	5837	// 과속 단속 지점
#define CHILD_SPEED_SIGNAL                  	5838	// 신호과속 단속 지점
#define CHILD_VIOLATIONSIGNAL               	5839	// 신호 위반 단속
#define CHILD_VIOLATION_SIGNAL              	5840	// 신호 위반 단속 지점
#define CHILD_IS                            	5841	// 입니다.

// 8.1추가.
#define IDG_CONTINUES_START                     5842    // 경로로 안내합니다.
#define IDG_CANNOT_REJOIN_FAVORITE_ROUTE        5843    // 즐겨찾는 경로로 재합류할 수 없습니다.
#define IDG_SCHOOLZONE_RG_START                 5844    // 어린이 보호 경로로 안내를 시작합니다.
#define IDG_SCHOOLZONE_RG_START1                5845    // 어린이 보호 경로로 안내합니다.
#define IDG_NO_SCHOOLZONE_ROUTE_SHORT_START     5846    // 어린이 보호 경로가 없어 최소포함 경로로 안내합니다.

#define RG_DATA_TEXT_LIGHT_GREEN_LANE           5847    // 연두색 차선으로 주행하세요
#define RG_DATA_TEXT_GREEN_LANE                 5848    // 초록색 차선으로 주행하세요
#define RG_DATA_TEXT_PINK_LANE                  5849    // 분홍색 차선으로 주행하세요
#define RG_DATA_TEXT_BLUE_LANE                  5850    // 파란색 차선으로 주행하세요
#define RG_DATA_TEXT_YELLOW_LANE                5851    // 노란색 차선으로 주행하세요
#define RG_DATA_TEXT_LEFT_WAY                   5852    // 왼쪽 길로 주행하세요
#define RG_DATA_TEXT_RIGHT_WAY                  5853    // 오른쪽 길로 주행하세요
#define RG_DATA_TEXT_LEFT_EXIT                  5854    // 왼쪽 출구로 주행하세요
#define RG_DATA_TEXT_RIGHT_EXIT                 5855    // 오른쪽 출구로 주행하세요
#define RG_DATA_TEXT_LEFT_LANE1                 5856    // 왼쪽 첫번째 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_LANE2                 5857    // 왼쪽 두번째 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_LANE3                 5858    // 왼쪽 세번째 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_LANE4                 5859    // 왼쪽 네번째 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_LANE1                5860    // 오른쪽 첫번째 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_LANE2                5861    // 오른쪽 두번째 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_LANE3                5862    // 오른쪽 세번째 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_LANE4                5863    // 오른쪽 네번째 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_1_LANE                5864    // 왼쪽 1개 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_2_LANE                5865    // 왼쪽 2개 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_3_LANE                5866    // 왼쪽 3개 차로로 주행하세요
#define RG_DATA_TEXT_LEFT_4_LANE                5867    // 왼쪽 4개 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_1_LANE               5868    // 오른쪽 1개 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_2_LANE               5869    // 오른쪽 2개 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_3_LANE               5870    // 오른쪽 3개 차로로 주행하세요
#define RG_DATA_TEXT_RIGHT_4_LANE               5871    // 오른쪽 4개 차로로 주행하세요

#define IDG_RG_TRUCK_ROUTE_S                    5872    // 화물차 통행가능 경로로 안내를 시작합니다.
#define IDG_RAILROAD_PAUSE                      5873    // 일시정지하세요.

// TMAP AUTO 추가
#define IDG_EV_CHARGING_STATION_ROUTE_START     5874    // 경로에 최적화된 전기차 충전소가 포함되어 있습니다.
#define IDG_EV_FAST_CHARGING_STATION            5875    // 급속 전기차 충전소가 있습니다.
#define IDG_EV_SLOW_CHARGING_STATION            5876    // 완속 전기차 충전소가 있습니다.
#define IDG_EV_FAST_SLOW_CHARGING_STATION       5877    // 급속과 완속 전기차 충전소가 있습니다.

#define IDG_EV_SUPER_CHARGING_STATION            5878    // 초급속 전기차충전소가 있습니다.
#define IDG_EV_SUPER_FAST_CHARGING_STATION       5879    // 초급속과 급속 전기차 충전소가 있습니다.
#define IDG_EV_SUPER_FAST_SLOW_CHARGING_STATION  5880    // 초급속과 급속, 완속 전기차 충전소가 있습니다.
#define IDG_EV_SUPER_SLOW_CHARGING_STATION      5881    // 초급속과 완속 전기차 충전소가 있습니다.

#define	IDG_IN_UNDER_PATH_2	                	5882	//	지하도로 진입입니다.
#define IDG_THEMEROAD                           5883    // 아름다운길
#define IDG_ECHO_RECOMMAND_ROUTE_S              5884    // 배터리 효율 경로로 안내를 시작합니다.
#define IDG_ECHO_RECOMMAND_ROUTE                5885    // 배터리 효율 경로로 안내합니다.
#define IDG_FLOOD_CAUTION                       5886   //홍수 주의 구간입니다.
#define IDG_DAM_CONTROLLED_RELEASE              5887   //침수 위험 구간입니다.
#define IDG_SMART_TALLING_EXPERIMENT            5888   //영상방식 스마트톨링 시범운영 중입니다.
#define IDG_PEDESTRIAN_PRIORITY_ROAD            5889   //전방에 보행자 우선도로입니다. 서행하세요
#define IDG_MAX                                 5890
#endif
