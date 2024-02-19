#include <cmath>
#include <string>

#include "BulletEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Resources.hpp"
PlayScene* BulletEffect::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
BulletEffect::BulletEffect(float x, float y) : Sprite("play/bullet-10.png", x, y), timeTicks(0) {
	for (int i = 1; i <= 5; i++) {
		bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/bullet-10.png"/* + std::to_string(i) + ""*/));
	}
}
void BulletEffect::Update(float deltaTime) {
	timeTicks += deltaTime;
	if (timeTicks >= timeSpan) {
		getPlayScene()->EffectGroup->RemoveObject(objectIterator);
		return;
	}
	int phase = floor(timeTicks / timeSpan * bmps.size());
	bmp = bmps[phase];
	Sprite::Update(deltaTime);
}
