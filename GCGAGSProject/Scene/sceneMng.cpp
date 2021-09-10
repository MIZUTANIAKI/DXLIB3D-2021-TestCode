#include <vector>
#include <tuple>
#include <DxLib.h>
#include "sceneMng.h"
#include "GameScene.h"
#include "../objmnj.h"


SceneMng* SceneMng::sInstance = nullptr;


SceneMng::SceneMng() :ScreenSize{500,500}
{
	SetWindowText("�N��");

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
	SetMouseDispFlag(false);	//�}�E�X���\����
	SetLightDifColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	SetLightAmbColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));

	fcon_ = 0;
	campos_ = VGet(0.0f, 0.0f, 0.0f);
	lightC_ = 0;


	SetFogEnable(TRUE); 
	SetFogStartEnd(1500.0f, 40000.0f);
	lightHandle_ = CreateDirLightHandle(VGet(0.0f, -1.0f, 0.0f));
	
	lpobjlMng.Create();
}

SceneMng::~SceneMng()
{
}

void SceneMng::GameEnd(void)
{
}

void SceneMng::SetLight(int num)
{
	int tm = 255 - num;
	if (tm > 255)
	{
		tm = 255;
	}
	if (tm < 0)
	{
		tm = 0;
	}
	lightC_ = tm;
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
		//for (int i = 0; i < 2; i++)
		{
			//SetLightDirectionHandle(lightHandle_, campos_);
			SetLightPositionHandle(lightHandle_, campos_);

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
