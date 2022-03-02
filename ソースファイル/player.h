//==========================================================
// [player.h]
// 作成:2022/02/13
//
//==========================================================
#ifndef __PLAYER_H__
#define __PLAYER_H__

//---インクルード部
#include "gameObject.h"

//---定数定義
#define NAME_PLAYER	"プレイヤー"

//---前方参照

//---クラス定義
class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();
	void Update();

private:

};

#endif