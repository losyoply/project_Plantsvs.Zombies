
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "tuanzibullet.hpp"
#include "Group.hpp"
#include "NoAtkTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
const int NoAtkTurret::Price = 15;
NoAtkTurret::NoAtkTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-3.png", x, y, Price, 500000,2000) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void NoAtkTurret::CreateBullet() {

}

