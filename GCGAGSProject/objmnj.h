#pragma once
//#define CPU_MAX 9


//#define CHARA_MAX_HITCOLL			2048		// ��������R���W�����|���S���̍ő吔
//#define CHARA_ENUM_DEFAULT_SIZE		3000.0f		// ���͂̃|���S�����o�Ɏg�p���鋅�̏����T�C�Y
//#define CHARA_HIT_WIDTH				3000.0f		// �����蔻��J�v�Z���̔��a
//#define CHARA_HIT_HEIGHT			1000.0f		// �����蔻��J�v�Z���̍���
//#define CHARA_HIT_PUSH_POWER		40.0f		// �L�����N�^�[���m�œ��������Ƃ��̉����o������

#define lpobjlMng Objmnj::GetInstance()

/// <summary>
/// 3D���f���̕`��֘A�����������肵�Ă����N���X
/// �K���g�p���邱�ƁB
/// �ǂݍ��񂾃��f���͕K���s�v���ɍ폜���邱�ƁB
/// 
/// ***�g�p���ExampleMap.cpp���Q��***
/// </summary>
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
	/// �`��\�񂳂ꂽ3D���f����`�悳����B
	/// �V�[���̕`�揈���ŕK���Ăяo�����ƁB
	/// </summary>
	/// <param name=""></param>
	void DrawNaw(void);

	/// <summary>
	/// �`��\�񃊃X�g���폜����
	/// ���C�����[�v�̐擪�ŕK���Ăяo�����ƁB
	/// </summary>
	/// <param name=""></param>
	void ReSetD(void);

	/// <summary>
	/// 3D���f���̈ʒu����ݒ肷��B
	/// </summary>
	/// <param name="pos">���W</param>
	/// <param name="mv1">mv1���f����ID</param>
	void Setobjpos(int mv1,VECTOR pos);					

	/// <summary>
	/// 3D���f����`�悷��B
	/// �`�悳����Ƃ��A�}�C�t���[���K�v
	/// </summary>
	/// <param name="mv1">mv1���f����ID</param>
	void ObjDraw(int mv1);

	/// <summary>
	/// MV1���f������]������
	/// </summary>
	/// <param name="mv1">mv1���f����ID</param>
	/// <param name="moveangle">�p�x</param>
	void SetRotation(int mv1,float moveangle);

	/// <summary>
	/// ���f���f�[�^�̊g�k�ݒ������B
	/// 1.0f���f�t�H���g�Ƃ��Ăǂ̂��炢����ݒ�B
	/// ���}�C�i�X�l�g�p�֎~�B
	/// </summary>
	/// <param name="mv1">mv1���f����ID</param>
	/// <param name="scale">�g�k�l</param>
	void SetScale(int mv1, VECTOR scale);

	//bool ObjCollHit(VECTOR pos, UNIT_ID id);

	/// <summary>
	/// 3D���f���f�[�^��ǂݍ��ށB
	/// �Ԃ�l��ID�B�`�悳�������Ƃ��ɕK�v�B
	/// �K���Ԃ�l��ۑ����邱�ƁB
	/// �����̓f�B���N�g��[MV1Date]�Ɋi�[���Ă���O��Ȃ̂�MV1Date�͏ȗ�
	/// </summary>
	/// <param name="fileName">3D���f���t�@�C����</param>
	/// <returns></returns>
	int LoadModel(std::string fileName);

	/// <summary>
	/// �ۑ�����Ă���3D���f����ID����폜����
	/// 
	/// �s�v�ȃ��f���͕K���폜���邱�ƁB
	/// </summary>
	/// <param name="Mhandle"></param>
	void DeleteModel(int mv1);

	/// <summary>
	/// �i�[����Ă��郂�f���f�[�^�����ׂč폜����B
	/// �V�[���؂�ւ����ȂǂŎg�p��z��B
	/// </summary>
	/// <param name=""></param>
	void ReSetModelDate(void);

	/// <summary>
	/// ���łɃ��[�h�ς݂̃��f���f�[�^�̃R�s�[�𐶐�����B
	/// �����̏o��G�Ȃǂ́A�I���W�i���ł͂Ȃ��R�s�[���g�p���邱�ƁB
	/// �Ԃ�l�̓R�s�[��ID�B
	/// </summary>
	/// <param name="mv1"></param>
	/// <returns></returns>
	int CopyModel(int mv1);

private:
	static Objmnj* sInstance;

	/// <summary>
	/// ID���烂�f���n���h�����擾����B
	/// </summary>
	/// <param name="mv1"></param>
	/// <returns></returns>
	int GetModelHandle(int mv1);

	std::map<int,int> mv1List_;						//�ۑ����Ă��郂�f���f�[�^�@ID�F�n���h��

	std::vector<int> drawList_;						//�`��\��L���[
	//std::vector<int> drawListnex_;				//�`��\��L���[�i������j

	Objmnj();
	~Objmnj();
};

