//==========================================================
// [updateComponent.h]
// �쐬:2022/02/13
//
//==========================================================
#ifndef __UPDATE_COMPONENT__
#define __UPDATE_COMPONENT__

//---�C���N���[�h��
#include "component.h"

//---�萔��`
#define NAME_UPDATE "�X�V"

//---�N���X��`
class CUpdateComponent:public CComponentBase
{
public:
	CUpdateComponent(CGameObject* owner);
	~CUpdateComponent();
	void Update();

protected:

};

#endif // !__UPDATE_COMPONENT__