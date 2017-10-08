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

	};
}