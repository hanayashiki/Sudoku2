#include "stdafx.h"

int main_ct() {
	UnitMaps unitmaps;
	int figure = -1, i = 0xffff, j = 0xffff;
	int constr_count = -1;
	int mat[SIZE*SIZE] =
	{
		6,7,5,8,9,1,4,3,0,
		4,9,2,6,7,3,1,8,5,
		1,8,3,4,5,2,7,9,6,
		3,6,4,5,8,7,2,1,9,
		7,1,8,2,3,9,5,6,4,
		2,5,9,1,6,4,3,7,8,
		8,3,7,9,4,5,6,2,1,
		9,4,1,7,2,6,8,5,3,
		5,2,6,3,1,8,9,4,7
	};
	unitmaps.read_matrix(mat);

	getchar();
	return 0;
}