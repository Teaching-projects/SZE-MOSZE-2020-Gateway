#include "monster.h"
#include "JSON.h"
#include <fstream>
#include <iostream>
#include <math.h>

const std::string& Monster::getName() const { return name; }

float Monster::getmaxHp() const { return maxhp; }

float Monster::getDamage() const { return dmg; }

float Monster::getHealthPoints() const { return akthp; }

/*float Monster::getXp() const { return xp; }*/

/*float Monster::getLvl() const { return lvl; }*/

float Monster::getCd() const { return cd; }

float Monster::getAttackCoolDown() const { return cd_c; }



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
bool Monster::isAlive() const {
  if (akthp <= 0) return true;
  else return false;
}

void Monster::fightTilDeath(Monster &enemy){
   float attackerTime = 0;
    float enemyTime = 0;

    while(this->isAlive() && enemy.isAlive())
    {
        cd_c = 0;
        if(attackerTime < enemyTime)
        {
            this->Attack(enemy);
            enemyTime -= attackerTime;
            attackerTime = this->getCd();
        } 
        else if(attackerTime > enemyTime)
        {   
            enemy.Attack(*this);
            attackerTime -= enemyTime;
            enemyTime = enemy.getCd();
        } 
        else 
        {
            this->Attack(enemy);
            attackerTime = this->getCd();
            enemyTime = 0;
        }
    }
}
void Monster::Attack(Monster &enemy)
{
    enemy.SufferDamage(this->dmg);
}

void Monster::SufferDamage(int damageRecieved)
{
    akthp -= damageRecieved;
    if (akthp < 0)
    {
        akthp = 0;
    }
}

Monster Monster::parse(const std::string&) {
  JSON data = JSON::Fileparse(filename);
    return Monster(data.get<std::string>("name"), data.get<int>("hp"), data.get<int>("dmg"), data.get<float>("cd"));
}
