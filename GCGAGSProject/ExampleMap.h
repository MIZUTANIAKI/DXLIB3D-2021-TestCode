#pragma once

/// <summary>
/// 3D���f���`��T���v���̃w�b�_�[�ł��B
/// CPP�t�@�C�����Q�Ƃ��Ă�������
/// </summary>
class ExampleMap
{
public:
	ExampleMap();
	~ExampleMap();
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();
private:
	int soraDate_;
	int sorairoDate_;
	int minaMainDate_;
	int minaTestDate_;

	float minaRotaPoint_;

	int fconnt_;
};

