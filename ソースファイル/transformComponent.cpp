//==========================================================
// [transformComponent.h]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
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
	printf("���W%.2f %.2f %.2f", m_vPos.x, m_vPos.y, m_vPos.z);
	printf("�ړ�%.2f %.2f %.2f", m_vVel.x, m_vVel.y, m_vVel.z);
	printf("�g�k%.2f %.2f %.2f", m_vSize.x, m_vSize.y, m_vSize.z);
	printf("�F %.2f %.2f %.2f %.2f", m_vColor.x, m_vColor.y, m_vColor.z, m_vColor.w);

	printf("���");
}
