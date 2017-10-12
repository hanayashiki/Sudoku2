#include "stdafx.h"

int main_fgmap_test() {
	UnitMaps unitmaps;
	int figure, i, j;
	int mat[SIZE*SIZE] =
	{
		1, 0, 0, 3, 0, 0, 0, 0, 5,
		0, 4, 0, 0, 0 ,6, 8, 0, 0,
		0, 6, 8, 7, 0, 0, 0, 0, 0,

		2, 0, 0, 9, 5, 0, 0, 0, 0,
		0, 1, 0, 0, 6, 0, 0, 7, 0,
		0, 0, 0, 0, 8, 7, 0, 0 ,6,

		0, 0, 0, 0, 0, 9, 6, 1, 7,
		0, 0, 7, 2, 0, 0, 0, 3, 0,
		3, 0, 0, 0, 0, 5, 0, 0, 8
	};
	for (int rep = 0; rep < 50000; rep++) {
		cout << "rep:" << rep << endl;
		unitmaps.read_matrix(mat);
		int step = 0;
		while (unitmaps.blank != 0) {
			unitmaps.get_decisive(figure, i, j);
			unitmaps.fill_in(figure, i, j);
			step++;
		}
		unitmaps.show();
	}
	return 0;
}