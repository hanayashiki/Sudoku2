#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
int solution[SIZE * SIZE] = { 0 };
int row_record[9] = { 0 }; // must be 511
int column_record[9] = { 0 };
int block_record[9] = { 0 };

namespace Sudoku2Test
{
	TEST_CLASS(UnitTest2)
	{
	public:

		void test_s(int puzzle[], bool resolvable) {
			int bit;

			int counter = 0;

			//vector<vector<int>>* results = create_sudokus(number);
			bool success = solve_sudoku(puzzle, solution);
			Assert::AreEqual(resolvable, success);
			if (!success) {
				return;
			}
			for (int rowno = 0; rowno < SIZE; rowno++) {
				for (int columnno = 0; columnno < SIZE; columnno++) {
					bit = (1 << (solution[GET_POS(rowno, columnno)] - 1));
					row_record[rowno] |= bit;
					column_record[columnno] |= bit;
					block_record[GET_BLOCKNO(rowno, columnno)] |= bit;
				}
			}

			// judge & initial
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(511, row_record[i]);
				Assert::AreEqual(511, column_record[i]);
				Assert::AreEqual(511, block_record[i]);
				row_record[i] = 0;
				column_record[i] = 0;
				block_record[i] = 0;
			}
			counter++;
			
		}

		TEST_METHOD(solve)
		{
			// TODO: 在此输入测试代码
			int mat_input[SIZE*SIZE] =
			{
				1, 2, 3, 0, 0, 0, 0, 0, 0,
				4, 5, 6, 0, 0, 0, 0, 0, 0,
				7, 8, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0
			};
			test_s(mat_input, true);
		}

		TEST_METHOD(solve2)
		{
			// TODO: 在此输入测试代码
			int mat_input[SIZE*SIZE] =
			{
				1, 0, 0, 0, 0, 0, 0, 0, 0,
				2, 0, 0, 0, 0, 0, 0, 0, 0,
				3, 0, 0, 0, 0, 0, 0, 0, 0,
				4, 0, 0, 0, 0, 0, 0, 0, 0,
				5, 0, 0, 0, 0, 0, 0, 0, 0,
				6, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 1, 2, 3, 4, 5, 6
			};
			test_s(mat_input, false);
		}

		TEST_METHOD(test_vec)
		{
			vector<int> v = test_vector();
			//getchar();
		}

	};
}