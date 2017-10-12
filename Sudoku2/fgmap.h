// copyright Wang Chenyu, Liu Chang 2017
// ����ļ��ж����� FgMap���� figure-grid map
// ����������������¼ һ�� �� �� �� �� �� �����Ϊ��Ԫ�� �У����� 1-9 ��λ�� 1-9 �����п���ӳ��
// �Ӷ����������� f �� [1-9] ʹ��ӳ��Ψһȷ��ʱ �� �������һ�����ֵ�λ�õ��Ƶ�

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
	int map[SIZE] = { 0 };  // map[i] �� �� j �� bit Ϊ 1 ��ʾ���� i+1 ������� j ����
	int limit[SIZE][SIZE] = { 0 };  // limit[i][j] ��ʾ���� i + 1 �� index Ϊ j �ĵط��ܵ�Լ��������
	int pos_count[SIZE] = { 0 };   // pos_count[i] ��¼�� map[i] �����ж��ٸ� bit �� 1.

public:
	int type = -1;  // ���л����л��ǹ��е�����-λ��ӳ��
	int id;  // �У����л򹬵���ţ������Ҵ��ϵ����� 0 ������
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