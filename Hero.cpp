#include "Hero.h"
#include "JSON.h"
#include <cmath>

float Hero::getLevel() const { return level; }

float Hero::getMaxHp() const { return max_health_points; }

void Hero::attack(Monster& target) {
  if (isAlive() && canHit()) {
    hpDown(target,damage);
    if (target.getHp() >= getDmg()) {
      xp += damage;
    }
    else {
      xp += target.getHp();
    }
    if (xp >= level * 100) {
      int mp = floor(xp / 100);
      level += mp;
      xp -= mp * 100;
      max_health_points += round(pow(1.1,mp));
      damage += round(pow(1.1,mp));
      cooldown *= pow(0.9,mp);
      health_points = max_health_points;
    }
  }
  resetTheCooldown();
}

void Hero::fightTilDeath(Monster& target) {
  if (isAlive() && target.isAlive()) {
    attack(target);
    timeDown();

    target.attack(*this);
    timeDown();
    target.timeDown();
  }
}

Hero Hero::readJson(const std::string& filename) {
  Parser json;
  std::map<std::string, std::string> data = json.Fileparse(filename);
  return Hero(data["name"], std::stof(data["hp"]), std::stof(data["dmg"]), std::stof(data["cd"]));
}
