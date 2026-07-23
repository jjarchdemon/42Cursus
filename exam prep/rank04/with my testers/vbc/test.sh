#!/bin/bash

# ANSI Color Codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# 1. Compile
echo -n "Compiling vbc.c... "
gcc -Wall -Wextra -Werror vbc.c -o vbc
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi
echo -e "${GREEN}OK${NC}\n"

# 2. Define Test Pairs: "INPUT" "EXPECTED_OUTPUT"
TESTS=(
    "1"                                         "1"
    "2+3"                                       "5"
    "3*4+5"                                     "17"
    "3+4*5"                                     "23"
    "(3+4)*5"                                   "35"
    "(((((2+2)*2+2)*2+2)*2+2)*2+2)*2"           "188"
    "1+"                                        "Unexpected end of input"
    "1+2)"                                      "Unexpected token ')'"
    "1+2+3+4+5"                                 "15"
    "2*4+9+3+2*1+5+1+6+6*1*1+8*0+0+5+0*4*9*5*8+9*7+5*1+3+1+4*5*7*3+0*3+4*8+8+8+4*0*5*3+5+4+5*7+9+6*6+7+9*2*6*9+2+1*3*7*1*1*5+1+2+7+4+3*4*2+0+4*4*2*2+6+7*5+9+0+8*4+6*7+5+4*4+2+5*5+1+6+3*5*9*9+7*4*3+7+4*9+3+0+1*8+1+2*9*4*5*1+0*1*9+5*3*5+9*6+5*4+5+5*8*6*4*9*2+0+0+1*5*3+6*8*0+0+2*3+7*5*6+8+6*6+9+3+7+0*0+5+2*8+2*7*2+3+9*1*4*8*7*9+2*0+1*6*4*2+8*8*3*1+8+2*4+8*3+8*3+9*5+2*3+9*5*6*4+3*6*6+7+4*8+0+2+9*8*0*6*8*1*2*7+0*5+6*5+0*2+7+2+3+8*7+6+1*3+5+4*5*4*6*1+4*7+9*0+4+9*8+7+5+6+2+6+1+1+1*6*0*9+7+6*2+4*4+1*6*2*9+3+0+0*1*8+4+6*2+6+2*7+7+0*9+6+2*1+6*5*2*3*5*2*6*4+2*9*2*4*5*2*2*3+8+8*3*2*3+0*5+9*6+8+3*1+6*9+8+9*2*0+2" "94305"
    "(1)"                                        "1"
    "(((((((3)))))))"                            "3"
    "(1+2)*3"                                    "9"
    "((6*6+7+5+8)*(1+0+4*8+7)+2)+4*(1+2)"        "2254"
    "((1+3)*12+(3*(2+6))"                        "Unexpected token '2'"
    "1+2a"                                       "Unexpected token 'a'"
    "1+2)"                                       "Unexpected token ')'"
    "(1+)"                                       "Unexpected token ')'"
)

PASSED=0
FAILED=0
TOTAL=$((${#TESTS[@]} / 2))

# 3. Execution Loop
test_num=1
for ((i=0; i<${#TESTS[@]}; i+=2)); do
    input="${TESTS[i]}"
    expected="${TESTS[i+1]}"
    
    actual=$(./vbc "$input" 2>&1)
    
    if [ "$actual" == "$expected" ]; then
        echo -e " ${GREEN}✓${NC} Test $test_num PASSED"
        ((PASSED++))
    else
        echo -e " ${RED}✗${NC} Test $test_num FAILED"
        echo -e "   ${RED}Command:${NC}  ./vbc '$input'"
        echo -e "   ${RED}Expected:${NC} '$expected'"
        echo -e "   ${RED}Got:${NC}      '$actual'"
        ((FAILED++))
    fi
    ((test_num++))
done

# 4. Summary
echo -e "\n----------------------------------------"
if [ $FAILED -eq 0 ]; then
    echo -e "Result: ${GREEN}PASS${NC} ($PASSED/$TOTAL passed)"
else
    echo -e "Result: ${RED}FAIL${NC} ($PASSED/$TOTAL passed, $FAILED failed)"
fi
echo -e "----------------------------------------"

rm -f vbc
