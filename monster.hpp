#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

private:

  std::string name;
  int hp;
  int dmg;

public:

  Monster() {}
  Monster(const std::string &n, const int &h, const int &d) : name(n), hp(h), dmg(d) {}

  // getterek
  std::string getName() const;
  int getHp() const;
  int getDmg() const;

  // mainbe használt függvények
  void hpDown(int dmg);
  void monsterAttack(Monster &monster);
  bool isDefeated() const;
  static Monster readJson(const std::string &filename);

};

#endif
