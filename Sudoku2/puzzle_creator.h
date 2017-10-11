#pragma once

#include <iostream>
#define SIZE 9

using namespace std;

int get_difficulty_puzzle(int sudoku[SIZE * SIZE], int puzzle[SIZE * SIZE], int difficulty);
int get_unique_solution_puzzle(int sudoku[SIZE * SIZE], int puzzle[SIZE * SIZE],
	int min_freebox_num, int max_freebox_num);
void clean_each_block_grids(int clean_count, int puzzle[SIZE * SIZE]);
int get_puzzle(int sudoku[SIZE * SIZE], int puzzle[SIZE * SIZE], 
	int min_freebox_num, int max_freebox_num);
void set_number_randomly(int sudoku[SIZE * SIZE]);
bool create_final_sudoku(int sudoku[SIZE * SIZE]);
int create_puzzle(int puzzle[SIZE * SIZE],
	int min_freebox_num, int max_freebox_num);