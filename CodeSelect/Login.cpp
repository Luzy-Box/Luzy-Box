#include "Login.h"

void __stdcall Line()
{
	for (int y = 0; y < 10; y++)
		std::cout << "——";
	std::cout << endl;
}

int __stdcall Equal(char *Target,char*Source)
{
	for (int y = 0; y < MAX_LENGTH; y++)
	{
		if (Target[y] != Source[y])return 0;
		if (Target[y] == '\0')break;
	}
	return 1;
}

void __stdcall Copy(char* Taget,const char* Source)
{
	int y = 0;
	while (Source[y] != '\0')
	{
		Taget[y] = Source[y];
		y++;
	}
	Taget[y] = '\0';
}

void Login::AddNewUser(const char* name, const char* account, const char* password,Pre pre)
{
	Copy(user_infor[user_n].name, name);
	Copy(user_infor[user_n].account, account);
	Copy(user_infor[user_n].password, password);
	user_infor[user_n].premission = pre;
	user_n++;
}

void Login::AddNewUser()
{
	std::cout << "[数组长度] : " << MAX_LENGTH << endl;
	//HAND
	std::cout << "[创建账号]" << endl;
	char cache[MAX_LENGTH] = { 0 };
	std::cout << "名称: "; std::cin >> cache;
	Copy(user_infor[user_n].name, cache);
	std::cout << "账号: "; std::cin >> cache;
	Copy(user_infor[user_n].account, cache);
	std::cout << "密码: "; std::cin >> cache;
	Copy(user_infor[user_n].password, cache);

	std::cout << "[权限]" << endl;
	std::cout << "0	普通用户" << endl;
	std::cout << "1	管理员" << endl;
	std::cout << "设置: ";
	std::cin >> cache[0];
	if (cache[0] == '0')
		user_infor[user_n].premission = Pre::NORMAL;
	else if(cache[0]=='1')
		user_infor[user_n].premission = Pre::ADMINI;
	/*FIX INFOR*/
	else 	user_infor[user_n].premission = Pre::NORMAL;
	user_infor[user_n].name[MAX_LENGTH - 1] = '\0';
	user_infor[user_n].account[MAX_LENGTH - 1] = '\0';
	user_infor[user_n].password[MAX_LENGTH - 1] = '\0';

	user_n++;
}

void Login::RemoveUser()
{
	if (select_arm != ACCOUNT_NO_SELECT)
	{
		user_n--;
		for (int y = select_arm; y < user_n; y++)
		{
			Copy(user_infor[y].name, user_infor[y + 1].name);
			Copy(user_infor[y].account, user_infor[y + 1].account);
			Copy(user_infor[y].password, user_infor[y + 1].password);
			user_infor[y].premission = user_infor[y + 1].premission;
		}
		select_arm = ACCOUNT_NO_SELECT;
		std::cout << "[删除成功]" << endl;
	}
}

int Login::checkAcount(char* Input)
{
	for (int y = 0;y<user_n;y++)
	{
		if (Equal(Input, user_infor[y].account))return y;
	}
	return ACCOUNT_NO_FIND;
}

void Login::login_user()
{
	if (!user_n) { std::cout << "未有注册的用户账号" << endl; return; }
	int account_check = ACCOUNT_NO_FIND;//目标账号
	char Input[MAX_LENGTH] = {};
	int option = 0;
	
	current_user = USER_NONE;

	while (current_user == USER_NONE)
	{
		system("CLS");
		std::cout << "[登入]" << endl;
		if (account_check == ACCOUNT_NO_FIND)
		{
			std::cout << "账号: ";
			std::cin >> Input;
			account_check = checkAcount(Input);
			if (account_check == ACCOUNT_NO_FIND) { std::cout << "[错误]: 未有匹配的账号." << endl; system("PAUSE"); continue; }
		}
		else
		{
			std::cout << "账号: " << user_infor[account_check].account << endl;;
		}

		//Password
		std::cout << "密码: ";
		std::cin >> Input;
		if (Equal(Input, user_infor[account_check].password))current_user = account_check;
		else { std::cout << "[错误]: 密码不正确." << endl; }

		//Option
		if (current_user == USER_NONE)
		{
			std::cout << "[操作]" << endl;
			Line();
			std::cout << "0	重试密码[任意]" << endl;
			if(account_check != ACCOUNT_NO_FIND)std::cout << "1	更改账号" << endl;
			Line();
			std::cout << "操作: ";std::cin >> option;
			/*Control*/
			if (account_check != ACCOUNT_NO_FIND && option == 1)account_check = ACCOUNT_NO_FIND;
		}
	}
	std::cout << "[登入成功]" << endl;
	system("PAUSE");
	system("CLS");
}

void Pre_Infor(Pre pr)
{
	switch (pr)
	{
		case Pre::NORMAL:
			std::cout << "正常用户";
			break;

		case Pre::ADMINI:
			std::cout << "管理员";
			break;

		case Pre::PRE_COUNT:
			std::cout << "未知错误[截止]";
			break;

		default:
			std::cout << "未知错误";
			break;
	}
	std::cout << endl;
}

void Login::ShowInfor()
{
	Line();
	std::cout << "名称: " << user_infor[current_user].name << endl;
	std::cout << "权限: ";
	Pre_Infor(user_infor[current_user].premission);
	Line();
}

Pre Login::getpre()
{
	return user_infor[current_user].premission;
}

void Login::ShowUserList()
{
	std::cout << "[用户列表]" << endl;
	for (int y = 0; y < user_n; y++)
	{
		std::cout
			<< " [ " << y << " ]	"
			<< "名称: " << user_infor[y].name << "		"
			<< "账号: " << user_infor[y].account
			<< endl;
	}
}

//Modify
void Login::select()
{
	while (select_arm == ACCOUNT_NO_SELECT)
	{
		system("CLS");
		ShowUserList();
		std::cout << "选择账号: ";
		std::cin >> select_arm;
		if (select_arm<0 || select_arm>user_n)select_arm = ACCOUNT_NO_SELECT;
	}
}

void Login::show_c_select()
{
	std::cout << "[当前选择 : " <<'{' << select_arm << "} ]" << endl;
	std::cout << "名称: " << user_infor[select_arm].name << endl;
	std::cout << "账号: " << user_infor[select_arm].account << endl;
}

void Login::s_infor()
{
	std::cout << "名称: " << user_infor[select_arm].name << endl;
	std::cout << "账号: " << user_infor[select_arm].account << endl;
	std::cout << "密码: " << user_infor[select_arm].password << endl;
	std::cout << "权限: ";Pre_Infor(user_infor[current_user].premission);
}

void Login::changeLoginInfor(int Index)
{
	char cache[MAX_LENGTH] = { 0 };
	switch (Index)
	{
		//NAME
		case 0:
			std::cout << "修改名称: ";	cin >> cache;
			Copy(user_infor[select_arm].name, cache);
			user_infor[select_arm].name[MAX_LENGTH - 1] = '/0';
			break;

		//ACCOUNT
		case 1:
			std::cout << "修改账号: ";	cin >> cache;
			Copy(user_infor[select_arm].account, cache);
			user_infor[select_arm].account[MAX_LENGTH - 1] = '/0';
			break;

		//PASSWORD
		case 2:
			std::cout << "修改密码: ";	cin >> cache;
			Copy(user_infor[select_arm].password, cache);
			user_infor[select_arm].password[MAX_LENGTH - 1] = '/0';
			break;

		//NULL
		default:
			break;
	}
}

void Login::no_select()
{
	select_arm = ACCOUNT_NO_SELECT;
}




