/**
 * @file dlink_list.h
 * @brief ˫����
 * @author CodeXiXi
 * @date 2025/7/15
 *
 * ���ļ�ʵ����˫����(��ͷ���)�Ļ���������������ʼ�������롢ɾ���ȡ�
 */

#ifndef DLINK_LIST_H
#define DLINK_LIST_H

#include <stdlib.h>

typedef struct DNode {
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

// ��ʼ��˫����
bool InitDLinkList(DLinkList &L)
{
	L = (DNode *)malloc(sizeof(DNode));
	if (L == nullptr)
	{
		return false;
	}

	L->next = nullptr;
	L->prior = nullptr;
	return true;
}

// �ж�˫�����Ƿ�Ϊ��
bool isEmpty(DLinkList &L)
{
	if (L->next == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ��p���������s���
bool InsertNextDNode(DNode *p, DNode *s)
{
	s->next = p->next;
	if (p->next != nullptr)
	{
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;

	return true;
}

// ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode *p)
{
	if (p == nullptr)
	{
		return false;
	}

	DNode *q = p->next;
	if (q == nullptr)
	{
		return false;
	}

	p->next = q->next;
	if (q->next != nullptr)
	{
		q->next->prior = p;
	}
	free(q);
	
	return true;
}

// ѭ���ͷŸ������
void DestoryList(DLinkList &L)
{
	while (L->next != nullptr)
	{
		DeleteNextDNode(L);
	}

	free(L);
	L = nullptr;	//��������ָ�룬free���ͷ��ڴ棬��ʱLָ��һ����Ч�ڴ�����
}

#endif	//DLINK_LIST_H

