#include "stdafx.h"

FgMap::FgMap(int unit_type, int unit_id) {
	id = unit_id;
	type = unit_type;
	clear();
}

FgMap::FgMap() {
	id = 0;
	type = 0;
	clear();
}

void FgMap::clear() {
	for (int index = 0; index < SIZE; index++) {
		map[index] = 0x1FF;
		pos_count[index] = 9;
		for (int place_index = 0; place_index < SIZE; place_index++) {
			limit[index][place_index] = 0;
		}
	}
}



bool FgMap::inside_lock(int figure, int index, bool unlock) {
	// 在单元中位置为index(zero indexed)填入一个了数，
	// 扼杀了这个数字的所有可能性以及其他数的填入位置的可能性。
	int pos_x, pos_y;
	map[F2INDEX(figure)] &= 0;
	pos_count[F2INDEX(figure)] = 0;

	//cout << "inside_lock: " << endl;
	index2co(index, pos_x, pos_y);
	for (int figure_x = 1; figure_x <= 9; figure_x++) {
		//cout << "inside lock :" << endl;
		if (lock(figure_x, index, unlock)) {
			constr[F2INDEX(figure_x)].add_constr(figure, pos_x, pos_y);
		}
	}

	return true;
}

bool FgMap::outside_lock(int figure, int i, int j, bool unlock) {
	// 外界在数独下标为 (i,j) (zero-indexed) 的位置填入了一个数
	// 就使得一个单元中，对应的数字不能与之发生冲突，从而减少了某些可能性
	for (int _index = 0; _index < 9; _index++) {
		int x, y;
		//assert(index < 9);
		index2co(_index, x, y);
		if (SAMEGROUP(x, y, i, j) || (x == i) || (y == j)) {
			//cout << "outside lock, figure: " << figure << endl;
			//cout << "outside lock :" << endl;
			if (lock(figure, _index, unlock)) {
				constr[F2INDEX(figure)].add_constr(figure, i, j);
			}
		}
	}

	return true;
}

bool FgMap::lock(int figure_x, int index, bool unlock) {
	if (unlock == false) {
		if (map[F2INDEX(figure_x)] & INDEX2TARGETBIT(index)) {
			/*if (figure_x == 1) {
				cout << "	locked. figure_x: " << figure_x << endl;
				cout << "	id: " << id << endl;
				cout << "	type: " << type << endl;
				cout << "	index: " << index << endl;
				cout << endl;
			}*/

			//  假如原来有这个可能性
			pos_count[F2INDEX(figure_x)]--;
			assert(pos_count[F2INDEX(figure_x)] > 0);
			map[F2INDEX(figure_x)] &= INDEX2MASK(index);
			assert(map[F2INDEX(figure_x)] != 0);
		}
		limit[F2INDEX(figure_x)][index] ++;
		if ((id == 2) && (type == GROUP)) {
			cout << "figure_x: " << figure_x << "; " << "index: " << index << endl;
			cout << "limit: " << limit[F2INDEX(figure_x)][index] << endl;
			display_limit(1);
		}
		return true;
	}
	else {
		if ((~map[F2INDEX(figure_x)]) & INDEX2TARGETBIT(index)) {
			/*if (figure_x == 1) {
			cout << "	locked. figure_x: " << figure_x << endl;
			cout << "	id: " << id << endl;
			cout << "	type: " << type << endl;
			cout << "	index: " << index << endl;
			cout << endl;
			}*/

			//  假如原来这个可能性已经被删除了，意味着取反以后这个位置为 1
			limit[F2INDEX(figure_x)][index] --;
			assert(limit[F2INDEX(figure_x)][index] >= 0);
			if (limit[F2INDEX(figure_x)][index] == 0) {
				pos_count[F2INDEX(figure_x)]++;
				map[F2INDEX(figure_x)] |= INDEX2TARGETBIT(index);
			}
			if ((id == 2) && (type == GROUP)) {
				cout << "figure_x: " << figure_x << "; " << "index: " << index << endl;
				cout << "limit: " << limit[F2INDEX(figure_x)][index] << endl;
				display_limit(1);
			}
		}
		return true;
	}
	return false;
}

bool FgMap::get_decisive(int & figure, int &i, int &j) const{
	//cout << "type: " << type << endl;
	//cout << "min_map: " << min_map << endl;
	int min_index = 0;
	int min_count = INT32_MAX;
	for (int fig_index = 0; fig_index < SIZE; fig_index++) {
		if (pos_count[fig_index] != 0 && (pos_count[fig_index] < min_count)) {
			min_index = fig_index;
			min_count = pos_count[fig_index];
		}
	}
	if (min_count == 1) {
		figure = min_index + 1;
		index2co(get_one(map[min_index]), i, j);
		//cout << "decisive: " << "figure " << figure << "("
		//	<< i << "," << j << ")" << "index: " << min_index << endl;
	}
	return min_count == 1;
}

void FgMap::dump_constr(constraint tg[], int & num, int fig) {
	constr[F2INDEX(fig)].dump_constr(tg, num);
}

bool FgMap::index2co(int index, int & i, int & j) const{

	assert(index < 9);
	// 将单元内部的序号转化为数独矩阵坐标
	int base_x, base_y;
	switch (type) {
	case ROW:
		i = id;
		j = index;
		break;
	case COLUMN:
		i = index;
		j = id;
		break;
	case GROUP:
		base_x = (id / 3) * 3;
		base_y = (id % 3) * 3;
		i = base_x + index / 3;
		j = base_y + index % 3;
		
		break;
	default:
		return false;
	}
	assert(i <= 8);
	assert(j <= 8);
	return true;
}

bool FgMap::co2index(int & index, int i, int j) const {
	assert(index < 9);
	// 将数独矩阵坐标转化为单元内部的序号
	switch (type) {
	case ROW:
		index = j;
		break;
	case COLUMN:
		index = i;
		break;
	case GROUP:
		index = 3 * (i % 3) + (j % 3);
		break;
	default:
		return false;
	}
	assert(i <= 8);
	assert(j <= 8);
	return true;
}


