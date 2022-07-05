#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "init.h"
enum {
	BLACexturnK,
	DARK_BLUexturnE,
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

void starting() {
	SetConsoleTitle(TEXT("주식게임"));
	system("color FF");
	system("mode con:cols=1000 lines=100"); // 콘솔창 크기
	setColor(WHITE);
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
	printf("\t\t\t\t■                                                        게임 설명                                                   ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                        게임 종료                                                   ■\n");
	printf("\t\t\t\t■                                                      ------------                                                  ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void game_rule() {
	printf("\t\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  게임을 시작하면 왼쪽의 주식 현황을 보고 가운데의 주식 매수/매도를 선택할 수 있습니다                              ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  아래쪽의 미션버튼을 선택해 오늘자 미션을 확인할 수 있습니다                                                       ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  아래쪽의 이벤트버튼을 선택해 오늘의 이벤트를 확인할 수 있습니다                                                   ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  아래쪽의 퀴즈버튼을 선택해 오늘의 퀴즈를 풀 수 있습니다                                                           ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  오른쪽의 시계로 오늘 남은시간을 확인할 수 있습니다                                                                ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  주식별로 상승/하락확률이 다르고, 확률이 낮을수록 수익이 큽니다                                                    ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  주식 원 가격의 50%가 오르면 하락 확률이 대폭 증가합니다                                                            ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  주식 원 가격의 80%가 내리면 상장 폐지후 3일후 재상장됩니다                                                         ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  상장 폐지가 되면 보유하고있는 주식이 사라지니 주의하시길 바랍니다                                                 ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  코인은 상승확률이 매우 낮은 대신 수익률이 좋습니다                                                                ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  코인은 이벤트의 영향을 받지 않습니다                                                                              ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  코인은 하락할시 보유량 삭제 / 상승할시 자동으로 판매됩니다                                                        ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■  현금으로 3천만원 보유시 자동으로 엔딩이 진행됩니다(주식 미포함)                       뒤로가기(Enter)             ■\n");
	printf("\t\t\t\t■                                                                                                                    ■\n");
	printf("\t\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void game_start() {
	system("mode con:cols=100 lines=35");
	printf("\n");
	printf("       ______________                    ---------------[주식 현황]--------------- \n");
	printf("      |              |                  |                                          \n");
	printf("      |     매수     |                  |                                          \n");
	printf("      |______________|                  | 은영 코인 - %d                            \n" , stock_eunyung.price);
	printf("                                        |                                          \n");
	printf("                                        | 허정 유통 - %d                           \n" , stock_heojung.price);
	printf("                                        | 진서 건설 - %d                           \n" , stock_jinseo.price);
	printf("       ______________                   | 민욱 반도체 - %d                         \n" , stock_minwook.price);
	printf("      |              |                  | 준성 게임즈 - %d                         \n" , stock_junsung.price);
	printf("      |     매도     |                  | 현서 조선 - %d                           \n" , stock_hyeonseo.price);
	printf("      |______________|                  | 아인 세큐리티 - %d                       \n" , stock_ain.price);
	printf("                                        | 강호 제과 - %d                           \n" , stock_kangho.price);
	printf("                                        | 태현 전자 - %d                           \n" , stock_taehyun.price);
	printf("                                        | 찬정 모터스 - %d                         \n" , stock_chanjung.price);
	printf("       ______________                   | 학진 문학 - %d                           \n" , stock_hakjin.price);
	printf("      |              |                  | 여준 리츠 - %d                           \n" , stock_yeojun.price);
	printf("      |   보유 주식  |                  | 김준 철물 - %d                           \n" , stock_kimjun.price);
	printf("      |______________|                  | 윤서 화재 - %d                           \n" , stock_yunseo.price);
	printf("                                        | 정윤 은행 - %d                           \n" , stock_jungyoon.price);
	printf("                                        | 박준 스포츠 - %d                         \n" , stock_parkjun.price);
	printf("       ______________                   | 주미 산업 - %d                           \n" , stock_jumi.price);
	printf("      |              |                  | 강현 투자 - %d                           \n" , stock_kanghyeon.price);
	printf("      |     퀴즈     |                  | 현우 전력 - %d                           \n" , stock_hyeonwoo.price);
	printf("      |______________|                  |_________________________________________ \n");
	printf("                                                                                   \n");
	printf("                                                                                   \n\n");
	printf("       ______________       ______________       _____________        _____________ \n");
	printf("      |  가위바위보  |     |    이벤트    |     |   새로고침  |      |   게임종료  |\n");
	printf("      |              |     |              |     |             |      |             |\n");
	printf("\n");// 화살표 자리는 > 표시	
}

void have_stock() {
	have=
		(eunyung * stock_eunyung.price) + (heojung * stock_heojung.price) + (jinseo * stock_jinseo.price) +
		(junsung * stock_junsung.price) + (taehyun * stock_taehyun.price) + (chanjung * stock_chanjung.price) + (hakjin * stock_hakjin.price) +
		(hyeonseo * stock_hyeonseo.price) + (yunseo * stock_yunseo.price) + (kimjun * stock_kimjun.price) + (yeojun * stock_yeojun.price) +
		(ain * stock_ain.price) + (jungyoon * stock_jungyoon.price) + (parkjun * stock_parkjun.price) + (jumi * stock_jumi.price) +
		(kangho * stock_kangho.price) + (kanghyeon * stock_kanghyeon.price) + (hyeonwoo * stock_hyeonwoo.price);

	printf("  [보유 주식]\n");
	printf("  은영 코인 - %d 주\n" , eunyung);
	printf("  허정 유통 - %d 주\n" , heojung);
	printf("  진서 건설 - %d 주\n" , jinseo);
	printf("  준성 게임즈 - %d 주\n" , junsung);
	printf("  현서 조선 - %d 주\n" , hyeonseo);
	printf("  아인 세큐리티 - %d 주\n" , ain);
	printf("  강호 제과 - %d 주\n" , kangho);
	printf("  태현 전자 - %d 주\n" , taehyun);
	printf("  찬정 모터스 - %d 주\n" , chanjung);
	printf("  학진 문학 - %d 주\n" , hakjin);
	printf("  여준 리츠 - % d 주\n" , yeojun);
	printf("  김준 철물 - %d 주\n" , kimjun);
	printf("  윤서 화재 - %d 주\n" , yunseo);
	printf("  정윤 은행 - %d 주\n" , jungyoon);
	printf("  박준 스포츠 - %d 주\n" , parkjun);
	printf("  주미 산업 - %d 주\n" , jumi);
	printf("  강현 투자 - %d 주\n" , kanghyeon);
	printf("  현우 전력 - %d 주\n\n" , hyeonwoo);
	printf("      [통장]\n");
	printf("     %d 원\n\n" , wallet);
	printf("  [보유 자산 가치]\n");
	printf("       %d 원\n\n", have);
}

void sisors() {
	printf("\n");
	printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("|                                                                                                    |\n");
	printf("|     -------  |       ---  |          |     | |        ---  |          |     |          ┌──┐        |\n");
	printf("|           |  |___   |   | |          |_____| |       |   | |          |_____|          |  |        |\n");
	printf("|          |   |      |___| |          |     | |---    |___| |          |_____|          |__|        |\n");
	printf("|         |    |      ----- |          |_____| |       ----- |             |              __         |\n");
	printf("|        |     |        |   |                  |         |   |          --------         |__|        |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                                                                                    |\n");
	printf("|                                                 @@@ @@@                                            |\n");
	printf("|                                                 @@@ @@@                                            |\n");
	printf("|                                                 @@@ @@@                                            |\n");
	printf("|                                                 @@@ @@@                                            |\n");
	printf("|                                              @@ @@@ @@@                                            |\n");
	printf("|                                          @@ @@@ @@@ @@@@@                                          |\n");
	printf("|                                         @@@ @@@ @@@ @@@@@@                                         |\n");
	printf("|                                         @@@ @@@ @@@@@@@@@@@                                        |\n");
	printf("|                                         @@@@@@@ @@                                                 |\n");
	printf("|                                         @@@@@@@@@@ @@@@@@@@                                        |\n");
	printf("|                                         @@@@@@@@@@ @@@@@@@@                                        |\n");
	printf("|                                                                                                    |\n");
	printf("|                                    [CPU]의 선택은 : 가위 입니다                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                             [플레이어]                                             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|            [가위]              |              [바위]             |                [보]             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
}

void rock() {
	printf("\n");
	printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("|                                                                                                    |\n");
	printf("|     -------  |       ---  |          |     | |        ---  |          |     |         ┌───┐        |\n");
	printf("|           |  |___   |   | |          |_____| |       |   | |          |_____|          |  |        |\n");
	printf("|          |   |      |___| |          |     | |---    |___| |          |_____|          |__|        |\n");
	printf("|         |    |      ----- |          |_____| |       ----- |             |              __         |\n");
	printf("|        |     |        |   |                  |         |   |          --------         |__|        |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@                                     |\n");
	printf("|                                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@                                     |\n");
	printf("|                                   @@@@ @@@@ @@@@ @@@@ @@@@@@@@                                     |\n");
	printf("|                                   @@@@ @@@@ @@@@ @@@@ @@@@@@@@                                     |\n");
	printf("|                                   @@@@ @@@@ @@@@ @@@@ @@@@@@@@                                     |\n");
	printf("|                                   @@@@ @@@@ @@@@ @@@@ @@@@@@@@                                     |\n");
	printf("|                                                           @@@@                                     |\n");
	printf("|                                                    @@@@@@@@@@@                                     |\n");
	printf("|                                                    @@@@@@@@@@@                                     |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                    [CPU]의 선택은 : 바위 입니다                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                             [플레이어]                                             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");;
	printf("|            [가위]              |              [바위]             |                [보]             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("\n");
}

void paper() {
	printf("\n");
	printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("|                                                                                                    |\n");
	printf("|     -------  |       ---  |          |     | |        ---  |          |     |         ┌───┐       |\n");
	printf("|           |  |___   |   | |          |_____| |       |   | |          |_____|          |  |        |\n");
	printf("|          |   |      |___| |          |     | |---    |___| |          |_____|          |__|        |\n");
	printf("|         |    |      ----- |          |_____| |       ----- |             |              __         |\n");
	printf("|        |     |        |   |                  |         |   |          --------         |__|        |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                 @@@                                                |\n");
	printf("|                                                 @@@ @@@                                            |\n");
	printf("|                                             @@@ @@@ @@@                                            |\n");
	printf("|                                         @@@ @@@ @@@ @@@                                            |\n");
	printf("|                                         @@@ @@@ @@@ @@@ @@@                                        |\n");
	printf("|                                         @@@@@@@@@@@@@@@@@@@                                        |\n");
	printf("|                                         @@@@@@@@@@@@@@@@@                                          |\n");
	printf("|                                          @@@@@@@@@@@@@@@                                           |\n");
	printf("|                                           @@@@@@@@@@@@@                                            |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                    [CPU]의 선택은 : 보 입니다                                      |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                             [플레이어]                                             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|            [가위]              |              [바위]             |                [보]             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("\n");
}
void tool() {
	system("mode con:cols=110 lines=32");
	printf("\n");
	printf("┌───────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("|                                                                                                    |\n");
	printf("|     -------  |       ---  |          |     | |        ---  |          |     |         ┌───┐        |\n");
	printf("|           |  |___   |   | |          |_____| |       |   | |          |_____|          |  |        |\n");
	printf("|          |   |      |___| |          |     | |---    |___| |          |_____|          |__|        |\n");
	printf("|         |    |      ----- |          |_____| |       ----- |             |              __         |\n");
	printf("|        |     |        |   |                  |         |   |          --------         |__|        |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|                                    [CPU]의 선택은 : ? 입니다                                       |\n");
	printf("|                                                                                                    |\n");
	printf("|                                                                                                    |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|                                             [플레이어]                                             |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("|            [가위]              |               [바위]             |                [보]            |\n");
	printf("|────────────────────────────────────────────────────────────────────────────────────────────────────|\n");
	printf("\n");
}
void ending() {
	printf("\n");
	printf(" ____________________________________________________________________________________________________________________________________\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                             ■                                                                                                     |\n");
	printf("|     ■■■■■■■    ■■■  ■                                    ■■■■■                                                     |\n");
	printf("|     ■            ■■                                            ■         ■                                                    |\n");
	printf("|     ■■          ■        ■                                   ■                                                                |\n");
	printf("|                   ■        ■                                   ■                                                ■              |\n");
	printf("|                 ■■        ■                                    ■                                               ■              |\n");
	printf("|                 ■        ■                                        ■■                                           ■              |\n");
	printf("|                 ■        ■                                            ■■                                      ■               |\n");
	printf("|                 ■        ■                                        ■■■                                ■■■  ■               |\n");
	printf("|  ■■■■       ■      ■  ■■          ■■■                   ■                 ■                 ■     ■■      ■■■■ |\n");
	printf("|                 ■      ■      ■      ■      ■                ■         ■        ■               ■        ■               |\n");
	printf("|                 ■      ■       ■    ■ ■■■■                ■          ■       ■■■           ■       ■                |\n");
	printf("|                 ■    ■         ■   ■■                        ■          ■       ■    ■        ■        ■                |\n");
	printf("|                 ■    ■         ■ ■   ■                        ■       ■         ■      ■      ■        ■                |\n");
	printf("|                 ■    ■           ■      ■■■                    ■■■■         ■       ■ ■    ■      ■                 |\n");
	printf("|               ■                                                                      ■        ■         ■■■                  |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|                                                                                                                                    |\n");
	printf("|____________________________________________________________________________________________________________________________________|\n");
	printf("\n");
}