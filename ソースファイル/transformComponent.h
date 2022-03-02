//==========================================================
// [transformComponent.h]
// 作成:2022/02/13
//
//==========================================================
#ifndef __TRANSFORM_COMPONENT__
#define __TRANSFORM_COMPONENT__

//---インクルード部
#include "component.h"

//---定数定義
#define NAME_TRANSFORM "情報"

//---構造体定義
struct Float3
{
	float x;
	float y;
	float z;
	Float3(float x1,float y1,float z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}
};
struct Float4
{
	float x;
	float y;
	float z;
	float w;
	Float4(float x1, float y1, float z1, float w1)
	{
		x = x1;
		y = y1;
		z = z1;
		w = w1;
	}
};

//---クラス定義
class CTransformComponent :public CComponentBase
{
public:
	CTransformComponent(CGameObject* owner);
	~CTransformComponent();
	void Update();// { printf("情報"); };

	void SetPos(Float3 pos) { m_vPos = pos; };
	void SetSize(Float3 size) { m_vSize = size; };
	void SetVel(Float3 vel) { m_vVel = vel; };
	void SetColor(Float4 col) { m_vColor = col; };
	Float3 GetPos() { return m_vPos; };
	Float3 GetVel() { return m_vVel; };
	Float3 GetSize() { return m_vSize; };
	Float4 GetColor() { return m_vColor; };
protected:
private:
	Float3 m_vPos;
	Float3 m_vVel;
	Float3 m_vSize;
	Float4 m_vColor;
};

#endif // !__TRANSFORM_COMPONENT__