#include "stdafx.h"

Templet::Templet() {
	fill_line1();
	fill_line2();
	fill_line3();
}

void Templet::fill_line(const string linetemp[], const string code, const int blockbegin) {
	int blockno = blockbegin;
	for (int i = 0; i < 3; i++, blockno++) { // each block
		for (int j = 0; j < 3; j++) { // each line, begin with linetemp1
			line[blockno][(code[i] + j) % 3] = linetemp[j];
		}
	}
}

Templet* Templet::fill_line1() {
	const string linetemp[3] = {
		"012",
		"345",
		"678"
	};
	fill_line(linetemp, line1_position_code, 0);
	return this;
}

Templet* Templet::fill_line2() {
	const string linetemp[3] = {
		"201",
		"534",
		"867"
	};
	fill_line(linetemp, line2_position_code, 3);
	return this;
}

Templet* Templet::fill_line3() {
	const string linetemp[3] = {
		"120",
		"453",
		"786"
	};
	fill_line(linetemp, line3_position_code, 6);
	return this;
}

bool Templet::change2next() {
	if (!next_permutation(line2_position_code.begin(), line2_position_code.end())) {
		next_permutation(line3_position_code.begin(), line3_position_code.end());
		sort(line2_position_code.begin(), line2_position_code.end()); // initial line2 code
		fill_line2();
		fill_line3();
	}
	else {
		fill_line2();
	}
	return true;
}

void Templet::show() {
	for (int i = 0; i < 8; i += 3) { // each big line
		for (int j = 0; j < 3; j++) { // each small line
			for (int k = 0; k < 3; k++) { // each block
				cout << line[i + k][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << '\n';
}
