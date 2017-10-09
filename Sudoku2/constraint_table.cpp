#include "stdafx.h"

bool ConstraintTable::add_constr(int fig, int x, int y) {
	constraint temp_constr = {fig, x, y };
	linked::iterator linked_iterator;
	for (linked_iterator = linked_constr[F2INDEX(fig)].begin();
		linked_iterator != linked_constr[F2INDEX(fig)].end();
		++linked_iterator)
	{
		if ((linked_iterator->x == x) && (linked_iterator->y == y)) {
			return false;
		}
	}
	linked_constr[F2INDEX(fig)].push_back(temp_constr);
	//cout << "Add a constaint:";
	//printf("%d at ( %d , %d )\n", fig, x, y);
	return true;
}

bool ConstraintTable::del_constr(int fig, int x, int y) {
	linked::iterator linked_iterator;
	for (linked_iterator = linked_constr[F2INDEX(fig)].begin();
		linked_iterator != linked_constr[F2INDEX(fig)].end();
		++linked_iterator)
	{
		if ((linked_iterator->x == x) && (linked_iterator->y == y)) {
			linked_constr[F2INDEX(fig)].erase(linked_iterator++);
			return true;
		}
	}
	return false;
}

void ConstraintTable::dump_constr(constraint constr[], int & num) {
	linked::iterator linked_iterator;
	int index = 0;
	num = 0;
	for (int fig = 1; fig <= 9; fig++) {
		num += linked_constr[F2INDEX(fig)].size();
		for (linked_iterator = linked_constr[F2INDEX(fig)].begin();
			linked_iterator != linked_constr[F2INDEX(fig)].end();
			linked_iterator++, index++) 
		{
			constr[index] = *linked_iterator;
		}
	}
	
}

