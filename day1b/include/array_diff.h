#ifndef ARRAYDIFF_H
#define ARRAYDIFF_H

#include <stdio.h>

void update_arrays(char* line, int index, int* array1, int* array2);
int get_distance(int index, int* array1, int* array2);
int sim_score(int index, int* array1, int* array2);

#endif