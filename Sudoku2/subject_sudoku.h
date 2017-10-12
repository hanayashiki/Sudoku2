#pragma once
#include "stdafx.h"

class Group;
class Box;

class Subject_sudoku {
public:
	Group* rows[9];
	Group* columns[9];
	Group* blocks[9];

	Subject_sudoku(string sudoku_str);
	Subject_sudoku(const Subject_sudoku& sudoku);
	Subject_sudoku(int sudoku[SIZE * SIZE]);
	~Subject_sudoku();
	Box* getbox(int rowno, int columnno) const;
	Box* get_minpos_box() const;
	void initial();
	void show(FILE* fout);
	string to_string();
	void to_array(int sudoku_array[SIZE * SIZE]);

	int zeroes;
};