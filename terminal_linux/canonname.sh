#!/bin/sh

#find . -maxdepth 1 -type f \( -name "*.cp" -o -name "*.c++" -o -name "*.cc" -o -name "*.cxx" \) -exec rename -a "s/\.(cp|c\+\+|cc|cxx)$/\.cpp/" {} \;

rename .cp .cpp *.cp
rename .c\+\+ .cpp *.c\+\+
rename .cc .cpp *.cc
rename .cxx .cpp *.cxx 
