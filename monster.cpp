#include "monster.hpp"
#include "parser.hpp"
#include <fstream>
#include <iostream>

std::string Monster::getName() const { return name; }

int Monster::getHp() const { return hp; }

int Monster::getDmg() const { return dmg; }

float Monster::getAttackcooldown()const{return attackcooldown;}

void Monster::monsterAttack(Monster &target) const {
  if (hp > 0) target.hp -= getDmg();
}

bool Monster::isDefeated() const {
  if (hp <= 0) return true;
  else return false;
}

Monster Monster::readJson(const std::string &filename) {
  Parser json;
  std::map<std::string, std::string> data =json.Fileparse(filename);
  return Monster(data["name"], std::stoi(data["hp"]), std::stoi(data["dmg"]), std::stof(data["attackcooldown"]));
}
