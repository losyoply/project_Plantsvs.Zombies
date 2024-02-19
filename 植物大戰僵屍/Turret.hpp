#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;
class EnemyBullet;

class Turret: public Engine::Sprite {
protected:
    int price;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;
    //
    int hp;
    //
    virtual void OnExplode();
    Engine::Point target;

public:
    bool Enabled = true;
    bool Preview = false;
    Enemy* Target = nullptr;
    Turret* Bomb = nullptr;
    Turret* Heal = nullptr;
    Enemy* Circle = nullptr;
    Turret(/*std::string imgBase,*/std::string imgTurret, float x, float y,/* float radius,*/ int price, float coolDown, int hp);
    void Update(float deltaTime) override;
    void Draw() const override;
    void Hit(float damage);
	int GetPrice() const;
	std::list<Enemy*> lockedEnemys;
	std::list<EnemyBullet*> lockedEnemyBullets;
};
#endif // TURRET_HPP
