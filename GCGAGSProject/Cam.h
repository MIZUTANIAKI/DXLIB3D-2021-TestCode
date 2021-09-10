#pragma once
#include <memory>

class Bullet;

class Cam
{
public:

	Cam();

	~Cam();

	/// <summary>
	/// �J�����X�V����
	/// </summary>
	/// <param name=""></param>
	void Update(void);

	/// <summary>
	/// �`��֘A �i���e�B�N�������Ă�Ƃ��[�j
	/// </summary>
	/// <param name=""></param>
	void Draw(void);

private:
	/// <summary>
	/// �J�����ړ�����
	/// </summary>
	/// <param name=""></param>
	void MoveUpdate(void);

	/// <summary>
	/// �}�E�X��񂩂�J�������𐶐��I
	/// </summary>
	void MouseMove();

	/// <summary>
	/// �J�����̍X�V����
	/// </summary>
	void CameraUpdate();

	float cameraRotate_speed_;//�J�����̉�]���x
	float cameraMove_speed_;//�J�����̈ړ��X�s�[�h

	float yaw_;				//���[
	float pih_;				//�s�b�`

	int mousePosX_;			//�}�E�X���W
	int mousePosY_;			//�}�E�X���W
	int mouseMovePosX_;		//�}�E�X���ǂꂾ����������
	int mouseMovePosY_;		//�}�E�X���ǂꂾ����������

	VECTOR target_;			//�����_

	VECTOR camPos_;			//�J�������W

	float mouse_SizeX_;		//�}�E�X�̂ǂꂾ���������画�肷�邩�B
	float mouse_SizeY_;		//�}�E�X�̂ǂꂾ���������画�肷�邩�B

	int screenSizeX_;		//�X�N���[���T�C�Y
	int screenSizeY_;		//�X�N���[���T�C�Y

	int lightHandle_;		//������1�J�����ǐՃ��C�g

	std::unique_ptr<Bullet> bullet_;
};

