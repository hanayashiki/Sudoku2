/* WARNING:
1. Timer may overflow (after 24h)
2. Track and clean
*/

/* FUNCS:
1. check
2. tip
3. track (digit)
4. immediately checking (bool)
*/

/* MENU
1. new
2. help
3. about (Easter eggs?)
4. ranking list
*/

#include "SudokuGUI.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <QFileInfo>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SudokuGUI ui;

	//ui.new_game(0); // new game
	ui.show();
	return a.exec();
}
