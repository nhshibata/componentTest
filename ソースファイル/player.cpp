//==========================================================
// [player.cpp]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
#include "game.h"
#include "player.h"
#include "updateComponent.h"
#include "transformComponent.h"
#include "drawComponent.h"

//
CPlayer::CPlayer()
{
	std::vector<CComponentBase*> com;
	std::vector<CComponentBase*>::iterator it;

	com.push_back(new CUpdateComponent(this));
	com.push_back(new CDrawComponent(this));
	com.push_back(new CTransformComponent(this));

	for(it = com.begin(); it < com.end(); ++it)
	{
		m_pComponent.insert(COMPONENT_PIR((*it)->GetName(),*it));
		GAME->RegComponent(*it);
	}
}
//
CPlayer::~CPlayer()
{
	//CGameObject::~CGameObject();
}
//
void CPlayer::Update()
{

}
