#!/bin/bash

CODEGEN=../bin/c_codegen.exe

# TODO: Make sure this points to your own mips gcc.

(cd .. && make bin/c_codegen)

for i in input/*.c; do
  BASE=$(basename $i .c);

  ###################################
  ## Reference (native) version

  gcc -std=c99 driver.c $i -o build/$BASE.ref
  ./build/$BASE.ref > output/$BASE.ref

  ###################################
  ## Tested (MIPS) version

  # TODO: C pre-processor?
  cat $i | $CODEGEN > build/$BASE.got

  ##################################
  ## Compare the output
  diff output/$BASE.got output/$BASE.ref > output/$BASE.diff;
  if [[ $? != 0 ]]; then
    echo "$BASE, FAIL, see output/$BASE.diff";
  else
    echo "$BASE, pass";
  fi
done
