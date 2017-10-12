#pragma once
#include "stdafx.h"

#define EXCHANGER_GROUPS_SIZE 3		// -- �Լ������ֽ���ȫ����
#define EXCHANGER_GROUPS_COUNT 3	// -- �м���������Ҫ����
#define MAX_EXCHANGE_COUNT 6		// -- һ����Ҫ������Ա����

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