#include "monster.hpp"

std::string Monster::getName() const {
  return name;
}

int Monster::getHp() const {
  return hp;
}

int Monster::getDmg() const {
  return dmg;
}

void Monster::hpDown(int dmg) {
  hp -= dmg;
}

void Monster::monsterAttack(Monster &monster) {
  if (hp > 0) {
    monster.hpDown(dmg);
  }
}

bool Monster::isDefeated() const {
  if (hp <= 0) {
    return true;
  }
  else return false;
}
