//==========================================================
// [game.h]
// 作成:2022/02/13
//
//==========================================================
#ifndef __GAME_H__
#define __GAME_H__

//---インクルード部
#include "component.h"
#include <vector>

//---定数定義
#define GAME	CGame::Get()

//---前方参照
class CSceneBase;

//---クラス定義
class CGame
{

public:
	enum EScene
	{
		SCENE_NONE = 0,
		SCENE_TITLE,
		SCENE_GAME,
		MAX_SCENE,
	};
public:
	CGame();
	~CGame();
	void Init();
	void Update();
	bool RegComponent(CComponentBase* com);		// コンポーネントの登録
	CSceneBase* GetScene();
	void SetScene(EScene scene);
	
	static bool Start();
	static void End();
	static CGame* Get();
private:
	static CGame* m_pInstance;
	std::vector<CComponentBase*> m_pComponentManager;
	CSceneBase* m_pScene;
};

#endif // !__GAME__

