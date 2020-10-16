#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

private:

  const std::string name;
  float hp;
  float dmg;
  float akthp;
  float xp = 0;
  float lvl = 1;

public:

  Monster(const std::string &n, const int &h, const int &d) : name(n), hp(h), dmg(d), akthp(h) {}

  std::string getName() const;
  float getHp() const;
  float getDmg() const;
  float getaktHp() const;
  float getXp() const;
  float getLvl() const;

  void monsterAttack(Monster &target);
  bool isDefeated() const;
  static Monster readJson(const std::string &filename);

};

#endif
