/********************************************************************
 * Assignment # 5
 * Programming systems and tools - CS580U
 * Qurrat Ul Ain - Oct 14, 2014
 * *********************************************************************/

#include "vector.h"
#include "data.h"


int main(){
	struct vector *vec = createVector();
	float sum = sumVector(vec);
	//printf("%f\n", sum);
    
    addFront(vec, createData(5.0,6.0));
	//printVector(vec);
    addFront(vec, createData(3.0,4.0));
	addFront(vec, createData(1.0,2.0));
	printVector(vec);
    
    //printf("Test AddBack\n");
	addBack(vec, createData(-3.0,-3.0));
	addBack(vec, createData(-1.0,-2.0));
	printVector(vec);
    
    //printf("Removing front \n");
    removeFront(vec);
    removeFront(vec);
    //printVector(vec);

    //printf("Removing Back\n");
    removeBack(vec);
    printVector(vec);

    //printf("Checking Sum Function\n");
    sum = sumVector(vec);
    printf("%f\n", sum);

    //printf("\n\nTesting clone");
    struct vector* new = cloneVector(vec);
    printVector(new);

	int result = compareVectors(vec,new);
    printf("%d\n\n",result); 
    
    //printf("Add new Vectors to new Vector and compare should give you 01 \n");
    addBack(new, createData(5.0,6.0));
	printVector(new);
    result = compareVectors(vec,new);
    
    //printf("Result By compare vector when they are not same= %d\n",result); 
    //printf("\n\nTesting reverese2\n");
    //printf("Before reversing\n");
	printVector(vec);
    reverseVector(vec);
    //printf("After reversing\n");
	printVector(vec);

    cleanVector(vec); 
    cleanVector(new); 
    
    return 0;
}
