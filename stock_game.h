#pragma once
#include <stdio.h>
#include "SFMT.h"
int update() {
	sfmt_t sfmt;
	sfmt_init_gen_rand(&sfmt, time(NULL));
	
	int pr = sfmt_genrand_uint32(&sfmt) % 100; //·£´ý

	//»ó½Â È®·ü
	if (pr <= stock_heojung.rise) 
		stock_heojung.price += stock_heojung.wid; //»ó½Â

	//ÇÏ¶ô È®·ü
	else 
		stock_heojung.price -= stock_heojung.wid; //ÇÏ¶ô

	if (pr <= stock_jinseo.rise)
		stock_jinseo.price += stock_jinseo.wid;
	else
		stock_jinseo.price -= stock_jinseo.wid;

	if (pr <= stock_minwook.rise)
		stock_minwook.price += stock_minwook.wid;
	else
		stock_minwook.price -= stock_minwook.wid;

	if (pr <= stock_junsung.rise)
		stock_junsung.price += stock_junsung.wid;
	else
		stock_junsung.price -= stock_junsung.wid;

	if (pr <= stock_hyeonseo.rise)
		stock_hyeonseo.price += stock_hyeonseo.wid;
	else
		stock_hyeonseo.price -= stock_hyeonseo.wid;

	if (pr <= stock_ain.rise)
		stock_ain.price += stock_ain.wid;
	else
		stock_ain.price -= stock_ain.wid;

	if (pr <= stock_kangho.rise)
		stock_kangho.price += stock_kangho.wid;
	else
		stock_kangho.price -= stock_kangho.wid;

	if (pr <= stock_taehyun.rise)
		stock_taehyun.price += stock_taehyun.wid;
	else
		stock_taehyun.price -= stock_taehyun.wid;

	if (pr <= stock_chanjung.rise)
		stock_chanjung.price += stock_chanjung.wid;
	else
		stock_chanjung.price -= stock_chanjung.wid;

	if (pr <= stock_yeojun.rise)
		stock_yeojun.price += stock_yeojun.wid;
	else
		stock_yeojun.price -= stock_yeojun.wid;

	if (pr <= stock_kimjun.rise)
		stock_kimjun.price += stock_kimjun.wid;
	else
		stock_kimjun.price -= stock_kimjun.wid;

	if (pr <= stock_jumi.rise)
		stock_jumi.price += stock_jumi.wid;
	else
		stock_jumi.price -= stock_jumi.wid;

	if (pr <= stock_kanghyeon.rise)
		stock_kanghyeon.price += stock_kanghyeon.wid;
	else
		stock_kanghyeon.price -= stock_kanghyeon.wid;

	if (pr <= stock_hyeonwoo.rise)
		stock_hyeonwoo.price += stock_hyeonwoo.wid;
	else
		stock_hyeonwoo.price -= stock_hyeonwoo.wid;

	if (pr <= stock_eunyung.rise)
		stock_eunyung.price += stock_eunyung.wid;
	else
		stock_eunyung.price -= stock_eunyung.wid;

	if (pr <= stock_hakjin.rise)
		stock_hakjin.price += stock_hakjin.wid;
	else
		stock_hakjin.price -= stock_hakjin.wid;

	if (pr <= stock_parkjun.rise)
		stock_parkjun.price += stock_parkjun.wid;
	else
		stock_parkjun.price -= stock_parkjun.wid;

	if (pr <= stock_jungyoon.rise)
		stock_jungyoon.price += stock_jungyoon.wid;
	else
		stock_jungyoon.price -= stock_jungyoon.wid;

	if (pr <= stock_yunseo.rise)
		stock_yunseo.price += stock_yunseo.wid;
	else
		stock_yunseo.price -= stock_yunseo.wid;

	return ;
}
void render() {

}