#!/bin/bash

./a.out units/Eivar.json units/Sigurd.json > results.txt
./a.out units/Eivar.json units/Ubba.json >> results.txt
./a.out units/Eivar.json units/Ragnar.json >> results.txt
./a.out units/Eivar.json units/Bjorn.json >> results.txt

./a.out units/Sigurd.json units/Eivar.json >> results.txt
./a.out units/Sigurd.json units/Ubba.json >> results.txt
./a.out units/Sigurd.json units/Ragnar.json >> results.txt
./a.out units/Sigurd.json units/Bjorn.json >> results.txt

./a.out units/Ubba.json units/Eivar.json >> results.txt
./a.out units/Ubba.json units/Sigurd.json >> results.txt
./a.out units/Ubba.json units/Ragnar.json >> results.txt
./a.out units/Ubba.json units/Bjorn.json >> results.txt

./a.out units/Bjorn.json units/Eivar.json >> results.txt
./a.out units/Bjorn.json units/Sigurd.json >> results.txt
./a.out units/Bjorn.json units/Ubba.json >> results.txt
./a.out units/Bjorn.json units/Ragnar.json >> results.txt

./a.out units/Ragnar.json units/Eivar.json >> results.txt
./a.out units/Ragnar.json units/Sigurd.json >> results.txt
./a.out units/Ragnar.json units/Ubba.json >> results.txt
./a.out units/Ragnar.json units/Bjorn.json >> results.txt