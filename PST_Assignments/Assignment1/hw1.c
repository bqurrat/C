

#include <stdio.h>

void addValues(int a,int b,int c);
double divideValues(float value1,float value2, float value3);
void callfunc(float a,float b,float c);

/* Add three number */
void addValues(int a,int b,int c){
	int result = a + b + c;
	printf(" Result from function addValues = %d \n", result);
}

/* divide first two numbers and then it will divide the result by third value */
double divideValues(float value1,float value2, float value3){
	if ( value1 == 0 || value2 == 0 || value3 ==0){
		printf("Incorrect input in function divideValues\n");
		return 0;
	}
	else {
	double divisonOfFirstTwoVal = (value1 / value2);
	double finalDivision = (divisonOfFirstTwoVal / value3);
	return finalDivision;
	}
}

/* Call the divideValues function */
void callfunc(float a,float b,float c){
	double result1 = divideValues(a, b, c);
	printf(" Result from function callfunc = %lf \n", result1);
}

int main(){
	addValues(2,4,6);
	callfunc(36.0,3.0,2.0);
	return 0;
}

