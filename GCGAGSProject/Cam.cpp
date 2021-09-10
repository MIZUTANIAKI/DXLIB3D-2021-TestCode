#include <math.h>
#include <DxLib.h>
#include "Cam.h"

Cam::Cam()
{
	GetDrawScreenSize(&screenSizeX_,&screenSizeY_);
	cameraYaw_speed_ = 0.001f;
	cameraMove_speed_ = 0.01f;
	rotate_speed_ = DX_PI_F / 60;
	yaw_ = 0.0f;
	camPos_ = VGet(3.0f, 0.0f, -10.0f);
	target_ = VGet(0.0f, 0.0f, 0.0f);

	mouse_SizeX_ = screenSizeX_/2;
	mouse_SizeY_ = screenSizeY_/2;

	SetMousePoint(mouse_SizeX_, mouse_SizeY_);

	mousePosX_ = 0;
	mousePosY_ = 0;
	pih_ = 0;
}

Cam::~Cam()
{
}

void Cam::Update(void)
{

	target_ = camPos_;

	if (CheckHitKey(KEY_INPUT_W))
	{
		camPos_.x += sinf(yaw_) * cameraMove_speed_;
		camPos_.z += cosf(yaw_) * cameraMove_speed_;
	}

	if (CheckHitKey(KEY_INPUT_S))
	{
		camPos_.x -= sinf(yaw_) * cameraMove_speed_;
		camPos_.z -= cosf(yaw_) * cameraMove_speed_;
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		camPos_.x += sinf(yaw_ - DX_PI_F / 2) * cameraMove_speed_;
		camPos_.z += cosf(yaw_ - DX_PI_F / 2) * cameraMove_speed_;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		camPos_.x += sinf(yaw_ + DX_PI_F / 2) * cameraMove_speed_;
		camPos_.z += cosf(yaw_ + DX_PI_F / 2) * cameraMove_speed_;
	}

	MouseReset();
}

void Cam::Draw(void)
{
	DrawLine(
		screenSizeX_ / 2 - 8,screenSizeY_ / 2,
		screenSizeX_ / 2 - 2,screenSizeY_ / 2,0xff0000
	);

	DrawLine(
		screenSizeX_ / 2 + 2, screenSizeY_ / 2,
		screenSizeX_ / 2 + 8, screenSizeY_ / 2, 0xff0000
	);


	DrawLine(
		screenSizeX_ / 2 , screenSizeY_ / 2 - 8,
		screenSizeX_ / 2 , screenSizeY_ / 2 - 2, 0xff0000
	);

	DrawLine(
		screenSizeX_ / 2, screenSizeY_ / 2 + 2,
		screenSizeX_ / 2, screenSizeY_ / 2 + 8, 0xff0000
	);
}

void Cam::MouseReset()
{	

	GetMousePoint(&mousePosX_, &mousePosY_);
	mouseMovePosX_ = mousePosX_ - mouse_SizeX_;
	mouseMovePosY_ = mousePosY_ - mouse_SizeY_;
	if (mouseMovePosX_ > 2|| mouseMovePosX_ < -2)
	{
		yaw_ += mouseMovePosX_ * cameraYaw_speed_;
	}

	/*if (mouseMovePosX_ != 0)
	{
	}
	else
	{
		if (yaw_ != 0.0f)
		{
			yaw_ -= yaw_ / 10;
			if (yaw_ < 0.05f)
			{
				yaw_ = 0;
			}
		}
	}*/

	pih_ += mouseMovePosY_* cameraYaw_speed_;

	target_.x += sinf(yaw_);
	target_.y = -pih_ ;
	target_.z += cosf(yaw_);

	SetCameraPositionAndTarget_UpVecY(camPos_, target_);

	SetMousePoint(mouse_SizeX_, mouse_SizeY_);
}