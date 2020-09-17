#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>

class Monster {

  std::string name;
  int hp;
  int dmg;

public:

  Monster(const std::string &nn, const int &hh, const int &dd) : name(nn), hp(hh), dmg(dd) {}

  std::string getName() const;

  int getHp() const;

  int getDmg() const;

  void hpDown(int dmg);

  void monsterAttack(Monster &monster);

  void whoWon(Monster &monster);

};

#endif
