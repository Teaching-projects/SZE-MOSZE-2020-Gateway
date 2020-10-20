#include "monster.hpp"
#include <fstream>
#include <iostream>
#include <math.h>

const std::string& Monster::getName() const { return name; }

float Monster::getmaxHp() const { return maxhp; }

float Monster::getDmg() const { return dmg; }

float Monster::getaktHp() const { return akthp; }

float Monster::getXp() const { return xp; }

float Monster::getLvl() const { return lvl; }

float Monster::getCd() const { return cd; }

float Monster::getCd_c() const { return cd_c; }

void Monster::monsterAttack(Monster &target) {
  float pot_Xp = 0;

  if (akthp <= 0) return;

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

  if (xp >= lvl * 100) {
    int mp = floor(xp/100);
    lvl += mp;
    xp -= mp * 100;
    maxhp = round(maxhp * pow(1.1,mp));
    dmg = round(dmg * pow(1.1,mp));
    akthp = maxhp;
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
  if (akthp <= 0) return true;
  else return false;
}

Monster Monster::readJson(const std::string &filename) {
  std::ifstream file(filename);

  if (file.is_open()) {

    std::string name;
    float maxhp;
    float dmg;
    float cd;
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
    maxhp = stof(line.substr(posColon+2,(posComma-1)-(posColon+1)));

    std::getline(file,line);
    posColon = line.find(':');
    posComma = line.find(',');
    dmg = stof(line.substr(posColon+2));

    std::getline(file,line);
    posColon = line.find(':');
    cd = std::stof(line.substr(posColon+2));

    file.close();

    Monster monster(name,maxhp,dmg,cd);
    return monster;
  }

  else {
    throw std::invalid_argument("Invalid file name");
  }
}
