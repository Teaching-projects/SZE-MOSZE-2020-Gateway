#ifndef HERO_HEADER
#define HERO_HEADER

#include "Monster.h"

class Hero : public Monster 
{
    public:
    Hero(const std::string&, const int, const int, const float);    
    /// This is a simple getter for a monsters level
    int getLevel() const;
    /// This is a simple getter for potential experience
    int getXp() const;
    /// This is a simple getter for a monsters experience points
    int getMaxHealthPoints() const;

    void Attack(Monster&);
    static Hero parse(const std::string&);

    private:
    int xp = 0;
    int level = 1;
    int maxHealth;
    const int ExperiencePerLevel; 
    const int HealthPointBonusPerLevel;
    const int DamageBonusPerLevel;
    const float ColdownMultiplierPerLevel;

    void LevelUp();
};

#endif 