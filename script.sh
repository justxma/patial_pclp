#!/bin/bash
#se ruleaza deocamdata doar pentur test si main
value=$1

if [[ $value="test" ]]; then
    gcc test.c -o test
    ./test
    rm -rf test
elif [[ $value="main" ]]; then
    gcc main.c -o test
    ./main
    rm -rf main
fi
