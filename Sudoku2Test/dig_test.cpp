#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Sudoku2Test
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(lock_test1)
		{
			UnitMaps unitmaps;
			unitmaps.fill_in(1, 1, 0);
			unitmaps.fill_in(1, 2, 3);
			unitmaps.fill_in(1, 3, 6);
			unitmaps.fill_in(1, 6, 7);
			int figure, i, j;
			unitmaps.get_decisive(figure, i, j);
			Assert::AreEqual(figure, 1);
			Assert::AreEqual(i, 0);
			Assert::AreEqual(j, 8);
		}
		TEST_METHOD(lock_test2)
		{
			UnitMaps unitmaps;
			unitmaps.fill_in(1, 2, 0);
			unitmaps.fill_in(1, 4, 4);
			unitmaps.fill_in(1, 3, 6);
			unitmaps.fill_in(2, 0, 3);
			unitmaps.fill_in(3, 0, 5);
			unitmaps.fill_in(5, 0, 7);
			int figure, i, j;
			unitmaps.get_decisive(figure, i, j);
			Assert::AreEqual(figure, 1);
			Assert::AreEqual(i, 0);
			Assert::AreEqual(j, 8);
		}
		TEST_METHOD(advanced_test)
		{
			UnitMaps unitmaps;
			int figure, i, j;
			int mat[SIZE*SIZE] =
			{
				1, 0, 0, 3, 0, 0, 0, 0, 5,
				0, 4, 0, 0, 0 ,6, 8, 0, 0,
				0, 6, 8, 7, 0, 0, 0, 0, 0,

				2, 0, 0, 9, 5, 0, 0, 0, 0,
				0, 1, 0, 0, 6, 0, 0, 7, 0,
				0, 0, 0, 0, 8, 7, 0, 0 ,6,

				0, 0, 0, 0, 0, 9, 6, 1, 7,
				0, 0, 7, 2, 0, 0, 0, 3, 0,
				3, 0, 0, 0, 0, 5, 0, 0, 8
			};
			unitmaps.read_matrix(mat);
			unitmaps.get_decisive(figure, i, j);
			Assert::AreEqual(figure, 6);
		}
	};
}