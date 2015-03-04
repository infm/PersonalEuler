#!/bin/bash

echo "Starting the tests now."

for source in *.cpp
do
  tmp=${source%*.}
  name=${tmp%.*}
  g++ $source -o bin
  echo "Running No. $name "
  ./bin >bin.out
  if diff -u bin.out $name.out; then
    echo "OK"
  else
    echo "FAIL"
  fi
done

rm bin
