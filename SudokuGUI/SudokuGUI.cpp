#include "SudokuGUI.h"
#include "difficulty.h"
#include "timer.h"
//#include "puzzle_creator.h"
//#include "../Sudoku2/solve.cpp"
//#include "../Sudoku2/subject_sudoku.cpp"
#include <qdebug>

SudokuGUI::SudokuGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	resize(760, 570);
	/* menu */
	binding_actions();
	/* sudoku */
	create_grids();
	create_input_buttons();
	create_func_buttons();
	disable_buttons();
	/* best time */
	/* timer */
	QLCDNumber* time_lcd = new QLCDNumber(this);
	time_lcd->setDigitCount(12);
	time_lcd->setMode(QLCDNumber::Dec);
	time_lcd->setSegmentStyle(QLCDNumber::Flat);
	time_lcd->setGeometry(550, 100, 200, 50);
	//time_lcd->setPalette(Qt::red);
	//QPalette palette = time_lcd->palette();
	//palette.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
	//time_lcd->setPalette(palette);
	timer = new Timer(this, time_lcd);
}

/*===========================\
|          DRAW GUI          |
\===========================*/
void SudokuGUI::create_func_buttons() {
	/* check */
	func_buttons[CHECK] = new QPushButton("Check", this);
	QPushButton* check_button = func_buttons[CHECK];
	check_button->setGeometry(547, 410, 2 * BOX_SIZE, BOX_SIZE); // set position & size
	check_button->setFont(FUNCTION_FONT); // set fond
	check_button->setStyleSheet(FUNCTION_BUTTON_STYLE); // set color
	QObject::connect(check_button, SIGNAL(clicked()), this, SLOT(judge()));
	/* filter */
	func_buttons[FILTER] = new QPushButton("Filter", this);
	QPushButton* filter_button = func_buttons[FILTER];
	filter_button->setGeometry(547, 465, 2 * BOX_SIZE, BOX_SIZE); // set position & size
	filter_button->setFont(FUNCTION_FONT); // set fond
	filter_button->setStyleSheet(FUNCTION_BUTTON_STYLE); // set color
	QObject::connect(filter_button, SIGNAL(clicked()), this, SLOT(filter()));
	/* tip */
	func_buttons[TIP] = new QPushButton("Tip", this);
	QPushButton* tip_button = func_buttons[TIP];
	tip_button->setGeometry(652, 410, 2 * BOX_SIZE, BOX_SIZE); // set position & size
	tip_button->setFont(FUNCTION_FONT); // set fond
	tip_button->setStyleSheet(FUNCTION_BUTTON_STYLE); // set color 
	QObject::connect(tip_button, SIGNAL(clicked()), this, SLOT(tip()));
	/* track */
	func_buttons[TRACK] = new QPushButton("Track", this);
	QPushButton* track_button = func_buttons[TRACK];
	track_button->setGeometry(652, 465, 2 * BOX_SIZE, BOX_SIZE); // set position & size
	track_button->setFont(FUNCTION_FONT); // set fond
	track_button->setStyleSheet(FUNCTION_BUTTON_STYLE); // set color
	QObject::connect(track_button, SIGNAL(clicked()), this, SLOT(set_tracking()));

}


void SudokuGUI::create_grids() {
	QSignalMapper* mapper = new QSignalMapper(this);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			numbers[i][j] = 0;
			buttons[i][j] = new QPushButton("", this);
			QPushButton* btn = buttons[i][j];

			btn->setGeometry(
				(j + 1) * BOX_SIZE + (j / 3) * 10,
				(i + 1) * BOX_SIZE + (i / 3) * 10,
				BOX_SIZE,
				BOX_SIZE
			); // set position
			btn->setEnabled(false);
			btn->setFont(QFont("Times", 18, QFont::Bold)); // set fond
			btn->setStyleSheet(CERTAIN_GRID_STYLE); // set color
			QObject::connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
			mapper->setMapping(btn, GET_GRIDNO(i, j));
		}
	}
	QObject::connect(mapper, SIGNAL(mapped(int)), this, SLOT(record_button(int)));
}


void SudokuGUI::create_input_buttons() {
	QSignalMapper* mapper = new QSignalMapper(this);
	for (int i = 1; i <= SIZE; i++) {
		char num[2];
		num[0] = i + '0';
		num[1] = '\0';
		input_buttons[i] = new QPushButton(num, this);
		QPushButton* btn = input_buttons[i];
		btn->setGeometry(
			((i - 1) % 3 + 1) * BOX_SIZE + 520 + ((i - 1) % 3) * 5,
			((i - 1) / 3 + 1) * BOX_SIZE + 130 + ((i - 1) / 3) * 5,
			BOX_SIZE,
			BOX_SIZE
		); // set position
		btn->setFont(QFont("Times", 18, QFont::Bold)); // set fond
		btn->setStyleSheet(INPUT_BOTTON_STYLE); // set color
		QObject::connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
		mapper->setMapping(btn, i);
	}
	/* Clean */
	input_buttons[0] = new QPushButton("Clean", this);
	QPushButton* clean_button = input_buttons[0];
	clean_button->setGeometry(570, 345, 2 * BOX_SIZE + 5, BOX_SIZE); // set position & size
	clean_button->setFont(FUNCTION_FONT); // set fond
	clean_button->setStyleSheet(INPUT_BOTTON_STYLE); // set color
	QObject::connect(clean_button, SIGNAL(clicked()), mapper, SLOT(map()));
	mapper->setMapping(clean_button, CLEAN);

	QObject::connect(mapper, SIGNAL(mapped(int)), this, SLOT(handle_number(int)));
}


void SudokuGUI::binding_actions() {
	QSignalMapper* mapper = new QSignalMapper(this);
	QObject::connect(ui.action_easy, SIGNAL(triggered()), mapper, SLOT(map()));
	QObject::connect(ui.action_normal, SIGNAL(triggered()), mapper, SLOT(map()));
	QObject::connect(ui.action_hard, SIGNAL(triggered()), mapper, SLOT(map()));
	mapper->setMapping(ui.action_easy, EASY);
	mapper->setMapping(ui.action_normal, NORMAL);
	mapper->setMapping(ui.action_hard, HARD);
	QObject::connect(mapper, SIGNAL(mapped(int)), this, SLOT(new_puzzle(int)));
}

/*===========================\
|           FUNCS            |
\===========================*/
void SudokuGUI::cancel_checking() {
	if (checking) {
		checking = false;
		restore_grids_style();
	}
}

void SudokuGUI::cancel_tracking() {
	if (tracking) {
		tracking = false;
		func_buttons[TRACK]->setStyleSheet(FUNCTION_BUTTON_STYLE);
		restore_grids_style();
	}
}

void SudokuGUI::restore_grids_style() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			QPushButton* grid = buttons[i][j];
			RESTORE_GRID_STYLE(grid); // restore style
		}
	}
	if (curbtn != NULL && !tracking) {
		curbtn->setStyleSheet(CURRENT_GRID_STYLE);
	}
}


void SudokuGUI::track_number(int x) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (numbers[i][j] == x) {
				buttons[i][j]->setStyleSheet(MARK_GRID_STYLE);
			}
			else {
				RESTORE_GRID_STYLE(buttons[i][j]); // restore style
			}
		}
	}
}


void SudokuGUI::set_number(int x) {
	if (curbtn != NULL) {
		int* intptr;
		intptr = &(numbers[this->cur_rowno][this->cur_colno]);
		if (x == CLEAN) {
			curbtn->setText("");
			*intptr = 0;
		}
		else {
			char num[2];
			num[0] = x + '0';
			num[1] = '\0';
			curbtn->setText(num);
			*intptr = x;
		}
	}
}


void SudokuGUI::new_game(int difficulty) {
	this->remaining_grid_number = get_puzzle(difficulty, sudoku, puzzle); // Here difficulty
	int index = 0;
	int digit;
	QPushButton* btn;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int digit = puzzle[index++];
			btn = buttons[i][j];
			if (digit == 0) { // free grid
				btn->setText("");
				btn->setEnabled(true);
				btn->setStyleSheet(UNCERTAIN_GRID_STYLE);
				numbers[i][j] = 0;
			}
			else {
				char num[2] = { '0' + digit, '\0' };
				btn->setText(num);
				btn->setEnabled(false);
				btn->setStyleSheet(CERTAIN_GRID_STYLE);
				numbers[i][j] = digit;
			}
		}
	}
	enable_buttons();
	timer->start();
	curbtn = NULL;
}


void SudokuGUI::disable_buttons() {
	QPushButton* btn;
	for (int i = 0; i < INPUTS_COUNT; i++) {
		btn = input_buttons[i];
		btn->setEnabled(false);
		btn->setStyleSheet(DISABLE_INPUT_BUTTON_STYLE);
	}
	for (int i = 0; i < FUNCTIONS_COUNT; i++) {
		btn = func_buttons[i];
		btn->setEnabled(false);
		btn->setStyleSheet(DISABLE_FUNCTION_STYLE);
	}
}

void SudokuGUI::enable_buttons() {
	QPushButton* btn;
	for (int i = 0; i < INPUTS_COUNT; i++) {
		btn = input_buttons[i];
		btn->setEnabled(true);
		btn->setStyleSheet(INPUT_BOTTON_STYLE);
	}
	for (int i = 0; i < FUNCTIONS_COUNT; i++) {
		btn = func_buttons[i];
		btn->setEnabled(true);
		btn->setStyleSheet(FUNCTION_BUTTON_STYLE);
	}
}

/*===========================\
|           SLOTS            |
\===========================*/
void SudokuGUI::record_button(int gridno) {
	cancel_checking();
	cancel_tracking();

	if (curbtn != NULL) {
		curbtn->setStyleSheet(UNCERTAIN_GRID_STYLE);
	}
	this->cur_rowno = GET_ROWNO(gridno);
	this->cur_colno = GET_COLNO(gridno);
	curbtn = buttons[cur_rowno][cur_colno];
	//curbtn = (QPushButton*)QObject::sender();
	curbtn->setStyleSheet(CURRENT_GRID_STYLE);
}


void SudokuGUI::handle_number(int i) {
	cancel_checking();

	if (tracking && i != CLEAN) {
		track_number(i);
	}
	else if (!tracking){
		set_number(i);
	}
}


bool SudokuGUI::judge() {
	if (checking) {
		cancel_checking();
		return false;
	}

	int row_digit_counter[SIZE][SIZE] = { 0 };
	int column_digit_counter[SIZE][SIZE] = { 0 };
	int block_digit_counter[SIZE][SIZE] = { 0 };

	bool pass = true;

	// store box 
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int value = numbers[i][j];
			if (value != 0) {
				row_digit_counter[i][value - 1]++;
				column_digit_counter[j][value - 1]++;
				block_digit_counter[GET_BLOCKNO(i, j)][value - 1]++;
			}
			else {
				pass = false;
			}
		}
	}

	// judge & initial
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int value = numbers[i][j];
			if (value != 0 && (
				row_digit_counter[i][value - 1] > 1 ||
				column_digit_counter[j][value - 1] > 1 ||
				block_digit_counter[GET_BLOCKNO(i, j)][value - 1] > 1
				)) {
				buttons[i][j]->setStyleSheet(WRONG_GRID_STYLE);
				pass = false;
			}
			else {
				RESTORE_GRID_STYLE(buttons[i][j]);
			}
		}
	}

	if (pass) {
		timer->stop();
		QPushButton* btn;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				btn = buttons[i][j];
				btn->setStyleSheet(CERTAIN_GRID_STYLE);
				btn->setEnabled(false);
			}
		}
		disable_buttons();
		/* you finish the puzzle */
	}
	else {
		checking = true;
	}

	return pass;
}



void SudokuGUI::new_puzzle(int difficulty) {
	qDebug() << "Date:" << QDate::currentDate();
	qDebug() << "Types:" << QString("String") << QChar('x') << QRect(0, 10, 50, 40);
	if (QMessageBox::Yes == QMessageBox::question(
		this,
		"New game",
		"Play a new game?",
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::No
	)) {
		cancel_checking();
		cancel_tracking();
		new_game(difficulty);
	}
}


void SudokuGUI::set_tracking() {
	cancel_checking();
	if (tracking) {
		cancel_tracking();
	}
	else {
		func_buttons[TRACK]->setStyleSheet(ENABLE_BUTTON_STYLE);
		tracking = true;
		if (curbtn != NULL) {
			curbtn->setStyleSheet(UNCERTAIN_GRID_STYLE);
		}
	}
}


void SudokuGUI::filter() {
	cancel_checking();
	cancel_tracking();

	int binary_recorder = 0;
	int bit = 1;
	if (curbtn != NULL) {
		GO_THROUGH_BLOCKS(GET_BLOCKNO(this->cur_rowno, this->cur_colno)) {
			int digit = numbers[i][j];
			if (digit != 0 && (i != this->cur_rowno || j != this->cur_colno)){
				binary_recorder |= (bit << (digit - 1));
			}
		}
		for (int i = 0; i < SIZE; i++) {
			int digit;
			digit = numbers[i][this->cur_colno];
			if (digit != 0 && i != this->cur_rowno) {
				binary_recorder |= (bit << (digit - 1));
			}
			digit = numbers[this->cur_rowno][i];
			if (digit != 0 && i != this->cur_colno) {
				binary_recorder |= (bit << (digit - 1));
			}
		}
		int cur_digit = numbers[this->cur_rowno][this->cur_colno];
		for (int digit = cur_digit + 1; digit <= SIZE; digit++) {
			if ((binary_recorder & (bit << (digit - 1))) == 0) {
				set_number(digit);
				return;
			}
		}
		for (int digit = 1; digit <= cur_digit; digit++) {
			if ((binary_recorder & (bit << (digit - 1))) == 0) {
				set_number(digit);
				return;
			}
		}
		set_number(CLEAN);
	}
}


void SudokuGUI::tip() {
	if (curbtn != NULL) {
		set_number(sudoku[GET_GRIDNO(cur_rowno, cur_colno)]);
		curbtn->setEnabled(false);
		curbtn->setStyleSheet(CERTAIN_GRID_STYLE);
		curbtn = NULL;
		cur_rowno = -1;
		cur_colno = -1;
	}
}