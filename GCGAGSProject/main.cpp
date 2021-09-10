#include <DxLib.h>
#include "Scene/sceneMng.h"

/* �����Ȃ��Ƃ��͂����Ƃ�86�ɂȂ��Ă��邩�m�F */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst,LPSTR lpszCmdLine, int nCmdShow)
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