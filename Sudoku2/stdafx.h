// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

// TODO: 在此处引用程序需要的其他头文件

#define BUFFER_SIZE 1'000'000
#define SIZE 9
#define GET_POS(ROWNO, COLUMNNO) ((ROWNO)*SIZE + (COLUMNNO))
#define GET_BLOCKNO(ROWNO, COLUMNNO) (ROWNO / 3) * 3 + (COLUMNNO / 3)

#include <iostream>  
using namespace std;

#ifndef __TEXT_H__
#define __TEXT_H__

#include <algorithm>  
#include <string> 
#include <vector>
#include <assert.h>
#include "templet.h"
#include "template_sudoku.h"
#include "subject_sudoku.h"
#include "box.h"
#include "subject_sudoku.h"
#include "group.h"
#include "utils.h"
#include "create.h"
#include "solve.h"
#include "mode_generatror.h"

#endif
