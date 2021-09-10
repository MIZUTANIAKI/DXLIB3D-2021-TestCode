#pragma once
//#define CPU_MAX 9


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
	
	/// <summary>
	/// ���f������ĕ`�悳����B���C�����[�v�œǂ�ł�ꍇ�G��Ȃ���OK
	/// </summary>
	/// <param name=""></param>
	void DrawNaw(void);

	/// <summary>
	/// ���t���[���ŏ��ɌĂԂ�ł����A���C�����[�v�œǂ�ł�ꍇ�G��Ȃ���OK
	/// </summary>
	/// <param name=""></param>
	void ReSetD(void);

	/// <summary>
	/// 3D���f���̈ʒu����ݒ�ł��܂��I
	/// </summary>
	/// <param name="pos">���W</param>
	/// <param name="mv1">mv1���f���̃n���h��</param>
	void Setobjpos(VECTOR pos,int mv1);	//�ʒu�����Z�b�g					

	/// <summary>
	/// 3D���f���`�悳����I
	/// </summary>
	/// <param name="mv1">mv1���f���̃n���h��</param>
	void ObjDraw(int mv1);

	/// <summary>
	/// MV1���f������]�����܂���[
	/// </summary>
	/// <param name="mv1">mv1���f���̃n���h��</param>
	/// <param name="moveangle">�p�x���������B</param>
	void ObjRotation(int mv1,float moveangle);

	//bool ObjCollHit(VECTOR pos, UNIT_ID id);		//�����蔻��`�F�b�N�p�@��������ł����ǁ[�������Ƃ���������ĂȂ��ł��ˁ[

private:
	static Objmnj* sInstance;


	std::vector<int> drawList_;						//�`�悷����̂𗭂߂Ă����L���[
	//std::vector<int> drawListnex_;					//�`�悷����̂𗭂߂Ă����L���[�i������j

	Objmnj();
	~Objmnj();
};

