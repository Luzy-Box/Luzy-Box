#pragma once
#include "System_L.h"
#include "Coder.h"

enum class NODE
{
	LOGIN = 0,//DEFAULT ENTRY POINT
	USER_MENU,
	ADMIN_MEUN,//Administration

	USER_M,
	USER_LIST,

	SELECT_USER,
	NO_SELECT,
	USER_INFOR,//当前选中对象
	MODIFY_USER,

	ADD_USER,
	REMOVE_USER,

	CHANG_NAME,
	CHANG_ACCOUNT,
	CHANG_PASSWORD,
	CHANG_PRE,

	PLATE_M,
};

void quit();

void getp(Coder* p);
void InitUser();

void login_in();
void current_infor();

void userlist();
void cancel_arm();
void selectAccount();
void selectInfor();

void addAccount();
void removeAccount();

void changName();
void changAccount();
void changPassword();

