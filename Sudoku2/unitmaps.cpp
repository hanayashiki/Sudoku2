#include "stdafx.h"

UnitMaps::UnitMaps() {
	clear();
}

void UnitMaps::clear() {
	for (int id = 0; id < SIZE; id++) {
		row_maps[id].id = id;
		column_maps[id].id = id;
		group_maps[id].id = id;

		row_maps[id].clear();
		column_maps[id].clear();
		group_maps[id].clear();

		row_maps[id].type = ROW;
		column_maps[id].type = COLUMN;
		group_maps[id].type = GROUP;
		for (int j = 0; j < SIZE; j++) {
			matrix[id][j] = 0;
		}
	}
}


bool UnitMaps::fill_in(int figure, int i, int j) {
	int group_id = GET_GROUP_ID(i, j);
	assert(matrix[i][j] == 0);
	matrix[i][j] = figure;
	// lock up relevant rows and columns
	row_maps[i].inside_lock(figure, j);
	for (int k = 0; k < 9; k++) {
		if (k != i) {
			row_maps[k].outside_lock(figure, i, j);
		}
	}
	column_maps[j].inside_lock(figure, i);
	for (int k = 0; k < 9; k++) {
		if (k != j) {
			column_maps[k].outside_lock(figure, i, j);
		}
	}
	// lock up the group
	assert(GET_GROUP_INDEX(i, j) < 9);
	group_maps[group_id].inside_lock(figure, GET_GROUP_INDEX(i, j));
	// lock up relevant groups
	for (int group_index = 0; group_index < RELEVANT; group_index++) {
		group_maps[group_id2relevant_groups[group_id][group_index]].outside_lock(figure, i, j);
	}
	return true;
}

bool UnitMaps::get_decisive(int & figure, int & i, int & j) {
	for (int trial = 0; trial < 9; trial++) {
		if (row_maps[trial].get_decisive(figure, i, j)) {
			return true;
		}
		if (column_maps[trial].get_decisive(figure, i, j)) {
			return true;
		}
		if (group_maps[trial].get_decisive(figure, i, j)) {
			cout << "get decisive at group:" << trial << endl;
			return true;
		}
	}
	cout << "no decisive." << endl;
	return false;
}