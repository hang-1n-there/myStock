#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "console.h"
#include "init.h"
#include "stock_game.h"

int main() {
	starting();
	initialization(); //�ʱⵥ����
	while (1) {
		update(); //�ֽ� ���� ����

		render(); //�ֽ� �׷��� �׸�
	}
	//ending(); //����

	return 0;
}