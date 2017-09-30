#pragma once

#include "stdafx.h"
#define MIN_ZERO_COUNT 0
#define MAX_ZERO_COUNT 1
#define MIN_SOLUTION_COUNT 2
#define MAX_SOLUTION_COUNT 3
#define EASY {31, 35, 11, 20}
#define MID {36, 40, 5, 10}
#define HARD {41, 50, 1, 4}

bool generator_guess_value(Box* box, Subject_sudoku* sudoku, int &solution_counter, int targets[4], int puzzle_template[SIZE*SIZE]);
bool generator_fill_sudoku(Subject_sudoku* sudoku, int &solution_counter, 
	int targets[4], int puzzle_template[SIZE*SIZE]);
bool generator_solve_sudoku(int puzzle[SIZE * SIZE], int targets[4], int puzzle_template[81]);