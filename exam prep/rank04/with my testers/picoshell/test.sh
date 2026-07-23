#!/bin/bash

# Ensure picoshell is removed on exit
trap 'rm -f picoshell /tmp/picoshell_out' EXIT

# Compile the project
gcc -Wall -Wextra -Werror main.c picoshell.c -o picoshell

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

TOTAL=0
PASSED=0

run_test() {
    local desc="$1"
    shift
    TOTAL=$((TOTAL + 1))
    
    # Run the command and capture output and exit code
    ./picoshell "$@" > /tmp/picoshell_out 2>&1
    local ret=$?
    
    # Simple evaluation based on execution success/failure expectation or compare outputs
    if [ $ret -eq 0 ]; then
        echo -e "🟢 Test $TOTAL: $desc"
        PASSED=$((PASSED + 1))
    else
        echo -e "🔴 Test $TOTAL: $desc (Failed with code $ret)"
    fi
}

echo "Running picoshell tests..."
echo "----------------------------------------"

# Test cases from 42 exam traces and standard examples
run_test "Single command: ls" /bin/ls
run_test "Simple pipe: ls | grep picoshell" /bin/ls "|" /usr/bin/grep picoshell
run_test "Multiple pipes: echo squalala | cat | sed s/a/b/g" echo squalala "|" cat "|" sed s/a/b/g
run_test "Three commands pipeline: seq 5 | head -n 3 | tail -n 1" seq 5 "|" head -n 3 "|" tail -n 1
run_test "Invalid command test" non_existent_cmd_xyz

echo "----------------------------------------"
echo "Passed: $PASSED / $TOTAL tests"

if [ $PASSED -eq $TOTAL ]; then
    exit 0
else
    exit 1
fi

rm -f picoshell