#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <math.h>
#include <DxLib.h>
#include "objmnj.h"
#include "ExampleMap.h"

/*
	3D���f����`�悷��ɂ������ĕK�v�Ȋ֐��̎g�p��ł��B
	�`�悷��ɂ������ĎQ�l�ɂ��Ă��������B
*/

ExampleMap::ExampleMap()
{
	//���f���f�[�^�ǂݍ���
	soraDate_ = lpobjlMng.LoadModel("sora.mv1");
	sorairoDate_ = lpobjlMng.LoadModel("sorairo1.52.mv1");
	minaMainDate_ = lpobjlMng.LoadModel("mato.x");

	//�����̏o�����肷��Ƃ��́A�R�s�[���g�p����
	minaTestDate_ = lpobjlMng.CopyModel(minaMainDate_);

	//���W��ݒ�
	lpobjlMng.Setobjpos(soraDate_, VGet(0.0f, 0.0f, 0.0f));
	lpobjlMng.Setobjpos(sorairoDate_, VGet(0.0f, -1.05f, 0.0f));
	lpobjlMng.Setobjpos(minaMainDate_, VGet(0.0f, 0.0f, 0.0f));
	lpobjlMng.Setobjpos(minaTestDate_, VGet(2.0f, -0.92f, -8.0f));

	//���f���̊g�k�ݒ�
	lpobjlMng.SetScale(minaTestDate_, VGet(0.008f, 0.008f, 0.008f));

	minaRotaPoint_ = 0;
}

ExampleMap::~ExampleMap()
{
	//�g�p���Ȃ��Ȃ����Ƃ��͍폜����B
	lpobjlMng.DeleteModel(soraDate_);
	lpobjlMng.DeleteModel(sorairoDate_);
	lpobjlMng.DeleteModel(minaMainDate_);
	lpobjlMng.DeleteModel(minaTestDate_);

}

void ExampleMap::Update()
{
	//���f������]������
	lpobjlMng.SetRotation(minaTestDate_, minaRotaPoint_);

	//���f���̕`��v��
	lpobjlMng.ObjDraw(soraDate_);
	lpobjlMng.ObjDraw(sorairoDate_);
	lpobjlMng.ObjDraw(minaTestDate_);

	minaRotaPoint_ += DX_PI_F / 10;
}
