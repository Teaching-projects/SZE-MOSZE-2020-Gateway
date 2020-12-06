#include "Hero.h"
#include "JSON.h"
#include <cmath>

float Hero::getLevel() const { return level; }

float Hero::getMaxHp() const { return maxhp; }

void Hero::attack(Monster& target) {
  if (isAlive() && canHit()) {
    hpDown(target,dmg);
    if (target.getHp() > getDmg()) {
      xp += dmg;
    }
    else if (target.getHp() <= getDmg()) {
      xp += target.getHp();
    }
    if (xp >= level * 100) {
      int mp = floor(xp / 100);
      level += mp;
      xp -= mp * 100;
      maxhp += 20;
      dmg += 2;
      hp = maxhp;
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
