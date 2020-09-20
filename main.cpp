#include <iostream>
#include <string>
#include "monster.hpp"

int main (int argc, char** argv) {

  bool error = false;

  Monster monster1(argv[1], atoi(argv[2]), atoi(argv[3]));
  Monster monster2(argv[4], atoi(argv[5]), atoi(argv[6]));

  if (argc != 7) {
    std::cerr << "Invalid arguments! You must type 7 arguments!" << std::endl;
    error = true;
  }
  if (atoi(argv[2]) == 0L) {
    std::cout << "The third argument must be a number!" << std::endl;
    error = true;
  }
  if (atoi(argv[3]) == 0L) {
    std::cout << "The fourth argument must be a number!" << std::endl;
    error = true;
  }
  if (atoi(argv[5]) == 0L) {
    std::cout << "The sixth argument must be a number!" << std::endl;
    error = true;
  }
  if (atoi(argv[6]) == 0L) {
    std::cout << "The seventh argument must be a number!" << std::endl;
    error = true;
  }
  if (error) {
    return -1;
  }

  std::cout << monster1.getName() << " HP: " << monster1.getHp() << " DMG: " << monster1.getDmg() << std::endl;
  std::cout << monster2.getName() << " HP: " << monster2.getHp() << " DMG: " << monster2.getDmg() << std::endl << std::endl;

  while ( (monster1.getHp() > 0) && (monster2.getHp() > 0) ) {
    if (monster1.getHp() > 0) {
      std::cout << monster1.getName() << " [" << monster1.getHp() << "]" << " attacks " << monster2.getName() << " and deals: " << monster1.getDmg() << " damage!\n";
      monster1.monsterAttack(monster2);
    }
    std::cout << std::endl;
    if (monster2.getHp() > 0) {
      std::cout << monster2.getName() << " [" << monster2.getHp() << "]" << " attacks " << monster1.getName() << " and deals: " << monster2.getDmg() << " damage!\n";
      monster2.monsterAttack(monster1);
    }
  }
  std::cout << std::endl;
  if (monster1.isDefeated() == true) {
    std::cout << monster2.getName() << " defeated " << monster1.getName() << std::endl;
  }
  else {std::cout << monster1.getName() << " defeated " << monster2.getName() << std::endl;}

  return 0;
}
