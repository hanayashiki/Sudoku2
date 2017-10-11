#include "stdafx.h"
#include "CppUnitTest.h"


int results[SUDOKU_MAX][SIZE*SIZE];
FILE* fout;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Sudoku2Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		typedef struct node {
			bool isbottom;
			int depth;
			string* sudoku;
			struct node* ptrs[9];
		}Treenode;

		Treenode* create_treenode(int depth, string* sudoku) {
			Treenode* p = (Treenode*)malloc(sizeof(Treenode));
			p->isbottom = true;
			p->depth = depth;
			p->sudoku = sudoku;
			for (int i = 0; i < 9; i++) {
				p->ptrs[i] = NULL;
			}
			return p;
		}

		void add_sudoku_to_tree(int depth, Treenode** p, string* sudoku) {
			if ((*p) == NULL) {
				(*p) = create_treenode(depth, sudoku);
			}
			else {
				if ((*((*p)->sudoku)).length() > 0) {
					if ((*sudoku).compare(*((*p)->sudoku)) == 0) {
						fclose(fout);
					}
					Assert::AreNotEqual(*sudoku, *((*p)->sudoku));
					add_sudoku_to_tree(depth + 1, &((*p)->ptrs[(*((*p)->sudoku))[depth + 1] - '1']), ((*p)->sudoku));
					(*p)->sudoku = new string("");
				}
				add_sudoku_to_tree(depth + 1, &((*p)->ptrs[(*sudoku)[depth + 1] - '1']), sudoku);
			}
		}

		void test_c(int number) {
			int row_record[9] = { 0 }; // must be 511
			int column_record[9] = { 0 };
			int block_record[9] = { 0 };

			char c;
			int bit;

			string* sudoku;
			Treenode* root = create_treenode(-1, new string(""));
			int counter = 0;

			fout = fopen("C:\\Users\\65486\\Desktop\\output2.txt", "w");

			//vector<vector<int>>* results = create_sudokus(number);
			create_sudokus(number, results);

			for (int i = 0; i < number; i++) {
				sudoku = new string();
				int* sudoku_ptr = results[i];
				for (int j = 0; j < SIZE; j++) {
					for (int k = 0; k < SIZE; k++) {
						c = sudoku_ptr[GET_POS(j, k)] + '0';
						(*sudoku) += c;
						bit = (1 << (c - '1'));
						row_record[j] |= bit;
						column_record[k] |= bit;
						block_record[(j / 3) * 3 + k / 3] |= bit;
					}
				}
				
				/*for (char &c : *sudoku) {
					fputc(c, fout);
				}
				fputc('\n', fout);*/

				// judge & initial
				for (int i = 0; i < 9; i++) {
					if (
						row_record[i] != 511 ||
						column_record[i] != 511 ||
						block_record[i] != 511
						) {
						fclose(fout);
					}
					Assert::AreEqual(511, row_record[i]);
					Assert::AreEqual(511, column_record[i]);
					Assert::AreEqual(511, block_record[i]);
					row_record[i] = 0;
					column_record[i] = 0;
					block_record[i] = 0;
				}
				add_sudoku_to_tree(-1, &root, sudoku);
				counter++;
			}
		}

		TEST_METHOD(create)
		{
			// TODO: 在此输入测试代码
			test_c(10000);

		}

		/*TEST_METHOD(test_vec)
		{
			vector<int> v = test_vector();
			//getchar();
		}*/

	};
}