#!/bin/bash

./$1 units/monster1.json units/monster2.json > results.txt
./$1 units/monster1.json units/monster3.json >> results.txt

./$1 units/monster2.json units/monster1.json >> results.txt
./$1 units/monster2.json units/monster3.json >> results.txt

./$1 units/monster3.json units/monster1.json >> results.txt
./$1 units/monster3.json units/monster2.json >> results.txt
