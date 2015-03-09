
/********************************************************************
 * Assignment # 5
 * Programming systems and tools - CS580U
 * Qurrat Ul Ain - Oct 14, 2014
 *********************************************************************/

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct vector
{
  int size;
  struct data **array;
};
/*To create a vector with size 0  */
struct vector* createVector() { 
	struct vector* v = malloc(sizeof(struct vector));
	v->size = 0;
	v->array = NULL;
	
	return v;
}
/* Add at the front */
void addFront(struct vector *vec,struct data *dta) {
	vec->size++;
	struct data** temp = vec->array;
	vec->array = malloc(sizeof(struct data*) * vec->size);
	vec->array[0] = dta;
	int i;
	
	for ( i = 1; i < vec->size; ++i ) {
		vec->array[i] = temp[ i - 1 ];
	}
	free(temp);
}
/* Add at the back */
void addBack(struct vector *vec,struct data *dta) {
    vec->size++;
    struct data** temp = vec->array;
    vec->array = malloc(sizeof(struct data*) * (vec->size));
    int i;
    for ( i = 0; i < vec->size - 1; ++i ) {
        vec->array[i] = temp[i];
    }
    vec->array[vec->size - 1] = dta;
    free(temp);       
}

/* Remove from back */
void removeBack(struct vector *vec) { 
	
    vec->size--;
	struct data** temp = vec->array;
	vec->array = malloc(sizeof(struct data*) * (vec->size) );
	int i;
	for ( i = 0; i < vec->size; ++i ) {
		vec->array[i] = temp[i];
	}
    /* size has been updated to size - 1 */
	free(temp[vec->size]);
	free(temp);
}
/* Remove from front */
void removeFront(struct vector *vec) {
    vec->size--;
    struct data **temp = vec->array;
    vec->array = malloc(sizeof(struct data*) * (vec->size) );
    int i;
    for ( i = 0; i < vec->size; ++i ) {
        vec->array[i] = temp[ i + 1 ];
    }
    free(temp[0]);
    free(temp);
}

void printVector(struct vector *vec) {
	int i;
	for ( i = 0; i < vec->size; ++i) { 
		printData(vec->array[i]);
	}
    printf("\n");
}
/* It will print summ of all values in all data structure */
float sumVector(struct vector *vec) {
    int i;
    float sum_of_data_struct = 0.0;
    for ( i = 0; i < vec->size; ++i ) {
        sum_of_data_struct += sumData(vec->array[i]);
    }
    return sum_of_data_struct;
}

/* Make another vector of same size and data */
struct vector* cloneVector(struct vector *vec) {
    int size = vec->size;
	struct vector* v_new = malloc(sizeof(struct vector));
	v_new->size = size;
	v_new->array = malloc(sizeof(struct data*)* size);
    int i;
    for ( i = 0; i < size; ++i ) {
        v_new->array[i] = malloc(sizeof(struct data));
        (v_new->array[i])->v1 = (vec->array[i])->v1;
        (v_new->array[i])->v2 = (vec->array[i])-> v2;
    }

    return v_new;
}
/* If two vectors are same in size and data, it will give 1, otherwise 0 */
int compareVectors(struct vector *vec1,struct vector *vec2) {
    if ( vec1->size == vec2->size ){
        int i;
        for ( i = 0; i < vec1->size; ++i ) {
            float v1_element1 = (vec1->array[i])->v1; 
            float v1_element2 = (vec1->array[i])->v2; 
            float v2_element1 = (vec2->array[i])->v1; 
            float v2_element2 = (vec2->array[i])->v2;

           if ( (v1_element1 == v2_element1) && (v1_element2 == v2_element2) ) {
                return 1;
           }else {
               return 0;
           }
        }

    } 
    return 0;
}
/* Reverse the array */
void reverseVector(struct vector *vec) {
    struct data** temp = vec->array;
    vec->array = malloc(sizeof(struct data*) * vec->size);
    int s = (vec->size) - 1;
    int i;
    for ( i = 0; i < vec->size; ++i ) {
        vec->array[i] = temp[s - i]; 
    } 
    free(temp);  
}

/* Free all the allocated space */
void cleanVector(struct vector *v) {
    int i;
    for ( i = 0; i < v->size; ++i ) {
        free(v->array[i]);
    }
    free(v->array);
    free(v);
}
