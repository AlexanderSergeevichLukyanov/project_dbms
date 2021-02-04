#!/bin/bash
#dfs(){
#	clang-format *.h 
#	clang-format *.cpp
#	for file in $1; 
#}
clang-format include/*.h include/*.cpp src/src/*.h src/src/*.cpp src/tests/*.h src/tests/*.cpp -i || true
