/**
 * @file link_list.h
 * @brief 单链表
 * @author CodeXiXi
 * @date 2025/7/14
 *
 * 本文件实现了单链表的基本操作，包括插入、删除、查找等。
 */

#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

/*
 *不带头结点的方法
 */

// 初始化单链表(不带头结点)
bool InitList(LinkList &L)
{
	L = nullptr;
	return true;
}

// 判断不带头结点的单链表是否为空表
bool isEmpty(LinkList L)
{
	return (L == nullptr);
}

// 在第i个位置插入元素e(不带头结点)
bool ListInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}

	// 不带头结点在插入位序为1时，无法找到其前置结点，需要针对处理
	if (i == 1)
	{
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}

	LNode *p = L;		// 当前指向的节点
	int j = 1;			// 指向节点的位序

	// 寻找i-1位序的结点
	while (j < i - 1 && p != nullptr)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr)	// 超位序
	{
		return false;
	}

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 按位序删除,不带头结点
bool ListDelete(LinkList &L, int i, int &e)
{
	if (i < 1)
	{
		return false;
	}

	if (i == 1)
	{
		e = L->data;
		LNode *d = L;
		L = L->next;
		free(d);
	}

	int j = 1;
	LNode *p = L;

	while (j < i - 1 && p != nullptr)
	{
		j++;
		p = p->next;
	}

	if (p == nullptr || p->next == nullptr)
	{
		return false;
	}

	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);

	return true;
}

/*
 *带头结点的方法
 */

// 初始化单链表(带头结点)
bool InitHList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == nullptr)
	{
		return false;
	}

	L->next = nullptr;
	return true;
}

// 判断带头结点的单链表是否为空表
bool isHEmpty(LinkList L)
{
	return (L->next == nullptr);
}

// 在第i个位置插入元素e(带头结点)
bool ListHInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}

	LNode *p = L;		// 当前指向的节点
	int j = 0;			// 指向节点的位序，头结点记为0

	// 寻找i-1位序的结点
	while (j < i - 1 && p != nullptr)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr)	// 超位序
	{
		return false;
	}

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 在p节点后插入元素e
bool InsertNextNode(LNode *p, int e)
{
	if (p == nullptr)
	{
		return false;
	}

	LNode *s = (LNode *)malloc(sizeof(LNode));

	if (s == nullptr)
	{
		return false;
	}

	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

// 在p节点前插入元素e,O(1)时间复杂度之偷梁换柱
bool InsertPriorNode(LNode *p, int e)
{
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == nullptr)
	{
		return false;
	}

	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;

	return true;
}

// 按位序删除,带头结点
bool ListHDelete(LinkList &L, int i, int &e)
{
	if (i < 1)
	{
		return false;
	}

	int j = 0;
	LNode *p = L;

	while (j < i - 1 && p != nullptr)
	{
		j++;
		p = p->next;
	}

	if (p == nullptr || p->next == nullptr)
	{
		return false;
	}

	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);

	return true;
}

// 删除指定结点p
bool DeleteNode(LNode *p, LinkList &L)
{
	LNode *q = p->next;
	if (q == nullptr)
	{
		for (LNode *s = L; s->next != p; s = s->next)
		{
			s->next = nullptr;
			free(p);
		}
	}
	else
	{
		p->data = q->data;
		p->next = q->next;
		free(q);
	}

	return true;
}

// 按位查找
LNode *GetElem(LinkList L, int i)
{
	if (i < 0)
	{
		return nullptr;
	}

	LNode *p = L;
	int j = 0;

	while (j < i && p != nullptr)
	{
		j++;
		p = p->next;
	}

	return p;
}

// 按值查找
LNode *LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != nullptr && p->data != e)
	{
		p = p->next;
	}

	return p;
}

// 求表长
int Length(LinkList L)
{
	int len = 0;
	LNode *p = L;
	while (p->next != nullptr)
	{
		p = p->next;
		len++;
	}

	return len;
}

#endif	//LINK_LIST_H
