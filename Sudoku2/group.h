#pragma once
#include "stdafx.h"

class Group {
public:
	int		number;						// --- which group?
	int		hasvalues = 0;				// --- a binary number
	Box*	members[SIZE];
	int		members_posvalues[SIZE];	// --- store members' posvalue (in case of cancel_certain)
	int		members_num = 0;			// --- only when store members 

	Group(int number, int has = 0);
	void make_certain(Box* box);
	void cancel_certain(Box* box);
	void push_back(Box* new_member);
	void initial();
	void refresh_pos();
};