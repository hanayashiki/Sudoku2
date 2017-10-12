// copyright Wang Chenyu, Liu Chang 2017
// 前置文件：fgmap.h/cpp
// 统一存储管理各个单元。存入数独，建立各个单元的映射记录类 FgMap，
// 实现填入和挖空时的 FgMap 同步更新

#pragma once
#include "stdafx.h"
#define GET_GROUP_ID(i,j) (3*((i)/3)+(j)/3)
#define GET_GROUP_X(i) ((i) % 3)
#define GET_GROUP_Y(j) ((j) % 3)
#define GET_GROUP_INDEX(i, j) (3*GET_GROUP_X(i) + GET_GROUP_Y(j))

#define RELEVANT 4

class UnitMaps {
private:

	int group_id2relevant_groups[9][4] =
	{
		1, 2, 3, 6,
		0, 2, 4, 7,
		0, 1, 5, 8,
		0, 4, 5, 6,
		1, 3, 5, 7,
		2, 3, 4, 8,
		0, 3, 7, 8,
		1, 4, 6, 8,
		2, 5, 6, 7
	};
	// 第 i 行表示如果在第 i 个宫填入一个数，
	// 那么受到影响的其他宫的集合，
	// 显然如果在 左上角的 0 号宫填入了一个数，
	// 横着和竖着的都会受到影响.

public:
	int matrix[SIZE][SIZE] = { 0 };
	int blank = SIZE*SIZE;
	FgMap row_maps[9];
	FgMap column_maps[9];
	FgMap group_maps[9];

	// 上次被挖掉的数的约束项

	UnitMaps();
	bool fill_in(int figure, int i, int j);  // 填入数字，更新 FgMap
	int hole(int i, int j);  // 挖去空格
	bool get_decisive(int & figure, int & i, int & j);  // 推导必然填入
	bool get_decisive_none_zero(int & figure, int & i, int & j);  // 推导必然填入

	void show() {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << matrix[i][j];
				cout << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	void clear();

	void read_matrix(int mat[SIZE * SIZE]) {
		clear();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (mat[9 * i + j] != 0) {
					fill_in(mat[9 * i + j], i, j);
				}
			}
		}
	}

	void dump_matrix2arr(int mat_out[SIZE*SIZE]) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				// cout << matrix[i][j];
				mat_out[9 * i + j] = matrix[i][j];
			}
		}
	}

};