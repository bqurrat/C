#include "linkedList.h"
#include "assert.h"
int main(int argc, char* argv[])
{	
	// char* s = "Test";
	//struct data* d = createDataLetters(s);

	//struct linkedList *ll;
	//ll = createLinkedList();
	
	/* To check if there is no node */
	//removeNPos(ll, 0);
	//removeNPos(ll, 3);
	//removeNPos(ll, 0);
	
	//addNPos(ll, d, 200);
	//printLinkedList(ll);

	//removeNPos(ll, 300);
	//printLinkedList(ll);
	
	//addFront(ll, createDataLetters("1abc"));
	//addFront(ll, createDataLetters("2abc"));
	//addFront(ll, createDataLetters("3abc"));
	//addFront(ll, createDataLetters("4abc"));
	//addFront(ll, createDataLetters("5abc"));

	//printLinkedList(ll);
	//addNPos(ll, d, 200);
	//printLinkedList(ll);
	//removeNPos(ll, 3);
	//printLinkedList(ll);
	//cleanLinkedList(ll);
	

  if ( argc < 2 ) return 1;

  struct linkedList* ll = malloc(sizeof(struct linkedList));
  ll->head = NULL;

  int i;
  for ( i = 1; i < argc; ++i ) {
    addNPos(ll, createDataLetters(argv[i]), 0);
  }

 // printLinkedList(ll);
  char* ans = getLetterCount(ll);
  if ( ans ) {
  printf("%s\n", ans);
  }

	free(ans);
	cleanLinkedList(ll);

  return 0;
}
