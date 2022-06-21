#pragma once
#include <stdio.h>
#include "SFMT.h"

struct Stock0 {
	int price; // ¿ø°¡°Ý
	int wid;   // Æø
	int rise;  // »ó½Â·ü
	int fall;  // ÇÏ¶ô·ü
};

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

void setStock(struct Stock0* st, int price, int wid, int rise, int fall) {
	st->price = price;
	st->rise = rise;
	st->fall = fall;
}

void initialization() {
	setStock(&stock_heojung, 424000, 30000, 10, 90); //¿ø°¡°Ý / Æø / »ó½Â·ü / ÇÏ¶ô·ü 
	setStock(&stock_jinseo, 215000, 15000, 20, 80);
	setStock(&stock_minwook, 153500, 10000, 25, 75);
	setStock(&stock_junsung, 98500, 7000, 30, 70);
	setStock(&stock_hyeonseo, 77900, 6500, 30, 70);
	setStock(&stock_ain, 68500, 6000, 30, 70);
	setStock(&stock_kangho, 54500, 4000, 40, 60);
	setStock(&stock_taehyun, 37500, 2000, 45, 55);
	setStock(&stock_chanjung, 28500, 1500, 50, 50);
	setStock(&stock_hakjin, 26000, 1000, 55, 45);
	setStock(&stock_yeojun, 19500, 500, 60, 40);
	setStock(&stock_kimjun, 17200, 500, 60, 40);
	setStock(&stock_yunseo, 3700, 400, 65, 25);
	setStock(&stock_jungyoon, 9100, 300, 70, 30);
	setStock(&stock_parkjun, 7400, 200, 80, 20);
	setStock(&stock_jumi, 6900, 150, 85, 15);
	setStock(&stock_kanghyeon, 5400, 100, 85, 15);
	setStock(&stock_hyeonwoo, 2100, 50, 90, 10);
	setStock(&stock_eunyung, 1000, 100000, 5, 95);
	gotoxy(85, 18);
	printf("¡æ");
}