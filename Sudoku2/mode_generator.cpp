#include "stdafx.h"
#include "mode_generatror.h"

int guess = 0;

bool generator_guess_value(Box* box, Subject_sudoku* sudoku, int &solution_counter, int targets[4], int puzzle_template[SIZE*SIZE]) {
	//cout << "guess" << endl;
	int rowno = box->row->number;
	int columnno = box->column->number;
	for (int i = 0; i < SIZE; i++) {
		if (box->posvalue & get_valuebit(i)) { // -- value i+1 is possible
											   //Subject_sudoku* new_sudoku = new Subject_sudoku(*sudoku);
			Box* box = sudoku->getbox(rowno, columnno);
			int son_solution_counter = 0;
			int members_posvalues[3][9];
			int posvalue = box->make_certain(i + 1, members_posvalues);
			guess++;
			if (generator_fill_sudoku(sudoku, son_solution_counter, targets, puzzle_template)) {
				return true;
			}
			if (guess % 10000 == 0 && (sudoku->zeroes >= targets[MIN_ZERO_COUNT]) && (sudoku->zeroes <= targets[MAX_ZERO_COUNT])) cout << guess << "; " << sudoku->zeroes << "; " <<son_solution_counter  << endl;
			solution_counter += son_solution_counter;
			if ((sudoku->zeroes >= targets[MIN_ZERO_COUNT]) && (sudoku->zeroes <= targets[MAX_ZERO_COUNT])) {
				if ((son_solution_counter >= targets[MIN_SOLUTION_COUNT]) && (son_solution_counter <= targets[MAX_SOLUTION_COUNT])) {
					sudoku->to_array(puzzle_template);
					return true;
				}
			}
			//delete(new_sudoku);
			box->cancel_certain(posvalue, members_posvalues);
		}
	}
	return false;
}

bool generator_fill_sudoku(Subject_sudoku* sudoku, int &solution_counter, 
	int targets[4], int puzzle_template[SIZE*SIZE]) { 
	/* -- succeed(true) or failed(false) */

	Box* box;
	box = sudoku->get_minpos_box();
	//cout << sudoku->to_string() << endl;
	if (box == NULL) {
		solution_counter++;
		return false;
	}
	return generator_guess_value(box, sudoku, solution_counter, targets, puzzle_template);
}

bool generator_solve_sudoku(int puzzle[SIZE * SIZE], int targets[4], int puzzle_template[81])
{
	Subject_sudoku* sudoku;
	sudoku = new Subject_sudoku(puzzle);
	int solution_counter = 0;

	if (!generator_fill_sudoku(sudoku, solution_counter, targets, puzzle_template)) {
		return false;
	};
	delete(sudoku);
	return true;
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

