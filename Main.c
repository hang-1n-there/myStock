#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "init.h"
#include "console.h"
#include "stock_game.h"
#include <process.h>

int main() {
	starting();
	initialization();	//�ʱⵥ����

	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);

	while (wallet < 30000000) {		//3õ���� ���� �� ����
		Sleep(30000);
		update();		//�ֽ� ���� ����
	}
	ending(); //����
	return 0;
}