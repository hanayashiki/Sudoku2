#include "stdafx.h"

int solution_count = 0;

bool guess_value(Box* box, Subject_sudoku* sudoku, int solution[SIZE * SIZE], bool unique) {
	//cout << "guess" << endl;
	int rowno = box->row->number;
	int columnno = box->column->number;
	for (int i = 0; i < SIZE; i++) {
		if (box->posvalue & get_valuebit(i)) { // -- value i+1 is possible
											   //Subject_sudoku* new_sudoku = new Subject_sudoku(*sudoku);
			Box* box = sudoku->getbox(rowno, columnno);
			int members_posvalues[3][9];
			int posvalue = box->make_certain(i + 1, members_posvalues);
			if (fill_sudoku(sudoku, solution, unique)) {
				return true;
			}
			//delete(new_sudoku);
			box->cancel_certain(posvalue, members_posvalues);
		}
	}
	return false;
}

bool fill_sudoku(Subject_sudoku* sudoku, int solution[SIZE * SIZE], bool unique){ // -- succeed(true) or failed(false)
	Box* box;
	box = sudoku->get_minpos_box();
	//cout << sudoku->to_string() << endl;
	if (box == NULL) {
		sudoku->to_array(solution);
		if (unique == false) {
			return true;
		}
		else {
			display_1d(solution, 81, 9);
			solution_count++;
			return false;
		}
	}
	return guess_value(box, sudoku, solution, unique);
}

bool solve_sudoku(int puzzle[SIZE * SIZE], int solution[SIZE * SIZE]) {
	Subject_sudoku* sudoku;
	sudoku = new Subject_sudoku(puzzle);
	if (!fill_sudoku(sudoku, solution, false)) {
		return false;
	};
	delete(sudoku);
	return true;
}

int unique_test(int puzzle[SIZE * SIZE], int solution[SIZE * SIZE]) {
	solution_count = 0;
	Subject_sudoku* sudoku;
	sudoku = new Subject_sudoku(puzzle);
	fill_sudoku(sudoku, solution, true);
	delete(sudoku);
	return solution_count;
}


int main3() {
	int mat_input[SIZE*SIZE] =
	{
		1, 2, 3, 0, 0, 0, 0, 0, 0,
		4, 5, 6, 0, 0, 0, 0, 0, 0,
		7, 8, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	int solution[SIZE*SIZE] = { 0 };
	bool result = solve_sudoku(mat_input, solution);
	cout << result << endl;
	cout << solution << endl;
	getchar();
	return 0;
}