/******************************************************************** 
 * Assignment # 7
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain
 ********************************************************************/ 

#include "queue.h"
#include<string.h>

struct queue* createQueue()
{
  struct queue *q = malloc(sizeof(struct queue));
  q->que = createDLinkedList();
  return q;

}
void pushQueue(struct queue *q,struct data *dta) { 
//get item from top of queue
    addBack(q->que, dta);
}
struct data* topQueue(struct queue *q) {
    return getFront(q->que); 
}
void popQueue(struct queue *q) {
    removeFront(q->que);
}


//print queue.  You have to print from the queue.  You can not call a print function from dlinklist
int isEmptyQueue(struct queue *q) {
    return isEmpty(q->que);
}

void printQueue(struct queue *q) {
    struct queue *tmp = createQueue();
    while ( !isEmptyQueue(q) ) {
        struct data* dta = topQueue(tmp);
        pushQueue(tmp, createData(dta->v1, dta->v2));
        popQueue(q);
    }
    while ( !isEmptyQueue(tmp) ) {
        struct data* dta = topQueue(tmp);
        pushQueue(q, createData(dta->v1, dta->v2));
        popQueue(tmp);
    }
    cleanQueue(tmp);
}
//get number of elements from queue
int sizeQueue(struct queue *q) {
    struct node* cur = q->que->head;
    int que_counter = 0;
    while( cur != NULL ) {
        ++que_counter;
        cur = cur->next;
    }
    return que_counter;
}
//clean queue memory
void cleanQueue(struct queue *q) {
    while ( !isEmptyQueue(q) ) {
        popQueue(q);
    }
    free(q->que);
    free(q);
}
int convertRomanNumeralQueue(struct queue *q) {
    char *str = createStringQueue(q);
    int number = getNumberQueue(str);
    free(str);
    
    return number;
}


char *createStringQueue(struct queue *q) {
    int string_len = sizeQueue(q);
    struct queue *tmp = createQueue();
    char *result = malloc(sizeof(char) * (string_len + 1));
    int i = 0;

    while (!isEmptyQueue(q)) {
        struct data* dta = topQueue(q);
        result[i] = dta->numeral;
        pushQueue(tmp, createDataNumeral(result[i]) );
        ++i;
        popQueue(q);
    }

    while ( !isEmptyQueue(tmp)) {
        struct data* dta = topQueue(tmp);
        pushQueue(q, createDataNumeral(dta->numeral));
        popQueue(tmp);
    }

    cleanQueue(tmp);
    result[string_len] = '\0';
    return result;
}

int getNumberQueue(char *str) {
    bool flag = true;
    int len = strlen(str);
    int number = getMapingQueue(str[len - 1]);
    int i;
    for (i = len - 2; i >= 0; --i ) {
        if ( getMapingQueue(str[i]) > getMapingQueue(str[i + 1]) ) {
            flag = true;
        } else if ( getMapingQueue(str[i]) < getMapingQueue(str[i + 1]) )  {
            flag = false;
        }
        if (flag == true) {

            int new_number = getMapingQueue(str[i]);
            number = new_number + number;
        } else {

            int new_number = getMapingQueue(str[i]);
            number =  number - new_number;
        }
    }
    return number;
}

int getMapingQueue(char c) {

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



