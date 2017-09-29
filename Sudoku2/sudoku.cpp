#include "stdafx.h"

Subject_sudoku::Subject_sudoku(string sudoku_str) {
	//cout << sudoku_str << endl;
	for (int i = 0; i < SIZE; i++) {
		rows[i] = new Group(i);
		columns[i] = new Group(i);
		blocks[i] = new Group(i);
	}
	int counter = 0;
	int rowno, columnno, blockno;
	for (char &c : sudoku_str) { // -- create boxes and put into groups
		rowno = counter / 9;
		columnno = counter % 9;
		blockno = GET_BLOCKNO(rowno, columnno);
		Box* box = new Box(this, rows[rowno], columns[columnno], blocks[blockno], (c - '0'));
		rows[rowno]->push_back(box);
		columns[columnno]->push_back(box);
		blocks[blockno]->push_back(box);
		counter++;
	}
	initial();
}

/* [copy construction] */
Subject_sudoku::Subject_sudoku(const Subject_sudoku& sudoku) {
	//cout << "create" << endl;
	for (int i = 0; i < SIZE; i++) {
		rows[i] = new Group(i, sudoku.rows[i]->hasvalues);
		columns[i] = new Group(i, sudoku.columns[i]->hasvalues);
		blocks[i] = new Group(i, sudoku.blocks[i]->hasvalues);
	}
	int counter = 0;
	int blockno;
	for (int rowno = 0; rowno < SIZE; rowno++) {
		for (int columnno = 0; columnno < SIZE; columnno++) {
			blockno = GET_BLOCKNO(rowno, columnno);
			Box* oldbox = sudoku.getbox(rowno, columnno);
			Box* box = new Box(this, rows[rowno], columns[columnno], blocks[blockno], oldbox->posvalue, oldbox->cervalue);
			rows[rowno]->push_back(box);
			columns[columnno]->push_back(box);
			blocks[blockno]->push_back(box);
			counter++;
		}
	}
}

Subject_sudoku::~Subject_sudoku() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			delete rows[i]->members[j];
		}
		delete rows[i];
		delete columns[i];
		delete blocks[i];
	}
}

Box* Subject_sudoku::getbox(int rowno, int columnno) const {
	return this->rows[rowno]->members[columnno];
}

Box* Subject_sudoku::get_minpos_box() const {
	int minpos = SIZE + 1;
	int pos;
	Box* minbox = NULL;
	Box* box;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			box = getbox(i, j);
			if (!box->iscertain()) {
				pos = count_one(box->posvalue);
				//cout << pos << endl;
				if (pos < minpos) {
					minpos = pos;
					minbox = box;
				}
			}
		}
	}
	return minbox;
}

void Subject_sudoku::initial() {
	for (int i = 0; i < SIZE; i++) {
		rows[i]->initial();
		columns[i]->initial();
		blocks[i]->initial();
	}
}

void Subject_sudoku::show(FILE* fout) {
	char buffer[200];
	int index = 0;
	for (int i = 0; i < SIZE; i++) {
		buffer[index++] = getbox(i, 0)->cervalue + '0';
		for (int j = 1; j < SIZE; j++) {
			buffer[index++] = ' ';
			buffer[index++] = getbox(i, j)->cervalue + '0';
		}
		buffer[index++] = '\n';
	}
	buffer[index++] = '\n';
	buffer[index++] = '\0';
	fputs(buffer, fout);
}

string Subject_sudoku::to_string() {
	string sudoku = "";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			sudoku += (getbox(i, j)->cervalue + '0');
		}
	}
	return sudoku;
}
