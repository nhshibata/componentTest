//==========================================================
// [updateComponent.h]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
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
	printf("\n更新");
}