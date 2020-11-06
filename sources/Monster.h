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

  private:
    static void RemoveChar(std::string & /** [in] The target string the charater(s) need to be removed from */, const char /** [in] The charater to be removed*/); ///< Removes specified characters from a given string. Used by the parseMonster function
    void SufferDamage(int); ///< Lowers a unit's health value by the specified amount
    

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
  Monster(const std::string &n, const float &h, const float &d, const float& c) : name(n), maxhp(h), dmg(d), cd(c), akthp(h){}
   /// This is a simple getter for a monsters name
  const std::string &getName() const;
  /// This is a simple getter for a monsters max health points
  float getmaxHp() const;
  /// This is a simple getter for a monsters name damage
  float getDamage() const;
  /// This is a simple getter for a monsters actual health points
  float getHealthPoints() const;
  /// This is a simple getter for a monsters experience points
  //float getXp() const;
  
  //float getLvl() const;
  
  //float getpot_Xp() const;
  /// This is a simple getter for a monsters cooldown
  float getCd() const;
  /// This is a simple getter for a monster cooldown counter
  float getAttackCoolDown() const;

  /**
   * \brief This is the main part of the cooldown counter program
   *
   * \param target It is a monster type
   *
   * In this function we watch the cooldown counter, and we decrease its number until it reaches 0
   * If the number reaches 0, we hit the other monster and we reset its cooldown and start again until one of the monster is not dead
   */
  void monsterCd(Monster &target);
  virtual void Attack(Monster &enemy);
  
  /**
   * \brief This function is called to decide which monster is isdead
   *
   * \param none
   *
   * \return true if the monster is dead
   * \return false if its not dead
   */
  bool isAlive() const;

  /**
   * \brief This function is for reading the data members from a json file
   *
   * \param filename It must be an existing json file.
   *
   * \return monster, with the right attributes (name,hp,dmg,cd)
   */
  static Monster parse(const std::string&/** [in] The name of the file to be parsed*/);

  void fightTilDeath(Monster & /** [in] The Monster the attack is targeting*/);

};

#endif
