#pragma once

/// <summary>
/// 3Dモデル描画サンプルのヘッダーです。
/// CPPファイルを参照してください
/// </summary>
class ExampleMap
{
public:
	ExampleMap();
	~ExampleMap();
	/// <summary>
	/// 更新処理
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

