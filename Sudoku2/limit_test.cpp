#include "stdafx.h"

int main_limit_test() {
	UnitMaps unitmaps;
	int figure = -1, i = 0xffff, j = 0xffff;

	int mat[SIZE*SIZE] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0,

		0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,

		0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	unitmaps.read_matrix(mat);
	unitmaps.group_maps[2].display_limit(1);
	cout << endl;
	unitmaps.hole(1, 0);
	unitmaps.show();
	unitmaps.group_maps[2].display_limit(1);
	cout << endl;
	cout << endl;
	unitmaps.hole(2, 3);
	unitmaps.show();
	unitmaps.group_maps[2].display_limit(1);
	unitmaps.row_maps[2].display_limit(1);
	cout << endl;
	getchar();
	return 0;
}