/**
  * \class Monster

  * \brief Monster class

  * This class contains a monsters attributes

  * \version 1.0

  * \date 2020/10/13 18:04

  Created on: 2020/10/13 18:04
  */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

private:

  const std::string name; ///< The name of the monster
  int hp; ///< The health points of the monster
  const int dmg; ///< The attack damage of the monster
  const double cd; ///< The cooldown of the monster
  double cd_c = 0; ///< The cooldown counter of the monster

  /// This funcitons decerease a monsters health by the other monsters damage
  void monsterAttack(Monster &target) const;

public:

  /// This is the constructor
  Monster(const std::string &n, int &h, const int &d, const double c) : name(n), hp(h), dmg(d), cd(c){}
  /// This is a simple getter for a monsters name
  std::string getName() const;
  /// This is a simple getter for a monsters name health points
  int getHp() const;
  /// This is a simple getter for a monsters name damage
  int getDmg() const;
  /// This is a simple getter for a monsters cooldown
  double getCd() const;
  /// This is a simple getter for a monster cooldown counter
  double getCd_c() const;

  /// This is a funciton to decrease the cooldown of a monster
  bool monsterCd(Monster &target);
  /// This funciton decides if a monster is defeated (health is lower or equal zero
  bool isDefeated() const;
  /// This is a function to read the monsters attributes
  static Monster readJson(const std::string &filename);

};

#endif
