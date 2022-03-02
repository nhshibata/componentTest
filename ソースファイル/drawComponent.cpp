//==========================================================
// [drawComponent.h]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
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
	printf("transformComponet������W�擾\n"); 
	printf("���W %.1f %.1f %.1f",pos.x,pos.y,pos.z); 
	printf("�`��"); 
}
