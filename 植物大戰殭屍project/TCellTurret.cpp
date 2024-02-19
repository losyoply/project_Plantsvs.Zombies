#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "ChickenBullet.hpp"
#include "Group.hpp"
#include "TCellTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
const int TCellTurret::Price = 500;
TCellTurret::TCellTurret(float x, float y) :
	Turret("play/turret-4.png", x, y, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void TCellTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new ChickenBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("missile.wav");
}
