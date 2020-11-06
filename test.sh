#!/bin/bash

./a.out ./units_test/monster1.json ./units_test/monster2.json > results.txt
./a.out ./units_test/monster1.json ./units_test/monster3.json >> results.txt

./a.out units_test/monster2.json ./units_test/monster1.json >> results.txt
./a.out units_test/monster2.json ./units_test/monster3.json >> results.txt

./a.out ./units_test/monster3.json ./units_test/monster1.json >> results.txt
./a.out ./units_test/monster3.json ./units_test/monster2.json >> results.txt
