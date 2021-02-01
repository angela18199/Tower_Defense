#include "ElectricBullet.hpp"
#include "DirtyEffect.hpp"

ElectricBullet::ElectricBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
Bullet("play/bullet-7.png", 600, 2, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 2 (1/8): You can imitate the 2 files: 'ElectricBullet.hpp', 'ElectricBullet.cpp' to create a new bullet.
}
void ElectricBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

