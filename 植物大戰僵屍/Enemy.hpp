#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <list>
#include <vector>
#include <string>

#include "Point.hpp"
#include "Sprite.hpp"

class Bullet;
class PlayScene;
class Turret;

class Enemy : public Engine::Sprite {
protected:
	Engine::Point target;
	float speed;
	float hp;
	int money;
	int type;
	PlayScene* getPlayScene();
	virtual void OnExplode();
	//by me
	float reload = 0;
    float coolDown ;
    std::list<Enemy*>::iterator lockedEnemyIterator;
    virtual void CreateBullet() = 0;
public:
	float reachEndTime;
	std::list<Turret*> lockedTurrets;
	std::list<Bullet*> lockedBullets;
	Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money,int type, double coolDown );
 	void Hit(float damage);
	void Update(float deltaTime) override;
	void Draw() const override;
	//
	Turret* Target = nullptr;
};
#endif // ENEMY_HPP
