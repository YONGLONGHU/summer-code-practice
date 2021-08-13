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