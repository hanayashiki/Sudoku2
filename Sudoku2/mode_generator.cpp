#include "stdafx.h"
#include "mode_generatror.h"

bool generator_guess_value(Box* box, Subject_sudoku* sudoku, int &solution_counter) {
	int rowno = box->row->number;
	int columnno = box->column->number;
	for (int i = 0; i < SIZE; i++) {
		if (box->posvalue & get_valuebit(i)) { // -- value i+1 is possible
			Box* box = sudoku->getbox(rowno, columnno);
			int members_posvalues[3][9];
			int posvalue = box->make_certain(i + 1, members_posvalues);
			if (!generator_fill_sudoku(sudoku, solution_counter)) {
				return false;
			}
			box->cancel_certain(posvalue, members_posvalues);
		}
	}
	return true;
}

bool generator_fill_sudoku(Subject_sudoku* sudoku, int &solution_counter) { 
	/* -- succeed(true) or failed(false) */
	Box* box;
	//cout << sudoku->to_string() << endl;
	box = sudoku->get_minpos_box();
	if (box == NULL) {
		solution_counter++;
		if (solution_counter > SOLUTION_MAX) {
			return false;
		}
		return true;
	}
	return generator_guess_value(box, sudoku, solution_counter);
}

bool generator_solve_sudoku(int puzzle[SIZE * SIZE])
{
	Subject_sudoku* sudoku;
	sudoku = new Subject_sudoku(puzzle);
	int solution_counter = 0;
	bool result = generator_fill_sudoku(sudoku, solution_counter);
	delete(sudoku);
	return result;
}

/*int main() {
	int puzzle[SIZE * SIZE] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0
		0
	};

	int targets[4] = { 36, 40, 5, 10 };
	int puzzle_template[SIZE * SIZE] = { 0 };

	cout << generator_solve_sudoku(puzzle, targets, puzzle_template) << endl;
	
	getchar();
}*/


