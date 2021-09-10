#pragma once
#define CPU_MAX 9
#include "obj.h"


//#define CHARA_MAX_HITCOLL			2048		// ��������R���W�����|���S���̍ő吔
//#define CHARA_ENUM_DEFAULT_SIZE		3000.0f		// ���͂̃|���S�����o�Ɏg�p���鋅�̏����T�C�Y
//#define CHARA_HIT_WIDTH				3000.0f		// �����蔻��J�v�Z���̔��a
//#define CHARA_HIT_HEIGHT			1000.0f		// �����蔻��J�v�Z���̍���
//#define CHARA_HIT_PUSH_POWER		40.0f		// �L�����N�^�[���m�œ��������Ƃ��̉����o������

#define lpobjlMng Objmnj::GetInstance()


//���f���Ǘ��}�l�[�W��
class Objmnj
{
public:
	static Objmnj& GetInstance(void)
	{

		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new Objmnj();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}
	
	void DrawNaw(void);

	void ReSetD(void);	//���t���[���ŏ��ɌĂ�

	void Setobjpos(VECTOR pos,int mv1);	//�ʒu�����Z�b�g					

	void ObjDraw(int mv1);								//������ĂԂƁA�`��v�����Ascene�}�l�[�W���ɂ��܂�

	void ObjRotation(int mv1,float moveangle);			//��]���i�����ځj���Z�b�g

	//bool ObjCollHit(VECTOR pos, UNIT_ID id);		//�����蔻��`�F�b�N�p

private:
	static Objmnj* sInstance;


	std::vector<int> drawList_;						//�`�悷����̂𗭂߂Ă����L���[
	std::vector<int> drawListnex_;					//�`�悷����̂𗭂߂Ă����L���[�i������j

	Objmnj();
	~Objmnj();
};

