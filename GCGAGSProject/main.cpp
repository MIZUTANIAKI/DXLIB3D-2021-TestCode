#include <DxLib.h>
#include "Scene/sceneMng.h"

/* ｘ64 */

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(true);										//フルスクリーン
	if (DxLib_Init() == -1)										//DXﾗｲﾌﾞﾗﾘの初期化処理
	{
		return false;
	}

	SetUseDirect3DVersion(DX_DIRECT3D_11);
	
	SceneMng::Create();
	SceneMng::GetInstance().Run();
 	SceneMng::GetInstance().Destroy();

	DxLib_End();
	return 0;
}