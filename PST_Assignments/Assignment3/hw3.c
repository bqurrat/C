/********************************************************************
 * Assignment # 3
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain - Sept 14, 2014
 ********************************************************************/

#include<stdio.h>
#include "hw3.h"

/* This Function will create structure of geoData and 
 * set the values to struct of input values */  
struct geoData createGeoData(int max, float error, float x){
    struct geoData gd;
    gd.maxTerms = max;
    gd.x = x;
    gd.errorTol = error;
    
    return gd;
}

/* This function will print the valuyes in the structure */
void printGeoData(struct geoData gd) {
    printf("%d %g %g \n", gd.maxTerms, gd.x, gd.errorTol);
}

/* Thsi function will take the input and if it is negative, ie will return its absolute value */
float absolute(float x) {
    if ( x < 0 ) {
        x = (-1) * x;
    }
    return x;
}

/* This function will take two input values
 * Take first input and calculat ethe power till second input */
float power(float x, int y) {
    int j = 1;
    float power = 1;
    for ( j = 1; j <= y; ++j ) {
        power = power * x;
    }
    return power;
}

/* This function will calculate the geometric series untill one of the while condition becomees false */
struct geoData calculateGeo(struct geoData gd){
 
    int counter = 1;
    float expectedValue = (1 / ( 1 + gd.x));
    float runningSum = 1.0;
    float calculatedError = runningSum - expectedValue;

    if ( gd.maxTerms == 1){
		gd.x = gd.maxTerms;
		gd.errorTol = calculatedError;
     }else {

        /* Keep calculating the values until these conditions are true */
        while ( (calculatedError > gd.errorTol) && (counter <= gd.maxTerms) ) {
        	++counter;
        	if ( counter % 2 == 0 ) {
            	runningSum -= power(gd.x, counter - 1);
        	} else {
            	runningSum += power(gd.x, counter - 1);
        	}
        	calculatedError = (runningSum - expectedValue);
        	calculatedError = absolute(calculatedError);
    	}
    	gd.errorTol = calculatedError;
    	gd.x = runningSum;
    	gd.maxTerms = counter;
    }
    return gd;
}
/* This function will take the structure array as input
 * Calculate the geometric series by calling calculateGeo Function 
 * Printout that values by calling printGeoData function */
void calculateGeoSeries(struct geoData gd[],int arraySize){
    int i = 0;
    for ( i = 0; i < arraySize; ++i ) {
        printGeoData(calculateGeo(gd[i]));
    }

}
