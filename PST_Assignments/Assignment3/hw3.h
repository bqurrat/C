/********************************************************************
 * Assignment # 3
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain- Sept 14, 2014
 ********************************************************************/

#ifndef HW3_H_
#define HW3_H_

struct geoData{
    int maxTerms;
    float x;
    float errorTol;
};
void calculateGeoSeries(struct geoData gd[],int arraySize);
struct geoData calculateGeo(struct geoData gd);
float power(float x, int y);
float absolute(float x);
void printGeoData(struct geoData gd);
struct geoData createGeoData(int max, float error, float x);

#endif
