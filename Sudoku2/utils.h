#pragma once
#include "stdafx.h"
#define FLAT(i, j)  (SIZE*(i)+(j))

int get_valuebit(Box* member);

int get_valuebit(int value);

int count_one(int value);

int get_one(int vect);

void display_2d(int** two_d, int m, int n);

void display_1d(int* two_d, int m, int cluster = 0);

bool read_file(FILE* f, int sudoku[SIZE*SIZE]);