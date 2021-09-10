#pragma once
#include <array>

struct BulletDate
{
	VECTOR pos_;
	VECTOR bulletSpeed_;
	int count_;
	bool fire_;
};

class Bullet
{
public:
	Bullet();
	~Bullet();
	void Updata(void);
	void Draw(void);
	void BulletFire(VECTOR pos, VECTOR targetdir);
private:
	std::array<BulletDate, 30> bulletDat_;
	int bulletCount_;
	int derayTime_;
	int reLoadTime_;
	bool reLoadF_;
};

