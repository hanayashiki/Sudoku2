#include "stdafx.h"
/*
int create_sudoku(int number) {
	Template_sudoku* tsudo = new Template_sudoku();
	int counter = 0;
	FILE* fout;
	fopen_s(&fout, "sudoku.txt", "w");
	int index = 0;
	char buffer[BUFFER_SIZE];
	tsudo->record(fout, &index, buffer);
	while (tsudo->change2next() && ++counter < number) {
		buffer[index++] = '\n';
		tsudo->record(fout, &index, buffer);
	}
	buffer[index] = '\0';
	fputs(buffer, fout);

	fclose(fout);
	return 0;
}
*/

vector<vector<int>>* create_sudokus(int number) {
	Template_sudoku templ = Template_sudoku();
	vector<vector<int>>* sudokus = new vector<vector<int>>(number);
	//sudokus.resize(number);
	
	for (int count = 0; count < number; count++) {
		//vector<int> & sudoku = sudokus[count];
		vector<int> sudoku(sudokus->at(count));
		sudoku.reserve(BOX_COUNT);
		templ.create_from_template(sudoku);
	}
	return sudokus;
}

int main() {
	vector<vector<int>>* mat = create_sudokus(1000);
	getchar();
	return 0;
}

vector<int> test_vector() {
	vector<int> v = { 0,1,2,3,4 };
	return v;
}