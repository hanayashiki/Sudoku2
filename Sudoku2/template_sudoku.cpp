#include "stdafx.h"

bool Template_sudoku::change2next() {
	if (!next_permutation(code.begin() + 1, code.end())) {
		templet->change2next();
		sort(code.begin() + 1, code.end());
	}
	return true;
}

void Template_sudoku::record(FILE* fout, int* index, char buffer[]) {
	int counter;

	for (int i = 0; i < 8; i += 3) { // each big line
		for (int j = 0; j < 3; j++) { // each small line
			counter = 0;
			for (int k = 0; k < 3; k++) { // each block
				for (char &c : templet->line[i + k][j]) {
					if ((*index) >= BUFFER_SIZE - 5) {
						buffer[(*index)] = '\0';
						fputs(buffer, fout);
						(*index) = 0;
					}
					buffer[(*index)++] = code[c - '0'];
					buffer[(*index)++] = (counter++ < 8) ? ' ' : '\n';
				}
			}
		}
	}
}

void Template_sudoku::create_from_template(vector<int> & sudoku) {
	int counter = 0;

	for (int i = 0; i < 8; i += 3) { // each big line
		for (int j = 0; j < 3; j++) { // each small line
			for (int k = 0; k < 3; k++) { // each block
				for (char &c : templet->line[i + k][j]) {
					sudoku.push_back(code[c - '0'] - '0');
				}
			}
		}
	}
}

