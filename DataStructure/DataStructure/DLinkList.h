/**
 * @file dlink_list.h
 * @brief 双链表
 * @author CodeXiXi
 * @date 2025/7/15
 *
 * 本文件实现了双链表(带头结点)的基本操作，包括初始化、插入、删除等。
 */

#ifndef DLINK_LIST_H
#define DLINK_LIST_H

#include <stdlib.h>

typedef struct DNode {
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化双链表
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

// 判断双链表是否为空
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

// 在p结点后面插入s结点
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

// 删除p结点的后继结点
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

// 循环释放各个结点
void DestoryList(DLinkList &L)
{
	while (L->next != nullptr)
	{
		DeleteNextDNode(L);
	}

	free(L);
	L = nullptr;	//避免悬空指针，free仅释放内存，此时L指向一个无效内存区域
}

#endif	//DLINK_LIST_H

