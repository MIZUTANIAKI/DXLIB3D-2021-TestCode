#pragma once
#include <array>

/// <summary>
/// 弾丸一つひとつのデータ
/// </summary>
struct BulletDate
{
	VECTOR pos_;			//位置情報
	VECTOR bulletSpeed_;	//弾のスピード
	int count_;				//弾生存時間カウント
	bool fire_;				//発射されているか
};

/// <summary>
/// 銃発射に関するサンプル
/// </summary>
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
	/// 弾の発射処理
	/// 連射対応しています。
	/// マイフレーム呼んでいても、必ず間隔をあけて発射します。
	/// </summary>
	/// <param name="pos">元座標</param>
	/// <param name="movedir">進むべき方向</param>
	void BulletFire(VECTOR pos, VECTOR movedir);
private:
	std::array<BulletDate, 30> bulletDat_;	//弾丸データ格納配列ー＞＜弾倉＞
	int bulletCount_;						//今何発目かカウントー＞撃ち切り判定
	int derayTime_;							//発射間隔測定用
	int reLoadTime_;						//リロード残り時間
	bool reLoadF_;							//リロード中かどうか -> true[リロード中] false[リロードしていない]
};

