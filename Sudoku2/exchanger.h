#pragma once
#include "stdafx.h"

#define EXCHANGER_GROUPS_SIZE 3		// -- 对几个数字进行全排列
#define EXCHANGER_GROUPS_COUNT 3	// -- 有几组数字需要排列
#define MAX_EXCHANGE_COUNT 6		// -- 一共需要交换成员几次

class Exchanger {
private:
	int exchange_counter = 0;	// -- record exchanging times
	bool reach_half = false;	// -- gone through half of posibilities
	bool mode = true;			// -- exchange member(1, 2) when true; overwise exchange member(2, 3)

public:
	Exchanger* next = NULL;		// -- the pointer of next exchanger
	int* perms[EXCHANGER_GROUPS_COUNT][EXCHANGER_GROUPS_SIZE];	// -- numbers to permutate

	Exchanger(int* perms[EXCHANGER_GROUPS_COUNT][EXCHANGER_GROUPS_SIZE]);
	static void exchange(int *n1, int *n2);
	void exchange_members();
	void exchange_groups();
	void try_activate_next();
	void change2next();
};