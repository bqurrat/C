/********************************************************************
 * Assignment # 3
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain - Sept 14, 2014
 ********************************************************************/

#include "hw3.h"

int main() {
    int arraySize = 10;
    struct geoData gd[arraySize];
    int i = 0;

    /* This loop will generate create array of GeoData structs using createGeoData function
     * Here we are using hardcoded values for each iteration
     * But this function can create any given values */
    for ( i = 0; i <  arraySize; ++i){
    	gd[i] = createGeoData(50,0.001,0.5);
    }

    calculateGeoSeries(gd, arraySize);
       
return 0;
}

