#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define AI 17
#define SPADE "♠"
#define CLUB "♣"
#define DIA "◆"
#define HEART "♥"

void have_stock();
void exit(int status);
void cursor2();
void starting();
void game_rule();
void game_start();
void tool();
void rock();
void sisors();
void paper();
void render();

//퀴즈
struct Question{
	char* Question; //문제
	char* Case[2];	//객관식 답 번호
	int Answer;		//정답
	BOOL Already;	//이미 출제된 문제 방지
};

struct Stock0 {
	int price;	// 원가격
	int wid;	// 폭
	int rise;	// 상승률
	int fall;	// 하락률
};

enum shape { spade, club, dia, heart };
enum num { ace = 1, jack = 11, queen = 12, king = 13 };

// 카드
struct Card {
	int number;	//숫자
	char shape;	//모양
};

// 모든 카드
struct Card card_all[52];
int next;

// 선수
struct Player {
	int cash;
	int score;
	struct Card card_player[21];
};

struct Player player[3];

static int wallet = 1000000;		//통장

// 카드 섞는 함수
void shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int index = rand() % 52;
		struct Card temp = card_all[index];
		card_all[index] = card_all[i];
		card_all[i] = temp;
	}
}

// 카드 채우는 함수
void filldeck()
{
	int i = 0;
	// 4개의 모양과 13개의 숫자를 짝지어서 카드 만듦
	for (int j = 0; j < 4; j++)
	{
		for (int k = 1; k < 14; k++)
		{
			card_all[i].number = k;
			card_all[i].shape = j;
			i++;
		}
	}
}

// 섞은 후 앞에서 부터 한장 나눠주는 함수
struct Card deal(int next)
{
	return card_all[next];
}

// 사용자가 뽑은 카드를 문자열이 아닌 카드 모양으로 출력, 점수 계산
void printcard(int p, int turns)
{
	int ace_score = 0;

	printf("-------\n");

	switch (player[p].card_player[turns].shape)
	{
	case spade:
		printf("|%s    |\n", SPADE);
		break;
	case club:
		printf("|%s    |\n", CLUB);
		break;
	case dia:
		printf("|%s    |\n", DIA);
		break;
	case heart:
		printf("|%s    |\n", HEART);
		break;
	}

	switch (player[p].card_player[turns].number)
	{
	case ace:
		printf("|  A  |\n");
		ace_score = -1;
		break;
	case jack:
		printf("|  J  |\n");
		player[p].score += 10;
		break;
	case queen:
		printf("|  Q  |\n");
		player[p].score += 10;
		break;
	case king:
		printf("|  K  |\n");
		player[p].score += 10;
		break;
	default:
		printf("| %2d  |\n", player[p].card_player[turns].number);
		player[p].score += player[p].card_player[turns].number;
		break;
	}

	switch (player[p].card_player[turns].shape)
	{
	case spade:
		printf("|    %s|\n", SPADE);
		break;
	case club:
		printf("|    %s|\n", CLUB);
		break;
	case dia:
		printf("|    %s|\n", DIA);
		break;
	case heart:
		printf("|    %s|\n", HEART);
		break;
	}

	printf("-------\n");

	// ace 계산 묻기
	if (ace_score == -1)
	{
		printf("ACE가 나왔네요, [1/11]점으로 계산합니다: ");
		scanf_s("%d", &ace_score);
		player[p].score += ace_score;
	}

	printf("score : %d\n", player[p].score);

	return;
}

// 배팅하는 함수
int betting(struct Player player)
{
	int won,bet=0;
	printf("돈을 걸기 전에, 환전을 시작합니다. 얼마를 환전 하실래요? ( 1cash == 100원) : ");
	scanf_s("%d", &won);

	if (won > wallet) {
		printf("환전이 안되잖아요! 다시");
		scanf_s("%d", &won);
	}

	player.cash += won / 100;

	printf("돈을 걸어봅시다! %d 중 얼마를 배팅하시겠습니까?", player.cash);
	scanf_s("%d", &bet);

	if (bet > player.cash)
	{
		printf("이런이런... 돈이 부족하군요. 조금만 아껴야겠어요. 다시 입력 : ");
		scanf_s("%d", &bet);
		return bet;
	}
	else return bet;
}

// 게임을 시작
void stayorhit(int p, int turns)
{
	char answer;

	printf("\n##########TURN : PLAYER%d님##########\n\n", p);
	while (player[p].score < 21)
	{
		printf("HIT을 원하시면 h를, STAY를 원하시면 s를 입력하세요[h/s]: ");
		scanf_s(" %c", &answer);

		if (answer == 'h' || answer == 'H')
		{
			turns++;
			player[p].card_player[turns] = deal(next++);
			printcard(p, turns);
		}
		else if (answer == 's' || answer == 'S')
		{
			break;
		}
		else
		{
			printf("HIT이면 h, STAY면 s라니까.. \n다시 ㄱ,");
		}
	}

	if (player[p].score > 21)
	{
		printf("21점을 넘었습니다. LOSS\n");
		player[p].score = 0;
	}
	else if (player[p].score == 21)
	{
		printf("21점입니다. WIN\n");
	}
}

// 딜러는 지능적으로 16까지만 안전하게 여기고 hit
void dealer(int turns)
{
	printf("\n##########DEALER's TURN##########\n\n");
	while (player[0].score < 21)
	{
		if (player[0].score < AI)
		{
			turns++;
			player[0].card_player[turns] = deal(next++);
			printcard(0, turns);
		}
		else
		{
			break;
		}
	}
	if (player[0].score > 21) player[0].score = 0;
}

// 게임 진행
void play()
{
	int turns = 0; int goon = 1; int push = 0; int push_flag = 0; int bet_total = 0;

	while (goon)
	{
		int winner, winnerscore = -1;
		int bet[3]; bet[0] = 10;
		push_flag = 0;

		if (push == 0) bet_total = 0;

		if (player[1].cash <= 0)
		{
			printf("!!! PLAYER1 파산하셨습니다.\n\n");
			player[1].cash += 100;
		}

		player[0].score = 0;
		player[1].score = 0;

		player[0].card_player[turns] = deal(next++);
		printcard(0, turns);

		printf("\n<<PLAYER1>>\n");
		printf("CASH (기본 제공) : %d\n", player[1].cash);
		player[1].card_player[turns] = deal(next++);
		printcard(1, turns);

		bet_total += bet[0];
		printf("\nPLAYER1님, ");
		bet[1] = betting(player[1]);
		bet_total += bet[1];

		stayorhit(1, turns);

		dealer(turns);

		printf("\n게임 결과>> DEALER: %d / PLAYER1: %d\n", player[0].score, player[1].score);

		// 동점 우승이 있으면, 다음 게임으로 배팅 금액을 몰빵
		for (int i = 0; i < 2; i++)
		{
			if (winnerscore < player[i].score)
			{
				winner = i;
				winnerscore = player[i].score;
			}
		}
		printf("prize: ");

		for (int i = 0; i < 3; i++)
		{
			if (winnerscore == player[i].score && winner != i)
			{
				if (push == 0) push = 1;
				push_flag = 1;
			}
		}

		push *= push_flag;

		if (push == 1)
		{
			player[1].cash -= bet[1];
			printf("0\n");
		}
		else if (winner == 0)
		{
			player[1].cash -= bet[1];
			push = 0;
			printf("%d\n", bet_total);
		}
		else if (winner == 1)
		{
			player[1].cash += bet_total;
			push = 0;
			printf("%d\n", bet_total);
		}
		printf("\n결과>> P1 CASH : %d \n", player[1].cash);

		wallet += player[1].cash*100;
		printf("환전 후 총 금액 : %d원\n" , wallet);

		char answer;
		printf("계속하시겠습니까? ");
		scanf_s(" %c", &answer);

		if (answer == 'y' || answer == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
	}

	printf("게임이 종료됩니다...");
}

void reset()
{
	player[0].score = 0; player[1].score = 0;
	player[1].cash = 100;

	filldeck(); shuffle(); next = 0;
}

// 블랙잭 시작
void blackjack()
{
	char choice = "";
	printf("게임 시작(Y or y) , 게임 종료(N or n) 중 하나를 입력하세요 : ");
	scanf_s("%c", &choice);
	fflush(stdin);
	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		printf("이상한 문자를 입력하셨습니다. 다시 입력해주세요! [y/n] ");
		scanf_s("%c", &choice);
	}

	if (choice == 'Y' || choice == 'y')
	{
		reset();
		play();
	}
	else if (choice == 'N' || choice == 'n')
	{
		printf("응 ㅋㅋ 게임종료\n");
	}
	return;
}
static struct Stock0 stock_heojung;
static struct Stock0 stock_jinseo;
static struct Stock0 stock_minwook;
static struct Stock0 stock_junsung;
static struct Stock0 stock_hyeonseo;
static struct Stock0 stock_ain;
static struct Stock0 stock_kangho;
static struct Stock0 stock_taehyun;
static struct Stock0 stock_chanjung;
static struct Stock0 stock_hakjin;
static struct Stock0 stock_yeojun;
static struct Stock0 stock_kimjun;
static struct Stock0 stock_yunseo;
static struct Stock0 stock_jungyoon;
static struct Stock0 stock_parkjun;
static struct Stock0 stock_jumi;
static struct Stock0 stock_kanghyeon;
static struct Stock0 stock_hyeonwoo;
static struct Stock0 stock_eunyung;

static int have;		//자산가치
static int heojung;
static int jinseo;
static int minwook;
static int junsung;
static int hyeonseo;
static int ain;
static int kangho;
static int taehyun;
static int chanjung;
static int hakjin;
static int yeojun;
static int kimjun;
static int yunseo;
static int jungyoon;
static int parkjun;
static int jumi;
static int kanghyeon;
static int hyeonwoo;
static int eunyung;

char a;

void setStock(struct Stock0* st, int Price, int Wid, int Rise, int Fall) {
	st->price = Price;
	st->wid = Wid;
	st->rise = Rise;
	st->fall = Fall;
}

//버퍼 비우는 함수
void ClearLineFromReadBuffer(void)
{
	while (getchar() != '\n');
}

//커서 이동 함수
void gotoxy(int x, int y) { 
	COORD Cur = { 0 };
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//커서 숨기는 함수
void CursorView() { 
	CONSOLE_CURSOR_INFO cursorInfo = { 0, 1};
	cursorInfo.dwSize = 1;		//커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE;		//커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//키 입력 함수
int Getkeydown(int vkey) { 
	if (GetAsyncKeyState(vkey) & 0x8000) {
		return true;
	}
	return false;
}

//첫 화면 커서 이동
void cursor1() {		

	int x = 85, y = 18;			// 프로그램실행했을때시작점의x,y 좌표

	do {
		gotoxy(x, y);
		printf("→"); 
		
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // ↓
			
			if (y >= 26) { y = 26; } // y의 최댓값
			else {
				y += 4; 
				system("cls");
				starting();
			}
		}

		else if (GetAsyncKeyState(VK_UP) & 0x8000) {		 // ↑
			
			if (y <= 18) { y = 18; }		// y의 최솟값
			else {
				y -= 4;
				system("cls");
				starting();
			}
		}
		Sleep(100);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {	//엔터 시
			if (y == 18) {		// 게임시작
				printf(" ");
				system("cls");
				break;
			}
			else if (y == 22) { //게임설명
				system("cls");
				game_rule();
				gotoxy(118, 28);
				printf("→");
				Sleep(300);
				while (1) {
					if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //엔터 입력 시 뒤로가기
						break;
					}		
				}
				Sleep(100);
				system("cls");
				starting();
			}
			else if (y == 26) {
				system("cls");
				exit(0);			// 게임종료
			}
		}
	} while (1);
}

//퀴즈 게임
void quiz() {
	srand(time(NULL));
	struct Question data[] = {
		{"우리 나라의 수도는?", "서울" , "평양" ,1,FALSE},
		{"정이가 요즘 즐겨하는 게임은?", "롤" , "메이플" ,2,FALSE},
		{"진서가 가장 좋아하는 사람은?", "태현" , "준성" ,1,FALSE},
		{"민욱이가 들어간 동아리는? ", "&persand" , "with강ㅋㅋ" ,1,FALSE},
		{"정이의 장래희망은 ?" ,"국회의원" , "인공지능전문가" ,2,FALSE},
		{"진서의 장래희망은 ? ", "장래식장조의금도둑엄준식" , "DataBase" ,1,FALSE},
		{"준성이의 여친은?",  "유상아" , "하츠네 미쿠" ,2,FALSE},
		{"진서가 자주하는 게임은?", "기적의검" , "메이플" ,1,FALSE},
		{"진서가 자주보는 애니는?", "이과가 사랑에 빠졌기에 증명해보았다 r=1-sinθ(하트)" , "러브라이브 니지가사키 학원 스쿨 아이돌 동호회 2기" ,2,FALSE},
		{"민욱이가 고른 애니 TOP픽은?", "귀엽지만 않은 시키모리 양" , "카구야님은 고백받고 싶어 3기" ,1,FALSE},
	};
	
	int rnd = rand() % 10 + 1;
	int cnt = 0,input;
	printf("┌───────────┐\n");
	printf("│ Quiz Game │\n");
	printf("└───────────┘\n");

	for (int i = 0; i < 10; i++) {
		printf("\n%d. %s\n", i+1,data[i].Question);
		printf("(1.%s , 2.%s)\n", data[i].Case[0], data[i].Case[1]);
		printf("1번과 2번 중 하나를 선택하세요 : ");
		scanf_s("%d", &input);
		if (input == 1 || input == 2) {
			if (input == data[i].Answer) cnt++;
		}
		else {
			i -= 1;
			printf("다시 입력하세요\n");
		}
	}
	wallet += 100000 * cnt * rnd;
	printf("\n퀴즈 %d개를 완료하셨습니다. %d원을 지급합니다.\n" ,cnt, 100000 * cnt * rnd);
	printf(">>엔터 키를 입력하시면 종료됩니다.");
	Sleep(200);
}

void handle_game() {
	srand(time(NULL));
	int my_num, bet;
	int cpu_num = rand() % 3 + 1;

	for (int i = 1; i < 2; i++) {
		printf("※베팅 금액을 설정하세요 (이기면 2배 , 비기면 1.5배, 지면 0.7배) : ");
		scanf_s("%d", &bet);
		if (wallet < bet) {
			i -= 1;
			printf("\n돈이 부족합니다..  다시 입력하세요.\n");
		}
	}
	wallet -= bet;
	for (int i = 1; i < 2; i++) {
		printf("무엇을 내시겠습니까? (1.가위 , 2.바위 , 3.보) : ");
		scanf_s("%d", &my_num);

		if(my_num>3 || my_num<1) {
			i -= 1;
			printf("\n다시 입력하세요.\n");
		}
	}
	
	if (cpu_num == 1) sisors();
	else if (cpu_num == 2) rock();
	else  if(cpu_num ==3) paper();

	if (cpu_num == 1) printf("당신의 선택은 \"가위\" 입니다.\n");
	else if (cpu_num == 2) printf("당신의 선택은 \"바위\" 입니다.\n");
	else  if (cpu_num == 3) printf("당신의 선택은 \"보\" 입니다.\n");

	if (my_num == cpu_num) {
		printf("아슬아슬하게 비겼습니다.. X1.5배!\n");
		wallet += bet * 1.5;
	}
	else if ((cpu_num == 1 && my_num == 2) || (cpu_num == 2 && my_num == 1) || (cpu_num == 3 && my_num == 1)) { //지는 경우
		printf("어머나 지셨네요 ㅋㅋ 베팅금액의 0.7배만 돌려드려용 ㅋㅋ\n");
		wallet += bet * 0.7;
	}
	else {
		printf("오.. 2배\n");
		wallet += bet * 2;
	}
	printf("현재 금액 : %d\n", wallet);
	printf("스페이스바 클릭 시 종료됩니다.");
	return;
}

void buy_sell() {
	int input1,input2,input3,price,have;
	printf("1.은영 코인 - %d\n", stock_eunyung.price);
	printf("2.허정 유통 - %d\n", stock_heojung.price);
	printf("3.진서 건설 - %d\n", stock_jinseo.price);
	printf("4.민욱 반도체 - %d\n", stock_minwook.price);
	printf("5.준성 게임즈 - %d\n", stock_junsung.price);
	printf("6.현서 조선 - %d\n", stock_hyeonseo.price);
	printf("7.아인 세큐리티 - %d\n", stock_ain.price);
	printf("8.강호 제과 - %d\n", stock_kangho.price);
	printf("9.태현 전자 - %d\n", stock_taehyun.price);
	printf("10.찬정 모터스 - %d\n", stock_chanjung.price);
	printf("11.학진 문학 - %d\n", stock_hakjin.price);
	printf("12.여준 리츠 - %d\n", stock_yeojun.price);
	printf("13.김준 철물 - %d\n", stock_kimjun.price);
	printf("14.윤서 화재 - %d \n", stock_yunseo.price);
	printf("15.정윤 은행 - %d\n", stock_jungyoon.price);
	printf("16.박준 스포츠 - %d\n", stock_parkjun.price);
	printf("17.주미 산업 - %d\n", stock_jumi.price);
	printf("18.강현 투자 - %d\n", stock_kanghyeon.price);
	printf("19.현우 전력 - %d\n\n", stock_hyeonwoo.price);
	for (int k = 1; k < 2; k++) {
		for (int j = 1; j < 2; j++) {		//종목
			printf("어떤 주식을 매수/매도 할까요? : ");
			scanf_s("%d", &input1);
			if (input1 < 1 || input1 > 19) {
				j -= 1;
				printf("입력하신 주식을 찾을 수 없습니다. 다시\n");
				continue;
			}
		}
		switch (input1) {
		case 1:price = stock_eunyung.price; have = eunyung; break;
		case 2: price = stock_heojung.price; have = heojung; break;
		case 3: price = stock_jinseo.price; have = jinseo; break;
		case 4: price = stock_minwook.price; have = minwook; break;
		case 5: price = stock_junsung.price; have = junsung; break;
		case 6: price = stock_hyeonseo.price; have = hyeonseo; break;
		case 7: price = stock_ain.price; have = ain; break;
		case 8: price = stock_kangho.price; have = kangho; break;
		case 9: price = stock_chanjung.price; have = chanjung; break;
		case 10: price = stock_taehyun.price; have = taehyun; break;
		case 11: price = stock_hakjin.price; have = hakjin; break;
		case 12: price = stock_yeojun.price; have = yeojun; break;
		case 13: price = stock_kimjun.price; have = kimjun; break;
		case 14: price = stock_yunseo.price; have = yunseo; break;
		case 15: price = stock_jungyoon.price; have = jungyoon; break;
		case 16: price = stock_parkjun.price; have = parkjun; break;
		case 17: price = stock_jumi.price; have = jumi; break;
		case 18: price = stock_kanghyeon.price; have = kanghyeon; break;
		case 19: price = stock_hyeonwoo.price; have = hyeonwoo; break;
		}
		for (int i = 1; i < 2; i++) {		//매수/매도
			printf("1. 매수 , 2. 매도");
			scanf_s("%d", &input2);
			if(input2 <1 || input2>2) {
				i -= 1;
				printf("다시 입력하세요\n");
			}
		}

		if (input2 == 1) {		//매수	
			for (int j = 1; j < 2; j++) {
				printf("얼만큼 사시겠습니까? : ");
				scanf_s("%d", &input3);
				if (price * input3>wallet) {
					printf("돈이 부족합니다. 처음부터 다시 실행됩니다.\n");
					break;
				}
				else {
					wallet -= price * input3;
					switch (input1) {
					case 1: eunyung+=input3; break;
					case 2: heojung+=input3; break;
					case 3: jinseo+=input3; break;
					case 4: minwook+=input3; break;
					case 5: junsung+=input3; break;
					case 6: hyeonseo+=input3; break;
					case 7: ain+=input3; break;
					case 8: kangho+=input3; break;
					case 9: chanjung+=input3; break;
					case 10: taehyun+=input3; break;
					case 11: hakjin+=input3; break;
					case 12: yeojun+=input3; break;
					case 13: kimjun+=input3; break;
					case 14: yunseo+=input3; break;
					case 15: jungyoon+=input3; break;
					case 16: parkjun+=input3; break;
					case 17: jumi+=input3; break;
					case 18: kanghyeon+=input3; break;
					case 19: hyeonwoo+=input3; break;
					}
				}
			}
			printf("매수가 완료되었습니다.\n");
		}

		else {		//매도
			for (int j = 1; j < 2; j++) {
				printf("얼만큼 파시겠습니까? : ");
				scanf_s("%d", &input3);
				if (input3>have) {
					printf("주식 수가 부족합니다. 처음부터 다시 실행됩니다.\n");
					break;
				}
			}
			printf("매도가 완료되었습니다.\n");
		}
	}
}
void cursor2() {
	int x = 3, y = 3;
	a = 0;
	while (_kbhit()) {
		gotoxy(x, y);
		printf("→");
		if (_kbhit()) {
			if (x == 3) {
				//위 아래
				if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // ↓

					if (y >= 29) y = 29;	// y의 최댓값
					else {

						if (y < 17) y += 7;
						else y += 6;

						system("cls");
						game_start();
					}
				}

				else if (GetAsyncKeyState(VK_UP) & 0x8000) {		 // ↑

					if (y <= 3) { y = 3; }		// y의 최솟값
					else {
						if (y <= 17) y -= 7;
						else y -= 6;
						system("cls");
						game_start();
					}
				}
			}

			//좌 우
			if (y == 29) {
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { // →

					if (x >= 66) x = 66;	// x의 최댓값
					else {
						x += 21;
						system("cls");
						game_start();
					}
				}

				else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {		 // ←

					if (x <= 3)  x = 3; 		// x의 최솟값
					else {
						x -= 21;
						system("cls");
						game_start();
					}
				}
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				if ((x == 3 && y == 3) || (x == 3 && y == 10)) {		//매수 or 매도
					Sleep(100);
					system("cls");
					buy_sell();
					Sleep(100);
					while (1) {
						if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //엔터 입력 시 뒤로가기
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 3 && y == 17) {		//보유 주식
					system("cls");
					have_stock();
					Sleep(100);
					while (1) {
						if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //엔터 입력 시 뒤로가기
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 3 && y == 23) {		//퀴즈
					system("cls");
					quiz();
					Sleep(100);
					while (1) {
						if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //엔터 입력 시 뒤로가기
							ClearLineFromReadBuffer();
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 3 && y == 29) {		//가위바위보
					system("cls");
					tool();
					handle_game();
					while (1) {
						if (GetAsyncKeyState(VK_SPACE) & 0x8000) { //엔터 입력 시 뒤로가기
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 24 && y == 29) {		//이벤트
					system("cls");
					Sleep(100);
					blackjack();
					while (1) {
						if (GetAsyncKeyState(VK_SPACE) & 0x8000) { //엔터 입력 시 뒤로가기
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 45 && y == 29) {		//새로고침
					system("cls");
					break;
				}
				else if (x == 66 && y == 29) {		//게임 종료
					system("cls");
					exit(0);
				}
			}
		}
		Sleep(100);
	}
}
//동시 쓰레드
unsigned _stdcall Thread_A(void* arg)
{
	while (wallet < 30000000)
	{
		render();
	}
}

//구조체 값 할당
void initialization() { 
	CursorView();		//커서 숨기는 함수
	cursor1();
	setStock(&stock_heojung, 424000, 30000, 40, 60);	//원가격 / 폭 / 상승률 / 하락률 
	setStock(&stock_jinseo, 215000, 15000, 45, 55);
	setStock(&stock_junsung, 98500, 7000, 52, 48);
	setStock(&stock_minwook, 79500, 7000, 52, 48);
	setStock(&stock_jumi, 78000, 7000, 42, 58);
	setStock(&stock_hyeonseo, 64900, 6500, 50, 50);
	setStock(&stock_kangho, 54500, 4000, 40, 60);
	setStock(&stock_taehyun, 37500, 2000, 45, 55);
	setStock(&stock_chanjung, 28500, 1500, 51, 49);
	setStock(&stock_hakjin, 26000, 1000, 47, 43);
	setStock(&stock_yeojun, 19500, 500, 46, 54);
	setStock(&stock_kimjun, 17200, 500, 54, 56);
	setStock(&stock_yunseo, 3700, 400, 44, 56);
	setStock(&stock_jungyoon, 9100, 300, 40, 60);
	setStock(&stock_parkjun, 7400, 200, 43, 47);
	setStock(&stock_kanghyeon, 5400, 100, 57, 43);
	setStock(&stock_hyeonwoo, 2100, 50, 60, 40);
	setStock(&stock_ain, 1000, 40, 47, 53);
	setStock(&stock_eunyung, 1000, 100000, 5, 95);
}

void render() {
	game_start();
	Sleep(100);
	cursor2();
}