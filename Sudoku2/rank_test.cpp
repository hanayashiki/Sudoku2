#include "stdafx.h"

int main() {
	Rank rank;
	char name[NAMESIZE];
	double time;

	//rank.clear();
	cout << 1 << endl;
	rank.record(EASY, 2, "kirito");
	cout << 2 << endl;
	rank.record(EASY, 3, "asuna");
	cout << 3 << endl;
	rank.record(EASY, 4, "abcd");
	rank.record(EASY, 2.5, "シマザキセツナ");
	rank.record(EASY, 1, "一二三四五六七八九2");
	rank.record(EASY, 1, "我是智障神经病事实上事实上所所所所所");
	cout << "finish record" << endl;
	rank.show(EASY);
	
	rank.fetch_last_record(name, time);
	cout << "last: " << name << " " << time << endl;
	rank.fetch_rank(0, 1, name, time);
	cout << "rank 1: " << name << " " << time << endl;
	rank.fetch_rank(0, 33, name, time);
	cout << "rank 33: " << name << " " << time << endl;
	rank.fetch_rank(0, 2, name, time);
	cout << "rank 2: " << name << " " << time << endl;
	rank.fetch_rank(0, 4, name, time);
	cout << "rank 4: " << name << " " << time << endl;

	rank.encrypt_flush(ENCRYPT);
	getchar();
	return 0;
}