#include <vector>
#include <tuple>
#include <DxLib.h>
#include "sceneMng.h"
#include "GameScene.h"
#include "../objmnj.h"


SceneMng* SceneMng::sInstance = nullptr;


SceneMng::SceneMng() :ScreenSize{500,500}
{
	SetWindowText("起動");

	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetCreate3DSoundFlag(true);
	SetFontSize(60);
	SetBackgroundColor(100, 255, 255);
	SetUseZBufferFlag(TRUE);
	SetCameraNearFar(0.1f, 1000.0f);
	SetMouseDispFlag(false);	//マウスを非表示に
	SetLightDifColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	SetLightAmbColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));

	fcon_ = 0;


	SetFogEnable(TRUE); 
	SetFogStartEnd(1500.0f, 40000.0f);
	
	lpobjlMng.Create();
}

SceneMng::~SceneMng()
{
}

void SceneMng::Draw(void)
{
	DxLib::ClsDrawScreen();
	activeScene_->Draw();
	
	lpobjlMng.DrawNaw();

	DxLib::ScreenFlip();
}

void SceneMng::Run(void)
{
	activeScene_ = std::make_unique<GameScene>();

	fcon_ = NULL;
	while (ProcessMessage() == 0&&CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		lpobjlMng.ReSetD();
		//for (int i = 0; i < 2; i++)
		{
			activeScene_ = (*activeScene_).Update(std::move(activeScene_));
		}

		Draw();
		fcon_++;
	}
}

bool SceneMng::SysInit(void)
{
	return true;
}

