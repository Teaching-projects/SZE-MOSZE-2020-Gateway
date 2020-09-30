#include "monster.hpp"
#include <fstream>
#include <iostream>

std::string Monster::getName() const { return name; }

int Monster::getHp() const { return hp; }

int Monster::getDmg() const { return dmg; }

// void Monster::hpDown(int dmg) { hp -= dmg; }

void Monster::monsterAttack(Monster &target) const {
  if (hp > 0) target.hp -= getDmg();
}

bool Monster::isDefeated() const {
  if (hp <= 0) return true;
  else return false;
}

Monster Monster::readJson(const std::string &filename) {
  std::ifstream file(filename);

  if (file.is_open()) {

    std::string name;
    int hp;
    int dmg;
    std::string line;

    std::getline(file,line);

    int posColon;
    int posComma;

    std::getline(file,line);
    posColon = line.find(':');
    posComma = line.find(',');
    name = line.substr(posColon+3,(posComma-1)-(posColon+3));

    std::getline(file,line);
    posColon = line.find(':');
    posComma = line.find(',');
    hp = stoi(line.substr(posColon+2,(posComma-1)-(posColon+1)));

    std::getline(file,line);
    posColon = line.find(':');
    posComma = line.find(',');
    dmg = stoi(line.substr(posColon+2));

    file.close();

    Monster monster(name,hp,dmg);
    return monster;

  }

  else {
    throw std::invalid_argument("Invalid file name");
  }

}
