#include <iostream>
#include <string>

struct Monster {
  Monster(const std::string &nn, const int &hh, const int &dd) : name(nn), hp(hh), dmg(dd) {}
  ~Monster() {}
  std::string name;
  int hp;
  int dmg;
};

void monsterAttack(Monster &monster1, Monster &monster2) {
  while ( (monster1.hp > 0) && (monster2.hp > 0) ) {
    if (monster1.hp > 0) {
      std::cout << monster1.name << " (" << monster1.hp << ")" << " hits " << monster2.name << " and deals " << monster1.dmg << " damage!" << std::endl;
      monster2.hp -= monster1.dmg;
    }
    if (monster2.hp > 0) {
      std::cout << monster2.name << " (" << monster2.hp << ")" << " hits " << monster1.name << " and deals " << monster2.dmg << " damage!" << std::endl << std::endl;
      monster1.hp -= monster2.dmg;
    }
  }
}

void compare(const Monster &monster1, const Monster &monster2) {
  if (monster1.hp <= 0) {
    std::cout << monster2.name << " defeated " << monster1.name << std::endl;
  }
  else if (monster2.hp <= 0) {
    std::cout << monster1.name << " defeated " << monster2.name << std::endl;
  }
}

int main (int argc, char** argv) {

  Monster monster1(argv[1], atoi(argv[2]), atoi(argv[3]));
  Monster monster2(argv[4], atoi(argv[5]), atoi(argv[6]));

  std::cout << monster1.name << " HP: " << monster1.hp << " DMG: " << monster1.dmg << std::endl;
  std::cout << monster2.name << " HP: " << monster2.hp << " DMG: " << monster2.dmg << std::endl << std::endl;

  monsterAttack(monster1, monster2);

  compare(monster1, monster2);

  return 0;
}
