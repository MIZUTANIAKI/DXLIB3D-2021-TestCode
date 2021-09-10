#pragma once
#include <array>

/// <summary>
/// 一発ずつの弾丸データ
/// </summary>
struct BulletDate
{
	VECTOR pos_;			//位置情報
	VECTOR bulletSpeed_;	//弾のスピード
	int count_;				//弾生存時間カウント
	bool fire_;				//発射されているか
};

class Bullet
{
public:
	Bullet();
	~Bullet();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name=""></param>
	void Updata(void);

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name=""></param>
	void Draw(void);

	/// <summary>
	/// 弾の発射処理。連射とかの処理承ってるので、気にせず打ちたいときに呼び出してくだせぇ
	/// </summary>
	/// <param name="pos">元座標</param>
	/// <param name="targetdir">ターゲット（ＮＯＴ目的地ＹＥＳ方向）</param>
	void BulletFire(VECTOR pos, VECTOR targetdir);
private:
	std::array<BulletDate, 30> bulletDat_;
	int bulletCount_;						//今何発目かカウントー＞撃ち切り判定
	int derayTime_;							//発射間隔
	int reLoadTime_;						//リロード残り
	bool reLoadF_;							//リロード中かどうか
};

