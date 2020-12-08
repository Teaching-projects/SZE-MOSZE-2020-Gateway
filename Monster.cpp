#include "Monster.h"
#include "JSON.h"

const std::string& Monster::getName() const { return name; }

float Monster::getHp() const { return health_points; }

float Monster::getDmg() const { return damage; }

float Monster::getCd() const { return cooldown; }

float Monster::getTimer() const { return timer; }

void Monster::hpDown(Monster& unit, const float& damage) {
  unit.health_points -= damage;
  if (unit.health_points < 0) {
    unit.health_points = 0;
  }
}

void Monster::resetTheCooldown() {
  if (timer <= 0) {
    timer = getCd();
  }
}

void Monster::timeDown() { timer -= 0.1f; }

bool Monster::canHit() const { return timer <= 0; }

void Monster::attack(Monster& target) {
  if (isAlive() && canHit()) {
    hpDown(target,damage);
    resetTheCooldown();
  }
}

bool Monster::isAlive() const {
  return getHp() > 0;
}

Monster Monster::readJson(const std::string& filename) {
  Parser json;
  std::map<std::string, std::string> data = json.Fileparse(filename);
  return Monster(data["name"], std::stof(data["hp"]), std::stof(data["dmg"]), std::stod(data["cd"]));
}