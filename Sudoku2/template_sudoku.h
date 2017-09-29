#pragma once
#include "stdafx.h"

using namespace std;

class Template_sudoku {
public:
	string code = "312456789";

	Templet* templet = new Templet();

	bool change2next();
	void record(FILE* fout, int* index, char buffer[]);
	void create_from_template(int sudoku[]);
	/////
};
