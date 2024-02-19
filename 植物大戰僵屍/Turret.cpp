#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <utility>

#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"
//
#include "AudioHelper.hpp"
#include "ExplosionEffect.hpp"
#include <random>
#include <string>
#include <vector>
#include <stdio.h>
#include "DirtyEffect.hpp"
#include "EnemyBullet.hpp"
#include "HealEffect.hpp"
PlayScene* Turret::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
Turret::Turret(std::string imgTurret, float x, float y,/* float radius,*/ int price, float coolDown, int hp) :
	Sprite(imgTurret, x, y), price(price), coolDown(coolDown), hp(hp) {
	//CollisionRadius = radius;
	target = Engine::Point(PlayScene::EndGridPointx , static_cast<int>(floor(Position.y / PlayScene::BlockSize))) * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);
}
void Turret::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	if (!Enabled)
		return;
    //Heal the NoAtk Turret  //´¡®yHeal Turret
    if(hp == 119)
    {
        for (auto& it : scene->TowerGroup->GetObjects())
        {
            if ((it->Position-Position).Magnitude()<=PlayScene::BlockSize/2)
            {
				Heal = dynamic_cast<Turret*>(it);
				if(Heal->coolDown ==  500000)
                {
                    Heal->hp = 2000;  //Heal No Atk
                }
			}
		}
		Hit(119);
    }
    //the NoAtk Heal Effect
    if(coolDown == 500000)
    {
        if(hp<=1000) getPlayScene()->EffectGroup->AddNewObject(new HealEffect(Position.x, Position.y+30));
    }
    //
    if(hp==9487)
    {
        for (auto& it : scene->TowerGroup->GetObjects())
        {
            if ((it->Position-Position).Magnitude()<=PlayScene::BlockSize/2 )
            {
				Bomb = dynamic_cast<Turret*>(it);
				Bomb->Hit(500000);
			}
		}
    }
	if (Target) {
		if (Target->Position.x < Position.x&& Target->Position.y >= Position.y  && Target->Position.y < Position.y+scene->BlockSize) {
			Target->lockedTurrets.erase(lockedTurretIterator);
			Target = nullptr;
			lockedTurretIterator = std::list<Turret*>::iterator();
		}
		// Shoot reload.
		reload -= deltaTime;
		if (reload <= 0) {
			// shoot.
			reload = coolDown;
			CreateBullet();
		}
	}
	if (!Target) {
		// Lock first seen target.
		// Can be improved by Spatial Hash, Quad Tree, ...
		// However simply loop through all enemies is enough for this program.
		for (auto& it : scene->EnemyGroup->GetObjects()) {
            if (it->Position.x > Position.x && it->Position.y >= Position.y  && it->Position.y < Position.y+scene->BlockSize) {
				Target = dynamic_cast<Enemy*>(it);
				Target->lockedTurrets.push_back(this);
				lockedTurretIterator = std::prev(Target->lockedTurrets.end());
				break;
			}
		}
	}

}
void Turret::Draw() const {
    if(price == 44)al_draw_circle(Position.x, Position.y, 350, al_map_rgb(255, 0, 0), 20);
	/*if (Preview) {
		al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
	}*/
	Sprite::Draw();
	/*if (PlayScene::DebugMode) {
		// Draw target radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(0, 0, 255), 2);
	}*/
}
int Turret::GetPrice() const {
	return price;
}
void Turret::Hit(float damage) {
    PlayScene* scene = getPlayScene();
    if(price == 44)
    {
        for (auto& it : scene->EnemyGroup->GetObjects())
        {
            if ((it->Position-Position).Magnitude()<=350 )
            {
				Target = dynamic_cast<Enemy*>(it);
				Target->Hit(500000);
			}
		}
    }
	hp -= damage;
	if (hp <= 0) {
        int x;
        int y;
		OnExplode();
		for (auto& it: lockedEnemys)
			it->Target = nullptr;
		for (auto& it: lockedEnemyBullets)
			it->Target = nullptr;
        y = (Position.y-PlayScene::BlockSize/2)/PlayScene::BlockSize;
        x = (Position.x-PlayScene::BlockSize/2)/PlayScene::BlockSize;
        scene->TurnTileFloor(y, x);             //tile_floor
		getPlayScene()->TowerGroup->RemoveObject(objectIterator);
		AudioHelper::PlayAudio("explosion.wav");
	}
}
void Turret::OnExplode() {
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
}
