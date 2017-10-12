#pragma once
#include "stdafx.h"

/* for creating the initial sudoku */
#define BASE_LINE {1,2,3}			// -- ���������Ļ������ɵ�λ
#define POSITION_SEED {0,1,2}		// -- �������ַ�˳�����line���������λ��

/* for creating Exchangers */
#define EXCHANGER_COUNT 6			// -- ���м���Exchanger
#define ORIGIN 3					// -- �ӵڼ��С��п�ʼ����

void roll_int(int i_array[], int len);
void fill_line_to_sudoku(int* grid, int line[BLOCK_SIZE]);
void initial_sudoku(int sudoku[SIZE][SIZE]);
void initial_exchanger(Exchanger* exchangers[], int sudoku[SIZE][SIZE]);
void output_sudoku(int sudoku[SIZE][SIZE], int result[SIZE*SIZE]);
void create_sudokus(int number, int result[][SIZE*SIZE]);