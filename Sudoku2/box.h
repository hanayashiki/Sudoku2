#pragma once
#include "stdafx.h"
#define BOX_COUNT (9*9)

class Box {
public:
	Subject_sudoku* sudoku;
	Group*	row;
	Group*	column;
	Group*	block;
	int		posvalue = 1023;	// --- a binary number, 000000000 means certain value
	int		cervalue = 0;		// --- range from 1 to 9

	Box(Subject_sudoku* sdk, Group* r, Group* c, Group* b, int value);
	Box(Subject_sudoku* sdk, Group* r, Group* c, Group* b, int pos, int cer);
	bool iscertain();
	int make_certain(int value, int members_posvalues[3][9]);
	void cancel_certain(int posvalue, int members_posvalues[3][9]);
};