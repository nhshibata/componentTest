//==========================================================
// [gameObject.h]
// �쐬:2022/02/13
//
//==========================================================
#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

//---�C���N���[�h��
#include <string>
#include <map>

//---�O���Q��
class CComponentBase;

//---�N���X��`
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Update();
	bool AddComponent(std::string comName, CComponentBase* com);	// �R���|�[�l���g�̓o�^
	CComponentBase* GetComponent(std::string comName);				// �R���|�[�l���g�̎擾
protected:
	//---�Ē�`
	using COMPONENT = std::map<std::string, CComponentBase*>;
	using COMPONENT_PIR = std::pair<std::string, CComponentBase*>;
protected:

	COMPONENT m_pComponent;
private:
};


#endif // !__GAME_OBJECT__


