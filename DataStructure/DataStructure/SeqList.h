/**
 * @file seq_list.h
 * @brief 顺序表动态实现
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * 本文件实现了顺序表的基本操作，包括插入、删除、查找等。
 */

#ifndef SEQ_LIST_H
#define SEQ_LIST_H

// 定义初始长度(动态)
#define INITSIZE 50		// 测试时可适当调小初始长度

#include <stdlib.h>

// 静态顺序表的类型定义
typedef struct {
	int* data;
	int MaxSize;
	int length;
} SeqList;

#endif // SEQ_LIST_H

// 初始化顺序表(动态)
void InitList(SeqList &L)
{
	L.data = (int*)malloc(sizeof(SeqList) * INITSIZE);
	L.length = 0;
	L.MaxSize = INITSIZE;
}

// 增加动态顺序表长度
void IncreaseSize(SeqList& L, int len)
{
	int *p = L.data;
	L.data = (int*)malloc(sizeof(SeqList) * (L.MaxSize + len));
	if (L.data)
	{
		for (int i = 0; i < L.length; ++i)
		{
			L.data[i] = p[i];
		}

		free(p);

		L.MaxSize = L.MaxSize + len;
		//printf("成功增加长度%d!\n", len);
	}
}

// 在L的位序i处插入元素e
bool ListInsert(SeqList &L, int i, int e)
{
	if (L.length >= L.MaxSize)
	{
		IncreaseSize(L, 1);
	}

	if (i < 1 || i > L.length + 1)
	{
		return false;
	}

	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;

	return true;
}

// 删除L中位序为i的元素
bool ListDelete(SeqList &L, int i, int &e)
{
	if (i < 1 || i > L.length)
	{
		return false;
	}

	e = L.data[i - 1];
	for (int j = i; j < L.length; ++j)
	{
		L.data[j - 1] = L.data[j];
	}

	L.length--;
	return true;
}

// 按位查找，获取L中第i个位置的元素
int GetElem(SeqList L, int i)
{
	return L.data[i - 1];
}

// 按值查找, 在表L中查找值为e的元素，返回位序
int LocateElem(SeqList L, int e)
{
	for (int i = 0; i < L.length; ++i)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}

	return 0;
}

// 输出L中全部的元素
void PrintList(SeqList L)
{
	for (int i = 0; i < L.length; ++i)
	{
		printf("%d\t", *(L.data + i));
	}
}