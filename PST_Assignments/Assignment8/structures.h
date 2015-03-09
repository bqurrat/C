/******************************************************************** 
 * Assignment # 8
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain
 ********************************************************************/ 

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

struct data
{
  float v1;
  float v2;
};


struct leaf
{
  struct leaf *left;
  struct leaf *right;
  struct data *dta;
};


struct node
{
  struct node *next;
  struct node *prev;
  struct leaf *lf;
};

struct dlinklist
{
  struct node *head;
  struct node *tail;
};

struct stack
{
  struct dlinklist *stk;

};

struct queue
{
  struct dlinklist *que;

};

struct tree
{
  struct leaf* root;
};


#endif
