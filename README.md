# SZE-MOSZE-2020-Gateway

The program shows two monsters who are hitting each other, and at the end of the fight one of them dies.

You have to run ./a.out with json files, for example: ./a.out units/monster1.json units/monster2.json

There are two main functions used in the main.cpp:
  * monsterAttack: This fuction is called to decrease the health of the monster who is given in the functions argument.
  * isDefeated: This function is called to check the health of a monster and returning 1 if the monster health is <= 0.
  * readJson: This function is called to read the parameters of the monsters from a Json file. In case of an error (eg the file does not exist), it returns an error message.
  * monsterCd: This funciton is called to decrease the cooldown for the next hit.

GitHub Pages Dokumentáció:
https://teaching-projects.github.io/SZE-MOSZE-2020-Gateway/pages.html
