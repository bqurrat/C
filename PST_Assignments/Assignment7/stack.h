#include "dlinklist.h"
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

struct stack
{
  struct dlinklist *stk;

};
//allocate stack
struct stack* createStack();
//push item onto the stack
void pushStack(struct stack *s,struct data *dta);
//get item from top of stack
struct data* top(struct stack *s);
//pop item from the stack
void popStack(struct stack *s);
//test if stack is empty.  return 1 if empty and 0 is not
int isEmptyStack(struct stack *s);
//print stack.  You have to print from the stack.  You can not call a print function from dlinklist
void printStack(struct stack *s);
//get number of elements from stack
int sizeStack(struct stack *s);
//clean stack memory
void cleanStack(struct stack *s);
int convertRomanNumeralStack(struct stack *s);
char *createString(struct stack* s);
int getMaping(char c);
int getNumber(char *str);
