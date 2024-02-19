#ifndef KIRBYTURRET_HPP
#define KIRBYTURRET_HPP
#include "Turret.hpp"

class KirbyTurret: public Turret {
public:
	static const int Price;
    KirbyTurret(float x, float y);
	void CreateBullet() override;
};
#endif // KIRBYTURRET_HPP
