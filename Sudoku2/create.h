#pragma once
#include "stdafx.h"

/* for creating the initial sudoku */
#define BASE_LINE {1,2,3}			// -- 生成数独的基本构成单位
#define POSITION_SEED {0,1,2}		// -- 根据其字符顺序决定line依次填入的位置

/* for creating Exchangers */
#define EXCHANGER_COUNT 6			// -- 共有几个Exchanger
#define ORIGIN 3					// -- 从第几行、列开始生成

void roll_int(int i_array[], int len);
void fill_line_to_sudoku(int* grid, int line[BLOCK_SIZE]);
void initial_sudoku(int sudoku[SIZE][SIZE]);
void initial_exchanger(Exchanger* exchangers[], int sudoku[SIZE][SIZE]);
void output_sudoku(int sudoku[SIZE][SIZE], int result[SIZE*SIZE]);
void create_sudokus(int number, int result[][SIZE*SIZE]);