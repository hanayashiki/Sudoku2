#include "stdafx.h"
#define HOLE_I 0
#define HOLE_J 0
#define REPEAT 100

int main_dig() {
	int mat[SIZE*SIZE] = {
		6,7,5,8,9,1,4,3,2,
		4,9,2,6,7,3,1,8,5,
		1,8,3,4,5,2,7,9,6,
		3,6,4,5,8,7,2,1,9,
		7,1,8,2,3,9,5,6,4,
		2,5,9,1,6,4,3,7,8,
		8,3,7,9,4,5,6,2,1,
		9,4,1,7,2,6,8,5,3,
		5,2,6,3,1,8,9,4,7
	};
	int out[SIZE*SIZE] = { 0 };

	for (int rep = 0; rep < REPEAT; rep++) {
		cout << dig(mat, out, 55);
	}
	//display_1d(out, SIZE*SIZE, 9);
	getchar();
	return 0;
}

int dig(int mat[SIZE*SIZE], int out[SIZE*SIZE], int dig_tg) {
	UnitMaps unitmaps;
	unitmaps.read_matrix(mat);
	try_dig(unitmaps, HOLE_I, HOLE_J, 0 , dig_tg, out);
	//unitmaps.show();
	return unitmaps.blank;
}

bool try_dig(UnitMaps & unitmaps, int dig_x, int dig_y, int dig_count, int dig_tg, int out[SIZE*SIZE]) {
	//cout << "dug: " << dig_count << endl;
	if (dig_tg == dig_count) {
		return true;
	}
	else {
		int decisive_figure, x, y;
		unitmaps.hole(dig_x, dig_y);
		//unitmaps.show();
		if (unitmaps.get_decisive_none_zero(decisive_figure, x, y)) {
			return try_dig(unitmaps, x, y, dig_count + 1, dig_tg, out);
		}
	}
	//cout << "failure" << endl;
	unitmaps.dump_matrix2arr(out);
	return false;
}