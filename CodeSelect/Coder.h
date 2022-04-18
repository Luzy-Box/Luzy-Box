#pragma once
#include "L.h"

typedef  void(*V_CALL)(void);
//typedef V_CALL PRINT;
typedef V_CALL SELECT;

#define QUIT -1

#define PREV_MODE -1
#define QUIT_MODE -10

#define ACTION_MAX 20
#define MAX_NODE 25

/*一条选项*/
struct Select
{
	char action[ACTION_MAX] = {0};
	int Next_code = 0;
};

struct node_L
{
	V_CALL function = NULL;
	void __stdcall menu();
	Select* action = NULL;
	int action_n = 0;
};

class Coder
{
private:
	int run = 1;
	int Index = 0;
	int node_now = 0;
	int prev_node = 0;

	node_L node[MAX_NODE];

public:
	void Init();
	void work();
	void quit();

	void SetNode(int, V_CALL);
	void SetNode(int, Select,...);//End with 0
	void SetNode(int, int next);
	void SetNode(int,int select,int next);

	void play_node();
	void __stdcall line();

	~Coder();
};

