//==========================================================
// [updateComponent.h]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
#include "updateComponent.h"

//
CUpdateComponent::CUpdateComponent(CGameObject* owner) :CComponentBase(NAME_UPDATE, owner)
{
};
CUpdateComponent::~CUpdateComponent()
{

}
//
void CUpdateComponent::Update()
{
	printf("\n�X�V");
}