//==========================================================
// [drawComponent.h]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
#include "drawComponent.h"
#include "transformComponent.h"

//
CDrawComponent::CDrawComponent(CGameObject* owner) :CComponentBase(NAME_DRAW, owner)
{

}
//
CDrawComponent::~CDrawComponent()
{

}
void CDrawComponent::Update()
{ 
	CTransformComponent* com = (CTransformComponent*)m_pOwner->GetComponent(NAME_TRANSFORM);
	Float3 pos = com->GetPos();
	printf("\n"); 
	printf("transformComponetから座標取得\n"); 
	printf("座標 %.1f %.1f %.1f",pos.x,pos.y,pos.z); 
	printf("描画"); 
}
