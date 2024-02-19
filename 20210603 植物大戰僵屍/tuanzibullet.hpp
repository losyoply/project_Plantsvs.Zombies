#ifndef TUANZIBULLET_HPP
#define TUANZIBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class TuanziBullet : public Bullet {
public:
	explicit TuanziBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // TUANZIBULLET_HPP

