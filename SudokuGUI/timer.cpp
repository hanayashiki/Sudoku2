#include "timer.h"

Timer::Timer(SudokuGUI* ui, QLCDNumber* lcd) {
	this->ui = ui;
	this->timer = new QTimer(this);
	this->time_lcd = lcd;
	connect(timer, SIGNAL(timeout()), this, SLOT(timeout_handle()));
}

void Timer::timeout_handle() {
	*time = time->addMSecs(TIMEOUT_MILL);
	time_lcd->display(time->toString("hh:mm:ss.zzz"));
}

void Timer::start() {
	if (time) {
		delete time;
	}
	time = new QTime(0, 0, 0, 0);
	timer->start(TIMEOUT_MILL);
}

void Timer::stop() {
	if (timer->isActive()) {
		timer->stop();
	}
}