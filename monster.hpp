#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

private:

  const std::string name;
  int hp;
  const int dmg;
  const double cd;
  double cd_c;

  void monsterAttack(Monster &target) const;

public:

  Monster(const std::string &n, int &h, const int &d, const double c) : name(n), hp(h), dmg(d), cd(c), cd_c(c) {}
  std::string getName() const;
  int getHp() const;
  int getDmg() const;
  double getCd() const;

  bool monsterCd(Monster &target);
  bool isDefeated() const;
  static Monster readJson(const std::string &filename);

};

#endif
