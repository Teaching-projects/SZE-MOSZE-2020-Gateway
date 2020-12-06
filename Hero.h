#ifndef HERO_H
#define HERO_H

#include <string>
#include "Monster.h"

class Hero : public Monster {

private:

    float maxhp;
    float level = 1;
    float xp = 0;

    void attack(Monster& target);

public:

    Hero(const std::string& n, const float& h, const float& d, const float& c)
        : Monster(n,h,d,c), maxhp(h) {}

    void fightTilDeath(Monster& target);
    void potentionalXp(Monster& target);
    static Hero readJson(const std::string& filename);

    float getLevel() const;
    float getMaxHp() const;

};

#endif
