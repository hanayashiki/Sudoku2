// copyright Wang Chenyu, Liu Chang 2017
// 这个文件中定义类 FgMap，即 figure-grid map
// 基本功能是用来记录 一个 行 或 列 或 宫 （简称为单元） 中，数字 1-9 到位置 1-9 的所有可能映射
// 从而当存在数字 f ∈ [1-9] 使得映射唯一确认时 ， 可以完成一个数字的位置的推导

#pragma once
#include "stdafx.h"
#define ROW 1
#define COLUMN 2
#define GROUP 3

#define F2INDEX(f) ((f)-1)
#define INDEX2MASK(I) (~(1 << (I)))
#define INDEX2TARGETBIT(I) (1 << (I))

#define SAMEGROUP(x,y,i,j) (((x)/3 == (i)/3) && ((y)/3 == (j)/3))

class UnitMaps;

class FgMap {
private:
	int map[SIZE] = { 0 };  // map[i] 的 第 j 个 bit 为 1 表示数字 i+1 能填入第 j 个空
	int limit[SIZE][SIZE] = { 0 };  // limit[i][j] 表示数字 i + 1 在 index 为 j 的地方受到约束的数量
	int pos_count[SIZE] = { 0 };   // pos_count[i] 记录了 map[i] 里面有多少个 bit 是 1.

public:
	int type = -1;  // 是行还是列还是宫中的数字-位置映射
	int id;  // 行，或列或宫的序号，从左到右从上到下自 0 递增。
	UnitMaps * Upper;

	FgMap();
	void clear();
	FgMap(int t, int id);

	bool inside_lock(int figure, int place, bool unlock = false);
	bool lock(int figure_x, int index, bool unlock = false);
	bool outside_lock(int figure, int i, int j, bool unlock = false);

	bool get_decisive(int & figure, int & i, int & j) const;
	bool get_decisive_none_zero(int & figure, int & i, int & j) const;

	bool index2co(int index, int & i, int & j) const;

	bool co2index(int & index, int i, int j) const;
	
	void display_pos(int figure) const {
		int v = map[F2INDEX(figure)];
		cout << "possible poses for figure " << figure << ": (1-indexed)" << endl;
		for (int i = 0; i < 32; i++, v = (v >> 1)) {
			if (v & 0x1) {
				cout <<  (i+1) << " ";
			}
		}
		cout << endl;
	}

	bool inside_unlock(int figure, int place) {
		return inside_lock(figure, place, true);
	}
	bool outside_unlock(int figure, int i, int j) {
		return outside_lock(figure, i, j, true);
	}

	void display_limit(int figure) {
		switch (type) {
		case ROW:
			display_1d(limit[F2INDEX(figure)], 9);
			break;
		case COLUMN:
			display_1d(limit[F2INDEX(figure)], 9);
			break;
		case GROUP:
			display_1d(limit[F2INDEX(figure)], 9, 3);
			break;
		default:
			assert(0);
		}
	}

};