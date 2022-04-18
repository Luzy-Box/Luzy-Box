#include "Coder.h"

void __stdcall node_L::menu()
{
	for (int y = 0; y < action_n; y++)
		cout << y << char(9) << action[y].action << endl;
}

void Coder::Init()
{
	play_node();
}

void Coder::work()
{
	while (run)
	{
		if (node[node_now].action_n == 1)//自动跳转下一节点，自加暂停
		{
			prev_node = node_now;
			node_now = node[node_now].action[0].Next_code;
			play_node();
			continue;
		}

		cout<<"操作: "; cin >> Index;//多条指令选择
		if (Index <= QUIT)break;//postive
		else if (Index < node[node_now].action_n)
		{
			if (node[node_now].action[Index].Next_code == QUIT_MODE)break;
			else if (node[node_now].action[Index].Next_code == PREV_MODE)
			{
				node_now = prev_node;
			}
			else if (node[node[node_now].action[Index].Next_code].action_n == 0)//只执行节点
			{
				if (node[node[node_now].action[Index].Next_code].function != NULL)
					node[node[node_now].action[Index].Next_code].function();
			}
			else
			{
				prev_node = node_now;
				node_now = node[node_now].action[Index].Next_code;
			}
			play_node();
		}
	}
}

void Coder::quit()
{
	run = 0;
}

void Coder::SetNode(int index, V_CALL funcion)
{
	node[index].function = funcion;
}

void Coder::SetNode(int index, Select Start, ...)
{
	int y = 0;
	while ((*(&Start + y)).action[0] != 0)
	{
		y++;
	}
	node[index].action_n = y;
	node[index].action = new Select[y];
	for (y = 0; y < node[index].action_n; y++)
		node[index].action[y] = *(&Start + y);
}

void Coder::SetNode(int index, int next)
{
	node[index].action[0].Next_code = next;
}

void Coder::SetNode(int index, int select, int next)
{
	node[index].action[select].Next_code = next;
}

void Coder::play_node()//仅使用调用当前节点
{
	system("CLS");
	//Now Node Index [TEST	]
	//cout << "[NODE INDEX] : [ " << (int)node_now << " ]" << endl;
	//指令函数
	if(node[node_now].function != NULL)node[node_now].function();
	//指令列表
	if (node[node_now].action_n != 0)
	{
		cout << "[操作]" << endl;
		line();
		node[node_now].menu();
		line();
	}
}

void __stdcall Coder::line()
{
	for (int y = 0; y < 10; y++)
		cout << "——";
	cout << endl;
}

Coder::~Coder()
{
	for (int y = 0; y < MAX_NODE; y++)
		if (node[y].action)delete[]node[y].action;
}


