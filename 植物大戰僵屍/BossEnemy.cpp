#include <string>

#include "BossEnemy.hpp"
//
#include "AudioHelper.hpp"
#include "NormalEnemyBullet.hpp"
#include "Group.hpp"
#include "KirbyTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
BossEnemy::BossEnemy(int x, int y) : Enemy("play/enemy-5.png", x, y, 20, 200, 10, 50, 5, 0.5) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
void BossEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new NormalEnemyBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("missile.wav");
}

