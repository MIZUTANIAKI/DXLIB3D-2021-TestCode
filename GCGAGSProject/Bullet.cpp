#include <math.h>
#include <DxLib.h>
#include "Bullet.h"

Bullet::Bullet()
{
	//for (auto& bullet : bulletDat_)
	//{
	//	bullet.pos_ = std::move(VGet(0.0f, 0.0f, 0.0f));
	//	bullet.bulletSpeed_ = std::move(VGet(0.0f, 0.0f, 0.0f));
	//	bullet.count_ = 0;
	//	bullet.fire_ = false;
	//}

	for (int bulletnum = 0; bulletnum < bulletDat_.size(); bulletnum++)
	{
		bulletDat_[bulletnum].pos_ = std::move(VGet(0.0f, 0.0f, 0.0f));
		bulletDat_[bulletnum].bulletSpeed_ = std::move(VGet(0.0f, 0.0f, 0.0f));
		bulletDat_[bulletnum].count_ = 0;
		bulletDat_[bulletnum].fire_ = false;
	}

	bulletCount_ = 0;
	derayTime_ = 0;
	reLoadTime_ = 0;
	reLoadF_ = false;
}

Bullet::~Bullet()
{
}

void Bullet::Updata(void)
{
	for (auto& bullet : bulletDat_)
	{
		if (bullet.fire_)
		{
			bullet.pos_ = VAdd(bullet.pos_, bullet.bulletSpeed_);
			bullet.count_++;

			if (bullet.count_ >= 60)
			{
				bullet.fire_ = false;
				bullet.pos_ = std::move(VGet(0.0f, 0.0f, 0.0f));
				bullet.count_ = 0;
				bullet.bulletSpeed_ = std::move(VGet(0.0f, 0.0f, 0.0f));
			}
		}
	}
	if (derayTime_ != 0)
	{
		if (derayTime_++ > 10)
		{
			derayTime_ = 0;
		}
	}
	if (reLoadF_)
	{
		if (reLoadTime_-- <= 0)
		{
			reLoadF_ = false;
			for (auto& bullet : bulletDat_)
			{
				bullet.fire_ = false;
				bullet.pos_ = std::move(VGet(0.0f, 0.0f, 0.0f));
				bullet.count_ = 0;
				bullet.bulletSpeed_ = std::move(VGet(0.0f, 0.0f, 0.0f));
			}
			reLoadTime_ = 0;
			bulletCount_ = 0;
		}
	}
}

void Bullet::Draw(void)
{
	for (const auto& bullet: bulletDat_)
	{
		if (bullet.fire_)
		{
			DrawSphere3D(bullet.pos_, 0.2f, 8, 0xffff00, 0xffffff, true);
		}
	}
}

void Bullet::BulletFire(VECTOR pos, VECTOR targetdir)
{
	if (!reLoadF_)
	{
		if (derayTime_ == 0)
		{
			if (bulletCount_ < 30)
			{
				auto& bullet = bulletDat_[bulletCount_];
				bullet.fire_ = true;
				bullet.count_ = 0;
				bullet.bulletSpeed_ = VSub(targetdir, pos);
				bullet.pos_ = pos;
				bulletCount_++;
				derayTime_++;


				bullet.pos_ = VAdd(bullet.pos_, bullet.bulletSpeed_);
			}
			else
			{
				reLoadF_ = true;
				reLoadTime_ = 3*60;
			}
		}
	}
}
