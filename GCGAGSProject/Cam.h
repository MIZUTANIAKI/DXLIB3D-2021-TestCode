#pragma once
#include <memory>

class Bullet;

class Cam
{
public:

	Cam();

	~Cam();

	void Update(void);

	void Draw(void);

private:
	void MouseReset();
	
	float rotate_speed_;

	float cameraYaw_speed_;
	float cameraMove_speed_;

	float yaw_;
	float pih_;

	int mousePosX_;
	int mousePosY_;
	int mouseMovePosX_;
	int mouseMovePosY_;

	VECTOR target_;

	VECTOR camPos_;

	float mouse_SizeX_;		//マウスのどれだけ動いたら判定するか。
	float mouse_SizeY_;		//マウスのどれだけ動いたら判定するか。

	int screenSizeX_;
	int screenSizeY_;

	int lightHandle_;								//あかり1カメラ追跡ライト

	std::unique_ptr<Bullet> bullet_;
};

