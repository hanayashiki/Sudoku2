#include "stdafx.h"

/* for sudoku */
#define BLOCK_SIZE 3				// -- the length of a block's side

/* for Exchanger */
#define EXCHANGER_GROUPS_SIZE 3		// -- 对几个数字进行全排列
#define EXCHANGER_GROUPS_COUNT 3	// -- 有几组数字需要排列
#define MAX_EXCHANGE_COUNT 6		// -- 一共需要交换几次
#define EXCHANGER_COUNT 12			// -- 共有几个Exchanger

/* for creating the initial sudoku */
#define BASE_LINE {1,2,3}			// -- 生成数独的基本构成单位
#define POSITION_SEED {0,1,2}		// -- 根据其字符顺序决定line依次填入的位置



class Exchanger {
private:
	int exchange_counter = 0;	// -- record exchanging times
	bool mode = true;			// -- exchange (1, 2) when true; overwise exchange (2, 3)
	char *c1, *c2;				// -- char to exchange

public:
	Exchanger* next = NULL;		// -- the pointer of next exchanger
	char* perms[EXCHANGER_GROUPS_COUNT][EXCHANGER_GROUPS_SIZE];	// -- numbers to permutate

	Exchanger() {}

	void exchange() {
		for (int i = 0; i < EXCHANGER_GROUPS_COUNT; i++) {
			// choose char
			if (mode) {
				c1 = perms[i][0];
				c2 = perms[i][1];
			}
			else {
				c1 = perms[i][1];
				c2 = perms[i][2];
			}
			// exchange
			*c1 = (*c1) ^ (*c2);
			*c2 = (*c1) ^ (*c2);
			*c1 = (*c1) ^ (*c2);
		}
	}

	void try_activate_next() {
		exchange_counter++;			// -- count exchanging
		if (exchange_counter == MAX_EXCHANGE_COUNT) {
			exchange_counter = 0;	// -- initial counter
			if (next != NULL) {
				next->change2next();
			}
		}
	}

	void change2next() {
		exchange();				// -- change the char
		try_activate_next();	// -- activate next exchanger if gone through all permutations
	}
};

void roll_int(int i_array[], int len) {
	if (i_array == NULL || len == 0) { // if NULL or empty, return
		return;
	}
	int first = i_array[0];
	int i;
	for (i = 0; i < len - 1; i++) {		// go through i_array from the 2nd element
		i_array[i] = i_array[i + 1];	// move char backward
	}
	i_array[i] = first;
}

void fill_line_to_sudoku(int* grid, int line[BLOCK_SIZE]) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		(*grid) = line[i];
		grid++;
	}
}

void initial_sudoku(int sudoku[SIZE][SIZE]){
	int position_seed[] = POSITION_SEED;
	int base_line[] = BASE_LINE;
	for (int i = 0; i < BLOCK_SIZE; i++) { // each type of base line
		for (int rowno = 0; rowno < SIZE; rowno += BLOCK_SIZE) { // rowno of 0 3 6
			for (int colno = 0, j = 0; colno < SIZE; colno += BLOCK_SIZE, j++) { // colno of 0 3 6, j go through position seed
				fill_line_to_sudoku(&(sudoku[rowno + position_seed[j]][colno]), base_line); // fill
			}
			roll_int(base_line, BLOCK_SIZE); // roll base_line
		}
		for (int k = 0; k < BLOCK_SIZE; k++) { // each element in base_line +=3
			base_line[k] += BLOCK_SIZE;
		}
		roll_int(position_seed, BLOCK_SIZE); // roll position_seed
	}
}

void initial_exchanger(Exchanger* exchangers[]) {

}

void output_sudoku(int sudoku[SIZE][SIZE], int result[SIZE*SIZE]) {

}

void create_sudokus(int number, int result[][SIZE*SIZE]) 
{
	int sudoku[SIZE][SIZE] = { 0 };
	Exchanger* exchangers[EXCHANGER_COUNT];
	/* initial */
	initial_sudoku(sudoku);
	initial_exchanger(exchangers);
	/* create */
	Exchanger* head_exchanger = exchangers[0];
	for (int count = 0; count < number; count++)	// (for each result)
	{	
		output_sudoku(sudoku, result[count]);	// -- write to result[][]
		head_exchanger->change2next();			// -- change the sudoku
	}
}

int main() {
	int sudoku[SIZE][SIZE] = { 0 };
	initial_sudoku(sudoku);
	getchar();
}

/*void create_sudokus(int number, int result[][SIZE*SIZE]) {
	Template_sudoku templ = Template_sudoku();
	//vector<vector<int>>* sudokus = new vector<vector<int>>(number);
	//sudokus.resize(number);
	
	for (int count = 0; count < number; count++) {
		//vector<int> & sudoku = sudokus[count];
		//vector<int> sudoku(sudokus->at(count));
		//sudoku.reserve(BOX_COUNT);
		templ.create_from_template(result[count]);
		templ.change2next();
	}
}*/