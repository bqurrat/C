/******************************************************************** 
 * Assignment # 9
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain
 ********************************************************************/ 

#include "avl.h"
#include <assert.h>


struct avlLeaf* createAvlLeaf(struct data *d)
{
  struct avlLeaf* maple = malloc(sizeof(struct avlLeaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->parent = NULL;
  maple->dta = d;
  maple->height = 1;
  return maple;
}

struct avlTree* createAvlTree()
{
  struct avlTree* oak = malloc(sizeof(struct avlTree));
  oak->root = NULL;
  return oak;
}
 void rotateRight(struct avlTree *t,struct avlLeaf *current)
  {
      struct avlLeaf *temp=current->left;
      current->left=temp->right;
      if(temp->right!=NULL)
          temp->right->parent=current;
      temp->right=current;
      temp->parent=current->parent;
          if(temp->parent==NULL)
                  t->root=temp;
          else if(temp->parent->left==current)
                temp->parent->left=temp;
         else
                 temp->parent->right=temp;

         current->parent=temp;
 
 
      current->height=maxHeight(getHeight(current->left),getHeight(current->right))+1;
      temp->height=maxHeight(getHeight(temp->left),getHeight(temp->right))+1;
  }


 void rotateLeft(struct avlTree *t,struct avlLeaf *current)
 {
         struct avlLeaf *temp=current->right;
         current->right=temp->left;
         if(temp->left!=NULL)
                 temp->left->parent=current;
         temp->left=current;
         temp->parent=current->parent;

         if(temp->parent==NULL)
                 t->root=temp;
         else if(temp->parent->right==current)
                 temp->parent->right=temp;
         else
                 temp->parent->left=temp;

          current->parent=temp;
 
      current->height=maxHeight(getHeight(current->left),getHeight(current->right))+1;
      temp->height=maxHeight(getHeight(temp->left),getHeight(temp->right))+1;
  }

void insertAvl(struct avlTree *t,struct data *d){

     struct avlLeaf* newLeaf = createAvlLeaf(d);
     if(t->root==NULL){
         t->root=newLeaf;
     }
     else
         insertAvl_r(t,t->root,newLeaf);

 }

void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf)
 {
     assert(current!=NULL);
    // {
     if(sumData(newLeaf->dta)<= sumData(current->dta))
     {
         if(current->left==NULL){

             current->left=newLeaf;
             newLeaf->parent = current;

         }
         else
             insertAvl_r(t,current->left,newLeaf);
     }

else
     {
         if(current->right==NULL){
             current->right=newLeaf;
             newLeaf->parent=current;
         }
         else{
             insertAvl_r(t,current->right,newLeaf);
         }
     }

     current->height = maxHeight(getHeight(current->left),getHeight(current->right))+1;

     if(getBalanceFact(current) == 2)
     {
         if(getBalanceFact(current->right) == 1)
             rotateLeft(t,current);
         else if(getBalanceFact(current->right) == -1){
                 rotateRight(t,current->right);
                 rotateLeft(t,current);
         }
     }

     if(getBalanceFact(current)== -2)
     {
         if(getBalanceFact(current->left) == -1)
             rotateRight(t,current);
         else if(getBalanceFact(current->left) == 1){
                 rotateLeft(t,current->left);
                 rotateRight(t,current);
         }


     }
 }
int maxHeight(int a,int b) {
    if ( a > b ) {
        return a;
    } else { 
        return b;
    }                       

}
int getHeight(struct avlLeaf *lf) {
    if ( lf == NULL ) {
        return 0;
    } else {
        return lf->height;
    }
}
int getBalanceFact(struct avlLeaf *lf) {
    int l = getHeight(lf->left);
    int r = getHeight(lf->right);
    int bf = r - l;
    return bf; 
}

int getavlHeight(struct avlTree *tr){
        return getavlHeight_r(tr->root);
}

int getavlHeight_r(struct avlLeaf* lf) {
    if ( lf == NULL ) {
        return 0;
    }
    int r = getavlHeight_r(lf->right);
    int l = getavlHeight_r(lf->left);

    if ( l > r ) {
        return l + 1;
    } else {
        return r + 1;
    }
}
void cleanAvl(struct avlTree *t){
    if ( t->root == NULL ) {
        return;
    }
    cleanAvl_r(t->root);
    free(t->root);
    free(t);
}

void cleanAvl_r(struct avlLeaf *lf) {
    if ( lf == NULL ) return;
    cleanAvl_r(lf->left);
    cleanAvl_r(lf->right);
    free(lf->left);
    free(lf->right);
    //free(lf->parent);
    free(lf->dta);
    
}

int searchAvl(struct avlTree *t,struct data *d) {
   if ( t->root == NULL ) {
        return 0;
   } else {
        int res = searchAvl_r(t->root, d);
        return res;
   }
} 

int searchAvl_r(struct avlLeaf *curr,struct data *d) {
    if ( curr == NULL ) {
    return 0;
    }
    if ( sumData(curr->dta) == sumData(d) ) {
        return 1;
    } else if ( sumData(d) <= sumData(curr ->dta) ) {
        return searchAvl_r(curr->left, d);
    } else {
        return searchAvl_r(curr->right,d);
    }
    /*if ( curr == NULL ) {
    return 0;
    }*/
}

void inOrderAvl(struct avlTree *t) {
    if ( t->root == NULL ) {
        return;
    }
    inOrderAvl_r(t->root);
}

void inOrderAvl_r(struct avlLeaf *current) {
    if (current == NULL ) {
        return;
    }
    inOrderAvl_r(current->left);
    printData(current->dta);
    inOrderAvl_r(current->right);
}

