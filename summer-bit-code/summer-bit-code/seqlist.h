#ifndef _SEQLIST_
#define _SEQLIST_
#include"common.h"
#define elemtype int
typedef struct seqlist
{
	elemtype * base;
	size_t capacity;
	size_t size;
}seqlist;
void seqlistinit(seqlist * pst, int capacity);




void seqlistinit(seqlist * pst, int capacity)
{
	pst->base = (elemtype *)malloc(sizeof(elemtype)*capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0,sizeof(elemtype)*capacity);
	pst->capacity = capacity;
	pst->size = 0;
}


#endif