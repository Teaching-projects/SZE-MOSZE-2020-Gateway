#include "monster.hpp"
#include <fstream>
#include <iostream>

std::string Monster::getName() const { return name; }

int Monster::getHp() const { return hp; }

int Monster::getDmg() const { return dmg; }

double Monster::getCd() const { return cd; }

double Monster::getCd_c() const { return cd_c; }

void Monster::monsterAttack(Monster &target) const {
  if (hp > 0) {
    target.hp -= getDmg();
  }
}

void Monster::monsterCd(Monster &target){
  if (cd_c >= 0.1) {
    cd_c -= 0.1;
  }
  else {
    if (target.cd_c == cd_c) {
      monsterAttack(target);
    }
    monsterAttack(target);
    cd_c = getCd();
  }
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
    double cd;
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

    std::getline(file,line);
    posColon = line.find(':');
    cd = std::stod(line.substr(posColon+2));

    file.close();

    Monster monster(name,hp,dmg,cd);
    return monster;
  }

  else {
    throw std::invalid_argument("Invalid file name");
  }
}
