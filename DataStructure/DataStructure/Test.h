/**
 * @file test.h
 * @brief ר�������������ݽṹ����
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * ���ļ�ʵ�����������ݽṹ�Ĳ��԰���
 */

#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#include "SqList.h"
#include "SeqList.h"
#include "LinkList.h"

#endif	// TEST_H

// ���Ծ�̬˳���
void TestSqList()
{
	SqList L;
	InitList(L);

	ListInsert(L, 1, 5);
	ListInsert(L, 2, 10);
	ListInsert(L, 3, 30);

	PrintList(L);

	int locate = LocateElem(L, 10);
	printf("10��λ��Ϊ%d\n", locate);

	int order = GetElem(L, 3);
	printf("3��λ��Ԫ��Ϊ%d\n", order);

	int del = -1;
	ListDelete(L, 1, del);
	printf("ɾ����ֵΪ%d\n", del);

	PrintList(L);
}

// ���Զ�̬˳���
void TestSeqList()
{
	SeqList L;
	InitList(L);

	ListInsert(L, 1, 5);
	ListInsert(L, 2, 10);
	ListInsert(L, 3, 30);

	PrintList(L);

	int locate = LocateElem(L, 10);
	printf("10��λ��Ϊ%d\n", locate);

	int order = GetElem(L, 3);
	printf("3��λ��Ԫ��Ϊ%d\n", order);

	int del = -1;
	ListDelete(L, 1, del);
	printf("ɾ����ֵΪ%d\n", del);

	PrintList(L);
}

// ���Ե�����
void TestLinkList()
{
	LinkList L;
	InitList(L);
	if (isEmpty(L))
	{
		printf("������Ϊ��\n");
	}
}
