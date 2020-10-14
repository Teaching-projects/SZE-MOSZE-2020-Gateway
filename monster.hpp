/**
 * \class Monster
 *
 * \ingroup Monster package
 *
 * \brief Monster class
 *
 * This class contains a monsters attributes, which can change it the future.
 * For now, the monster class has 5 members. These are:
 * name, hp, dmg, cd, cd_c
 *
 * \author hmartin28
 *
 * \version 1.0
 *
 * \date 2020/10/14 17:22
 *
 * Created on: 2020/10/14 17:22
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {

protected:

  const std::string name; ///< name of the monster
  int hp; ///< health of the monster
  const int dmg; ///< damage of the monster
  const double cd; ///< cooldown of the monster
  double cd_c = 0; ///< cooldown counter for the monster

  /**
   * \brief This is a function to decrease a monsters health points
   *
   * \param target It is a monster type.
   *
   * This funciton is called to decrease a monsters health with the opponents damage number
   * We call this funciton in the main.cpp like this: monster1.monsterAttack(monster2);
   */
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

  /**
   * \brief This is the main part of the cooldown counter program
   *
   * \param target It is a monster type.
   *
   * In this function we watch the cooldown counter, and we decrease its number until it reaches 0.
   * If the number reaches 0, we hit the other monster, and we reset its cooldown and start again until one of the monster is not dead.
   */
  void monsterCd(Monster &target);
  /**
   * \brief This function is called to decide which monsters is dead
   *
   * \param none
   *
   * \return true if the monsters is dead
   * \return false if its not dead
   */
  bool isDefeated() const;
  /**
   * \brief This function is for reading the data members from a json file
   *
   * \param filename It must be an existing json file.
   *
   * \return monster, with the right attributes (name,hp,dmg,cd)
   */
  static Monster readJson(const std::string &filename);

};

#endif
