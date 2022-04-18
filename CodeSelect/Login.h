#pragma once
#include "L.h"

#define USER_NONE -1

#define ACCOUNT_NO_FIND -1
#define ACCOUNT_NO_SELECT -1

#define MAX_LENGTH 20

enum class Pre {
	NORMAL = 0,
	ADMINI,//Administration

	PRE_COUNT
};

struct User
{
	char name[MAX_LENGTH] = {};
	char account[MAX_LENGTH] = {};
	char password[MAX_LENGTH] = {};
	Pre premission = Pre::NORMAL;
};

//Premission Table/Map every user's permission.
struct Action_Pre
{
	int Pre[int(Pre::PRE_COUNT)] = { 0 };
	void (*action_fun)() = NULL;
};

class Login
{
private:
	User user_infor[10];
	int current_user = USER_NONE;
	unsigned char user_n = 0;
	int select_arm = ACCOUNT_NO_SELECT;
public:
	void AddNewUser(const char* name, const char* account, const char* password, Pre pre);
	void AddNewUser();
	void RemoveUser();
	int checkAcount(char* Input);
	void login_user();
	void ShowInfor();//current user information.
	Pre getpre();
	void ShowUserList();

	void select();
	void show_c_select();
	void s_infor();

	void changeLoginInfor(int Index);
	void no_select();
};

