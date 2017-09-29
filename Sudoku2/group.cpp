#include "stdafx.h"

Group::Group(int number, int has) {
	this->number = number;
	this->hasvalues = has;
}

void Group::make_certain(Box* box) {
	hasvalues |= get_valuebit(box);
	refresh_pos();
}

void Group::cancel_certain(Box* box) {
	hasvalues &= ~get_valuebit(box);	// -- reset hasvalue
}

void Group::push_back(Box* new_member) {
	this->members[this->members_num++] = new_member;
}

void Group::initial() {
	/* collect values */
	for (size_t i = 0; i < SIZE; i++) {
		if (members[i]->iscertain()) {
			hasvalues |= get_valuebit(members[i]); // -- add cervalue to hasvalue
		}
	}
	/* initial members' posvalue */
	refresh_pos();
}

void Group::refresh_pos() {
	for (int i = 0; i < SIZE; i++) {
		members[i]->posvalue &= (~hasvalues); // -- remove impossible value bit
	}
}