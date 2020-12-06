#!/bin/bash

./a.out units/Eivar.json units/Sigurd.json > results.txt
./a.out units/Eivar.json units/Ubba.json >> results.txt

./a.out units/Sigurd.json units/monster1.json >> results.txt
./a.out units/Sigurd.json units/Ubba.json >> results.txt

./a.out units/Ubba.json units/monster1.json >> results.txt
./a.out units/Ubba.json units/Sigurd.json >> results.txt
