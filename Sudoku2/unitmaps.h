// copyright Wang Chenyu, Liu Chang 2017
// ǰ���ļ���fgmap.h/cpp
// ͳһ�洢���������Ԫ����������������������Ԫ��ӳ���¼�� FgMap��
// ʵ��������ڿ�ʱ�� FgMap ͬ������

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
	// �� i �б�ʾ����ڵ� i ��������һ������
	// ��ô�ܵ�Ӱ����������ļ��ϣ�
	// ��Ȼ����� ���Ͻǵ� 0 �Ź�������һ������
	// ���ź����ŵĶ����ܵ�Ӱ��.

public:
	int matrix[SIZE][SIZE] = { 0 };
	int blank = SIZE*SIZE;
	FgMap row_maps[9];
	FgMap column_maps[9];
	FgMap group_maps[9];

	// �ϴα��ڵ�������Լ����

	UnitMaps();
	bool fill_in(int figure, int i, int j);  // �������֣����� FgMap
	int hole(int i, int j);  // ��ȥ�ո�
	bool get_decisive(int & figure, int & i, int & j);  // �Ƶ���Ȼ����
	bool get_decisive_none_zero(int & figure, int & i, int & j);  // �Ƶ���Ȼ����

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