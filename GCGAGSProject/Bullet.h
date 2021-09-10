#pragma once
#include <array>

/// <summary>
/// �ꔭ���̒e�ۃf�[�^
/// </summary>
struct BulletDate
{
	VECTOR pos_;			//�ʒu���
	VECTOR bulletSpeed_;	//�e�̃X�s�[�h
	int count_;				//�e�������ԃJ�E���g
	bool fire_;				//���˂���Ă��邩
};

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
	/// �e�̔��ˏ����B�A�˂Ƃ��̏��������Ă�̂ŁA�C�ɂ����ł������Ƃ��ɌĂяo���Ă�������
	/// </summary>
	/// <param name="pos">�����W</param>
	/// <param name="targetdir">�^�[�Q�b�g�i�m�n�s�ړI�n�x�d�r�����j</param>
	void BulletFire(VECTOR pos, VECTOR targetdir);
private:
	std::array<BulletDate, 30> bulletDat_;
	int bulletCount_;						//�������ڂ��J�E���g�[�������؂蔻��
	int derayTime_;							//���ˊԊu
	int reLoadTime_;						//�����[�h�c��
	bool reLoadF_;							//�����[�h�����ǂ���
};

