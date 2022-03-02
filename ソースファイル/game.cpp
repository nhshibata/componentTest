//==========================================================
// [game.cpp]
// 作成:2022/02/13
//
//==========================================================

//---インクルード部
#include "game.h"
#include "scene.h"

//---静的メンバ変数
CGame* CGame::m_pInstance;

//
CGame::CGame()//:m_pComponentManager(0)
{
}
CGame::~CGame()
{
	if (m_pScene)
	{
		delete m_pScene;
	}

	// コンポーネントクラスの破棄
	for(std::vector<CComponentBase*>::iterator it = m_pComponentManager.begin(); it != m_pComponentManager.end(); ++it)
	{
		delete *it;
		// 次へ
	}
	m_pComponentManager.clear();
}
void CGame::Init()
{
	m_pScene = new CSceneBase(); 
};
//
void CGame::Update()
{
	std::vector<CComponentBase*>::iterator it = m_pComponentManager.begin();

	m_pScene->Update();

	// コンポーネントクラスの更新
	while (it != m_pComponentManager.end())
	{
		// 更新
		if ((*it)->GetState() == CComponentBase::GS_ACTIVE)
		{
			(*it)->Update();
		}
		// 削除
		if ((*it)->GetState() == CComponentBase::GS_DESTROY)
		{
			delete *it;
			it = m_pComponentManager.erase(it);
		}
		// 次へ
		++it;
	}
}
// コンポーネントの登録
bool CGame::RegComponent(CComponentBase* com)
{
	// nullはしない
	if (!com)
		return false;
	m_pComponentManager.push_back(com);
	// 登録を教える
	return true;
}
// 現在シーンの取得
CSceneBase* CGame::GetScene()
{
	return m_pScene;
}
// 現在シーンの破棄
void CGame::SetScene(EScene scene)
{
	if (m_pScene)
	{
		delete m_pScene;
	}

	switch (scene)
	{
	case CGame::SCENE_NONE:
		m_pScene = new CSceneBase();
		break;
	case CGame::SCENE_TITLE:
		break;
	case CGame::SCENE_GAME:
		break;
	case CGame::MAX_SCENE:
		break;
	default:
		break;
	}
}
bool CGame::Start()
{
	
	m_pInstance = new CGame();
	if (!m_pInstance)
	{
		return false;
	}
	return true;
}
void CGame::End()
{
	delete m_pInstance;
}
CGame* CGame::Get()
{
	return m_pInstance;
}