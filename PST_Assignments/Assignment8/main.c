#include <stdio.h>

#include "structures.h"
#include "bst.h"

int main(int argc,char* argv[])
{
    struct tree *t = createTree();
    insertBst(t, createData(0, 0));
    insertBst(t, createData(1, 0));
    insertBst(t, createData(4, 0));
    insertBst(t, createData(2, 0));
    insertBst(t, createData(6, 0));
    insertBst(t,createData(7,0));
    
 /*

    insertBst(t,createData(99,1));
    insertBst(t,createData(49,1));
    insertBst(t, createData(149, 1));
    insertBst(t, createData(29, 1));
    insertBst(t, createData(9, 1));

    insertBst(t, createData(169, 1));
    insertBst(t, createData(179, 1));
   */
    
 /*   insertBst(t,createData(99,1));
    insertBst(t,createData(49,1));
    insertBst(t, createData(149, 1));
    insertBst(t, createData(29, 1));
    insertBst(t, createData(69, 1));
    insertBst(t,createData(9,1));
    
    insertBst(t,createData(39,1));
    insertBst(t, createData(169, 1));
    insertBst(t, createData(129, 1));
    insertBst(t, createData(109, 1));
    insertBst(t, createData(139, 1));
    insertBst(t, createData(159, 1));
    insertBst(t, createData(179, 1));
    
*/
    printf("inorder\n");
    inOrderBst(t);

    printf("preorder\n");
    preOrderBst(t);
    
    printf("postorder\n");
    postOrderBst(t);
    
    float sum = totalSum_r(t->root);
    printf("%f\n", sum);

    printf("getMax\n");
    struct data* max = getMaxData(t);
    printf("%f %f %f\n", max->v1, max->v2, sumData(max));
    

    printf("getMim\n");
    struct data* min_data = getMimData(t);
    printf("%f %f %f\n", min_data->v1, min_data->v2, sumData(min_data));
    
    int h = getBstHeight(t);
    printf(" Height = %d\n", h);
    
    printInRange(t, 97.0, 150.0);

    printf("Checking IsComplete\n");
    int res = isCompleteBst(t);
    printf("%d\n", res);
    
   printf("Checking isFull\n");
    int isFull_test = isFullBst(t);
    printf("%d\n", isFull_test);

/*
    printf("Checking sumLeaves\n");
    float sumresult= sumLeaves(t);
    printf("%f\n", sumresult);


    printf("Checking Breadth First search\n");
    printBreadthFirstSearch(t);
    
    printf("Checking Depth First search\n\n");
    printDepthFirstSearch(t);

    printf("Checking Reverse\n");
    reverseBST(t);
    printBreadthFirstSearch(t);
    
    cleanBST(t);
   */
    cleanBST(t);
    return 0;
}
