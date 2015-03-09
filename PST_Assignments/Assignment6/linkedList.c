/******************************************************************** 
 * Assignment # 6
 * Programming systems and tools - CS580U
 * Copyright Qurrat Ul Ain
 ********************************************************************/ 



#include "linkedList.h"

struct node* createNode(struct data *dta) {
    struct node* n = malloc(sizeof(struct node));
    n->dta = dta;
    n->next = NULL;

    return n;
}

struct linkedList* createLinkedList() {
    struct linkedList* s = malloc(sizeof(struct linkedList));
    return s;
}

void addNPos(struct linkedList* ll, struct data* dta, int n) {
  /* Create a node first and wire it up to the data
   * and make the next field NULL for now
   */
  struct node* new_one = malloc(sizeof(struct node));
  new_one->dta = dta;
  new_one->next = NULL;

  /* Create two node*, and separate them, such that the prev
   * points to the node just before the position where new_one
   * should be wired in
   */
  struct node* cur;
  struct node* prev;
  cur = prev = NULL;
  int pos = 0;

  for ( cur = ll->head; cur != NULL; cur = cur->next ) {
    if ( pos == n ) {
      break;                     // prev and cur are off by one node
    }
    ++pos;
    prev = cur;
  }

  if ( prev == NULL ) {         // Happesn when n == 0 or head == NULL
    new_one->next = ll->head;
    ll->head = new_one;
  } else {                      // The rest of the normal cases
    new_one->next = prev->next;
    prev->next = new_one;
  }
}

void removeNPos(struct linkedList* ll, int n) {
  /* If there is nothing to remove just return */
  if ( ll->head == NULL ) {
    return;
  }

  struct node* cur;
  struct node* prev;
  cur = prev = NULL;
  int pos = 0;

  for ( cur = ll->head; cur->next != NULL; cur = cur->next ) {
    if ( pos == n ) {
      break;                     // prev and cur are off by one node
    }
    ++pos;
    prev = cur;
  }

  if ( prev == NULL ) {         // Happens when there is a single element
    ll->head = NULL;
  } else {
    prev->next = cur->next;
    cur->next = NULL;
  }

  /* Now free the node pointed by cursor, by calling
   * a helper function that frees the data first
   * and then the node itself
   */
  freeNode(cur);
}

void cleanLinkedList(struct linkedList* ll) {
  if ( ll->head == NULL ) {
    /* nothing to clean */
    return;
  }

  struct node* prev = ll->head;
  struct node* cur = NULL;

  while ( prev->next != NULL ) {
    cur = prev->next;
    freeNode(prev);
    prev = cur;
  }

  /* Finally clean off the last node as well */
  freeNode(prev);
  ll->head = NULL;
  free(ll);
}

char* getLetterCount(struct linkedList* ll) {
  if ( ll->head == NULL ) return NULL;
  if ( ll->head->next == NULL ) return ll->head->dta->letters;

  /* There are now two or more nodes in the linked list
   * Get the count of letters in the first node
   */
  int count[26] = { 0 };    // all elements are 0
  struct node* cur = ll->head;
  getCount(count, cur->dta);

  int running_count[26] = { 0 };
  for ( cur = ll->head; cur != NULL; cur = cur->next ) {
    getCount(running_count, cur->dta);

    int j;
    for ( j = 0; j < 26; ++j ) {
      if ( running_count[j] < count[j] ) {
        count[j] = running_count[j];
      }
      running_count[j] = 0;   // clean array for next node
    }
  }

  char* result = createString(count, 26);
  return result;
}


/**********************************************
 *              HELPER FUNCTIONS              *
 **********************************************/


void printlinkedList(struct linkedList* ll) {
  struct node* cur;
  int pos = 0;
  for ( cur = ll->head; cur != NULL; cur = cur->next ) {
    printf("Node# %d:\t%s\n", pos, cur->dta->letters);
    ++pos;
  }
}

void freeNode(struct node* cur) {
  if ( cur == NULL ) {
    return;
  }
  freeData(cur->dta);
  free(cur);
}

void freeData(struct data* dta) {
  if ( dta == NULL ) {
    return;
  }
  free(dta->letters);
  free(dta);
}

void getCount(int arr[], struct data* dta) {
  char* str = dta->letters;
  char c = 'a';
  while ( *str != '\0' ) {
    c = *str++;
    ++arr[c - 'a'];
  }
}

char* createString(int count[], int size) {
  if ( size != 26 ) return NULL;

  int str_len = 0;
  int k;
  for ( k = 0; k < size; ++k ) {
    str_len += count[k];
  }
if ( str_len == 0 ) return NULL;

  char* result = malloc(sizeof(char) * (str_len + 1));
  int i;
  int j;
  int ctr = 0;
  for ( i = 0; i < size; ++i ) {
    for ( j = 0; j < count[i]; ++j ) {
      result[ctr++] = i + 97;     // Add the ASCII values of a-z
    }
  }

  /* Important to null terminate the string */
  result[ctr]  = '\0';
  return result;
}



void addFront(struct linkedList *ll, struct data * dta) {
	struct node* n = createNode(dta);
	n->next = ll->head;
	ll->head = n;
}

void addBack(struct linkedList *ll, struct data* dta) {
	struct node* n = createNode(dta);
	if ( ll->head == NULL ) {
		ll->head = n;
	} else {
		struct node* temp = ll->head;
		while ( temp->next != 0 ) {
			temp = temp->next;
		}
		temp->next = n;
}
}

void removeFront(struct linkedList *ll) {
	struct node* temp = ll->head;
	ll->head = ll->head->next;
	free(temp->dta);
	free(temp);
	
}

void removeBack(struct linkedList *ll) {
	struct node* temp = ll->head;
	if (temp->next == NULL) {
		free(temp->dta);
		free(temp);
	} else {
		while ( (temp->next->next) != NULL ) {
		temp = temp->next;
		}
	}
	free(temp->next->dta);
	temp->next = NULL;
	free(temp);
	
}
void printLinkedList(struct linkedList *ll) {
	struct node* temp = ll->head;
	while (temp != NULL ) {
		printData(temp-> dta);
		temp = temp -> next;
	} 
	printf("\n");
}

int length(struct linkedList *ll) {
	struct node* temp = ll->head;
	int counter = 0;
	
	while ( temp !=  0) {
		++counter;
		temp = temp->next;
	}

	return counter;
}

