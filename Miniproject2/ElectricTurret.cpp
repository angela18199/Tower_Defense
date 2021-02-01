#include "PlayScene.hpp"
#include "ElectricTurret.hpp"
#include "ElectricBullet.hpp"
#include "AudioHelper.hpp"

const int ElectricTurret::Price = 150;
ElectricTurret::ElectricTurret(float x, float y) :
// TODO 2 (2/8): You can imitate the 2 files: 'ElectricTurret.hpp', 'ElectricTurret.cpp' to create a new turret.
Turret("play/tower-base.png", "play/turret-7.png", x, y, 200, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void ElectricTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new ElectricBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
