#include <stdio.h>

int main() {
    FILE *fp;
    size_t len = 0;
    char *line = NULL;
    unsigned long count = 0;
    fp = fopen("/home/quill/AOC2024/day1a/input/input.txt", "r");
    if (fp == NULL)
        return -1;
    int safe_count = 0;
    while (NULL != fp) {
        getline(&line, &len, fp);
    }
    return 0;
}