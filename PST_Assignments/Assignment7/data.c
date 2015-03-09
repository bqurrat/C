#include "data.h"

struct data* createData(float v1,float v2)
{
  struct data* dta = malloc(sizeof(struct data));
  dta->v1 = v1;
  dta->v2 = v2;
  return dta;
}


int compareData(struct data *dta1,struct data *dta2)
{
  if( (dta1->v1 == dta2->v1) && (dta1->v2 == dta2->v2))return 1;
  return 0;
}


float sumData(struct data *dta)
{
  return (dta->v1 + dta->v2);
}

void printData(struct data *dta)
{
  printf("%f %f\n",dta->v1,dta->v2);
}

struct data* createDataNumeral(char num) {
	struct data* new_dta = malloc(sizeof(struct data));
	new_dta->numeral = num;
	new_dta->v1 = 0;
	new_dta->v2 = 0;

	return new_dta;
}
