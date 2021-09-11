#include <time.h>
#include <DxLib.h>
#include <vector>
#include <memory>
#include "../ExampleMap.h"
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

	exampleMap = new ExampleMap;
}

UNBS GameScene::Update(UNBS own)
{
	camera_->Update();
	exampleMap->Update();

	return std::move(own);
}


GameScene::~GameScene()
{
	delete exampleMap;
}

void GameScene::Draw(void)
{
	DrawCube3D(VGet(-100, -20, -100), VGet(100, -50, 100), 0xaf00ff, 0xaf00ff, true);

	camera_->Draw();
}

SCN_ID GameScene::GetSCNID_(void)
{
	return scnID_;
}

