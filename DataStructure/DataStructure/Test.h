/**
 * @file test.h
 * @brief 专门用来测试数据结构功能
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * 本文件实现了所有数据结构的测试案例
 */

#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#include "SqList.h"
#include "SeqList.h"
#include "LinkList.h"

#endif	// TEST_H

// 测试静态顺序表
void TestSqList()
{
	SqList L;
	InitList(L);

	ListInsert(L, 1, 5);
	ListInsert(L, 2, 10);
	ListInsert(L, 3, 30);

	PrintList(L);

	int locate = LocateElem(L, 10);
	printf("10的位序为%d\n", locate);

	int order = GetElem(L, 3);
	printf("3的位序元素为%d\n", order);

	int del = -1;
	ListDelete(L, 1, del);
	printf("删除的值为%d\n", del);

	PrintList(L);
}

// 测试动态顺序表
void TestSeqList()
{
	SeqList L;
	InitList(L);

	ListInsert(L, 1, 5);
	ListInsert(L, 2, 10);
	ListInsert(L, 3, 30);

	PrintList(L);

	int locate = LocateElem(L, 10);
	printf("10的位序为%d\n", locate);

	int order = GetElem(L, 3);
	printf("3的位序元素为%d\n", order);

	int del = -1;
	ListDelete(L, 1, del);
	printf("删除的值为%d\n", del);

	PrintList(L);
}

// 测试单链表
void TestLinkList()
{
	LinkList L;
	InitList(L);
	if (isEmpty(L))
	{
		printf("单链表为空\n");
	}
}
