/********************************************************************
 * Assignment # 4
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain - Oct 7, 2014
 ********************************************************************/
#include "hw4.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 /* This function will allocate the space for input structure and array
  * Then it will fill the array with random number by using getRand function
  * Set the varibles in structure
  *	Then return a pointer to array 
  */ 
struct input* generateArray(int size) {
	struct input* pointer_to_inputStruc;
	pointer_to_inputStruc = malloc(sizeof(struct input));
	
	int *pointer_to_array;
	pointer_to_array = malloc(sizeof(int) * size);
	
	int i = 0;
	for ( i = 0; i < size; ++i ) {
		pointer_to_array[i] = getRand();
	}

	pointer_to_inputStruc -> array= pointer_to_array;
	pointer_to_inputStruc -> size = size;
	
	return pointer_to_inputStruc;
}

 /* This function will allocate the space for structure data
  * And the set the elements of data 
  * Then return a pointer to that data 
  */ 
struct data* generateData(int s,int e) {
	struct data* pointer_to_dataStruc;
	pointer_to_dataStruc = malloc(sizeof(struct data));

	pointer_to_dataStruc->Start = s;
	pointer_to_dataStruc->End = e;
	pointer_to_dataStruc->Max = -999;

	return pointer_to_dataStruc;
}

 /* This function will allocate the space for array of pointers
  * Each pointer in the array will point to a structure named data
  * For each element of arary set the values of stucture data by using function generateData
  */ 
struct data** generateDataArray(int size) {
	struct data** array_of_pointer_to_struct = malloc(sizeof(struct data*) * size);
	int i;
	
	for ( i = 0; i < size; ++i ) {
		int s_min = getRandBetween(0,size/2);
		int e_min = getRandBetween(size/2, size);
		array_of_pointer_to_struct[i] = generateData(s_min, e_min);
	}

	return array_of_pointer_to_struct;
}

 /* This function will extaract the start and end values from structure data
  * Then it will iterate through loop from index where start is located to the index where end is located 
  * In the loop it will calculate the differenec between two consecutive elements of array
  * Set the maximum difference equal to max_difference
  * Set the max of strucrure data equals to max_difference
  */ 
void getMax(struct input *inputArr, struct data *dVals) {
	int s = dVals->Start;
	int e = dVals->End;
	int i;
	int j;

	int largest = INT_MIN;
	for ( j = e; j > s; --j ) {
		for ( i = j - 1; i >= s; --i ) {
			int diff = (inputArr->array)[j] - (inputArr->array)[i];
			if ( diff > largest ) {
				largest = diff;	
			}
		}
	}
	
	dVals->Max = largest;
}

 /* Caller will give the pointer of pointer to structure data 
  * Extarct the values inside that structure data
  * Print the values
  */
void printData(struct data **d, int dataSize){
	int i;
	for ( i = 0; i < dataSize; ++i) {
		int s = d[i]->Start;
		int e = d[i]->End;
		int m = d[i]->Max;
		printf ("%d %d %d\n", s, e, m); 
	}
}

 /* Caller will give the pointer of pointer to struct data, size and pointer to struct inout 
  */
void findMax(struct data **points, int pointsSize, struct input *inputs){
	int i;
	for ( i = 0; i < pointsSize; ++i ) {
		getMax(inputs, points[i]);	
	}
}
