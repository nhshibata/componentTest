//==========================================================
// [gameObject.h]
// 作成:2022/02/13
//
//==========================================================
#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

//---インクルード部
#include <string>
#include <map>

//---前方参照
class CComponentBase;

//---クラス定義
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Update();
	bool AddComponent(std::string comName, CComponentBase* com);	// コンポーネントの登録
	CComponentBase* GetComponent(std::string comName);				// コンポーネントの取得
protected:
	//---再定義
	using COMPONENT = std::map<std::string, CComponentBase*>;
	using COMPONENT_PIR = std::pair<std::string, CComponentBase*>;
protected:

	COMPONENT m_pComponent;
private:
};


#endif // !__GAME_OBJECT__


