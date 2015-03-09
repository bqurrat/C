#include "bst.h"
#include <assert.h>

struct leaf* createLeaf(struct data *d)
{
  struct leaf* maple = malloc(sizeof(struct leaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->dta = d;
  return maple;
}

struct tree* createTree()
{
  struct tree* oak = malloc(sizeof(struct tree));
  oak->root = NULL;
  return oak;
}

void insertBst(struct tree *t,struct data *d)
{
    struct leaf* lf = createLeaf(d);
    if(t->root == NULL ) {
        t->root = lf;
    } else {
        insertBst_r(t->root, lf);
    }
}

void insertBst_r(struct leaf* current,struct leaf* newLeaf) {
    assert(current != NULL);

    if ( sumData(newLeaf->dta) <= sumData(current->dta)) {
        if ( current->left == NULL ) {
            current->left = newLeaf;
        } else {
            insertBst_r(current->left, newLeaf);
        }
    } else {
        if ( current->right == NULL ) {
            current->right = newLeaf;
        } else {
            insertBst_r(current->right, newLeaf);
        }
    }
}

void inOrderBst(struct tree *t) {
    if (t->root == NULL ) {
        return;
    }
    inOrderBst_r(t->root);
}

void inOrderBst_r(struct leaf *current) {
    //when to stop
    //1) print everything in left subTree (recurse)
    //2) print myself
    //3) print everything in right subTree
    if(current == NULL ) {
        return;
    }
    inOrderBst_r(current->left);
    printData(current->dta);
    inOrderBst_r(current->right);
}

void preOrderBst(struct tree *t) {
    if ( t->root == NULL ) {
        return;
    }
    preOrderBst_r(t->root);
}

void preOrderBst_r(struct leaf *lf) {
    if ( lf  == NULL ) {
        return;
    }

    printData(lf->dta);
    preOrderBst_r(lf->left);
    preOrderBst_r(lf->right);
}

void postOrderBst(struct tree *t) {
    postOrderBst_r(t->root);
}

void postOrderBst_r(struct leaf *lf) {
    if (lf == NULL ) {
        return;
    }
    
    postOrderBst_r(lf->left);
    postOrderBst_r(lf->right);
    printData(lf->dta);
}

struct data* getMaxData(struct tree *tr) {
    if (tr->root == NULL ) {
        return NULL;
    }
    struct data* d;
    d = getMaxData_r(tr->root);

    return d;    
}

struct data* getMaxData_r(struct leaf* lf) {
    if ( lf->right == NULL ) {
        return lf->dta;
    }
    
    struct data* dMax;
    dMax = getMaxData_r(lf->right);
    if ( sumData(lf->dta) > sumData(dMax)) {
        return (lf->dta);
    } else  {
        return dMax;
    }
}

struct data* getMimData(struct tree *tr) {
    if ( tr->root == NULL ) {
        return NULL;
    }   
    struct data* d;
    d = getMimData_r(tr->root);

    return d;
}

struct data* getMimData_r(struct leaf* lf) {
    if ( lf->left == NULL ) {
        return lf->dta;
    } 

    struct data* dMim;
    dMim = getMimData_r(lf->left);

    if ( sumData(lf->dta) <= sumData(dMim) ) {
        return lf->dta;
    } else {
        return dMim;
    }
}

void printInRange(struct tree *tr, float begin, float end) {
    if ( tr->root == NULL ) {
        return ;
    }
    printInRange_r(tr->root, begin, end);
}

void printInRange_r(struct leaf* lf, float begin,float end) {
    if ( lf == NULL ) {
        return;
    }
    printInRange_r(lf->left, begin, end);
    float new_val = sumData(lf->dta);
    if ( (new_val > begin) && (new_val < end) ) {
        printf("%f\n", new_val);
    }
    printInRange_r(lf->right, begin, end);
}

float totalSum(struct tree *t) {
    if ( t->root == NULL ) {
        return 0;
    }
    float sum = totalSum_r(t->root);
    return sum;
}

float totalSum_r(struct leaf* current) {
    if ( current == NULL ) {
       return 0;
    } 
    return sumData(current->dta) + totalSum_r(current->left) + totalSum_r(current->right); 
}

int getBstHeight(struct tree *tr){
    return getBstHeight_r(tr->root);
}

int getBstHeight_r(struct leaf* lf) {
    if ( lf == NULL ) {
        return 0;
    }
    int r = getBstHeight_r(lf->right);
    int l = getBstHeight_r(lf->left);

    if ( l > r ) {
        return l + 1;
    } else {
        return r + 1;
    }
}

int isCompleteBst(struct tree *tr) {
    if ( tr->root == NULL ) {
        return 0;
    }
    int res = isCompleteBst_r(tr->root);
    if ( res == -1 ) {
        return 0;
    } 
    return 1;
} 

int isCompleteBst_r(struct leaf* lf) {
    if ( lf == NULL ) {
        return 0;
    }
    if ( (lf->right == NULL) && (lf->left == NULL) ) {
        return 1;
    }

    int l = isCompleteBst_r(lf->left);
    int r = isCompleteBst_r(lf->right);

    if ( l == 0 ) return r + 1;
    if ( r == 0 ) return l + 1;
    
    if ( (l == r) && (l != -1) ) {
        return l + 1;
    } else {
        return -1;
    }
    
}

int isFullBst(struct tree *tr) {
    if ( tr->root == NULL ) {
        return 0;
    }
    int res = isFullBst_r(tr->root);

    return res;   
}

int isFullBst_r(struct leaf *lf) {
    //if this is leaf
    if ( (lf ->left == NULL) && (lf->right == NULL) ) {
        return 1;
    } else if ( lf->right == NULL ) {
        return 0;
    } else if ( lf->left == NULL  ) {
        return 0;
    } else {
        int l = isFullBst_r(lf->left);
        int r = isFullBst_r(lf->right);
        if ( l && r ) {
            return 1;
        } else {
            return 0;
        }
    }
    

}

float sumLeaves(struct tree *t) {
    if ( t->root == NULL ) {
        return 0;
    }
    float res = sumLeaves_r(t->root);
    return res;   
}

float sumLeaves_r(struct leaf *lf) {
    float sum = 0.0;
    
    if ( (lf->left == NULL) && (lf->right == NULL) ) {
        sum = sumData(lf->dta);
    } else if (lf->right == NULL ) {
        sum = sumLeaves_r(lf->left);
    } else if (lf->left == NULL ) {
         sum = sumLeaves_r(lf->right);
    } else {
        float l = sumLeaves_r(lf->left);
        float r = sumLeaves_r(lf->right);
        
        sum = l + r;
    }
    return sum;
}

void printBreadthFirstSearch(struct tree *t) {
    if ( t->root == NULL ) {
        return;
    } 
    struct queue* q = createQueue();
    pushQueue(q, t->root);

    while ( !isEmptyQueue(q) ) {
        struct leaf* current_node = topQueue(q);
       //printData(current_node->dta);
        float v = sumData(current_node->dta);
        printf("%f\n", v);
        popQueue(q);
        
        if ( current_node->left != NULL) {
            pushQueue(q, current_node->left);
        }
        if ( current_node->right != NULL) {
            pushQueue(q, current_node->right);
        }
    }
    cleanQueue(q);
}

void printDepthFirstSearch(struct tree *t) {
    if ( t->root == NULL ) {
        return;
    }
    struct stack* s = createStack();
    pushStack(s, t->root);

    while ( !isEmptyStack(s) ) {
        struct leaf* curr_node = topStack(s);
        //printData(curr_node->dta);
        float v = sumData(curr_node->dta);
        printf("%f\n",v);
        popStack(s);
        
        if ( curr_node->right != NULL ) {
            pushStack(s, curr_node->right);
        } 
        if ( curr_node->left != NULL ) {
            pushStack(s, curr_node->left);
        }
    }
    cleanStack(s);
}


void reverseBST(struct tree *t) {
    if ( t == NULL ) {
        return;
    }
    reverseBST_r(t->root);
}

void reverseBST_r(struct leaf *lf) {
    if ( lf == NULL ) return;
    reverseBST_r(lf->left);
    reverseBST_r(lf->right);
    swap(lf);
}
/*void reverseBST_r(struct leaf *lf) {
    if ( (lf->left == NULL) && (lf->right == NULL) ) {
        return;
    }
    if (lf->left != NULL ) {
        reverseBST_r(lf->left);
    }
    if ( lf->right != NULL ) {
        reverseBST_r(lf->right);
    }
    
    swap(lf);
}
*/

/* This is a helper function which will be used in reverse BST*/
void swap( struct leaf* l) {
    struct leaf* tmp = l->left;
    l->left = l->right;
    l->right = tmp;
}

/*Clean the structure tree and leaf */
void cleanBST(struct tree *t) {
    if (t->root == NULL ) {
        return;
    }
    cleanBST_r(t->root);
    free(t->root);
    free(t);
}
void cleanBST_r(struct leaf *lf) {
    if ( lf == NULL ) return;
    cleanBST_r(lf->left);
    cleanBST_r(lf->right);
    free(lf->left);
    free(lf->right);
    free(lf->dta);
    
    
}
