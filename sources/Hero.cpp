#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string& name, const int health, const int damage, const float atkcooldown) : Monster{name, health, damage, atkcooldown}, maxHealth(health)
{
}

int Hero::getLevel() const 
{
    return level;
}

int Hero::getXp() const 
{
    return xp;
}

int Hero::getMaxHealthPoints() const 
{
    return maxHealth;
}

void Hero::LevelUp() 
{
    level += 1;
    dmg += dmg * 0.1;
    maxHealth += maxHealth * 0.1;
    dmg += DamageBonusPerLevel;
    cd_c *= ColdownMultiplierPerLevel;
    maxHealth += HealthPointBonusPerLevel;
    akthp= maxHealth;
}

void Hero::Attack(Monster& enemy) 
{
    Monster::Attack(enemy);
    xp += dmg;
    if(enemy.isAlive())
    {
    while(level - 1 != (xp / 100))
    {
        LevelUp();
    }
    }
    xp += dmg;
}

Hero Hero::parse(const std::string& fileName)
{
    Monster parsedMonster = Monster::readJson(fileName);
    return Hero(parsedMonster.getName(), parsedMonster.getmaxHp(), parsedMonster.getDmg(), parsedMonster.getCd());
} 