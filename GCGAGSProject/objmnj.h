#pragma once
#define CPU_MAX 9
#include "obj.h"


//#define CHARA_MAX_HITCOLL			2048		// 処理するコリジョンポリゴンの最大数
//#define CHARA_ENUM_DEFAULT_SIZE		3000.0f		// 周囲のポリゴン検出に使用する球の初期サイズ
//#define CHARA_HIT_WIDTH				3000.0f		// 当たり判定カプセルの半径
//#define CHARA_HIT_HEIGHT			1000.0f		// 当たり判定カプセルの高さ
//#define CHARA_HIT_PUSH_POWER		40.0f		// キャラクター同士で当たったときの押し出される力

#define lpobjlMng Objmnj::GetInstance()


//モデル管理マネージャ
class Objmnj
{
public:
	static Objmnj& GetInstance(void)
	{

		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new Objmnj();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}
	
	void DrawNaw(void);

	void ReSetD(void);	//毎フレーム最初に呼ぶ

	void Setobjpos(VECTOR pos,int mv1);	//位置情報をセット					

	void ObjDraw(int mv1);								//これを呼ぶと、描画要求を、sceneマネージャにします

	void ObjRotation(int mv1,float moveangle);			//回転情報（見た目）をセット

	//bool ObjCollHit(VECTOR pos, UNIT_ID id);		//当たり判定チェック用

private:
	static Objmnj* sInstance;


	std::vector<int> drawList_;						//描画するものを溜めておくキュー
	std::vector<int> drawListnex_;					//描画するものを溜めておくキュー（すける）

	Objmnj();
	~Objmnj();
};

