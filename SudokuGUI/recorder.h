#pragma once

#include <QObject>
#include "guis.h"

class Recorder : public QObject{
	Q_OBJECT
public:
	SudokuGUI* ui;
	Recorder(SudokuGUI* ui) {
		this->ui = ui;
	}
public slots:
	void record_button();
	void set_number(int i);
	bool judge();
	void new_puzzle();
};
