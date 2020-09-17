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
    std::cout << name << " (" << hp << ")" << " hits " << monster.getName() << " and deals " << dmg << " damage!" << std::endl;
    monster.hpDown(dmg);
  }
}

void Monster::whoWon(Monster &monster) {
  if (hp < 0) {
    std::cout << monster.getName() << " defeated " << name << std::endl;
  }
  else {
    std::cout << name << " defeated " << monster.getName() << std::endl;
  }
}
