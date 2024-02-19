#ifndef TUANZIHPP
#define TUANZIHPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class tuanzibullet : public Bullet {
public:
	explicit tuanzibullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // TUANZIHPP
