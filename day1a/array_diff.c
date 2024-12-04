#include <stdlib.h>

void update_arrays(char* line, int index, int* array1, int* array2) {
    array1[index] = strtoul(line, NULL, 10);
    line += 6;
    array2[index] = strtoul(line, NULL, 10);
}

int get_distance(int index, int* array1, int* array2) {
    int offset = array1[index] - array2[index];
    if (offset < 0) {
        return offset * -1;
    }
    return offset;
}

int sim_score(int index, int* array1, int* array2) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (array1[index] == array2[i]) {
            count += 1;
        }
    }
    return count * array1[index];
}