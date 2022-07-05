#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "init.h"
#include "console.h"
#include "stock_game.h"
#include <process.h>

int main() {
	starting();
	initialization();	//초기데이터

	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);

	while (wallet < 30000000) {		//3천만원 보유 시 엔딩
		Sleep(30000);
		update();		//주식 변동 관련
	}
	ending(); //엔딩
	return 0;
}