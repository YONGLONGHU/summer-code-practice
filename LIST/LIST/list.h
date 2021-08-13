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

//��������
void listinit(list * pst);
void listshow(list pst);
listnode * buynode(elemtype v);
void listpushfront(list * pst);
void listpushhead(list * pst);
void listpopback(list * pst);
void listpopfront(list * pst);
size_t listlen(list * pst);
listnode * findlist(list * pst, elemtype v);



//����ʵ��
void listinit(list * pst)
{
	*pst = NULL;//�������͵�ָ�����������ʼ��������ָ��ָ��Ϊ�մ���
	             //��ʱΪһ��������            
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
listnode * buynode(elemtype v)//��ռ�����һ����㲢��ֵ���ص�ַ
{
	listnode * s = (listnode *)malloc(sizeof(listnode));
	s->date = v;
	s->next = NULL;
	return s;
}

void listpushback(list * pst, elemtype v)//β�巨
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
//��������
void greatlisttail(list * pst)//β�巨
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
		s->next = NULL;//���ٽ�㸳��ֵ
		              //�����γ�����
		p->next = s;
		p = p->next;
	}
}
void greatlisthead(list * pst)//ͷ�巨
{
	*pst = (listnode *)malloc(sizeof(listnode));
	assert(*pst != NULL);
	(*pst)->date = 1;
	(*pst)->next = NULL;
	for (int i = 0; i < 11; i++)
	{
		listnode * s = (listnode *)malloc(sizeof(listnode));
		s->date = i;
		s->next = NULL;//��������ʼ��
		//���ӳ�����
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