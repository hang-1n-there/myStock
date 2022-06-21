#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "console.h"
#include "init.h"
#include "stock_game.h"

int main() {
	starting();
	initialization(); //초기데이터
	while (1) {
		update(); //주식 변동 관련

		render(); //주식 그래프 그림
	}
	//ending(); //엔딩

	return 0;
}