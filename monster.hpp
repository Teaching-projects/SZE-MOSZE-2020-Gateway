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
  float maxhp; ///< max health of the monster
  float dmg; ///< dmg of the monster
  const float cd; ///< cooldown of the monster
  float akthp; ///< actual hp of the monster
  float xp = 0; ///< experience of the monster
  float lvl = 1; ///< level of the monster
  float cd_c = 0; ///< cooldown counter for the monster

  /**
   * \brief This is a function to decrease a monsters health points
   *
   * \param target It is a monster type.
   *
   * This funciton is called to decrease a monsters health with the opponents damage number
   * We call this funciton in the main.cpp like this: monster1.monsterAttack(monster2);
   */
  void monsterAttack(Monster &target);

public:

  /// This is the constructor
  Monster(const std::string &n, const float &h, const float &d, const double& c) : name(n), maxhp(h), dmg(d), cd(c), akthp(h){}
  /// This is a simple getter for a monsters name
  const std::string &getName() const;
  /// This is a simple getter for a monsters max health points
  float getmaxHp() const;
  /// This is a simple getter for a monsters name damage
  float getDmg() const;
  /// This is a simple getter for a monsters actual health points
  float getaktHp() const;
  /// This is a simple getter for a monsters experience points
  float getXp() const;
  /// This is a simple getter for a monsters level
  float getLvl() const;
  /// This is a simple getter for potential experience
  float getpot_Xp() const;
  /// This is a simple getter for a monsters cooldown
  float getCd() const;
  /// This is a simple getter for a monster cooldown counter
  float getCd_c() const;

  /**
   * \brief This is the main part of the cooldown counter program
   *
   * \param target It is a monster type
   *
   * In this function we watch the cooldown counter, and we decrease its number until it reaches 0
   * If the number reaches 0, we hit the other monster and we reset its cooldown and start again until one of the monster is not dead
   */
  void monsterCd(Monster &target);

  /**
   * \brief This function is called to decide which monster is isdead
   *
   * \param none
   *
   * \return true if the monster is dead
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
