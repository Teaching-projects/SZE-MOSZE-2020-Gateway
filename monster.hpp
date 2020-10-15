#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

private:

  const std::string name;
  int hp;
  const int dmg;

public:

  Monster(const std::string &n, const int &h, const int &d) : name(n), hp(h), dmg(d) {}

  std::string getName() const;
  int getHp() const;
  int getDmg() const;

  void monsterAttack(Monster &target) const;
  bool isDefeated() const;
  static Monster readJson(const std::string &filename);

};

#endif
