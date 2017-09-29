#pragma once
#include "stdafx.h"
using namespace std;

class Templet {
public:
	string line[9][3]; // line[block][row]
	const string line1_position_code = "012"; // not change
	string line2_position_code = "345"; // 3! = 6 types
	string line3_position_code = "678"; // 3! = 6 types

	Templet();
	void fill_line(const string linetemp[], const string code, const int blockbegin);
	Templet* fill_line1();
	Templet* fill_line2();
	Templet* fill_line3();
	bool change2next();
	void show();
};
