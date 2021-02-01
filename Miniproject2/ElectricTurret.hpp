#ifndef ELECTRICTURRET_HPP
#define ELECTRICTURRET_HPP
#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class ElectricTurret: public Turret {
public:
    static const int Price;
    ElectricTurret(float x, float y);
    void CreateBullet() override;
};
#endif // ELECTRICTURRET_HPP
