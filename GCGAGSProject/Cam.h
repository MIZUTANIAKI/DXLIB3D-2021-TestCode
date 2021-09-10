#pragma once
#include <memory>

class Bullet;

class Cam
{
public:

	Cam();

	~Cam();

	/// <summary>
	/// カメラ更新処理
	/// </summary>
	/// <param name=""></param>
	void Update(void);

	/// <summary>
	/// 描画関連 （レティクル書いてるとこー）
	/// </summary>
	/// <param name=""></param>
	void Draw(void);

private:
	/// <summary>
	/// カメラ移動処理
	/// </summary>
	/// <param name=""></param>
	void MoveUpdate(void);

	/// <summary>
	/// マウス情報からカメラ情報を生成！
	/// </summary>
	void MouseMove();

	/// <summary>
	/// カメラの更新処理
	/// </summary>
	void CameraUpdate();

	float cameraRotate_speed_;//カメラの回転速度
	float cameraMove_speed_;//カメラの移動スピード

	float yaw_;				//ヨー
	float pih_;				//ピッチ

	int mousePosX_;			//マウス座標
	int mousePosY_;			//マウス座標
	int mouseMovePosX_;		//マウスがどれだけ動いたか
	int mouseMovePosY_;		//マウスがどれだけ動いたか

	VECTOR target_;			//注視点

	VECTOR camPos_;			//カメラ座標

	float mouse_SizeX_;		//マウスのどれだけ動いたら判定するか。
	float mouse_SizeY_;		//マウスのどれだけ動いたら判定するか。

	int screenSizeX_;		//スクリーンサイズ
	int screenSizeY_;		//スクリーンサイズ

	int lightHandle_;		//あかり1カメラ追跡ライト

	std::unique_ptr<Bullet> bullet_;
};

