#pragma once
#include <array>

/// <summary>
/// �e�ۈ�ЂƂ̃f�[�^
/// </summary>
struct BulletDate
{
	VECTOR pos_;			//�ʒu���
	VECTOR bulletSpeed_;	//�e�̃X�s�[�h
	int count_;				//�e�������ԃJ�E���g
	bool fire_;				//���˂���Ă��邩
};

/// <summary>
/// �e���˂Ɋւ���T���v��
/// </summary>
class Bullet
{
public:
	Bullet();
	~Bullet();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name=""></param>
	void Updata(void);

	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name=""></param>
	void Draw(void);

	/// <summary>
	/// �e�̔��ˏ���
	/// �A�ˑΉ����Ă��܂��B
	/// �}�C�t���[���Ă�ł��Ă��A�K���Ԋu�������Ĕ��˂��܂��B
	/// </summary>
	/// <param name="pos">�����W</param>
	/// <param name="movedir">�i�ނׂ�����</param>
	void BulletFire(VECTOR pos, VECTOR movedir);
private:
	std::array<BulletDate, 30> bulletDat_;	//�e�ۃf�[�^�i�[�z��[�����e�q��
	int bulletCount_;						//�������ڂ��J�E���g�[�������؂蔻��
	int derayTime_;							//���ˊԊu����p
	int reLoadTime_;						//�����[�h�c�莞��
	bool reLoadF_;							//�����[�h�����ǂ��� -> true[�����[�h��] false[�����[�h���Ă��Ȃ�]
};

