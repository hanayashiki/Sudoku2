// copyright Wang Chenyu, Liu Chang 2017

// TODO: 想出一种数据结构，来记录一个格子的所有约束
// 约束 (figure, x, y) 是一个三元组

// 加快检索速度，可以用数字表头的链表群

#pragma once
#include "stdafx.h"

using std::list;

struct constraint {
	int figure;
	int x;
	int y;
};

typedef list<constraint> linked;

class ConstraintTable {
private:
	linked linked_constr[SIZE];
	// 链表群，其中下标 i 中的元素都是，代表的数字都是 i + 1
public:
	bool add_constr(int fig, int x, int y);
	bool del_constr(int fig, int x, int y);
	void dump_constr(constraint constr[], int & num);
};