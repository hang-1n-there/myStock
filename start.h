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
	WHITE,
};
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}


void starting() {
	SetConsoleTitle(TEXT("�ֽİ���"));
	system("color FF");
	system("mode con:cols=1000 lines=100"); // �ܼ�â ũ��
	setColor(RED);
	printf("\t\t\t\t                                                                                                                        \n");
	printf("\t\t\t\t                                                                                                                        \n");
	printf("\t\t\t\t                                                                                                                        \n");
	printf("\t\t\t\t                                                                                                                        \n");
	printf("\t\t\t\t                                                                                                                        \n");
	printf("\t\t\t\t                                                                                                                        \n");
	printf("\t\t\t\t                                ����        ��������        ����            �����      ��                  \n");
	printf("\t\t\t\t                              ��      ��            ��            ��      ��        ��        ��    ��                  \n");
	printf("\t\t\t\t                            ��        ��            ��          ��          ��    ��          ��    ��        ��        \n");
	printf("\t\t\t\t                            ��                      ��          ��          ��    ��                ��      ��  ��      \n");
	printf("\t\t\t\t                            ��                      ��          ��          ��    ��                ��      ��  ��      \n");
	printf("\t\t\t\t                            ��                      ��          ��          ��    ��                ��    ��            \n");
	printf("\t\t\t\t                            ��                      ��          ��          ��    ��                ��    ��            \n");
	printf("\t\t\t\t                              ��                    ��          ��          ��    ��                ��  ��              \n");
	printf("\t\t\t\t                              ��                    ��          ��          ��    ��                ��  ��              \n");
	printf("\t\t\t\t                                ��                  ��          ��          ��    ��                ���                \n");
	printf("\t\t\t\t                                ��                  ��          ��          ��    ��                ���                \n");
	printf("\t\t\t\t                                  ��                ��          ��          ��    ��                ���                \n");
	printf("\t\t\t\t                                  ��                ��          ��          ��    ��                ���                \n");
	printf("\t\t\t\t                                    ��              ��          ��          ��    ��                ��  ��              \n");
	printf("\t\t\t\t                                    ��              ��          ��          ��    ��                ��  ��              \n");
	printf("\t\t\t\t                                      ��            ��          ��          ��    ��                ��    ��            \n");
	printf("\t\t\t\t                                      ��            ��          ��          ��    ��                ��    ��            \n");
	printf("\t\t\t\t    ��  ��    ��      ��              ��            ��          ��          ��    ��                ��      ��          \n");
	printf("\t\t\t\t    ��  ��    ��      ��              ��            ��          ��          ��    ��                ��      ��          \n");
	printf("\t\t\t\t  ��  ��  ��    ��  ��      ��        ��            ��          ��          ��    ��          ��    ��        ��        \n");
	printf("\t\t\t\t  ��  ��  ��    ��  ��      ��        ��            ��            ��      ��        ��        ��    ��        ��        \n");
	printf("\t\t\t\t  ��  ��  ��      ��          �����              ��              ����            �����      ��          ��      \n");
	printf("\t\t\t\t  ��      ��      ��                                                                                                    \n");
	printf("\t\t\t\t  ��      ��      ��                                                                                                    \n");
	printf("\t\t\t\t  ��      ��      ��                                                                                                    \n");
}
