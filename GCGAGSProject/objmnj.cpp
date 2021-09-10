#include<DxLib.h>
#include "Scene/sceneMng.h"
#include <vector>
#include "objmnj.h"

Objmnj* Objmnj::sInstance = nullptr;

void Objmnj::DrawNaw(void)
{
	//’Êí•¨‚ğ‚·‚×‚Ä•`‰æŒãAƒKƒ‰ƒX‚È‚Ç‚Ì“§‚¯‚½‚¢‚à‚Ì‚ğ•`‰æ‚·‚é
	//ˆê‚Â‚¸‚Â•`‰æ
	
	MV1SetSemiTransDrawMode(DX_SEMITRANSDRAWMODE_ALWAYS);
	for (auto dQue : drawList_)
	{
		DxLib::MV1DrawModel(dQue);
	}
	
	MV1SetSemiTransDrawMode(DX_SEMITRANSDRAWMODE_SEMITRANS_ONLY);
	
	//‚·‚¯‚é‚Ì‚ğ•`‰æ
	DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
	
	for (auto dQue : drawListnex_)
	{
		DxLib::MV1DrawModel(dQue);
	}

	DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Objmnj::ReSetD(void)
{
	drawList_.clear();
	drawListnex_.clear();
}

void Objmnj::Setobjpos(VECTOR pos, int mv1)
{
		DxLib::MV1SetPosition(mv1, pos);
}

void Objmnj::ObjDraw(int mv1)
{
	drawList_.emplace_back(mv1);
}

void Objmnj::ObjRotation(int mv1, float moveangle)
{
	DxLib::MV1SetRotationXYZ(mv1, VGet(0.0f, moveangle / 180.0f * DX_PI_F, 0.0f));
}

Objmnj::Objmnj()
{
}

Objmnj::~Objmnj()
{
}
