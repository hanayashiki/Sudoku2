#include "stdafx.h"


Exchanger::Exchanger(int* perms[EXCHANGER_GROUPS_COUNT][EXCHANGER_GROUPS_SIZE]) {
	/* copy perms */
	for (int groupno = 0; groupno < EXCHANGER_GROUPS_COUNT; groupno++) {
		for (int memberno = 0; memberno < EXCHANGER_GROUPS_SIZE; memberno++) {
			this->perms[groupno][memberno] = perms[groupno][memberno];
		}
	}
}

void Exchanger::exchange(int *n1, int *n2) {
	*n1 = (*n1) ^ (*n2);
	*n2 = (*n1) ^ (*n2);
	*n1 = (*n1) ^ (*n2);
}

void Exchanger::exchange_members() {
	for (int i = 0; i < EXCHANGER_GROUPS_COUNT; i++) {
		if (mode) {
			exchange(perms[i][0], perms[i][1]);
		}
		else {
			exchange(perms[i][0], perms[i][2]);
		}
	}
	mode = !mode;
}

void Exchanger::exchange_groups() {
	for (int i = 0; i < EXCHANGER_GROUPS_SIZE; i++) {
		exchange(perms[1][i], perms[2][i]);
	}
}

void Exchanger::try_activate_next() {
	exchange_counter++;			// -- count exchanging
	if (exchange_counter == MAX_EXCHANGE_COUNT) {
		exchange_counter = 0;		// -- initial counter
		reach_half = !reach_half;	// -- reach half or reach ending(beginning)
		if (reach_half) {
			exchange_groups();		// -- exchange group(1, 2)
		}
		else if (next != NULL){
			next->change2next();	// -- exchange next Exchanger
		}
	}
}

void Exchanger::change2next() {
	exchange_members();		// -- change the char
	try_activate_next();	// -- activate next exchanger if gone through all permutations
}