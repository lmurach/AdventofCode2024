#include <stdio.h>
#include <reports.h>

int main() {
    FILE *fp;
    size_t len = 0;
    char *line = NULL;
    unsigned long count = 0;
    fp = fopen("/home/quill/AOC2024/day2a/input/input.txt", "r");
    int safe_count = 0;
    for (int i = 0; i < 1000; i++) {
        getline(&line, &len, fp);
        if (is_safe(line)) {
            safe_count += 1;
        }
    }
    printf("safe count %i\n", safe_count);
    return 0;
}