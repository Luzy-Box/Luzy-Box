#include "Order.h"

void cls() { system("CLS"); }

System_L Data;
Coder* node;

void login_in() 
{
	Data.user->login_user();
	if (Data.user->getpre() == Pre::NORMAL)
		node->SetNode((int)(NODE::LOGIN), (int)(NODE::USER_MENU));
	else if (Data.user->getpre() == Pre::ADMINI)
		node->SetNode((int)(NODE::LOGIN), (int)(NODE::ADMIN_MEUN));
}
void current_infor() { Data.user->ShowInfor(); }
void userlist() { Data.user->ShowUserList(); system("PAUSE"); }

void selectAccount()
{
	Data.user->select();
	system("CLS");
	Data.user->show_c_select();
}

void selectInfor() { Data.user->s_infor(); system("PAUSE"); }
void cancel_arm() { Data.user->no_select(); }

void addAccount(){Data.user->AddNewUser();}
void removeAccount(){Data.user->RemoveUser();}

void changName() { Data.user->changeLoginInfor(0); }
void changAccount() { Data.user->changeLoginInfor(1); }
void changPassword() { Data.user->changeLoginInfor(2); }

void quit() { node->quit(); }

void getp(Coder* p) { node = p; }

void InitUser()
{
	//LOGIN INFOR
	Data.user->AddNewUser("Admin", "A", "135", Pre::ADMINI);
	Data.user->AddNewUser("One", "123", "123", Pre::NORMAL);
	Data.user->AddNewUser("Two", "TWO", "123", Pre::NORMAL);
	Data.user->AddNewUser("Three", "S", "123", Pre::NORMAL);
	Data.user->AddNewUser("Four", "Shi", "123", Pre::NORMAL);
	Data.user->AddNewUser("看不见", "废物", "five", Pre::NORMAL);
}

