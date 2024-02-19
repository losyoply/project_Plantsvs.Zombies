#ifndef TCELLTURRET_HPP
#define TCELLTURRET_HPP
#include "Turret.hpp"

class TCellTurret: public Turret {
public:
	static const int Price;
    TCellTurret(float x, float y);
	void CreateBullet() override;
};
#endif // WBCELLTURRET_HPP
