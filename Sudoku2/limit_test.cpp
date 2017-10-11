#include "stdafx.h"

int main() {
	UnitMaps unitmaps;
	int figure = -1, i = 0xffff, j = 0xffff;
	constraint constr[SIZE];
	int constr_count = -1;
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
	
	getchar();
	return 0;
}