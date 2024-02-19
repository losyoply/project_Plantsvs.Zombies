
#ifndef NOATK_HPP
#define NOATK_HPP
#include "Turret.hpp"

class NoAtkTurret: public Turret {
public:
	static const int Price;
    NoAtkTurret(float x, float y);
	void CreateBullet() override;
};
#endif // NOATK_HPP
