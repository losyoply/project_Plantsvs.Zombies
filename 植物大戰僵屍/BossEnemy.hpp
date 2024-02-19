#ifndef BOSSHPP
#define BOSSHPP
#include "Enemy.hpp"

class BossEnemy : public Enemy {
public:
	BossEnemy(int x, int y);
	void CreateBullet();
};
#endif // BOSSHPP

