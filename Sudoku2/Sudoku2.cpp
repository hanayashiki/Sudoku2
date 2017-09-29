// Sudoku2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int solve_sudoku(FILE* subject);
bool fill_sudoku(Subject_sudoku* sudoku, FILE* fout);
int create_sudoku(int number);
bool guess_value(Box* box, Subject_sudoku* sudoku, FILE* fout);


int main2(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "invalid parameter number";
		return 0; // over
	}

	char* func = argv[1];
	char* para = argv[2];
	if (strcmp(func, "-c") == 0) {
		int number = 0;
		char c;
		for (int i = 0; (c = para[i]) != '\0'; i++) {
			if (isdigit(c)) {
				number *= 10;
				number += c - '0';
				if (number > 1'000'000) {
					cout << "the number is out of range";
					return 0;
				}
			}
			else {
				cout << "invalid number";
				return 0;
			}
		}
		if (number <= 0) {
			cout << "number should be positive";
			return 0;
		}
		create_sudoku(number);
	}
	else if (strcmp(func, "-s") == 0) {
		FILE* subject;
		fopen_s(&subject, para, "r");
		if (subject) {
			solve_sudoku(subject);
			fclose(subject);
		}
		else {
			cout << "cannot open the file";
			return 0;
		}
	}
	else {
		cout << "unknown function";
		return 0;
	}
}

int solve_sudoku(FILE* subject) {
	Subject_sudoku* sudoku;
	string code = "";
	int number_counter = 0;
	char c;

	FILE* fout;
	fopen_s(&fout, "sudoku.txt", "w");

	while ((c = fgetc(subject)) != EOF) {
		if (isdigit(c)) {
			code += c;
			number_counter++;
		}
		if (number_counter == SIZE * SIZE) {
			number_counter = 0;
			sudoku = new Subject_sudoku(code);
			if (!fill_sudoku(sudoku, fout)) {
				cout << "no solutions" << endl;
			};
			delete(sudoku);
			code = "";
		}
	}
	fclose(fout);
	return 0;
}

bool fill_sudoku(Subject_sudoku* sudoku, FILE* fout) { // -- succeed(true) or failed(false)
	Box* box;
	box = sudoku->get_minpos_box();
	//cout << sudoku->to_string() << endl;
	if (box == NULL) {
		sudoku->show(fout);
		return true;
	}
	return guess_value(box, sudoku, fout);
}

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

bool guess_value(Box* box, Subject_sudoku* sudoku, FILE* fout) {
	//cout << "guess" << endl;
	int rowno = box->row->number;
	int columnno = box->column->number;
	for (int i = 0; i < SIZE; i++) {
		if (box->posvalue & get_valuebit(i)) { // -- value i+1 is possible
											   //Subject_sudoku* new_sudoku = new Subject_sudoku(*sudoku);
			Box* box = sudoku->getbox(rowno, columnno);
			int members_posvalues[3][9];
			int posvalue = box->make_certain(i + 1, members_posvalues);
			if (fill_sudoku(sudoku, fout)) {
				return true;
			}
			//delete(new_sudoku);
			box->cancel_certain(posvalue, members_posvalues);
		}
	}
	return false;
}