#ifndef VECTOR_H_
#define VECTOR_H_

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct vector
{
  int size;
  struct data **array;
};
//class
struct vector* createVector();
void addFront(struct vector *vec,struct data *dta);
void removeBack(struct vector *vec);
void printVector(struct vector *vec);
void cleanVector(struct vector *v);
void addBack(struct vector *vec,struct data *dta);
void removeFront(struct vector *vec);
float sumVector(struct vector *vec);
struct vector* cloneVector(struct vector *vec);
int compareVectors(struct vector *vec1,struct vector *vec2);
void reverseVector(struct vector *vec);

#endif
