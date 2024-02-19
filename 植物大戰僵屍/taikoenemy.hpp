#ifndef TAIKOHPP
#define TAIKOHPP
#include "Enemy.hpp"

class taikoenemy : public Enemy {
public:
	taikoenemy(int x, int y);
	void CreateBullet() override;
};
#endif // TAIKOHPP
