#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "NormalEnemyBullet.hpp"
#include "Group.hpp"
#include "SofaEnemy.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"

SofaEnemy::SofaEnemy(int x, int y) : Enemy("play/enemy-2.png", x, y, 16, 100, 10, 10, 2, 0.5) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void SofaEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new NormalEnemyBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("missile.wav");
}
