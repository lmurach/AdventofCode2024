#include <stdio.h>
#include <stdlib.h>
#include <get_muls.h>

int main() {
   
    FILE *f = fopen("/home/quill/AOC2024/day3a/input/input.txt", "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = 0;
    printf("result: %llu", get_muls(string));
    return 0;
}