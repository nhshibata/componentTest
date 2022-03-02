//==========================================================
// [gameObject.cpp]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
#include "gameObject.h"
#include "game.h"
#include "scene.h"
#include "component.h"
#include <stdio.h>

//
CGameObject::CGameObject()
{
	printf("生成");
}
//
CGameObject::~CGameObject()
{
	COMPONENT::iterator it = m_pComponent.begin();

	// ここでメモリの破棄はしない
	// が、破棄待機状態にする
	while (it != m_pComponent.end())
	{
		(*it).second->SetState(CComponentBase::GS_ACTIVE);
		++it;
	}
	GAME->GetScene()->ReleaseObject(this);
	printf("\n破棄");
}
//
void CGameObject::Update()
{

}
// コンポーネントの登録
bool CGameObject::AddComponent(std::string comName, CComponentBase* com)
{
	// nullチェック
	if (!com)
	{
		return false;
	}
	// 名前が登録済みなら終了
	if (m_pComponent.find(comName) != m_pComponent.end())
	{
		return false;
	}
	// 登録
	m_pComponent.insert(COMPONENT_PIR(comName,com));
	return true;
}
// 文字列から特定のコンポーネントを取得
CComponentBase* CGameObject::GetComponent(std::string comName)
{
	return m_pComponent.at(comName);
}