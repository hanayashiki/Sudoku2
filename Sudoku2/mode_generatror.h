#pragma once

#include "stdafx.h"
#define SOLUTION_MAX 1

bool generator_guess_value(Box* box, Subject_sudoku* sudoku, int &solution_counter);
bool generator_fill_sudoku(Subject_sudoku* sudoku, int &solution_counter);
bool generator_solve_sudoku(int puzzle[SIZE * SIZE]);