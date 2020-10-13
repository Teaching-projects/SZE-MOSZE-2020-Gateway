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
  double cd_c; ///< The cooldown counter of the monster

  void monsterAttack(Monster &target) const; /// This funcitons decerease a monsters health by the other monsters damage

public:

  Monster(const std::string &n, int &h, const int &d, const double c) : name(n), hp(h), dmg(d), cd(c), cd_c(c) {} /// This is the constructor
  std::string getName() const; /// This is a simple getter for a monsters name
  int getHp() const; /// This is a simple getter for a monsters name health points
  int getDmg() const; /// This is a simple getter for a monsters name damage
  double getCd() const; /// This is a simple getter for a monsters cooldown

  bool monsterCd(Monster &target); /// This is a funciton to decrease the cooldown of a monster
  bool isDefeated() const; /// This funciton decides if a monster is defeated (health is lower or equal zero)
  static Monster readJson(const std::string &filename); /// This is a function to read the monsters attributes

};

#endif
