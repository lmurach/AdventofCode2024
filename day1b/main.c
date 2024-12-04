#include <stdio.h>
#include <array_diff.h>
#include <sorting.h>

int main() {
    FILE *fp;
    size_t len = 0;
    char *line = NULL;
    unsigned long count = 0;
    fp = fopen("/home/quill/AOC2024/day1a/input/input.txt", "r");
    if (fp == NULL)
        return -1;
    int array1[1000];
    int array2[1000];
    for (int i = 0; i < 1000; i++) {
        getline(&line, &len, fp);
        update_arrays(line, i, array1, array2);
    }
    unsigned long total = 0;
    for (int i = 0; i < 1000; i++) {
        total += sim_score(i, array1, array2);
    }
    printf("distance: %lu \n", total);
    return 0;
}