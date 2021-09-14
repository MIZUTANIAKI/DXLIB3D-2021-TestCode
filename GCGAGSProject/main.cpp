#include <DxLib.h>
#include "Scene/sceneMng.h"

/* ��64 */

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(true);										//�t���X�N���[��
	if (DxLib_Init() == -1)										//DXײ���؂̏���������
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