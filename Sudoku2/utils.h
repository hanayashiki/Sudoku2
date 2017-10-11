#pragma once
#include "stdafx.h"
int get_valuebit(Box* member);

int get_valuebit(int value);

int count_one(int value);

int get_one(int vect);

void show_constrs(constraint c[], int num);

void display_2d(int** two_d, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << two_d[m][n] << " ";
		}
		cout << endl;
	}
}