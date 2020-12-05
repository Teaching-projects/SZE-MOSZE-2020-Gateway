#include "Monster.h"
#include "JSON.h"
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
  Parser json;
  std::map<std::string, std::string> data = json.Fileparse(filename);
  return Monster(data["name"], std::stoi(data["hp"]), std::stoi(data["dmg"]), std::stof(data["cd"]));
}
