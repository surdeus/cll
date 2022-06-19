#include <stdio.h>
#include <stdlib.h>

#include <ll/ll.h>

void
printEls(LinkedList *l)
{
	int i;
	printf("[");
	for( i=0 ; i < l->len ; ++i ){
		printf("%d, ", *(int *)ll_at(l, i));
	}
	puts("]");
}

int
main(int argc, char *argv[])
{
	int a[] = {0, 1, 2, 3, 4} ;
	LinkedList *l = ll_create() ;
	printEls(l);
	ll_append(l, &a[0]);
	printEls(l);
	ll_append(l, &a[1]);
	printEls(l);
	ll_push(l, &a[1]);
	printEls(l);
	ll_insert(l, 0, &a[2]);
	printEls(l);
	ll_insert(l, 4, &a[3]);
	printEls(l);
	ll_swap(l, 0, 4);
	printEls(l);
	ll_remove(l, 1);
	printEls(l);
	ll_remove(l, 3);
	printEls(l);
	ll_remove(l, 1);
	printEls(l);
	ll_remove(l, 1);
	printEls(l);
	return 0 ;
}
