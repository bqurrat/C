/******************************************************************** 
 * Assignment # 6
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain
 ********************************************************************/ 

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *next;
  struct data *dta;
};

struct linkedList{
  struct node *head;
};
void addNPos(struct linkedList *ll, struct data *dta, int n);
void removeNPos(struct linkedList *ll, int n);
void removeBack(struct linkedList *ll);
void cleanLinkedList(struct linkedList *ll);
void freeData(struct data* dta);
void freeNode(struct node* ptr);
struct node* createNode(struct data *dta);
struct linkedList* createLinkedList();
void addFront(struct linkedList *ll,struct data *dta);
void addBack(struct linkedList *ll,struct data *dta);
void removeFront(struct linkedList *ll);
int searchLinkedList(struct linkedList *ll,struct data *dta);
void printLinkedList(struct linkedList *ll);
int length(struct linkedList *ll);
int node_count(struct linkedList* ll);
char* getLetterCount(struct linkedList* ll);
void getCount(int arr[], struct data* dta);
char* createString(int count[], int size);

#endif
