#pragma once
#include "stdafx.h"

int dig(int mat[SIZE*SIZE], int out[SIZE*SIZE], int dig_count);

bool try_dig(UnitMaps & unitmaps, int dig_x, int dig_y, int dig_count, int dig_tg, int out[SIZE*SIZE]);