#include <iostream>
#include <string>
#include "monster.hpp"

int main (int argc, char** argv) {

  if (argc != 3) {
    std::cout << "Invalid arguments! You must give 3 arguments!" << std::endl;
    return -1;
  }

  try {
    Monster monster1 = Monster::readJson(argv[1]);
    Monster monster2 = Monster::readJson(argv[2]);
  }

  catch (const std::invalid_argument &exception) {
    std::cout << exception.what() << std::endl;
    return -1;
  }

  Monster monster1 = Monster::readJson(argv[1]);
  Monster monster2 = Monster::readJson(argv[2]);

  while ( (monster1.getHp() > 0) && (monster2.getHp() > 0) ) {

    if (monster1.getHp() > 0) {
      monster1.monsterAttack(monster2);
    }

    if (monster2.getHp() > 0) {
      monster2.monsterAttack(monster1);
    }

  }

  if (monster1.isDefeated() == true) { std::cout << monster2.getName() << " wins. Remaining HP: " << monster2.getHp() << std::endl; }
  else { std::cout << monster1.getName() << " wins. Remaining HP: " << monster1.getHp() << std::endl; }

  return 0;
}
