//==========================================================
// [drawComponent.h]
// 作成:2022/02/13
//
//==========================================================
#ifndef __DRAW_COMPONENT__
#define __DRAW_COMPONENT__

//---インクルード部
#include "component.h"

//---定数定義
#define NAME_DRAW "描画"

//---クラス定義
class CDrawComponent :public CComponentBase
{
public:
	CDrawComponent(CGameObject* owner);
	~CDrawComponent();
	//void Update() { printf("描画"); };
	void Update();

protected:

};


#endif // !__DRAW_COMPONENT__