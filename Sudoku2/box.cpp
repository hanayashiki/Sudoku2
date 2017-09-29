#include "stdafx.h"

Box::Box(Subject_sudoku* sdk, Group* r, Group* c, Group* b, int value) {
	this->sudoku = sdk;
	this->block = b;
	this->row = r;
	this->column = c;
	if (value == 0) { // unknown
		this->cervalue = 0;
		this->posvalue = 511;
	}
	else { // certain
		this->cervalue = value;
		this->posvalue = 0;
	}
}

Box::Box(Subject_sudoku* sdk, Group* r, Group* c, Group* b, int pos, int cer) {
	this->sudoku = sdk;
	this->block = b;
	this->row = r;
	this->column = c;
	this->posvalue = pos;
	this->cervalue = cer;
}

bool Box::iscertain() {
	return cervalue != 0;
}

int Box::make_certain(int value, int members_posvalues[3][9]) {
	int posvalue = this->posvalue;
	this->cervalue = value;
	this->posvalue = 0;
	for (int i = 0; i < 9; i++) {
		members_posvalues[0][i] = this->row->members[i]->posvalue;
		members_posvalues[1][i] = this->column->members[i]->posvalue;
		members_posvalues[2][i] = this->block->members[i]->posvalue;
	}
	this->row->make_certain(this);
	this->column->make_certain(this);
	this->block->make_certain(this);
	return posvalue;
}

void Box::cancel_certain(int posvalue, int members_posvalues[3][9]) {
	this->row->cancel_certain(this);
	this->column->cancel_certain(this);
	this->block->cancel_certain(this);
	for (int i = 0; i < 9; i++) {
		this->row->members[i]->posvalue = members_posvalues[0][i];
		this->column->members[i]->posvalue = members_posvalues[1][i];
		this->block->members[i]->posvalue = members_posvalues[2][i];
	}

	this->posvalue = posvalue;
	this->cervalue = 0;
}