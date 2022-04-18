#include "Coder.h"
#include "Order.h"

void InitData(Coder* pt);

int main()
{
    Coder* pt = new Coder;
    getp(pt);
    InitUser();
    InitData(pt);
    pt->Init();
    pt->work();

    delete pt;
    return 0;
}

/*TREE CODE*/
void InitData(Coder* pt)
{
    //LOGIN [JUMP NODE]
    pt->SetNode((int)(NODE::LOGIN), login_in);
    pt->SetNode((int)(NODE::LOGIN), 
        Select{ "NI",(int)(NODE::USER_MENU) }, 
        Select{ "\0",0 }
    );

    //ADMIN
    pt->SetNode((int)(NODE::ADMIN_MEUN), current_infor);
    pt->SetNode((int)(NODE::ADMIN_MEUN),
        Select{ "用户信息管理",(int)(NODE::USER_M) },
        Select{ "平台信息管理",(int)(NODE::PLATE_M) },
        Select{ "PREV-LOG",(int)(NODE::LOGIN) },
        Select{ "\0",0 }
    );

    //用户信息管理
    pt->SetNode((int)(NODE::USER_M), current_infor);
    pt->SetNode((int)(NODE::USER_M),
        Select{ "用户账号列表",(int)(NODE::USER_LIST) },
        Select{ "修改账号",(int)(NODE::SELECT_USER) },
        Select{ "添加账号",(int)(NODE::ADD_USER) },
        Select{ "菜单",(int)(NODE::ADMIN_MEUN) },
        Select{ "\0",0 }
    );

    pt->SetNode((int)(NODE::ADD_USER), addAccount);

    pt->SetNode((int)(NODE::SELECT_USER), selectAccount);
    pt->SetNode((int)(NODE::SELECT_USER),
        Select{ "查看当前用户信息",(int)(NODE::USER_INFOR) },
        Select{ "更改选择",(int)(NODE::NO_SELECT) },
        Select{ "修改名称",(int)(NODE::CHANG_NAME) },
        Select{ "修改账号",(int)(NODE::CHANG_ACCOUNT) },
        Select{ "修改密码",(int)(NODE::CHANG_PASSWORD) },
        Select{ "更改权限",(int)(NODE::SELECT_USER) },
        Select{ "删除账号",(int)(NODE::CHANG_PRE) },
        Select{ "返回菜单",(int)(NODE::ADMIN_MEUN) },
        Select{ "\0",0 }
    );

    pt->SetNode((int)(NODE::REMOVE_USER), removeAccount);
    pt->SetNode((int)(NODE::USER_LIST), userlist);
    pt->SetNode((int)(NODE::USER_INFOR), selectInfor);
    pt->SetNode((int)(NODE::CHANG_NAME), changName);
    pt->SetNode((int)(NODE::CHANG_ACCOUNT), changAccount);
    pt->SetNode((int)(NODE::CHANG_PASSWORD), changPassword);
    pt->SetNode((int)(NODE::NO_SELECT), cancel_arm);

    //平台信息管理
    pt->SetNode((int)(NODE::PLATE_M),
        Select{ "用户信息管理",1 },
        Select{ "平台信息管理",1 },
        Select{ "菜单",(int)(NODE::USER_MENU) },
        Select{ "\0",0 }
    );

    //USER
    pt->SetNode((int)(NODE::USER_MENU),
        Select{ "平台",1 },
        Select{ "用户中心",1 },
        Select{ "PREV-USER",(int)(NODE::LOGIN) },
        Select{ "\0",0 }
    );



}
