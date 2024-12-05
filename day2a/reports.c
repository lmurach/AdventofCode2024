#include <stdio.h>
#include <stdlib.h>
#include <reports.h>

static int check_state(int* state, int prev_num, int cur_num) {
    if (prev_num < cur_num && (*state == INCREASING || *state == NO_STATE)) {
        *state = INCREASING;
        return 1;
    }
    if (prev_num > cur_num && (*state == DECREASING || *state == NO_STATE)) {
        *state = DECREASING;
        return 1;
    }
    return 0;
}

static int check_level(int state, int prev_num, int cur_num) {
    int diff = abs(cur_num - prev_num);
    if (diff >= 1 && diff <= 3) {
        return 1;
    }
    return 0;
}

int is_safe(char* array) {
    char* endptr = NULL;
    int slope_state = NO_STATE;
    unsigned long prev_num = strtoul(array, &endptr, 10);
    array = endptr;
    while (*array != '\n') {
        unsigned long cur_num = strtoul(array, &endptr, 10);
        if (!check_state(&slope_state, prev_num, cur_num)) {
            return 0;
        }
        if (!check_level(slope_state, prev_num, cur_num)) {
            return 0;
        }
        prev_num = cur_num;
        array = endptr;
    }
}