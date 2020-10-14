#include "monster.hpp"
#include <fstream>
#include <iostream>

std::string Monster::getName() const { return name; }

int Monster::getHp() const { return hp; }

int Monster::getDmg() const { return dmg; }

double Monster::getCd() const { return cd; }

double Monster::getCd_c() const { return cd_c; }

void Monster::monsterAttack(Monster &target /** [in] Monster type param*/) const {
  if (hp > 0) {
    target.hp -= getDmg();
  }
}

bool Monster::monsterCd(Monster &target /** [in] Monster type param*/){
  if (cd_c >= 0.1) {
    cd_c -= 0.1;
  }
  else {
    if (target.cd_c == cd_c) {
      monsterAttack(target);
    }
    monsterAttack(target);
    cd_c = getCd();
  }
}

bool Monster::isDefeated() const {
  if (hp <= 0) return true;
  else return false;
}

/**
  * \brief This functions read the datas of the monsters from a json file

  * \return A Monster type with the right datas

  The functions search for particular parts to find the rifght data to put into the variables
  */
Monster Monster::readJson(const std::string &filename /** [in] This file names param*/) {
  std::ifstream file(filename);

  if (file.is_open()) {

    std::string name; ///< Variable for monsters name
    int hp; ///< Variable for monsters health points
    int dmg; ///< Variable for monsters damage
    double cd; ///< Variable for monsters cooldown
    std::string line; ///< Variable for the read lines

    std::getline(file,line);

    ///< The variable for the position of the colon
    int posColon;
    ///< The variable for the position of the comma
    int posComma;

    /// This reads a line from a file
    std::getline(file,line);
    /// This finds the position of the colon
    posColon = line.find(':');
    /// This finds the position of the coma
    posComma = line.find(',');
    /// This puts a substring to the name variable
    name = line.substr(posColon+3,(posComma-1)-(posColon+3));

    std::getline(file,line);
    posColon = line.find(':');
    posComma = line.find(',');
    /// This puts a substring to the hp variable
    hp = stoi(line.substr(posColon+2,(posComma-1)-(posColon+1)));

    std::getline(file,line);
    posColon = line.find(':');
    posComma = line.find(',');
    /// This put a substring to the dmg variable
    dmg = stoi(line.substr(posColon+2));

    std::getline(file,line);
    posColon = line.find(':');
    /// This puts a substring to the cd variable
    cd = std::stod(line.substr(posColon+2));

    /// This closes the file
    file.close();

    Monster monster(name,hp,dmg,cd);
    /// This return a Monster type
    return monster;
  }

  else {
    throw std::invalid_argument("Invalid file name");
  }
}
