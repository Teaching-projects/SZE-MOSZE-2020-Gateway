#include <iostream>
#include "Monster.h"
#include "Hero.h"
#include "JSON.h"

int main (int argc, char** argv) {

  if (argc != 3) {
    std::cout << "Invalid arguments! You must give 3 arguments!" << std::endl;
    return -1;
  }

  try {
    Hero hero = Hero::readJson(argv[1]);
    Monster monster = Monster::readJson(argv[2]);

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << '\t' << hero.getName()
    << " HP: " << hero.getHp()
    << " DMG: " << hero.getDmg()
    << " CD: " << hero.getCd() 
    << " LVL: " << hero.getLevel() << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << '\t' << monster.getName()
    << " HP: " << monster.getHp()
    << " DMG: " << monster.getDmg()
    << " CD: " << monster.getCd() << std::endl;
    std::cout << "------------------------------------------------------" << std::endl << std::endl;

    while ( hero.isAlive() && monster.isAlive() ) {
      hero.fightTilDeath(monster);
    }

    if (hero.isAlive()) {
      std::cout << hero.getName() << " wins. Remaining HP: " << hero.getHp()
      << " | MAXHP: " << hero.getMaxHp() << ", DMG: " << hero.getDmg() << ", LVL: " << hero.getLevel() << " |" << std::endl << std::endl;
    }

    else {
      std::cout << monster.getName() << " wins. Remaining HP: " << monster.getHp() << std::endl;
    }
  }

  catch (const std::invalid_argument &exception) {
    std::cout << exception.what() << std::endl;
    return -1;
  }

  return 0;
}
