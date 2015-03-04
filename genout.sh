#!/bin/bash

echo "Generating output..."

rm *.out

for source in *.cpp
do
  tmp=${source%*.}
  name=${tmp%.*}
  g++ $source -o bin
  echo "Running No. $name"
  ./bin >$name.out
done
