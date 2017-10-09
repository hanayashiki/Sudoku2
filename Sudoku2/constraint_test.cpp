#include "stdafx.h"

int main_ct() {
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
	unitmaps.get_constraints(constr, constr_count, 1, 2, GROUP);
	show_constrs(constr, constr_count);
	getchar();
	return 0;
}