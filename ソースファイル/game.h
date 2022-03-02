//==========================================================
// [game.h]
// �쐬:2022/02/13
//
//==========================================================
#ifndef __GAME_H__
#define __GAME_H__

//---�C���N���[�h��
#include "component.h"
#include <vector>

//---�萔��`
#define GAME	CGame::Get()

//---�O���Q��
class CSceneBase;

//---�N���X��`
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
	bool RegComponent(CComponentBase* com);		// �R���|�[�l���g�̓o�^
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

