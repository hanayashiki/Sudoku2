// copyright Wang Chenyu, Liu Chang 2017
// 这个文件中定义类 FgMap，即 figure-grid map
// 基本功能是用来记录 一个 行 或 列 或 宫 （简称为单元） 中，数字 1-9 到位置 1-9 的所有可能映射
// 从而当存在数字 f ∈ [1-9] 使得映射唯一确认时 ， 可以完成一个数字的位置的推导

#pragma once
#include "stdafx.h"
#define ROW 1
#define COLUMN 2
#define GROUP 3

#define F2INDEX(f) (f-1)
#define INDEX2MASK(I) (~(1 << (I)))
#define INDEX2TARGETBIT(I) (1 << (I))

#define SAMEGROUP(x,y,i,j) (((x)/3 == (i)/3) && ((y)/3 == (j)/3))

class FgMap {
private:
	int map[9] = { 0 } ;  // map[i] 的 第 j 个 bit 为 1 表示数字 i+1 能填入第 j 个空
	int pos_count[9] = { 0 };   // pos_count[i] 记录了 map[i] 里面有多少个 bit 是 1.
	int min_map_index = 0;  // 指向 map 中 1 bit 最少的，优化推导
	int min_map = INT32_MAX;
public:
	FgMap();
	int type = -1;  // 是行还是列还是宫中的数字-位置映射
	int id;  // 行，或列或宫的序号，从左到右从上到下自 0 递增。

	bool inside_lock(int figure, int place);

	bool lock(int figure_x, int index);

	bool outside_lock(int figure, int i, int j);

	bool index2co(int index, int & i, int & j);

};