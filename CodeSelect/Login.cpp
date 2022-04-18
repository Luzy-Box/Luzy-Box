#include "Login.h"

void __stdcall Line()
{
	for (int y = 0; y < 10; y++)
		std::cout << "����";
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
	std::cout << "[���鳤��] : " << MAX_LENGTH << endl;
	//HAND
	std::cout << "[�����˺�]" << endl;
	char cache[MAX_LENGTH] = { 0 };
	std::cout << "����: "; std::cin >> cache;
	Copy(user_infor[user_n].name, cache);
	std::cout << "�˺�: "; std::cin >> cache;
	Copy(user_infor[user_n].account, cache);
	std::cout << "����: "; std::cin >> cache;
	Copy(user_infor[user_n].password, cache);

	std::cout << "[Ȩ��]" << endl;
	std::cout << "0	��ͨ�û�" << endl;
	std::cout << "1	����Ա" << endl;
	std::cout << "����: ";
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
		std::cout << "[ɾ���ɹ�]" << endl;
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
	if (!user_n) { std::cout << "δ��ע����û��˺�" << endl; return; }
	int account_check = ACCOUNT_NO_FIND;//Ŀ���˺�
	char Input[MAX_LENGTH] = {};
	int option = 0;
	
	current_user = USER_NONE;

	while (current_user == USER_NONE)
	{
		system("CLS");
		std::cout << "[����]" << endl;
		if (account_check == ACCOUNT_NO_FIND)
		{
			std::cout << "�˺�: ";
			std::cin >> Input;
			account_check = checkAcount(Input);
			if (account_check == ACCOUNT_NO_FIND) { std::cout << "[����]: δ��ƥ����˺�." << endl; system("PAUSE"); continue; }
		}
		else
		{
			std::cout << "�˺�: " << user_infor[account_check].account << endl;;
		}

		//Password
		std::cout << "����: ";
		std::cin >> Input;
		if (Equal(Input, user_infor[account_check].password))current_user = account_check;
		else { std::cout << "[����]: ���벻��ȷ." << endl; }

		//Option
		if (current_user == USER_NONE)
		{
			std::cout << "[����]" << endl;
			Line();
			std::cout << "0	��������[����]" << endl;
			if(account_check != ACCOUNT_NO_FIND)std::cout << "1	�����˺�" << endl;
			Line();
			std::cout << "����: ";std::cin >> option;
			/*Control*/
			if (account_check != ACCOUNT_NO_FIND && option == 1)account_check = ACCOUNT_NO_FIND;
		}
	}
	std::cout << "[����ɹ�]" << endl;
	system("PAUSE");
	system("CLS");
}

void Pre_Infor(Pre pr)
{
	switch (pr)
	{
		case Pre::NORMAL:
			std::cout << "�����û�";
			break;

		case Pre::ADMINI:
			std::cout << "����Ա";
			break;

		case Pre::PRE_COUNT:
			std::cout << "δ֪����[��ֹ]";
			break;

		default:
			std::cout << "δ֪����";
			break;
	}
	std::cout << endl;
}

void Login::ShowInfor()
{
	Line();
	std::cout << "����: " << user_infor[current_user].name << endl;
	std::cout << "Ȩ��: ";
	Pre_Infor(user_infor[current_user].premission);
	Line();
}

Pre Login::getpre()
{
	return user_infor[current_user].premission;
}

void Login::ShowUserList()
{
	std::cout << "[�û��б�]" << endl;
	for (int y = 0; y < user_n; y++)
	{
		std::cout
			<< " [ " << y << " ]	"
			<< "����: " << user_infor[y].name << "		"
			<< "�˺�: " << user_infor[y].account
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
		std::cout << "ѡ���˺�: ";
		std::cin >> select_arm;
		if (select_arm<0 || select_arm>user_n)select_arm = ACCOUNT_NO_SELECT;
	}
}

void Login::show_c_select()
{
	std::cout << "[��ǰѡ�� : " <<'{' << select_arm << "} ]" << endl;
	std::cout << "����: " << user_infor[select_arm].name << endl;
	std::cout << "�˺�: " << user_infor[select_arm].account << endl;
}

void Login::s_infor()
{
	std::cout << "����: " << user_infor[select_arm].name << endl;
	std::cout << "�˺�: " << user_infor[select_arm].account << endl;
	std::cout << "����: " << user_infor[select_arm].password << endl;
	std::cout << "Ȩ��: ";Pre_Infor(user_infor[current_user].premission);
}

void Login::changeLoginInfor(int Index)
{
	char cache[MAX_LENGTH] = { 0 };
	switch (Index)
	{
		//NAME
		case 0:
			std::cout << "�޸�����: ";	cin >> cache;
			Copy(user_infor[select_arm].name, cache);
			user_infor[select_arm].name[MAX_LENGTH - 1] = '/0';
			break;

		//ACCOUNT
		case 1:
			std::cout << "�޸��˺�: ";	cin >> cache;
			Copy(user_infor[select_arm].account, cache);
			user_infor[select_arm].account[MAX_LENGTH - 1] = '/0';
			break;

		//PASSWORD
		case 2:
			std::cout << "�޸�����: ";	cin >> cache;
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




