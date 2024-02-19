#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "tuanzibullet.hpp"
#include "Group.hpp"
#include "KirbyTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
const int KirbyTurret::Price = 150;
KirbyTurret::KirbyTurret(float x, float y) :
	Turret("play/kirby.png", x, y, Price, 0.5,180) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void KirbyTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new tuanzibullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("missile.wav");
}
