#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "tuanzibullet.hpp"
#include "Group.hpp"
#include "CircleTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
const int CircleTurret::Price = 44;
CircleTurret::CircleTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-4.png", x, y, Price, 0.5,1) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void CircleTurret::CreateBullet() {

}

