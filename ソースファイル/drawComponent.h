//==========================================================
// [drawComponent.h]
// �쐬:2022/02/13
//
//==========================================================
#ifndef __DRAW_COMPONENT__
#define __DRAW_COMPONENT__

//---�C���N���[�h��
#include "component.h"

//---�萔��`
#define NAME_DRAW "�`��"

//---�N���X��`
class CDrawComponent :public CComponentBase
{
public:
	CDrawComponent(CGameObject* owner);
	~CDrawComponent();
	//void Update() { printf("�`��"); };
	void Update();

protected:

};


#endif // !__DRAW_COMPONENT__