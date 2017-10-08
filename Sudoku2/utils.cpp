#include "stdafx.h"

int get_valuebit(Box* member) {
	return (1 << ((member->cervalue) - 1));
}
int get_valuebit(int value) {
	return (1 << value);
}

int count_one(int value) {
	int counter = 0;
	while (value) {
		value &= value - 1;
		counter++;
	}
	return counter;
}

int get_one(int vect) {
	int rightmost;
	for (int i = 0; i < SIZE; i++, vect = (vect >> 1)) {
		rightmost = vect & 0x1;
		if (rightmost == 1) {
			assert(i<9);
			return i;
		}
	}
	assert(0);
	return -1;
}