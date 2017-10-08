#include "stdafx.h"

int main() {
	UnitMaps unitmaps;
	int figure = -1, i = -1, j = -1;

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


	unitmaps.clear();
	unitmaps.fill_in(1, 2, 0);
	unitmaps.fill_in(1, 4, 4);
	unitmaps.fill_in(1, 3, 6);
	unitmaps.fill_in(2, 0, 3);
	unitmaps.fill_in(3, 0, 5);
	unitmaps.fill_in(5, 0, 7);
	bool found = unitmaps.get_decisive(figure, i, j);
	unitmaps.show();

	cout << "found: " << found << endl;
	cout << "figure: " << figure << endl;
	cout << "i: " << i << endl;
	cout << "j: " << j << endl;

	unitmaps.row_maps[0].display_pos(1);
	unitmaps.row_maps[0].display_pos(9);

	getchar();
	return 0;
}