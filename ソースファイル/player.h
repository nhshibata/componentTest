//==========================================================
// [player.h]
// �쐬:2022/02/13
//
//==========================================================
#ifndef __PLAYER_H__
#define __PLAYER_H__

//---�C���N���[�h��
#include "gameObject.h"

//---�萔��`
#define NAME_PLAYER	"�v���C���["

//---�O���Q��

//---�N���X��`
class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();
	void Update();

private:

};

#endif