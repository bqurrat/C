/******************************************************************** 
 * Assignment # 2
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain, Sept 14, 2014
 ********************************************************************/ 
 
#include <stdio.h>
#include <stdlib.h>

/* Function signatures */
int minHardDrives(int used[],int usedSize,int total[],int totalSize);
int findProfit(int cost[], int sales[], int unitSales[],int arraySizes);
void getMinFans(int fanSizes[],int numFans, int coolingNum);
int compare(const void * a, const void * b);
void qsort(void* base, size_t num, size_t size,int (*compar)(const void*,const void*));

int main() {
  
    /******************************Testing Q# 1 ******************************/
    int fanSizes2[] = {1, 2, 3, 4, 5, 6, 10};
    int numFans2 = 7;
    int  coolingNum2 = 10;

    getMinFans(fanSizes2, numFans2, coolingNum2);

    /***************************** Testing Q# 2 ******************************/
    int used[] = {14, 20, 10, 22};
    int usedSize = 4; 
    int total[] = {80, 120, 120, 80}; 
    int totalSize = 4;

    int requiredDrive = minHardDrives(used, usedSize, total, totalSize);
    printf("%d\n", requiredDrive);
    
    /***************************** Testing Q# 3 ******************************/
    int cost[] = {4,3,7};
    int sales[] = {5,6,9}; 
    int unitSales[] = {1,1,1}; 
    int arraySize = 3;

    int findProfit_result1 = findProfit(cost, sales, unitSales, arraySize);
    printf("%d\n", findProfit_result1);
        
    return 0;
}

/* Function implementations */
int compare (const void * a, const void * b) {
    return ( *(int*)b - *(int*)a );
}

/* This function calcuates the minimum number of hard drives
 * required to store the consolidated data
 */
int minHardDrives(int used[],int usedSize,int total[],int totalSize) {
    int i = 0;
    int j = 0;     
    int total_used_space = 0;

    /* Get the total used space by summing the used[] array */  
    for ( i = 0; i < usedSize; ++i ) {
                total_used_space += used[i];
        }
        
    /* Use the library function to sort the array in descending order */
        qsort(total, totalSize, sizeof(int), compare);
        
    /* Subtract each element of the sorted disk space until all of 
     * consolidated data is stored
     */ 
    for ( j = 0; j < totalSize; ++j ) {
                total_used_space -=  total[j];
                if ( total_used_space <= 0 ) {
                        return j + 1;
                }
        }
    /* If total number of given hard drives are not enough to store
     * the data, return a negative value to notify the user
     */
        return -1;
}


/* This funcion calulates the item that it most profitable 
 * and return the index of that item 
 */
int findProfit(int cost[], int sales[], int unitSales[],int arraySizes){
    int i = 0;
    int j = 0;
    int max = unitSales[0] * (sales[0] - cost[0]);
    int max_index = 0;
    
    for ( i = 1; i < arraySizes; ++i) {
        int current = unitSales[i] * (sales[i] - cost[i]);
        if ( current > max ) {
            max = current;
            max_index = i;
        }        
    }
    return max_index;
}

/* This function calculates the minimum fans needed to cool the computer
 * with smallest amount of power consumption
 */
void getMinFans(int fanSizes[],int numFans, int coolingNum) {
  int num_fans_used = 0;
  int fans_used[numFans];
  int i = 0;

  for ( i = 0; i < numFans; ++i ) {
    if ( coolingNum <= 0 ) {
      break;
    } else {
      coolingNum -= fanSizes[i];
      fans_used[i] = fanSizes[i];
    }
  }

  --i;  // index to the last fan added

  if ( coolingNum != 0 ) {
    /* Iterate backwards and try removing the most power
     * consuming fan
     */
    coolingNum = -1 * coolingNum;

    int j;
    for ( j = i; j >= 0; --j ) {
      if ( fans_used[j] == coolingNum ) {
        fans_used[j] = -1;      // signifying removal
        break;
      }
    }
  }

  int k;
  for ( k = 0; k <= i; ++k ) {
    if ( fans_used[k] != -1 ) {
      printf("%d ", fans_used[k]);
      
    }
   }
   printf("\n");
}
   


