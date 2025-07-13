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
#define INITSIZE 50

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
	}
}
