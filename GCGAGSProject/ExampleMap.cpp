#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <math.h>
#include <DxLib.h>
#include "objmnj.h"
#include "ExampleMap.h"

/*
	3Dモデルを描画するにあたって必要な関数の使用例です。
	描画するにあたって参考にしてください。
*/

ExampleMap::ExampleMap()
{
	//モデルデータ読み込み
	soraDate_ = lpobjlMng.LoadModel("sora.mv1");
	sorairoDate_ = lpobjlMng.LoadModel("sorairo1.52.mv1");
	minaMainDate_ = lpobjlMng.LoadModel("mato.x");

	//複数体出したりするときは、コピーを使用する
	minaTestDate_ = lpobjlMng.CopyModel(minaMainDate_);

	//座標を設定
	lpobjlMng.Setobjpos(soraDate_, VGet(0.0f, 0.0f, 0.0f));
	lpobjlMng.Setobjpos(sorairoDate_, VGet(0.0f, -1.05f, 0.0f));
	lpobjlMng.Setobjpos(minaMainDate_, VGet(0.0f, 0.0f, 0.0f));
	lpobjlMng.Setobjpos(minaTestDate_, VGet(2.0f, -0.92f, -8.0f));

	//モデルの拡縮設定
	lpobjlMng.SetScale(minaTestDate_, VGet(0.008f, 0.008f, 0.008f));

	minaRotaPoint_ = 0;
}

ExampleMap::~ExampleMap()
{
	//使用しなくなったときは削除する。
	lpobjlMng.DeleteModel(soraDate_);
	lpobjlMng.DeleteModel(sorairoDate_);
	lpobjlMng.DeleteModel(minaMainDate_);
	lpobjlMng.DeleteModel(minaTestDate_);

}

void ExampleMap::Update()
{
	//モデルを回転させる
	lpobjlMng.SetRotation(minaTestDate_, minaRotaPoint_);

	//モデルの描画要求
	lpobjlMng.ObjDraw(soraDate_);
	lpobjlMng.ObjDraw(sorairoDate_);
	lpobjlMng.ObjDraw(minaTestDate_);

	minaRotaPoint_ += DX_PI_F / 10;
}
