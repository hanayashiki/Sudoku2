#pragma once

#define NAMESIZE 20
#define ENTRYSIZE 100

#define EASY 0
#define MID 1
#define HARD 2

#define MODE_COUNT 3
#define NIL (-1)

#define MAGIC 0x12345678
#define ENCRYPT false
#define DBFILE "rank.db"


struct rank_entry {
	double time;
	char name[NAMESIZE];
	int next;
};

struct rank_list {
	int free_head;
	int used_head;
	rank_entry entry[ENTRYSIZE];
};

struct rank_board {
	int magic;
	rank_list list[MODE_COUNT];  // 三种难度的排行榜
};

class Rank {
private:
	rank_board board;
	rank_entry* ptr_last_record = NULL;  // 最近录入的指针
	FILE* dbfile = NULL;
public:
	Rank();
	~Rank();
	bool record(int mode, double time, char * name);
	// 保存记录（难度，用时，姓名）
	bool fetch_rank(int mode, int r, char * name, double & time);
	// 获取 mode 难度排名为 r 的姓名和时间, 1-indexed
	bool clear();
	// 清空排行榜
	bool fetch_last_record(char * name, double & time);
	// 获得上次录入的姓名和时间
	bool encrypt_flush(bool encrypt);
	// 加密并保存
	void load_db(bool encrypt);
	// 从文件中加载
	void init_db();
	// 初始化数据库
	void init_board();
	// 初始化 board
	bool fetch_free(int mode, int & index);
	// 拿走一个空的 entry
	bool insert_after(int mode, int tg_id, int new_id);
	// 在空间中id为tg_entry的位置后面插入new_entry
	bool show(int mode);
};