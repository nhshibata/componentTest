//==========================================================
// [scene.h]
// �쐬:2022/02/13
//
//==========================================================

//---�C���N���[�h��
#include <map>

//---�O���Q��
class CGameObject;

//---�N���X��`
class CSceneBase
{
public:
	CSceneBase();
	~CSceneBase();
	virtual void Update();
	bool AddObject(std::string name, CGameObject* object);
	void ReleaseObject(CGameObject* obj);
	CGameObject* GetObject(std::string name);
protected:
	using GAMEOBJECT = std::map<std::string, CGameObject*>;
	using GAMEOBJECT_PAIR = std::pair<std::string, CGameObject*>;
	GAMEOBJECT m_pObject;

private:	

};