#!/bin/bash
#se ruleaza deocamdata doar pentur test si main
value="$1"

if [[ "$value" == "test" ]]; then
    gcc test.c -o test
    ./test
    rm -rf test
	echo "test.c a rulat cu scucces"
elif [[ "$value" == "main" ]]; then
    gcc main.c -o main
    ./main
    rm -rf main
	echo "main.c a rulat cu scucces"
fi
