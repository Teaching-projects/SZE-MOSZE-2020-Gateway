# SZE-MOSZE-2020-Gateway

The program simulates a fight between a Hero and a Monster.
  
There are two classes dedicated to the fighters. Theres a class called **Monster** and a derived class, called **Hero**. The monster class has 5 data tags, these are: *name, healthpoints, damage, cooldown and timer*, the Hero class has additional private data tags. Such as *maxhp, level and xp*.

# Functions

The main functions that the **Monster** class has:

``` Monster(const std::string& n, const float& h, const float& d, const float& c) : name(n), hp(h), dmg(d), cd(c), timer(c) {} ``` -> This is the constructor

``` void hpDown(Monster& unit, const float& dmg); ``` -> Decrease a units health by the attacker's damage.

``` void resetTheCooldown(); ``` -> If a units timer reaches zero or below, it is resets the timer with the parsed cooldown.

``` void timeDown(); ``` -> Decrease the timer value by 0.1.

``` bool isAlive() const; ``` -> Checks if a units health points is above 0.

``` bool canHit() const; ``` -> Returns the timer value with zero or below 0, that indicates the unit is ready to hit.

``` static Monster readJson(const std::string& filename); ``` -> This parses a monster data from a JSON file.

``` void attack(Monster& target); ``` -> This function attacks the other unit, the **hpDown, resetTheCooldown, isAlive and canHit** is called in this function.

The functions that the **Hero** class has:

``` Hero(const std::string& n, const float& h, const float& d, const float& c) : Monster(n,h,d,c), maxhp(h) {} ``` -> This is the constructor

``` void fightTilDeath(Monster& target);  ``` -> This simulates the fight between the two unit, until one of them is dead.

``` static Hero readJson(const std::string& filename);  ``` -> This parses the Hero data from a JSON file.

# JSON

An example for the JSON file:
```
{
  "name" : "Eivar",
  "hp" : 1000,
  "dmg" : 40,
  "cd" : 0.8
}
```
# Output and test script

The result of the fight looks like this: 
```
------------------------------------------------------
	Eivar HP: 1000 DMG: 40 CD: 0.8 LVL: 1
------------------------------------------------------
------------------------------------------------------
	Sigurd HP: 1360 DMG: 40 CD: 1.7
------------------------------------------------------
Eivar wins. Remaining HP: 900 | MAXHP: 1060, DMG: 46, LVL: 8 |
```

The test script runs all the possible fights, and in the BuildNTest.yml file theres a diff test, which compare the *results.txt* and the *expected_output.txt* to check if theres a difference between them. If yes, it says, whats the difference between the text files.
  
# Documentation
[Click here to open the documentation](https://teaching-projects.github.io/SZE-MOSZE-2020-Gateway/pages.html)
