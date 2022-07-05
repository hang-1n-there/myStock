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
#define SPADE "��"
#define CLUB "��"
#define DIA "��"
#define HEART "��"

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

//����
struct Question{
	char* Question; //����
	char* Case[2];	//������ �� ��ȣ
	int Answer;		//����
	BOOL Already;	//�̹� ������ ���� ����
};

struct Stock0 {
	int price;	// ������
	int wid;	// ��
	int rise;	// ��·�
	int fall;	// �϶���
};

enum shape { spade, club, dia, heart };
enum num { ace = 1, jack = 11, queen = 12, king = 13 };

// ī��
struct Card {
	int number;	//����
	char shape;	//���
};

// ��� ī��
struct Card card_all[52];
int next;

// ����
struct Player {
	int cash;
	int score;
	struct Card card_player[21];
};

struct Player player[3];

static int wallet = 1000000;		//����

// ī�� ���� �Լ�
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

// ī�� ä��� �Լ�
void filldeck()
{
	int i = 0;
	// 4���� ���� 13���� ���ڸ� ¦��� ī�� ����
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

// ���� �� �տ��� ���� ���� �����ִ� �Լ�
struct Card deal(int next)
{
	return card_all[next];
}

// ����ڰ� ���� ī�带 ���ڿ��� �ƴ� ī�� ������� ���, ���� ���
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

	// ace ��� ����
	if (ace_score == -1)
	{
		printf("ACE�� ���Գ׿�, [1/11]������ ����մϴ�: ");
		scanf_s("%d", &ace_score);
		player[p].score += ace_score;
	}

	printf("score : %d\n", player[p].score);

	return;
}

// �����ϴ� �Լ�
int betting(struct Player player)
{
	int won,bet=0;
	printf("���� �ɱ� ����, ȯ���� �����մϴ�. �󸶸� ȯ�� �ϽǷ���? ( 1cash == 100��) : ");
	scanf_s("%d", &won);

	if (won > wallet) {
		printf("ȯ���� �ȵ��ݾƿ�! �ٽ�");
		scanf_s("%d", &won);
	}

	player.cash += won / 100;

	printf("���� �ɾ�ô�! %d �� �󸶸� �����Ͻðڽ��ϱ�?", player.cash);
	scanf_s("%d", &bet);

	if (bet > player.cash)
	{
		printf("�̷��̷�... ���� �����ϱ���. ���ݸ� �Ʋ��߰ھ��. �ٽ� �Է� : ");
		scanf_s("%d", &bet);
		return bet;
	}
	else return bet;
}

// ������ ����
void stayorhit(int p, int turns)
{
	char answer;

	printf("\n##########TURN : PLAYER%d��##########\n\n", p);
	while (player[p].score < 21)
	{
		printf("HIT�� ���Ͻø� h��, STAY�� ���Ͻø� s�� �Է��ϼ���[h/s]: ");
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
			printf("HIT�̸� h, STAY�� s��ϱ�.. \n�ٽ� ��,");
		}
	}

	if (player[p].score > 21)
	{
		printf("21���� �Ѿ����ϴ�. LOSS\n");
		player[p].score = 0;
	}
	else if (player[p].score == 21)
	{
		printf("21���Դϴ�. WIN\n");
	}
}

// ������ ���������� 16������ �����ϰ� ����� hit
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

// ���� ����
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
			printf("!!! PLAYER1 �Ļ��ϼ̽��ϴ�.\n\n");
			player[1].cash += 100;
		}

		player[0].score = 0;
		player[1].score = 0;

		player[0].card_player[turns] = deal(next++);
		printcard(0, turns);

		printf("\n<<PLAYER1>>\n");
		printf("CASH (�⺻ ����) : %d\n", player[1].cash);
		player[1].card_player[turns] = deal(next++);
		printcard(1, turns);

		bet_total += bet[0];
		printf("\nPLAYER1��, ");
		bet[1] = betting(player[1]);
		bet_total += bet[1];

		stayorhit(1, turns);

		dealer(turns);

		printf("\n���� ���>> DEALER: %d / PLAYER1: %d\n", player[0].score, player[1].score);

		// ���� ����� ������, ���� �������� ���� �ݾ��� ����
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
		printf("\n���>> P1 CASH : %d \n", player[1].cash);

		wallet += player[1].cash*100;
		printf("ȯ�� �� �� �ݾ� : %d��\n" , wallet);

		char answer;
		printf("����Ͻðڽ��ϱ�? ");
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

	printf("������ ����˴ϴ�...");
}

void reset()
{
	player[0].score = 0; player[1].score = 0;
	player[1].cash = 100;

	filldeck(); shuffle(); next = 0;
}

// ���� ����
void blackjack()
{
	char choice = "";
	printf("���� ����(Y or y) , ���� ����(N or n) �� �ϳ��� �Է��ϼ��� : ");
	scanf_s("%c", &choice);
	fflush(stdin);
	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		printf("�̻��� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���! [y/n] ");
		scanf_s("%c", &choice);
	}

	if (choice == 'Y' || choice == 'y')
	{
		reset();
		play();
	}
	else if (choice == 'N' || choice == 'n')
	{
		printf("�� ���� ��������\n");
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

static int have;		//�ڻ갡ġ
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

//���� ���� �Լ�
void ClearLineFromReadBuffer(void)
{
	while (getchar() != '\n');
}

//Ŀ�� �̵� �Լ�
void gotoxy(int x, int y) { 
	COORD Cur = { 0 };
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//Ŀ�� ����� �Լ�
void CursorView() { 
	CONSOLE_CURSOR_INFO cursorInfo = { 0, 1};
	cursorInfo.dwSize = 1;		//Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE;		//Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//Ű �Է� �Լ�
int Getkeydown(int vkey) { 
	if (GetAsyncKeyState(vkey) & 0x8000) {
		return true;
	}
	return false;
}

//ù ȭ�� Ŀ�� �̵�
void cursor1() {		

	int x = 85, y = 18;			// ���α׷�������������������x,y ��ǥ

	do {
		gotoxy(x, y);
		printf("��"); 
		
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // ��
			
			if (y >= 26) { y = 26; } // y�� �ִ�
			else {
				y += 4; 
				system("cls");
				starting();
			}
		}

		else if (GetAsyncKeyState(VK_UP) & 0x8000) {		 // ��
			
			if (y <= 18) { y = 18; }		// y�� �ּڰ�
			else {
				y -= 4;
				system("cls");
				starting();
			}
		}
		Sleep(100);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {	//���� ��
			if (y == 18) {		// ���ӽ���
				printf(" ");
				system("cls");
				break;
			}
			else if (y == 22) { //���Ӽ���
				system("cls");
				game_rule();
				gotoxy(118, 28);
				printf("��");
				Sleep(300);
				while (1) {
					if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //���� �Է� �� �ڷΰ���
						break;
					}		
				}
				Sleep(100);
				system("cls");
				starting();
			}
			else if (y == 26) {
				system("cls");
				exit(0);			// ��������
			}
		}
	} while (1);
}

//���� ����
void quiz() {
	srand(time(NULL));
	struct Question data[] = {
		{"�츮 ������ ������?", "����" , "���" ,1,FALSE},
		{"���̰� ���� ����ϴ� ������?", "��" , "������" ,2,FALSE},
		{"������ ���� �����ϴ� �����?", "����" , "�ؼ�" ,1,FALSE},
		{"�ο��̰� �� ���Ƹ���? ", "&persand" , "with������" ,1,FALSE},
		{"������ �巡����� ?" ,"��ȸ�ǿ�" , "�ΰ�����������" ,2,FALSE},
		{"������ �巡����� ? ", "�巡�������Ǳݵ��Ͼ��ؽ�" , "DataBase" ,1,FALSE},
		{"�ؼ����� ��ģ��?",  "�����" , "������ ����" ,2,FALSE},
		{"������ �����ϴ� ������?", "�����ǰ�" , "������" ,1,FALSE},
		{"������ ���ֺ��� �ִϴ�?", "�̰��� ����� �����⿡ �����غ��Ҵ� r=1-sin��(��Ʈ)" , "������̺� ��������Ű �п� ���� ���̵� ��ȣȸ 2��" ,2,FALSE},
		{"�ο��̰� �� �ִ� TOP����?", "�Ϳ����� ���� ��Ű�� ��" , "ī���ߴ��� ���ް� �;� 3��" ,1,FALSE},
	};
	
	int rnd = rand() % 10 + 1;
	int cnt = 0,input;
	printf("��������������������������\n");
	printf("�� Quiz Game ��\n");
	printf("��������������������������\n");

	for (int i = 0; i < 10; i++) {
		printf("\n%d. %s\n", i+1,data[i].Question);
		printf("(1.%s , 2.%s)\n", data[i].Case[0], data[i].Case[1]);
		printf("1���� 2�� �� �ϳ��� �����ϼ��� : ");
		scanf_s("%d", &input);
		if (input == 1 || input == 2) {
			if (input == data[i].Answer) cnt++;
		}
		else {
			i -= 1;
			printf("�ٽ� �Է��ϼ���\n");
		}
	}
	wallet += 100000 * cnt * rnd;
	printf("\n���� %d���� �Ϸ��ϼ̽��ϴ�. %d���� �����մϴ�.\n" ,cnt, 100000 * cnt * rnd);
	printf(">>���� Ű�� �Է��Ͻø� ����˴ϴ�.");
	Sleep(200);
}

void handle_game() {
	srand(time(NULL));
	int my_num, bet;
	int cpu_num = rand() % 3 + 1;

	for (int i = 1; i < 2; i++) {
		printf("�غ��� �ݾ��� �����ϼ��� (�̱�� 2�� , ���� 1.5��, ���� 0.7��) : ");
		scanf_s("%d", &bet);
		if (wallet < bet) {
			i -= 1;
			printf("\n���� �����մϴ�..  �ٽ� �Է��ϼ���.\n");
		}
	}
	wallet -= bet;
	for (int i = 1; i < 2; i++) {
		printf("������ ���ðڽ��ϱ�? (1.���� , 2.���� , 3.��) : ");
		scanf_s("%d", &my_num);

		if(my_num>3 || my_num<1) {
			i -= 1;
			printf("\n�ٽ� �Է��ϼ���.\n");
		}
	}
	
	if (cpu_num == 1) sisors();
	else if (cpu_num == 2) rock();
	else  if(cpu_num ==3) paper();

	if (cpu_num == 1) printf("����� ������ \"����\" �Դϴ�.\n");
	else if (cpu_num == 2) printf("����� ������ \"����\" �Դϴ�.\n");
	else  if (cpu_num == 3) printf("����� ������ \"��\" �Դϴ�.\n");

	if (my_num == cpu_num) {
		printf("�ƽ��ƽ��ϰ� �����ϴ�.. X1.5��!\n");
		wallet += bet * 1.5;
	}
	else if ((cpu_num == 1 && my_num == 2) || (cpu_num == 2 && my_num == 1) || (cpu_num == 3 && my_num == 1)) { //���� ���
		printf("��ӳ� ���̳׿� ���� ���ñݾ��� 0.7�踸 ��������� ����\n");
		wallet += bet * 0.7;
	}
	else {
		printf("��.. 2��\n");
		wallet += bet * 2;
	}
	printf("���� �ݾ� : %d\n", wallet);
	printf("�����̽��� Ŭ�� �� ����˴ϴ�.");
	return;
}

void buy_sell() {
	int input1,input2,input3,price,have;
	printf("1.���� ���� - %d\n", stock_eunyung.price);
	printf("2.���� ���� - %d\n", stock_heojung.price);
	printf("3.���� �Ǽ� - %d\n", stock_jinseo.price);
	printf("4.�ο� �ݵ�ü - %d\n", stock_minwook.price);
	printf("5.�ؼ� ������ - %d\n", stock_junsung.price);
	printf("6.���� ���� - %d\n", stock_hyeonseo.price);
	printf("7.���� ��ť��Ƽ - %d\n", stock_ain.price);
	printf("8.��ȣ ���� - %d\n", stock_kangho.price);
	printf("9.���� ���� - %d\n", stock_taehyun.price);
	printf("10.���� ���ͽ� - %d\n", stock_chanjung.price);
	printf("11.���� ���� - %d\n", stock_hakjin.price);
	printf("12.���� ���� - %d\n", stock_yeojun.price);
	printf("13.���� ö�� - %d\n", stock_kimjun.price);
	printf("14.���� ȭ�� - %d \n", stock_yunseo.price);
	printf("15.���� ���� - %d\n", stock_jungyoon.price);
	printf("16.���� ������ - %d\n", stock_parkjun.price);
	printf("17.�ֹ� ��� - %d\n", stock_jumi.price);
	printf("18.���� ���� - %d\n", stock_kanghyeon.price);
	printf("19.���� ���� - %d\n\n", stock_hyeonwoo.price);
	for (int k = 1; k < 2; k++) {
		for (int j = 1; j < 2; j++) {		//����
			printf("� �ֽ��� �ż�/�ŵ� �ұ��? : ");
			scanf_s("%d", &input1);
			if (input1 < 1 || input1 > 19) {
				j -= 1;
				printf("�Է��Ͻ� �ֽ��� ã�� �� �����ϴ�. �ٽ�\n");
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
		for (int i = 1; i < 2; i++) {		//�ż�/�ŵ�
			printf("1. �ż� , 2. �ŵ�");
			scanf_s("%d", &input2);
			if(input2 <1 || input2>2) {
				i -= 1;
				printf("�ٽ� �Է��ϼ���\n");
			}
		}

		if (input2 == 1) {		//�ż�	
			for (int j = 1; j < 2; j++) {
				printf("��ŭ ��ðڽ��ϱ�? : ");
				scanf_s("%d", &input3);
				if (price * input3>wallet) {
					printf("���� �����մϴ�. ó������ �ٽ� ����˴ϴ�.\n");
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
			printf("�ż��� �Ϸ�Ǿ����ϴ�.\n");
		}

		else {		//�ŵ�
			for (int j = 1; j < 2; j++) {
				printf("��ŭ �Ľðڽ��ϱ�? : ");
				scanf_s("%d", &input3);
				if (input3>have) {
					printf("�ֽ� ���� �����մϴ�. ó������ �ٽ� ����˴ϴ�.\n");
					break;
				}
			}
			printf("�ŵ��� �Ϸ�Ǿ����ϴ�.\n");
		}
	}
}
void cursor2() {
	int x = 3, y = 3;
	a = 0;
	while (_kbhit()) {
		gotoxy(x, y);
		printf("��");
		if (_kbhit()) {
			if (x == 3) {
				//�� �Ʒ�
				if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // ��

					if (y >= 29) y = 29;	// y�� �ִ�
					else {

						if (y < 17) y += 7;
						else y += 6;

						system("cls");
						game_start();
					}
				}

				else if (GetAsyncKeyState(VK_UP) & 0x8000) {		 // ��

					if (y <= 3) { y = 3; }		// y�� �ּڰ�
					else {
						if (y <= 17) y -= 7;
						else y -= 6;
						system("cls");
						game_start();
					}
				}
			}

			//�� ��
			if (y == 29) {
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { // ��

					if (x >= 66) x = 66;	// x�� �ִ�
					else {
						x += 21;
						system("cls");
						game_start();
					}
				}

				else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {		 // ��

					if (x <= 3)  x = 3; 		// x�� �ּڰ�
					else {
						x -= 21;
						system("cls");
						game_start();
					}
				}
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				if ((x == 3 && y == 3) || (x == 3 && y == 10)) {		//�ż� or �ŵ�
					Sleep(100);
					system("cls");
					buy_sell();
					Sleep(100);
					while (1) {
						if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //���� �Է� �� �ڷΰ���
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 3 && y == 17) {		//���� �ֽ�
					system("cls");
					have_stock();
					Sleep(100);
					while (1) {
						if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //���� �Է� �� �ڷΰ���
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 3 && y == 23) {		//����
					system("cls");
					quiz();
					Sleep(100);
					while (1) {
						if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //���� �Է� �� �ڷΰ���
							ClearLineFromReadBuffer();
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 3 && y == 29) {		//����������
					system("cls");
					tool();
					handle_game();
					while (1) {
						if (GetAsyncKeyState(VK_SPACE) & 0x8000) { //���� �Է� �� �ڷΰ���
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 24 && y == 29) {		//�̺�Ʈ
					system("cls");
					Sleep(100);
					blackjack();
					while (1) {
						if (GetAsyncKeyState(VK_SPACE) & 0x8000) { //���� �Է� �� �ڷΰ���
							break;
						}
					}
					Sleep(100);
					system("cls");
					break;
				}
				else if (x == 45 && y == 29) {		//���ΰ�ħ
					system("cls");
					break;
				}
				else if (x == 66 && y == 29) {		//���� ����
					system("cls");
					exit(0);
				}
			}
		}
		Sleep(100);
	}
}
//���� ������
unsigned _stdcall Thread_A(void* arg)
{
	while (wallet < 30000000)
	{
		render();
	}
}

//����ü �� �Ҵ�
void initialization() { 
	CursorView();		//Ŀ�� ����� �Լ�
	cursor1();
	setStock(&stock_heojung, 424000, 30000, 40, 60);	//������ / �� / ��·� / �϶��� 
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