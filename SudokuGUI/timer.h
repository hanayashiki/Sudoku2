#pragma once

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QLineEdit>
#include <QLCDNumber>

#define TIMEOUT_MILL 1

class SudokuGUI;

class Timer : public QObject {
	Q_OBJECT

public:
	SudokuGUI* ui;
	Timer(SudokuGUI* ui, QLCDNumber* lcd);
	void start();
	void stop();

private:
	QTimer* timer = NULL;
	QTime* time = NULL;
	QLCDNumber* time_lcd = NULL;



	public slots:
	void timeout_handle();

};