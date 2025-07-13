/**
 * @file sq_list.h
 * @brief 顺序表静态实现
 * @author CodeXiXi
 * @date 2025/7/13
 *
 * 本文件实现了顺序表的基本操作，包括插入、删除、查找等。
 */

#ifndef SQ_LIST_H
#define SQ_LIST_H

// 定义最大长度(静态)
#define MAXSIZE 50

// 静态顺序表的类型定义
typedef struct {
	int data[MAXSIZE];  // 用静态的“数组”存储顺序表的元素
	int length;         // 顺序表的当前长度
} SqList;

#endif // SQ_LIST_H

// 初始化顺序表(静态)
void InitList(SqList &L)
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		L.data[i] = 0;
	}

	L.length = 0;
}

// 在L的位序i处插入元素e
bool ListInsert(SqList &L, int i, int e)
{
	if (L.length >= MAXSIZE)
	{
		return false;
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
bool ListDelete(SqList &L, int i, int &e)
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
int GetElem(SqList L, int i)
{
	return L.data[i - 1];
}

// 按值查找, 在表L中查找值为e的元素，返回位序
int LocateElem(SqList L, int e)
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
void PrintList(SqList L)
{
	for (int i = 0; i < L.length; ++i)
	{
		printf("%d\t", L.data[i]);
	}

	printf("\n");
}