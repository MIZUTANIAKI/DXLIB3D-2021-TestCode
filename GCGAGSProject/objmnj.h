#pragma once
//#define CPU_MAX 9


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
	
	/// <summary>
	/// モデルを一斉描画させる。メインループで読んでる場合触らないでOK
	/// </summary>
	/// <param name=""></param>
	void DrawNaw(void);

	/// <summary>
	/// 毎フレーム最初に呼ぶんですが、メインループで読んでる場合触らないでOK
	/// </summary>
	/// <param name=""></param>
	void ReSetD(void);

	/// <summary>
	/// 3Dモデルの位置情報を設定できます！
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="mv1">mv1モデルのハンドル</param>
	void Setobjpos(VECTOR pos,int mv1);	//位置情報をセット					

	/// <summary>
	/// 3Dモデル描画させる！
	/// </summary>
	/// <param name="mv1">mv1モデルのハンドル</param>
	void ObjDraw(int mv1);

	/// <summary>
	/// MV1モデルを回転させますよー
	/// </summary>
	/// <param name="mv1">mv1モデルのハンドル</param>
	/// <param name="moveangle">角度ください。</param>
	void ObjRotation(int mv1,float moveangle);

	//bool ObjCollHit(VECTOR pos, UNIT_ID id);		//当たり判定チェック用　だったんですけどーだったというか作ってないですねー

private:
	static Objmnj* sInstance;


	std::vector<int> drawList_;						//描画するものを溜めておくキュー
	//std::vector<int> drawListnex_;					//描画するものを溜めておくキュー（すける）

	Objmnj();
	~Objmnj();
};

