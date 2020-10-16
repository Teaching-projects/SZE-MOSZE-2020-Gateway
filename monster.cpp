#include "monster.hpp"
#include <fstream>
#include <iostream>
#include <math.h>

const std::string& Monster::getName() const { return name; }

float Monster::getHp() const { return hp; }

float Monster::getDmg() const { return dmg; }

float Monster::getaktHp() const { return akthp; }

float Monster::getXp() const { return xp; }

float Monster::getpot_Xp() const { return pot_Xp; }

float Monster::getLvl() const { return lvl; }

void Monster::monsterAttack(Monster &target) {
  if (getaktHp() > 0) {
    if (target.akthp >= getDmg()) {
      pot_Xp += getDmg();
    }
    else {
      pot_Xp += target.akthp;
    }
    target.akthp -= getDmg();
    if (target.akthp < 0) {
      target.akthp = 0;
    }
    xp += pot_Xp;
    pot_Xp = 0;
    if (xp >= lvl*100) {
      float mp = floor(xp/100);
      lvl += mp;
      xp -= mp*100;
      hp = floor(hp*pow(1.1,mp));
      dmg = floor(dmg*pow(1.1,mp));
      akthp = hp;
    }
  }
}

bool Monster::isDefeated() const {
  if (akthp <= 0) return true;
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
