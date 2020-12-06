#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

protected:

  const std::string name;
  float hp;
  float dmg;
  float cd;
  float timer;

public:

  Monster(const std::string& n, const float& h, const float& d, const float& c)
    : name(n), hp(h), dmg(d), cd(c), timer(c) {}

  void hpDown(Monster& unit, const float& dmg);
  void attack(Monster& target);
  void resetTheCooldown();
  void timeDown();
  bool isAlive() const;
  bool canHit() const;
  static Monster readJson(const std::string& filename);

  const std::string& getName() const;
  float getHp() const;
  float getDmg() const;
  float getCd() const;
  float getTimer() const;

};

#endif