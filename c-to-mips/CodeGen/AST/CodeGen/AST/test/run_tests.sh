#!/bin/bash

for i in $(ls samples); do
cat samples/$i | ./c_parser.exe | less
done
