//==========================================================
// [game.cpp]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
#include "game.h"
#include "scene.h"

//---�ÓI�����o�ϐ�
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

	// �R���|�[�l���g�N���X�̔j��
	for(std::vector<CComponentBase*>::iterator it = m_pComponentManager.begin(); it != m_pComponentManager.end(); ++it)
	{
		delete *it;
		// ����
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

	// �R���|�[�l���g�N���X�̍X�V
	while (it != m_pComponentManager.end())
	{
		// �X�V
		if ((*it)->GetState() == CComponentBase::GS_ACTIVE)
		{
			(*it)->Update();
		}
		// �폜
		if ((*it)->GetState() == CComponentBase::GS_DESTROY)
		{
			delete *it;
			it = m_pComponentManager.erase(it);
		}
		// ����
		++it;
	}
}
// �R���|�[�l���g�̓o�^
bool CGame::RegComponent(CComponentBase* com)
{
	// null�͂��Ȃ�
	if (!com)
		return false;
	m_pComponentManager.push_back(com);
	// �o�^��������
	return true;
}
// ���݃V�[���̎擾
CSceneBase* CGame::GetScene()
{
	return m_pScene;
}
// ���݃V�[���̔j��
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