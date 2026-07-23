#!/bin/bash

# ANSI Color & Symbol Definitions
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"
CHECK="${GREEN}✔${RESET}"
CROSS="${RED}✘${RESET}"

TOTAL=0
PASSED=0

run_test() {
    local test_name="$1"
    local main_code="$2"
    ((TOTAL++))

    # Write test main
    cat << 'EOF' > test_main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ft_popen(const char *file, char *const argv[], char type);

EOF
    echo "$main_code" >> test_main.c

    # Compile with exam flags
    compile_err=$(cc -Wall -Wextra -Werror test_main.c ft_popen.c -o test_exe 2>&1)
    if [ $? -ne 0 ]; then
        echo -e " Test $TOTAL: $test_name -> $CROSS [Compilation Error]"
        echo "   Compiler output:"
        echo "$compile_err" | sed 's/^/   /'
        rm -f test_main.c test_exe
        return
    fi

    # Execute
    ./test_exe > user_out.txt 2>&1
    local status=$?

    if [ $status -eq 0 ]; then
        echo -e " Test $TOTAL: $test_name -> $CHECK"
        ((PASSED++))
    else
        echo -e " Test $TOTAL: $test_name -> $CROSS [Execution/Assertion Failed]"
    fi

    rm -f test_main.c test_exe user_out.txt
}

echo "=========================================="
echo "          FT_POPEN EXAM TEST RUNNER       "
echo "=========================================="

# Test 1: Exam Trace - Parameter Validation
run_test "Invalid parameters (NULL file/argv, bad mode)" '
int main() {
    if (ft_popen(NULL, (char *const[]){"ls", NULL}, '\''r'\'') != -1) return 1;
    if (ft_popen("ls", NULL, '\''r'\'') != -1) return 1;
    if (ft_popen("ls", (char *const[]){"ls", NULL}, '\''x'\'') != -1) return 1;
    if (ft_popen("ls", (char *const[]){"ls", NULL}, 0) != -1) return 1;
    return 0;
}
'

# Test 2: Exam Trace 1 - Simple Executable Read Mode
run_test "Simple read execution ('r')" '
int main() {
    int fd = ft_popen("echo", (char *const[]){"echo", "42_exam_test_1", NULL}, '\''r'\'');
    if (fd < 0) return 1;
    char buf[64] = {0};
    read(fd, buf, sizeof(buf) - 1);
    close(fd);
    if (strcmp(buf, "42_exam_test_1\n") != 0) return 1;
    return 0;
}
'

# Test 3: Exam Trace 2 - Command with Absolute Path and Flags (/usr/bin/ls -la)
run_test "Full path binary with flags (/bin/ls)" '
int main() {
    int fd = ft_popen("/bin/ls", (char *const[]){"/bin/ls", "-a", NULL}, '\''r'\'');
    if (fd < 0) return 1;
    char buf[256] = {0};
    int bytes = read(fd, buf, sizeof(buf) - 1);
    close(fd);
    if (bytes <= 0 || strstr(buf, ".") == NULL) return 1;
    return 0;
}
'

# Test 4: Exam Trace 3 - Write Mode ('w')
run_test "Write mode execution ('w')" '
int main() {
    int fd = ft_popen("cat", (char *const[]){"cat", NULL}, '\''w'\'');
    if (fd < 0) return 1;
    if (write(fd, "test_write\n", 11) != 11) return 1;
    close(fd);
    return 0;
}
'

# Test 5: Exam Trace 4 - Chained ft_popen (ft_popen -> dup2 -> ft_popen)
run_test "Chained ft_popen calls (Subject pattern)" '
int main() {
    int fd1 = ft_popen("echo", (char *const[]){"echo", "hello_42", NULL}, '\''r'\'');
    if (fd1 < 0) return 1;
    if (dup2(fd1, STDIN_FILENO) == -1) return 1;
    close(fd1);

    int fd2 = ft_popen("grep", (char *const[]){"grep", "42", NULL}, '\''r'\'');
    if (fd2 < 0) return 1;

    char buf[64] = {0};
    read(fd2, buf, sizeof(buf) - 1);
    close(fd2);

    if (strcmp(buf, "hello_42\n") != 0) return 1;
    return 0;
}
'

# Test 6: Exam Trace - Non-existent Command Handling
run_test "Non-existent command execution" '
int main() {
    int fd = ft_popen("/non_existent_cmd_1234", (char *const[]){"non_existent", NULL}, '\''r'\'');
    if (fd < 0) return 1; // Expected valid fd return from parent before child execvp fails
    char buf[16] = {0};
    int b = read(fd, buf, sizeof(buf));
    close(fd);
    if (b != 0) return 1; // Child failed execvp and exited, returning EOF
    return 0;
}
'

# Test 7: Exam Trace 5 - ulimit -n 30 FD Exhaustion & Leak Prevention
(
    ulimit -n 30
    run_test "File Descriptor Stress & Leak Test (ulimit -n 30)" '
    int main() {
        for (int i = 0; i < 15; i++) {
            int fd = ft_popen("echo", (char *const[]){"echo", "test", NULL}, '\''r'\'');
            if (fd < 0) return 1;
            close(fd);
        }
        return 0;
    }
    '
)

echo "=========================================="
if [ $PASSED -eq $TOTAL ]; then
    echo -e "${GREEN}OVERALL: ALL TESTS PASSED ($PASSED/$TOTAL) $CHECK${RESET}"
else
    echo -e "${RED}OVERALL: TESTS FAILED ($PASSED/$TOTAL PASSED) $CROSS${RESET}"
fi
echo "=========================================="
