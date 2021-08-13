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