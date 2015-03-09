/******************************************************************** 
 * Assignment # 7
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain
 ********************************************************************/ 

#include "stack.h"


struct stack* createStack()
{
  struct stack *s = malloc(sizeof(struct stack));
  s->stk = createDLinkedList();
  return s;

}

void pushStack(struct stack *s, struct data *dta) {
	addFront(s->stk, dta);
}

void popStack(struct stack *s) {
	removeFront(s->stk);
}

int isEmptyStack(struct stack *s) {
	return isEmpty(s->stk);
}

struct data* top(struct stack *s) {
	return getFront(s->stk);
}

void printStack(struct stack *s) {
	struct stack *tmp = createStack();
	while (!isEmptyStack(s)) {
		struct data *dta = top(s);
		printData(dta);
		pushStack(tmp, createData(dta->v1, dta->v2));
		popStack(s);
	}
	
	while (!isEmptyStack(tmp)) {
		struct data* dta = top(tmp);
		pushStack(s, createData(dta->v1, dta->v2));
		popStack(tmp);
	}

	cleanStack(tmp);
}

void cleanStack(struct stack *s) {
	while(!isEmptyStack(s)) {
		popStack(s);
	}

	free(s->stk);
	free(s);
}
int sizeStack(struct stack *s) {
	struct node* cur = s->stk->head;
	int stack_counter = 0;
	while (cur != NULL ) {
		++stack_counter;
		cur = cur->next;
	}
	return stack_counter;
}
int convertRomanNumeralStack(struct stack *s) {
	char *str = createString(s);
	int number = getNumber(str);
	free(str);
	return number;
}


char *createString(struct stack* s) {
	int string_len = sizeStack(s);
    struct stack *tmp = createStack();
    char *result = malloc(sizeof(char) * (string_len + 1));
    int i = string_len - 1;
	
    while ( !isEmptyStack(s) ) {
		struct data *dta = top(s);
        result[i] = dta->numeral;
        pushStack(tmp, createDataNumeral(result[i]));
        --i;
        popStack(s);
	}
    
    while( !isEmptyStack(tmp)) {
        struct data* dta = top(tmp);
        pushStack(s, createDataNumeral(dta->numeral));
        popStack(tmp);
    }
    
    cleanStack(tmp);
    result[string_len] = '\0';
	return result;
}

int getNumber(char *str) {
    bool flag = true;
    int len = strlen(str);
    int number = getMaping(str[len - 1]);
    int i;
    for (i = len - 2; i >= 0; --i ) {
        if ( getMaping(str[i]) > getMaping(str[i + 1]) ) {
            flag = true;
        } else if ( getMaping(str[i]) < getMaping(str[i + 1]) )  {
            flag = false;
        }
        if (flag == true) {

            int new_number = getMaping(str[i]);
            number = new_number + number;
        } else {

            int new_number = getMaping(str[i]);
            number =  number - new_number;
        }
    }
    return number;
}

int getMaping(char c) {

    switch(c)
    {
    case 'I' :
        return 1;
    case 'V' :
        return 5;
    case 'X' :
        return 10;
    case 'L' :
        return 50;
    case 'C' :
        return 100;
    case 'D' :
        return 500;
    case 'M' :
        return 1000;
    default:
        return -1;
    }
}

