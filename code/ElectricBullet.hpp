#ifndef ELECTRICBULLET_HPP
#define ELECTRICBULLET_HPP
#include "Bullet.hpp"
class ElectricBullet : public Bullet {
public:
    explicit ElectricBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif // ELECTRICBULLET_HPP
