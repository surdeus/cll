/* C linked list implementation. */
#include <stdlib.h>
#include "ll.h"

LinkedList *
ll_create(void)
{
	LinkedList *l = malloc(sizeof(LinkedList)) ;
	l->first = malloc(sizeof(LinkedListEl)) ;
	l->first->next = 0 ;
	l->first->data = 0 ;
	l->len = 0 ;
	return l ;
}

void
ll_append(LinkedList *l, void *data)
{
	int i, len;
	len = l->len ;
	LinkedListEl *el = l->first ;
	for( i=0 ; i<len ; ++i)
		el = el->next ;
	el->next = malloc(sizeof(LinkedListEl)) ;
	el->next->data = data ;
	++l->len;
}

void
ll_push(LinkedList *l, void *data)
{
	LinkedListEl *el = l->first->next ;
	l->first->next = malloc(sizeof(LinkedListEl)) ;
	l->first->next->data = data ;
	l->first->next->next = el ;
	++l->len;
}

void *
ll_at(LinkedList *l, unsigned int n)
{
	unsigned int i;
	LinkedListEl *el;

	if(n >= l->len) return 0 ;

	el = l->first->next;
	for( i=0 ; i<n ; ++i )
		el = el->next ;

	return el->data ;
}

int
ll_remove(LinkedList *l, unsigned int n)
{
	int i;
	LinkedListEl *el, *buf;

	if(n>=l->len) return -1 ;

	el = l->first ;
	for( i=0 ; i<n ; ++i)
		el = el->next ;	

	buf = el->next ;
	el->next = el->next->next;
	free(buf);

	--l->len;
	return 0 ;
}

int
ll_insert(LinkedList *l, unsigned int n, void *data)
{
	unsigned int i;
	LinkedListEl *el, *buf;

	if(n > l->len) return -1 ;

	el = l->first ;
	for( i=0 ; i<n ; ++i)
		el = el->next ;

	buf = el->next ;
	el->next = malloc(sizeof(LinkedListEl)) ;
	el->next->data = data ;
	el->next->next = buf ;

	++l->len;
	return 0 ;
}

