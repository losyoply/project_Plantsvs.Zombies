#ifndef HEALTURRET_HP
#define HEALTURRET_HP
#include "Turret.hpp"

class HealTurret: public Turret {
public:
	static const int Price;
    HealTurret(float x, float y);
	void CreateBullet() override;
};
#endif // HealTurret

