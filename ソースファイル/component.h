//==========================================================
// [component.h]
// �쐬:2022/02/13
//
//==========================================================
/*
	�S�ẴI�u�W�F�N�g�����¸׽
	3�̏�Ԃ����C���ɋ����邱�Ƃłӂ�܂���ς���

*/
#ifndef __COMPONENT__
#define __COMPONENT__

//---�C���N���[�h��
#include "gameObject.h"
//#include <stdio.h>
//#include <string>

//---�񋓑̒�`


//---�N���X��`
class CComponentBase
{
public:
	enum EGameState		// �R���|�[�l���g�X�V���
	{
		GS_ACTIVE = 0,		// �X�V���
		GS_WAIT,			// �ҋ@���
		GS_DESTROY,			// �폜�\��
		GS_TAKEOVER,		// �����p��
		MAX_GAME_STATE		// �ő吔
	};
public:
	CComponentBase(CGameObject* owner):m_pOwner(owner), m_eState(GS_ACTIVE)
	{};
	CComponentBase(std::string name, CGameObject* owner):m_Name(name ), m_pOwner(owner), m_eState(GS_ACTIVE)
	{};
	virtual ~CComponentBase()
	{};
	virtual void Update() = 0;
	EGameState GetState() { return m_eState; };
	void SetState(EGameState state) { m_eState = state; };
	std::string GetName() { return m_Name; };
protected:
	EGameState m_eState;
	CGameObject* m_pOwner;		// ������
	std::string m_Name;
};


#endif // !__COMPONENT__