//==========================================================
// [scene.h]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
#include "scene.h"
#include "gameObject.h"
#include "player.h"

//
CSceneBase::CSceneBase()	//:m_pObject(0)
{
	// オブジェクトを生成する
	//m_pObject.push_back(new CGameObject());
	CPlayer* player = new CPlayer();
	// オブジェクトを追加
	AddObject(NAME_PLAYER, player);
	//printf("new");
}
//
CSceneBase::~CSceneBase()
{
	// ゲームオブジェクト破棄
	// デストラクタでコンポーネント破棄を呼び出す
	for (std::map<std::string, CGameObject*>::iterator it = m_pObject.begin(); it != m_pObject.end();++it)
	{
		delete (*it).second;
		//it = m_pObject.erase(it);
	}
}
//
void CSceneBase::Update()
{
	std::map<std::string, CGameObject*>::iterator it = m_pObject.begin(); 
	while (it != m_pObject.end())
	{
		(*it).second->Update();
		++it;
	}
}
// オブジェクトが外部で生成されたときに追加する関数
// ポインタとしてメンバ変数が保持
bool CSceneBase::AddObject(std::string name, CGameObject* obj)
{
	// nullチェック
	if (!obj)
	{
		return false;
	}
	// 追加
	m_pObject.insert(GAMEOBJECT_PAIR(name,obj));

	return true;
}
//
void CSceneBase::ReleaseObject(CGameObject* obj)
{
	GAMEOBJECT::iterator it = m_pObject.begin();
	// 探索
	while (it != m_pObject.end())
	{
		if ((*it).second == obj)
		{
			delete (*it).second;
			break;
		}
		++it;
	}
}
// オブジェクトの取得
CGameObject* CSceneBase::GetObject(std::string name)
{
	return m_pObject.at(name);
}