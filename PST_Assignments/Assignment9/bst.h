#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"
#include "stack.h"
#include "queue.h"



struct leaf* createLeaf(struct data *d);
struct tree* createTree();
void insertBst(struct tree *t,struct data *d);
void insertBst_r(struct leaf* current,struct leaf* newLeaf);
void inOrderBst(struct tree *t);
void inOrderBst_r(struct leaf *current);
void preOrderBst(struct tree *t);
void preOrderBst_r(struct leaf *lf);    
void postOrderBst(struct tree *t);
void postOrderBst_r(struct leaf *lf);

struct data* getMaxData(struct tree *tr);
struct data* getMaxData_r(struct leaf* lf);
struct data* getMimData(struct tree *tr);
struct data* getMimData_r(struct leaf* lf);

void printInRange(struct tree *tr, float begin, float end);
void printInRange_r(struct leaf* lf, float begin,float end);
int isCompleteBst(struct tree *tr);
int isCompleteBst_r(struct leaf* lf);
float totalSum(struct tree *t);
float totalSum_r(struct leaf* current);
//void breathFirstBst(struct tree *t);
int getBstHeight(struct tree *tr); 
int getBstHeight_r(struct leaf* lf);
int isFullBst(struct tree *tr);
int isFullBst_r(struct leaf *lf);

float sumLeaves(struct tree *t);
float sumLeaves_r(struct leaf *lf);

void printDepthFirstSearch(struct tree *t);
void printBreadthFirstSearch(struct tree *t);

void swap(struct leaf* l);

void reverseBST(struct tree *t);
void reverseBST_r(struct leaf *lf);

void cleanBST(struct tree *t);
void cleanBST_r(struct leaf *lf);

int searchBst(struct tree *t, struct data *d);
int searchBst_r(struct leaf *curr,struct data *d);
#endif
