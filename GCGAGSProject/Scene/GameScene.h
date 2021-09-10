#pragma once
#include "BaseScene.h"
#include "../Obj.h"
#include "../Cam.h"

class GameScene :
	public BaseScene
{
public:
	UNBS Update(UNBS own) override;
	GameScene();
	~GameScene();
	void Draw(void)override;
	SCN_ID GetSCNID_(void)override;
private:
	std::unique_ptr<Cam> camera_;		//ƒJƒƒ‰Ši”[æ
};

