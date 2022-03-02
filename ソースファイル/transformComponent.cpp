//==========================================================
// [transformComponent.h]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
#include "transformComponent.h"

//
CTransformComponent::CTransformComponent(CGameObject* owner) 
	:CComponentBase(NAME_TRANSFORM, owner),m_vPos(2,3,4),m_vVel(0,0,0),m_vSize(1,1,1),m_vColor(1,1,1,1)
{
}
//
CTransformComponent::~CTransformComponent()
{

}
void CTransformComponent::Update()
{
	printf("\n");
	printf("座標%.2f %.2f %.2f", m_vPos.x, m_vPos.y, m_vPos.z);
	printf("移動%.2f %.2f %.2f", m_vVel.x, m_vVel.y, m_vVel.z);
	printf("拡縮%.2f %.2f %.2f", m_vSize.x, m_vSize.y, m_vSize.z);
	printf("色 %.2f %.2f %.2f %.2f", m_vColor.x, m_vColor.y, m_vColor.z, m_vColor.w);

	printf("情報");
}
