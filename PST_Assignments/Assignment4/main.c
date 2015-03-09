/********************************************************************
 * Assignment # 4
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain - Oct 7, 2014
 ********************************************************************/

#include "hw4.h"
#include "random.h"
int main(){
    int size = 10;
 	
	SeedRand();
    struct input* test3;
    struct data** test4;

    test3 = generateArray(size);
    test4 = generateDataArray(size);

    findMax(test4, size, test3);
    printData(test4,size);
 
  	free(test3->array);
	free(test3);
	int i;

	for (i = 0; i < size; ++i ) {
		free(*(test4 + i));
	}
	free(test4);
	
	 
	return 0;
}

