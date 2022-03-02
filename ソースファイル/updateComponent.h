//==========================================================
// [updateComponent.h]
// 作成:2022/02/13
//
//==========================================================
#ifndef __UPDATE_COMPONENT__
#define __UPDATE_COMPONENT__

//---インクルード部
#include "component.h"

//---定数定義
#define NAME_UPDATE "更新"

//---クラス定義
class CUpdateComponent:public CComponentBase
{
public:
	CUpdateComponent(CGameObject* owner);
	~CUpdateComponent();
	void Update();

protected:

};

#endif // !__UPDATE_COMPONENT__