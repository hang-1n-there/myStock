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
	SetConsoleTitle(TEXT("�ֽİ���"));
	system("color FF");
	system("mode con:cols=1000 lines=100"); // �ܼ�â ũ��
	setColor(RED);
	printf("\t\t\t\t�������������������������������������������������������������\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                          ����    ������    ����      ����   ��                           ��\n");
	printf("\t\t\t\t��                                        ��      ��      ��      ��      ��  ��      �� ��      ��                   ��\n");
	printf("\t\t\t\t��                                        ��              ��      ��      ��  ��         ��    ��  ��                 ��\n");
	printf("\t\t\t\t��                                        ��              ��      ��      ��  ��         ��  ��                       ��\n");
	printf("\t\t\t\t��                                          ����        ��      ��      ��  ��         ���                         ��\n");
	printf("\t\t\t\t��                                                ��      ��      ��      ��  ��         ��  ��                       ��\n");
	printf("\t\t\t\t��            ��  ��    ��  ��                    ��      ��      ��      ��  ��         ��    ��                     ��\n");
	printf("\t\t\t\t��          ��  ��  ��    ��              ��      ��      ��      ��      ��  ��      �� ��      ��                   ��\n");
	printf("\t\t\t\t��          ��  ��  ��    ��                ����        ��        ����      ����   ��        ��                 ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                      ------------                                                  ��\n");
	printf("\t\t\t\t��                                                        ���� ���                                                   ��\n");
	printf("\t\t\t\t��                                                      ------------                                                  ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                      ------------                                                  ��\n");
	printf("\t\t\t\t��                                                        �ϵ� ���                                                   ��\n");
	printf("\t\t\t\t��                                                      ------------                                                  ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                      ------------                                                  ��\n");
	printf("\t\t\t\t��                                                        ���� ����                                                   ��\n");
	printf("\t\t\t\t��                                                      ------------                                                  ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t��                                                                                                                    ��\n");
	printf("\t\t\t\t�������������������������������������������������������������\n");
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