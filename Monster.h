#ifndef MONSTER_H
#define MONSTER_H

#include <string>

/**
 * \class Monster
 * 
 * \brief This is a class for the monster unit.
 * 
 * This class includes the data tags and functions for a monster.
 * 
 * \author hmartin28
 * 
 * \version 1.0
 * 
 * \date 2020/12/06 11:00
*/
class Monster {

protected:

  const std::string name; ///< The name of the monster.
  float health_points; ///< The current health of the monster.
  float damage; ///< The damage value of the monster.
  float cooldown; ///< The cooldown of the monster.
  float timer; ///< The current state of a monster's cooldown.

  /**
   * \brief Function to decrease the health.
   * 
   * \param unit A monster reference type, this units health is decreased in this function.
   * \param damage A const float reference type, this is the damage of the unit who deals the damage.
   * 
   * This function decereases the given units health, by the other units damage value. If the health would go under 0, it sets the health to 0.
  */
  void hpDown(Monster& unit, const float& damage);

public:

  /// This is the constructor with the right parameters for inicialize a monster.
  Monster(const std::string& n, const float& h, const float& d, const float& c)
    : name(n), health_points(h), damage(d), cooldown(c), timer(c) {}

  /**
   * \brief This simulates the attack motion of the Monster.
   * 
   * \param target A monster type reference.
   * 
   * In this function we call 4 functions. These are: isAlive(), canHit(), hpDown() and resetTheCooldown().
  */
  void attack(Monster& target);

  /**
   * \brief This resets a units cooldown.
   * 
   * If the timer reaches zero, then it sets the timer to the parsed cooldown.
  */
  void resetTheCooldown();

  /**
   * \brief Elapse time.
   * 
   * This function decreases the timers by 0.1 every time.
  */
  void timeDown();

  /**
   * \brief Is a unit alive.
   * 
   * This function checks, if a units alive, based on the health points.
   * 
   * \return bool
  */
  bool isAlive() const;

  /**
   * \brief If a unit can hit.
   * 
   * This function checks, if a units timer reaches zero.
   * 
   * \return bool
  */
  bool canHit() const;

  /**
   * \brief A parser function for the class
   * 
   * \param filename A const string reference type, its the name of the file which needs to be read.
   * 
   * This function calls the fileparser to parse the datas from a JSON file.
   * 
   * \return Monster
  */
  static Monster readJson(const std::string& filename);

  /// This is a simple getter for the name.
  const std::string& getName() const;

  /// This is a simple getter for the current health points.
  float getHp() const;

  /// This is a simple getter for the damage.
  float getDmg() const;

  /// This is a simple getter for the cooldown.
  float getCd() const;

  /// This is a simple getter for the timer.
  float getTimer() const;

};

#endif