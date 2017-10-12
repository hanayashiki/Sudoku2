#pragma once
#include "stdafx.h"

bool guess_value(Box* box, Subject_sudoku* sudoku, int solution[SIZE * SIZE], bool unique = false);

bool fill_sudoku(Subject_sudoku* sudoku, int solution[SIZE * SIZE], bool unique = false);

bool solve_sudoku(int puzzle[SIZE * SIZE], int solution[SIZE * SIZE]);

int unique_test(int puzzle[SIZE * SIZE], int solution[SIZE * SIZE]);