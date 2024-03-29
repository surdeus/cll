#include <stdlib.h>
#include <ll/ll.h>

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

int
ll_swap(LinkedList *l, unsigned int i1, unsigned int i2)
{
	int i;

	LinkedListEl *el1, *el2;
	void *v;

	if(i1 == i2)
		return 0 ;

	if(i1 >= l->len || i2 >= l->len )
		return 1 ;


	el1 = l->first ;
	for(i=0 ; i<=i1 ; ++i)
		el1 = el1->next ;

	el2 = l->first ;
	for(i=0 ; i<=i2 ; ++i)
		el2 = el2->next ;

	v = el1->data ;
	el1->data = el2->data ;
	el2->data = v ;

	return 0 ;
}

void
ll_reverse(LinkedList *l)
{
	int i, end, len;
	end = l->len / 2 ;
	len = l->len ;
	for(i=0 ; i<end ; ++i){
		ll_swap(l, i, len-1-i);
	}
}

void
ll_bubbleSort(LinkedList *l, int (*fn)(void *, void *))
{
	int i, j;
	for(i=0 ; i<l->len - 1 ; ++i){
		for(j=0 ; j<l->len - 1 - i ; ++j){
			if(fn(ll_at(l, j), ll_at(l, j+1)) > 0){
			   ll_swap(l, j, j+1);
			}
		}
	}
}

