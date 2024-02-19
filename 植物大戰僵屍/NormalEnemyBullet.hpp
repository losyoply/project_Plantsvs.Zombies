#ifndef NORBULLET_HPP
#define NORBULLET_HPP
#include "EnemyBullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class NormalEnemyBullet : public EnemyBullet {
public:
	explicit NormalEnemyBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turr) override;
};
#endif // NORMALENEMY_HPP
