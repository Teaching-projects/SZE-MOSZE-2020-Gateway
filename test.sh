#!/bin/bash

./a.out units/monster1.json units/monster2.json > results.txt
./a.out units/monster1.json units/monster3.json >> results.txt

./a.out units/monster2.json units/monster1.json >> results.txt
./a.out units/monster2.json units/monster3.json >> results.txt

./a.out units/monster3.json units/monster1.json >> results.txt
./a.out units/monster3.json units/monster2.json >> results.txt
