#include "stdafx.h"

int main() {
	UnitMaps unitmaps;
	int figure = -1, i = 0xffff, j = 0xffff;

	/*
	unitmaps.fill_in(9, 1, 0);
	unitmaps.fill_in(9, 2, 3);
	unitmaps.fill_in(9, 3, 6);
	unitmaps.fill_in(9, 6, 7);
	unitmaps.get_decisive(figure, i, j);
	unitmaps.show();

	cout << "figure: " << figure << endl;
	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	*/


	/*unitmaps.clear();
	unitmaps.fill_in(1, 2, 0);
	unitmaps.fill_in(1, 4, 4);
	unitmaps.fill_in(1, 3, 6);
	unitmaps.fill_in(2, 0, 3);
	unitmaps.fill_in(3, 0, 5);
	unitmaps.fill_in(5, 0, 7);
	*/
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
	for (int rep = 0; rep < 1000; rep++) {
		unitmaps.read_matrix(mat);
		//unitmaps.show();
		//unitmaps.row_maps[0].display_pos(1);
		//unitmaps.row_maps[0].display_pos(6);

		int step = 0;
		while (bool found = unitmaps.get_decisive(figure, i, j)) {
			unitmaps.fill_in(figure, i, j);
			//cout << "step: " << ++step << endl;
			//cout << "figure: " << figure;
			//cout << " i: " << i;
			//cout << " j: " << j << endl;
			//unitmaps.show();
		}
		//cout << "solve quit" << endl;
		//unitmaps.show();
	}
	unitmaps.show();
	getchar();
	return 0;
}