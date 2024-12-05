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

static int check_level(int prev_num, int cur_num) {
    int diff = abs(cur_num - prev_num);
    if (diff >= 1 && diff <= 3) {
        return 1;
    }
    return 0;
}

static void skip_ij(int skip, int* was_skipped, int* i, int* j) {
    if (*i == skip) {
        was_skipped[0] = 1;
        *i += 1;
        *j += 1;
    }
    else if (*j == skip) {
        was_skipped[1] = 1;
        *j += 1;
    }
}

static void revert_skip_ij(int* was_skipped, int* i, int* j) {
    if (was_skipped[0]) {
        *i -= 1;
        *j -= 1;
    }
    if (was_skipped[1]) {
        *j -= 1;
    }
    was_skipped[0] = 0;
    was_skipped[1] = 0;
}

int is_safe(int* nums) {
    int was_skipped[2] = {0, 0};
    for (int skip = -1; skip == -1 || nums[skip] != 0; skip++) {
        int failed_state = 0;
        int slope_state = NO_STATE;
        for (int i = 0, j = 1; nums[j] != 0; i++, j++) {
            skip_ij(skip, was_skipped, &i, &j);
            if (nums[j] == 0) {
                revert_skip_ij(was_skipped, &i, &j);
                break;
            }
            if (!check_state(&slope_state, nums[i], nums[j]) ||
                !check_level(nums[i], nums[j])) {
                    failed_state = 1;
                    revert_skip_ij(was_skipped, &i, &j);
                    break;
            }
            revert_skip_ij(was_skipped, &i, &j);
        }
        if (!failed_state) {
            return 1;
        }
    }
    return 0;
}

void fill_num_buff(int* nums, char* array) {
    char* endptr = NULL;
    for (int i = 0; *array != '\n'; i++) {
        nums[i] = strtoul(array, &endptr, 10);
        array = endptr;
    }
}