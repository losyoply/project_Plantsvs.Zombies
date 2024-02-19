#include <string>

#include "OtakuEnemy.hpp"

OtakuEnemy::OtakuEnemy(int x, int y) : Enemy("play/enemy-5.png", x, y, 20, 50, 150, 80, 4) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
