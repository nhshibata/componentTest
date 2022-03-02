//==========================================================
// [component.h]
// 作成:2022/02/13
//
//==========================================================
/*
	全てのオブジェクトが持つｸﾗｽ
	3つの状態をメインに教えることでふるまいを変える

*/
#ifndef __COMPONENT__
#define __COMPONENT__

//---インクルード部
#include "gameObject.h"
//#include <stdio.h>
//#include <string>

//---列挙体定義


//---クラス定義
class CComponentBase
{
public:
	enum EGameState		// コンポーネント更新状態
	{
		GS_ACTIVE = 0,		// 更新状態
		GS_WAIT,			// 待機状態
		GS_DESTROY,			// 削除申請
		GS_TAKEOVER,		// 引き継ぎ
		MAX_GAME_STATE		// 最大数
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
	CGameObject* m_pOwner;		// 持ち主
	std::string m_Name;
};


#endif // !__COMPONENT__