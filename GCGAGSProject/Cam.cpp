#include <math.h>
#include <DxLib.h>
#include "Bullet.h"
#include "Cam.h"

int Fov;

Cam::Cam()
{
	GetDrawScreenSize(&screenSizeX_,&screenSizeY_);
	cameraRotate_speed_ = 0.001f;
	cameraMove_speed_ = 0.01f;
	yaw_ = 0.0f;
	camPos_ = VGet(0.0f, 0.0f, -10.0f);
	target_ = VGet(0.0f, 0.0f, 0.0f);

	mouse_SizeX_ = screenSizeX_/2;
	mouse_SizeY_ = screenSizeY_/2;

	SetMousePoint(mouse_SizeX_, mouse_SizeY_);

	mousePosX_ = 0;
	mousePosY_ = 0;
	pih_ = 0;


	SetupCamera_Perspective(60 * DX_PI_F / 180.0f);


	//lightHandle_ = CreateDirLightHandle(VGet(0.0f, -1.0f, 0.0f));
	lightHandle_ = CreatePointLightHandle(camPos_,500.0f, 0.0f, 0.0f,0.02f);

	bullet_ = std::make_unique<Bullet>();
}

Cam::~Cam()
{
}

void Cam::Update(void)
{
	bullet_->Updata();

	SetLightPositionHandle(lightHandle_, camPos_);

	MoveUpdate();

	MouseMove();

}

void Cam::Draw(void)
{
	bullet_->Draw();

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

void Cam::MoveUpdate(void)
{

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

	if (GetMouseInput() & MOUSE_INPUT_1)
	{
		bullet_->BulletFire(camPos_, target_);
	}

}

void Cam::MouseMove()
{
	target_ = camPos_;

	GetMousePoint(&mousePosX_, &mousePosY_);
	mouseMovePosX_ = mousePosX_ - mouse_SizeX_;
	mouseMovePosY_ = mousePosY_ - mouse_SizeY_;
	if (mouseMovePosX_ > 2 || mouseMovePosX_ < -2)
	{
		yaw_ += mouseMovePosX_ * cameraRotate_speed_;
	}

	pih_ += mouseMovePosY_ * cameraRotate_speed_;

	target_.x += sinf(yaw_);
	target_.y = -pih_;
	target_.z += cosf(yaw_);

	CameraUpdate();
}

void Cam::CameraUpdate()
{	
	SetCameraPositionAndTarget_UpVecY(camPos_, target_);

	SetMousePoint(mouse_SizeX_, mouse_SizeY_);
}
