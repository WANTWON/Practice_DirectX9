#include "stdafx.h"
#include "Stage4.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "AbstractFactory.h"
#include "Player4.h"
#include "Monster4.h"

CStage4::CStage4()
{
}


CStage4::~CStage4()
{
	Release();
}

void CStage4::Initialize(void)
{
	
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer4>::Create(400, 500));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster4>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster4>::Create(200, 200));


}

int CStage4::Update(void)
{
	CObjMgr::Get_Instance()->Update();

	return 0;
}

void CStage4::Late_Update(void)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_MENU);
	}

	CObjMgr::Get_Instance()->Late_Update();
}

void CStage4::Release(void)
{
	CObjMgr::Get_Instance()->Destroy_Instance();

}

void CStage4::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);

	CObjMgr::Get_Instance()->Render(hDC);
}
