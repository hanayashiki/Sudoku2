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
	rank_list list[MODE_COUNT];  // �����Ѷȵ����а�
};

class Rank {
private:
	rank_board board;
	rank_entry* ptr_last_record = NULL;  // ���¼���ָ��
	FILE* dbfile = NULL;
public:
	Rank();
	~Rank();
	bool record(int mode, double time, char * name);
	// �����¼���Ѷȣ���ʱ��������
	bool fetch_rank(int mode, int r, char * name, double & time);
	// ��ȡ mode �Ѷ�����Ϊ r ��������ʱ��, 1-indexed
	bool clear();
	// ������а�
	bool fetch_last_record(char * name, double & time);
	// ����ϴ�¼���������ʱ��
	bool encrypt_flush(bool encrypt);
	// ���ܲ�����
	void load_db(bool encrypt);
	// ���ļ��м���
	void init_db();
	// ��ʼ�����ݿ�
	void init_board();
	// ��ʼ�� board
	bool fetch_free(int mode, int & index);
	// ����һ���յ� entry
	bool insert_after(int mode, int tg_id, int new_id);
	// �ڿռ���idΪtg_entry��λ�ú������new_entry
	bool show(int mode);
};