#pragma once
#include "BaseScene.h"
#include "../common/Vector2.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	
	static SceneMng& GetInstance(void)
	{
		
		Create();
		return *sInstance;
	}
	
	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMng();
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

	int GetFcon(void) 
	{
		return fcon_; 
	}

	void Run(void);									//実行処理

	const Vector2 ScreenSize;						//画面サイズ

	void GameEnd(void);

	void SetLight(int num);

	VECTOR campos_;

private:

	int lightC_;

	int fcon_;										//フレームカウント
	static SceneMng* sInstance;						//シーンマネージャーの静的な宣言
	bool SysInit();									//初期化
	UNBS activeScene_;						//今動いてるsceneが入る。

	void Draw(void);								//描画処理
	SceneMng();
	~SceneMng(); 
	
	int lightHandle_;								//あかり1カメラ追跡ライト

};

