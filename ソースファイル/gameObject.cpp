//==========================================================
// [gameObject.cpp]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
#include "gameObject.h"
#include "game.h"
#include "scene.h"
#include "component.h"
#include <stdio.h>

//
CGameObject::CGameObject()
{
	printf("����");
}
//
CGameObject::~CGameObject()
{
	COMPONENT::iterator it = m_pComponent.begin();

	// �����Ń������̔j���͂��Ȃ�
	// ���A�j���ҋ@��Ԃɂ���
	while (it != m_pComponent.end())
	{
		(*it).second->SetState(CComponentBase::GS_ACTIVE);
		++it;
	}
	GAME->GetScene()->ReleaseObject(this);
	printf("\n�j��");
}
//
void CGameObject::Update()
{

}
// �R���|�[�l���g�̓o�^
bool CGameObject::AddComponent(std::string comName, CComponentBase* com)
{
	// null�`�F�b�N
	if (!com)
	{
		return false;
	}
	// ���O���o�^�ς݂Ȃ�I��
	if (m_pComponent.find(comName) != m_pComponent.end())
	{
		return false;
	}
	// �o�^
	m_pComponent.insert(COMPONENT_PIR(comName,com));
	return true;
}
// �����񂩂����̃R���|�[�l���g���擾
CComponentBase* CGameObject::GetComponent(std::string comName)
{
	return m_pComponent.at(comName);
}