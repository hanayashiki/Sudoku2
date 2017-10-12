#include "stdafx.h"

int main() {
	FILE* r;
	int mat[SIZE*SIZE] = 
	{   0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		1,8,3,4,5,2,7,9,6,
		3,6,4,5,8,7,2,1,9,
		7,1,8,2,3,9,5,6,4,
		2,5,9,1,6,4,3,7,8,
		8,3,7,9,4,5,6,2,1,
		9,4,1,7,2,6,8,5,3,
		5,2,6,3,1,8,9,4,7 };
	int unique = unique_test(mat, mat);
	cout << "count: " << unique << endl;
	fopen_s(&r, "C:\\Users\\sandy2008\\Desktop\\ศํนค\\pair prgm\\sudoku2_new_repo\\Sudoku2\\Sudoku2Test\\sudoku.txt",
		"r");
	if (r == NULL) {
		cout << "Cannot open test file." << endl;
	}
	while (read_file(r, mat)) {
		int blank = dig(mat, mat, 55);
		//Assert::AreEqual(unique_test(mat, mat), 1);
		int unique = unique_test(mat, mat);
		cout << "count: " << unique << endl;
		cout << "blank: " << blank << endl;
		assert(unique == 1);
	}
	fclose(r);
	return 0;
}