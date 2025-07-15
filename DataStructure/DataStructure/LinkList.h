/**
 * @file link_list.h
 * @brief ������
 * @author CodeXiXi
 * @date 2025/7/14
 *
 * ���ļ�ʵ���˵�����Ļ����������������롢ɾ�������ҵȡ�
 */

#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

/*
 *����ͷ���ķ���
 */

// ��ʼ��������(����ͷ���)
bool InitList(LinkList &L)
{
	L = nullptr;
	return true;
}

// �жϲ���ͷ���ĵ������Ƿ�Ϊ�ձ�
bool isEmpty(LinkList L)
{
	return (L == nullptr);
}

// �ڵ�i��λ�ò���Ԫ��e(����ͷ���)
bool ListInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}

	// ����ͷ����ڲ���λ��Ϊ1ʱ���޷��ҵ���ǰ�ý�㣬��Ҫ��Դ���
	if (i == 1)
	{
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}

	LNode *p = L;		// ��ǰָ��Ľڵ�
	int j = 1;			// ָ��ڵ��λ��

	// Ѱ��i-1λ��Ľ��
	while (j < i - 1 && p != nullptr)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr)	// ��λ��
	{
		return false;
	}

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// ��λ��ɾ��,����ͷ���
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
 *��ͷ���ķ���
 */

// ��ʼ��������(��ͷ���)
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

// �жϴ�ͷ���ĵ������Ƿ�Ϊ�ձ�
bool isHEmpty(LinkList L)
{
	return (L->next == nullptr);
}

// �ڵ�i��λ�ò���Ԫ��e(��ͷ���)
bool ListHInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}

	LNode *p = L;		// ��ǰָ��Ľڵ�
	int j = 0;			// ָ��ڵ��λ��ͷ����Ϊ0

	// Ѱ��i-1λ��Ľ��
	while (j < i - 1 && p != nullptr)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr)	// ��λ��
	{
		return false;
	}

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// ��p�ڵ�����Ԫ��e
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

// ��p�ڵ�ǰ����Ԫ��e,O(1)ʱ�临�Ӷ�֮͵������
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

// ��λ��ɾ��,��ͷ���
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

// ɾ��ָ�����p
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

// ��λ����
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

// ��ֵ����
LNode *LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != nullptr && p->data != e)
	{
		p = p->next;
	}

	return p;
}

// ���
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

// β�巨����������
LinkList List_TailInsert(LinkList &L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf_s("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = nullptr;

	return L;
}

// ͷ�巨����������
LinkList List_HeadInsert(LinkList &L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = nullptr;
	scanf_s("%d", &x);

	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}

	return L;
}

#endif	//LINK_LIST_H
