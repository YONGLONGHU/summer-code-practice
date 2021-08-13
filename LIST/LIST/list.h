#ifndef _LIST_
#define _LIST_
#include"conmon.h"
#define elemtype int
typedef struct listnode
{
	elemtype date;
	struct listnode * next;
}listnode;
typedef listnode * list;

//函数声明
void listinit(list * pst);
void listshow(list pst);
listnode * buynode(elemtype v);
void listpushfront(list * pst);
void listpushhead(list * pst);
void listpopback(list * pst);
void listpopfront(list * pst);
size_t listlen(list * pst);
listnode * findlist(list * pst, elemtype v);



//函数实现
void listinit(list * pst)
{
	*pst = NULL;//链表类型的指针代表链表，初始化将这类指针指向为空代表
	             //此时为一个空链表            
}

void listshow(list  pst)
{
	listnode * p = pst;
	while (p != NULL)
	{
		printf("%d ", p->date);
		p = p->next;
	}
	printf("\n");
}
listnode * buynode(elemtype v)//向空间申请一个结点并赋值返回地址
{
	listnode * s = (listnode *)malloc(sizeof(listnode));
	s->date = v;
	s->next = NULL;
	return s;
}

void listpushback(list * pst, elemtype v)//尾插法
{
	listnode * s = buynode(v);
	listnode * p = *pst;
	if (p == NULL)
	{
		*pst = s;
		return;
	}
	while (p != NULL)
	{
		p = p->next;
	}
	p->next = s;
}
void listpushfront(list * pst, elemtype v)
{
	listnode * s = buynode(v);
	if (*pst == NULL)
	{
		*pst = s; 
		return;
	}
	s->next = *pst;
	*pst = s;
}
void listpopback(list * pst)
{
	if (*pst == NULL)
		return;
	else if ((*pst)->next == NULL)
	{
		free(*pst);
		*pst == NULL;
	}
	else
	{
		listnode * p = *pst;
		listnode *prev = NULL;
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		free(p);
		prev->next = NULL;
	}
}

void listpopfront(list * pst)
{
	if (pst == NULL)
		return;
	else if ((*pst)->next == NULL)
	{
		free(pst);
		*pst == NULL;
	}
	else
	{
		free(*pst);
		*pst = (*pst)->next;
	}
}
size_t listlen(list * pst)
{
	listnode * p = * pst;
	int len = 0;
	while (p!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

listnode * findlist(list * pst, elemtype v)
{
	listnode * p = *pst;
	if (p != NULL&&p->date != v)
		p = p->next;
	return p;
}
///////////////////////////////////////////
//建立链表
void greatlisttail(list * pst)//尾插法
{
	*pst = (listnode *)malloc(sizeof(listnode)); 
	assert(*pst != NULL);
	(*pst)->date = 1;
	(*pst)->next = NULL;
	listnode * p = *pst;
	for (int i = 2; i < 11; ++i)
	{
		listnode * s= (listnode *)malloc(sizeof(listnode));
		assert(s!= NULL);
		s->date = i;
		s->next = NULL;//开辟结点赋初值
		              //链接形成链表
		p->next = s;
		p = p->next;
	}
}
void greatlisthead(list * pst)//头插法
{
	*pst = (listnode *)malloc(sizeof(listnode));
	assert(*pst != NULL);
	(*pst)->date = 1;
	(*pst)->next = NULL;
	for (int i = 0; i < 11; i++)
	{
		listnode * s = (listnode *)malloc(sizeof(listnode));
		s->date = i;
		s->next = NULL;//建立结点初始化
		//链接成链表
		s->next = *pst;
		*pst = s;
	}
}
void listshow1(list pst)
{
	listnode * p = pst;
	while (p != NULL)
	{
		printf("%d ", p->date);
	}
	printf("\n");
}
#endif