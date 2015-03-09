/********************************************************************
 * Assignment # 4
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain - Oct 7, 2014
 ********************************************************************/

#ifndef HW4_H_
#define HW4_H_
#include "random.h"
struct data {
    int Start;
    int End;
    int Max;
};

struct input {
    int *array;
    int size;
};

struct input* generateArray(int size);
struct data* generateData(int s,int e);
struct data** generateDataArray(int size);
void getMax(struct input *inputArr, struct data *dVals);
void printData(struct data **d, int dataSize);
void findMax(struct data **points, int pointsSize, struct input *inputs);

#endif
