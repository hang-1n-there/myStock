#pragma once
#include <Windows.h>
#include <stdio.h>
enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE
};
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}
// x=19 20,y=
void starting() {
	SetConsoleTitle(TEXT("주식게임"));
	system("color FF");
	system("mode con:cols=1000 lines=100"); // 콘솔창 크기
	setColor(RED);
	printf("\t\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                          ■■■    ■■■■■    ■■■      ■■■   ■                           ■\n");
	printf("\t\t\t\t■                                        ■      ■      ■      ■      ■  ■      ■ ■      ■                   ■\n");
	printf("\t\t\t\t■                                        ■              ■      ■      ■  ■         ■    ■  ■                 ■\n");
	printf("\t\t\t\t■                                        ■              ■      ■      ■  ■         ■  ■                       ■\n");
	printf("\t\t\t\t■                                          ■■■        ■      ■      ■  ■         ■■                         ■\n");
	printf("\t\t\t\t■                                                ■      ■      ■      ■  ■         ■  ■                       ■\n");
	printf("\t\t\t\t■            ■  ■    ■  ■                    ■      ■      ■      ■  ■         ■    ■                     ■\n");
	printf("\t\t\t\t■          ■  ■  ■    ■              ■      ■      ■      ■      ■  ■      ■ ■      ■                   ■\n");
	printf("\t\t\t\t■          ■  ■  ■    ■                ■■■        ■        ■■■      ■■■   ■        ■                 ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                        이지 모드                                                   ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                        하드 모드                                                   ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                        게임 종료                                                   ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}
/*
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}*/