#ifndef HERO_H
#define HERO_H

#include <string>
#include "Monster.h"

/**
 * \class Hero
 * 
 * \brief This is a class for the hero unit.
 * 
 * This class includes the extra data tags and functions for a hero.
 * 
 * \author hmartin28
 * 
 * \version 2.0
 * 
 * \date 2020/12/06 11:30
*/
class Hero : public Monster {

protected:

    float max_health_points; ///< The max health points of the hero.
    float level = 1; ///< The level of the hero.
    float xp = 0; ///< The experience points of the hero.

public:

    /// This is the constructor with the right parameters for inicialize a hero.
    Hero(const std::string& n, const float& h, const float& d, const float& c)
        : Monster(n,h,d,c), max_health_points(h) {}

    /**
     * \brief This simulates the attack motion of the Hero.
     * 
     * \param target A monster reference type.
     * 
     * In this function we call again the four functions: isAlive(), canHit(), hpDown() and resetTheCooldown.
     * If the Hero reaches the right amount of experience points, the hero reaches the next level.
     * Levelling up has some extra for the Hero, these are:
     * - The max health points increases by 20.
     * - The damage increases by 2.
     * - The current health points resets to the max healt points.
    */
    void attack(Monster& target);

    /**
     * \brief The fight between the two unit.
     * 
     * \param target A monster reference type.
     * 
     * In this function we check if both units is alive, then we call the attack function for the Hero, after that the timeDown, to decrease its timer.
     * After that we call the attack function for the target and the timeDown.
    */
    void fightTilDeath(Monster& target);

    /**
     * \brief A parser function for the class.
     * 
     * \param filename A const string reference type, its the name of the file.
     * 
     * This function calls the fileparser to parse the datas from a JSON file.
     * 
     * \return Monster
    */
    static Hero readJson(const std::string& filename);

    /// This is a simple getter for the level.
    float getLevel() const;

    /// This is a simple getter for the max health points.
    float getMaxHp() const;

};

#endif
