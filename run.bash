#!/bin/bash
set -e
g++ -Wall -g main.cpp linked.cpp excel.cpp -o main
./main $*