//==========================================================
// [scene.h]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
#include "scene.h"
#include "gameObject.h"
#include "player.h"

//
CSceneBase::CSceneBase()	//:m_pObject(0)
{
	// �I�u�W�F�N�g�𐶐�����
	//m_pObject.push_back(new CGameObject());
	CPlayer* player = new CPlayer();
	// �I�u�W�F�N�g��ǉ�
	AddObject(NAME_PLAYER, player);
	//printf("new");
}
//
CSceneBase::~CSceneBase()
{
	// �Q�[���I�u�W�F�N�g�j��
	// �f�X�g���N�^�ŃR���|�[�l���g�j�����Ăяo��
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
// �I�u�W�F�N�g���O���Ő������ꂽ�Ƃ��ɒǉ�����֐�
// �|�C���^�Ƃ��ă����o�ϐ����ێ�
bool CSceneBase::AddObject(std::string name, CGameObject* obj)
{
	// null�`�F�b�N
	if (!obj)
	{
		return false;
	}
	// �ǉ�
	m_pObject.insert(GAMEOBJECT_PAIR(name,obj));

	return true;
}
//
void CSceneBase::ReleaseObject(CGameObject* obj)
{
	GAMEOBJECT::iterator it = m_pObject.begin();
	// �T��
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
// �I�u�W�F�N�g�̎擾
CGameObject* CSceneBase::GetObject(std::string name)
{
	return m_pObject.at(name);
}