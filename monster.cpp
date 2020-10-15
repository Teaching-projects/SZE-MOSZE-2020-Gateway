#include "monster.hpp"
#include "parser.hpp"
#include <fstream>
#include <iostream>

std::string Monster::getName() const { return name; }

int Monster::getHp() const { return hp; }

int Monster::getDmg() const { return dmg; }

void Monster::monsterAttack(Monster &target) const {
  if (hp > 0) target.hp -= getDmg();
}

bool Monster::isDefeated() const {
  if (hp <= 0) return true;
  else return false;
}

Monster Monster::readJson(const std::string &filename) {
  Parser json;
  json.fileparser(filename);
  return Monster(json.readstring("name"), json.readint("hp"), json.readint("dmg"));
}
