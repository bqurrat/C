#include <stdio.h>
#include "structures.h"
#include "random.h"
#include "structures.h"
#include "avl.h"
#include "bst.h"
#include "timing.h"

int main(int argc,char* argv[])
{ 
    if ( argc < 2 ) {
    exit(0);
    } 
    struct avlTree* t = createAvlTree();
    struct tree* bt = createTree();
    
    randSeed();
    /* Going to insert random Data in avl */
    clock_t start = getTime();
    int i;
    for ( i = 0; i < atoi(argv[1]) * 1000000; ++i ) {
        insertAvl(t,randomData());
    }
    clock_t end = getTime();
    float diff = timeDiff(start,end);
    printf("Avl Insert Time = %f\n", diff);
    
    /* Going to insert random Data in bst */
    start = getTime();
    for ( i = 0; i < atoi(argv[1]) * 1000000; ++i ) {
        insertBst(bt, randomData());
    }
    end = getTime();
    diff = timeDiff(start, end);
    printf("Bst Insert Time = %f\n",diff);
    
    /* Going to searchAvl random Data in avl */
    start = getTime();
    for ( i = 0; i < atoi(argv[1]) * 1000000; ++i ) {
        struct data* d = randomData();
        searchAvl(t, d);
        free(d);
    
    }
    end = getTime();
    diff = timeDiff(start, end);
    printf("search Time for Avl = %f\n", diff);
    
    /* Going to searchBST ramdomData in BST */
    start = getTime();
    for ( i = 0; i < atoi(argv[1]) * 1000000; ++i ) {
        struct data* d1 = randomData();
        searchBst(bt, d1);
       free(d1); 
    }
    end = getTime();
    diff = timeDiff(start, end);
    printf("search time for Bst = %f\n", diff);
    
    cleanAvl(t);
    cleanBST(bt);
    return 0;
}
