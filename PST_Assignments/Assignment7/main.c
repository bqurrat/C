#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "queue.h"

int main(int argc, char* argv[])
{
	struct data* data1;
    struct data* data2;
	int len = strlen(argv[1]);
	char* input = argv[1];
    struct stack* my_stack = createStack();
    struct queue* my_queue = createQueue();
	
	int i;
	for ( i = 0; i < len; ++i) {
		data1 = createDataNumeral(input[i]);
		data2 = createDataNumeral(input[i]);
        pushStack(my_stack, data1);
        pushQueue(my_queue, data2);
    }
	
	int converted_val_stack = convertRomanNumeralStack(my_stack);
    int converted_val_queue = convertRomanNumeralQueue(my_queue);
	printf("%d\n", converted_val_stack);
    printf("%d\n", converted_val_queue);
    cleanStack(my_stack);
	cleanQueue(my_queue);
    
    return 0;
}


