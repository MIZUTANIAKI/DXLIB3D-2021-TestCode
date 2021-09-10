#include <time.h>
#include <DxLib.h>
#include <vector>
#include <memory>
#include "GameScene.h"
#include "SceneMng.h"

GameScene::GameScene()
{
	SetWindowText("::ÉQÅ[ÉÄ");
	srand((unsigned)time(NULL));
	scnID_ = SCN_ID::SCN_GAME;

	{
		SetFogColor(100, 100, 100);
	}
	camera_ = std::make_unique<Cam>();
}

UNBS GameScene::Update(UNBS own)
{
	camera_->Update();

	return std::move(own);
}


GameScene::~GameScene()
{
}

void GameScene::Draw(void)
{
	DrawCube3D(VGet(-100, 0, -100), VGet(100, 0, 100), 0x0000ff, 0x0000ff, true);
	DrawSphere3D(VGet(0, 0, 0), 2, 2, 0xff, 0xff, true);
	camera_->Draw();
}

SCN_ID GameScene::GetSCNID_(void)
{
	return scnID_;
}

