#pragma once
#include "BaseScene.h"
#include "../common/Vector2.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	
	static SceneMng& GetInstance(void)
	{
		
		Create();
		return *sInstance;
	}
	
	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMng();
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

	int GetFcon(void) 
	{
		return fcon_; 
	}

	void Run(void);									//���s����

	const Vector2 ScreenSize;						//��ʃT�C�Y

	void GameEnd(void);

	void SetLight(int num);

	VECTOR campos_;

private:

	int lightC_;

	int fcon_;										//�t���[���J�E���g
	static SceneMng* sInstance;						//�V�[���}�l�[�W���[�̐ÓI�Ȑ錾
	bool SysInit();									//������
	UNBS activeScene_;						//�������Ă�scene������B

	void Draw(void);								//�`�揈��
	SceneMng();
	~SceneMng(); 
	
	int lightHandle_;								//������1�J�����ǐՃ��C�g

};

