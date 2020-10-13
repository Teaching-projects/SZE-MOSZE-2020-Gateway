#include <iostream>
#include <string>
#include "monster.hpp"

int main (int argc, char** argv) {
  /**
    * \brief This tests the argumentums numbers

    * \return -1, it indicates, if something is wrong

    * If theres not the exacts number of arguments, the program stop running
    */
  if (argc != 3) {
    std::cout << "Invalid arguments! You must give 3 arguments!" << std::endl;
    return -1;
  }

  /**
    * \brief This tests for the right argumentums

    * \return -1, it indicates, if something is wrong

    * If you misspelled the name of the files, you will get a warning message
    */
  try {
    Monster monster1 = Monster::readJson(argv[1]);
    Monster monster2 = Monster::readJson(argv[2]);
  }

  catch (const std::invalid_argument &exception) {
    std::cout << exception.what() << std::endl;
    return -1;
  }

  Monster monster1 = Monster::readJson(argv[1] /** [in] The first monster file name as param*/);
  Monster monster2 = Monster::readJson(argv[2] /** [in] The second monster file name as param*/);

  while ( (monster1.getHp() > 0) && (monster2.getHp() > 0) )
  {
    monster1.monsterCd(monster2);
    monster2.monsterCd(monster1);
  }

  if (monster1.isDefeated() == true) { std::cout << monster2.getName() << " wins. Remaining HP: " << monster2.getHp() << std::endl; }
  else { std::cout << monster1.getName() << " wins. Remaining HP: " << monster1.getHp() << std::endl; }

  return 0;
}
